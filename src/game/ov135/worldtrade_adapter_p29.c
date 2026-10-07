/*
 * file:     worldtrade_adapter_p29.c
 * unit:     yes
 * function: func_022007E0, func_02200800, func_022008B0
 * address:  0x022007E0
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
 *   func_021F4BE0  0x021F4BE0  thumb  ov135
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02040588 0x02040588 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B878 0x0204B878 arm
 *   func_020355C4 0x020355C4 arm
 *   func_0220053C 0x0220053C thumb ov135
 */
#include "../../matched/include/Obj18608.h"
#include "../../matched/include/Obj00045.h"
#include "../../matched/include/Obj01749.h"

struct Descriptor;
struct Obj;
struct Actor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

extern void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e);
extern int func_021F4D14(char *p);
extern void func_021F4CE4(char *p);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B878(struct Obj *p, u16 value);
extern u8 func_020355C4(void);
extern void func_0220053C(u8 *p, int mode);
int func_022007E0(u8 *p);
int func_02200800(u8 *p);
int func_022008B0(u8 *p);


/*
 * State setter: build with the fixed 0x12/0x102/0x3/0x1 argument pair and latch state 0xd.
 */
int func_022007E0(u8 *p)
{
    func_021F4BE0((u32)p, 0x12, 0x102, 0x3, 0x1);
    ((struct Obj18608 *)p)->f28 = 0xd;
    return 2;
}

/*
 * lever: if/else dispatch retains the compare after the first full arm.
 */
int func_02200800(u8 *p)
{
    u32 w;
    u32 state;
    state = func_021F4D14((char *)p);
    if (state == 1) {
        func_021F4CE4((char *)p);
        func_0201F7A8((void *)(*(u32 *)&((struct Obj00045 *)p)->fDD0), 2);
        w = *(u32 *)&((struct Obj00045 *)p)->fDD0;
        func_020456F8((struct Descriptor *)w);
        func_02041B6C(func_02045730((struct Descriptor *)w));
        w = ((struct Obj00045 *)p)->fDE0;
        func_020456F8((struct Descriptor *)w);
        func_02041B6C(func_02045730((struct Descriptor *)w));
        func_02040588(6, 0);
        func_0204B3DC((struct Obj *)((struct Obj00045 *)p)->fD38, 0);
        func_021F4EC0(p, 0, 0x14);
        ((struct Obj00045 *)p)->f28 = 7;
    } else if (state == 2) {
        func_021F4CE4((char *)p);
        func_0201F7A8((void *)(*(u32 *)&((struct Obj00045 *)p)->fDD0), 2);
        w = *(u32 *)&((struct Obj00045 *)p)->fDD0;
        func_020456F8((struct Descriptor *)w);
        func_02041B6C(func_02045730((struct Descriptor *)w));
        func_0204B92C((struct Obj *)((struct Obj00045 *)p)->fBF4, 1);
        ((struct Obj00045 *)p)->f28 = 5;
        func_0204B3DC((struct Obj *)((struct Obj00045 *)p)->fBF4, 1);
    }
    return 2;
}

int func_022008B0(u8 *p)
{
    if (func_0204B98C((struct Actor *)(((struct Obj01749 *)p)->fBF4)) == 0) {
        func_0204B878((struct Obj *)(((struct Obj01749 *)p)->fBF4), 0);
        if (func_020355C4() == 1)
            func_0204B3DC((struct Obj *)((struct Obj01749 *)p)->fBF4, 0);
        else
            func_0204B3DC((struct Obj *)((struct Obj01749 *)p)->fBF4, 1);
        func_0220053C(p, ((struct Obj01749 *)p)->fC0);
    }
    return 2;
}
