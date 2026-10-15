/*
 * function: PSEL_GRAPHIC_StateRun
 * address: 0x021BBD74
 * packet: pkt_ov223_021BBD74
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PSEL_UpdateUnitAnime 0x021B9D4C thumb ov223
 *   PSEL_UpdateUnitPositions 0x021BA2B4 thumb ov223
 *   PSEL_GRAPHIC_UpdateFade 0x021BB964 thumb ov223
 *   PSEL_UpdateSelectAnime 0x021B9A8C thumb ov223
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   PSEL_StepAnimIndex  0x021B9C58  thumb
 */
#include "../include/Obj00738.h"
extern void PSEL_StepAnimIndex(char *);
struct Main;
extern void PSEL_UpdateSelectAnime(char *p);
typedef signed int     s32;
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void PSEL_UpdateUnitAnime(char *);
extern void PSEL_UpdateUnitPositions(struct Main *p);
extern void PSEL_GRAPHIC_UpdateFade(char *);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
int PSEL_GRAPHIC_StateRun(char *p,unsigned *state)
{
    if(((struct Obj00738 *)p)->f10>=16) PSEL_UpdateSelectAnime(p);
    if(((struct Obj00738 *)p)->f10==15) GFL_USE_PlaySeDefaultVolume(1957);
    PSEL_UpdateUnitAnime(p); PSEL_UpdateUnitPositions((struct Main *)p); PSEL_GRAPHIC_UpdateFade(p);
    switch(*state) {
    case 0: FADE_Start(12,16,0,2); (*state)++; break;
    case 1: if(!FADE_IsActive()) { ((struct Obj00738 *)p)->f10=0; return 9; } break;
    }
    (((struct Obj00738 *)p)->f10)++;
    return 8;
}
