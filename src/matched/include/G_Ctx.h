#ifndef ALETHEIA_G_CTX_H
#define ALETHEIA_G_CTX_H
/* gNetIrcWirelessLink (arm9) */
struct Ctx {
    unsigned char pad_0[0x18];
    void *base_fn_18;
    void *base_fn_1c;
    unsigned char pad_20[0xC];
    void *base_fn_2c;
    unsigned char pad_30[0x24];
    unsigned short base_heap;
    unsigned char pad_56[0xA];
    unsigned char base_f60;
    unsigned char pad_61[0x3];
    unsigned char base_f64;
    unsigned char base_f65;
    unsigned char pad_66;
    unsigned char f67;
    unsigned char pad_68[0x6];
    unsigned short f6e;
    unsigned int arg;
    unsigned int f74;
    void * (*fn_18)(void *);
    void * (*fn)(void *);
    void *fn_2c;
    void (*f84)(unsigned int);
    void (*f88)(unsigned int, int);
    void (*f8c)(unsigned int);
    unsigned char f90[4];
    unsigned char f94[108];
    unsigned char f100;
    unsigned char f101;
    unsigned char f102;
    unsigned char f103;
    unsigned char f104;
    unsigned char f105;
    unsigned char f106;
    unsigned char f107;
    unsigned char f108;
    unsigned char f109;
    unsigned char f10a;
    unsigned char f10b;
};
#endif
