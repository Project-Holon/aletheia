/*
 * function: func_0217AFE4
 * address:  0x0217AFE4
 * packet:   pkt_ov019_0217AFE4
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0217AED4  0x0217AED4  thumb  ov019
 *   func_0217AE40  0x0217AE40  thumb  ov019
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_02034714  0x02034714  arm
 *   d_021807E0     0x021807E0  data  ov019  a1
 */

typedef unsigned char u8;

typedef struct {
    int f0;
    u8 f4, f5, f6, f7, f8, f9;
    u8 pad[2];
} Ent;

typedef struct {
    u8 pad[6];
    u8 f6;
    u8 f7 : 1;
} Src;

extern int func_0217AED4(int, Ent *);
extern int func_0217AE40(void *, int, int, int);
extern void func_0216DAC8(int, int);
extern void func_02034714(const char *, int, const char *);
extern const char d_021807E0[];

Ent *func_0217AFE4(char *a, int b, Src *c, int d, int e, int *f)
{
    Ent *p;
    int i;
    int r;

    p = (Ent *)(a + 0x2E88);
    for (i = 0; i < 50; i++, p++) {
        if (p->f7 == 0) {
            p->f0 = b;
            p->f4 = c->f6;
            p->f5 = c->f7;
            p->f6 = d;
            p->f7 = 1;
            r = func_0217AED4(b, p);
            r = func_0217AE40(a, ((int *)*(int *)a)[2], c->f6, r);
            if (e == 0)
                func_0216DAC8(r, 1);
            *f = r;
            return p;
        }
    }
    func_02034714(d_021807E0, 0, d_021807E0);
    return 0;
}
