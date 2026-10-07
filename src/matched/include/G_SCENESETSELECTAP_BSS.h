#ifndef ALETHEIA_G_SCENESETSELECTAP_BSS_H
#define ALETHEIA_G_SCENESETSELECTAP_BSS_H
/* g_021DE60C (arm9) */
struct selobj;
struct SCENESETSELECTAP_BSS {
    unsigned char FocusPos;
    unsigned char pad_1[0x3];
    struct selobj *MemSssa;
};
#endif
