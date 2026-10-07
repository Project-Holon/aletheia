/*
 * file:     unit_021F5A80.c
 * unit:     yes
 * function: func_021F5A80, func_021F5ABC, func_021F5AE8
 * address:  0x021F5A80
 * region:   ov080
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F5B64 0x021F5B64 data a4
 *   func_02189A08 0x02189A08 thumb ov021
 *   func_021CF580 0x021CF580 thumb ov021
 *   func_021F5260 0x021F5260 thumb ov075
 *   func_021F582C 0x021F582C thumb ov077
 *   func_021F5620  0x021F5620  thumb  ov077
 *   func_021F5B44  0x021F5B44  thumb  ov080
 */
#include "../../matched/include/Obj09916.h"

struct Vec;
struct Param;
typedef struct { int x,y,z; } Vec;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct {
    int w;
    int h;
    void (*init)(void *);
    void (*step)(void *);
    int (*done)(void *);
} Cfg;

typedef unsigned short u16;

extern int func_02189A08(unsigned char *p);
extern void func_021CF580(void *);
extern void *func_021F5260(void *a, struct Vec *src, u32 b, u32 c);
extern void func_021F582C(u8 *p);
extern void *func_021F5620(void *task, const struct Param *p, int flag);
extern int func_021F5B44(int *o);
void *func_021F5A80(void *p, int b);
void func_021F5ABC(void *a);
void func_021F5AE8(u8 *w);
extern const Vec d_021F5B64;

void *func_021F5A80(void *p, int b) {
    Vec v = d_021F5B64;
    func_021CF580((void *)func_02189A08((unsigned char *)b));
    return func_021F5260(p, (struct Vec *)(&v), (u32)((void (*)(void))func_021F5ABC), (u32)func_021F582C);
}


void func_021F5ABC(void *a)
{
    Cfg c;

    c.w = 2;
    c.h = 2;
    c.init = 0;
    c.step = (void (*)(void *))func_021F5AE8;
    c.done = (int (*)(void *))func_021F5B44;
    func_021F5620(a, (const struct Param *)(&c), 1);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021F5AE8(u8 *w)
{
    int *c = (int *)(w + 0x3000);

    if (c[0] < ((struct Obj09916 *)w)->f3008) {
        if (c[1] == 0) {
            int i;

            for (i = 0; i < ((struct Obj09916 *)w)->f300A; i++)
                *(int *)(w + (c[0] + i * ((struct Obj09916 *)w)->f3008) * 64 + 0x34) = 1;
            c[0]++;
            c[1] = 1;
        } else {
            c[1]--;
        }
    }
}
