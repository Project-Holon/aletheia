/*
 * function: UNION_COMMAND_SendAppQuitCancel
 * address:  0x02173EC8
 * packet:   pkt_ov012_02173EC8
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

int UNION_COMMAND_SendAppQuitCancel(void)
{
    return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0, 0x140F, 0, 0, 1, 0, 0);
}
