/*
 * function: func_0217B1D0
 * address:  0x0217B1D0
 * packet:   pkt_ov019_0217B1D0
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   memcmp        0x0203EFC8  arm
 *   memset        0x02082BCC  arm
 *   func_02012114 0x02012114  thumb
 *   func_0201210C 0x0201210C  thumb
 *   func_02188CE0 0x02188CE0  thumb  ov021
 *   func_0217AED4 0x0217AED4  thumb  ov019
 *   func_02012964 0x02012964  thumb
 *   func_0216DE94 0x0216DE94  thumb  ov010
 *   func_0217F93C 0x0217F93C  thumb  ov019
 */

typedef unsigned char u8;

struct sub {
    u8 mac[6];
    u8 pad;
    u8 : 1;
    u8 f : 1;
    u8 : 6;
};

struct ent {
    u8 pad0[0x28];
    struct sub s[5];
    u8 pad1[0x20];
    int p[5];
};

struct inner {
    int pad0[2];
    int f8;
    int fc;
};

struct obj {
    struct inner *in;
};

extern int memcmp(const void *a, const void *b, int n);
extern void memset(void *p, int v, int n);
extern int func_02012114(int);
extern int func_0201210C(int);
extern int func_02188CE0(int);
extern int func_0217AED4(struct ent *e, int v);
extern int func_02012964(int);
extern int func_0216DE94(int, int);
extern void func_0217F93C(int, int);

int func_0217B1D0(struct obj *o, struct ent *e)
{
    int i;
    int v;
    int t;
    int r;

    for (i = 0; i < 5; i++) {
        v = e->p[i];
        if (v == 0 || e->s[i].f != 1) {
            continue;
        }
        if (memcmp(e->s[i].mac, (char *)o + 0x28a4, 6) != 0) {
            continue;
        }
        if (func_02012114(o->in->fc) == 1) {
            t = func_02188CE0(func_0201210C(o->in->fc));
            if (t != 0) {
                r = func_0217AED4(e, v);
                r = func_0216DE94(func_02012964(o->in->f8), r);
                if (r != 0) {
                    func_0217F93C(t, r);
                }
            }
        }
        memset((char *)o + 0x28a4, 0, 6);
        return 1;
    }
    return 0;
}
