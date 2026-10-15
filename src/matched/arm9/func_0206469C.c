/*
 * function: NNS_G2dSetAnimSequenceToMCAnimation
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
 * the descriptor and the node's own u16 counter at +0x30 to NNSi_G2dSetMCDataToMCInstanceImpl.
 *
 * PIN ../2.0/sp2: the "kept branches" tell in its CROSS-JUMP form, the same
 * one src/matched/NNS_G2dSetMCAnimationCurrentFrame.c and src/matched/NNSi_G2dRefreshCellAnimation.c carry.  The
 * image writes the kind==2 arm's `add r0, r4, #0x48` / `bl NNS_G2dSetSRTTranslate` tail
 * out in its own arm although the other arm's LAST call is a byte-identical
 * pair; 1.1p1 -O4,p cross-jumps the two and lands at 176 bytes against the
 * original's 184, 73 concrete bytes out (docs/notes/pkt_0206469C.c.txt, which
 * measured the goto/if-else/switch spellings and found them all folding).
 * Under the pin this SAME C is 184 bytes, 0 mismatches, all 9 sites by label.
 *
 * symbols:
 *   func_020629E8   0x020629E8  arm
 *   func_02062D40   0x02062D40  arm
 *   NNS_G2dSetCellAnimationBank   0x02062FF0  arm
 *   NNS_G2dSetSRTTranslate   0x020640DC  arm
 *   NNS_G2dSetSRTRotate   0x02064100  arm
 *   NNS_G2dSetSRTScale   0x02064120  arm
 *   NNSi_G2dSrtcInitControl   0x02064140  arm
 *   NNSi_G2dSetMCDataToMCInstanceImpl   0x020643CC  arm
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
extern void NNS_G2dSetCellAnimationBank(struct CellAnim *anim, void *bank);
extern void *func_02062D40(struct CellAnim *anim);
struct MultiCellBank;
struct MultiCellData;
extern struct MultiCellData *func_020629E8(struct MultiCellBank *bank, u32 idx);
extern void NNSi_G2dSrtcInitControl(struct O02064140 *o, u32 a);
extern void NNS_G2dSetSRTTranslate(struct Srt0206469C *srt, s16 x, s16 y);
struct Obj02064100;
extern void NNS_G2dSetSRTRotate(struct Obj02064100 *obj, u16 val);
extern void NNS_G2dSetSRTScale(struct Srt0206469C *srt, u32 sx, u32 sy);
struct MCInstance;
extern void NNSi_G2dSetMCDataToMCInstanceImpl(struct MCInstance *pMCInst, const struct MultiCellData *pMcData, u16 mcTotalFrame);

void NNS_G2dSetAnimSequenceToMCAnimation(struct Obj0206469C *o, void *bank)
{
    struct Node0206469C *p;
    u32 k;
    u32 r;

    NNS_G2dSetCellAnimationBank((struct CellAnim *)o, bank);
    o->unk_30 = 0;

    if (((struct Obj16437 *)(o->unk_04))->f4 == 0) {
        return;
    }

    p = func_02062D40((struct CellAnim *)o);
    r = (u32)func_020629E8(o->unk_44, p->unk_00);
    k = o->unk_1c->kind & 0xff;

    NNSi_G2dSrtcInitControl((struct O02064140 *)(&o->unk_48), 1);

    if (k == 0) {
        goto done;
    }

    if (k == 2) {
        NNS_G2dSetSRTTranslate(&o->unk_48, p->unk_04, p->unk_06);
    } else {
        NNS_G2dSetSRTScale(&o->unk_48, *(u32 *)&p->unk_04, p->unk_08);
        NNS_G2dSetSRTRotate((struct Obj02064100 *)(&o->unk_48), p->unk_02);
        NNS_G2dSetSRTTranslate(&o->unk_48, p->unk_0c, p->unk_0e);
    }

done:
    NNSi_G2dSetMCDataToMCInstanceImpl((struct MCInstance *)o->unk_34, (const struct MultiCellData *)r, o->unk_30);
}
