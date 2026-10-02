/*
 * function: func_02174D5C
 * address:  0x02174D5C
 * packet:   pkt_ov011_02174D5C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_0216749C  0x0216749C  thumb ov010
 *   func_021673C4  0x021673C4  thumb ov010
 *   func_021673A8  0x021673A8  thumb ov010
 *   func_02039338  0x02039338  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Blk {
    u8 pad[0x50];
    u32 a : 6;
    u32 b : 4;
    u32 c : 4;
    u32 d : 4;
    u32 e : 6;
} Blk;

int func_02026478(int a);
void *func_02012EBC(int p);
void *func_0200E0B0(void *p);
void func_0216749C(void *a, Blk *b, int c, int d, u8 *e);
int func_021673C4(void *a);
int func_021673A8(void *a);
int func_02039338(void);

void func_02174D5C(int *p, const u8 *q)
{
    Blk *b;
    void *x;
    int t;
    u8 buf[4];

    b = (Blk *)((u8 *)p + 0x880);
    x = func_0200E0B0(func_02012EBC(func_02026478(p[1])));
    func_0216749C(x, b, 0x14, q[0], buf);
    b->a = buf[0];
    b->b = func_021673C4(x);
    b->c = func_021673A8(x);
    t = func_02039338();
    b->d = t;
    b->e = q[0];
}
