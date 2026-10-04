/*
 * function: func_021B9D10
 * address: 0x021B9D10
 * packet: pkt_ov218_021B9D10
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA554 0x021BA554 thumb ov218
 *   func_021B8AB8 0x021B8AB8 thumb ov067
 *   func_021BA680 0x021BA680 thumb ov218
 *   func_021B93A4 0x021B93A4 thumb ov067
 *   func_021B93B0 0x021B93B0 thumb ov067
 *   func_021BA6BC 0x021BA6BC thumb ov218
 */
#include "../include/Obj03959.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021BA554(u8 *,int);
extern int func_021B8AB8(u8 *);
extern void func_021BA680(u8 *,int);
extern int func_021B93A4(char *);
extern int func_021B93B0(char *);
extern void func_021BA6BC(u8 *,int);
void func_021B9D10(u8 *p,int delta)
{
    int selected;
    s16 y;
    func_021BA554(p,(int)(0u-(u32)delta));
    y=func_021B8AB8(*(u8 * *)&((struct Obj03959 *)p)->f2C);
    func_021BA680(p,y);
    selected=func_021B93A4(*(char * *)&((struct Obj03959 *)p)->f2C);
    func_021BA6BC(p,(int)(((u32)selected-(u32)func_021B93B0(*(char * *)&((struct Obj03959 *)p)->f2C))*2+92));
}
