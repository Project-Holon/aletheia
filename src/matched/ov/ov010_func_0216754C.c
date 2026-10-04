/*
 * function: func_0216754C
 * address:  0x0216754C
 * packet:   pkt_ov010_0216754C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02167658  0x02167658  thumb  ov010
 *   func_02012114  0x02012114  thumb
 *   func_021942C8  0x021942C8  thumb  ov021
 *   func_02034714  0x02034714  arm
 *   func_020307B0  0x020307B0  arm
 *   d_02172A28  0x02172A28  data  ov010  a4
 */

struct O {
    int f0;
    int f4;
};

extern void func_02167658(struct O *o, int i);
struct Ctx;
extern unsigned int func_02012114(const struct Ctx *a);
extern void func_021942C8(int a);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_020307B0(void *p);
extern const char d_02172A28[];

void func_0216754C(int a, struct O *o)
{
    int i;
    if (o->f4 != 0) {
        for (i = 0; i < 4; i++)
            func_02167658(o, i);
        if (func_02012114((const struct Ctx *)a) == 1)
            func_021942C8(o->f4);
        else
            func_02034714(d_02172A28, 0, d_02172A28);
    }
    func_020307B0(o);
}
