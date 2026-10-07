#ifndef ALETHEIA_G_NDSTATE_H
#define ALETHEIA_G_NDSTATE_H
/* g_021D3B68 (arm9) */
struct NdState {
    void (*cb)(int, int, int);
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    void *svl;
};
#endif
