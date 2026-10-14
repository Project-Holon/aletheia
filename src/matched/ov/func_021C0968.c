/*
 * function: ZUKAN_DETAIL_AREA_UpdateScroll
 * address:  0x021C0968
 * packet:   pkt_021C0968
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_AREA_UpdateScrollFade 0x021C0980  thumb  ov208
 *   ZUKAN_DETAIL_AREA_NoOpUpdate 0x021C0A88  thumb  ov208

 */

extern void ZUKAN_DETAIL_AREA_UpdateScrollFade(int a, unsigned char *p, int a2);
extern void ZUKAN_DETAIL_AREA_NoOpUpdate(int, int, int);

void ZUKAN_DETAIL_AREA_UpdateScroll(int a, int b, int c)
{
    ZUKAN_DETAIL_AREA_UpdateScrollFade(a, (unsigned char *)b, c);
    ZUKAN_DETAIL_AREA_NoOpUpdate(a, b, c);
}

