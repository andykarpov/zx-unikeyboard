//Example file for Asus X200 keyboard

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
#define KEY_PAUSE 13
#define KEY_PRTSCR 14
#define KEY_INSERT 15
#define KEY_DELETE 16
#define KEY_ACCENT 17
#define KEY_1 18
#define KEY_2 19
#define KEY_3 20
#define KEY_4 21
#define KEY_5 22
#define KEY_6 23
#define KEY_7 24
#define KEY_8 25
#define KEY_9 26
#define KEY_0 27
#define KEY_MINUS 28
#define KEY_EQUAL 29
#define KEY_BACKSPACE 30
#define KEY_TAB 31
#define KEY_Q 32
#define KEY_W 33
#define KEY_E 34
#define KEY_R 35
#define KEY_T 36
#define KEY_Y 37
#define KEY_U 38
#define KEY_I 39
#define KEY_O 40
#define KEY_P 41
#define KEY_LBRACKET 42
#define KEY_RBRACKET 43
#define KEY_BACKSLASH 44
#define KEY_CAPSLOCK 45
#define KEY_A 46
#define KEY_S 47
#define KEY_D 48
#define KEY_F 49
#define KEY_G 50
#define KEY_H 51
#define KEY_J 52
#define KEY_K 53
#define KEY_L 54
#define KEY_SEMICOLON 55
#define KEY_QUOTE 56
#define KEY_ENTER 57
#define KEY_LSHIFT 58
#define KEY_Z 59
#define KEY_X 60
#define KEY_C 61
#define KEY_V 62
#define KEY_B 63
#define KEY_N 64
#define KEY_M 65
#define KEY_COMMA 66
#define KEY_PERIOD 67
#define KEY_SLASH 68
#define KEY_RSHIFT 69
#define KEY_LCTRL 70
#define KEY_FN 71
#define KEY_GUI 72
#define KEY_LALT 73
#define KEY_SPACE 74
#define KEY_RALT 75
#define KEY_CONTEXTMENU 76
#define KEY_RCTRL 77
#define KEY_LEFT 78
#define KEY_RIGHT 79
#define KEY_UP 80
#define KEY_DOWN 81

const uint8_t keyaddr[][3] =
{
{ KEY_ESC, 7, 24 },
{ KEY_F1, 6, 14 },
{ KEY_F2, 7, 14 },
{ KEY_F3, 8, 15 },
{ KEY_F4, 12, 14 },
{ KEY_F5, 7, 16 },
{ KEY_F6, 10, 16 },
{ KEY_F7, 13, 15 },
{ KEY_F8, 13, 17 },
{ KEY_F9, 12, 18 },
{ KEY_F10, 13, 18 },
{ KEY_F11, 12, 19 },
{ KEY_F12, 13, 19 },
{ KEY_PAUSE, 12, 20 },
{ KEY_PRTSCR, 9, 15 },
{ KEY_INSERT, 12, 21 },
{ KEY_DELETE, 12, 23 },
{ KEY_ACCENT, 1, 13 },
{ KEY_1, 11, 14 },
{ KEY_2, 10, 14 },
{ KEY_3, 11, 15 },
{ KEY_4, 10, 15 },
{ KEY_5, 11, 16 },
{ KEY_6, 11, 17 },
{ KEY_7, 10, 18 },
{ KEY_8, 11, 18 },
{ KEY_9, 10, 19 },
{ KEY_0, 11, 19 },
{ KEY_MINUS, 13, 20 },
{ KEY_EQUAL, 11, 21 },
{ KEY_BACKSPACE, 13, 23 },
{ KEY_TAB, 1, 11 },
{ KEY_Q, 13, 21 },
{ KEY_W, 6, 15 },
{ KEY_E, 13, 16 },
{ KEY_R, 6, 16 },
{ KEY_T, 10, 17 },
{ KEY_Y, 6, 17 },
{ KEY_U, 6, 18 },
{ KEY_I, 9, 18 },
{ KEY_O, 6, 19 },
{ KEY_P, 11, 20 },
{ KEY_LBRACKET, 10, 21 },
{ KEY_RBRACKET, 11, 23 },
{ KEY_BACKSLASH, 11, 22 },
{ KEY_CAPSLOCK, 1, 10 },
{ KEY_A, 9, 14 },
{ KEY_S, 7, 17 },
{ KEY_D, 9, 23 },
{ KEY_F, 8, 16 },
{ KEY_G, 9, 17 },
{ KEY_H, 8, 18 },
{ KEY_J, 8, 19 },
{ KEY_K, 9, 21 },
{ KEY_L, 10, 20 },
{ KEY_SEMICOLON, 6, 21 },
{ KEY_QUOTE, 10, 23 },
{ KEY_ENTER, 6, 20 },
{ KEY_LSHIFT, 5, 11 },
{ KEY_Z, 8, 14 },
{ KEY_X, 13, 14 },
{ KEY_C, 7, 21 },
{ KEY_V, 8, 17 },
{ KEY_B, 7, 18 },
{ KEY_N, 7, 19 },
{ KEY_M, 9, 20 },
{ KEY_COMMA, 8, 20 },
{ KEY_PERIOD, 8, 21 },
{ KEY_SLASH, 9, 19 },
{ KEY_RSHIFT, 5, 8 },
{ KEY_LCTRL, 4, 12 },
{ KEY_FN, 1, 6 },
{ KEY_GUI, 3, 13 },
{ KEY_LALT, 2, 7 },
{ KEY_SPACE, 7, 20 },
{ KEY_RALT, 2, 9 },
{ KEY_CONTEXTMENU, 1, 9 },
{ KEY_RCTRL, 4, 6 },
{ KEY_LEFT, 6, 23 },
{ KEY_RIGHT, 7, 15 },
{ KEY_UP, 12, 24 },
{ KEY_DOWN, 8, 24 },
};

#define COLS_MAX 8
#define ROWS_MAX 16

const uint8_t cols[COLS_MAX] = 
{
6, 7, 8, 9, 10, 11, 12, 13
};

const uint8_t rows[ROWS_MAX] = 
{
1, 2, 3, 4, 5, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24
};

