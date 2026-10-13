/*
 * function: OPTION_MENU_ScreenTaskMain
 * address: 0x021B996C
 * packet: pkt_ov068_021B996C
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Task callback ignores its task handle; preserve the pointers visibly loaded.
 * symbols:
 *   OPTION_MENU_FlushGfx 0x021B9D60 thumb ov068
 *   OPTION_MENU_DrawSprites 0x021BA010 thumb ov068
 */
extern void OPTION_MENU_FlushGfx(char *);
extern void OPTION_MENU_DrawSprites(char *);
void OPTION_MENU_ScreenTaskMain(void *task, char *p)
{
    OPTION_MENU_FlushGfx(p);
    OPTION_MENU_DrawSprites(p + 0x7c);
}
