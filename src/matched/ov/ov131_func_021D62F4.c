/*
 * function: P_STATUS_HasRibbon
 * address: 0x021D62F4
 * packet: pkt_ov131_021D62F4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   P_STA_RIBBON_GetRibbonInfo 0x021DBF2C thumb ov131
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 */
extern unsigned int P_STA_RIBBON_GetRibbonInfo(unsigned int, unsigned int);
typedef unsigned int   u32;
extern u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
int P_STATUS_HasRibbon(char *p, void *q)
{
    unsigned char i;
    for (i = 0; i < 0x50; i++) {
        if (POKE_TOOL_GetBoxValue(q, P_STA_RIBBON_GetRibbonInfo(i, 0), 0) == 1) {
            return 1;
        }
    }
    return 0;
}
