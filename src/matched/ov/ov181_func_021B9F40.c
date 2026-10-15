/*
 * function: STAFF_ROLL_Draw3d
 * address: 0x021B9F40
 * packet: pkt_ov181_021B9F40
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_GetMainVisiblePlanes 0x02043658 arm
 *   STAFF_ROLL_UpdateBrightness 0x021BA2D8 thumb ov181
 *   STAFF_ROLL_UpdateLights 0x021BA128 thumb ov181
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   d_021BAC2C 0x021BAC2C data a4
 */
#include "../include/Obj03877.h"
extern unsigned BG_SYS_GetMainVisiblePlanes(void);
extern void STAFF_ROLL_UpdateBrightness(char *);
extern void STAFF_ROLL_UpdateLights(char *);
struct Arg;
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);
extern void G3D_SYSTEM_DrawStart(void);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);
extern void G3D_SYSTEM_DrawEnd(void);
extern const unsigned d_021BAC2C[];
void STAFF_ROLL_Draw3d(char *p)
{
    unsigned i;
    if (**(int * *)&((struct Obj03877 *)p)->f0 != 1 && (BG_SYS_GetMainVisiblePlanes() & 1)) {
        STAFF_ROLL_UpdateBrightness(p);
        STAFF_ROLL_UpdateLights(p);
        for (i = 0; i < ((struct Obj03877 *)p)->f24; i++)
            G3D_SYSTEM_LoopObjectAnimeFrame(((struct Obj03877 *)p)->f20, (unsigned short)i, 0x1000);
        G3D_SYSTEM_DrawStart();
        G3D_SYSTEM_ApplyLookAt();
        G3D_SYSTEM_DrawObject(((struct Obj03877 *)p)->f20, (struct Arg *)d_021BAC2C);
        G3D_SYSTEM_DrawEnd();
    }
}
