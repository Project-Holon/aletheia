/*
 * function: NNS_G2dSetMCAnimationCurrentFrame
 * address:  0x02064AB4
 * packet:   pkt_02064934
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * PIN ../2.0/sp2: the "kept branches" tell.  The image writes the case-2
 * call tail out in its own arm -- `add r0, r4, #0x48` (0x02064B20) /
 * `bl NNS_G2dSetSRTTranslate` (0x02064B24) / `b 0x02064B54` (0x02064B28) -- although
 * the default arm ends in a byte-identical `add r0, r4, #0x48` /
 * `bl NNS_G2dSetSRTTranslate` pair at 0x02064B4C/0x02064B50.  1.1p1 -O4,p cross-jumps
 * the two, branching case 2 into the default arm's pair and giving 172 bytes
 * against the original's 180, 64 concrete bytes out.  Two independent lanes
 * measured a dozen spellings (switch arm order, if-chain, goto tail, named
 * s16 locals, nested switch) and all cross-jump.  Under the pin the same C
 * is 180 bytes, 0 mismatches.
 *
 * symbols:
 *   NNSi_G2dSetCellAnimationCurrentFrame  0x02062F00  arm
 *   NNSi_G2dGetCellAnimationCurrentSequence  0x02062D40  arm
 *   NNS_G2dGetMultiCellDataByIdx  0x020629E8  arm
 *   NNSi_G2dSrtcInitControl  0x02064140  arm
 *   NNS_G2dSetSRTTranslate  0x020640DC  arm
 *   NNS_G2dSetSRTScale  0x02064120  arm
 *   NNS_G2dSetSRTRotate  0x02064100  arm
 *   NNSi_G2dSetMCDataToMCInstanceImpl  0x020643CC  arm
 *
 * Same body as NNS_G2dTickMCAnimation from the header test down, but with a guard
 * that returns early instead of the missed-lookup arm, and no call to
 * NNSi_G2dTickMCInstance.  The early-out is ONE expression: the two tests are
 * predicated onto a single `popeq` (`ldrne`/`cmpne`/`popeq`), which is what
 * makes it a `||` inside a single `if` rather than two `if`s (two separate
 * guards would each need their own `pop`).
 */
#include "../include/Obj03475.h"
#include "../include/Obj07024.h"

typedef unsigned int   u32;
extern int NNSi_G2dSetCellAnimationCurrentFrame(void *s, u32 i);
struct CellAnim;
struct O02064140;
extern void *NNSi_G2dGetCellAnimationCurrentSequence(struct CellAnim *anim);
typedef unsigned short u16;
struct MCInstance;
struct MultiCellBank;
struct MultiCellData;
extern struct MultiCellData *NNS_G2dGetMultiCellDataByIdx(struct MultiCellBank *bank, u32 idx);
extern void NNSi_G2dSrtcInitControl(struct O02064140 *o, u32 a);
extern void NNS_G2dSetSRTTranslate(char *self, int a, int b);
extern void NNS_G2dSetSRTScale(char *self, int a, int b);
struct Obj02064100;
extern void NNS_G2dSetSRTRotate(struct Obj02064100 *obj, u16 val);
extern void NNSi_G2dSetMCDataToMCInstanceImpl(struct MCInstance *pMCInst, const struct MultiCellData *pMcData, u16 mcTotalFrame);

void NNS_G2dSetMCAnimationCurrentFrame(char *self, unsigned int i)
{
    char *p;
    int kind;
    int item;

    if (NNSi_G2dSetCellAnimationCurrentFrame(self, i) == 0 || *(unsigned short *)(((struct Obj07024 *)self)->f4 + 4) == 0)
        return;
    p = NNSi_G2dGetCellAnimationCurrentSequence((struct CellAnim *)self);
    item = (int)NNS_G2dGetMultiCellDataByIdx((struct MultiCellBank *)(((struct Obj07024 *)self)->f44), ((struct Obj03475 *)p)->f0);
    kind = *(int *)(((struct Obj07024 *)self)->f1C + 4) & 0xff;
    NNSi_G2dSrtcInitControl((struct O02064140 *)(self + 0x48), 1);
    switch (kind) {
    case 0:
        break;
    case 2:
        NNS_G2dSetSRTTranslate(self + 0x48, *(short *)&((struct Obj03475 *)p)->f4, *(short *)(p + 6));
        break;
    default:
        NNS_G2dSetSRTScale(self + 0x48, ((struct Obj03475 *)p)->f4, ((struct Obj03475 *)p)->f8);
        NNS_G2dSetSRTRotate((struct Obj02064100 *)(self + 0x48), ((struct Obj03475 *)p)->f2);
        NNS_G2dSetSRTTranslate(self + 0x48, ((struct Obj03475 *)p)->fC, ((struct Obj03475 *)p)->fE);
        break;
    }
    NNSi_G2dSetMCDataToMCInstanceImpl((struct MCInstance *)(self + 0x34), (const struct MultiCellData *)item, ((struct Obj07024 *)self)->f30);
}
