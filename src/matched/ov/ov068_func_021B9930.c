/*
 * function: OPTION_MENU_UpdateScreen
 * address: 0x021B9930
 * packet: pkt_ov068_021B9930
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   OPTION_MENU_UpdateSprites 0x021B9FC0 thumb ov068
 *   OPTION_MENU_UpdateGfxBlink 0x021B9BD0 thumb ov068
 */
typedef unsigned char u8;
extern void OPTION_MENU_UpdateSprites(u8 *);
extern void OPTION_MENU_UpdateGfxBlink(u8 *);
void OPTION_MENU_UpdateScreen(u8 *p)
{
    OPTION_MENU_UpdateSprites(p + 0x7c);
    OPTION_MENU_UpdateGfxBlink(p);
}
