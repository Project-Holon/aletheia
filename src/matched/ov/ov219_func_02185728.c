/*
 * function: func_02185728
 * address: 0x02185728
 * packet: pkt_ov219_02185728
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   d_02185F00 0x02185F00 data a4
 *   d_02185E0C 0x02185E0C data a4
 *   d_02185DF4 0x02185DF4 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 */
#include "../include/Obj10975.h"
#include "../include/G_02185E0C.h"
#include "../include/G_Vec3.h"
typedef unsigned short u16;
typedef struct {unsigned x,y,z;} Vec3;
typedef struct {Vec3 vec;short x,y;} Config;
extern struct G_02185E0C d_02185E0C;
extern struct Vec3 d_02185DF4;
extern Vec3 d_02185F00;
extern Config d_020A1EB8;
extern void *G3D_CAMERA_Create(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,Vec3 *,Vec3 *,Vec3 *,u16);
struct Light;
extern void G3D_CAMERA_Reset(struct Light *l);
void func_02185728(char *p)
{
    Vec3 vec;
    u16 heap;
    heap=((struct Obj10975 *)p)->f0;
    vec=d_02185F00;
    ((struct Obj10975 *)p)->fC36C=G3D_CAMERA_Create(0,d_020A1EB8.x,d_020A1EB8.y,5461,0,4096,4194304,0,((Vec3 *)&d_02185E0C),&vec,((Vec3 *)&d_02185DF4),heap);
    G3D_CAMERA_Reset(((struct Obj10975 *)p)->fC36C);
}
