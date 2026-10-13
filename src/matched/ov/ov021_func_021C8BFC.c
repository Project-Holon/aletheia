/*
 * function: FIELD_TILE_MOVE_SlideTaskMain
 * address:  0x021C8BFC
 * packet:   pkt_ov021_021C8BFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_TILE_MOVE_GetSlideTileAttr  0x021C8D18  thumb  ov021
 *   FIELD_TILE_MOVE_HasSlideEntry  0x021C8BC4  thumb  ov021
 *   FIELD_PLAYER_GetRideEffect  0x021A2F98  thumb  ov021
 *   FLDEFF_NAMIPOKE_SetWakeEnabled  0x021ACBC8  thumb  ov021
 *   FIELD_TILE_MOVE_SlidePlayLoopSe  0x021C8E30  thumb  ov021
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FIELD_TILE_MOVE_SlideFinishBump  0x021C8D74  thumb  ov021
 *   FIELD_TILE_MOVE_SlideSelectSlideEntry  0x021C8DC4  thumb  ov021
 *   FIELD_TILE_MOVE_SlideSelectBumpEntry  0x021C8DD4  thumb  ov021
 *   FIELD_TILE_MOVE_SlideStopLoopSe  0x021C8E5C  thumb  ov021
 *   FIELD_TILE_MOVE_SlideStartStep  0x021C8D3C  thumb  ov021
 *   FIELD_TILE_MOVE_SlideShowSurfPokemon  0x021C8DE4  thumb  ov021
 */

extern int FIELD_TILE_MOVE_GetSlideTileAttr(int *p);
typedef unsigned int   u32;
extern int FIELD_TILE_MOVE_HasSlideEntry(u32 a);
typedef unsigned char  u8;
extern u32 FIELD_PLAYER_GetRideEffect(u8 *p);
extern void FLDEFF_NAMIPOKE_SetWakeEnabled(u32 a, int v);
extern void FIELD_TILE_MOVE_SlidePlayLoopSe(int *p);
extern int FLDMMDL_CheckEndAcmd(int a);
extern void FIELD_TILE_MOVE_SlideFinishBump(int *p);
extern void FIELD_TILE_MOVE_SlideSelectSlideEntry(int *p);
extern void FIELD_TILE_MOVE_SlideSelectBumpEntry(int *p);
extern void FIELD_TILE_MOVE_SlideStopLoopSe(int *p);
extern void FIELD_TILE_MOVE_SlideStartStep(int *p);
extern int FIELD_TILE_MOVE_SlideShowSurfPokemon(u32 a);

int FIELD_TILE_MOVE_SlideTaskMain(int a, int *st, int *p)
{
    switch (*st) {
    case 0:
        if (FIELD_TILE_MOVE_HasSlideEntry(FIELD_TILE_MOVE_GetSlideTileAttr(p)) == 0) {
            *st = 2;
        } else {
            FLDEFF_NAMIPOKE_SetWakeEnabled(FIELD_PLAYER_GetRideEffect((u8 *)p[2]), 0);
            FIELD_TILE_MOVE_SlidePlayLoopSe(p);
            *st = 1;
        }
        break;
    case 1:
        FIELD_TILE_MOVE_SlidePlayLoopSe(p);
        if (FLDMMDL_CheckEndAcmd(p[3])) {
            FIELD_TILE_MOVE_SlideFinishBump(p);
            FIELD_TILE_MOVE_SlideSelectSlideEntry(p);
            FIELD_TILE_MOVE_SlideSelectBumpEntry(p);
            if (p[4] == 0 && p[5] == 0) {
                FIELD_TILE_MOVE_SlideStopLoopSe(p);
                *st = 2;
            } else {
                FIELD_TILE_MOVE_SlideStartStep(p);
            }
        }
        break;
    case 2:
        FIELD_TILE_MOVE_SlideShowSurfPokemon((u32)p);
        return 1;
    }
    return 0;
}
