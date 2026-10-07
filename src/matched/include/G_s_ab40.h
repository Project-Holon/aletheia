#ifndef ALETHEIA_G_S_AB40_H
#define ALETHEIA_G_S_AB40_H
/* d_0217AB40 (ov015) */
struct s_ab40 {
    unsigned char pad_0[0x38];
    unsigned int f38;
    unsigned int f3c;
    unsigned char pad_40[0x4];
    unsigned int f44;
    int (*f48)(unsigned char, unsigned char);
};
#endif
