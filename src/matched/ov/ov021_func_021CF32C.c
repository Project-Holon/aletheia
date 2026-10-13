/*
 * unit:     yes
 * function: COMM_ENTRY_SendReady, COMM_ENTRY_RecvAccept
 * address:  0x021CF32C
 * packet:   pkt_ov021_021CF32C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * COMM_ENTRY_RecvAccept (unlabelled) is a tail-call stub into COMM_ENTRY_MENU_SetAcceptFlag.
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   COMM_ENTRY_MENU_SetAcceptFlag  0x021CE70C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void COMM_ENTRY_MENU_SetAcceptFlag(u8 *p);

u32 COMM_ENTRY_SendReady(u32 flag)
{
    if (flag == 1)
        GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0xff, 0x2704, 0, 0, 0, 0, 0);
    else
        return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0, 0x2704, 0, 0, 0, 0, 0);
}

void COMM_ENTRY_RecvAccept(u32 a, u32 b, u32 c, u32 d)
{
    COMM_ENTRY_MENU_SetAcceptFlag((u8 *)d);
}
