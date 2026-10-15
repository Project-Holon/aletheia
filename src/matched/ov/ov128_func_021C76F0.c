/*
 * function: Wf2dmapFriend_InitItemScreen
 * address: 0x021C76F0
 * packet: pkt_ov128_021C76F0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: sole unresolved overlay blocker of handed 021C76F8.
 * symbols:
 *   Wf2dmapFriend_InitItemWidgets 0x021C7ACC thumb ov128
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void Wf2dmapFriend_InitItemWidgets(u8 *,u8 *,u8 *,u32);
void Wf2dmapFriend_InitItemScreen(u8 *p,u8 *q,u8 *ctx,u32 value)
{
    Wf2dmapFriend_InitItemWidgets(p,q,ctx,value);
}
