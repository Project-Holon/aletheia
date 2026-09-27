/*
 * function: CARD_InitPulledOutCallback
 * address:  0x020773DC
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02088498   0x02088498  arm
 *   func_020885A0   0x020885A0  arm
 *   d_02150B00      0x02150B00  data  a4
 *
 * Original (52 bytes):
 *   push {r3, r4, r5, lr}
 *   bl   #0x02088498
 *   ldr  r4, [pc, #0x1c]   ; &d_02150B00
 *   mov  r5, #0
 *   str  r5, [r4]
 *   ldr  r1, [pc, #0x14]   ; 0x02077410
 *   mov  r0, #0xe
 *   str  r5, [r4, #4]
 *   bl   #0x020885A0
 *   str  r5, [r4, #8]
 *   pop  {r3, r4, r5, pc}
 */

typedef unsigned int u32;

extern void func_02088498(void);
extern void func_020885A0(u32 id, void *callback);
extern char d_02150B00;

void CARD_InitPulledOutCallback(void)
{
    func_02088498();
    *(u32 *)((char *)&d_02150B00 + 0) = 0;
    *(u32 *)((char *)&d_02150B00 + 4) = 0;
    func_020885A0(0xe, (void *)0x02077410);
    *(u32 *)((char *)&d_02150B00 + 8) = 0;
}
