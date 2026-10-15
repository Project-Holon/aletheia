/*
 * function: CHIHOU_ZUKAN_AWARD_GRAPHIC_Task
 * address:  0x021B9F9C
 * packet:   pkt_021B9F9C
 * region:   ov221
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CHIHOU_ZUKAN_AWARD_GRAPHIC_DrawObjects  0x021BA04C  thumb  ov221
 *   CHIHOU_ZUKAN_AWARD_GRAPHIC_VBlank  0x021BA0B8  thumb  ov221
 *
 * Addresses are Black-image addresses.
 */

extern void CHIHOU_ZUKAN_AWARD_GRAPHIC_DrawObjects(void *);
extern void CHIHOU_ZUKAN_AWARD_GRAPHIC_VBlank(void *);

void CHIHOU_ZUKAN_AWARD_GRAPHIC_Task(void *unused, char *p)
{
    CHIHOU_ZUKAN_AWARD_GRAPHIC_DrawObjects(p);
    CHIHOU_ZUKAN_AWARD_GRAPHIC_VBlank(p + 4);
}
