/*
 * function: IRCBATTLEMATCH_RecvMacAddressHandler
 * address: 0x021B9950
 * packet: pkt_ov100_021B9950
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow the return.
 * lever: pointer declared before counter; zero counter assigned before pointer base.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   GF_STANDARD_CompareBytes 0x0203EFC8 arm
 */
#include "../include/Obj22071.h"
typedef unsigned char u8;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern unsigned GFL_NET_IsParentAid(void);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);
void IRCBATTLEMATCH_RecvMacAddressHandler(int a,int b,void *c,int d,int e)
{
 u8 *p;
 int i;
 if(e == (int)GFL_NET_HANDLE_GetCurrentHandle()) {
  if(GFL_NET_IsParentAid() != 0) {
   i=0;
   p = (u8 *)(d+0x260);
   for(;i<4;i++) {
    if(GF_STANDARD_CompareBytes(p+i*6,c,6)==0) {
     *(u8 *)(((struct Obj22071 *)d)->f244+a+0x18)=i;
     return;
    }
   }
  }
 }
}
