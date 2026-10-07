/*
 * file:     worldtrade_adapter_p23.c
 * unit:     yes
 * function: func_021FF218, func_021FF26C
 * address:  0x021FF218
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 *   func_021FE9B0 0x021FE9B0 thumb ov135
 *   func_0204B878 0x0204B878 arm
 *   func_020355C4 0x020355C4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021FE264 0x021FE264 thumb ov135
 *   d_02203D4A 0x02203D4A data a2
 *   func_021FF318 0x021FF318 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 */
#include "../../matched/include/Obj00018.h"

struct Actor;
struct Obj;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern u32 func_0204B98C(struct Actor *a);
extern int func_021FE9B0(char *);
extern void func_0204B878(struct Obj *p, u16 value);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_021FE264(u8 *p, int mode);
extern void func_021FF318(u8 *p, u32 k, int b, int c, int d);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
int func_021FF218(char *p);
int func_021FF26C(char *p);
extern const u16 d_02203D4A[][4];

int func_021FF218(char *p)
{
    if (func_0204B98C((struct Actor *)(((struct Obj00018 *)p)->fBF4)) == 0) {
        func_0204B878((struct Obj *)(((struct Obj00018 *)p)->fBF4), d_02203D4A[func_021FE9B0(p)][0]);
        if (func_020355C4() == 1)
            func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 0);
        else
            func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 1);
        func_021FE264((u8 *)p, func_021FE9B0(p));
    }
    return 2;
}

int func_021FF26C(char *p)
{
    if (func_0204B98C((struct Actor *)(((struct Obj00018 *)p)->fBF4)) == 0) {
        func_0204B878((struct Obj *)(((struct Obj00018 *)p)->fBF4), d_02203D4A[func_021FE9B0(p)][0]);
        if (func_020355C4() == 1)
            func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 0);
        else
            func_0204B3DC((struct Obj *)((struct Obj00018 *)p)->fBF4, 1);
        func_021FF318((u8 *)p, 15, 1, 0, 0xf0f);
        func_021F4E98((u8 *)p, 23, 26);
    }
    return 2;
}
