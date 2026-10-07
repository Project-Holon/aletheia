/*
 * file:     shinka_demo_p03.c
 * unit:     yes
 * function: func_02204DC4, func_02204DDC, func_02204DE0, func_02204EA0, func_02204EB0, func_02204ED0
 * address:  0x02204DC4
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02005E50 0x02005E50 thumb
 *   func_02005F38 0x02005F38 thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005D28 0x02005D28 thumb
 *   func_020063B4 0x020063B4 thumb
 *   func_02204F40 0x02204F40 thumb ov195
 *   func_02005E9C 0x02005E9C thumb
 *   func_02005DF8 0x02005DF8 thumb
 *   func_02005D90  0x02005D90  thumb
 */
#include "../../matched/include/Obj24942.h"
#include "../../matched/include/Obj24943.h"
#include "../../matched/include/Obj03902.h"
#include "../../matched/include/Obj24944.h"
#include "../../matched/include/Obj14523.h"
#include "../../matched/include/Obj24946.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void func_02005E30(u32);
extern int func_02005E50(void);
extern int func_02005F38(void);
extern void func_02005DE4(void *p);
extern int func_02005E64(void);
extern void func_02005D28(void);
extern u32 func_020063B4(u8 *a0, u32 *a1, u32 a2);
extern void func_02204F40(int a, int *p);
extern int func_02005E9C(void);
extern void func_02005DF8(u32 a);
extern void func_02005D90(int, int);
void func_02204DC4(u8 *p, u8 *q);
void func_02204DDC(int a0, int *a1);
void func_02204DE0(char *a, char *b);
int func_02204EA0(int a, int *p);
void func_02204EB0(char *a, char *b);
void func_02204ED0(int a, int *p);


/*
 * Addresses are Black-image addresses.
 */
void func_02204DC4(u8 *p, u8 *q)
{
    if (((struct Obj24942 *)p)->fC != 0) {
        func_02005E30(0x1e);
    }
    ((struct Obj24943 *)q)->f30 = 1;
}

void func_02204DDC(int a0, int *a1) {}


void func_02204DE0(char *a, char *b)
{
    switch (((struct Obj03902 *)b)->f30) {
    case 0:
        break;
    case 1:
        if (func_02005E50() == 0) {
            if (((struct Obj24944 *)a)->fC != 0) {
                func_02005DE4((void *)1);
                func_02005E64();
            }
            ((struct Obj03902 *)b)->f30 = 0;
        }
        break;
    case 2:
        if (func_02005F38() == 0)
            ((struct Obj03902 *)b)->f30 = 0;
        break;
    case 3:
        if (func_020063B4((u8 *)0x3f3, (u32 *)(b + 0x34), 0) != 0)
            ((struct Obj03902 *)b)->f30 = 4;
        break;
    case 4:
    case 5:
        break;
    case 6:
        if (func_02005E50() == 0) {
            func_02005D28();
            ((struct Obj03902 *)b)->f30 = 0;
        }
        break;
    case 7:
        if (func_020063B4((u8 *)0x519, (u32 *)(b + 0x34), 0) != 0)
            ((struct Obj03902 *)b)->f30 = 8;
        break;
    case 8:
        if (func_02005F38() == 0)
            func_02204F40((int)a, (int *)b);
        break;
    case 9:
        if (func_02005F38() == 0)
            func_02204F40((int)a, (int *)b);
        break;
    }
}

/*
 * Leaf of the func_022040E0 dependency tree: true when the scene object's
 * state word +0x30 is 1.  Unlabelled in the listing (a leaf that saves no
 * lr), so region-qualified.
 */
int func_02204EA0(int a, int *p)
{
    return p[0xc] == 1;
}


void func_02204EB0(char *a, char *b)
{
    if (((struct Obj24946 *)b)->f30 == 0 && ((struct Obj14523 *)a)->fC != 0) {
        func_02005E9C();
        func_02005DE4(0);
        func_02005DF8(0x3c);
    }
}


/*
 * Leaf of the func_022040E0 dependency tree: when the scene object sits in
 * state word +0x30 == 0, play cue 0x3f2 and move it to state 2.
 */
void func_02204ED0(int a, int *p)
{
    if (p[0xc] == 0) {
        func_02005D90(0x3f2, 0xffff);
        p[0xc] = 2;
    }
}
