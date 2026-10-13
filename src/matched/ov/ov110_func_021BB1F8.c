/*
 * function: PMSI_SEARCH_GetKeyLabel
 * address: 0x021BB1F8
 * packet: pkt_ov110_021BB1F8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_SetStringN 0x02045994 arm
 *   sPmsiKanaKeys 0x021C37A8 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 sPmsiKanaKeys[];
struct Strbuf;
extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, u32 len);
void PMSI_SEARCH_GetKeyLabel(u32 i, void *dst)
{
    STRBUF_SetStringN(dst, (const u16 *)(sPmsiKanaKeys + i * 10), 2);
}
