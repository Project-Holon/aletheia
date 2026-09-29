/*
 * function: func_021FADC0
 * address:  0x021FADC0
 * packet:   pkt_ov094_021FADC0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0207C768  0x0207C768  arm
 *   func_021FCA04  0x021FCA04  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FFB04  0x021FFB04  thumb  ov094
 */
typedef struct {
    char pad[0x23C];
    int f23c;
} State;

typedef struct {
    int f0;
    int item;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
} Req;

extern int func_0201134C(void *);
extern int func_0207C768(int a, int b);
extern int func_021FCA04(State *s, int id, int *out);
extern void *func_021F8694(void);
extern void func_021FFB04(void *w, Req *r);

int func_021FADC0(void *a, State *s)
{
    Req q;
    int buf[8];
    int n;
    int p;
    int r;
    int t;
    int u;
    int v;
    int i;

    n = func_021FCA04(s, func_0201134C(a), buf);
    p = func_0201134C(a);
    r = func_0201134C(a);
    t = func_0201134C(a);
    u = func_0201134C(a);
    v = func_0201134C(a);
    q.f18 = r;
    q.f24 = v;
    q.f14 = p;
    q.f20 = u;
    q.f1c = func_0207C768(t - r, v << 12);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            q.item = buf[i];
            func_021FFB04(func_021F8694(), &q);
        }
    }
    return s->f23c;
}
