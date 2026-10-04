/*
 * function: func_022094BC
 * address:  0x022094BC
 * packet:   pkt_ov094_022094BC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020870D0  0x020870D0  arm
 *   func_0204B22C  0x0204B22C  arm
 *   func_02209540  0x02209540  thumb  ov094
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    int h[2];
    char pad8[0x4c - 8];
    int x4c[2];
    u64 t[2];
    int x64[2];
} W;

extern u64 func_020870D0(void);
struct Bank;
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern void func_02209540(W *w, int i);

void func_022094BC(u8 *p, int i, int a, int b)
{
    W *w = (W *)p;

    if (*(int *)(p + i * 0x1c + 8) != 0) {
        if (a == 1 && b == 1) {
            w->t[i] = func_020870D0();
            w->x64[i] = 0;
            func_02209540(w, i);
        }
        func_0204B22C((struct Bank *)w->h[i], a);
    }
}
