/*
 * file:     pms_input_view_p05.c
 * unit:     yes
 * function: func_021B99E4, func_021B99F0, func_021B9A48
 * address:  0x021B99E4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021C1C88 0x021C1C88 data ov110 a4
 */
#include "../../matched/include/Obj22313.h"
#include "../../matched/include/Obj07996.h"
#include "../../matched/include/Obj22314.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

extern int func_02024810(u8 *);
u8 *func_021B99E4(u8 *p);
u16 func_021B99F0(int unused, int id, int index);
int func_021B9A3C(u8 *p, u16 a1, int a2);
int func_021B9A48(u32 a0);
extern u8 *d_021C1C88[];


u8 *func_021B99E4(u8 *p) { return p + 4 + (((struct Obj22313 *)p)->f2 - 1) * 2; }

u16 func_021B99F0(int unused, int id, int index) {
    u8 *p = d_021C1C88[id];
    int n = 0;
    while (((struct Obj07996 *)p)->f0 != 65535) {
        if (n == index) {
            if (((struct Obj07996 *)p)->f0 == 65534) p = func_021B99E4(p);
            return ((struct Obj07996 *)p)->f0;
        }
        if (((struct Obj07996 *)p)->f0 == 65534) {
            p = func_021B99E4(p);
            p += 2;
        } else {
            p += 2;
        }
        ++n;
    }
    return 0;
}

/*
 * lever: explicit if/else increments preserve the branch after the skip call.
 */
int func_021B9A3C(u8 *p, u16 a1, int a2) { return func_02024810(*(u8 * *)&((struct Obj22314 *)p)->f4); }


int func_021B9A48(u32 a0) { return 0xffff; }
