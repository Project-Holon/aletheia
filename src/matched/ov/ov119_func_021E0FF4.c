/*
 * function: POKETRADE_SAVE_OpenMessageWindowAtPos
 * address: 0x021E0FF4
 * packet: pkt_ov119_021E0FF4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_OpenMessageWindow 0x021E0EF4 thumb ov119
 */
extern void POKETRADE_SAVE_OpenMessageWindow(char *p, int flag, int x, int y, int w, int h);
void POKETRADE_SAVE_OpenMessageWindowAtPos(void *p, int a, int flag)
{
    if (flag) {
        POKETRADE_SAVE_OpenMessageWindow(p, a, 1, 0x12, 0x1E, 4);
        return;
    }
    POKETRADE_SAVE_OpenMessageWindow(p, a, 1, 1, 0x1E, 4);
}
