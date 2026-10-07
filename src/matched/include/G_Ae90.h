#ifndef ALETHEIA_G_AE90_H
#define ALETHEIA_G_AE90_H
/* g_021CAE90 (arm9) */
struct Ae90 {
    unsigned short tag;
    unsigned short type;
    unsigned int count;
    signed char f8;
    unsigned char pad9;
    signed short fa;
    unsigned int fc;
    unsigned int f10;
    unsigned int f14;
    unsigned char field18[30];
    char str[30];
    unsigned int field54;
};
#endif
