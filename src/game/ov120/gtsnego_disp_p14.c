/*
 * file:     gtsnego_disp_p14.c
 * unit:     yes
 * function: func_021D5980, func_021D59E0, func_021D5A84, func_021D5AD4, func_021D5BEC
 * address:  0x021D5980
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D596C 0x021D596C thumb ov120
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_021D7D3C 0x021D7D3C thumb ov120
 *   func_02041B6C 0x02041B6C arm
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4EC0 0x021D4EC0 thumb ov120
 *   func_021D57B0 0x021D57B0 thumb ov120
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021D8418 0x021D8418 thumb ov120
 *   func_021D44AC 0x021D44AC thumb ov120
 *   func_021D79F4 0x021D79F4 thumb ov120
 *   func_020355C4 0x020355C4 arm
 *   func_021D6988 0x021D6988 thumb ov120
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021D63F4 0x021D63F4 thumb ov120
 *   func_021D7AF4 0x021D7AF4 thumb ov120
 *   func_021D7B60 0x021D7B60 thumb ov120
 *   func_021B6498 0x021B6498 thumb ov067
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_021D593C 0x021D593C thumb ov120
 *   func_021D7C10 0x021D7C10 thumb ov120
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_021D846C 0x021D846C thumb ov120
 *   func_02040588 0x02040588 arm
 *   func_021D761C 0x021D761C thumb ov120
 *   func_021D7B38 0x021D7B38 thumb ov120
 *   func_021D883C 0x021D883C thumb ov120
 *   func_021D588C 0x021D588C thumb ov120
 */
#include "../../matched/include/Obj05346.h"
#include "../../matched/include/Obj01928.h"
#include "../../matched/include/Obj22833.h"
#include "../../matched/include/Obj05347.h"
#include "../../matched/include/Obj01400.h"
#include "../../matched/include/Obj01056.h"
#include "../../matched/include/Obj22834.h"
#include "../../matched/include/Obj22835.h"

struct TaskMenu;
struct S;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

