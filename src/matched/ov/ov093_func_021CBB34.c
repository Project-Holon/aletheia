/*
 * function: BTL_SERVER_FLOW_CalcCaptureShakes
 * address: 0x021CBB34
 * packet: pkt_ov093_021CBB34
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: A u16 mode homes its spill early; named u16 form avoids an
 * argument copy. Ternary count selection shares the flag read across
 * the preceding threshold branch and settles the register allocation.
 * symbols:
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 *   BTL_MAIN_CheckSetupStatusFlag 0x021BA1A8 thumb ov093
 *   BTL_SERVER_FLOW_GetCaptureDexFactor 0x021CBCF4 thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   POKE_TOOL_GetPersonalParam 0x02019C90 thumb
 *   BTL_SERVER_FLOW_GetBallCatchRate 0x021CBD48 thumb ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex 0x021D62A8 thumb ov093
 *   GPOWER_ApplyCaptureRate 0x020111BC thumb
 *   BTL_SERVER_FLOW_RollCriticalCapture 0x021CBEA8 thumb ov093
 *   FX_Div 0x0207C768 arm
 *   FX_Sqrt 0x0207C7B4 arm
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   _u32_div_f 0x0209C2B0 arm
 */
#include "../include/Obj09980.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed long long s64;
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
struct QF;
struct Unk021D62A8;
extern int BTL_MAIN_CheckSetupStatusFlag(char **p, int m);
extern u32 BTL_SERVER_FLOW_GetCaptureDexFactor(u8 *p);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern u32 POKE_TOOL_GetPersonalParam(u16 a, u16 b, u32 k);
extern int BTL_SERVER_FLOW_GetBallCatchRate(u8 *, void *, void *, int);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern int GPOWER_ApplyCaptureRate(int);
extern int BTL_SERVER_FLOW_RollCriticalCapture(u8 *p, int x);
extern int FX_Div(int, int);
extern int FX_Sqrt(int);
extern u32 BTL_CALC_Random(u32);
int BTL_SERVER_FLOW_CalcCaptureShakes(u8 *p, void *q, void *m, u16 mode, u8 *out, u8 *flag)
{
    u32 a, t;
    int rate, factor, v;
    u32 count, i;
    u16 species, form;
    *flag = 0;
    if (mode == 1) { *out = 3; return 1; }
    a = BTL_POKEPARAM_GetValue((void *)m, 14) * 3;
    t = a - BTL_POKEPARAM_GetValue((void *)m, 13) * 2;
    v = (int)(t != 0 ? 0.5f + (float)(t << 12) : (float)(t << 12) - 0.5f);
    if (BTL_MAIN_CheckSetupStatusFlag(((struct Obj09980 *)p)->f4, 32)) {
        factor = BTL_SERVER_FLOW_GetCaptureDexFactor(p);
        v = ((s64)v * factor + 0x800) >> 12;
    }
    species = BTL_POKEPARAM_GetSpecies((void *)m);
    form = BTL_POKEPARAM_GetValue((void *)m, 19);
    v *= (u16)POKE_TOOL_GetPersonalParam(species, form, 8);
    factor = BTL_SERVER_FLOW_GetBallCatchRate(p, q, (void *)m, mode);
    v = ((s64)v * factor + 0x800) >> 12;
    v = (u32)v / a;
    switch (BTL_POKEPARAM_GetMajorStatusIndex((void *)m)) {
    case 2: case 3: v = ((s64)v * 0x2800 + 0x800) >> 12; break;
    case 1: case 4: case 5: v = ((s64)v * 0x1800 + 0x800) >> 12; break;
    }
    rate = GPOWER_ApplyCaptureRate(v);
    *flag = BTL_SERVER_FLOW_RollCriticalCapture(p, rate);
    if (rate >= 0xff000) { *out = *flag ? 1 : 3; return 1; }
    count = *flag ? 1 : 3;
    rate = FX_Div(0x10000000, FX_Sqrt(FX_Sqrt(FX_Div(0xff000, rate)))) >> 12;
    *out = 0;
    for (i = 0; i < count; i++) {
        if (BTL_CALC_Random(0x10000) < (u32)rate) (*out)++;
        else return 0;
    }
    return 1;
}
