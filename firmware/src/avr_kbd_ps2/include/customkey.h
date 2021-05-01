// Header file for BK3001BA bluetooth keyboard matrix

#define KEY_ESC 0
#define KEY_F1 1
#define KEY_F2 2
#define KEY_F3 3
#define KEY_F4 4
#define KEY_F5 5
#define KEY_F6 6
#define KEY_F7 7
#define KEY_F8 8
#define KEY_F9 9
#define KEY_F10 10
#define KEY_F11 11
#define KEY_F12 12
#define KEY_DELETE 13
#define KEY_ACCENT 14
#define KEY_1 15
#define KEY_2 16
#define KEY_3 17
#define KEY_4 18
#define KEY_5 19
#define KEY_6 20
#define KEY_7 21
#define KEY_8 22
#define KEY_9 23
#define KEY_0 24
#define KEY_MINUS 25
#define KEY_EQUAL 26
#define KEY_BACKSPACE 27
#define KEY_TAB 28
#define KEY_Q 29
#define KEY_W 30
#define KEY_E 31
#define KEY_R 32
#define KEY_T 33
#define KEY_Y 34
#define KEY_U 35
#define KEY_I 36
#define KEY_O 37
#define KEY_P 38
#define KEY_LBRACKET 39
#define KEY_RBRACKET 40
#define KEY_BACKSLASH 41
#define KEY_CAPSLOCK 42
#define KEY_A 43
#define KEY_S 44
#define KEY_D 45
#define KEY_F 46
#define KEY_G 47
#define KEY_H 48
#define KEY_J 49
#define KEY_K 50
#define KEY_L 51
#define KEY_SEMICOLON 52
#define KEY_QUOTE 53
#define KEY_ENTER 54
#define KEY_LSHIFT 55
#define KEY_Z 56
#define KEY_X 57
#define KEY_C 58
#define KEY_V 59
#define KEY_B 60
#define KEY_N 61
#define KEY_M 62
#define KEY_COMMA 63
#define KEY_PERIOD 64
#define KEY_SLASH 65
#define KEY_RSHIFT 66
#define KEY_FN 67
#define KEY_LCTRL 68
#define KEY_LALT 69
#define KEY_GUI 70
#define KEY_SPACE 71
#define KEY_CONTEXTMENU 72
#define KEY_RALT 73
#define KEY_LEFT 74
#define KEY_RIGHT 75
#define KEY_UP 76
#define KEY_DOWN 77

const uint8_t keyaddr[][3] =
{
{ KEY_ESC, 4, 9 },
{ KEY_F1, 7, 10 },
{ KEY_F2, 7, 11 },
{ KEY_F3, 2, 11 },
{ KEY_F4, 4, 11 },
{ KEY_F5, 8, 21 },
{ KEY_F6, 4, 14 },
{ KEY_F7, 2, 15 },
{ KEY_F8, 7, 15 },
{ KEY_F9, 7, 24 },
{ KEY_F10, 8, 24 },
{ KEY_F11, 5, 26 },
{ KEY_F12, 8, 22 },
{ KEY_DELETE, 7, 26 },
{ KEY_ACCENT, 7, 9 },
{ KEY_1, 8, 9 },
{ KEY_2, 8, 10 },
{ KEY_3, 8, 11 },
{ KEY_4, 8, 12 },
{ KEY_5, 7, 12 },
{ KEY_6, 7, 13 },
{ KEY_7, 8, 13 },
{ KEY_8, 8, 14 },
{ KEY_9, 8, 15 },
{ KEY_0, 8, 23 },
{ KEY_MINUS, 7, 23 },
{ KEY_EQUAL, 7, 14 },
{ KEY_BACKSPACE, 2, 24 },
{ KEY_TAB, 2, 9 },
{ KEY_Q, 1, 9 },
{ KEY_W, 1, 10 },
{ KEY_E, 1, 11 },
{ KEY_R, 1, 12 },
{ KEY_T, 2, 12 },
{ KEY_Y, 2, 13 },
{ KEY_U, 1, 13 },
{ KEY_I, 1, 14 },
{ KEY_O, 1, 15 },
{ KEY_P, 1, 23 },
{ KEY_LBRACKET, 2, 23 },
{ KEY_RBRACKET, 2, 14 },
{ KEY_BACKSLASH, 3, 24 },
{ KEY_CAPSLOCK, 2, 10 },
{ KEY_A, 3, 9 },
{ KEY_S, 3, 10 },
{ KEY_D, 3, 11 },
{ KEY_F, 3, 12 },
{ KEY_G, 4, 12 },
{ KEY_H, 4, 13 },
{ KEY_J, 3, 13 },
{ KEY_K, 3, 14 },
{ KEY_L, 3, 15 },
{ KEY_SEMICOLON, 3, 23 },
{ KEY_QUOTE, 4, 23 },
{ KEY_ENTER, 5, 24 },
{ KEY_LSHIFT, 2, 25 },
{ KEY_Z, 5, 9 },
{ KEY_X, 5, 10 },
{ KEY_C, 5, 11 },
{ KEY_V, 5, 12 },
{ KEY_B, 6, 12 },
{ KEY_N, 6, 13 },
{ KEY_M, 5, 13 },
{ KEY_COMMA, 5, 14 },
{ KEY_PERIOD, 5, 15 },
{ KEY_SLASH, 6, 23 },
{ KEY_RSHIFT, 3, 25 },
{ KEY_FN, 7, 21 },
{ KEY_LCTRL, 3, 22 },
{ KEY_LALT, 2, 20 },
{ KEY_GUI, 4, 22 },
{ KEY_SPACE, 4, 26 },
{ KEY_CONTEXTMENU, 6, 22 },
{ KEY_RALT, 5, 21 },
{ KEY_LEFT, 6, 16 },
{ KEY_RIGHT, 6, 18 },
{ KEY_UP, 4, 16 },
{ KEY_DOWN, 6, 26 },
};

#define COLS_MAX 8
#define ROWS_MAX 16

const uint8_t cols[COLS_MAX] = 
{
1, 2, 3, 4, 5, 6, 7, 8
};

const uint8_t rows[ROWS_MAX] = 
{
9, 10, 11, 12, 13, 14, 15, 16, 18, 20, 21, 22, 23, 24, 25, 26
};