extern int func_021D596C(u8 *, int);
extern void func_021D69F4(u8 *p, void *q, u32 n);
extern void func_021D7D3C(char *);
extern void func_02041B6C(u32 bit);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D4EC0(u8 *p);
extern void func_021D57B0(u8 *p);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *);
extern void func_021D8418(int);
extern void func_021D44AC(int *p);
extern void func_021D79F4(u8 *p, u16 n);
extern u8 func_020355C4(void);
extern u32 func_021D6988(u8 *p);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern void func_021D63F4(u8 *p, int flag, int mode);
extern int func_021D7AF4(char *p);
extern void *func_021D7B60(char *p, int n);
extern int func_021B6498(u8 *);
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern int func_021D593C(u8 *, int);
extern void func_020061E4(u32 a);
extern int func_021D7C10(char *p);
extern void func_021B63D0(struct S *p);
extern int func_021B6448(u8 *);
extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
extern void func_021D846C(u8 *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021D761C(u8 *p);
extern void func_021D7B38(char *p);
extern void func_021D883C(char *);
extern void func_021D588C(u8 *p);
void func_021D5980(u8 *p);
void func_021D59E0(u8 *p);
void func_021D5A84(u8 *p);
void func_021D5AD4(u8 *p);
void func_021D5BEC(u8 *p);

void func_021D5980(u8 *p)
{
    int state = func_021D596C(p, ((struct Obj05346 *)p)->f15C);
    if (state == 0) {
        func_021D69F4(((struct Obj05346 *)p)->f3C, ((struct Obj05346 *)p)->f34, 9);
        func_021D7D3C(*(char * *)&((struct Obj05346 *)p)->f40);
        func_02041B6C(6);
        func_021D4244((int *)p, (int)func_021D4EC0, 0x8a3);
        return;
    }
    if (state == 1) {
        func_021D69F4(((struct Obj05346 *)p)->f3C, ((struct Obj05346 *)p)->f34, 9);
        func_021D4244((int *)p, (int)func_021D57B0, 0x8a7);
    }
}

void func_021D59E0(u8 *p)
{
    int state;
    if (func_020279E8(((struct Obj01928 *)p)->f38)) {
        state = func_02027A04(((struct Obj01928 *)p)->f38);
        func_021D8418(*(int *)&((struct Obj01928 *)p)->f38);
        *(int *)&((struct Obj01928 *)p)->f38 = 0;
        switch (state) {
        case 0:
            ((struct Obj22833 *)(*(u8 * *)&((struct Obj01928 *)p)->f48))->f1B0 = 1;
            ((struct Obj01928 *)p)->f14 = 0;
            func_021D4244((int *)p, (int)func_021D44AC, 0x8b5);
            return;
        case 1:
            if (((struct Obj01928 *)p)->f184 == 0)
                func_021D79F4(((struct Obj01928 *)p)->f40, 0x20);
            else
                func_021D79F4(((struct Obj01928 *)p)->f40, 0x2b);
            if (func_020355C4() == 0)
                func_021D69F4(((struct Obj01928 *)p)->f3C, 0, ((struct Obj01928 *)p)->f15C);
            func_021B6558((unsigned char *)func_021D6988(((struct Obj01928 *)p)->f3C), 1, 1);
            func_021D63F4(((struct Obj01928 *)p)->f3C, 0, 0);
            func_021D4244((int *)p, (int)func_021D5AD4, 0x8c3);
            break;
        }
    }
}

void func_021D5A84(u8 *p)
{
    if (func_021D7AF4(((struct Obj05347 *)p)->f40)) {
        func_021B6558((unsigned char *)func_021D6988(((struct Obj05347 *)p)->f3C), 1, 0);
        ((struct Obj05347 *)p)->f38 = func_021D7B60(((struct Obj05347 *)p)->f40, 1);
        func_021D63F4(((struct Obj05347 *)p)->f3C, 1, 0);
        func_021D69F4(((struct Obj05347 *)p)->f3C, 0, 9);
        func_021D4244((int *)p, (int)func_021D59E0, 0x8d4);
    }
}

void func_021D5AD4(u8 *p)
{
    int changed = 0;
    u8 *q = (u8 *)func_021D6988(((struct Obj01400 *)p)->f3C);
    if (func_021D7AF4(((struct Obj01400 *)p)->f40)) {
        if (func_021B6498(q) == 0) {
            if (func_020362DC() != 0 && func_020355C4() == 1) {
                func_021D69F4(((struct Obj01400 *)p)->f3C, 0, ((struct Obj01400 *)p)->f15C);
                func_020355D8(changed);
                return;
            }
            if (func_020362DC() == 1) {
                if (((struct Obj01400 *)p)->f184 == 0) {
                    func_021D593C(p, ((struct Obj01400 *)p)->f15C);
                    func_021D4244((int *)p, (int)func_021D5980, 0x8f4);
                    return;
                }
                func_020061E4(0x551);
            }
            if (func_020362DC() == 0x40) {
                changed = 1;
                func_020061E4(0x548);
                ((struct Obj01400 *)p)->f15C = 0;
            }
            if (func_020362DC() == 0x80) {
                changed = 1;
                func_020061E4(0x548);
                ((struct Obj01400 *)p)->f15C = 1;
            }
            if (changed)
                func_021D69F4(((struct Obj01400 *)p)->f3C, 0, ((struct Obj01400 *)p)->f15C);
            func_021D7C10((char *)(*(int *)&((struct Obj01400 *)p)->f40));
        }
        func_021B63D0((struct S *)func_021D6988(((struct Obj01400 *)p)->f3C));
        if (func_021B6448((u8 *)func_021D6988(((struct Obj01400 *)p)->f3C)) == 1) {
            ((struct Obj01400 *)p)->f14 = 1;
            func_021D79F4(((struct Obj01400 *)p)->f40, 0x2a);
            if (func_020355C4() == 1)
                func_021D69F4(((struct Obj01400 *)p)->f3C, 0, 9);
            func_021D4244((int *)p, (int)func_021D5A84, 0x916);
        }
    }
}

void func_021D5BEC(u8 *p)
{
    if (((struct Obj22834 *)(*(u8 * *)&((struct Obj01056 *)p)->f48))->f1B0 != 1) {
        int zero = 0;
        func_0203D7B0(0);
        func_0203D7BC(0);
        func_021D846C(*(u8 * *)&((struct Obj01056 *)p)->f40);
        func_021D63F4(((struct Obj01056 *)p)->f3C, 0, 0);
        func_02040588(4, 0);
        func_021D761C(((struct Obj01056 *)p)->f3C);
        func_021D7B38((char *)(*(int *)&((struct Obj01056 *)p)->f40));
        func_021D883C(*(char * *)&((struct Obj01056 *)p)->f40);
        func_021D69F4(((struct Obj01056 *)p)->f3C, 0, 9);
        ((struct Obj01056 *)p)->f1B0 = 1;
        ((struct Obj01056 *)p)->f1B4 = zero;
        ((struct Obj22835 *)(*(u8 * *)&((struct Obj01056 *)p)->f48))->f1B0 = 1;
        func_021D4244((int *)p, (int)func_021D588C, 0x937);
    }
}
