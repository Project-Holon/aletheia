/*
 * function: ZENKOKU_ZUKAN_AWARD_GRAPHIC_Task
 * address:  0x021BA034
 * packet:   pkt_021BA034
 * region:   ov222
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZENKOKU_ZUKAN_AWARD_GRAPHIC_DrawObjects  0x021BA0E4  thumb  ov222
 *   ZENKOKU_ZUKAN_AWARD_GRAPHIC_VBlank  0x021BA150  thumb  ov222
 *
 * Addresses are Black-image addresses.
 */

extern void ZENKOKU_ZUKAN_AWARD_GRAPHIC_DrawObjects(void *);
extern void ZENKOKU_ZUKAN_AWARD_GRAPHIC_VBlank(void *);

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Task(void *unused, char *p)
{
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_DrawObjects(p);
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_VBlank(p + 4);
}
