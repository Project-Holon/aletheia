/*
 * function: func_021B889C
 * address:  0x021B889C
 * packet:   pkt_ov071_021B889C
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Twin of func_021B8494 (six handle slots at +0x18 instead of two at +8).
 *
 * symbols:
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B8A70  0x021B8A70  thumb  ov071
 *   func_021B8ADC  0x021B8ADC  thumb  ov071
 *   func_021B8B08  0x021B8B08  thumb  ov071
 *   func_021B8EC4  0x021B8EC4  thumb  ov071
 *   func_021B8C0C  0x021B8C0C  thumb  ov071
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02040588  0x02040588  arm
 *   func_02043598  0x02043598  arm
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

typedef unsigned int   u32;
struct Descriptor;
struct PrintSys;
int func_021B889C(int a, int *b, C *c, u8 *d)
{
    extern u8 *func_0203159C(int, int, int);
    extern void func_02082BCC(void *, int, int);
    extern void func_021B8A70(void);
    extern void func_021B8ADC(Q *);
    extern void func_021B8B08(Q *, u8 *);
    extern void func_021B8EC4(C *, u8 *);
    extern void func_021B8C0C(C *, Q *, u8 *);
    extern void *func_02045770(struct Descriptor *p);
    extern u32 func_0201C6C4(struct PrintSys *p, void *v);
    extern void func_02045334(struct Descriptor *d);
    extern void func_02040588(u32 which, u32 enable);
    extern void func_02043598(u32 mask, u32 enable);
    u8 *m;
    int busy;
    int i;

    switch (*b) {
    case 0:
        m = func_0203159C(a, 0x50, 0x61);
        func_02082BCC(m, 0, 0x50);
        func_021B8A70();
        func_021B8ADC(c->f4);
        func_021B8B08(c->f4, m);
        func_021B8EC4(c, m);
        func_021B8C0C(c, c->f4, m);
        *b = *b + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 6; i++) {
            void *q = c->f4->f8;
            u8 *s = d + i * 8;
            if (s[0x1c] != 0) {
                if (func_0201C6C4(q, (void *)((unsigned)func_02045770(*(void **)(s + 0x18)))) == 0) {
                    func_02045334(*(void **)(s + 0x18));
                    s[0x1c] = 0;
                }
            }
            if ((!s[0x1c]) == 0) {
                busy = 1;
            }
        }
        if (busy == 0) {
            func_02040588(4, 1);
            func_02040588(6, 1);
            func_02043598(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}
