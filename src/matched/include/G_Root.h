#ifndef ALETHEIA_G_ROOT_H
#define ALETHEIA_G_ROOT_H
/* gCurrentRS (arm9) */
struct Root {
    void *h;
    unsigned char pad_4[0xC0];
    unsigned int bits[1];
    unsigned char pad_C8[0xC];
    void *bank;
    unsigned char pad_D8[0x10];
    void (*hook)(void *, void *, void *, unsigned int);
};
#endif
