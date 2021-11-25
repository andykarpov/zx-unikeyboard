#define KEY_ESC 78
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
#define KEY_LCTRL 67
#define KEY_FN 68
#define KEY_GUI 69
#define KEY_LALT 70
#define KEY_SPACE 71
#define KEY_RALT 72
#define KEY_RCTRL 73
#define KEY_LEFT 74
#define KEY_UP 75
#define KEY_DOWN 76
#define KEY_RIGHT 77

const uint8_t keyaddr[][3] =
{
{ KEY_ESC, 5, 26 },
{ KEY_F1, 2, 25 },
{ KEY_F2, 2, 24 },
{ KEY_F3, 7, 24 },
{ KEY_F4, 5, 24 },
{ KEY_F5, 1, 11 },
{ KEY_F6, 5, 21 },
{ KEY_F7, 7, 20 },
{ KEY_F8, 2, 20 },
{ KEY_F9, 2, 14 },
{ KEY_F10, 1, 14 },
{ KEY_F11, 4, 16 },
{ KEY_F12, 8, 11 },
{ KEY_DELETE, 2, 16 },
{ KEY_ACCENT, 2, 26 },
{ KEY_1, 1, 26 },
{ KEY_2, 1, 25 },
{ KEY_3, 1, 24 },
{ KEY_4, 1, 23 },
{ KEY_5, 2, 23 },
{ KEY_6, 2, 22 },
{ KEY_7, 1, 22 },
{ KEY_8, 1, 21 },
{ KEY_9, 1, 20 },
{ KEY_0, 1, 13 },
{ KEY_MINUS, 2, 13 },
{ KEY_EQUAL, 2, 21 },
{ KEY_BACKSPACE, 7, 14 },
{ KEY_TAB, 7, 26 },
{ KEY_Q, 8, 26 },
{ KEY_W, 8, 25 },
{ KEY_E, 8, 24 },
{ KEY_R, 8, 23 },
{ KEY_T, 7, 23 },
{ KEY_Y, 7, 22 },
{ KEY_U, 8, 22 },
{ KEY_I, 8, 21 },
{ KEY_O, 8, 20 },
{ KEY_P, 8, 13 },
{ KEY_LBRACKET, 7, 13 },
{ KEY_RBRACKET, 7, 21 },
{ KEY_BACKSLASH, 6, 14 },
{ KEY_CAPSLOCK, 7, 25 },
{ KEY_A, 6, 26 },
{ KEY_S, 6, 25 },
{ KEY_D, 6, 24 },
{ KEY_F, 6, 23 },
{ KEY_G, 5, 23 },
{ KEY_H, 5, 22 },
{ KEY_J, 6, 22 },
{ KEY_K, 6, 21 },
{ KEY_L, 6, 20 },
{ KEY_SEMICOLON, 6, 13 },
{ KEY_QUOTE, 5, 13 },
{ KEY_ENTER, 4, 14 },
{ KEY_LSHIFT, 7, 15 },
{ KEY_Z, 4, 26 },
{ KEY_X, 4, 25 },
{ KEY_C, 4, 24 },
{ KEY_V, 4, 23 },
{ KEY_B, 3, 23 },
{ KEY_N, 3, 22 },
{ KEY_M, 4, 22 },
{ KEY_COMMA, 4, 21 },
{ KEY_PERIOD, 4, 20 },
{ KEY_SLASH, 3, 13 },
{ KEY_RSHIFT, 6, 15 },
{ KEY_LCTRL, 2, 11 },
{ KEY_FN, 6, 12 },
{ KEY_GUI, 7, 10 },
{ KEY_LALT, 5, 12 },
{ KEY_SPACE, 5, 16 },
{ KEY_RALT, 3, 12 },
{ KEY_RCTRL, 4, 11 },
{ KEY_LEFT, 3, 19 },
{ KEY_UP, 5, 19 },
{ KEY_DOWN, 3, 16 },
{ KEY_RIGHT, 3, 17 },
};

#define COLS_MAX 8
#define ROWS_MAX 16

const uint8_t cols[COLS_MAX] = 
{
1, 2, 3, 4, 5, 6, 7, 8
};

const uint8_t rows[ROWS_MAX] = 
{
10, 11, 12, 13, 14, 15, 16, 17, 19, 20, 21, 22, 23, 24, 25, 26
};
