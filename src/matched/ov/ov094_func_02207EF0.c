/*
 * function: func_02207EF0
 * address:  0x02207EF0
 * packet:   pkt_ov094_02207EF0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_022080B0  0x022080B0  thumb  ov094
 *   func_02207F6C  0x02207F6C  thumb  ov094
 *   func_022082FC  0x022082FC  thumb  ov094
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct E {
    char p0[0x54];
    int f54;
    int f58;
    int p5c;
    int f60;
    int f64;
    char p68[8];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 hi : 30;
    char p74[12];
} E;

typedef struct O {
    char pad[0x40];
    E e[8];
} O;

extern int func_022080B0(int a, int b, int c, unsigned int d);
extern int func_02207F6C(int a, int b, int c, int *d, int e, u16 f);
extern void func_022082FC(O *obj, int idx, int k);

void func_02207EF0(O *obj, int idx)
{
    E *e;
    int k;
    int q;
    int r;

    e = &obj->e[idx];
    k = func_022080B0(e->f54, e->f60, e->f58, 10);
    if (k == 0) {
        k = 1;
    }
    q = e->f60 / k;
    if (q < 0) {
        q = -q;
    }
    if (q == 0) {
        q = 1;
    }
    r = func_02207F6C(e->f58, e->f54, e->f60, &e->f64, 10, q);
    func_022082FC(obj, idx, 1);
    if (r == -1) {
        e->f54 = e->f54 - e->f60;
        e->b1 = 0;
        e->f64 = 0;
    }
}
