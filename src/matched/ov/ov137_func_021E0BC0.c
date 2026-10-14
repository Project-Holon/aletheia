/*
 * function: GURU2_MAIN_UpdateCardUnitAnim
 * address: 0x021E0BC0
 * packet: pkt_ov137_021E0BC0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 */
#include "../include/Obj08221.h"
#include "../include/Obj14240.h"
typedef unsigned short u16;
typedef struct { int x,y,z; } Vec;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_02048A18(u8 *a0, int i);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);
void GURU2_MAIN_UpdateCardUnitAnim(char *p,char *q,int i)
{
    void *r = (void *)func_02048A18(((struct Obj08221 *)p)->fAF4,(u16)(*(int *)(p+0xae0+i*4)));
    *(Vec *)(q+4) = *(Vec *)(*(char * *)&((struct Obj14240 *)q)->f64+0x44);
    ((struct Obj14240 *)q)->f8 += 0x14000;
    G3D_SYSTEM_LoopObjectAnimeFrame(r,0,0x1000);
}
