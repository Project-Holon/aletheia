#ifndef ALETHEIA_G_SND_H
#define ALETHEIA_G_SND_H
/* g_021DE648 (arm9) */
struct SND {
    unsigned char pad_0[0xA0];
    int handle;
    void *arc;
    void *task;
    int pad2;
};
#endif
