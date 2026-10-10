/*
 * function: func_0689D15C
 * address: 0x0689D15C
 * packet: pkt_ov095_0689D15C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/ov095/unit_0689D0FC.c and filed here.
 */

typedef unsigned char u8;

/* One 0x31-byte slot: a count, 24 flag bytes, 24 value bytes (31 = unset). */
typedef struct {
    u8 n;
    u8 a[24];
    u8 b[24];
} Slot;

void func_0689D15C(Slot *s, u8 v)
{
    u8 *q;

    if (s->n < 24) {
        q = (u8 *)s + s->n;
        q[25] = v;
        q[1] = 0;
        s->n++;
    }
}
