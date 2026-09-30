/*
 * function: func_021D4784
 * address: 0x021D4784
 * packet: pkt_ov093_021D4784
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct S { u8 pad[0x3b04]; void *tblC[4]; };
extern struct S *d_021F3B88;
int func_021D4784(u32 a)
{
    if (d_021F3B88->tblC[a]) return 1;
    return 0;
}
