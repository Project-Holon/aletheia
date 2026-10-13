/*
 * function: func_021DEC84
 * address: 0x021DEC84
 * packet: pkt_ov137_021DEC84
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 */
#include "../include/Obj10619.h"
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Entry;
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void TIME_ICON_Delete(u8 *p);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, u32 lo, u32 hi);
int func_021DEC84(char *p) {void *v;v=GFL_NET_HANDLE_GetCurrentHandle();TIME_ICON_Delete(((struct Obj10619 *)p)->fDA8);((struct Obj10619 *)p)->fDA8=0;GFL_NET_HANDLE_SetTimingSyncRange(v,202,40);((struct Obj10619 *)p)->f0=11;return 0;}
