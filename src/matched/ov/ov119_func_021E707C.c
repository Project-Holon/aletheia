/*
 * function: POKETRADE_2D_ClearCursorIfDisabled
 * address: 0x021E707C
 * packet: pkt_ov119_021E707C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_DeleteCursorActor 0x021E7058 thumb ov119
 */
extern void POKETRADE_2D_DeleteCursorActor(void *p);

int POKETRADE_2D_ClearCursorIfDisabled(void *p)
{
    if (*((unsigned char *)p + 0x11f5)) {
        POKETRADE_2D_DeleteCursorActor(p);
        return 0;
    }
    return 1;
}
