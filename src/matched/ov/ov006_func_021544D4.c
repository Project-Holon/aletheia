/*
 * function: EVENT_WIFICLUB_ResetSound
 * address: 0x021544D4
 * packet: pkt_ov006_021544D4
 * region: ov006
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two bytes of alignment padding at 0x021544EE.
 * symbols:
 *   GFL_USE_SetPlayerVolumes 0x02005CBC thumb
 *   PM_VOICE_SetMasterVolume 0x02006734 thumb
 */
#include "../include/Obj18631.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void GFL_USE_SetPlayerVolumes(u32 value, u32 mask);
extern void PM_VOICE_SetMasterVolume(u8 volume);
void EVENT_WIFICLUB_ResetSound(u8 *p)
{
    GFL_USE_SetPlayerVolumes(127, 63);
    PM_VOICE_SetMasterVolume(127);
    ((struct Obj18631 *)p)->fAC = 1;
}
