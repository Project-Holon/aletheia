/*
 * function: ERROR_SCREEN_ShowAndWait
 * address:  0x021B6100
 * packet:   pkt_ov017_021B6100
 * region:   ov017
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Waits for A/B to be released, then pressed, reading the pad the way
 * PAD_Read does (KEYINPUT | the ARM7 XY buffer, inverted) with opposite
 * d-pad directions cancelled.
 *
 * symbols:
 *   APP_ENV_IsRunOnTwl  0x0202EB0C  thumb
 *   ERROR_SCREEN_Setup  0x021B61F8  thumb  ov017
 *   GFL_USE_PollPowerExit  0x020053EC  thumb
 *   func_02034F5C  0x02034F5C  arm
 *   ERROR_SCREEN_Teardown  0x021B641C  thumb  ov017
 */

typedef unsigned short u16;

typedef unsigned int   u32;
extern u32 APP_ENV_IsRunOnTwl(void);
extern void ERROR_SCREEN_Setup(int x);
extern void GFL_USE_PollPowerExit(void);
extern void func_02034F5C(void);
extern void ERROR_SCREEN_Teardown(void);

static inline u16 ReadKeys(void)
{
    u16 k = (u16)(((*(volatile u16 *)0x04000130 | *(volatile u16 *)0x02FFFFA8) ^ 0x2FFF) & 0x2FFF);
    k = (u16)(k & ~((k & 0x40) << 1) & ~((k & 0x20) >> 1));
    return k;
}

void ERROR_SCREEN_ShowAndWait(void)
{
    ERROR_SCREEN_Setup(APP_ENV_IsRunOnTwl() ? 0x2A : 0x10);
    while (ReadKeys() & 3) {
        GFL_USE_PollPowerExit();
        func_02034F5C();
    }
    while (!(ReadKeys() & 3)) {
        GFL_USE_PollPowerExit();
        func_02034F5C();
    }
    ERROR_SCREEN_Teardown();
}
