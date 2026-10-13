/*
 * function: ISS_SWITCH_SYS_TurnOn
 * address:  0x0202C1D4
 * packet:   pkt_0202C1D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ISS_SWITCH_SYS_ChangeActiveSet  0x0202C29C  thumb
 *   ISS_SWITCH_SYS_UpdateVolume  0x0202C2C0  thumb
 *   ISS_SWITCH_SYS_GetPlayingBgm  0x0202C2D0  thumb
 *   ISS_SWITCH_SYS_IsOn  0x0202C2D8  thumb
 *   ISS_SWITCH_SYS_ResetActiveSet  0x0202C2DC  thumb
 */
#include "../include/Obj15848.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 ISS_SWITCH_SYS_IsOn(u32 *p);
extern u32  ISS_SWITCH_SYS_GetPlayingBgm(u32 v);
extern int ISS_SWITCH_SYS_ChangeActiveSet(u32 *p, u32 v);
extern void ISS_SWITCH_SYS_ResetActiveSet(void *p);
extern void ISS_SWITCH_SYS_UpdateVolume(void *p);

void ISS_SWITCH_SYS_TurnOn(u8 *p)
{
    if (ISS_SWITCH_SYS_IsOn((u32 *)p) == 1) {
        return;
    }
    ((struct Obj15848 *)p)->f0 = 1;
    if (ISS_SWITCH_SYS_ChangeActiveSet((u32 *)p, ISS_SWITCH_SYS_GetPlayingBgm(1)) != 1) {
        return;
    }
    ISS_SWITCH_SYS_ResetActiveSet(p);
    ISS_SWITCH_SYS_UpdateVolume(p);
}
