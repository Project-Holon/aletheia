/*
 * function: func_02200800
 * address: 0x02200800
 * packet: pkt_ov135_02200800
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: if/else dispatch retains the compare after the first full arm.
 * symbols:
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02040588 0x02040588 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 */
#include "../include/Obj00045.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021F4D14(char *p);
extern void func_021F4CE4(char *p);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
struct Descriptor;
extern void func_0201F7A8(void *desc, u32 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0204B92C(struct Obj *p, unsigned int v);
int func_02200800(u8 *p)
{
    u32 w;
    u32 state;
    state = func_021F4D14((char *)p);
    if (state == 1) {
        func_021F4CE4((char *)p);
        func_0201F7A8((void *)(*(u32 *)&((struct Obj00045 *)p)->fDD0), 2);
        w = *(u32 *)&((struct Obj00045 *)p)->fDD0;
        BMP_WIN_ClearScreen((struct Descriptor *)w);
        func_02041B6C(func_02045730((struct Descriptor *)w));
        w = ((struct Obj00045 *)p)->fDE0;
        BMP_WIN_ClearScreen((struct Descriptor *)w);
        func_02041B6C(func_02045730((struct Descriptor *)w));
        func_02040588(6, 0);
        func_0204B3DC((struct Obj *)((struct Obj00045 *)p)->fD38, 0);
        func_021F4EC0(p, 0, 0x14);
        ((struct Obj00045 *)p)->f28 = 7;
    } else if (state == 2) {
        func_021F4CE4((char *)p);
        func_0201F7A8((void *)(*(u32 *)&((struct Obj00045 *)p)->fDD0), 2);
        w = *(u32 *)&((struct Obj00045 *)p)->fDD0;
        BMP_WIN_ClearScreen((struct Descriptor *)w);
        func_02041B6C(func_02045730((struct Descriptor *)w));
        func_0204B92C((struct Obj *)((struct Obj00045 *)p)->fBF4, 1);
        ((struct Obj00045 *)p)->f28 = 5;
        func_0204B3DC((struct Obj *)((struct Obj00045 *)p)->fBF4, 1);
    }
    return 2;
}
