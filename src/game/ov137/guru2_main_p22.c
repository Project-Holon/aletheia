/*
 * file:     guru2_main_p22.c
 * unit:     yes
 * function: func_021E1320, func_021E13BC, func_021E13F0, func_021E1400, func_021E140C, func_021E141C, func_021E1468, func_021E1488
 * address:  0x021E1320
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DFEA0 0x021DFEA0 thumb ov137
 *   func_021DFEAC 0x021DFEAC thumb ov137
 *   func_021DFEB8 0x021DFEB8 thumb ov137
 *   func_020061E4 0x020061E4 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_02030EAC  0x02030EAC  arm
 *   d_021E2278 0x021E2278 data a4
 */
#include "../../matched/include/Obj14248.h"
#include "../../matched/include/Obj23797.h"
#include "../../matched/include/Obj23798.h"
#include "../../matched/include/Obj14249.h"
#include "../../matched/include/Obj14250.h"

struct Node;
typedef unsigned short u16;

typedef struct { u16 state, flag; int count; } State;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed int     s32;

typedef signed char s8;

typedef signed short s16;

extern void func_021DFEA0(u8 *p);
extern void func_021DFEAC(u8 *p);
extern void func_021DFEB8(u8 *p);
extern void func_020061E4(u32 a);
extern void func_02082BCC(void *, int, unsigned);
extern void *func_02030DA8(void *, void (*)(void *, char *), void *, int);
extern void func_02030EAC(struct Node *n);
void func_021E1320(void *task, State *p);
void func_021E13A8(void *unused, char *p);
void func_021E13BC(char *p);
void func_021E13F0(u8 *p);
u16 func_021E1400(char *p);
void func_021E140C(char *p);
void func_021E141C(void *unused, int *p);
void func_021E1468(void *unused, char *p);
void func_021E1488(char *p);
extern const int d_021E2278[];

void func_021E1320(void *task, State *p)
{
    switch (p->state) {
    case 0: break;
    case 1:
        func_021DFEA0(task);
        func_020061E4(1832);
        p->count = 0;
        p->state++;
    case 2:
        p->count++;
        if (p->count >= 2) {
            p->count = 0;
            p->state++;
            func_021DFEB8(task);
        }
        break;
    case 3:
        p->count++;
        if (p->count >= 4) {
            func_021DFEA0(task);
            p->count = 0;
            p->state++;
        }
        break;
    case 4:
        p->count++;
        if (p->count >= 2) {
            func_021DFEAC(task);
            p->flag = 0;
            p->state = 0;
        }
        break;
    }
}

/*
 * follower: 021E13A8 tail-forwards r1 and r1+0xC88 to this callback.
 */
void func_021E13A8(void *unused, char *p)
{
    func_021E1320(p, (State *)(p + 0xc88));
}

void func_021E13BC(char *p)
{
    unsigned n = 8;
    func_02082BCC(p + 0xc88, 0, n);
    n += 251;
    ((struct Obj14248 *)p)->fD8C = func_02030DA8(((struct Obj14248 *)p)->fD98, func_021E13A8, p, n);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021E13F0(u8 *p)
{
    func_02030EAC(((struct Obj23797 *)p)->fD8C);
}


u16 func_021E1400(char *p)
{
    return ((struct Obj23798 *)p)->fC8A;
}


void func_021E140C(char *p)
{
    char *q = p + 0xC88;

    ((struct Obj14249 *)q)->f2 = 1;
    ((struct Obj14249 *)q)->f0 = 1;
}

void func_021E141C(void *unused, int *p)
{
    switch (p[0]) {
    case 0: break;
    case 1:
        *(int *)(p[3] + 0x54) = d_021E2278[p[1]] << 12;
        p[1]++;
        if (p[1] >= 16) {
            p[1] = 0;
            p[0]++;
        }
        break;
    case 2:
        p[2]++;
        if (p[2] >= 15) {
            p[2] = 0;
            p[0] = 1;
        }
        break;
    }
}

void func_021E1468(void *unused, char *p)
{
    int i;
    int *q = (int *)(p + 0xc90);
    for (i = 0; i < 5; i++, q += 4) func_021E141C(p, q);
}

void func_021E1488(char *p)
{
    unsigned n = 80;
    func_02082BCC(p + 0xc90, 0, n);
    n += 180;
    ((struct Obj14250 *)p)->fD90 = func_02030DA8(((struct Obj14250 *)p)->fD98, func_021E1468, p, n);
}
