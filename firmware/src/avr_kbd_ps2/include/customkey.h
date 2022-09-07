// include file for asus zg5

#define KEY_ESC 84
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
#define KEY_PRTSCR 13
#define KEY_PAUSE 14
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
#define KEY_PAGE_UP 78
#define KEY_UP 79
#define KEY_PAGE_DOWN 80
#define KEY_LEFT 81
#define KEY_DOWN 82
#define KEY_RIGHT 83

const uint8_t keyaddr[][3] =
{
{ KEY_ESC, 1, 5 },
{ KEY_F1, 1, 18 },
{ KEY_F2, 1, 22 },
{ KEY_F3, 2, 22 },
{ KEY_F4, 2, 18 },
{ KEY_F5, 1, 9 },
{ KEY_F6, 1, 24 },
{ KEY_F7, 2, 24 },
{ KEY_F8, 2, 9 },
{ KEY_F9, 4, 8 },
{ KEY_F10, 4, 5 },
{ KEY_F11, 2, 5 },
{ KEY_F12, 2, 8 },
{ KEY_PRTSCR, 4, 23 },
{ KEY_PAUSE, 4, 24 },
{ KEY_INSERT, 3, 5 },
{ KEY_DELETE, 3, 8 },
{ KEY_ACCENT, 1, 8 },
{ KEY_1, 2, 23 },
{ KEY_2, 4, 18 },
{ KEY_3, 4, 11 },
{ KEY_4, 8, 17 },
{ KEY_5, 5, 17 },
{ KEY_6, 8, 16 },
{ KEY_7, 5, 16 },
{ KEY_8, 8, 15 },
{ KEY_9, 5, 15 },
{ KEY_0, 8, 14 },
{ KEY_MINUS, 5, 14 },
{ KEY_EQUAL, 8, 13 },
{ KEY_BACKSPACE, 4, 9 },
{ KEY_TAB, 1, 11 },
{ KEY_Q, 2, 11 },
{ KEY_W, 9, 21 },
{ KEY_E, 11, 17 },
{ KEY_R, 9, 17 },
{ KEY_T, 9, 16 },
{ KEY_Y, 11, 15 },
{ KEY_U, 9, 15 },
{ KEY_I, 11, 14 },
{ KEY_O, 9, 14 },
{ KEY_P, 6, 8 },
{ KEY_LBRACKET, 5, 6 },
{ KEY_RBRACKET, 9, 13 },
{ KEY_BACKSLASH, 15, 24 },
{ KEY_CAPSLOCK, 1, 23 },
{ KEY_A, 18, 21 },
{ KEY_S, 11, 21 },
{ KEY_D, 17, 22 },
{ KEY_F, 17, 18 },
{ KEY_G, 16, 18 },
{ KEY_H, 11, 16 },
{ KEY_J, 15, 18 },
{ KEY_K, 14, 22 },
{ KEY_L, 14, 18 },
{ KEY_SEMICOLON, 6, 11 },
{ KEY_QUOTE, 6, 9 },
{ KEY_ENTER, 11, 13 },
{ KEY_LSHIFT, 12, 22 },
{ KEY_Z, 21, 22 },
{ KEY_X, 17, 23 },
{ KEY_C, 16, 23 },
{ KEY_V, 16, 22 },
{ KEY_B, 15, 23 },
{ KEY_N, 15, 22 },
{ KEY_M, 14, 24 },
{ KEY_COMMA, 14, 23 },
{ KEY_PERIOD, 6, 22 },
{ KEY_SLASH, 6, 18 },
{ KEY_RSHIFT, 12, 18 },
{ KEY_LCTRL, 10, 24 },
{ KEY_FN, 21, 24 },
{ KEY_GUI, 20, 24 },
{ KEY_LALT, 19, 24 },
{ KEY_SPACE, 16, 24 },
{ KEY_RALT, 19, 23 },
{ KEY_CONTEXTMENU, 13, 24 },
{ KEY_RCTRL, 10, 22 },
{ KEY_PAGE_UP, 3, 11 },
{ KEY_UP, 4, 22 },
{ KEY_PAGE_DOWN, 3, 18 },
{ KEY_LEFT, 3, 24 },
{ KEY_DOWN, 3, 23 },
{ KEY_RIGHT, 3, 22 },
};

#define COLS_MAX 8
#define ROWS_MAX 15

const uint8_t rows[ROWS_MAX] = 
{
1, 2, 3, 4, 6, 10, 12, 13, 14, 15, 16, 17, 19, 20, 21
};

const uint8_t cols[COLS_MAX] = 
{
5, 8, 9, 11, 18, 22, 23, 24
};
