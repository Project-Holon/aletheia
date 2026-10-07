/*
 * file:     unit_0217D3AC_p01.c
 * unit:     yes
 * function: func_0217D3AC, func_0217D3F8, func_0217D448, func_0217D4D8
 * address:  0x0217D3AC
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
 *   current_time_hires               0x0217f28c arm
 *   gTimers                          0x021ad064 data
 */
#include "../../matched/include/G_GSLintTimer.h"

typedef unsigned int u32;

struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
};

extern unsigned int current_time_hires(void);
int func_0217D448(const u32 *a, u32 n, const u32 *b, u32 m);
extern struct GSLintTimer gTimers[9];


static void gsiLargeIntTimerEnter(int id)
{
    if (gTimers[id].started == 0)
    {
        gTimers[id].entries++;
        gTimers[id].start = current_time_hires();
        gTimers[id].started = 1;
    }
}


static void gsiLargeIntTimerExit(int id)
{
    if (gTimers[id].started == 1)
    {
        gTimers[id].total += current_time_hires() - gTimers[id].start;
        gTimers[id].started = 0;
    }
}


/*
 * Big-number vector compare.  Both operands are little-endian limbs with the
 * length given separately; trailing zero limbs are trimmed off each operand
 * first, then the trimmed lengths decide, then the limbs are walked from the
 * top.  -1 / 1 / 0 as usual.
 */
int func_0217D448(const u32 *a, u32 n, const u32 *b, u32 m)
{
    while (a[n - 1] == 0 && n != 0)
        n--;
    while (b[m - 1] == 0 && m != 0)
        m--;
    if (n < m)
        return -1;
    if (n > m)
        return 1;
    while (n != 0) {
        if (a[n - 1] < b[n - 1])
            return -1;
        if (a[n - 1] > b[n - 1])
            return 1;
        n--;
    }
    return 0;
}


static int gsiLargeIntStripLeadingZeroes(struct gsLargeInt_s * lint)
{
    while (lint->mLength != 0 && lint->mData[lint->mLength - 1] == 0)
        lint->mLength--;

    return 1;
}
