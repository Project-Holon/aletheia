/*
 * function: func_021D9BC4
 * address: 0x021D9BC4
 * packet: pkt_ov119_021D9BC4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9B84 0x021D9B84 thumb ov119
 */
#include "../include/Obj00001.h"
extern int func_021E12AC(char *p);
extern int func_021D8A24(void *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern void func_021D8E84(void *,int);
extern void func_021D9B84(void *);
void func_021D9BC4(char *p) {
 if(func_021E12AC(p) && ((struct Obj00001 *)p)->fF2C>30) {
  if(func_021D8A24(p)) GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),20,8);
  func_021D8E84(p,(int)func_021D9B84);
 }
}
