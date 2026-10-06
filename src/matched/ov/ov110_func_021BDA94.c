/*
 * function: func_021BDA94
 * address: 0x021BDA94
 * packet: pkt_ov110_021BDA94
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * input: caller's incoming pointer in r0 is ignored; stub replaces it with the table.
 * symbols:
 *   d_021C3948 0x021C3948 data ov110 a1
 *   func_02035C08 0x02035C08 arm
 */
typedef unsigned char u8;
extern u8 d_021C3948[];
extern int func_02035C08(const void *p);
int func_021BDA94(u8 *unused)
{
    return func_02035C08(d_021C3948);
}
