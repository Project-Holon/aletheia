/*
 * function: func_021BF58C
 * address:  0x021BF58C
 * packet:   pkt_ov021_021BF58C
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
 *   func_021BF694  0x021BF694  thumb  ov021
 */

typedef unsigned int u32;

typedef struct {
    void *x0;
    u32 x4;
} Work;

extern void *func_020122C0(void *p, int a, void (*cb)(void), int n);
struct Obj;
extern void *func_020124E8(struct Obj *p);
void func_021BF694(void);

void *func_021BF58C(int a, void *p, u32 c)
{
    void *task = func_020122C0(p, a, func_021BF694, 0x68);
    Work *w = func_020124E8(task);

    w->x4 = c;
    w->x0 = p;
    return task;
}
