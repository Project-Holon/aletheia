/*
 * function: func_021B2E60
 * address:  0x021B2E60
 * packet:   pkt_ov021_021B2E60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020113D0  0x020113D0  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021B2E80  0x021B2E80  thumb  ov021
 *   d_021EE720     0x021EE720  data  a2
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u16 d_021EE720;
extern unsigned int func_02159B10(void *, void *);
extern void func_020113D0(u32, u32);
extern int func_021B2E80(u32, u32);

int func_021B2E60(u32 a, u32 b)
{
    d_021EE720 = func_02159B10((void *)a, (void *)b);
    func_020113D0(a, (u32)func_021B2E80);
    return 1;
}
