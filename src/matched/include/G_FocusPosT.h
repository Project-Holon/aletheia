#ifndef ALETHEIA_G_FOCUSPOST_H
#define ALETHEIA_G_FOCUSPOST_H
/* g_021DE5A8 (arm9) */
struct FocusPosT {
    unsigned char idx;
    unsigned char flag;
    unsigned char pad_2[0x2];
    void *ptr;
    void *obj;
};
#endif
