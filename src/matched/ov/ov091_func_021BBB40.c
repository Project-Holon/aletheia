/*
 * function: func_021BBB40
 * address:  0x021BBB40
 * packet:   pkt_ov091_021BBB40
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BBC04  0x021BBC04  thumb  ov091
 *   func_020355D8  0x020355D8  arm
 *   func_02027778  0x02027778  thumb
 *   d_021BEC80     0x021BEC80  data  a4
 */
#include "../include/Obj07734.h"
#include "../include/Obj13255.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Req {
    u32 heap;
    u8 v;
    u8 *p;
    u32 one;
    u8 c[4];
} Req;

typedef struct Tbl {
    u32 a;
    u32 b;
    u32 c;
} Tbl;

extern Tbl d_021BEC80;
extern void func_021BBC04(u8 *p, u8 *s, int *items);
extern void func_020355D8(u32 a);
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);

void func_021BBB40(u8 *a, u8 *b)
{
    Req r;
    Tbl t = d_021BEC80;

    func_021BBC04(a, b, (int *)(&t));
    r.heap = ((struct Obj07734 *)a)->f0;
    r.v = b[0];
    r.p = b + 0x14;
    r.one = 1;
    r.c[0] = 0x20;
    r.c[1] = 0x12;
    r.c[2] = 8;
    r.c[3] = 3;
    func_020355D8(((struct Obj07734 *)a)->f8);
    ((struct Obj13255 *)b)->f74 = (int)func_02027778((struct TaskMenuTmpl *)(&r), (void *)(((struct Obj07734 *)a)->f254));
}
