/*
 * function: func_021BB460
 * address:  0x021BB460
 * packet:   pkt_ov099_021BB460
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C388C     0x021C388C  data   ov099  a4
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B62E0  0x021B62E0  thumb  ov067
 *   func_021B6578  0x021B6578  thumb  ov067
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    int v[8];
} T8;

typedef struct {
    void *f0;
    u32 f4;
    int f8;
    u32 fC;
    u32 f10;
    u32 f14;
    int f18;
    int f1c;
} A;

extern const T8 d_021C388C;
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *func_021B62E0(A *a, int heap);
extern void func_021B6578(void *a, int b, int c);

void func_021BB460(char *p, int x)
{
    T8 t;
    A a;
    void *r;

    t = d_021C388C;
    if (*(void **)(p + 0x9AC) == 0) {
        func_02082BCC(&a, 0, 0x20);
        a.f0 = &t;
        a.f4 = 1;
        a.f8 = *(int *)(p + 0x110);
        a.f1c = 0;
        a.fC = 4;
        a.f10 = 0xC;
        a.f14 = 0xC;
        a.f18 = 2;
        r = func_021B62E0(&a, x);
        *(void **)(p + 0x9AC) = r;
        func_021B6578(r, 1, 0);
    }
}
