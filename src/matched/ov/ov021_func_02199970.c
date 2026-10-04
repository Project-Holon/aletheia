/*
 * function: func_02199970
 * address:  0x02199970
 * packet:   pkt_ov021_02199970
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   d_021DDBD4     0x021DDBD4  data   ov021  a4
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D80C  0x0216D80C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D818  0x0216D818  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D824  0x0216D824  thumb  ov010
 *   func_0216D848  0x0216D848  thumb  ov010
 *   func_0216D860  0x0216D860  thumb  ov010
 *   func_0216D87C  0x0216D87C  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
typedef struct {
    u8  count;
    u8  axis;
    u8  moveAxis;
    u8  negate;
    int speed;
    int accum;
    u16 angle;
    u16 step;
} State;
extern State *func_0216D6D4(u32);
struct Actor;
struct VecFx32;
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void func_0216D89C(u32, Vec *);
extern int *d_021DDBD4[2];
extern void func_0216D8C0(u32, Vec *);
extern u32 func_0216D83C(u32);
extern u32 func_0216D80C(u32, u32);
extern u32 func_0216D854(u32);
extern u32 func_0216D818(u32, u32);
extern u32 func_0216D86C(u32);
extern u32 func_0216D824(u32, u32);
extern u32 func_0216D848(u32, s16);
extern u32 func_0216D860(u32, s16);
extern u32 func_0216D87C(u32, s16);
extern u32 func_0216D568(u32, u32);
extern u32 func_02163F10(u32);
extern u32 func_0216D674(u32, u32);
extern u32 func_0216D7CC(u32);

int func_02199970(u32 a)
{
    State *p;
    Vec v;
    int t;
    int s;

    p = func_0216D6D4(a);
    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    switch (p->moveAxis) {
    case 0:
        v.x += p->speed;
        break;
    case 1:
        v.y += p->speed;
        break;
    case 2:
        v.z += p->speed;
        break;
    }
    func_0216D89C(a, &v);
    t = p->speed;
    if (t < 0)
        t = -t;
    p->accum += t;
    p->angle += p->step;
    if (p->angle > 0xF00)
        p->angle = 0xF00;
    {
    Vec w = { 0, 0, 0 };
    s = d_021DDBD4[1][(u16)(p->angle / 256)];
    if (p->negate == 1)
        s = -s;
    switch (p->axis) {
    case 0:
        w.x = s;
        break;
    case 1:
        w.y = s;
        break;
    case 2:
        w.z = s;
        break;
    }
    func_0216D8C0(a, &w);
    }
    p->count--;
    if (p->accum >= 0x10000 && p->count != 0) {
        int b;
        int dir;

        p->accum -= 0x10000;
        dir = 1;
        b = p->speed;
        func_0216D80C(a, func_0216D83C(a));
        func_0216D818(a, func_0216D854(a));
        func_0216D824(a, func_0216D86C(a));
        switch (p->moveAxis) {
        case 0:
            if (b < 0)
                dir = -1;
            func_0216D848(a, dir);
            break;
        case 1:
            if (b < 0)
                dir = -1;
            func_0216D860(a, dir * 2);
            break;
        case 2:
            if (b < 0)
                dir = -1;
            func_0216D87C(a, dir);
            break;
        }
    }
    if (p->count != 0)
        return 0;
    {
        Vec z = { 0, 0, 0 };
        func_0216D8C0(a, &z);
    }
    func_0216D568(a, 0x540);
    func_02163F10(a);
    func_0216D674(a, 0);
    func_0216D7CC(a);
    return 1;
}
