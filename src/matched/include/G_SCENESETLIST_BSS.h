#ifndef ALETHEIA_G_SCENESETLIST_BSS_H
#define ALETHEIA_G_SCENESETLIST_BSS_H
/* scenesetlist_bss (arm9) */
struct SCENESETLIST_BSS {
    unsigned char Focus;
    unsigned char RetScene;
    unsigned char FocusClm;
    unsigned char pad_3[0x1];
    unsigned short Pos;
    unsigned char pad_6[0x2];
    void *MemSsl;
};
#endif
