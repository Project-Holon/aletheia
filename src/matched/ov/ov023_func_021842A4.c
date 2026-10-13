/*
 * function: OEKAKI_RecvStroke
 * address: 0x021842A4
 * packet: pkt_ov023_021842A4
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   OEKAKI_StoreStroke 0x02186988 thumb ov023
 */
extern void OEKAKI_StoreStroke(char *src, char *dst, int index);
void OEKAKI_RecvStroke(int index, int unused, char *src, char *p)
{
    if (index != 0)
        OEKAKI_StoreStroke(src, p + 0x928c, index);
}
