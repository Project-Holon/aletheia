/*
 * function: func_021C8D3C
 * address:  0x021C8D3C
 * packet:   pkt_ov021_021C8D3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021C8CF8  0x021C8CF8  thumb  ov021
 *   func_021C8D08  0x021C8D08  thumb  ov021
 *   func_021C8DF4  0x021C8DF4  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; void *f14; u32 f18; u32 f1C; u32 f20; u32 f24; } P;
extern int func_021C8D08(u32 a);
extern int func_021C8CF8(u32 a);
extern void func_0216D410(u32 a, u32 b);
extern void func_021C8DF4(P *p);
void func_021C8D3C(P *p)
{
    if (p->f14 != 0) {
        func_0216D410(p->fC, func_021C8D08((u32)p));
        func_021C8DF4(p);
        p->f18 = 1;
        return;
    }
    if (p->f10 != 0)
        func_0216D410(p->fC, func_021C8CF8((u32)p));
}
