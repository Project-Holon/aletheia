/*
 * file:     worldtrade_adapter_p06.c
 * unit:     yes
 * function: func_021FC638, func_021FC668, func_021FC6B8, func_021FC70C, func_021FC7C4, func_021FC7E0, func_021FC810, func_021FC8A8
 * address:  0x021FC638
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
 *   func_021F4BF8  0x021F4BF8  thumb  ov135
 *   func_021F5060  0x021F5060  thumb  ov135
 *   func_021F5034  0x021F5034  thumb  ov135
 *   func_021F4D14 0x021F4D14 thumb ov135
 *   func_021F4CE4 0x021F4CE4 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021FCBF0 0x021FCBF0 thumb ov135
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_021F4D50 0x021F4D50 thumb ov135
 *   func_021F4E30 0x021F4E30 thumb ov135
 *   func_021F4E64 0x021F4E64 thumb ov135
 *   func_0201F868 0x0201F868 thumb
 *   func_0200ADB4 0x0200ADB4 thumb
 *   func_021F6DE8 0x021F6DE8 thumb ov135
 *   func_0201AA18 0x0201AA18 thumb
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_02202840  0x02202840  thumb  ov135
 *   func_0201EE84  0x0201EE84  thumb
 *   sub_02045EC0   0x02045EC0  arm
 *   func_0201F250  0x0201F250  thumb
 *   sub_02045770   0x02045770  arm
 *   sub_02043B5C   0x02043B5C  arm
 *   sub_02045334   0x02045334  arm
 *   sub_02045374   0x02045374  arm
 *   unit_02045730  0x02045730  arm
 *   sub_020409B4   0x020409B4  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   sub_02045808   0x02045808  arm
 *   func_02202858  0x02202858  thumb  ov135
 */
#include "../../matched/include/Obj02489.h"
#include "../../matched/include/Obj08186.h"
#include "../../matched/include/Obj00448.h"
#include "../../matched/include/Obj00045.h"
#include "../../matched/include/Obj23409.h"
#include "../../matched/include/Obj12210.h"
#include "../../matched/include/Obj07246.h"
#include "../../matched/include/Obj00018.h"

struct Slot;
struct WordSet;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct U16Vec;
struct Descriptor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

extern void func_021F4BF8(u8 *p, int b, int unused, int a, int c, u8 flag);
extern void func_021F5060(void);
extern void func_021F5034(u32 v);
extern int func_021F4D14(char *p);
extern void func_021F4CE4(char *p);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_021FCBF0(char *p);
extern void func_0201F7A8(void *p, unsigned kind);
extern void *func_0201F81C(u32 n, u32 heap);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void func_021F4D50(u8 *p, u16 a, int count, int b);
extern unsigned int func_021F4E30(unsigned char *p);
extern void func_021F4E64(unsigned char *p);
extern unsigned int func_0201F868(void *p);
extern void *func_0200ADB4(void *);
extern int func_021F6DE8(unsigned int handle);
extern u32 func_0201AA18(void *p);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern u32 func_02202840(u8 *p);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern void *sub_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *sub_02045770(struct Descriptor *p);
extern void sub_02043B5C(struct CharBuf *buf, u8 value);
extern void sub_02045334(struct Descriptor *a);
extern void sub_02045374(struct Cfg *cfg);
extern u8 unit_02045730(u32 a);
extern void sub_020409B4(u32 index);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void sub_02045808(struct U16Vec *vec);
extern u32 func_02202858(void *p, u8 b, void *s, u32 x, u32 y, void *out);
int func_021FC638(u8 *p);
int func_021FC668(char *p);
int func_021FC6B8(char *p);
int func_021FC70C(char *p);
int func_021FC7C4(u8 *p);
int func_021FC7E0(u8 *p);
void func_021FC810(u8 *p, u32 b, u32 c, u32 d, u32 e, void *sel);
u16 func_021FC8A8(int mode);


/*
 * Build, kick the two fixed helpers and latch state 6.
 */
int func_021FC638(u8 *p)
{
    func_021F4BF8(p, 0x14, 0x16a, 8, 2, 1);
    func_021F5060();
    func_021F5034(1);
    ((struct Obj02489 *)p)->f28 = 6;
    return 2;
}

/*
 * spelling: if/else keeps the first arm before the second compare; switch moved both compares ahead.
 */
