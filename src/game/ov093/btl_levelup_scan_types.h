#ifndef ALETHEIA_STATEDATA_TYPES_H
#define ALETHEIA_STATEDATA_TYPES_H

#include "../version.h"

struct LevelUpMoveScan {
    unsigned short move;
#if LANGUAGE == LANGUAGE_JAPANESE
    unsigned char pad_2[0x2];
    int counter;
    unsigned char pad_8[4];
    unsigned int iter;
    unsigned int remaining;
    unsigned char pad_14[0xc];
#else
    unsigned char pad_2[0x6];
    int counter;
    unsigned int remaining;
    unsigned int iter;
    unsigned char pad_14[0x10];
#endif
};

#endif
