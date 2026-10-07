/*
 * file:     fldeff_splash_p10.c
 * unit:     yes
 * function: func_021C51A0, func_021C5224, func_021C5334, func_021C5348, func_021C536C, func_021C5380, func_021C5394
 * address:  0x021C51A0
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
 *   func_02040588  0x02040588  arm
 *   func_021C5424  0x021C5424  thumb  ov021
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_020403F4  0x020403F4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020061E4 0x020061E4 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_021C59BC 0x021C59BC thumb ov021
 *   func_02030EAC 0x02030EAC arm
 *   func_021C553C 0x021C553C thumb ov021
 *   func_021C5768 0x021C5768 thumb ov021
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02040618 0x02040618 arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_021C56F8  0x021C56F8  thumb  ov021
 */
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj01216.h"
#include "../../matched/include/Obj18304.h"
#include "../../matched/include/Obj07562.h"
#include "../../matched/include/Obj12940.h"
#include "../../matched/include/Obj12941.h"
#include "../../matched/include/Obj12942.h"

struct Bank;
struct Obj;
struct PrintSys;
struct Rec;
struct Node;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed short   s16;

typedef signed char    s8;

extern void func_02040588(unsigned char which, unsigned char enable);
extern int func_021C5424(u32 a, u32 b);
extern void func_0204B3B4(struct Obj *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern u32 func_020307B0(void *p);
extern void func_020061E4(u32 se);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void func_021C59BC(void *a, u8 *p);
extern void func_02030EAC(struct Node *n);
extern void func_021C553C(char *p);
extern int func_021C5768(char *p);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern int func_021C56F8(int *a);
void func_021C51A0(int *a);
void func_021C5224(char *p);
int func_021C5334(u32 a);
void func_021C5348(u8 *p);
void func_021C536C(u8 *p);
int func_021C5380(u8 *p);
u32 func_021C5394(u8 *p, u32 *out);


void func_021C51A0(int *a)
{
    int i = 0;

    *(volatile u16 *)0x04000050 = 0;
    func_02040588(1, 0);
    func_021C5424((int)a, a[0x7c / 4]);
    for (i = 0; i < 3; i++) {
        func_0204B3B4((struct Obj *)a[0x58 / 4 + i]);
    }
    func_0201C6EC((struct PrintSys *)a[0x6c / 4]);
    func_0201C4C0((struct PrintSys *)a[0x6c / 4]);
    func_0201D83C((void *)a[0x68 / 4]);
    func_02045C04((struct Rec *)a[0x64 / 4]);
    func_0204ADA4(((struct Obj00020 *)a)->f50);
    func_0204A8D4(((struct Obj00020 *)a)->f52);
    func_0204AFD8(((struct Obj00020 *)a)->f54);
    func_0204B1CC((struct Bank *)a[0x4c / 4]);
    func_02040DA8(1, 1, 0);
    func_020403F4(1);
    func_020307B0((void *)((int)a));
}


void func_021C5224(char *p)
{
    int r;
    int i;

    if (func_021C5334((u32)p) == 0) {
        return;
    }
    switch (((struct Obj01216 *)p)->f70) {
    case 0:
        break;
    case 1:
        func_020061E4(0x54C);
        ((struct Obj01216 *)p)->f72 = 0;
        ((struct Obj01216 *)p)->f80 = 0;
        ((struct Obj01216 *)p)->f84 = func_020056A0((void *)func_021C59BC, p, 0);
        ((struct Obj01216 *)p)->f70 = 2;
        break;
    case 2:
        if (((struct Obj01216 *)p)->f80 != 0) {
            func_02030EAC(((struct Obj01216 *)p)->f84);
            ((struct Obj01216 *)p)->f70 = 3;
        }
        break;
    case 3:
        func_021C553C(p);
        r = func_021C5768(p);
        switch (r) {
        case -1:
            ((struct Obj01216 *)p)->f74 = 0;
            break;
        case -2:
            ((struct Obj01216 *)p)->f74 = 2;
            break;
        default:
            ((struct Obj01216 *)p)->f74 = 1;
            ((struct Obj01216 *)p)->f78 = r;
            break;
        }
        break;
    case 4:
        for (i = 0; i < 3; i++) {
            func_0204B3DC((struct Obj *)*(u32 *)(p + 0x58 + i * 4), 0);
        }
        ((struct Obj01216 *)p)->f72 = 4;
        ((struct Obj01216 *)p)->f70 = 5;
        break;
    case 5:
        func_02040618(1, 3, ((struct Obj01216 *)p)->f72 * 0xC0 / 4 - 0xC0);
        if ((((struct Obj01216 *)p)->f72)-- == 0) {
            ((struct Obj01216 *)p)->f70 = 0;
        }
        break;
    }
}


int func_021C5334(u32 a)
{
func_0201C4E4((struct PrintSys *)(((struct Obj18304 *)((u8 *)(a)))->f6C));
return func_021C56F8((int *)a);
}


/*
 * Starts the fade sequence once (state 0 to 1).
 */
void func_021C5348(u8 *p)
{
    if (((struct Obj07562 *)p)->f70 == 0) {
        ((struct Obj07562 *)p)->f74 = 0;
        ((struct Obj07562 *)p)->f78 = 0x19;
        func_02040588(1, 1);
        ((struct Obj07562 *)p)->f70 = 1;
    }
}


/*
 * Advances the sequence from state 3 to 4 (EXACT*: pad).
 */
void func_021C536C(u8 *p)
{
    if (((struct Obj12940 *)p)->f70 == 3)
        ((struct Obj12940 *)p)->f70 = 4;
}


/*
 * Returns 1 in states 2 and 5.
 */
int func_021C5380(u8 *p)
{
    int r = 1;

    if (((struct Obj12941 *)p)->f70 != 2 && ((struct Obj12941 *)p)->f70 != 5)
        r = 0;
    return r;
}


/*
 * Returns the result word and optionally its argument.
 */
u32 func_021C5394(u8 *p, u32 *out)
{
    if (out != 0)
        *out = ((struct Obj12942 *)p)->f78;
    return ((struct Obj12942 *)p)->f74;
}
