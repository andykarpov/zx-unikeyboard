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
#define KEY_NUMLOCK 13
#define KEY_PRTSCR 14
#define KEY_SCRLOCK 15
#define KEY_PAUSE 16
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
#define KEY_HOME 31
#define KEY_TAB 32
#define KEY_Q 33
#define KEY_W 34
#define KEY_E 35
#define KEY_R 36
#define KEY_T 37
#define KEY_Y 38
#define KEY_U 39
#define KEY_I 40
#define KEY_O 41
#define KEY_P 42
#define KEY_LBRACKET 43
#define KEY_RBRACKET 44
#define KEY_BACKSLASH 45
#define KEY_PAGEUP 46
#define KEY_CAPSLOCK 47
#define KEY_A 48
#define KEY_S 49
#define KEY_D 50
#define KEY_F 51
#define KEY_G 52
#define KEY_H 53
#define KEY_J 54
#define KEY_K 55
#define KEY_L 56
#define KEY_SEMICOLON 57
#define KEY_QUOTE 58
#define KEY_ENTER 59
#define KEY_PAGEDOWN 60
#define KEY_LSHIFT 61
#define KEY_Z 62
#define KEY_X 63
#define KEY_C 64
#define KEY_V 65
#define KEY_B 66
#define KEY_N 67
#define KEY_M 68
#define KEY_COMMA 69
#define KEY_PERIOD 70
#define KEY_SLASH 71
#define KEY_RSHIFT 72
#define KEY_UP 73
#define KEY_END 74
#define KEY_FN 75
#define KEY_LCTRL 76
#define KEY_WINR 77
#define KEY_LALT 78
#define KEY_SPACE 79
#define KEY_RALT 80
#define KEY_WINL 81
#define KEY_CONTEXTMENU 82
#define KEY_INSERT 83
#define KEY_DELETE 84
#define KEY_LEFT 85
#define KEY_DOWN 86
#define KEY_RIGHT 87

const uint8_t keyaddr[][3] =
{
{ KEY_ESC, 8, 24 },
{ KEY_F1, 8, 22 },
{ KEY_F2, 8, 20 },
{ KEY_F3, 8, 19 },
{ KEY_F4, 8, 18 },
{ KEY_F5, 8, 17 },
{ KEY_F6, 8, 16 },
{ KEY_F7, 8, 15 },
{ KEY_F8, 8, 14 },
{ KEY_F9, 8, 13 },
{ KEY_F10, 8, 12 },
{ KEY_F11, 8, 12 },
{ KEY_F12, 8, 10 },
{ KEY_NUMLOCK, 8, 9 },
{ KEY_PRTSCR, 3, 9 },
{ KEY_SCRLOCK, 3, 10 },
{ KEY_PAUSE, 3, 11 },
{ KEY_ACCENT, 7, 24 },
{ KEY_1, 7, 22 },
{ KEY_2, 7, 20 },
{ KEY_3, 7, 19 },
{ KEY_4, 7, 18 },
{ KEY_5, 7, 17 },
{ KEY_6, 7, 16 },
{ KEY_7, 7, 15 },
{ KEY_8, 7, 14 },
{ KEY_9, 8, 12 },
{ KEY_0, 8, 12 },
{ KEY_MINUS, 7, 11 },
{ KEY_EQUAL, 7, 10 },
{ KEY_BACKSPACE, 7, 9 },
{ KEY_HOME, 1, 12 },
{ KEY_TAB, 6, 24 },
{ KEY_Q, 6, 22 },
{ KEY_W, 6, 20 },
{ KEY_E, 6, 19 },
{ KEY_R, 6, 18 },
{ KEY_T, 6, 17 },
{ KEY_Y, 6, 16 },
{ KEY_U, 6, 15 },
{ KEY_I, 6, 14 },
{ KEY_O, 6, 13 },
{ KEY_P, 6, 11 },
{ KEY_LBRACKET, 6, 10 },
{ KEY_RBRACKET, 6, 9 },
{ KEY_BACKSLASH, 3, 12 },
{ KEY_PAGEUP, 5, 24 },
{ KEY_CAPSLOCK, 5, 22 },
{ KEY_A, 5, 20 },
{ KEY_S, 5, 19 },
{ KEY_D, 5, 18 },
{ KEY_F, 5, 17 },
{ KEY_G, 5, 16 },
{ KEY_H, 5, 15 },
{ KEY_J, 5, 14 },
{ KEY_K, 5, 13 },
{ KEY_L, 5, 12 },
{ KEY_SEMICOLON, 5, 11 },
{ KEY_QUOTE, 5, 10 },
{ KEY_ENTER, 4, 10 },
{ KEY_PAGEDOWN, 4, 10 },
{ KEY_LSHIFT, 4, 24 },
{ KEY_Z, 4, 22 },
{ KEY_X, 4, 20 },
{ KEY_C, 4, 19 },
{ KEY_V, 4, 18 },
{ KEY_B, 4, 17 },
{ KEY_N, 4, 16 },
{ KEY_M, 4, 15 },
{ KEY_COMMA, 4, 14 },
{ KEY_PERIOD, 4, 13 },
{ KEY_SLASH, 4, 12 },
{ KEY_RSHIFT, 5, 9 },
{ KEY_UP, 4, 11 },
{ KEY_END, 4, 9 },
{ KEY_FN, 3, 24 },
{ KEY_LCTRL, 3, 22 },
{ KEY_WINR, 3, 20 },
{ KEY_LALT, 3, 19 },
{ KEY_SPACE, 3, 18 },
{ KEY_RALT, 3, 17 },
{ KEY_WINL, 3, 16 },
{ KEY_CONTEXTMENU, 3, 15 },
{ KEY_INSERT, 3, 14 },
{ KEY_DELETE, 3, 13 },
{ KEY_LEFT, 2, 24 },
{ KEY_DOWN, 2, 22 },
{ KEY_RIGHT, 2, 20 },
};

#define COLS_MAX 8
#define ROWS_MAX 14

const uint8_t cols[COLS_MAX] = 
{
1, 2, 3, 4, 5, 6, 7, 8
};

const uint8_t rows[ROWS_MAX] = 
{
9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 22, 24
};
