/*
 * function: HALL_OF_FAME_InitMcss
 * address: 0x021B68A8
 * packet: pkt_ov180_021B68A8
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MCSS_Init 0x02014B08 thumb
 *   MCSS_SetTextureTransAdrs 0x02016020 thumb
 *   MCSS_SetOrthoMode 0x02015BF0 thumb
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   gHallOfFameCameraPos 0x021B8034 data a4
 *   gHallOfFameCameraTarget 0x021B801C data a4
 *   gHallOfFameCameraUp 0x021B8028 data a4
 */
#include "../include/Obj00547.h"
typedef unsigned int   u32;
extern void *MCSS_Init(u32 id, void *heap); extern void MCSS_SetTextureTransAdrs(void *,unsigned); extern void MCSS_SetOrthoMode(void *);
extern void *G3D_CAMERA_Create(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,void *,void *,void *,unsigned short);
struct Light;
extern void G3D_CAMERA_Reset(struct Light *l);
extern unsigned gHallOfFameCameraPos[]; extern unsigned gHallOfFameCameraTarget[]; extern unsigned gHallOfFameCameraUp[];
void HALL_OF_FAME_InitMcss(char *p) {
 ((struct Obj00547 *)p)->f18=MCSS_Init(1,(void *)141); MCSS_SetTextureTransAdrs(((struct Obj00547 *)p)->f18,0); MCSS_SetOrthoMode(((struct Obj00547 *)p)->f18);
 ((struct Obj00547 *)p)->f20=G3D_CAMERA_Create(2,0x60000,0xFFFA0000,0xFFF80000,0x80000,0x1000,0x400000,0,gHallOfFameCameraPos,gHallOfFameCameraTarget,gHallOfFameCameraUp,141);
 G3D_CAMERA_Reset(((struct Obj00547 *)p)->f20);
}
