/*
 * unit: yes
 * function: HALL_OF_FAME_UpdatePlatePositions, HALL_OF_FAME_SetPlateEnabled
 * address: 0x021B7C08
 * packet: pkt_ov180_021B7C08
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 0x021B7C60 tail-call stub included in this verified unit.
 * symbols:
 *   HALL_OF_FAME_GetActorPos 0x021B7408 thumb ov180
 *   BMP_OAM_SetPos 0x0202590C thumb
 *   BMP_OAM_SetEnabled 0x02025774 thumb
 */
#include "../include/Obj14405.h"
typedef unsigned char  u8;
extern void HALL_OF_FAME_GetActorPos(u8 *p, int n, signed short *x, signed short *y);
typedef signed short   s16;
struct Grid;
extern void BMP_OAM_SetPos(struct Grid *g, s16 x, s16 y);
void HALL_OF_FAME_UpdatePlatePositions(char *p) {
    short x,y;
    HALL_OF_FAME_GetActorPos((u8 *)p,2,&x,&y);
    BMP_OAM_SetPos((struct Grid *)(((struct Obj14405 *)p)->f9120),x-176,y-8);
    HALL_OF_FAME_GetActorPos((u8 *)p,3,&x,&y);
    BMP_OAM_SetPos((struct Grid *)(((struct Obj14405 *)p)->f9128),x,y-8);
}
extern void BMP_OAM_SetEnabled(unsigned char *,unsigned);
void HALL_OF_FAME_SetPlateEnabled(char *p,int index,unsigned value) {
    BMP_OAM_SetEnabled(*(unsigned char **)(p+0x9120+index*8),value);
}
