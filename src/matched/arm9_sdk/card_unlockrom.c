/*
 * function: CARD_UnlockRom
 * address:  0x02075E80
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02084E10   0x02084E10  arm
 *   func_02075F4C   0x02075F4C  arm
 *
 * Original (28 bytes):
 *   push {r4, lr}
 *   mov  r4, r0
 *   bl   #0x02084E10
 *   mov  r0, r4
 *   mov  r1, #1
 *   bl   #0x02075F4C
 *   pop  {r4, pc}
 */

extern int func_02084E10(unsigned int id);
typedef signed int     s32;
extern void func_02075F4C(s32 owner, int target);

void CARD_UnlockRom(unsigned int id)
{
    func_02084E10(id);
    func_02075F4C(id, 1);
}
