/*
 * function: GDS_RAP_RequestSearchVideos
 * address: 0x021D68EC
 * packet: pkt_ov125_021D68EC
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GDS_RAP_IsIdle 0x021D730C thumb ov125
 *   sGdsEmptyString 0x021D8D28 data a4
 *   sGdsSearchCategories 0x021D8C80 data a2
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */
#include "../include/Obj03806.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int   u32;
extern int GDS_RAP_IsIdle(char *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void MI_CpuFill8(void *, int, unsigned int);
extern const char sGdsEmptyString[];
extern const u16 sGdsSearchCategories[][2];
int GDS_RAP_RequestSearchVideos(char *p, int id, unsigned int index, int mode, u8 other)
{
    if (!GDS_RAP_IsIdle(p)) return 0;
    if (index >= 20) func_02034714(sGdsEmptyString, 0, sGdsEmptyString);
    MI_CpuFill8(p + 0x174, 0, 16);
    ((struct Obj03806 *)p)->f174 = id;
    ((struct Obj03806 *)p)->f176 = sGdsSearchCategories[index][0];
    ((struct Obj03806 *)p)->f178 = sGdsSearchCategories[index][1];
    ((struct Obj03806 *)p)->f17A = mode;
    ((struct Obj03806 *)p)->f17B = other;
    ((struct Obj03806 *)p)->f17C = 100;
    ((struct Obj03806 *)p)->f3E0 = 0;
    ((struct Obj03806 *)p)->f3D8 = 0x55f1;
    return 1;
}
