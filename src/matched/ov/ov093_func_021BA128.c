/*
 * function: func_021BA128
 * address:  0x021BA128
 * packet:   pkt_ov093_021BA128
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKEPARTY_Init  0x0201A948  thumb
 *   func_0201AC2C  0x0201AC2C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 */

typedef unsigned int u32;

struct Party;
struct Rec534;
extern void POKEPARTY_Init(struct Party *p);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);

struct S {
    char pad[0x298];
    void *a[4];
    void *b[4];
    void *c;
};

void func_021BA128(struct S *p, int i, void *x)
{
    if (p->a[i]) {
        POKEPARTY_Init(p->a[i]);
        POKEPARTY_Init(p->b[i]);
        func_0201AC2C(x, p->a[i]);
        func_0201AC2C(x, p->b[i]);
        if (func_0201AA18(p->b[i])) {
            func_0201AB28(p->b[i], 0);
        }
    }
}
