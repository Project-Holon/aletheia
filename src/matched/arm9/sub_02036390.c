/*
 * function: KEY_ClearFrameRateWork
 * address:  0x02036390
 * packet:   pkt_020362EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203521C  0x0203521C  arm
 *
 * Zeroes the six-word block at +0x24 of the record func_0203521C resolves
 * its argument to.  The other follow-up pass that src/pending/UI_ChangeFrameRate.c
 * runs (see src/matched/TOUCHPANEL_ClearFrameRateWork.c for the first).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/KEY_ClearFrameRateWork.c \
 *       --func KEY_ClearFrameRateWork --addr 0x02036390 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Rec {
    u8 pad_00[0x24];
    u32 unk24;
    u32 unk28;
    u32 unk2c;
    u32 unk30;
    u32 unk34;
    u32 unk38;
};

extern u32 func_0203521C(u32 *p);

void KEY_ClearFrameRateWork(struct Rec *p)
{
    struct Rec *rec = (struct Rec *)func_0203521C((u32 *)p);

    rec->unk24 = 0;
    rec->unk28 = 0;
    rec->unk2c = 0;
    rec->unk30 = 0;
    rec->unk34 = 0;
    rec->unk38 = 0;
}
