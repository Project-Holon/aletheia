#ifndef ALETHEIA_SCENEMENU_BSS_TYPES_H
#define ALETHEIA_SCENEMENU_BSS_TYPES_H

struct SCENEMENU_BSS {
    unsigned char FocusPos;
    unsigned char pad_1[0x3];
    void *Palette;
};

#endif
