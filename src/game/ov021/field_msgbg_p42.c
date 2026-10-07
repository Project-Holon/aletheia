/*
 * file:     field_msgbg_p42.c
 * unit:     yes
 * function: func_0218F818, func_0218F848, func_0218F878, func_0218F89C
 * address:  0x0218F818
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
 *   func_0218E13C  0x0218E13C  thumb
 *   func_0218F780  0x0218F780  thumb
 *   func_0218F7D0  0x0218F7D0  thumb
 *   func_0218FB1C  0x0218FB1C  thumb  ov021
 */
#include "../../matched/include/Obj02371.h"
#include "../../matched/include/Obj07423.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef struct {
    u32 saved;
    u8 body[0x94];
    u32 active;
} Sub;

typedef struct { u32 w[12]; } B48;

typedef struct { u32 w[6]; } B24;

extern void func_0218E13C(u8 *a, u32 s);
extern void func_0218F780(u8 *s, u8 *d);
extern void func_0218F7D0(u8 *s, u8 *d);
extern void func_0218FB1C(u8 *p);
void func_0218F818(u8 *a);
void func_0218F848(u8 *a);
void func_0218F878(u8 *a);
void func_0218F89C(u8 *p, u8 *src, u16 v);


void func_0218F818(u8 *a)
{
    if (a != 0) {
        Sub *s = (Sub *)(a + 0xf0);
        if (s->active == 0) {
            s->saved = ((struct Obj02371 *)a)->f14;
            func_0218E13C(a, 0);
            func_0218F780(a, s->body);
            s->active = 1;
        }
    }
}


void func_0218F848(u8 *a)
{
    if (a != 0) {
        Sub *s = (Sub *)(a + 0xf0);
        if (s->active == 0) {
            s->saved = ((struct Obj02371 *)a)->f14;
            func_0218E13C(a, 0);
            func_0218F7D0(a, s->body);
            s->active = 1;
        }
    }
}


void func_0218F878(u8 *a)
{
    if (a != 0) {
        Sub *s = (Sub *)(a + 0xf0);
        if (s->active != 0) {
            func_0218E13C(a, s->saved);
            s->active = 0;
        }
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_0218F89C(u8 *p, u8 *src, u16 v)
{
    u8 *q;
    if (p) {
        q = p + 0xf0;
        func_0218E13C(p, 0);
        *(B48 *)(q + 0x64) = *(B48 *)src;
        ((struct Obj07423 *)q)->f96 = 0;
        ((struct Obj07423 *)q)->f94 = v;
        *(B24 *)(q + 0xa0) = *(B24 *)(src + 0x30);
        ((struct Obj02371 *)p)->f1AC = (void *)func_0218FB1C;
        ((struct Obj07423 *)q)->fB8 = 0;
        ((struct Obj07423 *)q)->f9C = 1;
    }
}
