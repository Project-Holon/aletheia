/*
 * function: BTLV_GAUGE_StepValue
 * address:  0x02207F6C
 * packet:   pkt_ov094_02207F6C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;

int BTLV_GAUGE_StepValue(int n, int target, int delta, int *cur, u8 x, int speed)
{
    u8 lim;
    int t;
    int v;
    int d;

    lim = x * 8;
    if (*cur == (int)0x80000000) {
        if (n < lim)
            *cur = target << 8;
        else
            *cur = target;
    }
    t = target - delta;
    if (t < 0)
        t = 0;
    else if (t > n)
        t = n;
    if (n < lim) {
        if (t == (*cur >> 8) && (*cur & 0xff) == 0)
            return -1;
    } else if (t == *cur) {
        return -1;
    }
    if (n < lim) {
        d = (n << 8) / lim;
        if (delta < 0) {
            *cur += d;
            v = *cur >> 8;
            if (v >= t || speed == 0) {
                *cur = t << 8;
                return t;
            }
        } else {
            *cur -= d;
            v = *cur >> 8;
            if ((*cur & 0xff) > 0)
                v++;
            if (v <= t || speed == 0) {
                *cur = t << 8;
                return t;
            }
        }
    } else {
        if (delta < 0) {
            *cur += speed;
            if (*cur > t || speed == 0)
                *cur = t;
        } else {
            *cur -= speed;
            if (*cur < t || speed == 0)
                *cur = t;
        }
        v = *cur;
    }
    return v;
}
