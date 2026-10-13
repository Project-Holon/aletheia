#ifndef ALETHEIA_G_ARCHDR_H
#define ALETHEIA_G_ARCHDR_H
/* gNNSSndArcWaveArcHeader (arm9) */
struct ArcHdr {
    unsigned int pad[14];
    unsigned int count;
    unsigned int off[1];
};
#endif
