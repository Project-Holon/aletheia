/*
 * function: func_021DE80C
 * address: 0x021DE80C
 * packet: pkt_ov171_021DE80C
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   BMP_Create 0x02043678 arm
 *   BMP_OAM_Create 0x020255A0 thumb
 *   BMP_OAM_SetEnabled 0x02025774 thumb
 */
#include "../include/Obj01756.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Descriptor {
    void *image;
    u16 x, y;
    void *source;
    u32 mode;
    u8 a, b;
    u16 id;
    u32 extra;
} Descriptor;
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
struct Bmp;
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
struct Grid;
struct Param;
struct Sys;
extern struct Grid *BMP_OAM_Create(struct Sys *sys, const struct Param *param);
extern void BMP_OAM_SetEnabled(u8 *g, u32 a);
void func_021DE80C(char *p)
{
    Descriptor descriptor;
    ((struct Obj01756 *)p)->fC50 = BMP_OAM_CreateSys(0x8C, ((struct Obj01756 *)p)->fB70);
    ((struct Obj01756 *)p)->fC58 = BMP_Create(5, 3, 0x20, 0x8C);
    descriptor.image = ((struct Obj01756 *)p)->fC58;
    descriptor.x = 0x28;
    descriptor.y = 0xA8;
    descriptor.source = ((struct Obj01756 *)p)->fC18;
    descriptor.mode = 1;
    descriptor.a = 0;
    descriptor.b = 0;
    descriptor.id = 0xFFFF;
    descriptor.extra = 0;
    ((struct Obj01756 *)p)->fC54 = BMP_OAM_Create(((struct Obj01756 *)p)->fC50, (const struct Param *)(&descriptor));
    if (((struct Obj01756 *)p)->fC5F == 1) BMP_OAM_SetEnabled(((struct Obj01756 *)p)->fC54, 0);
}
