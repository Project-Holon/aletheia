/*
 * function: func_021D8FE4
 * address: 0x021D8FE4
 * packet: pkt_ov119_021D8FE4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   func_02082D44 0x02082D44 arm
 */
#include "../include/Obj10353.h"
typedef unsigned char u8;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_GetHandleNetID(struct Link *p);
typedef unsigned int   u32;
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void func_02082D44(void *,void *,int);
void func_021D8FE4(int idx,int a,int b,void *p,int id) {
 if(id==(int)GFL_NET_HANDLE_GetCurrentHandle()) {
 int n=POKE_TOOL_GetPartyParamSize();
 func_02082D44(*(void **)((char *)p+idx*4+0x1064),*(void **)((char *)p+idx*4+0x5dc),n);
 if(idx!=GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) {
 ((struct Obj10353 *)p)->fF9C=idx+1;
 ((struct Obj10353 *)p)->f11FB=(((struct Obj10353 *)p)->f11FB&~0xf0)|0x10;
 }
 }
}
