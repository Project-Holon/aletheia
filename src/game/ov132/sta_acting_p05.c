/*
 * file:     sta_acting_p05.c
 * unit:     yes
 * function: func_021F92CC, func_021F9374, func_021F93D8, func_021F94B0, func_021F94F8, func_021F95CC, func_021F95E8, func_021F95F0, func_021F9664, func_021F9680, func_021F9690, func_021F969C, func_021F96B0, func_021F96C4, func_021F96D0
 * address:  0x021F92CC
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045C44 0x02045C44 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0203101C 0x0203101C arm
 *   func_0201C440 0x0201C440 thumb
 *   func_020310C4 0x020310C4 arm
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_021FA558 0x021FA558 thumb ov132
 *   func_021FA56C 0x021FA56C thumb ov132
 *   func_02006448  0x02006448  thumb
 *   func_020064F4  0x020064F4  thumb
 *   func_02006504 0x02006504 thumb
 *   func_020064B8  0x020064B8  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_02005D28 0x02005D28 thumb
 *   func_020061E4 0x020061E4 thumb
 */
#include "../../matched/include/Obj01257.h"
#include "../../matched/include/Obj23182.h"
#include "../../matched/include/Obj23183.h"
#include "../../matched/include/Obj02849.h"
#include "../../matched/include/Obj00832.h"
#include "../../matched/include/Obj03817.h"
#include "../../matched/include/Obj10532.h"
#include "../../matched/include/Obj23184.h"
#include "../../matched/include/Obj10533.h"
#include "../../matched/include/Obj23185.h"
#include "../../matched/include/Obj23186.h"
#include "../../matched/include/Obj23187.h"
#include "../../matched/include/Obj23188.h"
#include "../../matched/include/Obj23189.h"
#include "../../matched/include/Obj23190.h"

