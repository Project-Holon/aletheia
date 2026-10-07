/*
 * file:     btl_server_p132.c
 * unit:     yes
 * function: func_021CDF1C, func_021CDF58
 * address:  0x021CDF1C
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
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B86C0 0x021B86C0 thumb ov093
 *   func_021B9064 0x021B9064 thumb ov093
 *   func_021B9920 0x021B9920 thumb ov093
 *   func_021EAA00  0x021EAA00  thumb  ov093
 *   func_021CE068  0x021CE068  thumb  ov093
 *   func_021CE08C  0x021CE08C  thumb  ov093
 *   func_021EAA5C  0x021EAA5C  thumb  ov093
 *   func_021EAA34  0x021EAA34  thumb  ov093
 *   func_021CDFE4  0x021CDFE4  thumb  ov093
 *   func_021CE0E0  0x021CE0E0  thumb  ov093
 */
#include "../../matched/include/Obj04362.h"
#include "../../matched/include/Obj01892.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern u32 func_021B8588(void **);
extern u8 func_021B86C0(u8 **);
extern u32 func_021B9064(u8 *p, int k, int x);
extern u8 *func_021B9920(void *p, u32 i, u8 j);
extern void func_021EAA00(u8 *p, u8 v);
extern void func_021CE068(u8 *p);
extern int func_021CE08C(u8 *p);
extern void func_021EAA5C(u8 *o);
extern int func_021EAA34(u8 *o, u8 *out);
extern u32 func_021CDFE4(u32 mode);
extern void func_021CE0E0(u8 *p);
void *func_021CDF1C(u8 *p);
int func_021CDF58(u8 *p, int *st);

/*
 * Prototype: original narrows getter result to u8 before 021B9920;
 * caller extern has u8 second argument; named u8 local keeps shift in r0.
 */
void *func_021CDF1C(u8 *p) { u8 side; if(func_021B8588(*(void ** *)&((struct Obj04362 *)p)->f0)==0 && func_021B86C0(*(u8 ** *)&((struct Obj04362 *)p)->f0)==0) { side=func_021B9064(*(u8 * *)&((struct Obj04362 *)p)->f0,p[0x1a6],0); return func_021B9920(*(char * *)&((struct Obj04362 *)p)->f4,side,0); } return 0; }


int func_021CDF58(u8 *p, int *st)
{
    u8 buf;

    switch (*st) {
    case 0:
        func_021EAA00(((struct Obj01892 *)p)->f54, p[0xc4]);
        func_021CE068(p);
        *st = *st + 1;
        break;
    case 1:
        if (func_021CE08C(p) != 0) {
            func_021EAA5C(((struct Obj01892 *)p)->f54);
            *st = 2;
        } else if (func_021EAA34(((struct Obj01892 *)p)->f54, &buf) != 0) {
            p[0xc4] = buf;
            *st = 3;
        }
        break;
    case 2:
        p[0xc4] = func_021CDFE4(p[0xc4]);
        *st = *st + 1;
        break;
    case 3:
        func_021CE0E0(p);
        *st = *st + 1;
        break;
    case 4:
        *(u8 * *)&((struct Obj01892 *)p)->fD8 = p + 0xc4;
        ((struct Obj01892 *)p)->fDC = 1;
        return 1;
    }
    return 0;
}
