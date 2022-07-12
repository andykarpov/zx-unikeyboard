// Header file for 27-pin notebook keyboard matrix

#define KEY_ESC 85
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
#define KEY_INSERT 13
#define KEY_HOME 14
#define KEY_PGUP 15
#define KEY_DELETE 16
#define KEY_END 17
#define KEY_PGDN 18
#define KEY_ACCENT 19
#define KEY_1 20
#define KEY_2 21
#define KEY_3 22
#define KEY_4 23
#define KEY_5 24
#define KEY_6 25
#define KEY_7 26
#define KEY_8 27
#define KEY_9 28
#define KEY_0 29
#define KEY_MINUS 30
#define KEY_EQUAL 31
#define KEY_BACKSPACE 32
#define KEY_TAB 33
#define KEY_Q 34
#define KEY_W 35
#define KEY_E 36
#define KEY_R 37
#define KEY_T 38
#define KEY_Y 39
#define KEY_U 40
#define KEY_I 41
#define KEY_O 42
#define KEY_P 43
#define KEY_LBRACKET 44
#define KEY_RBRACKET 45
#define KEY_ENTER 46
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
#define KEY_BACKSLASH 59
#define KEY_LSHIFT 60
#define KEY_RCTRL2 61
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
#define KEY_FN 73
#define KEY_LCTRL 74
#define KEY_GUI 75
#define KEY_LALT 76
#define KEY_SPACE 77
#define KEY_RALT 78
#define KEY_CONTEXTMENU 79
#define KEY_RCTRL 80
#define KEY_LEFT 81
#define KEY_RIGHT 82
#define KEY_UP 83
#define KEY_DOWN 84

const uint8_t keyaddr[][3] =
{
{ KEY_ESC, 17, 24 },
{ KEY_F1, 6, 24 },
{ KEY_F2, 5, 25 },
{ KEY_F3, 6, 25 },
{ KEY_F4, 5, 7 },
{ KEY_F5, 4, 24 },
{ KEY_F6, 13, 16 },
{ KEY_F7, 5, 10 },
{ KEY_F8, 5, 11 },
{ KEY_F9, 14, 27 },
{ KEY_F10, 8, 14 },
{ KEY_F11, 5, 8 },
{ KEY_F12, 8, 17 },
{ KEY_INSERT, 13, 17 },
{ KEY_HOME, 13, 14 },
{ KEY_PGUP, 5, 27 },
{ KEY_DELETE, 15, 27 },
{ KEY_END, 10, 17 },
{ KEY_PGDN, 6, 10 },
{ KEY_ACCENT, 17, 25 },
{ KEY_1, 14, 25 },
{ KEY_2, 7, 14 },
{ KEY_3, 14, 24 },
{ KEY_4, 16, 23 },
{ KEY_5, 4, 23 },
{ KEY_6, 4, 9 },
{ KEY_7, 9, 16 },
{ KEY_8, 10, 14 },
{ KEY_9, 12, 14 },
{ KEY_0, 11, 14 },
{ KEY_MINUS, 11, 17 },
{ KEY_EQUAL, 16, 27 },
{ KEY_BACKSPACE, 6, 8 },
{ KEY_TAB, 5, 24 },
{ KEY_Q, 15, 25 },
{ KEY_W, 7, 15 },
{ KEY_E, 15, 24 },
{ KEY_R, 15, 23 },
{ KEY_T, 18, 23 },
{ KEY_Y, 9, 18 },
{ KEY_U, 9, 15 },
{ KEY_I, 10, 15 },
{ KEY_O, 12, 15 },
{ KEY_P, 11, 15 },
{ KEY_LBRACKET, 8, 16 },
{ KEY_RBRACKET, 6, 11 },
{ KEY_ENTER, 8, 18 },
{ KEY_CAPSLOCK, 7, 17 },
{ KEY_A, 16, 25 },
{ KEY_S, 7, 16 },
{ KEY_D, 16, 24 },
{ KEY_F, 14, 23 },
{ KEY_G, 6, 23 },
{ KEY_H, 6, 9 },
{ KEY_J, 9, 14 },
{ KEY_K, 10, 16 },
{ KEY_L, 12, 16 },
{ KEY_SEMICOLON, 11, 16 },
{ KEY_QUOTE, 4, 10 },
{ KEY_BACKSLASH, 11, 18 },
{ KEY_LSHIFT, 21, 26 },
{ KEY_RCTRL2, 4, 25 },
{ KEY_Z, 18, 25 },
{ KEY_X, 7, 18 },
{ KEY_C, 18, 24 },
{ KEY_V, 5, 23 },
{ KEY_B, 17, 23 },
{ KEY_N, 9, 17 },
{ KEY_M, 5, 9 },
{ KEY_COMMA, 10, 18 },
{ KEY_PERIOD, 12, 18 },
{ KEY_SLASH, 4, 11 },
{ KEY_RSHIFT, 1, 26 },
{ KEY_FN, 22, 26 },
{ KEY_LCTRL, 20, 26 },
{ KEY_GUI, 6, 12 },
{ KEY_LALT, 19, 26 },
{ KEY_SPACE, 5, 13 },
{ KEY_RALT, 2, 26 },
{ KEY_CONTEXTMENU, 8, 15 },
{ KEY_RCTRL, 4, 25 },
{ KEY_LEFT, 6, 27 },
{ KEY_RIGHT, 17, 27 },
{ KEY_UP, 4, 8 },
{ KEY_DOWN, 6, 13 },
};

#define COLS_MAX 9
#define ROWS_MAX 17

const uint8_t cols[COLS_MAX] = 
{
    4, 5, 6, 14, 15, 16, 17, 18, 26
};

const uint8_t rows[ROWS_MAX] = 
{
    1, 2, 7, 8, 9, 10, 11, 12, 13, 19, 20, 21, 22, 23, 24, 25, 27
};

