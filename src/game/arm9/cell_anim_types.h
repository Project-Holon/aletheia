#ifndef GAME_ARM9_CELL_ANIM_TYPES_H
#define GAME_ARM9_CELL_ANIM_TYPES_H

/* Cell animation object (0x58 bytes in MultiCellAnim, see nns_g2d_multi_cell_animation_2.c). */

struct O02064140;
struct CellDataBank;

struct CellAnimHdr {
    unsigned char  pad00[4];
    unsigned short count;
};

struct CellBank {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int attr;
};

struct CellAnim {
    unsigned int        f00;
    struct CellAnimHdr *hdr;
    unsigned int        f08;
    unsigned int        active;
    unsigned char       pad10[0x18 - 0x10];
    unsigned int        attrOverride;
    struct CellBank    *bank;
    unsigned int        callBackType;
    unsigned int        callBackParam;
    unsigned int        callBackFunc;
    unsigned short      callBackFrameIdx;
    unsigned char       pad2e[2];
    int                 f30;
    struct CellDataBank *dataBank;
    int                 f38;
    unsigned char       sub3c[0x1c];
};

#endif
