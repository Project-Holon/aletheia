/*
 * function: BTL_MAIN_StoreClientVoiceFlag
 * address: 0x021BA698
 * packet: pkt_ov093_021BA698
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_GetRelativeClientIndex 0x021BA710 thumb ov093
 *   BTL_MAIN_GetClientVoiceFlag 0x021B997C thumb ov093
 */
#include "../include/Obj07743.h"

typedef unsigned char u8;
extern u8 BTL_MAIN_GetRelativeClientIndex(int, int);
extern int BTL_MAIN_GetClientVoiceFlag(u8 *p, unsigned int i);
void BTL_MAIN_StoreClientVoiceFlag(u8 *p, int k)
{
 int i;
 i = BTL_MAIN_GetRelativeClientIndex(p[0x46c], k);
 *((u8 *)(*(char * *)&((struct Obj07743 *)p)->f0 + i) + 0x44) = BTL_MAIN_GetClientVoiceFlag(p, k);
}
