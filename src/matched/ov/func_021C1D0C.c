/*
 * function: ZUKAN_DETAIL_AREA_UpdateFadeAndOverlay
 * address:  0x021C1D0C
 * packet:   pkt_021C1D0C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_AREA_BeginModeTransition 0x021C1FC4  thumb  ov208
 *   ZUKAN_DETAIL_AREA_UpdateTerrainIcons 0x021C2238  thumb  ov208

 * Calls ZUKAN_DETAIL_AREA_BeginModeTransition then ZUKAN_DETAIL_AREA_UpdateTerrainIcons on the same three arguments.
 */


extern void ZUKAN_DETAIL_AREA_BeginModeTransition(void *a, char *b, int c);
typedef unsigned short u16;
typedef unsigned char  u8;
extern void ZUKAN_DETAIL_AREA_UpdateTerrainIcons(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_UpdateFadeAndOverlay(int a, int b, int c)
{
    ZUKAN_DETAIL_AREA_BeginModeTransition((void *)a, (char *)b, c);
    ZUKAN_DETAIL_AREA_UpdateTerrainIcons((u16 *)a, (u8 *)b, c);
}

