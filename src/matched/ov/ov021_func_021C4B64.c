/*
 * function: func_021C4B64
 * address:  0x021C4B64
 * packet:   pkt_ov021_021C4B64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C67D8  0x021C67D8  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct P { u32 f0; u16 h4; u16 h6; } P;

extern u32 func_021ABE18(u32 a);
extern u32 func_021ABE24(u32 a);
extern void func_021C6AE0(u32 *a);
extern void func_021C6AF0(u32 *a, u32 b, u32 c);
extern void func_021C6AF8(u32 *a, u32 b);
extern void func_021C6AFC(u32 *a, u32 b);
extern u16 func_021C6574(u32 a, u32 *b, u32 c);
extern u16 func_021C6590(u32 a, u32 b, u32 c, u32 d);
extern void func_021C67D8(u32 a, u32 b, u32 c);

void func_021C4B64(P *p)
{
    u32 buf[9];
    u32 x = func_021ABE18(p->f0);
    u32 y = func_021ABE24(p->f0);

    func_021C6AE0(buf);
    func_021C6AF0(buf, y, 0x5f);
    func_021C6AF8(buf, y);
    func_021C6AFC(buf, 0x6a);
    p->h4 = func_021C6574(x, buf, 0);
    p->h6 = func_021C6590(x, p->h4, 0, 0);
    func_021C67D8(x, p->h6, 1);
}
