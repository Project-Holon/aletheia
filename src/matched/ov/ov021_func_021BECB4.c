/*
 * function: func_021BECB4
 * address:  0x021BECB4
 * packet:   pkt_ov021_021BECB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BEA6C  0x021BEA6C  thumb  ov021
 *   func_021BF208  0x021BF208  thumb  ov021
 */

typedef unsigned int u32;

typedef struct {
    void *x0;
    u32 x4;
    u32 x8;
    u32 xc;
} Work;

typedef unsigned char  u8;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
int func_021BEA6C(int x);
int func_021BF208(u32 p0, int *st, u8 *q);

void *func_021BECB4(void *p, u32 b)
{
    void *task = func_020122C0(p, 0, func_021BF208, 0x2C);
    Work *w = func_020124E8(task);

    w->x0 = p;
    w->x4 = b;
    w->x8 = 6;
    w->xc = func_021BEA6C(6);
    return task;
}
