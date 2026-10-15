/*
 * function: CTVT_COMM_SendPeerStatus
 * address:  0x021B8AD4
 * packet:   pkt_ov172_021B8AD4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   CTVT_COMM_GetPeerStatus  0x021B8B9C  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern char *CTVT_COMM_GetPeerStatus(int unused, char *base);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int CTVT_COMM_SendPeerStatus(int unused, char *base)
{
    char *p = CTVT_COMM_GetPeerStatus(unused, base);
    return GFL_NET_SendData((int)GFL_NET_HANDLE_GetCurrentHandle(), 0xFF, 0x2003, 0x21, (u32)p, 1, 1, 1);
}
