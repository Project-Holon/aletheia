/*
 * file:     btl_server_p93.c
 * unit:     yes
 * function: func_021C83CC, func_021C83D4, func_021C83DC, func_021C83E8
 * address:  0x021C83CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C2E4C   0x021C2E4C  thumb ov093
 *   func_021BC2B0   0x021BC2B0  thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021BB908 0x021BB908 thumb ov093
 */
#include "../../matched/include/Obj21120.h"
#include "../../matched/include/Obj13342.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern u32 func_021C2E4C(u8 *p);
extern int func_021BC2B0(u8 *p);
extern void *func_021B86B8(void ***);
extern void func_021BB908(int *, int);
u32 func_021C83CC(u8 *p);
int func_021C83D4(u8 *p);
void func_021C83DC(char *p, int x);
int func_021C83E8(unsigned char *p, int i, int b);


/*
 * tail-call thunk to func_021C2E4C
 */
u32 func_021C83CC(u8 *p)
{
    return func_021C2E4C(p);
}


/*
 * tail-call thunk to func_021BC2B0
 */
int func_021C83D4(u8 *p)
{
    return func_021BC2B0(p);
}


void func_021C83DC(char *p, int x)
{
    *(char *)(((struct Obj21120 *)p)->f4A8 + 4) = x;
}

/*
 * evidence: Original loads r1 for func_021BB908 even though its body ignores it.
 */
int func_021C83E8(unsigned char *p, int i, int b)
{
    if ((unsigned int)func_021B86B8(*(void *** *)&((struct Obj13342 *)p)->f4) <= 1) {
        func_021BB908(*(int * *)&((struct Obj13342 *)p)->f0, i);
        return 1;
    }
    return 0;
}
