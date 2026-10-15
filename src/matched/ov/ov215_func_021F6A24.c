/*
 * function: EGG_DEMO_VIEW_Draw
 * address: 0x021F6A24
 * packet: pkt_ov215_021F6A24
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: existing follower unit 021F6A3C/6A44.
 * symbols:
 *   MCSS_Draw 0x02014D2C thumb
 *   EGG_DEMO_VIEW_DrawModels 0x021F6F24 thumb ov215
 *   EGG_DEMO_VIEW_MainParticles 0x021F6EE4 thumb ov215
 */
#include "../include/Obj06708.h"
struct McssSys;
extern void MCSS_Draw(struct McssSys *);
extern void EGG_DEMO_VIEW_DrawModels(char *);
extern void EGG_DEMO_VIEW_MainParticles(char *);
void EGG_DEMO_VIEW_Draw(char *p){MCSS_Draw(*(struct McssSys * *)&((struct Obj06708 *)p)->f30);EGG_DEMO_VIEW_DrawModels(p);EGG_DEMO_VIEW_MainParticles(*(char * *)&((struct Obj06708 *)p)->f44);}
