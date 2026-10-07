#ifndef ALETHEIA_G_TBL_H
#define ALETHEIA_G_TBL_H
/* g_021F3ECC (arm9) */
struct Tbl {
    unsigned int count;
    unsigned short keys[96];
    unsigned int vals[96];
    unsigned int a[96];
    unsigned int b[96];
    unsigned char c[96];
};
#endif
