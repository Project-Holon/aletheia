#ifndef ALETHEIA_STATEDATA_TYPES_H
#define ALETHEIA_STATEDATA_TYPES_H

struct LevelUpMoveScan {
    unsigned short move;
    unsigned char pad_2[0x6];
    int counter;
    unsigned int remaining;
    unsigned int iter;
    unsigned char pad_14[0x10];
};

#endif
