/*
 * function: func_021F0B88
 * address:  0x021F0B88
 * packet:   pkt_ov029_021F0B88
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _s32_div_f     0x0209C0A4  arm
 *   _u32_div_f     0x0209C2B0  arm
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

extern void func_021F0C00(Ent *p, int t);

void func_021F0B88(Ent *p)
{
    unsigned int q;
    int t;

    if (p->on) {
        p->cnt = p->cnt + 1;
        q = p->cnt / p->f2;
        t = 0;
        if (q >= 5) {
            q = 4 - q % 5;
            if (q == p->f5)
                p->on = 0;
        }
        if (q < 5) {
            if (p->cnt % p->f2 == 0)
                t = 1;
        }
        if (t)
            func_021F0C00(p, q);
    }
}
