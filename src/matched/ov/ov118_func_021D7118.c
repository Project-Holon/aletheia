/*
 * function: func_021D7118
 * address:  0x021D7118
 * packet:   pkt_ov118_021D7118
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_3D_AddUnitAndInit  0x021E3208  thumb  ov119
 *   POKETRADE_DEMO_MIDDLE_UpdateScene  0x021D7130  thumb  ov118
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void POKETRADE_3D_AddUnitAndInit(void *p, int a);
extern void POKETRADE_DEMO_MIDDLE_UpdateScene(u8 *p);

void func_021D7118(u8 *p)
{
    POKETRADE_3D_AddUnitAndInit(p, 3);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_MIDDLE_UpdateScene);
}
