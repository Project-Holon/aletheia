#ifndef ALETHEIA_G_GXDATASTATE_H
#define ALETHEIA_G_GXDATASTATE_H
/* sIsDispOn (arm9) */
struct GXDataState {
    unsigned short isDispOn;
    unsigned char pad_2[0x2];
    unsigned int dmaId;
};
#endif
