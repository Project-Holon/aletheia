/*
 * function: func_021FAD2C
 * address:  0x021FAD2C
 * packet:   pkt_ov094_021FAD2C
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
 *   func_021FFA18  0x021FFA18  thumb  ov094
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
    char pad[0x14];
} Req;

extern int func_0201134C(void *);
extern int func_021FCA04(State *s, int id, int *out);
extern int func_021F8694(void);
extern void func_021FFA18(void *w, Req *r);

int func_021FAD2C(void *a, State *s)
{
    Req q;
    int buf[8];
    int n;
    int i;

    n = func_021FCA04(s, func_0201134C(a), buf);
    q.f8 = func_0201134C(a);
    q.fc = func_0201134C(a);
    q.f10 = func_0201134C(a);
    q.f14 = func_0201134C(a);
    q.f18 = func_0201134C(a) >> 12;
    q.f1c = func_0201134C(a) >> 12;
    q.f20 = func_0201134C(a) >> 12;
    q.f24 = func_0201134C(a);
    if (n != 0 && q.f20 != 0) {
        for (i = 0; i < n; i++) {
            q.item = buf[i];
            func_021FFA18((void *)func_021F8694(), &q);
        }
    }
    return s->f23c;
}
