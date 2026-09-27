/*
 * function: CARDi_OnFifoRecv
 * address:  0x020763BC
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02085868   0x02085868  arm
 *   cardi_common    0x02150200  data  a4
 *
 * Original (52 bytes):
 *   push  {r3, lr}
 *   cmp   r0, #0xb
 *   popne {r3, pc}
 *   cmp   r2, #0
 *   popeq {r3, pc}
 *   ldr   r0, [pc, #0x14]   ; &cardi_common
 *   ldr   r1, [r0, #4]
 *   bic   r1, r1, #0x20
 *   str   r1, [r0, #4]
 *   ldr   r0, [r0, #0x51c]
 *   bl    #0x02085868
 *   pop   {r3, pc}
 */

typedef unsigned int u32;

typedef struct
{
    char pad0[4];
    u32 flags;        /* +0x04 */
    char pad8[0x51c - 8];
    u32 thread;       /* +0x51c */
} CARDiCommon;

extern void func_02085868(u32 thread);
extern CARDiCommon cardi_common;

void CARDi_OnFifoRecv(u32 a, u32 b, u32 c)
{
    (void)b;
    if (a != 0xb)
        return;
    if (c == 0)
        return;
    cardi_common.flags &= ~0x20u;
    func_02085868(cardi_common.thread);
}
