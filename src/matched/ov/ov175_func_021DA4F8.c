/*
 * function: func_021DA4F8
 * address:  0x021DA4F8
 * packet:   pkt_021DA4F8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DWC_GetMatchIntValue  0x0216CB30  arm
 *   _s32_div_f            0x0209C0A4  arm
 *
 * Matchmaking evaluation callback: reads the candidate's keys 3..6; a candidate with none of them scores 0, one whose key 4 differs from ours scores 0, otherwise 1000 less the key 3 distance and 32 times the distance between the two key5*50/(key6+5) ratios, floored at 0.
 */
#include "../include/Obj08280.h"

typedef unsigned char u8;
typedef unsigned long u32;

extern int DWC_GetMatchIntValue(int index, const char *key, int idefault);

int func_021DA4F8(int index, void *param)
{
    char *p = param;
    int b, a, c, d;
    int q1, q2, da, dq, score;

    a = DWC_GetMatchIntValue(index, p + 0xee, -1);
    b = DWC_GetMatchIntValue(index, p + 0x106, -1);
    c = DWC_GetMatchIntValue(index, p + 0x112, -1);
    d = DWC_GetMatchIntValue(index, p + 0xfa, -1);

    if (a == -1 && b == -1 && d == -1 && c == -1)
        return 0;
    if (d == ((struct Obj08280 *)p)->fF4) {
        q1 = b * 50 / (c + 5);
        q2 = ((struct Obj08280 *)p)->f100 * 50 / (((struct Obj08280 *)p)->f10C + 5);
        da = a - ((struct Obj08280 *)p)->fE8;
        if (da < 0)
            da = -da;
        dq = q1 - q2;
        if (dq < 0)
            dq = -dq;
        score = 1000 - da - dq * 32;
        if (score < 0)
            return 0;
        return score;
    }
    return 0;
}
