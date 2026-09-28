/*
 * function: func_0217F478
 * address:  0x0217F478
 * packet:   pkt_ov009_0217F478
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiDateToSeconds (gsplatformutil.o)
 *
 * symbols:
 *   _s32_div_f                     0x0209C0A4  arm
 *   func_0217F2C8                  0x0217F2C8  arm ov009
 *   g_021A3800                     0x021A3800  data
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

#define ChkAdd(dest, src1, src2) (((src1 >= 0L) && (src2 >= 0L) && (dest < 0L)) || ((src1 < 0L) && (src2 < 0L) && (dest >= 0L)))
#define ChkMul(dest, src1, src2) (src1 ? (dest / src1 != src2) : 0)

extern struct tm *func_0217F2C8(long *timp);
extern int g_021A3800[];

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
