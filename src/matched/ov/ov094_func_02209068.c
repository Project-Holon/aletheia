/*
 * unit:     yes
 * function: func_02209068, func_022090A4
 * address:  0x02209068
 * packet:   pkt_ov094_02209068
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_020307B0  0x020307B0  arm
 */
typedef unsigned int u32;

typedef struct {
    int h0;
    int h4;
    int h8;
    int hc;
    struct { int f10; char pad[0x18]; } e[7];
} W;

struct Bank;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204B1CC(struct Bank *bank);
extern u32 func_020307B0(void *p);

void func_02209068(W *w)
{
    int i;

    for (i = 0; i < 7; i++)
        func_0204B3B4((struct Obj *)w->e[i].f10);
    func_0204A8D4(w->h4);
    func_0204ADA4(w->hc);
    func_0204AFD8(w->h8);
    func_0204B1CC((struct Bank *)w->h0);
    func_020307B0(w);
}

int func_022090A4(int *p)
{
    if (p[0xd8 / 4 + 0] != 0)
        return 1;
    return 0;
}
