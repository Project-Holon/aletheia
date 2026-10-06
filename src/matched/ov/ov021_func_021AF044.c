/*
 * function: func_021AF044
 * address:  0x021AF044
 * packet:   pkt_ov021_021AF044
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Blocker: func_02029DF4 (arm9, unlabelled thumb veneer: ldr r3,[pc]; bx r3;
 * .word 0x02029EB5) has no witness outside the range (evidence class: none;
 * arm9 leaf belongs to Ilias, not filed here).
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02029DF4  0x02029DF4  thumb
 *   func_020298A0  0x020298A0  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02028BDC  0x02028BDC  thumb
 *   func_02159168  0x02159168  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
struct Stream;
extern unsigned short func_02011330(struct Stream *s);
struct Ctx;
struct S;
extern void *func_020120F4(const struct Ctx *p);
typedef unsigned short u16;
typedef unsigned char  u8;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
struct BigObj;
extern unsigned int func_02012A30(const struct BigObj *a);
extern u8 func_02012984(const struct BigObj *p);
extern u16 func_02188C9C(u8 *p);
extern unsigned int func_02029DF4(void *a, unsigned int id, unsigned int which);
extern void *func_020298A0(void *a, u32 b, u32 c, u32 d);
extern void func_0215897C(void *vm, void *task);
extern void func_02028BDC(struct S *s, u32 mask);
extern void func_02159168(int n);

int func_021AF044(struct Stream *a, u32 b)
{
    u32 y, m, n, q, s;
    void *x;
    void *l;
    void *p;

    x = func_0215A5DC((void *)b);
    y = (u32)func_020120F4(x);
    l = func_0201210C((void *)x);
    m = func_02012A30((const struct BigObj *)y);
    p = func_0215A5F4((void *)b);
    n = func_02011330(a);
    q = func_02012984((const struct BigObj *)y);
    s = func_02029DF4((void *)y, func_02188C9C(l), q);
    func_0215897C(p, (void *)func_020298A0(x, s, n, 0x3c));
    func_02028BDC((struct S *)m, 2);
    func_02159168(13);
    return 1;
}
