/*
 * function: INTRUDE_COMM_SendPeerStatus
 * address:  0x02173984
 * packet:   pkt_ov011_02173984
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
 *   GFL_NET_SendData  0x0203D3F8  arm
 */

int INTRUDE_COMM_IsLinked(void);
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int INTRUDE_COMM_SendPeerStatus(char *p, int b)
{
    int r;

    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    r = GFL_NET_SendData((int)GFL_NET_HANDLE_GetCurrentHandle(), 0xFF, 0x205, 0x1C, (u32)((void *)b), 0, 1, 0);
    if (r == 1) {
        p[0x900] = 0;
    }
    return r;
}
