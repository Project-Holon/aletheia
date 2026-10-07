#ifndef ALETHEIA_G_SLOT_H
#define ALETHEIA_G_SLOT_H
/* D_0218A7C0 (arm9) */
struct Slot {
    unsigned char id[4];
    unsigned char ref[4];
    void *obj[4];
};
#endif
