/*
 * unit:     yes
 * function: GFL_USE_IsNetQuiet, GFL_USE_HBlankHandler
 * address:  0x020051D8
 * packet:   pkt_020051D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_NET_SYSTEM_GetConnectNum  0x020392B8  arm
 *   GFL_NET_IsNetTypeBeacon  0x0203D26C  arm
 *   GFL_NET_IsNetTypeWifi  0x0203D29C  arm
 *   GFL_USE_RunHBlankTasks   0x02005610  thumb
 *
 * Boot path, 0x020051D8..0x0200520C: a three-step readiness test (each
 * step its own early `return 0`, per the image's four epilogues) and the
 * unlabelled forwarding thunk GFL_USE_HBlankHandler to GFL_USE_RunHBlankTasks
 * (src/matched/unit_0200560C.c), a pool-word tail call.
 *
 * Rewritten wave 16 from src/pending/GFL_USE_IsNetQuiet.c, a one-line generated
 * body with implicit declarations that was EXACT* on its own.
 * Integrator: seed 0x02005204 (unlabelled follower, member of this unit).
 */

extern int GFL_NET_SYSTEM_GetConnectNum(void);
typedef unsigned int   u32;
extern u32 GFL_NET_IsNetTypeBeacon(void);
extern u32 GFL_NET_IsNetTypeWifi(void);
extern void GFL_USE_RunHBlankTasks(void);

int GFL_USE_IsNetQuiet(void)
{
    if (GFL_NET_SYSTEM_GetConnectNum() > 1)
        return 0;
    if (GFL_NET_IsNetTypeBeacon() != 0)
        return 0;
    if (GFL_NET_IsNetTypeWifi() == 0)
        return 1;
    return 0;
}

void GFL_USE_HBlankHandler(void)
{
    GFL_USE_RunHBlankTasks();
}
