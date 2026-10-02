/*
 * function: ENV_SetResourceSet
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
 *   func_02062FF0   0x02062FF0  arm
 *   func_0206419C   0x0206419C  arm
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
 * untouched to func_02062FF0, then the animation is restarted.  The SDK
 * table's name ENV_SetResourceSet for this address sits in the rejected
 * list of layout/symbols_sdk.json, so the name is suspect.
 */

extern void func_02062FF0(void *anim, void *seq);
extern void func_0206419C(void *anim);

void ENV_SetResourceSet(void *anim, void *seq)
{
    func_02062FF0(anim, seq);
    func_0206419C(anim);
}
