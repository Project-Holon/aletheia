/*
 * function: func_021A5880
 * address:  0x021A5880
 * packet:   pkt_ov021_021A5880
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_021A395C  0x021A395C  thumb  ov021
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216E0AC  0x0216E0AC  thumb  ov010
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_0219E2C0  0x0219E2C0  thumb  ov021
 *   func_021A6B88  0x021A6B88  thumb  ov021
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A3CB0  0x021A3CB0  thumb  ov021
 *   func_021A3CE8  0x021A3CE8  thumb  ov021
 *   d_021DDF04     0x021DDF04  data  a4
 *   d_021DDEE0     0x021DDEE0  data  a4
 *   d_021DDEE0b    0x021DDEE0  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern char d_021DDF04;
extern u16  d_021DDEE0[2];
extern u16  d_021DDEE0b[2];

extern u8 *func_02030734(int heap, int size, int a, void *file, int line);
extern int func_021A395C(u8 *p);
extern void *func_021A3960(unsigned char *p);
extern int func_0216D5A0(void *o);
extern u16 func_0216D598(void *o);
extern void func_0216E0AC(void *o, void *d);
extern int func_0219E348(void *o);
extern void func_0219E2C0(void *o, u16 *v);
extern void func_021A6B88(u8 *p);
extern int func_021A3974(u8 *p);
extern void func_021A3CB0(u8 *p, int v);
extern void func_021A3CE8(u8 *p);

static void clr4(u16 *q)
{
    q[0] = 0;
    q[1] = 0;
    q[2] = 0;
    q[3] = 0;
}

u8 *func_021A5880(u8 *obj, int heap)
{
    u8 *p;

    p = func_02030734(heap, 0x24, 1, &d_021DDF04, 0x1a0);
    *(u8 **)(p + 0x14) = obj;
    *(int *)(p + 0x18) = func_021A395C(obj);
    *(void **)(p + 0x1c) = func_021A3960(*(u8 **)(p + 0x14));
    if (func_0216D5A0(*(void **)(p + 0x1c)) != 0x45) {
        d_021DDEE0[1] = func_0216D598(*(void **)(p + 0x1c));
        func_0216E0AC(*(void **)(p + 0x1c), d_021DDEE0b);
    }
    *(int *)(p + 0x20) = func_0219E348(*(void **)(p + 0x1c));
    {
        u16 v[4] = {0, 0, 0, 0};
        func_0219E2C0(*(void **)(p + 0x1c), v);
    }
    func_021A6B88(p + 0xc);
    {
        int t = func_021A3974(*(u8 **)(p + 0x14));
        switch (t) {
        case 2:
            func_021A3CB0(*(u8 **)(p + 0x14), 4);
            func_021A3CE8(*(u8 **)(p + 0x14));
            break;
        case 3:
            func_021A3CB0(*(u8 **)(p + 0x14), 0x100);
            func_021A3CE8(*(u8 **)(p + 0x14));
            break;
        }
    }
    return p;
}
