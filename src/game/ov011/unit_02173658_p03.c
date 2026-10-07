/*
 * file:     unit_02173658_p03.c
 * unit:     yes
 * function: func_02173828, func_021738BC, func_021738E4
 * address:  0x02173828
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D578  0x0203D578  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02175920  0x02175920  thumb ov011
 *   func_0217592C  0x0217592C  thumb ov011
 *   func_02167658 0x02167658 thumb ov010
 *   func_02039338  0x02039338  arm
 *   func_0203D3A8  0x0203D3A8  arm
 */
#include "../../matched/include/Obj09343.h"

struct Entry;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct { void *sys; void *obj; } Work;

typedef unsigned short u16;

int func_021736D8(void);
struct Entry *func_020399A8(void);
int func_0203D578(int a, int b);
void func_02082D44(void *d, void *s, int n);
unsigned int func_0203D3F8(unsigned int entry, unsigned int sendID, unsigned int c, unsigned int d, unsigned int e, unsigned int f, unsigned int g, unsigned int h);
u32 func_0203D378(void);
void func_02175920(void *p);
void func_0217592C(void *p);
extern void func_02167658(Work *, int);
u16 func_02039338(void);
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
int func_02173828(char *p);
void func_021738BC(int a, int b, int *c, u8 *d, void *e);
int func_021738E4(void *a, int b);


int func_02173828(char *p)
{
    int r;

    if (func_021736D8() == 0) {
        return 0;
    }
    if (func_0203D578((int)func_020399A8(), 0x203) == 1) {
        return 0;
    }
    func_02082D44(p + 0x160, p + 0x3A4, 0x4C);
    r = func_0203D3F8((int)func_020399A8(), 0xFF, 0x203, 0x4C, (unsigned int)(p + 0x3A4), 0, 0, 1);
    if (r == 1) {
        p[0x8FE] = 0;
        if (func_0203D378() == 1) {
            p[0x903] = 1;
            func_02175920(p + 0x1AC);
            func_0217592C(p + 0x1AC);
        }
    }
    return r;
}

/*
 * The index loaded from c remains live in r1 into 02167658.
 */
void func_021738BC(int a, int b, int *c, u8 *d, void *e)
{
    int i;
    u32 bit;
    u8 mask;
    i = *c;
    bit = 1u << i;
    mask = d[0x8fb];
    if (mask & bit) {
        d[0x8fb] = mask ^ (u8)bit;
        func_02167658(*(Work * *)&((struct Obj09343 *)d)->f8, i);
    }
}


int func_021738E4(void *a, int b)
{
    int h;

    if (func_021736D8() == 0) {
        h = func_02039338();
        func_021738BC(h, 4, &b, (u8 *)a, func_020399A8());
        return 1;
    }
    return func_0203D3A8(func_020399A8(), 0x204, 4, (u32)(&b));
}
