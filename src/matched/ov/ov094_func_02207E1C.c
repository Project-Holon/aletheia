/*
 * function: func_02207E1C
 * address:  0x02207E1C
 * packet:   pkt_ov094_02207E1C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02207F6C  0x02207F6C  thumb  ov094
 *   func_022082FC  0x022082FC  thumb  ov094
 *   func_02208420  0x02208420  thumb  ov094
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct E {
    char p0[0x48];
    int f48;
    int f4c;
    int f50;
    char p54[0x14];
    int f68;
    int p6c;
    u32 b0 : 1;
    u32 mid : 20;
    u32 x : 5;
    u32 y : 1;
    u32 hi : 5;
    int f74;
    char p78[8];
} E;

typedef struct O {
    char pad[0x40];
    E e[8];
} O;

extern int func_02207F6C(int a, int b, int c, int *d, int e, u16 f);
extern void func_022082FC(O *obj, int idx, int k);
extern void func_02208420(O *obj, E *e, int v);

void func_02207E1C(O *obj, int idx)
{
    E *e;
    int r;

    e = &obj->e[idx];
    r = func_02207F6C(e->f4c, e->f48, e->f68, &e->f50, 6, e->f74);
    func_022082FC(obj, idx, 0);
    if (r == -1) {
        e->f48 = e->f48 - e->f68;
        func_02208420(obj, e, e->f48);
        e->b0 = 0;
        e->f50 = 0;
        if (e->f68 > 0) {
            e->x = 18;
            e->y = 1;
        }
    } else {
        func_02208420(obj, e, r);
    }
}
