/*
 * file:     field_msgbg_p43.c
 * unit:     yes
 * function: func_0218F900, func_0218F918, func_0218F930, func_0218F9C4
 * address:  0x0218F900
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0218F89C  0x0218F89C  thumb
 *   func_0218F780  0x0218F780  thumb
 *   func_0218F7D0  0x0218F7D0  thumb
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0218FC80  0x0218FC80  thumb  ov021
 *   func_0218FB1C  0x0218FB1C  thumb  ov021
 */
#include "../../matched/include/Obj07424.h"
#include "../../matched/include/Obj19572.h"
#include "../../matched/include/Obj01653.h"
#include "../../matched/include/Obj05980.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef struct { u32 w[3]; } B12;

typedef struct { u32 w[6]; } B24;

typedef struct { u32 w[12]; } B48;

extern void func_0218F89C(void *a);
extern void func_0218F780(u8 *s, u8 *d);
extern void func_0218F7D0(u8 *s, u8 *d);
extern void func_0218E13C(u8 *p, u32 v);
extern void func_0218FC80(u8 *p);
extern void func_0218FB1C(u8 *p);
void func_0218F900(u8 *a, void *p, int n);
void func_0218F918(u8 *a);
void func_0218F930(u8 *p, u8 *a, u8 *b, u32 *c, u16 v);
void func_0218F9C4(u8 *p, u8 *src, u16 v);


void func_0218F900(u8 *a, void *p, int n)
{
    if (a != 0) {
        func_0218F89C(a);
        func_0218F780(a, a + 0x124);
    }
}


void func_0218F918(u8 *a)
{
    if (a != 0) {
        func_0218F89C(a);
        func_0218F7D0(a, a + 0x124);
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_0218F930(u8 *p, u8 *a, u8 *b, u32 *c, u16 v)
{
    u8 *q;
    B24 loc;
    if (p) {
        q = p + 0xf0;
        func_0218E13C(p, 2);
        func_0218F780(p, q + 0x34);
        *(B12 *)(q + 0x64) = *(B12 *)a;
        *(B12 *)(q + 0x70) = *(B12 *)b;
        ((struct Obj07424 *)q)->f96 = 0;
        ((struct Obj07424 *)q)->f94 = v;
        loc.w[5] = c[5];
        loc.w[1] = 0;
        loc.w[4] = c[4];
        loc.w[2] = 0;
        loc.w[3] = 0;
        loc.w[0] = c[0];
        *(B24 *)(q + 0xa0) = loc;
        ((struct Obj19572 *)p)->f1AC = (void *)func_0218FC80;
        ((struct Obj07424 *)q)->fB8 = 0;
        ((struct Obj07424 *)q)->f9C = 1;
    }
}


void func_0218F9C4(u8 *p, u8 *src, u16 v)
{
    u8 *q;
    if (p) {
        q = p + 0xf0;
        if (((struct Obj05980 *)q)->f98 != 0 && v != 0) {
            func_0218E13C(p, 0);
            func_0218F780(p, q + 0x34);
            *(B48 *)(q + 0x64) = *(B48 *)(q + 4);
            ((struct Obj05980 *)q)->f96 = 0;
            ((struct Obj05980 *)q)->f94 = v;
            *(B24 *)(q + 0xa0) = *(B24 *)src;
            ((struct Obj01653 *)p)->f1AC = (void *)func_0218FB1C;
            ((struct Obj05980 *)q)->fB8 = 0;
            ((struct Obj05980 *)q)->f9C = 1;
        }
    }
}
