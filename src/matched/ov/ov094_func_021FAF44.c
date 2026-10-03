/*
 * function: func_021FAF44
 * address:  0x021FAF44
 * packet:   pkt_ov094_021FAF44
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
 *   func_021FF924  0x021FF924  thumb  ov094
 */
typedef struct {
    char pad[0x23C];
    int f23c;
} State;

extern int func_0201134C(void *);
extern int func_021FCA04(State *s, int id, int *out);
extern void *func_021F8694(void);
extern void func_021FF924(char *w, int key, int kind, int value, int a, int b, int c);

int func_021FAF44(void *a, State *s)
{
    int buf[8];
    int n;
    int p;
    int q;
    int r;
    int t;
    int u;
    int i;

    n = func_021FCA04(s, func_0201134C(a), buf);
    p = func_0201134C(a);
    q = func_0201134C(a);
    r = func_0201134C(a);
    t = func_0201134C(a);
    u = func_0201134C(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            func_021FF924(func_021F8694(), buf[i], p, q, r, t, u);
    }
    return s->f23c;
}
