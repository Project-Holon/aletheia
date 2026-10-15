/*
 * function: OPTION_MENU_FlushGfx
 * address:  0x021B9D60
 * packet:   pkt_ov068_021B9D60
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to BG_SYS_Update.
 *
 * symbols:
 *   BG_SYS_Update  0x020419E4  arm
 */

void OPTION_MENU_FlushGfx(char *a0)
{
    void BG_SYS_Update(void);
    BG_SYS_Update();
}
