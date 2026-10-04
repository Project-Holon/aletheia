/*
 * function: func_021DFABC
 * address:  0x021DFABC
 * packet:   pkt_ov093_021DFABC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct Rec {
    int pad00;
    u16 f04;
    u8 f06;
    u8 pad07[5];
    u8 f0c[1];
} Rec;

extern int func_021D775C(int key);
extern u32 func_0201BEB8(u16 id, u32 bit);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void *func_021C7CF4(int a, int b);
extern int func_021DCFF8(int a, int b);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);

void func_021DFABC(int a, int q, int id)
{
    Rec *r;
    void *m;
    int n;

    if (id != func_021D775C(4))
        return;
    if (func_021D775C(70) != 0)
        return;
    if (!func_0201BEB8(func_021D775C(18), 0))
        return;
    r = (Rec *)func_021C88A4((void *)q, 7, id);
    r->f06 = func_021D775C(3);
    m = func_021C7CF4(q, r->f06);
    n = (u8)func_021DCFF8(a, 2);
    r->f04 = func_021D7B74(m, n);
    func_021C8838(r->f0c, 2, 424);
    func_021C8860((struct S *)r->f0c, r->f06);
    func_021C88C8((void *)q, r);
}
