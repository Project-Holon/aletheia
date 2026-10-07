#ifndef ALETHEIA_G_BLOCK_H
#define ALETHEIA_G_BLOCK_H
/* d_021D4098 (arm9) */
struct Block {
    unsigned int buf[60];
    unsigned char first;
    unsigned char second;
    unsigned char third;
    unsigned char pad_F3[0x5];
    unsigned int pair[2];
    unsigned int buf2[32];
    unsigned int value;
};
#endif
