/*
 * function: func_021D30B8
 * address:  0x021D30B8
 * packet:   pkt_ov021_021D30B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02030734  0x02030734  arm
 *   func_021D310C  0x021D310C  thumb  ov021
 *   d_021DE698     0x021DE698  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_020120F4(void);
extern void *func_0201210C(void *p);
extern u32 func_020122C0(u32 a, u32 b, void *cb, u32 size);
extern u32 *func_020124E8(u32 task);
extern u32 *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_021D310C(void);
extern char d_021DE698[];

u32 func_021D30B8(u32 a, u32 b)
{
    u32 r7;
    void *s4;
    u32 s8;
    u32 *w;

    r7 = func_020120F4();
    s4 = func_0201210C((void *)a);
    s8 = func_020122C0(a, 0, func_021D310C, 0x10);
    w = func_020124E8(s8);
    w[0] = a;
    w[1] = s4;
    w[3] = b;
    w[2] = (u32)func_02030734(4, 8, 0, d_021DE698, 0x4a);
    *(u32 *)w[2] = r7;
    return s8;
}
