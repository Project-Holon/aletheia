/*
 * function: func_021C5B58
 * address:  0x021C5B58
 * packet:   pkt_ov021_021C5B58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5A28  0x021C5A28  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_0216C0C0  0x0216C0C0  thumb  ov010
 */

typedef unsigned short u16;

typedef unsigned int   u32;
struct Ctx;
struct Evt;
struct Sub02008C20Obj;
extern void *func_021C5A28(void *a, u32 b, u32 c, u32 d);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern int func_0216C0C0(int a0);

int func_021C5B58(int a, int *st, int *c)
{
    int *q;
    int f;

    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, func_021C5A28((void *)c[0], c[1], c[2], c[5]));
        (*st)++;
        break;
    case 1:
        q = (int *)c[2];
        if (q[7] != 1) {
            func_02017E40((void *)c[3], 0x73, q[8]);
        }
        f = 1;
        if (((int *)c[2])[7] == 1) {
            f = 0;
        }
        *(u16 *)c[4] = f;
        if (*(u16 *)c[4] == 1) {
            func_02008DF0(func_02012F2C(func_020120F4((const struct Ctx *)c[0])), 0x1e);
        }
        func_0216C0C0(c[2]);
        return 1;
    }
    return 0;
}
