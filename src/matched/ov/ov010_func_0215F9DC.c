/*
 * function: EVENT_GAMECLEAR_AdvanceStep
 * address:  0x0215F9DC
 * packet:   pkt_ov010_0215F9DC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Advance the step counter and load the next step from the sequence.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Work {
    u8 pad00[0x34];
    u32 step;           /* 0x34 */
    u32 seq[1];         /* 0x38 */
} Work;

void EVENT_GAMECLEAR_AdvanceStep(Work *w, u32 *i)
{
    (*i)++;
    w->step = w->seq[*i];
}
