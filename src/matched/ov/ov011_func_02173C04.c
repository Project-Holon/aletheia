/*
 * function: INTRUDE_COMM_SendNoticeBytes
 * address:  0x02173C04
 * packet:   pkt_ov011_02173C04
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   INTRUDE_COMM_IsLinked  0x021736D8  thumb ov011
 *   MI_CpuFill8  0x02082BCC  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 */

int INTRUDE_COMM_IsLinked(void);
void MI_CpuFill8(void *p, int v, int n);
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

int INTRUDE_COMM_SendNoticeBytes(int a, int b)
{
    unsigned char buf[4];

    if (INTRUDE_COMM_IsLinked() == 0) {
        return 0;
    }
    MI_CpuFill8(buf, 0, 4);
    buf[0] = 1;
    buf[1] = b;
    return GFL_NET_SendData((int)GFL_NET_HANDLE_GetCurrentHandle(), (unsigned char)a, 0x20B, 4, (u32)buf, 0, 0, 0);
}
