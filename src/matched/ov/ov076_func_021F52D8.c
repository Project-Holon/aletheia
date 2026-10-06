/*
 * function: func_021F52D8
 * address:  0x021F52D8
 * packet:   pkt_ov076_021F52D8
 * region:   ov076
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the func_020122C0 handle (r0 stays live to the epilogue, which
 * pushes the -1 / flag temporaries into r1).
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF52C  0x021CF52C  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F5334  0x021F5334  thumb  ov076
 */
typedef unsigned int u32;

struct Ctx;
struct Desc;
extern void *func_0201210C(const struct Ctx *p);
extern int func_02189A08(unsigned char *p);
extern u32 *func_021CF52C(u32 *p, int size, int heap);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F5334(void *task, int *st);

void *func_021F52D8(void *a, u32 b, u32 c, u32 d, int e)
{
    u32 *w;
    void *h;

    w = func_021CF52C((u32 *)func_02189A08((unsigned char *)((int)func_0201210C(a))), 0x44, 0x50);
    h = func_020122C0(a, 0, func_021F5334, 0);
    w[1] = b;
    w[0xB] = c;
    w[0xC] = d;
    w[0x10] = -1;
    if (e != 0) {
        w[0xD] = 0xC;
    } else {
        w[0xD] = 3;
    }
    return h;
}
