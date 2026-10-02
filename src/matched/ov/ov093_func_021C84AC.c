/*
 * function: func_021C84AC
 * address: 0x021C84AC
 * packet: pkt_ov093_021C84AC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C2128 0x021C2128 thumb ov093
 */
typedef unsigned char u8;
struct Flags { u8 low:5; u8 flag:1; u8 high:2; };
extern int func_021C2128(u8 *, u8 *);
int func_021C84AC(u8 *p, u8 *a, u8 *out)
{
    int r;
    ((struct Flags *)(p + 0x78a))->flag = 0;
    r = func_021C2128(p, a);
    *out = ((struct Flags *)(p + 0x78a))->flag;
    return r;
}
