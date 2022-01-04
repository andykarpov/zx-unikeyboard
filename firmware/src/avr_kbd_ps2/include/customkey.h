#define KEY_ESC 80
#define KEY_ACCENT 1
#define KEY_F1 2
#define KEY_F2 3
#define KEY_F3 4
#define KEY_F4 5
#define KEY_F5 6
#define KEY_F6 7
#define KEY_F7 8
#define KEY_F8 9
#define KEY_F9 10
#define KEY_F10 11
#define KEY_F11 12
#define KEY_F12 13
#define KEY_PAUSE 14
#define KEY_INSERT 15
#define KEY_DELETE 16
#define KEY_1 17
#define KEY_2 18
#define KEY_3 19
#define KEY_4 20
#define KEY_5 21
#define KEY_6 22
#define KEY_7 23
#define KEY_8 24
#define KEY_9 25
#define KEY_0 26
#define KEY_MINUS 27
#define KEY_EQUAL 28
#define KEY_BACKSPACE 29
#define KEY_TAB 30
#define KEY_Q 31
#define KEY_W 32
#define KEY_E 33
#define KEY_R 34
#define KEY_T 35
#define KEY_Y 36
#define KEY_U 37
#define KEY_I 38
#define KEY_O 39
#define KEY_P 40
#define KEY_LBRACKET 41
#define KEY_RBRACKET 42
#define KEY_BACKSLASH 43
#define KEY_CAPSLOCK 44
#define KEY_A 45
#define KEY_S 46
#define KEY_D 47
#define KEY_F 48
#define KEY_G 49
#define KEY_H 50
#define KEY_J 51
#define KEY_K 52
#define KEY_L 53
#define KEY_SEMICOLON 54
#define KEY_QUOTE 55
#define KEY_ENTER 56
#define KEY_LSHIFT 57
#define KEY_Z 58
#define KEY_X 59
#define KEY_C 60
#define KEY_V 61
#define KEY_B 62
#define KEY_N 63
#define KEY_M 64
#define KEY_COMMA 65
#define KEY_PERIOD 66
#define KEY_SLASH 67
#define KEY_UP 68
#define KEY_RSHIFT 69
#define KEY_LCTRL 70
#define KEY_FN 71
#define KEY_GUI 72
#define KEY_LALT 73
#define KEY_SPACE 74
#define KEY_RALT 75
#define KEY_CONTEXTMENU 76
#define KEY_LEFT 77
#define KEY_DOWN 78
#define KEY_RIGHT 79

const uint8_t keyaddr[][3] =
{
{ KEY_ESC, 15, 16 },
{ KEY_ACCENT, 14, 16 },
{ KEY_F1, 15, 17 },
{ KEY_F2, 14, 17 },
{ KEY_F3, 15, 18 },
{ KEY_F4, 14, 18 },
{ KEY_F5, 15, 19 },
{ KEY_F6, 14, 19 },
{ KEY_F7, 15, 20 },
{ KEY_F8, 14, 20 },
{ KEY_F9, 15, 21 },
{ KEY_F10, 14, 21 },
{ KEY_F11, 3, 15 },
{ KEY_F12, 3, 14 },
{ KEY_PAUSE, 15, 23 },
{ KEY_INSERT, 15, 26 },
{ KEY_DELETE, 14, 26 },
{ KEY_1, 12, 16 },
{ KEY_2, 11, 16 },
{ KEY_3, 12, 17 },
{ KEY_4, 11, 17 },
{ KEY_5, 12, 18 },
{ KEY_6, 11, 18 },
{ KEY_7, 12, 19 },
{ KEY_8, 12, 20 },
{ KEY_9, 11, 20 },
{ KEY_0, 12, 21 },
{ KEY_MINUS, 11, 21 },
{ KEY_EQUAL, 3, 12 },
{ KEY_BACKSPACE, 12, 26 },
{ KEY_TAB, 12, 13 },
{ KEY_Q, 11, 13 },
{ KEY_W, 9, 16 },
{ KEY_E, 9, 17 },
{ KEY_R, 7, 17 },
{ KEY_T, 9, 18 },
{ KEY_Y, 7, 18 },
{ KEY_U, 11, 19 },
{ KEY_I, 9, 20 },
{ KEY_O, 7, 20 },
{ KEY_P, 9, 21 },
{ KEY_LBRACKET, 3, 11 },
{ KEY_RBRACKET, 3, 9 },
{ KEY_BACKSLASH, 11, 26 },
{ KEY_CAPSLOCK, 10, 11 },
{ KEY_A, 9, 10 },
{ KEY_S, 9, 13 },
{ KEY_D, 7, 16 },
{ KEY_F, 2, 17 },
{ KEY_G, 5, 17 },
{ KEY_H, 5, 18 },
{ KEY_J, 9, 19 },
{ KEY_K, 5, 20 },
{ KEY_L, 2, 20 },
{ KEY_SEMICOLON, 7, 21 },
{ KEY_QUOTE, 3, 7 },
{ KEY_ENTER, 9, 26 },
{ KEY_LSHIFT, 2, 6 },
{ KEY_Z, 5, 10 },
{ KEY_X, 5, 13 },
{ KEY_C, 5, 16 },
{ KEY_V, 2, 18 },
{ KEY_B, 5, 19 },
{ KEY_N, 7, 19 },
{ KEY_M, 5, 21 },
{ KEY_COMMA, 2, 21 },
{ KEY_PERIOD, 2, 3 },
{ KEY_SLASH, 9, 23 },
{ KEY_UP, 11, 23 },
{ KEY_RSHIFT, 6, 11 },
{ KEY_LCTRL, 1, 2 },
{ KEY_FN, 3, 5 },
{ KEY_GUI, 2, 4 },
{ KEY_LALT, 2, 8 },
{ KEY_SPACE, 5, 23 },
{ KEY_RALT, 2, 24 },
{ KEY_CONTEXTMENU, 2, 23 },
{ KEY_LEFT, 7, 23 },
{ KEY_DOWN, 7, 26 },
{ KEY_RIGHT, 2, 26 },
};

#define COLS_MAX 8
#define ROWS_MAX 16

const uint8_t rows[ROWS_MAX] =
{
1, 3, 4, 6, 8, 10, 13, 16, 17, 18, 19, 20, 21, 23, 24, 26
};

const uint8_t cols[COLS_MAX] =
{
2, 5, 7, 9, 11, 12, 14, 15
};

