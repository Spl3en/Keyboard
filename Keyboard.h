#pragma once

#include "KeyState.h"


/*
 * Description : Checks if a key is typed (pressed then released)
 * unsigned char key : A keycode of the key to check (for special keys, see here : http://www.kbdedit.com/manual/low_level_vk_list.html)
 * Return : true if the key is typed, false otherwise
 */
bool
Keyboard_is_key_typed (
	unsigned char key
);

/*
 * Description : Checks if a is pressed
 * unsigned char key : A keycode of the key to check (for special keys, see here : http://www.kbdedit.com/manual/low_level_vk_list.html)
 * Return : true if the key is pressed, false otherwise
 */
bool
Keyboard_is_key_pressed (
	unsigned char key
);
