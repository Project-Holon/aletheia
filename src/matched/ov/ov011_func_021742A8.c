/*
 * function: INTRUDE_CMD_SendStartNotice
 * address:  0x021742A8
 * packet:   pkt_ov011_021742A8
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   INTRUDE_COMM_IsLinked  0x021736D8  thumb ov011
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendDataMask  0x0203D4D0  arm
 */

int INTRUDE_COMM_IsLinked(void);
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
u32 GFL_NET_SendDataMask(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int INTRUDE_CMD_SendStartNotice(int a)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return GFL_NET_SendDataMask((u32)GFL_NET_HANDLE_GetCurrentHandle(), a, 0x21a, 0, 0, 0, 0, 0);
}
