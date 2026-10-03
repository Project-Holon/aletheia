/*
 * function: func_0215CDF0
 * address:  0x0215CDF0
 * packet:   pkt_ov010_0215CDF0
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
 *   func_021F3768  0x021F3768  thumb  ov037
 *   ov037_id       0x00000025  data
 */

typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern unsigned short *func_02159AE8(void *a0, void *a1);
typedef signed int     s32;
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern void func_021F3768(void *, void *);
extern char ov037_id[];

int func_0215CDF0(void *a, void *b)
{
    unsigned short *v[8];
    void *h = func_0215A5DC(b);
    v[0] = func_02159AE8(a, b);
    v[1] = func_02159AE8(a, b);
    v[2] = func_02159AE8(a, b);
    v[3] = func_02159AE8(a, b);
    v[4] = func_02159AE8(a, b);
    v[5] = func_02159AE8(a, b);
    v[6] = func_02159AE8(a, b);
    v[7] = func_02159AE8(a, b);
    func_02034AC4((u32)ov037_id);
    func_021F3768(h, v);
    func_02034A5C((u32)ov037_id);
    return 0;
}
