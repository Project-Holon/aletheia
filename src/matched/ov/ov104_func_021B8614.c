/*
 * function: IRC_RHYTHM_IsRecordFull
 * address: 0x021B8614
 * packet: pkt_ov104_021B8614
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj22229.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
int IRC_RHYTHM_IsRecordFull(u8 *p) { if(((struct Obj22229 *)p)->f78>=10) return 1; return 0; }
