/*
 * function: func_021BD60C
 * address:  0x021BD60C
 * packet:   pkt_ov093_021BD60C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B86E4  0x021B86E4  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021BD6B8  0x021BD6B8  thumb  ov093
 *   func_021B9920  0x021B9920  thumb  ov093
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021BD708  0x021BD708  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021B86E4(u8 *p);
extern u8 func_021D5440(u8 *p);
extern int func_021B8DDC(u8 v);
extern int func_021B8FF4(u8 *p);
extern int func_021BD6B8(u8 *p, u8 *a);
extern u8 *func_021B9920(u8 *p, int i, int j);
extern u32 func_021D58A8(u8 *p, int k);
extern u32 func_021D78AC(int k);
extern int func_021BD708(u8 *p, u8 *a, int r, int z);

int func_021BD60C(u8 *p, u8 *a, u8 flag)
{
    int ret = 0;
    int k;
    u8 *q;
    u16 lo;
    u16 hi;
    int d;
    u32 t;
    if (func_021B86E4(*(u8 **)(p + 4)) == 0) {
        k = func_021B8DDC(func_021D5440(a));
        if (k == func_021B8FF4(*(u8 **)(p + 4))) {
            ret = func_021BD6B8(p, a);
            if (ret) flag = 1;
        } else {
            flag = 1;
        }
    } else {
        flag = 1;
        ret = 1;
    }
    if (flag == 0) {
        q = func_021B9920(*(u8 **)(p + 8), 1, 0);
        if (q) {
            lo = func_021D58A8(a, 0xc);
            hi = func_021D58A8(q, 0xc);
            if (lo <= hi) {
                d = (((int)lo << 12) / (int)hi << 7) >> 12;
                t = d + p[0x786] * 30;
                if (func_021D78AC(0x100) >= t) return 0;
            }
        }
    }
    return func_021BD708(p, a, ret, 0);
}
