/*
 * function: func_021DECB0
 * address: 0x021DECB0
 * packet: pkt_ov183_021DECB0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 * symbols:
 *   func_021DF388 0x021DF388 thumb ov183
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 */
#include "../include/Obj02894.h"
#include "../include/Obj24599.h"
#include "../include/Obj24600.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021DF388(char *p);
extern void func_021FC734(u8 *p);
extern void func_020409B4(u32 index);
extern void func_021FB494(char *p);
extern void func_021FC0C8(char *p, unsigned i);
extern void func_021FBDA4(int a, unsigned mode);
extern int func_021FD744(int a);
void func_021DECB0(void *a, int b, char *p)
{
    func_021DF388(p + 0x28);
    ((struct Obj02894 *)p)->f100 = 0;
    func_021FC734(((struct Obj02894 *)p)->fC);
    ((struct Obj02894 *)p)->fC = 0;
    func_021FC734(((struct Obj02894 *)p)->f8);
    ((struct Obj02894 *)p)->f8 = 0;
    func_020409B4(4);
    func_020409B4(1);
    func_021FB494(((struct Obj02894 *)p)->f4);
    ((struct Obj02894 *)p)->f4 = 0;
    func_021FC0C8(((struct Obj24599 *)(*(char * *)&((struct Obj02894 *)p)->f108))->f10, 6);
    func_021FBDA4((int)(((struct Obj24600 *)(*(char * *)&((struct Obj02894 *)p)->f108))->f10), 24);
    ((struct Obj02894 *)p)->f104 = 0;
    func_021FD744((int)a);
}
