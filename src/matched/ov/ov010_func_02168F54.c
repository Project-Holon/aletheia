/*
 * function: FIELD_CLOCK_CalcElapsed
 * address:  0x02168F54
 * packet:   pkt_ov010_02168F54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RTC_ConvertDateTimeToSecond  0x02089004  arm
 *   RTC_ConvertDateToDay  0x02088F58  arm
 *   _ll_sdiv       0x0209BE5C  arm
 */

typedef unsigned int u32;
typedef long long s64;

typedef struct { u32 a, b, c, d; } Date;
typedef struct { u32 a, b, c; } Time;

typedef struct {
    int f0;
    Date date;
    Time time;
    int f20;
} A;

typedef signed int     s32;
struct RTCDate;
struct RTCTime;
extern long long RTC_ConvertDateTimeToSecond(struct RTCDate *date, struct RTCTime *time);
extern s32 RTC_ConvertDateToDay(struct RTCDate *date);

int FIELD_CLOCK_CalcElapsed(A *a, Date *b, Time *c, int *d, int *e)
{
    s64 sa = RTC_ConvertDateTimeToSecond((struct RTCDate *)(&a->date), (struct RTCTime *)(&a->time));
    s64 sb = RTC_ConvertDateTimeToSecond((struct RTCDate *)b, (struct RTCTime *)c);
    int day = RTC_ConvertDateToDay((struct RTCDate *)b);
    int q;
    *d = 0;
    *e = 0;
    if (sb < sa) {
        a->date = *b;
        a->time = *c;
        a->f20 = day;
        return 0;
    }
    q = (int)((sb - sa) / 60);
    if (q > 0) {
        int dd;
        *e = q;
        a->date = *b;
        a->time = *c;
        dd = day - a->f20;
        if (dd != 0) {
            *d = dd;
            a->f20 = day;
        }
    }
    return 1;
}
