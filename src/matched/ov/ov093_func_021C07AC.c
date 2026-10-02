/*
 * function: func_021C07AC
 * address: 0x021C07AC
 * packet: pkt_ov093_021C07AC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two alignment bytes at 0x021C07D2 precede matched func_021C07D4.
 * lever: Wide forwarded arguments avoid truncations absent before the first call.
 * symbols:
 *   func_021C07D4 0x021C07D4 thumb ov093
 *   func_021C0898 0x021C0898 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021C07D4(u8 *, u8 *, u32, u32, int);
extern int func_021C0898(u8 *, u8 *, u32, u32);
int func_021C07AC(u8 *p, u8 *a, u32 c, u32 d, int e)
{
    u8 result = func_021C07D4(p, a, d, c, e);
    return func_021C0898(p, a, d, result);
}
