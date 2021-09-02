#define KEY_WWW 0
#define KEY_DOS 1
#define KEY_DOC 2
#define KEY_VCD 3
#define KEY_DVD 4
#define KEY_CLOSE 5
#define KEY_PLAY 6
#define KEY_STOP 7
#define KEY_NEXT 8
#define KEY_BACK 9
#define KEY_VOL_DOWN 10
#define KEY_VOL_UP 11
#define KEY_MUTE 12
#define KEY_SLEEP 13
#define KEY_ESC 14
#define KEY_F1 15
#define KEY_F2 16
#define KEY_F3 17
#define KEY_F4 18
#define KEY_F5 19
#define KEY_F6 20
#define KEY_F7 21
#define KEY_F8 22
#define KEY_F9 23
#define KEY_F10 24
#define KEY_F11 25
#define KEY_F12 26
#define KEY_NUMLOCK 27
#define KEY_PRTSCR 28
#define KEY_SCRLOCK 29
#define KEY_PAUSE 30
#define KEY_ACCENT 31
#define KEY_1 32
#define KEY_2 33
#define KEY_3 34
#define KEY_4 35
#define KEY_5 36
#define KEY_6 37
#define KEY_7 38
#define KEY_8 39
#define KEY_9 40
#define KEY_0 41
#define KEY_MINUS 42
#define KEY_EQUAL 43
#define KEY_BACKSPACE 44
#define KEY_HOME 45
#define KEY_TAB 46
#define KEY_Q 47
#define KEY_W 48
#define KEY_E 49
#define KEY_R 50
#define KEY_T 51
#define KEY_Y 52
#define KEY_U 53
#define KEY_I 54
#define KEY_O 55
#define KEY_P 56
#define KEY_LBRACKET 57
#define KEY_RBRACKET 58
#define KEY_BACKSLASH 59
#define KEY_PAGEUP 60
#define KEY_CAPSLOCK 61
#define KEY_A 62
#define KEY_S 63
#define KEY_D 64
#define KEY_F 65
#define KEY_G 66
#define KEY_H 67
#define KEY_J 68
#define KEY_K 69
#define KEY_L 70
#define KEY_SEMICOLON 71
#define KEY_QUOTE 72
#define KEY_ENTER 73
#define KEY_PAGEDOWN 74
#define KEY_LSHIFT 75
#define KEY_Z 76
#define KEY_X 77
#define KEY_C 78
#define KEY_V 79
#define KEY_B 80
#define KEY_N 81
#define KEY_M 82
#define KEY_COMMA 83
#define KEY_PERIOD 84
#define KEY_SLASH 85
#define KEY_RSHIFT 86
#define KEY_UP 87
#define KEY_END 88
#define KEY_FN 89
#define KEY_LCTRL 90
#define KEY_WINR 91
#define KEY_LALT 92
#define KEY_SPACE 93
#define KEY_RALT 94
#define KEY_WINL 95
#define KEY_CONTEXTMENU 96
#define KEY_INSERT 97
#define KEY_DELETE 98
#define KEY_RCTRL 99
#define KEY_LEFT 100
#define KEY_DOWN 101
#define KEY_RIGHT 102

const uint8_t keyaddr[][3] =
{
{ KEY_WWW, 1, 22 },
{ KEY_DOS, 1, 3 },
{ KEY_DOC, 1, 18 },
{ KEY_VCD, 1, 17 },
{ KEY_DVD, 2, 10 },
{ KEY_CLOSE, 2, 11 },
{ KEY_PLAY, 2, 12 },
{ KEY_STOP, 2, 13 },
{ KEY_NEXT, 2, 14 },
{ KEY_BACK, 2, 15 },
{ KEY_VOL_DOWN, 2, 16 },
{ KEY_VOL_UP, 2, 17 },
{ KEY_MUTE, 2, 18 },
{ KEY_SLEEP, 1, 24 },
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
{ KEY_P, 6, 12 },
{ KEY_LBRACKET, 6, 11 },
{ KEY_RBRACKET, 6, 10 },
{ KEY_BACKSLASH, 6, 9 },
{ KEY_PAGEUP, 3, 12 },
{ KEY_CAPSLOCK, 5, 24 },
{ KEY_A, 5, 22 },
{ KEY_S, 5, 20 },
{ KEY_D, 5, 19 },
{ KEY_F, 5, 18 },
{ KEY_G, 5, 17 },
{ KEY_H, 5, 16 },
{ KEY_J, 5, 15 },
{ KEY_K, 5, 14 },
{ KEY_L, 5, 13 },
{ KEY_SEMICOLON, 5, 12 },
{ KEY_QUOTE, 5, 11 },
{ KEY_ENTER, 5, 10 },
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

#define COLS_MAX 20
#define ROWS_MAX 22

const uint8_t rows[ROWS_MAX] = 
{
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 22, 24
};

const uint8_t cols[COLS_MAX] = 
{
2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 22, 24
};

