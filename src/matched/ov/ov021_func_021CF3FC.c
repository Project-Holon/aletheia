/*
 * function: COMM_ENTRY_SendRoster
 * address:  0x021CF3FC
 * packet:   pkt_ov021_021CF3FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls GFL_NET_SendDataMask with 0x2707 on the handle of GFL_NET_HANDLE_GetNetHandle(0xff) when c == 1,
 * otherwise on the handle of GFL_NET_HANDLE_GetCurrentHandle().
 *
 * symbols:
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   COMM_ENTRY_GetRosterSize  0x021CF128  thumb  ov021
 *   GFL_NET_SendDataMask  0x0203D4D0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 COMM_ENTRY_GetRosterSize(void);
extern u32 GFL_NET_SendDataMask(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

void COMM_ENTRY_SendRoster(u32 a, u32 b, int c)
{
    u32 h;

    if (c == 1) {
        h = (u32)GFL_NET_HANDLE_GetNetHandle(0xff);
        GFL_NET_SendDataMask(h, b, 0x2707, COMM_ENTRY_GetRosterSize(), a, 0, 0, 1);
    } else {
        h = (u32)GFL_NET_HANDLE_GetCurrentHandle();
        GFL_NET_SendDataMask(h, b, 0x2707, COMM_ENTRY_GetRosterSize(), a, 0, 0, 1);
    }
}
