/*
 * function: func_0203F540
 * address:  0x0203F540
 * packet:   pkt_0203F540
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   tbl_020A08B6   0x020A08B6  data  a2
 *   func_02088F58  0x02088F58  arm
 *
 * Blocking class: NONE AVAILABLE.  Every concrete byte of the body and of
 * the pool reproduces (MATCH*, 0 concrete bytes out).  The one unresolved
 * site is the ABS32 at +0xB4 naming the cumulative-days table at
 * 0x020A08B6, and it cannot be attested by any of the eight classes:
 *
 *   - `literal` / `label`: the pool word at 0x0203F5F4 is the ONLY reference
 *     to 0x020A08B6 anywhere in the image (layout/data_objects.txt line 475
 *     lists three referrers, but all three are the same 0x0203F5F4 word seen
 *     through three alternative unit cuts of the same listing), and it lies
 *     inside the compared range.  --suggest-split confirms: "witnesses image
 *     wide: 1, of them inside this range: 1", best partition 0 pieces.
 *   - every `sole-ref` sub-kind: 0x020A08B6 is HALFWORD aligned.
 *     `in_data_section()` in tools/match.py works at word granularity and
 *     returns False for it (it returns True for 0x020A08B4 and 0x020A08B8),
 *     so guard (a) of sole-ref/data and sole-ref/self both refuse before
 *     the ROM-word check is ever reached.  Rebasing the declaration to the
 *     4-aligned 0x020A08B4 and indexing [month + 1] is not a way out: it
 *     would put a different word in the pool and break the byte match, and
 *     guard (b) of sole-ref/self correctly refuses the claim because the
 *     ROM word at the site names 0x020A08B6, not 0x020A08B4.
 *
 * This promotes to EXACT with no change to the C the moment anything else
 * in the image is found to reference 0x020A08B6, or once a halfword-aligned
 * data start is recognised by the layout.
 *
 * WHAT IT IS.  Day-of-year from an RtcDate: the cumulative days before the
 * month out of the halfword table, plus the day, plus one if the month is
 * March or later and the year is a leap year.  It then copies the date to a
 * stack temp with month and day forced to 1 and runs func_02088F58 over
 * that temp and over the caller's date (the normalise/weekday pass), and
 * returns the day-of-year.
 *
 * Two typing details are load-bearing:
 *
 *   - `month` is UNSIGNED.  The guard at +0x28 is `blo`, not `blt`; with a
 *     signed `month` the whole function is otherwise identical and exactly
 *     one byte differs.
 *   - `year` is SIGNED.  All three divisions (by 4, 100 and 400) are the
 *     signed shapes: the `lsr ip, r0, #0x1f` sign words, the
 *     `rsb/adds ... ror #30` pair for %4, and the 0x51EB851F magic reused at
 *     `asr #5` for /100 and `asr #7` for /400.
 *
 * The leap test is ONE expression, `(y%4==0 && y%100!=0) || y%400==0`; note
 * the %4 failure path branches INTO the %400 test rather than around it,
 * which is the shared-exit tail-merge the disjunction gives.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0203F540.c \
 *       --func func_0203F540 --addr 0x0203F540 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct RtcDate {
    s32 year;
    u32 month;
    s32 day;
    s32 week;
};

extern u16 tbl_020A08B6[];

struct RTCDate;
extern s32 func_02088F58(struct RTCDate *date);

s32 func_0203F540(struct RtcDate *d)
{
    struct RtcDate t;
    s32 n = d->day + tbl_020A08B6[d->month];

    if (d->month >= 3) {
        if ((d->year % 4 == 0 && d->year % 100 != 0)
            || d->year % 400 == 0) {
            n++;
        }
    }

    t = *d;
    t.month = 1;
    t.day = 1;
    func_02088F58((struct RTCDate *)(&t));
    func_02088F58((struct RTCDate *)d);
    return n;
}
