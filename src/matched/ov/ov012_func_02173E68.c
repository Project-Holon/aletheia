/*
 * function: UNION_COMMAND_SendAppQuitAccept
 * address:  0x02173E68
 * packet:   pkt_ov012_02173E68
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_SendData(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

u32 UNION_COMMAND_SendAppQuitAccept(u32 a)
{
    return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(), a, 0x140E, 0, 0, 1, 0, 0);
}
