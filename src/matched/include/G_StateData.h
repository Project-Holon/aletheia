#ifndef ALETHEIA_G_STATEDATA_H
#define ALETHEIA_G_STATEDATA_H
/* g_021F3B64 (arm9) */
struct StateData {
    unsigned short move;
    unsigned char pad_2[0x6];
    int counter;
    unsigned int remaining;
    unsigned int iter;
    unsigned char pad_14[0x10];
};
#endif
