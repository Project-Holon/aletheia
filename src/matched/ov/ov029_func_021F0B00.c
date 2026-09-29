/*
 * function: func_021F0B00
 * address:  0x021F0B00
 * packet:   pkt_ov029_021F0B00
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     `t = 0` must come first: set after the stores, the third parameter stays in r2
 *           instead of moving to r1 at entry (27 bytes out).
 *
 * symbols:
 *   func_021F0C70  0x021F0C70  thumb  ov029
 *   func_021F1290  0x021F1290  thumb  ov029
 *   func_021F0C00  0x021F0C00  thumb  ov029
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    u16 on  : 1;
    u16 cnt : 15;
    u16 f2;
    u8  f4;
    u8  f5;
    u8  f6;
    u8  f7;
} Ent;

extern u8 func_021F0C70(void *q, int a, int b, int c);
extern void func_021F1290(void *q, int a, int b, int c);
extern void func_021F0C00(Ent *p, int t);

void func_021F0B00(Ent *p, void *q, int a, int mode, int c, u16 d)
{
    int t;

    t = 0;
    p->f4 = a;
    p->cnt = 0;
    p->on = 1;
    p->f2 = d;
    if (mode == 0) {
        p->f5 = 0;
    } else if (mode == 1) {
        p->f5 = 4;
    } else if (mode == 2) {
        p->f5 = func_021F0C70(q, a, p->f6, p->f7);
        p->cnt = d * 5;
        t = 4;
    }
    func_021F1290(q, p->f6, p->f7, c);
    func_021F0C00(p, t);
}
