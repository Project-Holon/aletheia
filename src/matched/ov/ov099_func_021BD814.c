/*
 * function: WIFICLUB_StateResetNetOptions
 * address: 0x021BD814
 * packet: pkt_ov099_021BD814
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 */
#include "../include/Obj13692.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
int WIFICLUB_StateResetNetOptions(char *p, int v)
{
    int zero = 0;
    GFL_NET_SetAutoExit(zero);
    GFL_NET_SetLoginOption(zero);
    ((struct Obj13692 *)p)->f1E0 = zero;
    ((struct Obj13692 *)p)->f1CC = 0x91;
    return v;
}
