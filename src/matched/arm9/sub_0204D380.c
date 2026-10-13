/*
 * unit:     no
 * function: CLACT_SetVramAnimSeq
 * address:  0x0204D380
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_020627D8  0x020627D8  arm
 *   sub_0206469C  0x0206469C  arm
 *
 * The third member of the CLACT_SetCellAnimSeq / CLACT_SetMultiCellAnimSeq trio, reading the
 * handle from +0x74 instead of +8 and finishing in sub_0206469C instead of
 * sub_0206434C.  The shared middle step, sub_020627D8 on the handle, is
 * what says these three are the same operation over different slots.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetVramAnimSeq.c \
 *       --func CLACT_SetVramAnimSeq --addr 0x0204D380 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Rec {
    u8 unk_00[1];
};

struct Obj {
    u8         pad_00[0xc];
    struct Rec unk_0c;
    u8         pad_0d[0x74 - 0xd];
    void      *unk_74;
};

struct AnimBank;
struct AnimSequence;
extern struct AnimSequence *sub_020627D8(struct AnimBank *bank, u32 idx);
struct Obj0206469C;
extern void sub_0206469C(struct Obj0206469C *o, void *bank);

void CLACT_SetVramAnimSeq(struct Obj *o, u32 idx)
{
    sub_0206469C((struct Obj0206469C *)(&o->unk_0c), sub_020627D8(o->unk_74, idx));
}
