/*
 * function: COMM_ENTRY_RecvRoster
 * address:  0x021CF3DC
 * packet:   pkt_021CF3DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   COMM_ENTRY_MENU_AckSend  0x021CEADC  thumb  ov021
 *   COMM_ENTRY_MENU_SetNameBuffer  0x021CEB04  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 GFL_NET_IsParentAid(void);
extern u8 *COMM_ENTRY_MENU_AckSend(u8 *p);
extern u32 COMM_ENTRY_MENU_SetNameBuffer(u32, u32);

int COMM_ENTRY_RecvRoster(u32 a, u32 b, u32 c, u8 *d)
{
if (GFL_NET_IsParentAid() == 1) {
    return (int)COMM_ENTRY_MENU_AckSend(d);
}
return COMM_ENTRY_MENU_SetNameBuffer((u32)d, c);
}

