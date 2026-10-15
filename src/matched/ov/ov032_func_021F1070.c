/*
 * function: BEACON_VIEW_PrintEntryName
 * address: 0x021F1070
 * packet: pkt_ov032_021F1070
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_VIEW_DrawEntryText 0x021F2144 thumb ov032
 */

typedef unsigned short u16;
typedef unsigned int u32;
extern void BEACON_VIEW_DrawEntryText(char *p, char *q, void *text, u16 col, u32 a4);
void BEACON_VIEW_PrintEntryName(char *p, char *q, void *text, int a4)
{
    BEACON_VIEW_DrawEntryText(p, q, text, 0x3c60, a4);
}
