/*
 * function: INTRUDE_CMD_SendEndNotice
 * address: 0x021742EC
 * packet: pkt_ov011_021742EC
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: INTRUDE_COMM_IsLinked's matched void forwarder leaves r0 live and the
 *       caller tests r0 at 021742F6; its extern returns int here.
 * symbols:
 *   INTRUDE_COMM_IsLinked 0x021736D8 thumb ov011
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendDataMask 0x0203D4D0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
int INTRUDE_COMM_IsLinked(void);
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
u32 GFL_NET_SendDataMask(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

u32 INTRUDE_CMD_SendEndNotice(u32 a)
{
    if (INTRUDE_COMM_IsLinked() == 0) return 1;
    return GFL_NET_SendDataMask((u32)GFL_NET_HANDLE_GetCurrentHandle(), a, 0x21b, 0, 0, 0, 0, 0);
}
