/*
 * function: NNS_G2dTickMCAnimation
 * address:  0x020649D4
 * packet:   pkt_020640DC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The tick-driven form of NNS_G2dSetMCAnimationCurrentFrame: steps the multi-cell animation by a
 * fx32 tick through NNS_G2dTickAnimCtrl and, when that reports no advance, hands the
 * whole walk block at +0x34 to NNSi_G2dTickMCInstance instead.  From the header test
 * down the body is NNS_G2dSetMCAnimationCurrentFrame's verbatim.
 *
 * PIN ../2.0/sp2, inherited from the sibling src/matched/NNS_G2dSetMCAnimationCurrentFrame.c: the
 * same case-2 cross-jump.  1.1p1 -O4,p shares case 2's
 * `add r0, r4, #0x48` / `bl NNS_G2dSetSRTTranslate` tail with the default arm's
 * identical pair at 0x02064A88/0x02064A8C and lands at 220 bytes against the
 * original's 224 (docs/notes/pkt_02064934.NNS_G2dTickMCAnimation.c.txt).
 *
 * THREE C LEVERS, all needed and all found in this pass:
 *  1. NNS_G2dTickAnimCtrl IS ARITY TWO, not three.  The note's body declared a third
 *     parameter and passed the latched halfword `t`; that costs a `mov r2, r5`
 *     at 0x020649E8 and the compile is 228 bytes.  The image sets only r0/r1.
 *  2. THE MISS ARM MUST BE A `goto` TO THE FUNCTION'S TAIL.  Written inline as
 *     `{ NNSi_G2dTickMCInstance(...); return; }` the compiler emits it in place under a
 *     `bne` where the image emits `beq #0x2064aa4` over the whole body to an
 *     arm placed AFTER the main epilogue.  Size-exact either way; the inline
 *     form is 140 concrete bytes out because everything after +0x1C is shifted
 *     by one instruction.
 *  3. `int kind;` MUST BE DECLARED BEFORE `int r7;`.  Declaration order is
 *     stack/colour order here: the reverse puts the masked kind in r7 and the
 *     descriptor in r6, where the image has kind in r6 and the descriptor in
 *     r7 (docs/idioms/declaration-order-decides-which-register-a-local-gets.md).
 *
 * The +0x2C PC24 to NNSi_G2dTickMCInstance resolves by `sole-ref/code`: 0x02064934 is a
 * traced function start and this `bl` is its only branch image-wide, which is
 * exactly the single-caller shape `label` cannot reach.
 *
 * symbols:
 *   NNS_G2dTickAnimCtrl  0x02062D4C  arm
 *   NNSi_G2dTickMCInstance  0x02064934  arm
 *   NNSi_G2dGetCellAnimationCurrentSequence  0x02062D40  arm
 *   NNS_G2dGetMultiCellDataByIdx  0x020629E8  arm
 *   NNSi_G2dSrtcInitControl  0x02064140  arm
 *   NNS_G2dSetSRTTranslate  0x020640DC  arm
 *   NNS_G2dSetSRTScale  0x02064120  arm
 *   NNS_G2dSetSRTRotate  0x02064100  arm
 *   NNSi_G2dSetMCDataToMCInstanceImpl  0x020643CC  arm
 */
#include "../include/Obj03474.h"
#include "../include/Obj04783.h"

extern int NNS_G2dTickAnimCtrl(char *self, int a1);
struct CellAnim;
struct Root;
extern void NNSi_G2dTickMCInstance(struct Root *p, int arg);
extern void *NNSi_G2dGetCellAnimationCurrentSequence(struct CellAnim *anim);
typedef unsigned short u16;
typedef unsigned int   u32;
struct MCInstance;
struct MultiCellBank;
struct MultiCellData;
extern struct MultiCellData *NNS_G2dGetMultiCellDataByIdx(struct MultiCellBank *bank, u32 idx);
struct O02064140;
extern void NNSi_G2dSrtcInitControl(struct O02064140 *o, u32 a);
extern void NNS_G2dSetSRTTranslate(char *self, int a, int b);
extern void NNS_G2dSetSRTScale(char *self, int a, int b);
struct Obj02064100;
extern void NNS_G2dSetSRTRotate(struct Obj02064100 *obj, u16 val);
extern void NNSi_G2dSetMCDataToMCInstanceImpl(struct MCInstance *pMCInst, const struct MultiCellData *pMcData, u16 mcTotalFrame);

void NNS_G2dTickMCAnimation(char *self, int a1)
{
    unsigned short t = *(unsigned short *)(((struct Obj04783 *)self)->f0 + 4);
    char *p;
    int kind;
    int r7;

    if (NNS_G2dTickAnimCtrl(self, a1) == 0) {
        goto miss;
    }
    ((struct Obj04783 *)self)->f30 += t;
    if (*(unsigned short *)(((struct Obj04783 *)self)->f4 + 4) == 0)
        return;
    p = NNSi_G2dGetCellAnimationCurrentSequence((struct CellAnim *)self);
    r7 = (int)NNS_G2dGetMultiCellDataByIdx((struct MultiCellBank *)(((struct Obj04783 *)self)->f44), ((struct Obj03474 *)p)->f0);
    kind = *(int *)(((struct Obj04783 *)self)->f1C + 4) & 0xff;
    NNSi_G2dSrtcInitControl((struct O02064140 *)(self + 0x48), 1);
    switch (kind) {
    case 0:
        break;
    case 2:
        NNS_G2dSetSRTTranslate(self + 0x48, *(short *)&((struct Obj03474 *)p)->f4, *(short *)(p + 6));
        break;
    default:
        NNS_G2dSetSRTScale(self + 0x48, ((struct Obj03474 *)p)->f4, ((struct Obj03474 *)p)->f8);
        NNS_G2dSetSRTRotate((struct Obj02064100 *)(self + 0x48), ((struct Obj03474 *)p)->f2);
        NNS_G2dSetSRTTranslate(self + 0x48, ((struct Obj03474 *)p)->fC, ((struct Obj03474 *)p)->fE);
        break;
    }
    NNSi_G2dSetMCDataToMCInstanceImpl((struct MCInstance *)(self + 0x34), (const struct MultiCellData *)r7, ((struct Obj04783 *)self)->f30);
    return;
miss:
    NNSi_G2dTickMCInstance((struct Root *)(self + 0x34), a1);
}
