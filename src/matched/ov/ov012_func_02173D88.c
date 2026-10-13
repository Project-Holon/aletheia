/*
 * unit:     yes
 * function: UNION_COMMAND_SendAppEntryRefused, UNION_COMMAND_RecvAppEntryAccepted
 * address:  0x02173D88
 * packet:   pkt_ov012_02173D88
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendDataMask  0x0203D4D0  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_SendDataMask(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int UNION_COMMAND_SendAppEntryRefused(u32 a)
{
    return GFL_NET_SendDataMask((u32)GFL_NET_HANDLE_GetCurrentHandle(), a, 0x140B, 0, 0, 1, 0, 0);
}

void UNION_COMMAND_RecvAppEntryAccepted(int a, int b, int c, u8 *p)
{
    p[0x282B] = 1;
}
