#ifndef ALETHEIA_G_DOUBLE3DDISP_H
#define ALETHEIA_G_DOUBLE3DDISP_H
/* gDouble3Ddisp (arm9) */
struct Double3Ddisp {
    unsigned short heap;
    unsigned short pad02;
    signed int unk04;
    signed int unk08;
    unsigned int oam_0_w[2];
    unsigned int oam_1_w[2];
    unsigned int oam_2_w[2];
    unsigned int oam_3_w[2];
    unsigned int oam_4_w[2];
    unsigned int oam_5_w[2];
    unsigned int oam_6_w[2];
    unsigned int oam_7_w[2];
    unsigned int oam_8_w[2];
    unsigned int oam_9_w[2];
    unsigned int oam_10_w[2];
    unsigned int oam_11_w[2];
};
#endif
