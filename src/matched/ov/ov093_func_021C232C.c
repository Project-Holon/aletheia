/*
 * function: func_021C232C
 * address:  0x021C232C
 * packet:   pkt_ov093_021C232C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C236C  0x021C236C  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021C25A4  0x021C25A4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u32 func_021C236C(u8 *p, u32 v, u32 b, u8 *c, u32 *out);
extern int func_021D5B68(void *p);
extern int func_021C25A4(u8 *p, u32 b, u8 *c, u32 v, u32 s0, u32 s1, u32 s2);

void func_021C232C(u8 *p, const u16 *a, u32 b, u8 *c)
{
    u32 loc;
    u32 r;
    r = func_021C236C(p, *a, b, c, &loc);
    if (r != 0 && func_021D5B68(c) == 0)
        func_021C25A4(p, b, c, *a, r, loc, 0);
}
