/*
 * function: func_0215BF7C
 * address:  0x0215BF7C
 * packet:   pkt_ov010_0215BF7C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_0215B4DC  0x0215B4DC  thumb  ov010
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020185C4  0x020185C4  thumb
 *   d_02171180     0x02171180  data   ov010  a2
 *   d_0217118E     0x0217118E  data   ov010  a2
 *   d_02171190     0x02171190  data   ov010  a2
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017A20  0x02017A20  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02159B10(void *, void *);
extern void *func_0215A5F4(void *);
extern void *func_0215A5DC(void *);
extern void *func_020120F4(void *);
extern void *func_02012934(void *);
extern void *func_0201AB28(void *, void *);
extern void func_02017A20(void *, void *, void *);
extern void *func_0200CA1C(void *);
extern void func_0200CFA0(void *, void *);

int func_0215BF7C(void *a0, void *a1)
{
    void *k = func_02159B10(a0, a1);
    void *v = func_02159B10(a0, a1);
    void *w = func_02159B10(a0, a1);
    void *h;
    void *e;

    func_0215A5F4(a1);
    h = func_020120F4(func_0215A5DC(a1));
    e = func_0201AB28(func_02012934(h), k);
    func_02017A20(e, w, v);
    func_0200CFA0(func_0200CA1C(h), e);
    return 0;
}
