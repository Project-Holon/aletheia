/*
 * file:     btl_calc.c
 * unit:     yes
 * function: func_021D7840, func_021D787C, func_021D7894, func_021D78AC, func_021D78E4, func_021D7908, func_021D7930
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
 *   d_021F3AB8 0x021F3AB8 data a1
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   data_021F6360  0x021F6360  data  ov093
 *   d_021F0448 0x021F0448 data a1
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021F0462 0x021F0462 data a1
 *   _s32_div_f 0x0209C0A4 arm
 *   d_021F041C 0x021F041C data a1
 *   func_021D78AC 0x021D78AC thumb ov093
 */
#include "btl_calc_types.h"

extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern u32 func_020307B0(void *p);
extern unsigned int _u32_div_f(unsigned int, unsigned int);
void func_021D7840(const BtlRngState *rng, unsigned int heapId);
void func_021D787C(const BtlRngState *rng);
void func_021D7894(void);
u32 func_021D78AC(u32 range);
unsigned short func_021D78E4(unsigned short stat, int stage);
extern struct BtlCalcWork data_021F6360;
extern const unsigned char d_021F3AB8[];
extern unsigned char d_021F0448[][2];
extern int _s32_div_f(int numerator, int denominator);
extern const u8 d_021F0462[][2];
extern const u8 d_021F041C[];


void func_021D7840(const BtlRngState *rng, unsigned int heapId) { data_021F6360.workTable=func_02030734(heapId,0x460,1,(const char *)d_021F3AB8,0x50); data_021F6360.rng=*rng; }


void func_021D787C(const BtlRngState *rng) { data_021F6360.rng = *rng; }


void func_021D7894(void) { if (data_021F6360.workTable) { func_020307B0(data_021F6360.workTable); data_021F6360.workTable = 0; } }


u32 func_021D78AC(u32 range)
{
    struct BtlCalcWork *work = &data_021F6360;
    u32 value;

    work->rng.seed = work->rng.mul * work->rng.seed + work->rng.add;
    if (range == 0) {
        value = (u32)(work->rng.seed >> 32);
    } else {
        value = (u32)(((work->rng.seed >> 32) * range) >> 32);
    }
    return value;
}


unsigned short func_021D78E4(unsigned short stat, int stage) { return _u32_div_f((unsigned short)(stat*d_021F0448[stage][0]), d_021F0448[stage][1]); }

/* Scales accuracy by the ratio of an accuracy stage (numerator, denominator); the result is at most 100. */
u8 func_021D7908(int accuracy, int stage)
{
    u32 scaled = _s32_div_f(accuracy * d_021F0462[stage][0], d_021F0462[stage][1]);
    if (scaled > 100) scaled = 100;
    return scaled;
}

/* A critical hit lands when a roll below the stage's range comes up 0. */
int func_021D7930(int critStage)
{
    if ((u8)func_021D78AC(d_021F041C[critStage]) == 0) return 1;
    return 0;
}
