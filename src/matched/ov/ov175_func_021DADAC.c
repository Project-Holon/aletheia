/*
 * function: WIFIBATTLEMATCH_NET_GetReportState
 * address: 0x021DADAC
 * packet: pkt_ov175_021DADAC
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 */
#include "../include/Obj24330.h"
typedef unsigned char u8;
typedef unsigned int u32;
u32 WIFIBATTLEMATCH_NET_GetReportState(u8 *p) { return ((struct Obj24330 *)p)->f150; }
