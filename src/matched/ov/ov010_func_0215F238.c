/*
 * function: func_0215F238
 * address:  0x0215F238
 * packet:   pkt_ov010_0215F238
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_0201213C  0x0201213C  thumb
 *   func_02159144  0x02159144  thumb  ov010
 */

extern void *func_0215A5DC(void *p);
struct Ctx;
extern unsigned int func_02012138(const struct Ctx *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Comm;
struct Ctx;
extern u32 func_02026454(void *obj);
extern void func_02026400(struct Comm *p);
extern void func_0201213C(struct Ctx *p, u32 v);
extern void func_02159144(int v);

int func_0215F238(void *a, void *b)
{
    void *t;
    void *s;

    t = func_0215A5DC(b);
    s = (void *)func_02012138(t);
    switch (func_02026454(s)) {
    case 1:
    case 2:
    case 5:
        func_02026400(s);
        break;
    case 0:
    case 3:
    case 4:
        break;
    }
    func_0201213C(t, 1);
    func_02159144(0xb);
    return 1;
}
