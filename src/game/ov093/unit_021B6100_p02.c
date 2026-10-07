/*
 * file:     unit_021B6100_p02.c
 * unit:     yes
 * function: func_021B6818, func_021B6848
 * address:  0x021B6818
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B8BEC  0x021B8BEC  thumb  ov093
 *   func_021B68D8  0x021B68D8  thumb  ov093
 *   func_021B9114  0x021B9114  thumb  ov093
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02007B44  0x02007B44  thumb
 *   func_02007B20  0x02007B20  thumb
 *   func_02007C20  0x02007C20  thumb
 *   func_021B997C  0x021B997C  thumb  ov093
 *   func_021BA710  0x021BA710  thumb  ov093
 */
#include "../../matched/include/Obj03184.h"

struct PerapVoice;
struct Sub02007AC8Entry;
struct Big;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct P {
    u8 pad00[0x44];
    u8 f44[4];
};

struct T {
    u8 pad00[0x21];
    u8 f21;
    u8 pad22[0x36];
    u32 f58;
};

extern u8 func_021B8BEC(u8 *s, u32 k, u8 n);
extern void func_021B68D8(u8 *s, struct T *t);
extern u8 func_021B9114(u8 **p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02007AC8Entry *func_02007B44(void *sys);
extern void *func_02007B20(u32 heap);
extern void func_02007C20(struct PerapVoice *dest, const struct PerapVoice *src);
extern int func_021B997C(u8 *p, unsigned int i);
extern u8 func_021BA710(int a, int b);
unsigned int func_021B6818(unsigned int *p);
void func_021B6848(u8 *s, struct T *t);

unsigned int func_021B6818(unsigned int *p) { switch (*p) { case 0: return 0; case 1: return 0; case 2: return 0; case 3: return 1; default: return 0; } }


void func_021B6848(u8 *s, struct T *t)
{
    u32 i;
    u32 v;
    u8 tmp[4];
    u8 k = t->f21;

    i = 0;
    s[0x46c] = k;
    s[0x46d] = func_021B8BEC(s, k, 0);
    func_021B68D8(s, t);
    if (func_021B9114((u8 **)s) == 0) {
        v = (u32)func_02007B44(func_02012EBC((void *)t->f58));
        ((struct Obj03184 *)s)->f3E0 = (u32)func_02007B20(((struct Obj03184 *)s)->f468);
        func_02007C20((struct PerapVoice *)(((struct Obj03184 *)s)->f3E0), (const struct PerapVoice *)v);
        (*(struct P * *)&((struct Obj03184 *)s)->f0)->f44[0] = func_021B997C(s, i);
    } else {
        for (i = 0; i < 4; i++) {
            tmp[(int)func_021BA710(s[0x46c], (u8)i)] = (*(struct P * *)&((struct Obj03184 *)s)->f0)->f44[i];
        }
        for (i = 0; i < 4; i++) {
            (*(struct P * *)&((struct Obj03184 *)s)->f0)->f44[i] = tmp[i];
        }
    }
}
