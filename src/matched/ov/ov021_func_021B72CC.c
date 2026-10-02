/*
 * function: func_021B72CC
 * address:  0x021B72CC
 * packet:   pkt_ov021_021B72CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Same func_0204A298 lookup as func_021B70D8 / func_021B716C.  Here the
 * table byte d_021D99D0[idx] is loaded ahead of the `str r0,[sp]` that
 * passes &cnt: that needs the table declared const, otherwise the load
 * may alias the stack store and is scheduled after it.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C278  0x0200C278  thumb
 *   func_0204A298  0x0204A298  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021D99D0     0x021D99D0  data   ov021  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ent { u32 k; u32 v; };

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern u32 *func_02158F58(u32 p);
extern u32 func_02188C84(u32 p);
extern u32 func_02159B10(u32 a, u32 b);
extern u32 func_020127A4(u32 p);
extern u32 func_02012F08(u32 p);
extern void func_0200C278(u32 a, u32 b);
extern struct Ent *func_0204A298(u32, u32, u32, u32, u32 *);
extern void func_020307B0(void *p);
extern const u8 d_021D99D0[];

int func_021B72CC(u32 a, u32 b)
{
    void *h;
    u32 v;
    u32 k;
    u32 idx;
    struct Ent *arr;
    u32 cnt;
    u32 i;

    v = func_02188C84(func_02158F58(func_0215A5F4((void *)b))[1]);
    k = func_02159B10(a, b);
    idx = func_02159B10(a, b);
    h = func_0215A5E4((void *)b);
    func_020127A4(h);
    arr = func_0204A298(0xd0, d_021D99D0[idx], 0, (u16)((v & 0x7fff) | 0x8000), &cnt);
    cnt >>= 3;
    for (i = 0; i < cnt; i++) {
        if (k == arr[i].k) {
            func_0200C278(func_02012F08(h), arr[i].v);
            break;
        }
    }
    func_020307B0(arr);
    return 0;
}
