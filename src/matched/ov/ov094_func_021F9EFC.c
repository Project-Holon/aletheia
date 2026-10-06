/*
 * function: func_021F9EFC
 * address:  0x021F9EFC
 * packet:   pkt_ov094_021F9EFC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021FDB20  0x021FDB20  thumb  ov094
 *   func_021F8684  0x021F8684  thumb  ov094
 *   func_021F6EDC  0x021F6EDC  thumb  ov094
 *   func_021F6F48  0x021F6F48  thumb  ov094
 *   func_021F70F0  0x021F70F0  thumb  ov094
 *   func_0207C9D0  0x0207C9D0  arm
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    char pad[0x23C];
    int ret;            /* 0x23C */
} Ctx;

struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
extern void func_021FDB20(Ctx *c);
extern int func_021F8684(void);
extern void func_021F6EDC(int *p, int *a, int *b);
extern void func_021F6F48(int cam, int *a, int *b, int n, int s, int t);
extern void func_021F70F0(void **p, void *b, int c);
extern void func_0207C9D0(int *a, int *b, int *c);

int func_021F9EFC(void *r, Ctx *c)
{
    int A[3];
    int B[3];
    int C[3];
    int D[3];
    int n;
    int s;
    int t;
    int type;

    type = func_0201134C(r);
    A[0] = func_0201134C(r);
    A[1] = func_0201134C(r);
    A[2] = func_0201134C(r);
    B[0] = func_0201134C(r);
    B[1] = func_0201134C(r);
    B[2] = func_0201134C(r);
    n = func_0201134C(r);
    s = func_0201134C(r);
    t = func_0201134C(r);
    func_021FDB20(c);
    switch (type) {
    case 0:
        func_021F6EDC((int *)func_021F8684(), A, B);
        break;
    case 1:
        func_021F6F48(func_021F8684(), A, B, n, s, t);
        break;
    case 2:
        func_021F70F0((void **)func_021F8684(), C, (int)D);
        func_0207C9D0(C, A, A);
        func_0207C9D0(D, B, B);
        func_021F6F48(func_021F8684(), A, B, n, s, t);
        break;
    }
    return c->ret;
}
