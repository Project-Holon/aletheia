/*
 * function: func_02162C84
 * address:  0x02162C84
 * packet:   pkt_ov010_02162C84
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02162C54  0x02162C54  thumb  ov010
 *   func_02162AA4  0x02162AA4  thumb  ov010
 */

typedef unsigned short u16;
typedef short s16;

struct Sub {
    s16 f0;
    s16 f2;
    s16 f4;
    u16 f6;
    u16 f8;
};

struct Box {
    u16 pad0[4];
    struct Sub s;
};

typedef unsigned char  u8;
extern int func_02162C54(u8 *p);
extern u16 func_02162AA4(int q, int m, int a, int b, u16 n);

void func_02162C84(struct Box *b, int q, int *out)
{
    struct Sub *s = &b->s;
    int m = func_02162C54((u8 *)b);
    out[0] = b->s.f0 << 12;
    out[1] = s->f2 << 12;
    out[2] = s->f4 << 12;
    if (s->f6 > 1) {
        out[0] += func_02162AA4(q, m, 0, 0, s->f6) << 16;
    } else if (s->f8 > 1) {
        out[2] += func_02162AA4(q, m, 0, 0, s->f8) << 16;
    }
}
