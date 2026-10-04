/*
 * function: func_0215A07C
 * address:  0x0215A07C
 * packet:   pkt_ov010_0215A07C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02030734  0x02030734  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A214  0x0215A214  thumb  ov010
 *   d_021728CC  0x021728CC  data
 */
#include "../include/Obj07281.h"

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    void *f0;
    void *f4;
    u32 *f8;
    void *fC;
    u16 *f10;
    u16 *f14;
} Task;

struct BigObj;
struct Ctx;
struct Obj;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void func_0215A214(void);
extern const char d_021728CC[];

void *func_0215A07C(int a, u16 *b, u16 *c)
{
    void *h = func_02012934(func_020120F4((void *)a));
    u32 *p = func_02030734(4, 0x98, 1, d_021728CC, 0x40);
    void *r;
    Task *q;
    ((struct Obj07281 *)p)->f0 = h;
    p[0x34 / 4] = 3;
    p[0x38 / 4] = 0;
    p[0x3c / 4] = 0;
    r = func_020122C0((void *)a, 0, func_0215A214, 0x18);
    q = func_020124E8(r);
    q->f0 = (void *)a;
    q->f4 = func_0201210C((void *)a);
    q->f8 = p;
    q->fC = 0;
    q->f10 = b;
    q->f14 = c;
    return r;
}
