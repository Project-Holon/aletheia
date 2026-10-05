/*
 * function: func_0200E518
 * address:  0x0200E518
 * packet:   pkt_0200E518
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Folds two arrays of pending increments into their saturating totals and
 * clears the increments: 30 u16 into u32 totals capped at 999999, then 150
 * u8 into u16 totals capped at 9999.  Seeded in layout/function_starts.txt
 * from its only caller, the bl at ov010 0x02169056 (w6_fix18).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Tally {
    u16 add16[30];      /* 0x000 */
    u8 add8[150];       /* 0x03C */
    u8 pad[10];         /* 0x0D2 */
    u32 total32[30];    /* 0x0DC */
    u16 total16[150];   /* 0x154 */
} Tally;

void func_0200E518(Tally *t)
{
    int i;

    for (i = 0; i < 30; i++) {
        t->total32[i] += t->add16[i];
        if (t->total32[i] > 999999) {
            t->total32[i] = 999999;
        }
        t->add16[i] = 0;
    }
    for (i = 0; i < 150; i++) {
        t->total16[i] += t->add8[i];
        if (t->total16[i] > 9999) {
            t->total16[i] = 9999;
        }
        t->add8[i] = 0;
    }
}
