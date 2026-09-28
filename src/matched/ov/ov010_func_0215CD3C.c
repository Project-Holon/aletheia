/*
 * function: func_0215CD3C
 * address:  0x0215CD3C
 * packet:   pkt_ov010_0215CD3C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021F36C0  0x021F36C0  thumb  ov037
 *   ov037_id       0x00000025  data
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern void *func_0215A5DC(void *);
extern u16 *func_02159AE8(void *, void *);
extern void func_02034AC4(u32);
extern void func_02034A5C(u32);
extern void func_021F36C0(void *, u32, u32);
extern char ov037_id[];

int func_0215CD3C(void *a, void *b)
{
    void *h = func_0215A5DC(b);
    u16 *p = func_02159AE8(a, b);
    u16 *q = func_02159AE8(a, b);
    func_02034AC4((u32)ov037_id);
    func_021F36C0(h, *p, *q);
    func_02034A5C((u32)ov037_id);
    return 0;
}
