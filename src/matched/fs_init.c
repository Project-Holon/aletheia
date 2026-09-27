/*
 * function: FS_Init
 * address:  0x0207AD04
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0207AB10   0x0207AB10  arm
 *   func_02078C40   0x02078C40  arm
 *   d_02150E04      0x02150E04  data  a4
 *
 * Original (44 bytes):
 *   push  {r3, lr}
 *   ldr   r1, [pc, #0x1c]   ; &d_02150E04
 *   ldr   r2, [r1]
 *   cmp   r2, #0
 *   popne {r3, pc}
 *   mov   r2, #1
 *   str   r2, [r1]
 *   bl    #0x0207AB10
 *   bl    #0x02078C40
 *   pop   {r3, pc}
 */

typedef unsigned int u32;

extern void func_0207AB10(void);
extern void func_02078C40(void);
extern u32 d_02150E04;

void FS_Init(void)
{
    u32 *p = &d_02150E04;
    if (*p)
        return;
    *p = 1;
    func_0207AB10();
    func_02078C40();
}
