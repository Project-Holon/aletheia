/*
 * function: FIELD_ENCOUNT_CheckEncountRoll
 * address:  0x021AA3FC
 * packet:   pkt_ov021_021AA3FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   FIELD_ENCOUNT_RandRatePercent  0x021AA6E0  thumb
 *   FIELD_ENCOUNT_GetStepCount  0x021AA778  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 FIELD_ENCOUNT_GetStepCount(u8 *p);
extern u32 FIELD_ENCOUNT_RandRatePercent(void);

int FIELD_ENCOUNT_CheckEncountRoll(void *a0, void *p, u32 rate)
{
    u32 r;

    if (rate > 100)
        rate = 100;
    r = FIELD_ENCOUNT_GetStepCount(p);
    if (r == 0)
        return 0;
    if (r == 1)
        rate = 1;
    if (FIELD_ENCOUNT_RandRatePercent() <= rate)
        return 1;
    return 0;
}
