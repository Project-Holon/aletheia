/*
 * file:     unit_021B95A0_p07.c
 * unit:     yes
 * function: func_021BA65C, func_021BA668, func_021BA694, func_021BA6B8, func_021BA730
 * address:  0x021BA65C
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02028230  0x02028230  thumb
 *   func_020282A4  0x020282A4  thumb
 *   func_02028218  0x02028218  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02028148  0x02028148  thumb
 *   func_02027FEC  0x02027FEC  thumb
 */
#include "../../matched/include/Obj13139.h"
#include "../../matched/include/Obj13140.h"
#include "../../matched/include/Obj06169.h"
#include "../../matched/include/Obj20643.h"

struct Obj;
struct MsgBank;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

typedef struct { u32 h; u16 x; u16 pad; u32 idx; } Ent;

typedef struct { u8 pad[0x1c]; Ent e[2]; } P;

extern u32 func_02028230(u8 *p);
extern void func_020282A4(struct Obj *obj);
extern void func_02028218(struct Obj *obj, u32 a);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02028148(u8 *p);
extern u32  func_02027FEC(u32 a, u8 *b, u8 c, u32 d, u32 e, u32 f);
int func_021BA65C(u8 *p, int *out);
u32 func_021BA668(u8 *p);
void func_021BA694(u8 *p);
void func_021BA6B8(u8 *p, u32 arg);
int func_021BA730(u8 *p);


int func_021BA65C(u8 *p, int *out)
{
    if (out != 0)
        *out = ((struct Obj13139 *)p)->fC;
    return ((struct Obj13139 *)p)->f10;
}


u32 func_021BA668(u8 *p)
{
    u32 r = 0;

    if (((struct Obj13140 *)p)->f10 != 0) {
        u32 t = ((struct Obj13140 *)p)->fC;

        if (t != 3) {
            r = func_02028230((u8 *)(*(u32 *)(p + t * 4 + 0x34)));
            if (r != 0) {
                func_021BA694(p);
            }
        }
    }
    return r;
}


void func_021BA694(u8 *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        func_020282A4((struct Obj *)(*(u32 *)(p + i * 4 + 0x34)));
        func_02028218((struct Obj *)(*(u32 *)(p + i * 4 + 0x34)), 0);
    }
}


/*
 * The stores through a 12-byte element struct (P/Ent) versus the byte-offset
 * reads keep two separate i*12 multiplies, as in the original.
 */
void func_021BA6B8(u8 *p, u32 arg)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (*(u32 *)(p + i * 12 + 0x1c) != 0) {
            func_02045808((struct U16Vec *)(*(u32 *)(p + i * 12 + 0x1c)));
        }
        ((P *)p)->e[i].h = (u32)func_02045EC0((struct MsgBank *)(((struct Obj06169 *)p)->f18), i + 8);
        ((P *)p)->e[i].x = 0x39e3;
        ((P *)p)->e[i].idx = i;
        if (*(u32 *)(p + i * 4 + 0x34) != 0) {
            func_02028148((u8 *)(*(u32 *)(p + i * 4 + 0x34)));
        }
        *(u32 *)(p + i * 4 + 0x34) =
            func_02027FEC(((struct Obj06169 *)p)->f14, p + 0x1c + i * 12, i * 9 + 14, 0x15, 9, arg);
    }
}


/*
 * Unlabelled leaf before func_021BA734; func_021BB1C4 tests its result.
 */
int func_021BA730(u8 *p)
{
    return ((struct Obj20643 *)p)->f40;
}
