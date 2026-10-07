#ifndef ALETHEIA_G_AOSSCTL_H
#define ALETHEIA_G_AOSSCTL_H
/* g_021DE564 (arm9) */
struct AossCtl {
    unsigned char status;
    unsigned char pad_1[0x3];
    void *work;
};
#endif
