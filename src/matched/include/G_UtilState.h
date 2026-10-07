#ifndef ALETHEIA_G_UTILSTATE_H
#define ALETHEIA_G_UTILSTATE_H
/* g_021DE56C (arm9) */
struct UtilState {
    unsigned char lang;
    unsigned char end;
    unsigned char pad_2[0x2];
    void *work;
    unsigned int param;
    void (*scene)(void);
    void (*scene_10)(void);
    void *f14;
};
#endif
