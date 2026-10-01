/*
 * function: func_021C98F4
 * address:  0x021C98F4
 * packet:   pkt_ov021_021C98F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021C9854  0x021C9854  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; u32 f10; } W;
extern u32 func_020122C0(u32 a, u32 b, void *fn, u32 size);
extern W *func_020124E8(u32 t);
extern void func_021C9854(void);
u32 func_021C98F4(u32 a, u32 b, u32 c, u32 d)
{
    u32 t = func_020122C0(b, a, func_021C9854, 0x14);
    W *w = func_020124E8(t);
    w->f0 = b;
    w->f4 = c;
    w->f8 = 0;
    w->f10 = d;
    return t;
}
