/*
 * function: BTL_MAIN_IsRecordingActive
 * address: 0x021B90F8
 * packet: pkt_ov093_021B90F8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj13274.h"
#include "../include/Obj20977.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
int BTL_MAIN_IsRecordingActive(u8 *p) { u8 *q; q=*(u8 * *)&((struct Obj20977 *)p)->f0; if(((struct Obj13274 *)q)->f94!=0 && q[0x23]==0) return 1; return 0; }
