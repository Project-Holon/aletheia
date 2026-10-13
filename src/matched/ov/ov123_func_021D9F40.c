/*
 * function: func_021D9F40
 * address: 0x021D9F40
 * packet: pkt_ov123_021D9F40
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021D9F54 re-reads the byte stored at 021D9F52; 021D9F8C re-reads the halfword stored at 021D9F8A.
 * symbols:
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_02040618 0x02040618 arm
 */
#include "../include/Obj03274.h"
typedef unsigned char u8;
typedef short s16;
extern void GX_LoadBGPltt(void *, unsigned int, unsigned int);
extern void func_0207E468(void *, unsigned int, unsigned int);
typedef unsigned int   u32;
extern void func_02040618(u32 layer, u32 a, u32 b);
void func_021D9F40(void *unused, char *p)
{
    if (((struct Obj03274 *)p)->f4) {
        ((struct Obj03274 *)p)->f96B^=1;
        if (!(*(volatile u8 *)&((struct Obj03274 *)p)->f96B&1)) {
            GX_LoadBGPltt(p+0x1f0+((struct Obj03274 *)p)->f968*32,40,14);
            func_0207E468(p+0x1f0+((struct Obj03274 *)p)->f968*32,40,14);
            ++((struct Obj03274 *)p)->f968;
            if (*(volatile s16 *)&((struct Obj03274 *)p)->f968>=60) ((struct Obj03274 *)p)->f968=0;
            func_02040618(((struct Obj03274 *)p)->f96C,2,7);
        }
    }
}
