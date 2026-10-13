/*
 * function: COMM_ENTRY_SendAccept
 * address:  0x021CF378
 * packet:   pkt_ov021_021CF378
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed int     s32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);

void COMM_ENTRY_SendAccept(int mode)
{
    if (mode == 1) {
        GFL_NET_SendToHandle(GFL_NET_HANDLE_GetNetHandle(0xff), 0x2705, 0, 0);
    } else {
        GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2705, 0, 0);
    }
}
