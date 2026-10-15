/*
 * file:     poke_summary_anim.c
 * unit:     yes
 * function: func_021B75E0, func_021B75FC, func_021B7618, func_021B7634
 * address:  0x021B75E0
 * region:   ov173
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B7460  0x021B7460  thumb  ov173
 */
#include "../../matched/include/Obj14316.h"
#include "../../matched/include/Obj14317.h"
#include "../../matched/include/Obj14318.h"
#include "../../matched/include/Obj24178.h"
#include "../../matched/include/Obj24179.h"

typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern void func_021B7460(char *p, u32 kind);
int func_021B75E0(int *p);
int func_021B75FC(int *p);
int func_021B7618(int *p);
int func_021B7634(u8 *p);
int func_021B764C(u8 *p);


int func_021B75E0(int *p)
{
    func_021B7460((char *)p, 7);
    ((struct Obj14316 *)p)->f1BA = 3;
    ((struct Obj14316 *)p)->f1B0 = 3;
    return 2;
}


int func_021B75FC(int *p)
{
    func_021B7460((char *)p, 8);
    ((struct Obj14317 *)p)->f1B0 = 8;
    *(unsigned char *)(((struct Obj14317 *)p)->f0 + 0x1a) = 1;
    return 2;
}


int func_021B7618(int *p)
{
    func_021B7460((char *)p, 4);
    ((struct Obj14318 *)p)->f1BA = 2;
    ((struct Obj14318 *)p)->f1B0 = 3;
    return 2;
}

int func_021B7634(u8 *p) {func_021B7460((char *)p,5);((struct Obj24178 *)p)->f1B0=6;return 2;}

int func_021B764C(u8 *p) {((struct Obj24179 *)p)->f1B0=10;return 0;}
