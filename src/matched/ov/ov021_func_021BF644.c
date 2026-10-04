/*
 * function: func_021BF644
 * address:  0x021BF644
 * packet:   pkt_ov021_021BF644
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
 *   func_021BFB90  0x021BFB90  thumb  ov021
 */

typedef struct {
    int f0;
    int f4;
} Ent;

typedef unsigned int   u32;
struct Desc;
int func_021BFB90(int task, int *state, int *q);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
Ent *func_020124E8(int h);

int func_021BF644(int a, int b, int c)
{
    int h = (int)func_020122C0((void *)b, (void *)a, func_021BFB90, 0x68);
    Ent *e = func_020124E8(h);
    e->f4 = c;
    e->f0 = b;
    return h;
}
