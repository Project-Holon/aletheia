/*
 * function: CARDi_ICInvalidateSmart
 * address:  0x02076344
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02086320   0x02086320  arm
 *   func_0208632C   0x0208632C  arm
 *
 * Original (28 bytes):
 *   push {r3, lr}
 *   cmp  r1, r2
 *   blo  #0x02076358
 *   bl   #0x02086320
 *   pop  {r3, pc}
 *   bl   #0x0208632C
 *   pop  {r3, pc}
 */

extern void func_02086320(void);
extern void func_0208632C(void *p, unsigned int size);

void CARDi_ICInvalidateSmart(void *p, unsigned int a, unsigned int b)
{
    if (a >= b)
        func_02086320();
    else
        func_0208632C(p, a);
}
