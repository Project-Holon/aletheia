/*
 * function: func_021BF3D8
 * address:  0x021BF3D8
 * packet:   pkt_ov093_021BF3D8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CC8A0  0x021CC8A0  thumb  ov093
 *   func_021CC8B0  0x021CC8B0  thumb  ov093
 *   func_021BF46C  0x021BF46C  thumb  ov093
 *   func_021BF47C  0x021BF47C  thumb  ov093
 *   func_021BF48C  0x021BF48C  thumb  ov093
 *   func_021BF49C  0x021BF49C  thumb  ov093
 *   func_021C6E3C  0x021C6E3C  thumb  ov093
 *   func_021C7C24  0x021C7C24  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021BA1B4  0x021BA1B4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void func_021CC8A0(void *arr);
extern void func_021CC8B0(void *arr, int i, u32 v);
extern void func_021BF46C(int d);
extern u8 *func_021BF47C(int d);
extern void func_021BF48C(int d, u8 *x);
extern u8 *func_021BF49C(int d);
extern int func_021C6E3C(u8 *p, u8 *a, u8 *x, int b, int k);
extern void func_021C7C24(u8 *w, u8 *p, u8 *a, u8 *x, int k);
extern u8 func_021D5440(u8 *p);
extern int func_021B8DDC(int m);
extern u8 func_021B8FF4(u8 *p);
extern void func_021BA1B4(u8 *p, int k);

void func_021BF3D8(u8 *p, int b, u8 *a, int d, void *arr)
{
    u8 *x;
    int r;
    int e;
    func_021CC8A0(arr);
    func_021BF46C(d);
    x = func_021BF47C(d);
    while (x != 0) {
        r = func_021C6E3C(p, a, x, b, 1);
        func_021CC8B0(arr, func_021D5440(x), r);
        if (r == 0) {
            func_021BF48C(d, x);
            func_021C7C24(p + 0x1f7c, p, a, x, 0);
            e = func_021B8DDC(func_021D5440(a));
            if (e == func_021B8FF4(*(u8 **)(p + 4)))
                func_021BA1B4(*(u8 **)(p + 4), 0x4b);
        }
        x = func_021BF49C(d);
    }
}
