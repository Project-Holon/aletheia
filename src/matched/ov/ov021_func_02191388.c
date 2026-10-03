/*
 * function: func_02191388
 * address:  0x02191388
 * packet:   pkt_ov021_02191388
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02194974  0x02194974  thumb  ov021
 *   func_02194984  0x02194984  thumb  ov021
 *   func_0201CE30  0x0201CE30  thumb
 *   func_02040618  0x02040618  arm
 *   func_021927F8  0x021927F8  thumb  ov021
 *   func_02194990  0x02194990  thumb  ov021
 *   func_02045770  0x02045770  arm
 *   func_021927FC  0x021927FC  thumb  ov021
 *   func_02045334  0x02045334  arm
 *   func_02193228  0x02193228  thumb  ov021
 *   func_021932A0  0x021932A0  thumb  ov021
 *   func_0219320C  0x0219320C  thumb  ov021
 *   func_021928C0  0x021928C0  thumb  ov021
 *   func_0201CE34  0x0201CE34  thumb
 *   func_02193260  0x02193260  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_0201CE38  0x0201CE38  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_02194974(u32, u32);
extern u32 func_02194984(u32, u32);
extern u32 func_0201CE30(u32);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern u32 func_021927F8(u32 *);
extern u32 func_02194990(u32, u32);
extern u32 func_02045770(u32);
extern void func_021927FC(u32 *, u32, u32);
extern void func_02045334(u32);
extern u32 func_02193228(u32);
extern void func_021932A0(u32 a, int f);
extern u32 func_0219320C(u32);
extern void func_021928C0(u32 *, u32, u32);
extern u32 func_0201CE34(u32);
extern u32 func_02193260(u32, u32);
extern void func_020061E4(u32);
extern void func_0201CE38(u32);

u32 func_02191388(u32 *a)
{
    u32 h;
    u32 r;
    u32 w;
    u32 c;

    if (func_02194974(a[2], *((u8 *)a + 1)) == 0) {
        return 0;
    }
    h = func_02194984(a[2], *((u8 *)a + 1));
    r = func_0201CE30(h);
    func_02040618(1, 3, *(s16 *)((u8 *)a + 2));
    if (*(s16 *)((u8 *)a + 2) < 0) {
        *(s16 *)((u8 *)a + 2) += 2;
        if (*(s16 *)((u8 *)a + 2) > 0) {
            *(s16 *)((u8 *)a + 2) = 0;
        }
    }
    *(s16 *)((u8 *)a + 2) = -*(s16 *)((u8 *)a + 2);
    switch (r) {
    case 0:
        if (func_021927F8(a + 3) == 1) {
            w = func_02194990(a[2], *((u8 *)a + 1));
            func_021927FC(a + 3, func_02045770(w), 15);
            func_02045334(w);
        }
        if (func_02193228(a[5] + 0x160) != 0) {
            func_021932A0(h, 1);
        } else {
            func_021932A0(h, 0);
        }
        break;
    case 1:
        w = func_02194990(a[2], *((u8 *)a + 1));
        c = func_02045770(w);
        if (func_0219320C(a[5] + 0x160) == 0) {
            func_021928C0(a + 3, c, 15);
        }
        if (func_02193260(a[5] + 0x160, func_0201CE34(h)) != 0) {
            if (func_0219320C(a[5] + 0x160) == 0) {
                func_020061E4(0x547);
            }
            func_0201CE38(h);
            func_021927FC(a + 3, c, 15);
            func_021932A0(h, 0);
        }
        func_02045334(w);
        break;
    case 2:
        if (*(s16 *)((u8 *)a + 2) != 0) {
            *(s16 *)((u8 *)a + 2) = 0;
            func_02040618(1, 3, *(s16 *)((u8 *)a + 2));
        }
        return 1;
    }
    return 0;
}
