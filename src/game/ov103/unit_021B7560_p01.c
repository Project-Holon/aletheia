/*
 * file:     unit_021B7560_p01.c
 * unit:     yes
 * function: func_021B77B0, func_021B787C
 * address:  0x021B77B0
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021B7FF0 0x021B7FF0 thumb ov103
 *   func_021B8100 0x021B8100 thumb ov103
 *   func_021B7918 0x021B7918 thumb ov103
 *   func_021B63D0 0x021B63D0 thumb ov101
 *   func_021B71E4 0x021B71E4 thumb ov101
 *   func_02082BCC 0x02082BCC arm
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_021B7B3C 0x021B7B3C thumb ov103
 *   func_021B7970 0x021B7970 thumb ov103
 *   func_021B7C68 0x021B7C68 thumb ov103
 *   func_021B8C14 0x021B8C14 thumb ov103
 *   func_020056A0 0x020056A0 thumb
 *   d_021B92D4 0x021B92D4 data ov103 a4
 *   func_021B795C 0x021B795C thumb ov103
 */
#include "../../matched/include/Obj10240.h"
#include "../../matched/include/Obj22175.h"
#include "../../matched/include/Obj22176.h"

struct Obj;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

extern void func_0204E720(u32, int, int, int);
extern int func_0204E804(void);
extern u32 func_021B7FF0(u8 *);
extern int func_021B8100(u8 *p, u8 *q);
extern void func_021B7918(u8 *);
extern int func_021B63D0(struct Obj *p);
extern void func_021B71E4(int);
extern void func_02082BCC(void *,int,int);
extern void func_0204335C(int);
extern void func_020433E0(void *);
extern int func_0204363C(int);
extern int func_0204361C(int);
extern void func_020434CC(int);
extern void func_021B7B3C(void *,void *,int);
extern void func_021B7970(void *,int);
extern void func_021B7C68(void *,int);
extern void func_021B8C14(void *,void *,int);
extern int func_020056A0(void *,void *,int);
extern void func_021B795C(void);
int func_021B77B0(void *unused, u32 *state, int unused2, char *p);
void func_021B787C(u8 *p,int x);
extern u8 d_021B92D4[];

/*
 * prototype: 7FF0 tail-forwards to u32-returning 0201C4E4; caller tests live r0.
 */
int func_021B77B0(void *unused, u32 *state, int unused2, char *p)
{
    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        func_0204E720(3, 16, 0, 0);
        *state = 2;
        break;
    case 2:
        if (func_0204E804() == 0) *state = 3;
        break;
    case 3:
        (*(void (**)(char *, char *))(p + 0x728))(p, p + 0x72c);
        if (((struct Obj10240 *)p)->f730 != 0) *state = 4;
        break;
    case 4:
        func_0204E720(3, 0, 16, 0);
        *state = 5;
        break;
    case 5:
        if (func_0204E804() == 0) *state = 6;
        break;
    case 6:
        return 1;
    }
    if (func_021B7FF0((u8 *)(p + 0x174)) != 0) {
        func_021B8100((u8 *)(p + 0x184), (u8 *)(p + 0x174));
        func_021B8100((u8 *)(p + 0x748), (u8 *)(p + 0x174));
    }
    func_021B7918((u8 *)p);
    func_021B63D0(((struct Obj22175 *)(*(u8 * *)&((struct Obj10240 *)p)->fB0C))->f4);
    func_021B71E4(((struct Obj10240 *)p)->fA38);
    return 0;
}

/*
 * note: Verified against the ov103 Thumb image.
 */
void func_021B787C(u8 *p,int x) {func_02082BCC(p,0,0x174); func_0204335C(0); func_020433E0(d_021B92D4); func_020434CC(func_0204361C(func_0204363C(0))); func_021B7B3C(p+0xcc,d_021B92D4,x); func_021B7970(p,x); func_021B7C68(p+4,x); func_021B8C14(p+0x160,p+4,x); ((struct Obj22176 *)p)->f170=func_020056A0(func_021B795C,p,0); }
