/*
 * function: BTL_CLIENT_StartWindowModeSend
 * address: 0x021CE044
 * packet: pkt_ov093_021CE044
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_CLIENT_PickWindowMode 0x021CDFE4 thumb ov093
 */
#include "../include/Obj07768.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 BTL_CLIENT_PickWindowMode(u32);
void BTL_CLIENT_StartWindowModeSend(u8 *p) { p[0xc4]=BTL_CLIENT_PickWindowMode(p[0xc4]); *(u8 * *)&((struct Obj07768 *)p)->fD8=p+0xc4; ((struct Obj07768 *)p)->fDC=1; }