struct Descriptor;
struct Cfg;
struct GfFont;
struct MsgBank;
struct Tcbl;
struct PrintSys;
struct Rec3;
struct CharBuf;
struct U16Vec;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { ZERO } Zero;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045C44(const void *file, u32 heapId);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *);
extern void func_020310C4(struct Tcbl *p);
extern unsigned func_0201CE30(void *);
extern void func_0201CE48(struct Rec3 *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_0201CCE4(void *, u32, u32, void *, void *, u32, void *, u32, u16, u32);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_021FA558(char *, int, int);
extern void func_021FA56C(char *, u8);
extern int func_02006448(u32 a0, u32 a1, u32 a2);
extern void func_020064F4(u32 a);
extern void func_02006504(void);
extern int func_020064B8(u32, u32, u32, u32);
extern void func_02005D90(int, int);
extern void func_02005D28(void);
extern void func_020061E4(u32 a);
void func_021F92CC(u8 *p);
void func_021F9374(u8 *p);
void func_021F93D8(u8 *p, u16 index, u32 speed);
void func_021F94B0(u8 *p);
void func_021F94F8(char *p);
void func_021F95CC(char *p, u8 v, int c);
void func_021F95E8(char *p);
void func_021F95F0(u8 *p);
void func_021F9664(char *p, int a);
void func_021F9680(char *p, int a);
void func_021F9690(char *p);
int func_021F969C(char *p, u32 a, u32 b, u32 d);
void func_021F96B0(char *p, int a);
void func_021F96C4(char *p);
void func_021F96D0(char *p);

void func_021F92CC(u8 *p)
{
    int zero;
    ((struct Obj01257 *)p)->fD0=func_020450F0(1,4,20,24,4,15,1);
    func_02045334((struct Descriptor *)((struct Obj01257 *)p)->fD0);
    func_02045374((struct Cfg *)(((struct Obj01257 *)p)->fD0));
    func_020409B4(1);
    zero=0;
    ((struct Obj01257 *)p)->fD4=(u32)func_0201D7EC(23,0,0,0,((struct Obj01257 *)p)->f0);
    ((struct Obj01257 *)p)->fDC=(u32)func_02045C44(((struct Obj23183 *)(*(u8 * *)&((struct Obj23182 *)(*(u8 * *)&((struct Obj01257 *)p)->f30))->f18))->f8,((struct Obj01257 *)p)->f0);
    func_02049B40(23,5,0,480,32,((struct Obj01257 *)p)->f0);
    ((struct Obj01257 *)p)->fCC=(u32)func_0203101C(((struct Obj01257 *)p)->f0,((struct Obj01257 *)p)->f0,3,256);
    ((struct Obj01257 *)p)->fD8=zero;
    ((struct Obj01257 *)p)->fE0=zero;
    ((struct Obj01257 *)p)->fE4=zero;
    ((struct Obj01257 *)p)->fE8=func_0201C440((void *)(u32)((struct Obj01257 *)p)->f0);
}

void func_021F9374(u8 *p)
{
    func_020310C4(((struct Obj02849 *)p)->fCC);
    if (((struct Obj02849 *)p)->fD8 && func_0201CE30(((struct Obj02849 *)p)->fD8) == 2) {
        func_0201CE48(((struct Obj02849 *)p)->fD8);
        ((struct Obj02849 *)p)->fD8 = 0;
    }
    if (((struct Obj02849 *)p)->fE4 == 1) {
        func_0201C4E4(((struct Obj02849 *)p)->fE8);
        if (func_0201C6B4(((struct Obj02849 *)p)->fE8) == 1) {
            func_02045334(((struct Obj02849 *)p)->fD0);
            ((struct Obj02849 *)p)->fE4 = 0;
        }
    }
}

/*
 * abi: 0201CCE4 forwards the pointer result of matched 0201CD10; the caller stores it at d8.
 */
void func_021F93D8(u8 *p, u16 index, u32 speed)
{
    Zero zero;
    if (((struct Obj00832 *)p)->fD8) {
        func_0201CE48(((struct Obj00832 *)p)->fD8);
        ((struct Obj00832 *)p)->fD8 = 0;
    }
    if (((struct Obj00832 *)p)->fE0) {
        func_02045808(((struct Obj00832 *)p)->fE0);
        ((struct Obj00832 *)p)->fE0 = 0;
    }
    func_02043B5C(func_02045770(((struct Obj00832 *)p)->fD0), 0);
    zero = ZERO;
    ((struct Obj00832 *)p)->fE0 = func_02045EC0(((struct Obj00832 *)p)->fDC, index);
    if (speed != 255) {
        ((struct Obj00832 *)p)->fD8 = func_0201CCE4(((struct Obj00832 *)p)->fD0, zero, zero,
            ((struct Obj00832 *)p)->fE0, ((struct Obj00832 *)p)->fD4, speed,
            ((struct Obj00832 *)p)->fCC, 2, ((struct Obj00832 *)p)->f0, zero);
    } else {
        func_0201C6FC(((struct Obj00832 *)p)->fE8, (u32)func_02045770(((struct Obj00832 *)p)->fD0),
            zero, zero, ((struct Obj00832 *)p)->fE0, *(u32 *)&((struct Obj00832 *)p)->fD4);
        ((struct Obj00832 *)p)->fE4 = 1;
        func_02045808(((struct Obj00832 *)p)->fE0);
        ((struct Obj00832 *)p)->fE0 = (void *)zero;
    }
}

void func_021F94B0(u8 *p)
{
    if (((struct Obj03817 *)p)->fD8) {
        func_0201CE48(((struct Obj03817 *)p)->fD8);
        ((struct Obj03817 *)p)->fD8 = 0;
    }
    if (((struct Obj03817 *)p)->fE0) {
        func_02045808(((struct Obj03817 *)p)->fE0);
        ((struct Obj03817 *)p)->fE0 = 0;
    }
    func_02043B5C(func_02045770(((struct Obj03817 *)p)->fD0), 0);
    func_02045334(((struct Obj03817 *)p)->fD0);
}

void func_021F94F8(char *p)
{
    u8 count, i, j, selected, index;
    if (*(int *)(p + 0xEC) != 1) return;
    count = 0;
    i = 0;
    for (; i < 4; i++) func_021FA558(*(char **)(p + 0xB8), i, 0);
    func_021FA56C(*(char **)(p + 0xB8), 255);
    *(u8 *)(p + 0xF1) = 4;
    *(u8 *)(p + 0xF2) = 4;
    for (j = count; j < 4; j = (u8)(j + 1)) {
        if (*(int *)(p + 0x94 + j * 4) != 0) {
            selected = j;
            count = (u8)(count + 1);
        }
    }
    index = *(u8 *)(p + 0x11C);
    if (index < 4) {
        *(u8 *)(p + 0xF1) = index;
        func_021FA558(*(char **)(p + 0xB8), index, 1);
    } else if ((index = *(u8 *)(p + 0xF0)) < 4) {
        *(u8 *)(p + 0xF1) = index;
        func_021FA558(*(char **)(p + 0xB8), index, 1);
    } else if (count == 1) {
        *(u8 *)(p + 0xF2) = selected;
        func_021FA56C(*(char **)(p + 0xB8), selected);
    } else {
        for (j = 0; j < 4; j = (u8)(j + 1)) {
            if (*(u8 *)(p + 0xF3 + j) == 0)
                func_021FA558(*(char **)(p + 0xB8), j, 1);
        }
    }
    *(int *)(p + 0xEC) = 0;
}


/*
 * The original stores p+0xEC = 1 unconditionally after the if/else, so the
 * store is a shared tail reached by both arms (b .end out of the `c == 1`
 * arm); writing it inside the else made the compiler emit two epilogues.
 * See docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md.
 */
void func_021F95CC(char *p, u8 v, int c)
{
    if (c == 1) {
        ((struct Obj10532 *)p)->fF0 = v;
    } else {
        ((struct Obj10532 *)p)->fF0 = 4;
    }
    ((struct Obj10532 *)p)->fEC = 1;
}

void func_021F95E8(char *p){((struct Obj23184 *)p)->fEC=1;}

void func_021F95F0(u8 *p)
{
    u8 i, j;
    u16 score;
    for (i = 0; i < 4; i++) p[0xf3 + i] = 0;
    for (i = 0; i < 4; i++) {
        score = (u16)(*(u16 *)((*(u8 ***)(p + 0x30))[i + 1] + 0x4a) + p[0xf7 + i]);
        for (j = 0; j < 4; j++) {
            if (i != j) {
                if ((u16)(*(u16 *)((*(u8 ***)(p + 0x30))[j + 1] + 0x4a) + p[0xf7 + j]) > score) p[0xf3 + i]++;
            }
        }
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021F9664(char *p, int a)
{
    ((struct Obj10533 *)p)->f24 = 1;
    func_02006448(((struct Obj10533 *)p)->f1DC, ((struct Obj10533 *)p)->f1E0, a);
}


void func_021F9680(char *p, int a)
{
    ((struct Obj23185 *)p)->f28 = 1;
    func_020064F4(a);
}

void func_021F9690(char *p){((struct Obj23186 *)p)->f28=0;func_02006504();}


/*
 * lever: The matched 020064B8 body reads four arguments; incoming r3 is
 * forwarded unchanged, preventing the erroneous three-argument tail call.
 *
 * Addresses are Black-image addresses.
 */
int func_021F969C(char *p, u32 a, u32 b, u32 d)
{
    return func_020064B8(a, b, ((struct Obj23187 *)p)->f1E4, d);
}


void func_021F96B0(char *p, int a)
{
    ((struct Obj23188 *)p)->f2C = 1;
    func_02005D90(a, 0xffff);
}

void func_021F96C4(char *p){((struct Obj23189 *)p)->f2C=0;func_02005D28();}

void func_021F96D0(char *p)
{
    u8 i;
    u8 min = 255;
    char *a = *(char * *)&((struct Obj23190 *)p)->f30;
    for (i = 0; i < 4; i++) {
        u16 v = *(u16 *)(*(char **)(a + i * 4 + 4) + 0x4a) + *(u8 *)(p + i + 0xf7);
        if (min > v) min = v;
    }
    if (min >= 70) func_020061E4(1578);
    else if (min >= 30) func_020061E4(1579);
    else if (min >= 1) func_020061E4(1580);
}
