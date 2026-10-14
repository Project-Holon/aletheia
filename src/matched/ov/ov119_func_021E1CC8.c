/*
 * function: POKETRADE_SAVE_DeleteTypeIcons
 * address: 0x021E1CC8
 * packet: pkt_ov119_021E1CC8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   POKETRADE_SAVE_DeleteTypeIconActor 0x021E0DA0 thumb ov119
 */
extern void POKETRADE_SAVE_DeleteTypeIconActor(char *p);
void POKETRADE_SAVE_DeleteTypeIcons(char *p)
{
    char *q;
    int i = 0;
    q = p + 0x900;
    for (; i < 4; i++) {
        POKETRADE_SAVE_DeleteTypeIconActor(q + i * 0x14);
    }
}
