/*
 * function: func_0217CA40
 * address:  0x0217CA40
 * packet:   pkt_ov018_0217CA40
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02012B8C  0x02012B8C  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02175710  0x02175710  thumb  ov011
 *   func_0217CA1C  0x0217CA1C  thumb  ov018
 */

struct Ctx;

extern unsigned int func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
typedef unsigned char  u8;
struct BigObj;
extern u8 func_02012B58(const struct BigObj *p);
extern void func_02012B8C(struct BigObj *p, unsigned int v);
extern int func_02158344(int a0);
typedef unsigned int   u32;
extern void func_02175710(u8 *o, u32 v);
extern void *func_0217CA1C(void *p);

void *func_0217CA40(int a0)
{
    int h;
    void *c;
    int p;

    h = func_02012138((const struct Ctx *)a0);
    c = func_020120F4((const struct Ctx *)a0);
    p = func_02158344(h);
    if (p != 0) {
        func_02175710((u8 *)p, func_02012B58(c));
    } else {
        func_02012B8C(c, func_02012B58(c));
    }
    return func_0217CA1C((void *)a0);
}
