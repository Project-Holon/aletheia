/*
 * function: func_021FC81C
 * address: 0x021FC81C
 * packet: pkt_ov132_021FC81C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   d_021FDC38 0x021FDC38 data a4
 */
#include "../include/Obj14126.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern void GFL_NET_COMMAND_AddCommandTable(u32,u32,u32,u32);
extern u32 GFL_NET_IsParentAid(void);
extern char d_021FDC38[];
void func_021FC81C(char *p) { GFL_NET_COMMAND_AddCommandTable(0x1100,(u32)d_021FDC38,9,(u32)p); if(GFL_NET_IsParentAid()==1) ((struct Obj14126 *)p)->f48=1; else ((struct Obj14126 *)p)->f48=2; }
