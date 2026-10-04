/*
 * function: func_021FAECC
 * address:  0x021FAECC
 * packet:   pkt_ov094_021FAECC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021FCA04  0x021FCA04  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FF730  0x021FF730  thumb  ov094
 */
typedef struct {
    char pad[0x23C];
    int f23c;
} State;

extern int func_0201134C(void *);
extern int func_021FCA04(State *s, int id, int *out);
extern int func_021F8694(void);
extern void func_021FF730(void *w, int a, int b, int *c, int d, int e, int f);

int func_021FAECC(void *a, State *s)
{
    int buf[8];
    int t[3];
    int n;
    int x;
    int r;
    int u;
    int v;
    int i;

    n = func_021FCA04(s, func_0201134C(a), buf);
    x = func_0201134C(a);
    i = 0;
    t[0] = 0;
    t[1] = 0;
    t[2] = func_0201134C(a);
    r = func_0201134C(a);
    u = func_0201134C(a);
    v = func_0201134C(a);
    if (n != 0) {
        for (; i < n; i++)
            func_021FF730((void *)func_021F8694(), buf[i], x, t, r, u, v);
    }
    return s->f23c;
}
