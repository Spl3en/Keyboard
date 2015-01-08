#include "Keyboard.h"


/*
 * Description : Checks if a key is typed (pressed then released)
 * unsigned char key : A keycode of the key to check (for special keys, see here : http://www.kbdedit.com/manual/low_level_vk_list.html)
 * Return : true if the key is typed, false otherwise
 */
bool
Keyboard_is_key_typed (
	unsigned char key
) {
	static KeyState states[sizeof(key)] = {[0 ... (sizeof(key)-1)] = KEY_STATE_RELEASED};
	bool keyPressed = Keyboard_is_key_pressed (key);

	if (keyPressed) {
		// The key has been pressed but not released yet
		states[key] = KEY_STATE_PRESSED;
		return false;
	}

	// On release, trigger the event
	if (!keyPressed && states[key] == KEY_STATE_PRESSED) {
		states[key] = KEY_STATE_RELEASED;
		return true;
	}

	return false;
}


/*
 * Description : Checks if a is pressed
 * unsigned char key : A keycode of the key to check (for special keys, see here : http://www.kbdedit.com/manual/low_level_vk_list.html)
 * Return : true if the key is pressed, false otherwise
 */
bool
Keyboard_is_key_pressed (
	unsigned char key
) {
	return GetKeyState (key) < 0;
}
