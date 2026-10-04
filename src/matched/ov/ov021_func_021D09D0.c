/*
 * function: func_021D09D0
 * address:  0x021D09D0
 * packet:   pkt_ov021_021D09D0
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
 *   func_0200E5A0  0x0200E5A0  thumb
 *   func_0200E5CC  0x0200E5CC  thumb
 *   func_0200734C  0x0200734C  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_021DE674     0x021DE674  data  a4
 */

extern int d_021DE674;

typedef unsigned int   u32;
struct Big;
struct Ctx;
struct Sub020073D8Ctrl;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);
extern void func_020072CC(int a, int b, int c, void *d, int e);
extern void *func_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v);
extern int func_0200E5A0(void *a0);
extern int func_0200E5CC(void *p);
struct Sub02007324Ctrl;
extern void func_0200734C(struct Sub02007324Ctrl *a, unsigned int b);
extern void func_020307B0(void *p);

void func_021D09D0(int a, char *out)
{
    int v;
    int t;
    int h;
    void *buf;

    h = (int)func_02012EBC(func_020120F4((const struct Ctx *)a));
    buf = func_02030734(0x8004, 0x8004 >> 3, 1, (const char *)&d_021DE674, 0x79);
    v = 0x8004 >> 3;
    func_020072CC(h, 5, 0x8004, buf, v);
    v = 0;
    t = (int)func_020073D8((struct Sub020073D8Ctrl *)h, 5, 0);
    if (func_0200E5A0((void *)t)) {
        int r = func_0200E5CC((void *)t);
        v = 1;
        if (r == 0) {
            v = 2;
        }
    }
    func_0200734C((struct Sub02007324Ctrl *)h, 5);
    func_020307B0(buf);
    *(int *)(out + 0x150) = v;
}
