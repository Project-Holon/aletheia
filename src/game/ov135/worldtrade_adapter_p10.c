/*
 * file:     worldtrade_adapter_p10.c
 * unit:     yes
 * function: func_021FD3CC, func_021FD4D4, func_021FD528, func_021FD550
 * address:  0x021FD3CC
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
 *   func_020362DC 0x020362DC arm
 *   func_02035C08 0x02035C08 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0202208C 0x0202208C thumb
 *   func_021FD6F4 0x021FD6F4 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_021FD368 0x021FD368 thumb ov135
 *   func_021FFB00 0x021FFB00 thumb ov135
 *   tbl_02203608 0x02203608 data a1
 *   tbl_022035FC 0x022035FC data a1
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021F4BF8  0x021F4BF8  thumb  ov135
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021FD760 0x021FD760 thumb ov135
 *   func_021FD790 0x021FD790 thumb ov135
 *   func_021FD5F0 0x021FD5F0 thumb ov135
 */
#include "../../matched/include/Obj01063.h"
#include "../../matched/include/Obj08187.h"
#include "../../matched/include/Obj02489.h"
#include "../../matched/include/Obj00045.h"

struct Obj;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {u8 left,right;} Pair;

typedef unsigned short u16;

typedef signed int s32;

extern u32 func_020362DC(void);
extern int func_02035C08(const void *);
extern void func_020061E4(u32);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_021FD6F4(u8 *p, u32 k, u32 a2, u32 a3, u32 a4);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern void func_021FD368(u8 *,int);
extern int func_021FFB00(int);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_021F4BF8(u8 *p, int b, int unused, int a, int c, u8 flag);
extern int func_021F4D14(char *p);
extern void func_021F4CE4(char *p);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_021FD760(void *, void *, u32, void *, u16);
extern void func_021FD790(void *, void *, u32, void *);
extern void func_021FD5F0(void *);
extern void func_0201F7A8(void *, u32);
int func_021FD3CC(u8 *p);
int func_021FD4D4(unsigned char *p);
int func_021FD528(u8 *p);
int func_021FD550(unsigned char *p);
extern const Pair tbl_02203608[];
extern const u8 tbl_022035FC[];

/*
 * prototype: 021FD6F4 retains r2=1,r3=0,sp=0xF0F visibly loaded by this caller.
 */
int func_021FD3CC(u8 *p)
{
    int next, r;
    if(func_020362DC()&1) {
        func_021FD6F4(p,16,1,0,0xF0F);
        func_021F4E98(p,3,4);
        func_020061E4(0x54C);
    } else if(func_020362DC()&2) {
        func_0202208C(0,0,0,0,16,1,0x48);
        ((struct Obj01063 *)p)->f28=8;
        func_020061E4(0x551);
    } else if(func_020362DC()&32) {
        next=tbl_02203608[(u32)*(int *)(p+0xD4)].left;
        if(((struct Obj01063 *)p)->fD4!=next && ((struct Obj01063 *)p)->fD0>=next+1)
            func_021FD368(p,next);
    } else if(func_020362DC()&16) {
        next=tbl_02203608[(u32)*(int *)(p+0xD4)].right;
        if(((struct Obj01063 *)p)->fD4!=next && ((struct Obj01063 *)p)->fD0>=next+1)
            func_021FD368(p,next);
    } else {
        r=func_021FFB00(((struct Obj01063 *)p)->fD0);
        if(r!=-1) func_021FD368(p,r);
        r=func_02035C08(tbl_022035FC);
        if(r==0) {
            func_021FD6F4(p,16,1,0,0xF0F);
            func_021F4E98(p,3,4);
            func_020061E4(0x54C);
        } else if(r==1) {
            func_0202208C(0,0,0,0,16,1,0x48);
            ((struct Obj01063 *)p)->f28=8;
            func_020061E4(0x551);
        }
    }
    return 2;
}

int func_021FD4D4(unsigned char *p)
{
    func_0204B3DC((struct Obj *)((struct Obj08187 *)p)->fD34, 0);
    if (((struct Obj08187 *)p)->f20 != 15) {
        if (((struct Obj08187 *)p)->f20 == 6)
            func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
        else
            func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    ((struct Obj08187 *)p)->f28 = 0;
    return 3;
}


/*
 * Build with the fixed 0x12/0x12e/3/4/1 argument pair and latch state 5.
 */
int func_021FD528(u8 *p)
{
    func_021F4BF8(p, 0x12, 0x12e, 3, 4, 1);
    ((struct Obj02489 *)p)->f28 = 5;
    return 2;
}

int func_021FD550(unsigned char *p)
{
    unsigned r = func_021F4D14((char *)p);
    if (r == 1) {
        func_021F4CE4((char *)p);
        *(int *)&((struct Obj00045 *)p)->f28 = 2;
        func_021F4EC0(p, 5, 6);
        func_021FD760(((struct Obj00045 *)p)->fB6C, p + 0xdc8, 0x53, p + 0xfa0, 0x440);
        func_021FD760(((struct Obj00045 *)p)->fB6C, p + 0xdb4, 0x57, p + 0xfa0, 0x3c40);
        func_021FD5F0(p);
    } else if (r == 2) {
        func_021F4CE4((char *)p);
        func_0201F7A8(((struct Obj00045 *)p)->fD40, 0);
        *(int *)&((struct Obj00045 *)p)->f28 = 1;
        func_021FD790(((struct Obj00045 *)p)->fB6C, p + 0xd50, 0x5e, p + 0xfa0);
        func_021FD790(((struct Obj00045 *)p)->fB6C, p + 0xd54, 0x73, p + 0xfa0);
    }
    return 2;
}
