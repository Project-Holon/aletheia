/*
 * function: FRAME_LIST_UpdateHoldStage
 * address:  0x021B83A0
 * packet:   pkt_ov067_021B83A0
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The counter is re-read after the guard, inside the arm and after the
 * store: a volatile field; the chain then works on one local copy.
 */

typedef unsigned char u8;

typedef struct S {
    u8 pad[0x94];
    volatile u8 cnt;
    u8 idx;
} S;

void FRAME_LIST_UpdateHoldStage(S *p)
{
    u8 v;
    if (p->cnt < 20) {
        p->cnt = p->cnt + 1;
    }
    v = p->cnt;
    if (v == 20) {
        p->idx = 0;
    } else if (v >= 16) {
        p->idx = 1;
    } else if (v >= 12) {
        p->idx = 2;
    } else if (v >= 8) {
        p->idx = 3;
    } else if (v >= 4) {
        p->idx = 4;
    } else {
        p->idx = 5;
    }
}
