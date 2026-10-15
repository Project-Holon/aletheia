/*
 * function: gsiSecondsToDate
 * address:  0x0217F2C8
 * packet:   pkt_ov009_0217F2C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiSecondsToDate (gsplatformutil.o)
 *
 * symbols:
 *   gGsTimeBuffer                     0x021AD164  data
 *   gGsMonthDaysLeap                     0x021A37CC  data
 *   gGsMonthDays                     0x021A3800  data
 */

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

extern struct tm gGsTimeBuffer;
extern int gGsMonthDaysLeap[];
extern int gGsMonthDays[];

/*
 * The whole-day count is read into its own long before tm_mon is stored
 * (permuter lead): computing it inline in the tm_wday statement colours
 * ptb into r3 instead of lr.
 */
struct tm *gsiSecondsToDate(long *timp)
{
    long caltim = *timp;
    long alldays;
    int islpyr = 0;
    int tmptim;
    int *mdays;
    struct tm *ptb = &gGsTimeBuffer;

    if (caltim < 0)
        return 0;

    tmptim = (int)(caltim / (1461L * 86400L));
    caltim -= (long)tmptim * (1461L * 86400L);
    tmptim = (tmptim * 4) + 70;

    if (caltim >= 365L * 86400L) {
        tmptim++;
        caltim -= 365L * 86400L;
        if (caltim >= 365L * 86400L) {
            tmptim++;
            caltim -= 365L * 86400L;
            if (caltim >= 366L * 86400L) {
                tmptim++;
                caltim -= 366L * 86400L;
            } else {
                islpyr++;
            }
        }
    }

    ptb->tm_year = tmptim;
    ptb->tm_yday = (int)(caltim / 86400L);
    caltim -= (long)ptb->tm_yday * 86400L;

    if (islpyr)
        mdays = gGsMonthDaysLeap;
    else
        mdays = gGsMonthDays;

    for (tmptim = 1; mdays[tmptim] < ptb->tm_yday; tmptim++)
        ;

    alldays = *timp / 86400L;
    ptb->tm_mon = --tmptim;
    ptb->tm_mday = ptb->tm_yday - mdays[tmptim];
    ptb->tm_wday = ((int)alldays + 4) % 7;
    ptb->tm_hour = (int)(caltim / 3600);
    caltim -= (long)ptb->tm_hour * 3600L;
    ptb->tm_min = (int)(caltim / 60);
    ptb->tm_sec = (int)(caltim - ptb->tm_min * 60);
    ptb->tm_isdst = 0;
    return ptb;
}
