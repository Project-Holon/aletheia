/*
 * function: INTRO_GRAPHIC_Main
 * address:  0x021BDB30
 * packet:   pkt_ov204_021BDB30
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRO_CMD_Main  0x021BEF88  thumb  ov204
 *   INTRO_GRAPHIC_UpdateDisplay  0x021BDD4C  thumb  ov204
 *   INTRO_GRAPHIC_Draw3d  0x021BDD60  thumb  ov204
 *   INTRO_G3D_UpdateIdleAnim  0x021BF898  thumb  ov204
 *   INTRO_MCSS_Main  0x021BF610  thumb  ov204
 *   INTRO_PARTICLE_Main  0x021BFCE0  thumb  ov204
 *   INTRO_G3D_Draw  0x021BF9FC  thumb  ov204
 *   INTRO_GRAPHIC_Draw3dEnd  0x021BDD6C  thumb  ov204
 */
#include "../include/Obj03919.h"

typedef unsigned char  u8;
extern int INTRO_CMD_Main(char *p);
extern void INTRO_GRAPHIC_UpdateDisplay(u8 *p);
extern void INTRO_GRAPHIC_Draw3d(char *p);
extern void INTRO_G3D_UpdateIdleAnim(char *p);
extern void INTRO_MCSS_Main(u8 *p);
extern void INTRO_PARTICLE_Main(int);
extern void INTRO_G3D_Draw(char *p);
extern void INTRO_GRAPHIC_Draw3dEnd(char *p);

int INTRO_GRAPHIC_Main(int a, int b, int c, void *p)
{
    if (INTRO_CMD_Main((char *)(((struct Obj03919 *)p)->f14)) == 0) {
        return 1;
    }
    INTRO_GRAPHIC_UpdateDisplay((u8 *)(((struct Obj03919 *)p)->f8));
    INTRO_GRAPHIC_Draw3d((char *)(((struct Obj03919 *)p)->f8));
    INTRO_G3D_UpdateIdleAnim((char *)(((struct Obj03919 *)p)->f18));
    INTRO_MCSS_Main((u8 *)(((struct Obj03919 *)p)->f18));
    INTRO_PARTICLE_Main(((struct Obj03919 *)p)->f20);
    INTRO_G3D_Draw((char *)(((struct Obj03919 *)p)->f1C));
    INTRO_GRAPHIC_Draw3dEnd((char *)(((struct Obj03919 *)p)->f8));
    return 0;
}
