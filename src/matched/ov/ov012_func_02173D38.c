/*
 * function: func_02173D38
 * address:  0x02173D38
 * packet:   pkt_ov012_02173D38
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_02008468  0x02008468  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0203D3F8  0x0203D3F8  arm
 */

typedef unsigned char u8;

extern int func_020399A8(void);
extern int func_02008468(void);
extern int func_02012944(int v);
extern int func_0203D3F8(int a, int b, int c, int d, int e, int f, int g, int h);

void func_02173D38(u8 *p)
{
    p[0x282B] = 0;
    func_0203D3F8(func_020399A8(), 0, 0x140A, func_02008468(),
                  func_02012944(*(int *)(*(u8 **)p + 8)), 1, 0, 0);
}
