/*
 * function: POKETRADE_DEMO_UP_SetupEmitterA
 * address:  0x021D4A34
 * packet:   pkt_ov118_021D4A34
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_DEMO_UP_UpdateEmitterA  0x021D49F4  thumb  ov118
 *   BUTTON_MAN_SetCallback  0x02051A24  arm  arm9
 *   BUTTON_MAN_SetUserData  0x02051A2C  arm  arm9
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern u32 func_02051774(void);
extern void BUTTON_MAN_SetUserData(void *p, int v);
extern void BUTTON_MAN_SetCallback(void *p, int v);
extern void POKETRADE_DEMO_UP_UpdateEmitterA(void *obj, int on);

void POKETRADE_DEMO_UP_SetupEmitterA(void *p)
{
    BUTTON_MAN_SetUserData(p, func_02051774());
    BUTTON_MAN_SetCallback(p, (int)POKETRADE_DEMO_UP_UpdateEmitterA);
}
