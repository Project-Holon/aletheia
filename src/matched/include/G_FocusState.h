#ifndef ALETHEIA_G_FOCUSSTATE_H
#define ALETHEIA_G_FOCUSSTATE_H
/* g_021DE614 (arm9) */
struct FocusState {
    signed char last;
    signed char cur;
    unsigned char flag;
    unsigned char pad;
    void *screen;
};
#endif
