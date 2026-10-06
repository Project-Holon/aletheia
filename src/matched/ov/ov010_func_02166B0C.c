/*
 * function: func_02166B0C
 * address:  0x02166B0C
 * packet:   pkt_ov010_02166B0C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: stores 0x3F800000 and 0 into a two-word datum, then
 * tail-calls func_02005654(func_02166A6C, 0).
 *
 * symbols:
 *   func_02005654  0x02005654  thumb
 *   func_02166A6C  0x02166A6C  thumb  ov010
 *   d_02172BA4     0x02172BA4  data  ov010  a4
 */

typedef unsigned int u32;

extern int func_02005654(int a, int b);
extern void func_02166A6C(void);
extern u32 d_02172BA4[2];

void func_02166B0C(void)
{
    d_02172BA4[0] = 0x3F800000;
    d_02172BA4[1] = 0;
    func_02005654((int)func_02166A6C, 0);
}
