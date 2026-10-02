/*
 * function: func_0215FBF4
 * address:  0x0215FBF4
 * packet:   pkt_ov010_0215FBF4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_0201232C  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0215FA54  0x0215FA54  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02188CCC();
struct Desc;
struct Ctx;
struct Big;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void func_0201232C();
extern u32 *func_020124E8();
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void func_0215FA54();

/* record behind the descriptor: owner, its context, the context's head */
struct Rec {
    int   owner;
    void *ctx;
    void *head;
};

struct Desc *func_0215FBF4(int a0, int a1, struct Desc *a2, int a3)
{
    struct Rec *p;
    void *ctx;

    func_02188CCC(a1);
    if (a3 != 0) {
        a2 = func_020122C0((void *)a0, 0, (void *)func_0215FA54, 0x34);
    } else {
        func_0201232C(a2, func_0215FA54, 0x34);
    }
    p = (struct Rec *)func_020124E8(a2);
    ctx = func_020120F4((const struct Ctx *)a0);
    p->ctx = ctx;
    p->head = func_02012EBC((struct Big *)ctx);
    p->owner = a0;
    return a2;
}
