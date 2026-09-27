/*
 * function: FSi_ROMFAT_Unmount
 * address:  0x0207A234
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0207A7A8   0x0207A7A8  arm
 *
 * Original (60 bytes):
 *   push {r4, lr}
 *   ldr  r4, [r0, #0x20]
 *   bl   #0x0207A7A8
 *   mov  r0, #0
 *   str  r0, [r4]
 *   ... seven zero words ...
 *   pop  {r4, pc}
 */

typedef unsigned int u32;

extern int func_0207A7A8(void *arc);

void FSi_ROMFAT_Unmount(void *arc)
{
    u32 *p = *(u32 **)((char *)arc + 0x20);
    func_0207A7A8(arc);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
}
