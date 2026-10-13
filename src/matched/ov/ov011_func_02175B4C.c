/*
 * function: INTRUDE_COMM_AcceptSession
 * address:  0x02175B4C
 * packet:   pkt_ov011_02175B4C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRUDE_COMM_IsSessionActive  0x02175B14  thumb  ov011
 */

typedef unsigned char u8;

typedef struct Fl {
    u8 lo : 2;
    u8 x  : 1;
    u8 y  : 1;
    u8 hi : 4;
} Fl;

extern int INTRUDE_COMM_IsSessionActive(u8 *p);

void INTRUDE_COMM_AcceptSession(u8 *a, u8 *b)
{
    if (INTRUDE_COMM_IsSessionActive(b) == 1) {
        ((Fl *)(b + 0x1a5))->x = 1;
        ((Fl *)(b + 0x1a5))->y = 0;
        a[0x8a] |= 0x20;
        a[0x900] = 1;
    }
}
