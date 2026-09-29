/*
 * function: func_021BD584
 * address:  0x021BD584
 * packet:   pkt_ov093_021BD584
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B8DDC  0x021B8DDC  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021BD60C  0x021BD60C  thumb  ov093
 *   func_021BA1B4  0x021BA1B4  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern int func_021B8DDC(u8 v);
extern int func_021B8FF4(u8 *p);
extern int func_021BD60C(u8 *p, u8 *a, u8 flag);
extern void func_021BA1B4(u8 *p, int k);
extern void func_021CD64C(void *w, u8 id, ...);

int func_021BD584(u8 *p, u8 *a)
{
    int k = func_021B8DDC(func_021D5440(a));
    int m = func_021B8FF4(*(u8 **)(p + 4));
    int s = func_021BD60C(p, a, 0);
    if (s) return 1;
    if (k == m) {
        func_021BA1B4(*(u8 **)(p + 4), 0x4e);
        func_021CD64C(*(void **)(p + 0xc), 0x5a, 0x49, 0xffff0000);
    } else {
        func_021CD64C(*(void **)(p + 0xc), 0x5b, 0x36b, func_021D5440(a), 0xffff0000);
    }
    if (k == m) {
        p[0x786]++;
        if (p[0x786] > 0x1e) p[0x786] = 0x1e;
    }
    return s;
}
