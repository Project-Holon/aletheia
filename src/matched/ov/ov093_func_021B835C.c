/*
 * function: func_021B835C
 * address:  0x021B835C
 * packet:   pkt_ov093_021B835C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4270  0x021D4270  thumb  ov093
 *   func_021B6818  0x021B6818  thumb  ov093
 *   func_021E8F20  0x021E8F20  thumb  ov093
 *   func_021CD95C  0x021CD95C  thumb  ov093
 *   func_021BAB40  0x021BAB40  thumb  ov093
 *   func_021B8434  0x021B8434  thumb  ov093
 *   func_021B84D8  0x021B84D8  thumb  ov093
 */
#include "../include/Obj03685.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad[0x473];
    u8 a : 1;
    u8 b : 1;
} B;

extern int func_021D4270(void);
extern unsigned int func_021B6818(unsigned int *p);
struct QA;
struct Scene;
extern struct Scene *func_021E8F20(void *a, void *b, u32 c, int d, u16 heap);
extern void func_021CD95C(struct QA *p, u32 v);
extern void func_021BAB40(char *p);
extern int func_021B8434(u8 *);
extern int func_021B84D8(u8 *);

int func_021B835C(u8 *p, int *q)
{
    int r, t;
    if (func_021D4270()) {
        ((B *)p)->a = 1;
        return 1;
    }
    if (*q == 0) {
        r = func_021B6818((unsigned int *)(*(int * *)&((struct Obj03685 *)p)->f0));
        t = (int)func_021E8F20(p, (void *)(*(int *)(p + p[0x46c] * 4 + 0x10)), (u32)(p + 0xc8), r, 0x13);
        ((struct Obj03685 *)p)->f4 = t;
        func_021CD95C((struct QA *)(*(int *)(p + p[0x46c] * 4 + 0x10)), t);
        if (p[0x46e]) {
            ((struct Obj03685 *)p)->f464 = (u32)func_021B8434;
            func_021BAB40((char *)(((struct Obj03685 *)p)->f8));
        } else {
            ((struct Obj03685 *)p)->f464 = (u32)func_021B84D8;
        }
        *q = *q + 1;
    } else {
        return 1;
    }
    return 0;
}
