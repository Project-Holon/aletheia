/*
 * file:     unit_0217F2C8_p01.c
 * unit:     yes
 * function: func_0217F2C8, func_0217F478, func_0217F730, func_0217F774, func_0217F790
 * address:  0x0217F2C8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021AD164                     0x021AD164  data
 *   g_021A37CC                     0x021A37CC  data
 *   g_021A3800                     0x021A3800  data
 *   _s32_div_f                     0x0209C0A4  arm
 *   g_021A37C8  0x021A37C8  data
 */
#define ChkAdd(dest, src1, src2) (((src1 >= 0L) && (src2 >= 0L) && (dest < 0L)) || ((src1 < 0L) && (src2 < 0L) && (dest >= 0L)))
#define ChkMul(dest, src1, src2) (src1 ? (dest / src1 != src2) : 0)
#define RANa         16807
#define LONGRAND_MAX 2147483647L
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

long func_0217F478(struct tm *tb);
int func_0217F730(long seed);
void func_0217F774(void);
void func_0217F790(unsigned int v);
extern struct tm g_021AD164;
extern int g_021A37CC[];
extern int g_021A3800[];
extern char g_021A37C8[];


/*
 * The whole-day count is read into its own long before tm_mon is stored
 * (permuter lead): computing it inline in the tm_wday statement colours
 * ptb into r3 instead of lr.
 */
/*
 * sdk:      gsiSecondsToDate (gsplatformutil.o)
 */
struct tm *func_0217F2C8(long *timp)
{
    long caltim = *timp;
    long alldays;
    int islpyr = 0;
    int tmptim;
    int *mdays;
    struct tm *ptb = &g_021AD164;

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
        mdays = g_021A37CC;
    else
        mdays = g_021A3800;

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


/*
 * sdk:      gsiDateToSeconds (gsplatformutil.o)
 */
long func_0217F478(struct tm *tb)
{
    long tmptm1;
    long tmptm2;
    long tmptm3;

    if (((tmptm1 = tb->tm_year) < 69) || (tmptm1 > 139))
        return -1;

    if ((tb->tm_mon < 0) || (tb->tm_mon > 11)) {
        tmptm1 += (tb->tm_mon / 12);
        if ((tb->tm_mon %= 12) < 0) {
            tb->tm_mon += 12;
            tmptm1--;
        }
        if ((tmptm1 < 69) || (tmptm1 > 139))
            return -1;
    }

    tmptm2 = g_021A3800[tb->tm_mon];
    if (!(tmptm1 & 3) && (tb->tm_mon > 1))
        tmptm2++;

    tmptm3 = (tmptm1 - 70) * 365L + ((tmptm1 - 1L) >> 2) - 17;
    tmptm3 += tmptm2;
    tmptm1 = tmptm3 + (tmptm2 = (long)(tb->tm_mday));
    if (ChkAdd(tmptm1, tmptm3, tmptm2))
        return -1;

    tmptm2 = tmptm1 * 24L;
    if (ChkMul(tmptm2, tmptm1, 24L))
        return -1;
    tmptm1 = tmptm2 + (tmptm3 = (long)tb->tm_hour);
    if (ChkAdd(tmptm1, tmptm2, tmptm3))
        return -1;

    tmptm2 = tmptm1 * 60L;
    if (ChkMul(tmptm2, tmptm1, 60L))
        return -1;
    tmptm1 = tmptm2 + (tmptm3 = (long)tb->tm_min);
    if (ChkAdd(tmptm1, tmptm2, tmptm3))
        return -1;

    tmptm2 = tmptm1 * 60L;
    if (ChkMul(tmptm2, tmptm1, 60L))
        return -1;
    tmptm1 = tmptm2 + (tmptm3 = (long)tb->tm_sec);
    if (ChkAdd(tmptm1, tmptm2, tmptm3))
        return -1;

    {
        struct tm *tbtemp;
        if ((tbtemp = func_0217F2C8(&tmptm1)) == 0)
            return -1;
        *tb = *tbtemp;
    }
    return tmptm1;
}


/*
 * nextlongrand: one step of the GameSpy Park-Miller LCG (multiplier 16807,
 * modulus 2**31-1), written in 16-bit halves so the product fits a 32-bit
 * register.  The two `if (lo > LONGRAND_MAX)` folds are the compiler's
 * `(x & 0x7fffffff) + (x >> 31)` reduction, emitted as cmn/bic/addhi.
 *
 * Reached from longrand (0x0217F774) <- Util_RandInt (0x0217F7AC) <-
 * gpiEncodeString.
 */
int func_0217F730(long seed)
{
    unsigned long lo, hi;

    lo = RANa * (unsigned long)(seed & 0xFFFF);
    hi = RANa * ((unsigned long)seed >> 16);
    lo += (hi & 0x7FFF) << 16;
    if (lo > LONGRAND_MAX) {
        lo &= LONGRAND_MAX;
        ++lo;
    }
    lo += hi >> 15;
    if (lo > LONGRAND_MAX) {
        lo &= LONGRAND_MAX;
        ++lo;
    }
    return (int)lo;
}


/*
 * Refreshes the word the state object holds.
 */
void func_0217F774(void)
{
    *(int *)g_021A37C8 = func_0217F730(*(int *)g_021A37C8);
}


/*
 * probe
 */
void func_0217F790(unsigned int v)
{
    *(int *)g_021A37C8 = v ? (int)(v & 0x7fffffff) : 1;
}
