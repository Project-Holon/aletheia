/*
 * file:     unit_02073EE4.c
 * function: func_02073EE4
 * address:  0x02073EE4
 * packet:   pkt_02073BF0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_0214E9FC  0x0214E9FC  data
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


struct SndSystem { u32 initialized; u8 pad04[0x24 - 4]; u32 timerChannelMask; u32 timerCaptureMask; u32 timerAlarmNo; };
extern struct SndSystem g_0214E9FC;
extern void func_020894DC(u32, u32, u32, u32);
extern u32 func_02089D40(void);
extern void func_02089B38(u32);
extern void func_02089CD4(u32);
void func_02073EE4(void) {
    struct SndSystem *sndSystem = &g_0214E9FC;
    u32 alarmMask;
    u32 commandTag;
    if (sndSystem->initialized == 0) return;
    if ((int)sndSystem->timerAlarmNo >= 0) alarmMask = 1u << sndSystem->timerAlarmNo;
    else alarmMask = 0;
    func_020894DC(sndSystem->timerChannelMask, sndSystem->timerCaptureMask, alarmMask, 0);
    commandTag = func_02089D40();
    func_02089B38(1);
    func_02089CD4(commandTag);
}
