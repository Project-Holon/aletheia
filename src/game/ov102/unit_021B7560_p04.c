/*
 * file:     unit_021B7560_p04.c
 * unit:     yes
 * function: func_021B8320, func_021B838C
 * address:  0x021B8320
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B7DFC 0x021B7DFC thumb ov102
 *   func_021B63C4 0x021B63C4 thumb ov101
 *   func_021B63BC 0x021B63BC thumb ov101
 *   func_021B61E8 0x021B61E8 thumb ov101
 *   func_021B7F08 0x021B7F08 thumb ov102
 *   func_021B81B0 0x021B81B0 thumb ov102
 *   func_021B7F18 0x021B7F18 thumb ov102
 */
#include "../../matched/include/Obj10237.h"
#include "../../matched/include/Obj22152.h"
#include "../../matched/include/Obj22153.h"
#include "../../matched/include/Obj22154.h"
#include "../../matched/include/Obj07976.h"
#include "../../matched/include/Obj22155.h"
#include "../../matched/include/Obj22156.h"
#include "../../matched/include/Obj22157.h"
#include "../../matched/include/Obj22158.h"

struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

extern void func_021B7DFC(u8 *, void *, int, int, s16);
extern void func_021B63C4(int *);
extern void func_021B63BC(int *);
extern int func_021B61E8(struct Obj *o);
extern void func_021B7F08(unsigned p, unsigned x);
extern void func_021B81B0(u8 *, u16 *);
extern void func_021B7F18(u8 *);
void func_021B8320(u8 *p, u16 *state);
void func_021B838C(u8 *p, u16 *state);

void func_021B8320(u8 *p, u16 *state)
{
    switch (*state) {
    case 0:
        func_021B7DFC(p + 0xac, p + 0x9c, 5, 0, 0);
        func_021B63C4(*(int * *)&((struct Obj22152 *)(*(u8 * *)&((struct Obj10237 *)p)->f48C))->f4);
        func_021B63BC(*(int * *)&((struct Obj22153 *)(*(u8 * *)&((struct Obj10237 *)p)->f48C))->f4);
        *state = 1;
        break;
    case 1:
        if (func_021B61E8((struct Obj *)(*(int * *)&((struct Obj22154 *)(*(u8 * *)&((struct Obj10237 *)p)->f48C))->f4)))
            *state = 2;
        break;
    case 2:
        func_021B7F08((unsigned int)p, (unsigned int)func_021B81B0);
        break;
    }
}

void func_021B838C(u8 *p, u16 *state)
{
    switch (*state) {
    case 0:
        *state = 1;
        func_021B63C4(*(int * *)&((struct Obj22155 *)(*(u8 * *)&((struct Obj07976 *)p)->f48C))->f4);
        func_021B63BC(*(int * *)&((struct Obj22156 *)(*(u8 * *)&((struct Obj07976 *)p)->f48C))->f4);
        break;
    case 1:
        if (func_021B61E8((struct Obj *)(*(int * *)&((struct Obj22157 *)(*(u8 * *)&((struct Obj07976 *)p)->f48C))->f4)))
            *state = 2;
        break;
    case 2:
        ((struct Obj22158 *)(*(u8 * *)&((struct Obj07976 *)p)->f48C))->fC = 2;
        func_021B7F18(p);
        break;
    }
}
