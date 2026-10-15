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
 *   BR_UTIL_Delete 0x021FC734 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   BR_BTN_DeleteObject 0x021FB494 thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   BR_UTIL_ClearTaskStep 0x021FD744 thumb ov186
 */
#include "../include/Obj02894.h"
#include "../include/Obj24599.h"
#include "../include/Obj24600.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021DF388(char *p);
extern void BR_UTIL_Delete(u8 *p);
extern void func_020409B4(u32 index);
extern void BR_BTN_DeleteObject(char *p);
extern void BR_RES_ReleaseSprite(char *p, unsigned i);
extern void BR_RES_ApplyBgSet(int a, unsigned mode);
extern int BR_UTIL_ClearTaskStep(int *a);
void func_021DECB0(void *a, int b, char *p)
{
    func_021DF388(p + 0x28);
    ((struct Obj02894 *)p)->f100 = 0;
    BR_UTIL_Delete(((struct Obj02894 *)p)->fC);
    ((struct Obj02894 *)p)->fC = 0;
    BR_UTIL_Delete(((struct Obj02894 *)p)->f8);
    ((struct Obj02894 *)p)->f8 = 0;
    func_020409B4(4);
    func_020409B4(1);
    BR_BTN_DeleteObject(((struct Obj02894 *)p)->f4);
    ((struct Obj02894 *)p)->f4 = 0;
    BR_RES_ReleaseSprite(((struct Obj24599 *)(*(char * *)&((struct Obj02894 *)p)->f108))->f10, 6);
    BR_RES_ApplyBgSet((int)(((struct Obj24600 *)(*(char * *)&((struct Obj02894 *)p)->f108))->f10), 24);
    ((struct Obj02894 *)p)->f104 = 0;
    BR_UTIL_ClearTaskStep((int *)a);
}
