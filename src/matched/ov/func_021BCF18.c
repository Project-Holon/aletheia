/*
 * function: ZUKAN_DETAIL_GRAPHIC_DrawFrame
 * address:  0x021BCF18
 * packet:   pkt_021BCF18
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZUKAN_DETAIL_GRAPHIC_DrawActors 0x021BD098  thumb  ov208
 *   ZUKAN_DETAIL_GRAPHIC_NoOp 0x021BD030  thumb  ov208

 * Calls ZUKAN_DETAIL_GRAPHIC_DrawActors on +4 then ZUKAN_DETAIL_GRAPHIC_NoOp on the object.
 */


extern void ZUKAN_DETAIL_GRAPHIC_DrawActors(char *);
extern void ZUKAN_DETAIL_GRAPHIC_NoOp(char *);

void ZUKAN_DETAIL_GRAPHIC_DrawFrame(char *p)
{
    ZUKAN_DETAIL_GRAPHIC_DrawActors(p + 4);
    ZUKAN_DETAIL_GRAPHIC_NoOp(p);
}

