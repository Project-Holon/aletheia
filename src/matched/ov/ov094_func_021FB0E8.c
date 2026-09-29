/*
 * function: func_021FB0E8
 * address:  0x021FB0E8
 * packet:   pkt_ov094_021FB0E8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021FCA04  0x021FCA04  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FFDB4  0x021FFDB4  thumb  ov094
 */
typedef unsigned char u8;

typedef struct {
    char pad[0x23C];
    int f23c;
} State;

extern int func_0201134C(void *);
extern int func_021FCA04(State *s, int id, int *out);
extern void *func_021F8694(void);
extern void func_021FFDB4(void *w, int a, u8 b, u8 c, u8 d, int e);

int func_021FB0E8(void *a, State *s)
{
    int buf[8];
    int n;
    int p;
    int q;
    int r;
    int t;
    int i;

    n = func_021FCA04(s, func_0201134C(a), buf);
    p = func_0201134C(a);
    q = func_0201134C(a);
    r = func_0201134C(a);
    t = func_0201134C(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FFDB4(func_021F8694(), buf[i], p, q, r, t);
    }
    return s->f23c;
}
