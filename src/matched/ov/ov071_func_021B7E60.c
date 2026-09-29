/*
 * function: func_021B7E60
 * address:  0x021B7E60
 * packet:   pkt_ov071_021B7E60
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_021B8308  0x021B8308  thumb  ov071
 *   func_021B8350  0x021B8350  thumb  ov071
 *   func_021B81A0  0x021B81A0  thumb  ov071
 *   func_021B82E4  0x021B82E4  thumb  ov071
 *   func_02043598  0x02043598  arm
 */

typedef struct {
    char pad[0x32];
    unsigned char f32;
} W;

typedef struct {
    char pad[0x3d];
    unsigned char f3d;
} Q;

typedef struct {
    Q *q;
    int *f4;
} C;

int func_021B7E60(int a, int unused, C *c)
{
    extern void *func_020120F4(void *);
    extern void *func_0203159C(int, int, int);
    extern void func_02082BCC(void *, int, int);
    extern void *func_0201296C(void *);
    extern int func_020142E8(void *, unsigned);
    extern void func_021B8308(void);
    extern void func_021B8350(W *, int *);
    extern void func_021B81A0(C *, W *);
    extern void func_021B82E4(void *, int);
    extern void func_02043598(int, int);
    void *h = func_020120F4(*(void **)c->q);
    W *w = func_0203159C(a, 0x48, 0x61);

    func_02082BCC(w, 0, 0x48);
    if (func_020142E8(func_0201296C(h), 0x980) == 0) {
        w->f32 = 2;
    } else if (c->q->f3d == 1) {
        w->f32 = 1;
    } else {
        w->f32 = 0;
    }
    func_021B8308();
    func_021B8350(w, c->f4);
    func_021B81A0(c, w);
    func_021B82E4(c, (int)w);
    func_02043598(0x10, 1);
    return 1;
}
