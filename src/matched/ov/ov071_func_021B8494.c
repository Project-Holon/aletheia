/*
 * function: func_021B8494
 * address:  0x021B8494
 * packet:   pkt_ov071_021B8494
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
 *   func_021B8650  0x021B8650  thumb  ov071
 *   func_021B86BC  0x021B86BC  thumb  ov071
 *   func_021B86E8  0x021B86E8  thumb  ov071
 *   func_021B8764  0x021B8764  thumb  ov071
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02040588  0x02040588  arm
 *   func_020434DC  0x020434DC  arm
 */

typedef unsigned char u8;

typedef struct {
    char pad0[8];
    void *f8;
} Q;

typedef struct {
    void **f0;
    Q *f4;
} C;

int func_021B8494(int a, int *b, C *c, u8 *d)
{
    extern u8 *func_0203159C(int, int, int);
    extern void func_02082BCC(void *, int, int);
    extern void func_021B8650(void);
    extern void func_021B86BC(Q *);
    extern void func_021B86E8(Q *, u8 *);
    extern void func_021B8764(Q *, u8 *);
    extern unsigned func_02045770(void *);
    extern int func_0201C6C4(void *, unsigned);
    extern void func_02045334(void *);
    extern void func_02040588(int, int);
    extern void func_020434DC(int, int);
    u8 *m;
    int busy;
    int i;

    switch (*b) {
    case 0:
        m = func_0203159C(a, 0x28, 0x61);
        func_02082BCC(m, 0, 0x28);
        func_021B8650();
        func_021B86BC(c->f4);
        func_021B86E8(c->f4, m);
        func_021B8764(c->f4, m);
        m[0x24] = 0xff;
        *b = *b + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 2; i++) {
            void *q = c->f4->f8;
            u8 *s = d + i * 8;
            if (s[0xc] != 0) {
                if (func_0201C6C4(q, func_02045770(*(void **)(s + 8))) == 0) {
                    func_02045334(*(void **)(s + 8));
                    s[0xc] = 0;
                }
            }
            if ((!s[0xc]) == 0) {
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
