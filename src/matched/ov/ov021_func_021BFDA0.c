/*
 * function: func_021BFDA0
 * address:  0x021BFDA0
 * packet:   pkt_ov021_021BFDA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns a 0x7C-byte task (callback func_021C021C).
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021C021C  0x021C021C  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Desc;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
void *func_020124E8(struct Obj *p);
int func_021C021C(u32 a, int *st, u8 *p);

void *func_021BFDA0(int a0, void *p, int a2, int a3)
{
    void *t = func_020122C0(p, (void *)a0, func_021C021C, 0x7C);
    int *w = func_020124E8(t);

    w[0] = (int)p;
    w[1] = a2;
    w[3] = 0;
    w[29] = 0;
    w[30] = a3;
    return t;
}
