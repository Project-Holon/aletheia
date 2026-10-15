/*
 * function: NNS_G2dSetCellAnimationSequence
 * address:  0x0206434C
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G2dSetCellAnimationBank   0x02062FF0  arm
 *   NNSi_G2dRefreshCellAnimation   0x0206419C  arm
 *
 * Original (24 bytes):
 *   push {r4, lr}
 *   mov  r4, r0
 *   bl   #0x02062FF0
 *   mov  r0, r4
 *   bl   #0x0206419C
 *   pop  {r4, pc}
 *
 * Sets a cell animation's sequence: seq arrives in r1 and is forwarded
 * untouched to NNS_G2dSetCellAnimationBank, then the animation is restarted.  The SDK
 * table's name NNS_G2dSetCellAnimationSequence for this address sits in the rejected
 * list of layout/symbols_sdk.json, so the name is suspect.
 */

struct CellAnim;
extern void NNS_G2dSetCellAnimationBank(struct CellAnim *anim, void *bank);
extern void NNSi_G2dRefreshCellAnimation(char *self);

void NNS_G2dSetCellAnimationSequence(void *anim, void *seq)
{
    NNS_G2dSetCellAnimationBank(anim, seq);
    NNSi_G2dRefreshCellAnimation(anim);
}
