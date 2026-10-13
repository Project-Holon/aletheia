/*
 * function: func_021BD868
 * address: 0x021BD868
 * packet: pkt_ov110_021BD868
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021BED84 0x021BED84 thumb ov110
 *   func_021BEDEC 0x021BEDEC thumb ov110
 *   func_021B9BEC 0x021B9BEC thumb ov110
 */
#include "../include/Obj13788.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void func_021BED84(u8 *,void *);
extern int func_021BEDEC(u8 *,u32 *);
extern void func_021B9BEC(u8 *,int);
void func_021BD868(u8 *p)
{
    GFL_USE_PlaySeDefaultVolume(1356);
    func_021BED84(p+0x54,p);
    ((struct Obj13788 *)p)->f28=(u32)func_021BEDEC;
    func_021B9BEC(*(u8 * *)&((struct Obj13788 *)p)->f14,12);
}
