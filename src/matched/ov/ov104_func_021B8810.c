/*
 * function: IRC_RHYTHM_OnRecordReceived
 * address: 0x021B8810
 * packet: pkt_ov104_021B8810
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two zero bytes of alignment padding follow the return.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
#include "../include/Obj22233.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
void IRC_RHYTHM_OnRecordReceived(int a,int b,int c,u8 *p,int e) { if(e==(int)GFL_NET_HANDLE_GetCurrentHandle() && a!=GFL_NET_SYSTEM_GetCurrentAid()) ((struct Obj22233 *)p)->f194=1; }
