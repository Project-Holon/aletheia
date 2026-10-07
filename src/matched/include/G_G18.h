#ifndef ALETHEIA_G_G18_H
#define ALETHEIA_G_G18_H
/* g_02148718 (arm9) */
struct Aff;
struct G18 {
    unsigned short currentCellAnimIdx;
    unsigned short pad16_;
    struct Aff *arr04[256];
    int bDrawMC;
};
#endif
