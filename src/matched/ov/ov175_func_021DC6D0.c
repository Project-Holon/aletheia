/*
 * function: WIFIBATTLEMATCH_NET_NdCancelState
 * address: 0x021DC6D0
 * packet: pkt_ov175_021DC6D0
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DWC_NdCancelAsync 0x021C5DB4 arm ov114
 *   d_021E4B80 0x021E4B80 data a4
 */
#include "../include/Obj10692.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 d_021E4B80[];
extern int DWC_NdCancelAsync(void);
void WIFIBATTLEMATCH_NET_NdCancelState(u8 *p,int state) { d_021E4B80[0]=0; *(u32 *)(d_021E4B80+4)=0; ((struct Obj10692 *)p)->f130=state; ((struct Obj10692 *)p)->f12C=300; if(DWC_NdCancelAsync()==0) ((struct Obj10692 *)p)->f130=state; }
