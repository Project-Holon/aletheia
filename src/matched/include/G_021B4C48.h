#ifndef ALETHEIA_G_021B4C48_H
#define ALETHEIA_G_021B4C48_H
/* d_021B4C48 (arm9) */
struct G_021B4C48 {
    signed short att;
    signed short pad0;
    signed int pad1;
    signed int rd;
    signed int wr;
    signed int pad4;
    signed int c[6];
    signed int x[6];
    unsigned char pad_44[0x440];
    signed short buf[2048];
};
#endif
