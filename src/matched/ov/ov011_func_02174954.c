/*
 * function: INTRUDE_COMM_SendAreaNotice
 * address: 0x02174954
 * packet: pkt_ov011_02174954
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: caller consumes the live r0 result of legacy void forwarders.
 * symbols:
 *   INTRUDE_COMM_IsLinked 0x021736D8 thumb ov011
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 */
typedef unsigned int u32;
int INTRUDE_COMM_IsLinked(void);
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned short u16;
int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
u32 INTRUDE_COMM_SendAreaNotice(u32 p)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return GFL_NET_SendToHandle((struct Entry *)((u32)GFL_NET_HANDLE_GetCurrentHandle()), 0x22a, 4, p);
}
