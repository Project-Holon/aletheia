/*
 * function: func_0206469C
 * address:  0x0206469C
 * packet:   pkt_020640DC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Rebuilds one multi-cell node's SRT block from its current NANR frame record.
 * The node record comes through func_02062D40 and its descriptor through
 * func_020629E8; the frame's kind byte (a word masked with 0xff, not a ldrb)
 * selects the arm: 0 does nothing, 2 is translation-only, anything else is the
 * full SRT form (scale, rotation, translation).  The walk finishes by handing
 * the descriptor and the node's own u16 counter at +0x30 to func_020643CC.
 *
 * PIN ../2.0/sp2: the "kept branches" tell in its CROSS-JUMP form, the same
 * one src/matched/func_02064AB4.c and src/matched/func_0206419C.c carry.  The
 * image writes the kind==2 arm's `add r0, r4, #0x48` / `bl func_020640DC` tail
 * out in its own arm although the other arm's LAST call is a byte-identical
 * pair; 1.1p1 -O4,p cross-jumps the two and lands at 176 bytes against the
 * original's 184, 73 concrete bytes out (docs/notes/pkt_0206469C.c.txt, which
 * measured the goto/if-else/switch spellings and found them all folding).
 * Under the pin this SAME C is 184 bytes, 0 mismatches, all 9 sites by label.
 *
 * symbols:
 *   func_020629E8   0x020629E8  arm
 *   func_02062D40   0x02062D40  arm
 *   func_02062FF0   0x02062FF0  arm
 *   func_020640DC   0x020640DC  arm
 *   func_02064100   0x02064100  arm
 *   func_02064120   0x02064120  arm
 *   func_02064140   0x02064140  arm
 *   func_020643CC   0x020643CC  arm
 */
#include "../include/Obj16437.h"
typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

struct Srt0206469C {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    s16 unk_0c;
    s16 unk_0e;
    u16 unk_10;
    u16 unk_12;
};

struct FrameHdr0206469C {
    u8  pad_00[4];
    u32 kind;
};

struct Node0206469C {
    u16 unk_00;
    u16 unk_02;
    s16 unk_04;
    s16 unk_06;
    u32 unk_08;
    s16 unk_0c;
    s16 unk_0e;
};

struct Obj0206469C {
    u8  pad_00[4];
    u8 *unk_04;
    u8  pad_08[0x14];
    struct FrameHdr0206469C *unk_1c;
    u8  pad_20[0x10];
    u16 unk_30;
    u8  pad_32[2];
    u32 unk_34[4];
    void *unk_44;
    struct Srt0206469C unk_48;
};

struct CellAnim;
struct O02064140;
extern void func_02062FF0(struct CellAnim *anim, void *bank);
extern void *func_02062D40(struct CellAnim *anim);
struct MultiCellBank;
struct MultiCellData;
extern struct MultiCellData *func_020629E8(struct MultiCellBank *bank, u32 idx);
extern void func_02064140(struct O02064140 *o, u32 a);
extern void func_020640DC(struct Srt0206469C *srt, s16 x, s16 y);
extern void func_02064100(struct Srt0206469C *srt, u16 rot);
extern void func_02064120(struct Srt0206469C *srt, u32 sx, u32 sy);
struct MCInstance;
extern void func_020643CC(struct MCInstance *pMCInst, const struct MultiCellData *pMcData, u16 mcTotalFrame);

void func_0206469C(struct Obj0206469C *o, void *bank)
{
    struct Node0206469C *p;
    u32 k;
    u32 r;

    func_02062FF0((struct CellAnim *)o, bank);
    o->unk_30 = 0;

    if (((struct Obj16437 *)(o->unk_04))->f4 == 0) {
        return;
    }

    p = func_02062D40((struct CellAnim *)o);
    r = (u32)func_020629E8(o->unk_44, p->unk_00);
    k = o->unk_1c->kind & 0xff;

    func_02064140((struct O02064140 *)(&o->unk_48), 1);

    if (k == 0) {
        goto done;
    }

    if (k == 2) {
        func_020640DC(&o->unk_48, p->unk_04, p->unk_06);
    } else {
        func_02064120(&o->unk_48, *(u32 *)&p->unk_04, p->unk_08);
        func_02064100(&o->unk_48, p->unk_02);
        func_020640DC(&o->unk_48, p->unk_0c, p->unk_0e);
    }

done:
    func_020643CC((struct MCInstance *)o->unk_34, (const struct MultiCellData *)r, o->unk_30);
}
