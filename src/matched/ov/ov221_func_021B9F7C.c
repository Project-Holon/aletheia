/*
 * function: CHIHOU_ZUKAN_AWARD_GRAPHIC_Update
 * address:  0x021B9F7C
 * packet:   pkt_021B9F7C
 * region:   ov221
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CHIHOU_ZUKAN_AWARD_GRAPHIC_Draw  0x021BA0B0  thumb  ov221
 *   CHIHOU_ZUKAN_AWARD_GRAPHIC_Noop  0x021BA048  thumb  ov221
 *
 * Addresses are Black-image addresses.
 */

extern void CHIHOU_ZUKAN_AWARD_GRAPHIC_Draw(void *);
extern void CHIHOU_ZUKAN_AWARD_GRAPHIC_Noop(void *);

void CHIHOU_ZUKAN_AWARD_GRAPHIC_Update(char *p)
{
    CHIHOU_ZUKAN_AWARD_GRAPHIC_Draw(p + 4);
    CHIHOU_ZUKAN_AWARD_GRAPHIC_Noop(p);
}
