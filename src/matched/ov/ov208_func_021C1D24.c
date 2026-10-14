/*
 * function: ZUKAN_DETAIL_AREA_RequestModeEvent4
 * address:  0x021C1D24
 * packet:   pkt_021C1D0C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZUKAN_DETAIL_AREA_HandleModeEvent 0x021C1920  thumb  ov208
 *
 * Region-qualified name: src/matched/ZUKAN_DETAIL_AREA_RequestModeEvent4.c is ov217's function at the
 * same load address; this is ov208's.
 *
 * Thin forwarder: hands its first three arguments straight through to
 * ZUKAN_DETAIL_AREA_HandleModeEvent with a literal fourth argument of 4.
 */

typedef unsigned short u16;
typedef unsigned char  u8;
extern void ZUKAN_DETAIL_AREA_HandleModeEvent(u16 *heap, u8 *p, int key, int mode);

void ZUKAN_DETAIL_AREA_RequestModeEvent4(void *a, int b, int c)
{
    ZUKAN_DETAIL_AREA_HandleModeEvent(a, (u8 *)b, c, 4);
}