int func_021FC668(char *p)
{
    unsigned r;
    r = func_021F4D14(p);
    if (r == 1) {
        func_021F4CE4(p);
        ((struct Obj08186 *)p)->f28 = 2;
        ((struct Obj08186 *)p)->fEB4 = 1;
        func_021F4EC0((u8 *)p, 7, 8);
        func_021FCBF0(p);
    } else if (r == 2) {
        func_021F4CE4(p);
        ((struct Obj08186 *)p)->f28 = 0;
        func_0201F7A8(((struct Obj08186 *)p)->fD40, 0);
        func_021FCBF0(p);
    }
    return 2;
}

int func_021FC6B8(char *p)
{
    ((struct Obj00448 *)p)->fDE8 = func_0201F81C(2, 0x48);
    func_0201F878(((struct Obj00448 *)p)->fDE8, (u32)(((struct Obj00448 *)p)->fB6C), 0x3d, 1, 0x48);
    func_0201F878(((struct Obj00448 *)p)->fDE8, (u32)(((struct Obj00448 *)p)->fB6C), 0x3e, 2, 0x48);
    func_021F4D50((u8 *)p, 2, 2, 0x14);
    func_021F5034(1);
    *(int *)&((struct Obj00448 *)p)->f28 = 8;
    return 2;
}

int func_021FC70C(char *p)
{
    int r;
    void *q;
    r = func_021F4E30((unsigned char *)p);
    if (r == 1) {
        func_021F4E64((unsigned char *)p);
        func_0201F868(((struct Obj00045 *)p)->fDE8);
        q = func_0200ADB4(**(void ** *)&((struct Obj00045 *)p)->f0);
        if (func_021F6DE8((unsigned int)q) && func_0201AA18(((struct Obj23409 *)(*(char * *)&((struct Obj00045 *)p)->f0))->f8) == 6) {
            func_021FC810((u8 *)p, 0x2a, 1, 0, 0xf0f, q);
            func_021F4E98((u8 *)p, 3, 1);
            return 2;
        }
        func_021FC810((u8 *)p, 6, 1, 0, 0xf0f, q);
        func_021F4E98((u8 *)p, 3, 5);
        func_021FCBF0(p);
    } else if (r == 2 || r == -2) {
        func_021F4E64((unsigned char *)p);
        func_0201F868(((struct Obj00045 *)p)->fDE8);
        *(int *)&((struct Obj00045 *)p)->f28 = 2;
        func_021F4EC0((u8 *)p, 1, 0);
        func_021FCBF0(p);
    }
    return 2;
}


int func_021FC7C4(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        ((struct Obj12210 *)p)->f28 = ((struct Obj12210 *)p)->f2C;
    }
    return 2;
}


/*
 * When the build query answers 0, bump the countdown at +0xdfc and roll state when it passes 0x2d.
 */
int func_021FC7E0(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        if (++((struct Obj07246 *)p)->fDFC > 0x2d) {
            ((struct Obj07246 *)p)->fDFC = 0;
            ((struct Obj07246 *)p)->f28 = ((struct Obj07246 *)p)->f2C;
        }
    }
    return 2;
}


/*
 * The two-parameter member of the 021F7538 family: an extra 0201EE84 call
 * keyed by the sixth argument, the same 0xb6c/0xb88 fields and the same
 * p+0xd40 window group in the other order.
 */
void func_021FC810(u8 *p, u32 b, u32 c, u32 d, u32 e, void *sel)
{
    u32 v;
    u32 h;

    func_0201EE84(((struct Obj00018 *)p)->fB68, 0, (void *)sel);
    v = (u32)sub_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00018 *)p)->fB6C), b);
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00018 *)p)->fB68), (void *)(((struct Obj00018 *)p)->fB88), (void *)v);
    sub_02043B5C((struct CharBuf *)((u32)sub_02045770((struct Descriptor *)((struct Obj00018 *)p)->fD40)), 0xf);
    func_0201F73C((void *)(((struct Obj00018 *)p)->fD40), 0, 1, 0xe);
    h = ((struct Obj00018 *)p)->fD40;
    sub_02045334((struct Descriptor *)h);
    sub_02045374((struct Cfg *)h);
    sub_020409B4(unit_02045730(h));
    func_02202858((void *)(((struct Obj00018 *)p)->fD40), 0, (void *)(((struct Obj00018 *)p)->fB88), 0, 0, p + 0xfa0);
    sub_02045808((struct U16Vec *)v);
}


/*
 * Mode table: 0 -> 0, 1 -> 0x14c0, 2 -> 0xc80, anything else 0.
 */
u16 func_021FC8A8(int mode)
{
    switch (mode) {
    case 0:
        return 0;
    case 1:
        return 0x53 << 6;
    case 2:
        return 0x32 << 6;
    default:
        return 0;
    }
}
