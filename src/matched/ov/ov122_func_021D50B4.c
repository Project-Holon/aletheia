/*
 * function: INTRUDE_COMM_VIEW_SetFoundPeerMac
 * address: 0x021D50B4
 * packet: pkt_ov122_021D50B4
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Two-byte zero alignment padding follows the compiled body.
 * symbols:
 *   GFL_NET_GetInitParam 0x0203D798 arm
 *   GFL_NET_GetScanResultMac 0x0203CF3C arm
 *   MI_CpuCopy8 0x02082D44 arm
 */
#include "../include/Obj13965.h"
#include "../include/Obj22932.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *GFL_NET_GetInitParam(void);extern void *GFL_NET_GetScanResultMac(u32);extern void MI_CpuCopy8(const void *,void *,u32);
void INTRUDE_COMM_VIEW_SetFoundPeerMac(char *p,u32 n) {void *q;GFL_NET_GetInitParam();q=GFL_NET_GetScanResultMac(n);((struct Obj22932 *)(*(char * *)&((struct Obj13965 *)p)->f344))->f10=2;MI_CpuCopy8(q,*(char * *)&((struct Obj13965 *)p)->f344+20,6);}
