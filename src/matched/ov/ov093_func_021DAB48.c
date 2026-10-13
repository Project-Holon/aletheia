/*
 * unit: yes
 * function: BTL_ABILITY_ScrappyIgnoreGhostImmunity, BTL_ABILITY_GetScrappyHandlers
 * address: 0x021DAB48
 * packet: pkt_ov093_021DAB48
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gScrappyHandlerTable 0x021F0790 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 * extent: includes store-and-return followers 021DAB6C.
 */
extern unsigned char gScrappyHandlerTable[];
extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int, unsigned int);

void BTL_ABILITY_ScrappyIgnoreGhostImmunity(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3) && BTL_EVENT_GetVar(0x15) == 7)
        BTL_EVENT_OverwriteVar(0x4b, 1);
}

void *BTL_ABILITY_GetScrappyHandlers(int *p)
{
    *p = 1;
    return gScrappyHandlerTable;
}
