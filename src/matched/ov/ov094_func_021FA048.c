/*
 * function: func_021FA048
 * address:  0x021FA048
 * packet:   pkt_ov094_021FA048
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021F8684  0x021F8684  thumb  ov094
 *   func_021F7000  0x021F7000  thumb  ov094
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    char pad[0x23C];
    int ret;            /* 0x23C */
} Ctx;

struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
extern int func_021F8684(void);
extern void func_021F7000(int cam, int mode, int v, int unused, int n, int g, int h);

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
