#ifndef ALETHEIA_G_GXLOAD2DSTATE_H
#define ALETHEIA_G_GXLOAD2DSTATE_H
/* sSubBGExtPltt (arm9) */
struct GXLoad2DState {
    int subBGExtPltt;
    unsigned int objExtPlttLCDCBlk;
    int objExtPltt;
    unsigned int bgExtPlttLCDCOffset;
    unsigned int bgExtPlttLCDCBlk;
    int bgExtPltt;
    int subOBJExtPltt;
};
#endif
