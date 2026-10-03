/*
 * function: func_021BE9F0
 * address:  0x021BE9F0
 * packet:   pkt_021BE9F0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator with callback, then link-node field setup; returns the allocator
 * result.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BEA6C  0x021BEA6C  thumb  ov021
 *   func_021BF518  0x021BF518  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
int func_021BEA6C(int x);
int func_021BF518(int a, int *s, int *q);

void *func_021BE9F0(void *p, int a1, int a2, int a3, int a4)
{
    void *r0v = func_020122C0(p, 0, func_021BF518, 0x2C);
    int *r4 = func_020124E8(r0v);

    r4[0] = (int)p;
    r4[1] = a1;
    r4[2] = a2;
    r4[5] = a3;
    r4[3] = (int)func_021BEA6C(a2);
    r4[4] = a4;
    return r0v;
}
