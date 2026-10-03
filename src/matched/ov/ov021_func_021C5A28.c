/*
 * function: func_021C5A28
 * address:  0x021C5A28
 * packet:   pkt_ov021_021C5A28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns the func_021C5A54 task with a four-word work area.
 *
 * symbols:
 *   func_021C5A54  0x021C5A54  thumb  ov021
 */

typedef unsigned int u32;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
int func_021C5A54(int a, int *st, int *c);

void *func_021C5A28(void *a, u32 b, u32 c, u32 d)
{
    void *t = func_020122C0(a, 0, func_021C5A54, 0x10);
    u32 *w = func_020124E8(t);

    w[0] = (u32)a;
    w[1] = b;
    w[2] = c;
    w[3] = d;
    return t;
}
