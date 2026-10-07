/*
 * file:     wifibattlematch_view_p04.c
 * unit:     yes
 * function: func_021E564C, func_021E5668
 * address:  0x021E564C
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204A600  0x0204A600  arm
 */
#include "../../matched/include/Obj24444.h"

struct Bank;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef signed int s32;

extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02082BCC(int *, int, int);
extern void func_0204A600(void);
void func_021E564C(int *p);
void func_021E5668(void *p);


void func_021E564C(int *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj24444 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}


void func_021E5668(void *p)
{
    func_0204A600();
}
