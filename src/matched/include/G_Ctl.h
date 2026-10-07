#ifndef ALETHEIA_G_CTL_H
#define ALETHEIA_G_CTL_H
/* g_0214BAC0 (arm9) */
struct Ctl {
    signed char b00;
    unsigned char p01[3];
    unsigned int pending;
    unsigned int tag;
    unsigned int f0c;
    void (*cb10_fn)(void *);
    void *cb10_arg;
    void *cb10_p08;
    void *cb10_p0c;
    void (*cb20_fn)(void *);
    void *cb20_arg;
    void *cb20_p08;
    void *cb20_p0c;
};
#endif
