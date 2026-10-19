/*
 * function: APP_POWER_HaltWithMessage
 * address:  0x0202F788
 * packet:   pkt_0202F788
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * time_icon.c: the power callback reached from APP_POWER_ClearCallback as
 * APP_POWER_HaltWithMessage(0) (and registered through the pool word 0x0202F789 at
 * 0x0202F784).  disasm.py carried it as .word data until it was seeded in
 * layout/function_starts.txt.  It never returns: after the shutdown work it
 * spins on GFL_USE_PollPowerExit.
 *
 * symbols:
 *   func_02007084  0x02007084  thumb
 *   APP_POWER_ShowShutdownScreen  0x0202F7C4  thumb
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_ClearExitFlag  0x0203CF04  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_IRC_WIRELESS_Exit  0x0203D0D0  arm
 *   GFL_NET_Main  0x0203CF5C  arm
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   UI_ClearSoftResetInhibitGlobal  0x020351A0  arm
 *   GFL_USE_PollPowerExit  0x020053EC  thumb
 */

typedef unsigned int u32;

extern void func_02007084(void);
extern void APP_POWER_ShowShutdownScreen(u32 mode);
extern int  GFL_NET_GetRunState(void);
extern void GFL_NET_ClearExitFlag(void);
extern int GFL_NET_Exit(int a0);
extern void GFL_NET_IRC_WIRELESS_Exit(void);
extern u32 GFL_NET_Main(void);
extern int  GFL_NET_IsSessionNull(void);
extern int UI_ClearSoftResetInhibitGlobal(u32 v);
extern void GFL_USE_PollPowerExit(void);

void APP_POWER_HaltWithMessage(u32 mode)
{
    func_02007084();
    APP_POWER_ShowShutdownScreen(mode);
    if (GFL_NET_GetRunState()) {
        GFL_NET_ClearExitFlag();
        GFL_NET_Exit(0);
        GFL_NET_IRC_WIRELESS_Exit();
        do {
            GFL_NET_Main();
        } while (!GFL_NET_IsSessionNull());
    }
    UI_ClearSoftResetInhibitGlobal(2);
    for (;;)
        GFL_USE_PollPowerExit();
}
