/*
 * function: EVENTDATA_SYSTEM_IsConnectGridHit
 * address: 0x02162D2C
 * packet: pkt_ov010_02162D2C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * following: two-byte alignment padding at 02162D8E.
 * lever: assign the Sub pointer before the position loads; signed x0 has
 * the field's s16 width. Bounded permuter first closed this spelling.
 */
typedef unsigned short u16;
typedef short s16;
struct Sub { s16 f0, f2, f4; u16 f6, f8; };
struct Box { u16 pad0[3]; u16 f6; struct Sub s; };
int EVENTDATA_SYSTEM_IsConnectGridHit(const struct Box *b, const int *pos)
{
    const struct Sub *s;
    s16 x0;
    int z;
    int y;
    int x;
    if ((int)(b->f6 == 1)) return 0;
    s = &b->s;
    x = pos[0] >> 12;
    y = pos[1] >> 12;
    z = pos[2] >> 12;
    x0 = b->s.f0;
    if (x0 <= x && x0 + (s->f6 - 1) * 16 >= x
        && s->f2 - 2 <= y && s->f2 + 2 >= y
        && s->f4 <= z && s->f4 + (s->f8 - 1) * 16 >= z)
        return 1;
    return 0;
}
