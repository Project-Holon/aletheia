/*
 * file:     plist_battle_p12.c
 * unit:     yes
 * function: func_021BC2C8, func_021BC30C
 * address:  0x021BC2C8
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BB97C  0x021BB97C  thumb  ov091
 *   func_021BB9AC  0x021BB9AC  thumb  ov091
 *   func_021B9788  0x021B9788  thumb  ov091
 *   func_021BB98C  0x021BB98C  thumb  ov091
 *   func_021B9E3C  0x021B9E3C  thumb  ov091
 *   func_021B9E20  0x021B9E20  thumb  ov091
 */
#include "../../matched/include/Obj00009.h"

typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern void func_021BB97C(u16 *p, u32 s);
extern void func_021BB9AC(int, int, int, int);
extern void func_021B9788(u8 *p, int a1, int a2, int a3);
extern void func_021BB98C(void *p, u32 s);
extern void func_021B9E3C(char *p);
extern void func_021B9E20(u8 *p);
void func_021BC2C8(int p);
void func_021BC30C(int p);


void func_021BC2C8(int p)
{
    *(int *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x40) = 10;
    func_021BB97C((u16 *)p, *(int *)&((struct Obj00009 *)p)->f150);
    func_021BB9AC(p, *(int *)&((struct Obj00009 *)p)->f150, 0, *(u16 *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x44));
    func_021B9788((u8 *)p, 0x51, 1, (int)func_021B9E3C);
    func_021BB98C((void *)p, *(int *)&((struct Obj00009 *)p)->f150);
}


void func_021BC30C(int p)
{
    *(int *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x40) = 10;
    func_021BB97C((u16 *)p, *(int *)&((struct Obj00009 *)p)->f150);
    func_021BB9AC(p, *(int *)&((struct Obj00009 *)p)->f150, 0, *(u16 *)(*(int *)&((struct Obj00009 *)p)->f280 + 0x44));
    func_021B9788((u8 *)p, 0x51, 1, (int)func_021B9E20);
    func_021BB98C((void *)p, *(int *)&((struct Obj00009 *)p)->f150);
}
