/*
 * function: EVENTDATA_SYSTEM_IsConnectRailHit
 * address:  0x02162E00
 * packet:   pkt_ov010_02162E00
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

typedef unsigned short u16;
typedef short s16;

struct Sub {
    u16 f0;
    u16 f2;
    s16 f4;
    u16 f6;
    u16 f8;
};

struct Box {
    u16 pad0[3];
    u16 f6;
    struct Sub s;
};

struct Q {
    u16 f0;
    u16 pad2;
    s16 f4;
    u16 f6;
};

int EVENTDATA_SYSTEM_IsConnectRailHit(struct Box *b, struct Q *q)
{
    struct Sub *s;
    if (b->f6 == 0)
        return 0;
    s = &b->s;
    if (s->f0 == q->f0 && s->f2 <= q->f6 && s->f2 + s->f6 > q->f6
        && s->f4 <= q->f4 && s->f4 + s->f8 > q->f4)
        return 1;
    return 0;
}
