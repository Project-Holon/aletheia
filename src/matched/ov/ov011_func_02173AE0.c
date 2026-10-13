/*
 * function: INTRUDE_COMM_SendReply
 * address:  0x02173AE0
 * packet:   pkt_ov011_02173AE0
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
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int INTRUDE_COMM_SendReply(int a, int b, int c, int d)
{
    unsigned char buf[4];

    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    buf[0] = c;
    buf[1] = d;
    return GFL_NET_SendData((int)GFL_NET_HANDLE_GetCurrentHandle(), (unsigned char)b, 0x208, 4, (u32)buf, 0, 0, 0);
}
