/*
 * function: WIFILOGIN_DISP_Draw
 * address: 0x021D4DF4
 * packet: pkt_ov115_021D4DF4
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte alignment padding, no follower.
 * symbols:
 *   WIFILOGIN_DISP_DrawActors 0x021D580C thumb ov115
 */
#include "../include/Obj03765.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void WIFILOGIN_DISP_DrawActors(u8 *);
void WIFILOGIN_DISP_Draw(u8 *p) { if(((struct Obj03765 *)p)->f8==1) WIFILOGIN_DISP_DrawActors(p); }
