/*
 * function: func_0217D4DC
 * address:  0x0217D4DC
 * packet:   pkt_ov018_0217D4DC
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02158378  0x02158378  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_0217F174  0x0217F174  thumb  ov018
 *   func_0217F0C4  0x0217F0C4  thumb  ov018
 *   func_0217CEE8  0x0217CEE8  thumb  ov018
 *   func_0217CE08  0x0217CE08  thumb  ov018
 *   func_0217CE6C  0x0217CE6C  thumb  ov018
 */

typedef struct {
    void *f0;
    unsigned char pad004[0x10C];
    unsigned short f110;
    unsigned char f112;
    unsigned char pad113[0x55];
    unsigned char f168;
} Ov018Menu;

void *func_02012138(void *);
void *func_020120F4(void *);
void *func_0201210C(void *p);
int func_02012B70(void *);
int func_02158344(void *);
int func_02158378(void *);
void func_020061E4(int);
void func_0217F174(Ov018Menu *);
void func_0217F0C4(Ov018Menu *);
int func_0217CEE8(void *, int, int);
int func_0217CE08(void *, int, int, int);
int func_0217CE6C(void *, int, int);

int func_0217D4DC(Ov018Menu *w, int b, int c)
{
    void *s1;
    void *s2;
    void *r;
    int ret;

    s1 = func_02012138(w->f0);
    s2 = func_020120F4(w->f0);
    r = func_0201210C(w->f0);
    ret = 0;
    if (b == 0 || r == 0) {
        return 0;
    }
    if (w->f168 == 1 || (func_02012B70(s2) == 0 && func_02158344(s1) == 0)) {
        func_020061E4(0x551);
        func_0217F174(w);
        return func_0217CEE8(w->f0, r, c);
    }
    switch (w->f112) {
    case 1:
        func_020061E4(0x737);
        func_0217F0C4(w);
        ret = func_0217CE08(w->f0, r, w->f110, 0);
        break;
    case 2:
        func_020061E4(0x737);
        ret = func_0217CE6C(w->f0, r, func_02158378(s1));
        break;
    }
    if (ret != 0) {
        w->f112 = 0;
        return ret;
    }
    return 0;
}
