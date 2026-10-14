/*
 * function: GDS_RAP_RequestSearchKind3
 * address: 0x021D69B4
 * packet: pkt_ov125_021D69B4
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GDS_RAP_IsIdle 0x021D730C thumb ov125
 */
#include "../include/Obj14006.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GDS_RAP_IsIdle(char *);
int GDS_RAP_RequestSearchKind3(char *p) {if(!GDS_RAP_IsIdle(p))return 0;((struct Obj14006 *)p)->f3E0=3;((struct Obj14006 *)p)->f3D8=0x55f1;return 1;}
