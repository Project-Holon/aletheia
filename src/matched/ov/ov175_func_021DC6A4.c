/*
 * function: WIFIBATTLEMATCH_NET_NdCleanupState
 * address: 0x021DC6A4
 * packet: pkt_ov175_021DC6A4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DWC_NdCleanupAsync 0x021C5B80 arm ov114
 *   d_021E4B80 0x021E4B80 data a4
 */
#include "../include/Obj10691.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 d_021E4B80[];
extern int DWC_NdCleanupAsync(void);
void WIFIBATTLEMATCH_NET_NdCleanupState(u8 *p,int state) { d_021E4B80[0]=0; *(u32 *)(d_021E4B80+4)=0; ((struct Obj10691 *)p)->f130=state; ((struct Obj10691 *)p)->f12C=200; if(DWC_NdCleanupAsync()==0) ((struct Obj10691 *)p)->f130=state; }
