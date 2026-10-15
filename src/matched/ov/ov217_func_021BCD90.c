/*
 * function: RESEARCH_LIST_DestroyLabels
 * address: 0x021BCD90
 * packet: pkt_ov217_021BCD90
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BgTextLabel_Destroy 0x021C0F48 thumb ov217
 *   RESEARCH_LIST_GetEntryCount 0x021BC6DC thumb ov217
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void BgTextLabel_Destroy(u8 *);
extern u32 RESEARCH_LIST_GetEntryCount(void *);
void RESEARCH_LIST_DestroyLabels(u8 *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        BgTextLabel_Destroy(*(u8 **)(p + i * 4 + 0xDC));
        *(u32 *)(p + i * 4 + 0xDC) = 0;
    }
    for (i = 0; i < (int)RESEARCH_LIST_GetEntryCount(p); i++) {
        BgTextLabel_Destroy(*(u8 **)(p + i * 4 + 0xB4));
        *(u32 *)(p + i * 4 + 0xB4) = 0;
    }
}
