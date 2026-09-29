/*
 * function: func_021BA1FC
 * address:  0x021BA1FC
 * packet:   pkt_ov071_021BA1FC
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021BA3B4  0x021BA3B4  thumb  ov071
 *   func_021BA420  0x021BA420  thumb  ov071
 *   func_021BA44C  0x021BA44C  thumb  ov071
 *   func_021BA4EC  0x021BA4EC  thumb  ov071
 *   func_021BA528  0x021BA528  thumb  ov071
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02040588  0x02040588  arm
 *   func_020434DC  0x020434DC  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef enum { B_FALSE, B_TRUE } Bool;

extern void *func_0203159C(int a, int b, int c);
extern void func_02082BCC(void *p, int v, int n);
extern void func_021BA3B4(void);
extern void func_021BA420(void *a);
extern void func_021BA44C(void *a, void *b);
extern void func_021BA4EC(void *a, void *b);
extern void func_021BA528(void *a, void *b, void *c);
extern u32 func_02045770(u32 a);
extern int func_0201C6C4(u32 a, u32 b);
extern void func_02045334(u32 a);
extern void func_02040588(int a, int b);
extern void func_020434DC(int a, int b);

int func_021BA1FC(int a, int *b, u8 *o, u8 *c)
{
    u8 *m;
    int busy;
    int i;
    u32 t;
    u8 *e;
    Bool f;

    switch (*b) {
    case 0:
        m = func_0203159C(a, 0x28, 0x61);
        func_02082BCC(m, 0, 0x28);
        *(u32 *)(m + 0x24) = 0x30;
        func_021BA3B4();
        func_021BA420(*(void **)(o + 4));
        func_021BA44C(*(void **)(o + 4), m);
        func_021BA4EC(*(void **)(o + 4), m);
        func_021BA528(o, *(void **)(o + 4), m);
        *b = *b + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 3; i++) {
            t = (*(u32 **)(o + 4))[2];
            e = c + i * 8;
            if (e[0x10] != 0) {
                if (func_0201C6C4(t, func_02045770(*(u32 *)(e + 0xc))) == 0) {
                    func_02045334(*(u32 *)(e + 0xc));
                    e[0x10] = 0;
                }
            }
            f = e[0x10] == 0 ? B_TRUE : B_FALSE;
            if (f == B_FALSE) {
                busy = 1;
            }
        }
        if (busy == 0) {
            func_02040588(0, 1);
            func_02040588(2, 1);
            func_020434DC(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}
