/*
 * function: FNDHEAP_Finalize
 * address:  0x0206074C
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020606A8   0x020606A8  arm
 *   func_020605B4   0x020605B4  arm
 *
 * Original (24 bytes):
 *   push {r4, lr}
 *   mov  r4, r0
 *   bl   #0x020606A8
 *   mov  r1, r4
 *   bl   #0x020605B4
 *   pop  {r4, pc}
 *
 * The first call keeps the incoming r0.
 */

typedef unsigned int   u32;
extern void *func_020606A8(u32 a);
struct DList;
extern void func_020605B4(volatile struct DList *list, void *elem);

void FNDHEAP_Finalize(void *p)
{
    func_020605B4(func_020606A8((u32)p), p);
}
