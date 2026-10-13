/*
 * function: INTRUDE_CMD_SendEntryIndex
 * address:  0x02173D2C
 * packet:   pkt_ov011_02173D2C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   INTRUDE_COMM_IsLinked  0x021736D8  thumb  ov011
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 */

typedef unsigned short u16;

int INTRUDE_COMM_IsLinked(void);
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);

int INTRUDE_CMD_SendEntryIndex(int a0, int a1)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x20E, 4, (u32)(&a1));
}
