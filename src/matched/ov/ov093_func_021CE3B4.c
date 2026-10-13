/*
 * function: BTL_CLIENT_ShowMessage
 * address: 0x021CE3B4
 * packet: pkt_ov093_021CE3B4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_CORE_BuildAndPrintMessage 0x021EA614 thumb ov093
 */
#include "../include/Obj13356.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct H;
extern void BTLV_CORE_BuildAndPrintMessage(char *p, struct H *h);
void BTL_CLIENT_ShowMessage(u8 *p, void *q) { BTLV_CORE_BuildAndPrintMessage(((struct Obj13356 *)p)->f54,q); p[0x120]=1; }
