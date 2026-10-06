/*
 * function: func_021B3018
 * address: 0x021B3018
 * packet: pkt_ov013_021B3018
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * note 2026-10-06 (integrator): volatile f0 fields accepted by the user (f0 is a flag shared with the mic callback).
 * lever: the f0 flag words of both state structs are volatile. Two volatile stores keep their order
 *   against each other, which places the d_021B3C50 pool load after the first d_021B4C2C store.
 *   All 120 plain store orders stay at 2 B or more; int/unsigned/pointer types and chained stores
 *   do not move the load. The same declarations bring the sibling 021B3084 from 17 to 15 B off.
 * note pass 2 2026-10-06 P2L01: closed (EXACT in --lang c99 and --lang c). Earlier forms in the
 *   pending header (G2L8, G10L10, P21 L6) stayed at 2 to 6 B.
 * symbols:
 *   d_021B4C38 0x021B4C38 data a4
 *   d_021B4C2C 0x021B4C2C data a4
 *   d_021B3C50 0x021B3C50 data a4
 */
typedef int s32;
typedef unsigned int u32;

typedef struct VadCfg { volatile u32 f0; u32 f4; s32 f8; } VadCfg;
typedef struct VadState { volatile u32 f0; u32 f4; s32 f8; } VadState;

extern u32 d_021B4C38[];
extern VadState d_021B4C2C;
extern VadCfg d_021B3C50;

void func_021B3018(void)
{
    int i;
    for (i = 0; i < 4; i++) d_021B4C38[i] = 0x1000000;
    d_021B4C2C.f4 = 0;
    d_021B4C2C.f0 = 0;
    d_021B3C50.f0 = 0;
    d_021B3C50.f4 = 0;
    d_021B4C2C.f8 = 0;
}
