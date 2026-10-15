/*
 * function: Wf2dmapFriend_Exit
 * address: 0x021C7138
 * packet: pkt_ov128_021C7138
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   Wf2dmapFriend_DeleteListScreen 0x021C72A0 thumb ov128
 */
typedef unsigned char u8;
extern void Wf2dmapFriend_DeleteListScreen(u8 *,u8 *,u8 *);
void Wf2dmapFriend_Exit(u8 *p,u8 *q,u8 *ctx) { Wf2dmapFriend_DeleteListScreen(p,q,ctx); }
