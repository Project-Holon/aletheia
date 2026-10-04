/*
 * function: func_021C6BEC
 * address:  0x021C6BEC
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C654C  0x021C654C  arm  ov114
 *   func_021C6B44  0x021C6B44  arm  ov114
 *   func_021C797C  0x021C797C  arm  ov114
 *
 *
 * Rebuilds the +0x? table for `b`, refreshes the pool, then re-links `a`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021C654C(void * volatile handle);
extern void func_021C797C(void);
extern void func_021C6B44(int *hrq);

void func_021C6BEC(void *a, int b)
{
    func_021C654C((void * volatile)b);
    func_021C797C();
    func_021C6B44(a);
}
