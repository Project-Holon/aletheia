/*
 * function: BTL_CLIENT_AttachRemoteLink
 * address: 0x021CD938
 * packet: pkt_ov093_021CD938
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Prototype: 021D3F48 stores only r1 low16; caller forwards full getter
 * result without truncation, so its extern argument is widened to u32.
 * symbols:
 *   BTL_REC_CountFlaggedRecords 0x021EE830 thumb ov093
 *   BTL_CLIENT_SetCounterMaximum 0x021D3F48 thumb ov093
 */
#include "../include/Obj13353.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 BTL_REC_CountFlaggedRecords(void *);
extern void BTL_CLIENT_SetCounterMaximum(u8 *,u32);
void BTL_CLIENT_AttachRemoteLink(u8 *p,void *a) { p[0x1a7]=2; ((struct Obj13353 *)p)->f14=a; BTL_CLIENT_SetCounterMaximum(p+0x18,BTL_REC_CountFlaggedRecords(a)); }
