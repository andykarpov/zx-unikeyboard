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
#define KEY_PRTSCR 13
#define KEY_INSERT 14
#define KEY_DELETE 15
#define KEY_ACCENT 16
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
#define KEY_RSHIFT 68
#define KEY_LCTRL 69
#define KEY_FN 70
#define KEY_GUI 71
#define KEY_LALT 72
#define KEY_SPACE 73
#define KEY_RALT 74
#define KEY_CONTEXTMENU 75
#define KEY_RCTRL 76
#define KEY_PGUP 77
#define KEY_UP 78
#define KEY_PGDN 79
#define KEY_LEFT 80
#define KEY_DOWN 81
#define KEY_RIGHT 82

const uint8_t keyaddr[][3] =
{
{ KEY_ESC, 1, 18 },
{ KEY_F1, 2, 18 },
{ KEY_F2, 1, 17 },
{ KEY_F3, 2, 17 },
{ KEY_F4, 3, 17 },
{ KEY_F5, 1, 16 },
{ KEY_F6, 2, 16 },
{ KEY_F7, 1, 15 },
{ KEY_F8, 2, 15 },
{ KEY_F9, 1, 14 },
{ KEY_F10, 2, 14 },
{ KEY_F11, 1, 13 },
{ KEY_F12, 2, 13 },
{ KEY_PRTSCR, 1, 12 },
{ KEY_INSERT, 2, 9 },
{ KEY_DELETE, 2, 10 },
{ KEY_ACCENT, 3, 18 },
{ KEY_1, 4, 18 },
{ KEY_2, 4, 17 },
{ KEY_3, 5, 17 },
{ KEY_4, 3, 16 },
{ KEY_5, 4, 16 },
{ KEY_6, 3, 15 },
{ KEY_7, 4, 15 },
{ KEY_8, 3, 14 },
{ KEY_9, 4, 14 },
{ KEY_0, 3, 13 },
{ KEY_MINUS, 4, 13 },
{ KEY_EQUAL, 2, 12 },
{ KEY_BACKSPACE, 1, 9 },
{ KEY_TAB, 4, 20 },
{ KEY_Q, 3, 20 },
{ KEY_W, 2, 20 },
{ KEY_E, 7, 16 },
{ KEY_R, 8, 16 },
{ KEY_T, 5, 18 },
{ KEY_Y, 6, 16 },
{ KEY_U, 5, 16 },
{ KEY_I, 5, 15 },
{ KEY_O, 5, 14 },
{ KEY_P, 6, 13 },
{ KEY_LBRACKET, 5, 13 },
{ KEY_RBRACKET, 3, 12 },
{ KEY_BACKSLASH, 4, 10 },
{ KEY_CAPSLOCK, 4, 21 },
{ KEY_A, 3, 21 },
{ KEY_S, 2, 21 },
{ KEY_D, 5, 20 },
{ KEY_F, 6, 20 },
{ KEY_G, 7, 17 },
{ KEY_H, 6, 18 },
{ KEY_J, 7, 18 },
{ KEY_K, 6, 15 },
{ KEY_L, 6, 14 },
{ KEY_SEMICOLON, 7, 13 },
{ KEY_QUOTE, 4, 12 },
{ KEY_ENTER, 6, 10 },
{ KEY_LSHIFT, 1, 24 },
{ KEY_Z, 5, 21 },
{ KEY_X, 6, 21 },
{ KEY_C, 7, 21 },
{ KEY_V, 8, 20 },
{ KEY_B, 7, 20 },
{ KEY_N, 8, 18 },
{ KEY_M, 7, 15 },
{ KEY_COMMA, 8, 13 },
{ KEY_PERIOD, 7, 14 },
{ KEY_SLASH, 5, 12 },
{ KEY_RSHIFT, 2, 24 },
{ KEY_LCTRL, 3, 23 },
{ KEY_FN, 8, 21 },
{ KEY_GUI, 7, 19 },
{ KEY_LALT, 5, 22 },
{ KEY_SPACE, 8, 17 },
{ KEY_RALT, 6, 22 },
{ KEY_CONTEXTMENU, 8, 12 },
{ KEY_RCTRL, 4, 23 },
{ KEY_PGUP, 3, 10 },
{ KEY_UP, 6, 9 },
{ KEY_PGDN, 4, 9 },
{ KEY_LEFT, 7, 11 },
{ KEY_DOWN, 7, 10 },
{ KEY_RIGHT, 5, 11 },
};

#define COLS_MAX 8
#define ROWS_MAX 16

const uint8_t cols[COLS_MAX] = 
{
1, 2, 3, 4, 5, 6, 7, 8
};

const uint8_t rows[ROWS_MAX] = 
{
9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24
};
