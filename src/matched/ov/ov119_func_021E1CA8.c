/*
 * function: POKETRADE_SAVE_DeleteOfferStatusIcons
 * address: 0x021E1CA8
 * packet: pkt_ov119_021E1CA8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_DeleteStatusIconActor 0x021E0E4C thumb ov119
 */
extern void POKETRADE_SAVE_DeleteStatusIconActor(char *p);
void POKETRADE_SAVE_DeleteOfferStatusIcons(char *p)
{
    char *q = p + 0x8C4;
    int i;
    for (i = 0; i < 3; i++) {
        POKETRADE_SAVE_DeleteStatusIconActor(q + i * 0x14);
    }
}
