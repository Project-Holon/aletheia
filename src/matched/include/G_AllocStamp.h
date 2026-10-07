#ifndef ALETHEIA_G_ALLOCSTAMP_H
#define ALETHEIA_G_ALLOCSTAMP_H
/* g_020A7E7C (arm9) */
struct AllocStamp {
    unsigned short value;
    unsigned short pad;
    char site[1];
};
#endif
