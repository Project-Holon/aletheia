/*
 * function: func_0215A7F0
 * address:  0x0215A7F0
 * packet:   pkt_ov010_0215A7F0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F91C  0x0201F91C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045874  0x02045874  arm
 *   func_02190A64  0x02190A64  thumb  ov021
 */

typedef struct {
    unsigned short a;
    unsigned short pad[5];
    int g;
    int h;
    int i;
    int j;
    int pad1c;
    int k[32];
} Q;

extern unsigned func_0201F91C(int);
extern void func_02045CAC(int, int, int);
struct WordSet;
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int func_02045874(int, int);
typedef unsigned int   u32;
extern int func_02190A64(u32 a, u32 b, u32 c, u32 d);

void func_0215A7F0(unsigned short *p, int a, int b, int c, int s0, int s1)
{
    Q *q = (Q *)(*(char **)((char *)p + 0x20) + 0x34);

    if (b != 0xffff) {
        unsigned i = func_0201F91C(q->j);
        if (i >= 0x20) {
            return;
        }
        func_02045CAC(q->i, b, s1);
        func_0201F250((struct WordSet *)q->g, (void *)s0, (void *)s1);
        q->k[i] = func_02045874(s0, *p);
    }
    func_02045CAC(q->i, a, s1);
    func_0201F250((struct WordSet *)q->g, (void *)s0, (void *)s1);
    func_02190A64(q->j, s0, c, *p);
}
