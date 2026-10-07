/*
 * file:     field_wfbc_p32.c
 * unit:     yes
 * function: func_02196A4C, func_02196A60
 * address:  0x02196A4C
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
 *   func_020221A4  0x020221A4  thumb
 *   func_02051C88  0x02051C88  arm
 *   func_02196034  0x02196034  thumb  ov021
 *   func_0219630C  0x0219630C  thumb  ov021
 *   func_021966B0  0x021966B0  thumb  ov021
 *   func_02197190  0x02197190  thumb  ov021
 *   func_0219649C  0x0219649C  thumb  ov021
 *   func_02196BF8  0x02196BF8  thumb  ov021
 *   func_02196FF0  0x02196FF0  thumb  ov021
 *   func_02051B84  0x02051B84  arm
 *   d_021D3FE0     0x021D3FE0  data  ov021  a4
 *   d_021D3FF4     0x021D3FF4  data  ov021  a4
 *   d_021DDAF4     0x021DDAF4  data  ov021  a4
 */
#include "../../matched/include/Obj19634.h"
#include "../../matched/include/Obj00093.h"

struct Ctx;
struct Cb;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef signed int     s32;

struct Rec8 { u32 a; u32 b; };

extern u32 func_020221A4(void);
extern s32 func_02051C88(struct Ctx *c);
extern void func_02196034(u8 *p, void *fn, u32 n);
extern void func_0219630C(u32 a, void *b, u8 *c, void *d, u32 e, u32 f);
extern void func_021966B0(u8 *p, u32 n);
extern void func_02197190(u8 *p);
extern void func_0219649C(void *a, int b, struct Cb *c);
extern int func_02196BF8(u32 v, u8 *p);
extern void func_02196FF0(u8 *p);
extern void *func_02051B84(u8 *a0, int a1, int a2, int a3);
void func_02196A4C(u8 *a);
void func_02196A60(u8 *p);
extern struct Rec8 d_021D3FE0;
extern u8 d_021D3FF4[];
extern u8 d_021DDAF4[];


/*
 * Addresses are Black-image addresses.
 */
void func_02196A4C(u8 *a)
{
    if (func_020221A4() != 0) {
        func_02051C88((struct Ctx *)(((struct Obj19634 *)a)->f24));
    }
}


/*
 * State setup: copies an 8-byte record, calls the setup helpers, installs
 * the per-frame handler at +4 and registers the next step.
 *
 * Addresses are Black-image addresses.
 */
void func_02196A60(u8 *p)
{
    struct Rec8 loc = d_021D3FE0;

    func_02197190(p);
    func_021966B0(p, 0xC);
    func_0219630C(2, &loc, p, d_021DDAF4, 0, 0);
    ((struct Obj00093 *)p)->f24 = func_02051B84(d_021D3FF4, (int)func_0219649C, (int)p, ((struct Obj00093 *)p)->f10);
    ((struct Obj00093 *)p)->f4 = func_02196BF8;
    func_02196034(p, func_02196FF0, 0x432);
}
