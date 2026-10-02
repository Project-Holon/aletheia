/*
 * function: func_021B70D8
 * address:  0x021B70D8
 * packet:   pkt_ov021_021B70D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0204A298  0x0204A298  arm
 *   func_020307B0  0x020307B0  arm
 *   d_021D99D0     0x021D99D0  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern u32 *func_02158F58(u32 p);
extern u32 func_02188C84(u32 p);
extern u32 func_02159B10(u32 a, u32 b);
extern u16 *func_02159AE8(void *a0, void *a1);
typedef struct Ent {
    u32 k;
    u32 v;
} Ent;

extern Ent *func_0204A298(u32, u32, u32, u32, u32 *);
extern void func_020307B0(void *p);
extern u8 d_021D99D0[];

int func_021B70D8(u32 a, u32 b)
{
    u32 i;
    u32 v;
    u32 k;
    u32 idx;
    u16 *out;
    Ent *arr;
    u32 cnt;

    v = func_02188C84(func_02158F58(func_0215A5F4((void *)b))[1]);
    k = func_02159B10(a, b);
    idx = func_02159B10(a, b);
    out = func_02159AE8((void *)a, (void *)b);
    arr = func_0204A298(0xd0, d_021D99D0[idx], 0, (u16)((v & 0x7fff) | 0x8000), &cnt);
    cnt >>= 3;
    i = 0;
    *out = 0;
    for (i = 0; i < cnt; i++) {
        if (k == arr[i].k) {
            *out = arr[i].v;
            break;
        }
    }
    func_020307B0(arr);
    return 0;
}
