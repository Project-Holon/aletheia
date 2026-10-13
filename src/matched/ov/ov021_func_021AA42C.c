/*
 * function: FIELD_ENCOUNT_CheckWfbcRoll
 * address:  0x021AA42C
 * packet:   pkt_ov021_021AA42C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_ENCOUNT_GetStepCount  0x021AA778  thumb  ov021
 *   FIELD_WFBC_GetPeopleNum  0x021938F4  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 *   func_0207C7B4  0x0207C7B4  arm
 *   _ll_mul        0x0209C054  arm
 *   GPOWER_ApplyEncountRate  0x02010FB0  thumb
 */

typedef long long fx64;
typedef int fx32;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 FIELD_ENCOUNT_GetStepCount(u8 *p);
extern int FIELD_WFBC_GetPeopleNum(unsigned char *p);
extern u32 func_020056EC(u32 range);
extern fx32 func_0207C7B4(fx32 x);
extern u32 GPOWER_ApplyEncountRate(u32 v);

static inline fx32 FX_MUL(fx32 v1, fx32 v2)
{
    return (fx32)(((fx64)v1 * v2 + 0x800LL) >> 12);
}

int FIELD_ENCOUNT_CheckWfbcRoll(void *a, void *b)
{
    int n = FIELD_ENCOUNT_GetStepCount(a);
    int m = FIELD_WFBC_GetPeopleNum(b);
    int rnd = func_020056EC(100);
    fx32 sq = func_0207C7B4(m << 12);
    fx32 t = FX_MUL((n - 1) << 12, sq);

    t = FX_MUL(t, 0x4000);
    return (int)GPOWER_ApplyEncountRate((int)(t >> 12)) > rnd;
}
