/*
 * function: GSYNC_MESSAGE_RestartTimeIcon
 * address: 0x021D5A7C
 * packet: pkt_ov123_021D5A7C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 */
#include "../include/Obj04497.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
extern void TIME_ICON_Delete(u8 *p);
extern u8 *TIME_ICON_CreateNode(u32,void *,u8,u8,u16);
void GSYNC_MESSAGE_RestartTimeIcon(char *p){if(((struct Obj04497 *)p)->f7C){TIME_ICON_Delete(((struct Obj04497 *)p)->f7C);((struct Obj04497 *)p)->f7C=0;}((struct Obj04497 *)p)->f7C=TIME_ICON_CreateNode(((struct Obj04497 *)p)->f84,((struct Obj04497 *)p)->f44,15,16,((struct Obj04497 *)p)->fB0);}
