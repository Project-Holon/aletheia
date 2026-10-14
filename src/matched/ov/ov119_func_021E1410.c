/*
 * function: POKETRADE_SAVE_OpenTaskMenu
 * address: 0x021E1410
 * packet: pkt_ov119_021E1410
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   POKETRADE_SAVE_OpenTaskMenuAt 0x021E131C thumb ov119
 */
extern void POKETRADE_SAVE_OpenTaskMenuAt(char *p, int *ids, int count, int x, int y);
void POKETRADE_SAVE_OpenTaskMenu(void *p, int *ids, int count)
{
    if (count == 1) {
        POKETRADE_SAVE_OpenTaskMenuAt(p, ids, count, 0x20, 0x15);
        return;
    }
    POKETRADE_SAVE_OpenTaskMenuAt(p, ids, count, 0x20, 0x18);
}
