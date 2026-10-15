/*
 * function: PSEL_GRAPHIC_StateCleanup
 * address: 0x021BC2CC
 * packet: pkt_ov223_021BC2CC
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: display blend register stores at 021BC2D2/021BC2D8.
 * symbols:
 *   PSEL_GRAPHIC_UpdateFadeNop 0x021BB954 thumb ov223
 *   PSEL_NopBgUpdate 0x021BADFC thumb ov223
 *   PSEL_ClearBgLayerEx 0x021BAD68 thumb ov223
 *   PSEL_DeleteActors 0x021BAA30 thumb ov223
 *   PSEL_DeleteUnits 0x021BA050 thumb ov223
 *   PSEL_DeleteSelectAnime 0x021B9A6C thumb ov223
 * Original caller passes p in r0 to BAD68 despite its matched void prototype;
 * retain that visibly supplied input without editing the callee.
 */
#include "../include/Obj05571.h"
extern void PSEL_GRAPHIC_UpdateFadeNop(char *);
extern void PSEL_NopBgUpdate(char *);
extern void PSEL_ClearBgLayerEx(char *);
extern void PSEL_DeleteActors(char *);
extern void PSEL_DeleteUnits(char *);
extern void PSEL_DeleteSelectAnime(char *);
int PSEL_GRAPHIC_StateCleanup(char *p)
{
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    PSEL_GRAPHIC_UpdateFadeNop(p); PSEL_NopBgUpdate(p); PSEL_ClearBgLayerEx(p);
    PSEL_DeleteActors(p); PSEL_DeleteUnits(p); PSEL_DeleteSelectAnime(p);
    ((struct Obj05571 *)p)->f10=0;
    return 12;
}
