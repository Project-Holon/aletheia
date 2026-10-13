/*
 * function: INTRUDE_COMM_SendUnionInfoRequest
 * address:  0x021746AC
 * packet:   pkt_ov011_021746AC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRUDE_COMM_IsLinked  0x021736D8  thumb ov011
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 */

int INTRUDE_COMM_IsLinked(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int INTRUDE_COMM_SendUnionInfoRequest(char *a, int b)
{
    int r;

    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    r = GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(), b, 0x224, 0, 0, 0, 0, 0);
    if (r == 1) {
        a[0x90c] = 0;
    }
    return r;
}
