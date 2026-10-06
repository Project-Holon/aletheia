/*
 * function: func_02162BCC
 * address:  0x02162BCC
 * packet:   pkt_ov010_02162BCC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02162C54  0x02162C54  thumb  ov010
 */

typedef unsigned short u16;
typedef short s16;

struct Sub {
    u16 f0;
    u16 f2;
    s16 f4;
    u16 f6;
    u16 f8;
    u16 fa;
};

struct Box {
    u16 pad0[4];
    struct Sub s;
};

struct Q {
    u16 pad0[2];
    s16 f4;
    u16 f6;
};

typedef unsigned char  u8;
extern int func_02162C54(u8 *p);

u16 func_02162BCC(struct Box *b, struct Q *q)
{
    struct Sub *s = &b->s;
    int a = 0;
    int c = 0;
    int m = func_02162C54((u8 *)b);
    int d;
    switch (s->fa) {
    case 0:
        a = 1;
        break;
    case 1:
        c = 1;
        break;
    case 2:
        a = 1;
        c = 1;
        break;
    case 3:
        break;
    }
    if (s->f8 > 1) {
        d = q->f4 - s->f4;
        if (c != 0)
            d = s->f8 - 1 - d;
        return (s->f8 << 4) | d | (m << 8);
    }
    if (s->f6 > 1) {
        d = q->f6 - s->f2;
        if (a != 0)
            d = s->f6 - 1 - d;
        return (s->f6 << 4) | d | (m << 8);
    }
    return 0x10 | (m << 8);
}
