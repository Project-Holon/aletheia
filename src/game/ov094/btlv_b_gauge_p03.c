/*
 * file:     btlv_b_gauge_p03.c
 * unit:     yes
 * function: func_02207E1C, func_02207EA8
 * address:  0x02207E1C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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

typedef unsigned char  u8;

typedef struct S {
    u8 pad0[0x54];
    int f54;
    int f58;
    int pad5c;
    int f60;
    int f64;
    u8 pad68[4];
    u8 f6c;
    u8 pad6d[3];
    unsigned int f70;
} S;

extern int func_02207F6C(int n, int target, int delta, int *cur, u8 x, int speed);
extern void func_022082FC(O *obj, int idx, int k);
extern void func_02208420(O *obj, E *e, int v);
void func_02207E1C(O *obj, int idx);
void func_02207EA8(S *p, int a);


void func_02207E1C(O *obj, int idx)
{
    E *e;
    int r;

    e = &obj->e[idx];
    r = func_02207F6C(e->f4c, e->f48, e->f68, &e->f50, (int)6, (u16)e->f74);
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


/*
 * Lever: the clamp bound p->f58 is read from the struct twice (no local).
 */
void func_02207EA8(S *p, int a)
{
    int t;
    int x;

    if (p->f6c != 100) {
        t = p->f54;
        p->f64 = 0x80000000;
        x = t + a;
        if (x < 0) {
            a -= x;
        }
        x = t + a;
        if (x > p->f58) {
            a -= x - p->f58;
        }
        p->f60 = -a;
        if (p->f54 < 0) {
            p->f54 = 0;
        }
        if (p->f54 > p->f58) {
            p->f54 = p->f58;
        }
        p->f70 |= 2;
    }
}
