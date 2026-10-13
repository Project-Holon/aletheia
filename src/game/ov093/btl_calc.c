/*
 * file:     btl_calc.c
 * unit:     yes
 * function: BTL_CALC_Init, BTL_CALC_SetRngState, BTL_CALC_Exit, BTL_CALC_Random, BTL_CALC_ApplyStatStage, BTL_CALC_ApplyAccuracyStage, BTL_CALC_RollCriticalHit
 * address:  0x021D7840
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Battle calculation: the random number state and work table, the accuracy
 * stage scale and the stat stage scale.
 *
 * symbols:
 *   gBtlCalcFileName 0x021F3AB8 data a1
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   gBtlCalcWork  0x021F6360  data  ov093
 *   gBtlStatStageRatios 0x021F0448 data a1
 *   _u32_div_f 0x0209C2B0 arm
 *   gBtlCalcAccuracyStageRatios 0x021F0462 data a1
 *   _s32_div_f 0x0209C0A4 arm
 *   gBtlCalcCriticalRanges 0x021F041C data a1
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 */
#include "btl_calc_types.h"

extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern u32 func_020307B0(void *p);
extern unsigned int _u32_div_f(unsigned int, unsigned int);
void BTL_CALC_Init(const BtlRngState *rng, unsigned int heapId);
void BTL_CALC_SetRngState(const BtlRngState *rng);
void BTL_CALC_Exit(void);
u32 BTL_CALC_Random(u32 range);
unsigned short BTL_CALC_ApplyStatStage(unsigned short stat, int stage);
extern struct BtlCalcWork gBtlCalcWork;
extern const unsigned char gBtlCalcFileName[];
extern unsigned char gBtlStatStageRatios[][2];
extern int _s32_div_f(int numerator, int denominator);
extern const u8 gBtlCalcAccuracyStageRatios[][2];
extern const u8 gBtlCalcCriticalRanges[];


void BTL_CALC_Init(const BtlRngState *rng, unsigned int heapId) { gBtlCalcWork.workTable=func_02030734(heapId,0x460,1,(const char *)gBtlCalcFileName,0x50); gBtlCalcWork.rng=*rng; }


void BTL_CALC_SetRngState(const BtlRngState *rng) { gBtlCalcWork.rng = *rng; }


void BTL_CALC_Exit(void) { if (gBtlCalcWork.workTable) { func_020307B0(gBtlCalcWork.workTable); gBtlCalcWork.workTable = 0; } }


u32 BTL_CALC_Random(u32 range)
{
    struct BtlCalcWork *work = &gBtlCalcWork;
    u32 value;

    work->rng.seed = work->rng.mul * work->rng.seed + work->rng.add;
    if (range == 0) {
        value = (u32)(work->rng.seed >> 32);
    } else {
        value = (u32)(((work->rng.seed >> 32) * range) >> 32);
    }
    return value;
}


unsigned short BTL_CALC_ApplyStatStage(unsigned short stat, int stage) { return _u32_div_f((unsigned short)(stat*gBtlStatStageRatios[stage][0]), gBtlStatStageRatios[stage][1]); }

/* Scales accuracy by the ratio of an accuracy stage (numerator, denominator); the result is at most 100. */
u8 BTL_CALC_ApplyAccuracyStage(int accuracy, int stage)
{
    u32 scaled = _s32_div_f(accuracy * gBtlCalcAccuracyStageRatios[stage][0], gBtlCalcAccuracyStageRatios[stage][1]);
    if (scaled > 100) scaled = 100;
    return scaled;
}

/* A critical hit lands when a roll below the stage's range comes up 0. */
int BTL_CALC_RollCriticalHit(int critStage)
{
    if ((u8)BTL_CALC_Random(gBtlCalcCriticalRanges[critStage]) == 0) return 1;
    return 0;
}
