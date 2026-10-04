/*
 * function: func_021D0B58
 * address:  0x021D0B58
 * packet:   pkt_ov021_021D0B58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   func_020072CC  0x020072CC  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_0200E5F8  0x0200E5F8  thumb
 *   func_0200734C  0x0200734C  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_021DE674     0x021DE674  data  a4
 */

typedef struct Big {
    int w[72];
} Big;

extern int d_021DE674;

typedef unsigned int   u32;
struct Ctx;
struct Sub020073D8Ctrl;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern int func_020072CC(int a, int b, int c, void *d, int e);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern Big *func_0200E5F8(int a, int b);
struct Sub02007324Ctrl;
extern void func_0200734C(struct Sub02007324Ctrl *a, unsigned int b);
extern void func_020307B0(void *p);

void func_021D0B58(int a, Big *dst, int idx)
{
    int h;
    void *buf;
    int v;

    h = (int)func_02012EBC(func_020120F4((const struct Ctx *)a));
    buf = func_02030734(0x8004, 0x8004 >> 3, 1, (const char *)&d_021DE674, 0x14C);
    v = 0x8004 >> 3;
    if (func_020072CC(h, 5, 0x8004, buf, v) == 1) {
        *dst = *func_0200E5F8((int)func_020073D8((struct Sub020073D8Ctrl *)h, 5, 0), idx);
    }
    func_0200734C((struct Sub02007324Ctrl *)h, 5);
    func_020307B0(buf);
}
