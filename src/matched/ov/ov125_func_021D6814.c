/*
 * function: GDS_RAP_RequestDownloadEntries
 * address: 0x021D6814
 * packet: pkt_ov125_021D6814
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GDS_RAP_IsIdle 0x021D730C thumb ov125
 */
#include "../include/Obj02838.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GDS_RAP_IsIdle(char *);
int GDS_RAP_RequestDownloadEntries(char *p,int v) {if(!GDS_RAP_IsIdle(p))return 0;*(u16 *)&((struct Obj02838 *)p)->f3A4=v;((struct Obj02838 *)p)->f3D8=0x5209;return 1;}
