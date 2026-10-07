/*
 * file:     btlv_effvm_p33.c
 * unit:     yes
 * function: func_021F9FC0, func_021FA048
 * address:  0x021F9FC0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021FDB20  0x021FDB20  thumb  ov094
 *   func_021F8684  0x021F8684  thumb  ov094
 *   func_021F6F20  0x021F6F20  thumb  ov094
 *   func_021F7108  0x021F7108  thumb  ov094
 *   func_021F6F48  0x021F6F48  thumb  ov094
 *   func_021F7000  0x021F7000  thumb  ov094
 */
struct Cursor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    char pad[0x23C];
    int ret;            /* 0x23C */
} Ctx;

extern u32 func_0201134C(struct Cursor *p);
extern void func_021FDB20(Ctx *c);
extern int func_021F8684(void);
extern void func_021F6F20(int cam, int a, int b);
extern void func_021F7108(int *p, int a, int b, int *out, int *base);
extern void func_021F6F48(int cam, int *a, int *b, int n, int s, int t);
extern void func_021F7000(int cam, int mode, int v, int unused, int n, int g, int h);
int func_021F9FC0(void *r, Ctx *c);
int func_021FA048(void *r, Ctx *c);


int func_021F9FC0(void *r, Ctx *c)
{
    int E[3];
    int F[3];
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;
    int type;

    type = func_0201134C(r);
    v1 = func_0201134C(r);
    v2 = func_0201134C(r);
    v3 = func_0201134C(r);
    v4 = func_0201134C(r);
    v5 = func_0201134C(r);
    func_021FDB20(c);
    switch (type) {
    case 0:
        func_021F6F20(func_021F8684(), v1, v2);
        break;
    case 1:
        func_021F7108((int *)func_021F8684(), v1, v2, E, F);
        func_021F6F48(func_021F8684(), E, F, v3, v4, v5);
        break;
    }
    return c->ret;
}


int func_021FA048(void *r, Ctx *c)
{
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;

    v0 = func_0201134C(r);
    v1 = func_0201134C(r);
    v2 = func_0201134C(r);
    v3 = func_0201134C(r);
    v4 = func_0201134C(r);
    v5 = func_0201134C(r);
    func_021F7000(func_021F8684(), v0, v1, v2, v3, v4, v5);
    return c->ret;
}
