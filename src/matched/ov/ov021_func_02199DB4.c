/*
 * function: func_02199DB4
 * address:  0x02199DB4
 * packet:   pkt_ov021_02199DB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0219FC68  0x0219FC68  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef struct { int x, y, z; } Vec;
typedef struct {
    int pos;
    int vel;
    u16 timer;
    u8  last;
} State;
extern State *func_0216D6D4(u32);
extern int func_0219FC68(u32, u16 *, u16 *);
extern u16 func_0216D598(void *p);
extern void func_020061E4(u32);
extern void func_0216D8C0(u32, Vec *);
extern void func_0216D674(void *p, u16 v);
extern void func_0216D7CC(u32);

int func_02199DB4(u32 a)
{
    State *p;
    u16 v[2];

    p = func_0216D6D4(a);
    if (func_0219FC68(a, &v[1], &v[0]) != 1)
        return 0;
    p->timer = p->timer + 1;
    v[0] = v[0] - 1;
    if (func_0216D598((void *)a) == 0xD3) {
        if (v[1] == 2 && p->last != v[0]) {
            p->last = v[0];
            switch (v[0]) {
            case 7:
            case 12:
            case 17:
                func_020061E4(0x7E5);
                break;
            case 10:
            case 15:
            case 20:
                func_020061E4(0x7E6);
                break;
            }
        }
    } else if (p->timer == 0x5F) {
        func_020061E4(0x7E7);
    }
    if (p->timer < 0x5F)
        return 0;
    p->pos += p->vel;
    {
        Vec w = { 0, 0, 0 };
        w.y = p->pos;
        func_0216D8C0(a, &w);
    }
    if (p->pos / 0x8000 < 16)
        return 0;
    func_0216D674((void *)a, 0);
    func_0216D7CC(a);
    return 1;
}
