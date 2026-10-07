#ifndef ALETHEIA_G_OV015_0217ABA8_H
#define ALETHEIA_G_OV015_0217ABA8_H
/* d_0217ABA8 (ov015) */
struct G_ov015_0217ABA8 {
    int f0;
    int f4;
    void (*onData)(unsigned char *, unsigned char, unsigned char, unsigned char);
    int fC;
    void (*onDone)(unsigned char, int);
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    unsigned long long tick;
};
#endif
