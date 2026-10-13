/*
 * function: COMM_ENTRY_EndNetCommands
 * address:  0x021CF17C
 * packet:   pkt_021CF17C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Tail call with 0x2700.
 *
 * symbols:
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void GFL_NET_COMMAND_DeleteCommandTable(u32 v);

void COMM_ENTRY_EndNetCommands(void)
{
    GFL_NET_COMMAND_DeleteCommandTable(0x2700);
}
