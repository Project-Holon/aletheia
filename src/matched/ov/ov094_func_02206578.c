/*
 * function: func_02206578
 * address:  0x02206578
 * packet:   pkt_ov094_02206578
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203630C  0x0203630C  arm
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_0220684C  0x0220684C  thumb  ov094
 *   func_0220663C  0x0220663C  thumb  ov094
 *   func_02206710  0x02206710  thumb  ov094
 *   d_0220AEB0     0x0220AEB0  data   ov094
 */
#include "../include/Obj00823.h"
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    unsigned int lo : 31;
    unsigned int top : 1;
} Top;

typedef struct {
    char *s;
    int f4;
    int f8;
    int fc;
} Ctx;

extern unsigned int func_0203630C(void);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *file, u16 line);
extern void *func_02030DA8(void *owner, void *fn, void *p, u32 a3);
extern void func_0220684C(char *p, int a, int b);
extern void func_0220663C(void);
extern void func_02206710(void *h);
extern char d_0220AEB0[];

int func_02206578(char *s, int a, int b)
{
    Ctx *c;
    int flag;

    if (b < 0)
        return a;
    if ((func_0203630C() & 0x200) && a < 4 && (((struct Obj00823 *)s)->f58 == 2 || ((struct Obj00823 *)s)->f58 == 5))
        ((struct Obj00823 *)s)->f70 = a | 0x8000;
    else
        ((struct Obj00823 *)s)->f70 = a;
    c = func_02030734((u16)((((struct Obj00823 *)s)->f240 & 0x7fff) | 0x8000), 0x10, 0, d_0220AEB0, 0x1440);
    flag = 0;
    if ((0x10000 & b) == 0)
        flag = 1;
    ((Top *)(s + 0x68))->top = flag;
    c->s = s;
    c->f4 = 0;
    c->f8 = (u16)b;
    if (((struct Obj00823 *)s)->f220 == 1 && c->f8 == 0)
        c->fc = 1;
    else
        c->fc = 0;
    func_0220684C(s, (int)func_02030DA8(((struct Obj00823 *)s)->f0, (void *)func_0220663C, c, 0), (int)((void *)func_02206710));
    return -1;
}
