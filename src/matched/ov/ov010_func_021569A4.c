/*
 * function: func_021569A4
 * address:  0x021569A4
 * packet:   pkt_ov010_021569A4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Index of the member's best score slot, or 4 on a tie for the best.
 * 2026-10-05 (wave P20): the loop counter is set before the member load
 * (i = 0; then for (; ...)). That gives the w->party temporary the
 * register the image uses (r6, shared with m). Earlier drafts set i in the
 * for-init and stayed 2 bytes out.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

typedef struct Member {
    u8 pad00[0x4A];
    u16 total;          /* 0x4A */
    u16 score[4];       /* 0x4C */
} Member;

typedef struct Party {
    u32 f00;
    Member *members[4]; /* 0x04 */
} Party;

typedef struct Work {
    u8 pad00[0x30];
    Party *party;       /* 0x30 */
} Work;

u8 func_021569A4(Work *w, u8 idx)
{
    u8 best;
    u8 i;
    u8 max;
    u8 tie;
    Member *m;

    max = 0;
    best = 0;
    tie = 0;
    i = 0;
    m = w->party->members[idx];
    for (; i < 4; i++) {
        if (max < m->score[i]) {
            tie = 0;
            best = i;
            max = m->score[i];
        } else if (max == m->score[i]) {
            tie = 1;
        }
    }
    if (tie == 1)
        best = 4;
    return best;
}
