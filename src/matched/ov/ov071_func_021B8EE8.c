/*
 * function: func_021B8EE8
 * address:  0x021B8EE8
 * packet:   pkt_ov071_021B8EE8
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B6C54  0x021B6C54  thumb  ov071
 *   func_02045B38  0x02045B38  arm
 *   func_021B9560  0x021B9560  thumb  ov071
 *   func_021B95FC  0x021B95FC  thumb  ov071
 *   func_021B96A4  0x021B96A4  thumb  ov071
 *   func_021BA11C  0x021BA11C  thumb  ov071
 *   func_021B9BB8  0x021B9BB8  thumb  ov071
 *   func_021B9AE4  0x021B9AE4  thumb  ov071
 *   func_021B9B64  0x021B9B64  thumb  ov071
 *   func_021B9BE8  0x021B9BE8  thumb  ov071
 *   func_021B9750  0x021B9750  thumb  ov071
 *   func_021B7174  0x021B7174  thumb  ov071
 *   func_020056A0  0x020056A0  thumb
 *   func_021BA1B0  0x021BA1B0  thumb  ov071
 *   func_021B9970  0x021B9970  thumb  ov071
 *   func_021B992C  0x021B992C  thumb  ov071
 *   func_021B9A40  0x021B9A40  thumb  ov071
 *   func_021BA140  0x021BA140  thumb  ov071
 *   func_020355C4  0x020355C4  arm
 *   func_021B9F2C  0x021B9F2C  thumb  ov071
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02040588  0x02040588  arm
 *   func_02043598  0x02043598  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef enum { B_FALSE, B_TRUE } Bool;

extern void *func_0203159C(int a, int b, int c);
extern void func_02082BCC(void *p, int v, int n);
extern void func_021B6C54(void *a);
extern int func_02045B38(int a, int b, int c, int d);
extern void func_021B9560(void);
extern void func_021B95FC(void *a, void *b);
extern void func_021B96A4(void *a, void *b);
extern void func_021BA11C(void *a);
extern void func_021B9BB8(void *a, void *b);
extern void func_021B9AE4(void *a, void *b);
extern void func_021B9B64(void *a, void *b);
extern void func_021B9BE8(void *a, void *b);
extern void func_021B9750(void *a, void *b);
extern int func_021B7174(void *a, int b, int c);
extern u32 func_020056A0(void (*cb)(void), void *arg, int pri);
extern void func_021BA1B0(void);
extern void func_021B9970(void *a, void *b, void *c);
extern void func_021B992C(void *a);
extern int func_021B9A40(void *a, void *b);
extern void func_021BA140(void *a);
extern int func_020355C4(void);
extern int func_021B9F2C(void *p, int i, int v);
extern u32 func_02045770(u32 a);
extern int func_0201C6C4(u32 a, u32 b);
extern void func_02045334(u32 a);
extern void func_02040588(int a, int b);
extern void func_02043598(int a, int b);

int func_021B8EE8(int a, int *b, u8 *c, u8 *o)
{
    int busy;
    u32 t;
    Bool f;

    switch (*b) {
    case 0:
        o = func_0203159C(a, 0x314, 0x61);
        func_02082BCC(o, 0, 0x314);
        *(int *)(o + 0x2d8) = 0x800;
        *(int *)(o + 0x300) = 0xffff;
        *(int *)(o + 0x2f8) = 0xffff;
        *(int *)(o + 0x2fc) = 0xffff;
        func_021B6C54(c);
        *(int *)(o + 0x20) = func_02045B38(0, 2, 0xa0, 0x61);
        func_021B9560();
        func_021B95FC(o, *(void **)(c + 4));
        func_021B96A4(o, *(void **)(c + 4));
        func_021BA11C(o);
        func_021B9BB8(c, o);
        func_021B9AE4(o, *(void **)(c + 4));
        func_021B9B64(c, o);
        func_021B9BE8(c, o);
        func_021B9750(c, o);
        *(int *)(o + 0x30c) = func_021B7174(*(void **)(c + 4), 4, 0x61);
        (*(u8 **)(c + 8))[1] = 0x30;
        *(u32 *)o = func_020056A0(func_021BA1B0, o, 3);
        func_021B9970(c, o, *(void **)(c + 4));
        func_021B992C(o);
        *b = *b + 1;
        break;
    case 1:
        if (func_021B9A40(o, *(void **)(c + 4)) == 1) {
            func_021BA140(o);
            *(int *)(o + 0x2f0) = 1;
            if (func_020355C4() == 0) {
                func_021B9F2C(o, 1, 0);
            } else {
                func_021B9F2C(o, 0xffff, 0);
            }
            *b = *b + 1;
        }
        break;
    case 2:
        busy = 0;
        t = (*(u32 **)(c + 4))[2];
        if (o[0x28c] != 0) {
            if (func_0201C6C4(t, func_02045770(*(u32 *)(o + 0x288))) == 0) {
                func_02045334(*(u32 *)(o + 0x288));
                o[0x28c] = 0;
            }
        }
        f = o[0x28c] == 0 ? B_TRUE : B_FALSE;
        if (f == B_FALSE) {
            busy = 1;
        }
        if (busy == 0) {
            func_02040588(4, 1);
            func_02040588(5, 1);
            func_02040588(6, 1);
            func_02043598(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}
