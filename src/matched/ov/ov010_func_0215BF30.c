/*
 * function: func_0215BF30
 * address:  0x0215BF30
 * packet:   pkt_ov010_0215BF30
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017988  0x02017988  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned int func_02159B10(void *a0, void *a1);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct BigObj;
struct Blk37;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_02017988(void *, void *);
extern void *func_0200CA1C(void *);
extern void func_0200CFA0(struct Blk37 *p, void *m);

int func_0215BF30(void *a0, void *a1)
{
    void *k = (void *)func_02159B10(a0, a1);
    void *v = (void *)func_02159B10(a0, a1);
    void *h;
    void *e;

    func_0215A5F4(a1);
    h = func_020120F4(func_0215A5DC(a1));
    e = func_0201AB28(func_02012934(h), (u32)k);
    func_02017988(e, v);
    func_0200CFA0(func_0200CA1C(h), e);
    return 0;
}
