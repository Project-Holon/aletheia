/*
 * function: ZENKOKU_ZUKAN_AWARD_GRAPHIC_Update
 * address:  0x021BA014
 * packet:   pkt_ov222_021BA014
 * region:   ov222
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * This address is also matched in ov114 and ov172; the ov222 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   ZENKOKU_ZUKAN_AWARD_GRAPHIC_Draw  0x021BA148  thumb  ov222
 *   ZENKOKU_ZUKAN_AWARD_GRAPHIC_Noop  0x021BA0E0  thumb  ov222
 *
 * Addresses are Black-image addresses.
 */

extern void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Draw(void *);
extern void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Noop(void *);

void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Update(char *p)
{
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_Draw(p + 4);
    ZENKOKU_ZUKAN_AWARD_GRAPHIC_Noop(p);
}
