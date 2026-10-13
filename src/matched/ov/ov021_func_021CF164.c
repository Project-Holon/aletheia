/*
 * function: COMM_ENTRY_StartNetCommands
 * address:  0x021CF164
 * packet:   pkt_ov021_021CF164
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Opens the ov021 resource 0x021DB4BC in heap 0x2700 with 8 entries.
 *
 * symbols:
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm
 *   data_021DB4BC  0x021DB4BC  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
extern const u8 data_021DB4BC[];

void COMM_ENTRY_StartNetCommands(u32 a)
{
    GFL_NET_COMMAND_AddCommandTable(0x2700, (u32)data_021DB4BC, 8, a);
}
