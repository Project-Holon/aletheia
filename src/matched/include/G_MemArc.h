#ifndef ALETHEIA_G_MEMARC_H
#define ALETHEIA_G_MEMARC_H
/* g_021DE66C (arm9) */
struct MemArc {
    void *table;
    void *file[32];
    void *queue;
    unsigned char pad_88[0x5C];
    unsigned short lockId;
};
#endif
