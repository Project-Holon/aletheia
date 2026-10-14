/*
 * function: HALL_OF_FAME_RunState
 * address: 0x021B6A10
 * packet: pkt_ov180_021B6A10
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gHallOfFameStateTable 0x021B814C data a4
 *   HALL_OF_FAME_DrawMonScene 0x021B7D5C thumb ov180
 *   HALL_OF_FAME_DrawParticles 0x021B6704 thumb ov180
 *   HALL_OF_FAME_DrawTrainerScene 0x021B7F30 thumb ov180
 *   HALL_OF_FAME_DrawMonSprite3d 0x021B66E4 thumb ov180
 *   HALL_OF_FAME_EnableBgEffects 0x021B7300 thumb ov180
 */
#include "../include/Obj08298.h"
extern int (*gHallOfFameStateTable[])(char *);
extern void HALL_OF_FAME_DrawMonScene(void *p);
extern void HALL_OF_FAME_DrawParticles(char *);
extern void HALL_OF_FAME_DrawTrainerScene(void *p);
extern void HALL_OF_FAME_DrawMonSprite3d(char *);
extern void HALL_OF_FAME_EnableBgEffects(char *);
int HALL_OF_FAME_RunState(char *p) {
    ((struct Obj08298 *)p)->f918C=gHallOfFameStateTable[*(int *)(p+0x918c)](p);
    if(((struct Obj08298 *)p)->f918C==10) return 0;
    if(((struct Obj08298 *)p)->f8==1) {
        HALL_OF_FAME_DrawMonScene(p); HALL_OF_FAME_DrawParticles(p);
    } else if(((struct Obj08298 *)p)->f8==2) {
        HALL_OF_FAME_DrawTrainerScene(p); HALL_OF_FAME_DrawMonSprite3d(p); HALL_OF_FAME_EnableBgEffects(p);
    }
    return 1;
}
