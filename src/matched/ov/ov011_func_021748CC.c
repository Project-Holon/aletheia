/*
 * function: INTRUDE_COMM_SendSymbolPage
 * address: 0x021748CC
 * packet: pkt_ov011_021748CC
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_COMM_IsLinked 0x021736D8 thumb ov011
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 */
typedef unsigned int u32;
int INTRUDE_COMM_IsLinked(void);
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
u32 GFL_NET_SendData(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
int INTRUDE_COMM_SendSymbolPage(char *p, int a)
{
    if (INTRUDE_COMM_IsLinked() == 0) {
        return 1;
    }
    return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(), a, 0x229, 0x54, (u32)(p + 0x880), 0, 0, 0);
}
