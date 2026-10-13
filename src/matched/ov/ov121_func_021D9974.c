/*
 * function: func_021D9974
 * address: 0x021D9974
 * packet: pkt_ov121_021D9974
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: two trailing zero alignment bytes.
 * symbols:
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   PARTICLE_Main 0x02050BE8 arm
 */
#include "../include/Obj10413.h"
typedef unsigned char u8;
struct Light;
extern void G3D_SYSTEM_DrawStart(void *);
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void PARTICLE_Main(void);
void func_021D9974(void **p) {
    if(((struct Obj10413 *)p)->f4) {
        G3D_SYSTEM_DrawStart(((struct Obj10413 *)p)->f4);
        G3D_CAMERA_Reset(((struct Obj10413 *)p)->f0);
        G3D_SYSTEM_ApplyLookAt();
        PARTICLE_Main();
    }
}
