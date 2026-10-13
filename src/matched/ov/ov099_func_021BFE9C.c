/*
 * function: func_021BFE9C
 * address: 0x021BFE9C
 * packet: pkt_ov099_021BFE9C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 */
#include "../include/Obj00008.h"
extern int func_021BA928(void *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned int,unsigned int);
int func_021BFE9C(char *p,int ret) {
 if (!func_021BA928(p)) return ret;
 if (--((struct Obj00008 *)p)->f1E0<0) {
  GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),18,10);
  ((struct Obj00008 *)p)->f1CC=147;
 }
 return ret;
}
