#ifndef ALETHEIA_G_SCENEMENU_BSS_H
#define ALETHEIA_G_SCENEMENU_BSS_H
/* scenemenu_bss (arm9) */
struct SCENEMENU_BSS {
    unsigned char FocusPos;
    unsigned char pad_1[0x3];
    void *Palette;
};
#endif
