/*
 * function: func_021B716C
 * address:  0x021B716C
 * packet:   pkt_ov021_021B716C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0201292C  0x0201292C  thumb
 *   func_0204A298  0x0204A298  arm
 *   func_02007F68  0x02007F68  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_021D99D0     0x021D99D0  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern u32 *func_02158F58(void *p);
extern u32 func_02188C84(u32 p);
extern u32 func_02159B10(u32 a, u32 b);
extern u16 *func_02159AE8(void *a0, void *a1);
struct BigObj;
extern void *func_0201292C(const struct BigObj *p);
extern u32 *func_0204A298(u32, u32, u32, u32, u32 *);
extern int func_02007F68(void *a, u32 b, u32 c, u32 d);
extern void func_020307B0(void *p);
extern u8 d_021D99D0[];

int func_021B716C(u32 a, u32 b)
{
    void *s;
    void *h;
    u32 v;
    u32 idx;
    u16 *out;
    u32 *arr;
    u32 cnt;
    u32 i;

    s = func_0215A5F4((void *)b);
    h = func_0215A5E4((void *)b);
    v = func_02188C84(func_02158F58(s)[1]);
    idx = func_02159B10(a, b);
    out = func_02159AE8((void *)a, (void *)b);
    h = func_0201292C(h);
    arr = func_0204A298(0xd0, d_021D99D0[idx], 0, (u16)((v & 0x7fff) | 0x8000), &cnt);
    cnt >>= 3;
    *out = 0;
    for (i = 0; i < cnt; i++) {
        if (func_02007F68(h, (u16)arr[i * 2], 1, v)) {
            *out = 1;
            break;
        }
    }
    func_020307B0(arr);
    return 0;
}
