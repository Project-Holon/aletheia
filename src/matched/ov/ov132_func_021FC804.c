/*
 * function: MUS_COMM_FUNC_SetHostFlag
 * address: 0x021FC804
 * packet: pkt_ov132_021FC804
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_IsParentAid 0x0203D378 arm
 */
#include "../include/Obj14125.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor; struct Comm;
extern u32 GFL_NET_IsParentAid(void);
void MUS_COMM_FUNC_SetHostFlag(char *p) { if(GFL_NET_IsParentAid()==1) ((struct Obj14125 *)p)->f48=1; else ((struct Obj14125 *)p)->f48=2; }
