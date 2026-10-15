/*
 * function: NNSi_SndStrmAlarmHandler
 * address:  0x02073CA0
 * packet:   pkt_020737C0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Sound-object teardown guarded on bit 1 of the flags word at +0x2C: releases
 * the channel mask built from +0x48 with the handle at +0x4C, then brackets
 * func_02089B38(1) with the save/restore pair SND_GetCurrentCommandTag / SND_WaitForCommandProc.
 * It is NNS_SndStrmStop's tail with the two sub-object teardowns removed.
 *
 * PINNED ../2.0/sp2 on the repeated-small-constant tell, exactly as its
 * cluster siblings NNS_SndStrmSetVolume and NNS_SndStrmStop already are (see
 * docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md and
 * those two files' headers). The literal 1 is live twice (the `1 << o->f48`
 * shift argument and the func_02089B38 argument); under dsi/1.1p1 -O4,p this
 * body is 76 bytes with every instruction and relocation right but 5 bytes
 * out, all five from 1.1p1 pooling the 1 into a callee-saved register
 * (`mov r5,#1` / `lsl r2,r5,r2` / `mov r0,r5`), which also widens the
 * prologue from `push {r4,lr}` to `push {r3,r4,r5,lr}`. Under the pin the
 * same C is 76 bytes, 0 concrete mismatches.
 *
 * The guard is a SIGNED one-bit bitfield: the image reads it `lsl #30 /
 * asrs #31`, so `s32 b1 : 1` is required
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 *
 * symbols:
 *   SND_StopTimer  0x020894DC  arm
 *   SND_GetCurrentCommandTag  0x02089D40  arm
 *   func_02089B38  0x02089B38  arm
 *   SND_WaitForCommandProc  0x02089CD4  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_SndStrmAlarmHandler.c \
 *       --func NNSi_SndStrmAlarmHandler --addr 0x02073CA0 --cc ../2.0/sp2 --arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed   int   s32;

struct Obj {
    u8  pad_00[0x2c];
    u32 b0 : 1;       /* 0x2c */
    s32 b1 : 1;
    u32 b2 : 30;
    u8  pad_30[0x18];
    u32 f48;          /* 0x48 */
    u32 f4c;          /* 0x4c */
};

extern void SND_StopTimer(u32 a, u32 b, u32 c, u32 d);
extern u32  SND_GetCurrentCommandTag(void);
extern void func_02089B38(u32 a);
extern void SND_WaitForCommandProc(u32 a);

void NNSi_SndStrmAlarmHandler(struct Obj *o)
{
    u32 saved;

    if (!o->b1) return;
    SND_StopTimer(o->f4c, 0, 1u << o->f48, 0);
    saved = SND_GetCurrentCommandTag();
    func_02089B38(1);
    SND_WaitForCommandProc(saved);
}
