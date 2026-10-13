/*
 * function: func_021DF168
 * address: 0x021DF168
 * packet: pkt_ov119_021DF168
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: field p+0x11fa re-read at 0x021DF18E after store at 0x021DF18C.
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_021E4888 0x021E4888 thumb ov119
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   WIPE_ResetBrightness 0x02022230 thumb
 *   func_021D89CC 0x021D89CC thumb ov119
 *   func_021D9434 0x021D9434 thumb ov119
 *   func_021DF0B8 0x021DF0B8 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 */
#include "../include/Obj13901.h"
typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);
extern void func_021E4888(char *p);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void WIPE_ResetBrightness(u32 which);
extern void func_021D89CC(char *p);
extern void func_021D9434(void *);
extern void func_021DF0B8(char *p);
extern void func_021D8E84(void *,int);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void func_02039C68(struct Link *,unsigned,unsigned);
void func_021DF168(void *p) {
 if(WIPE_SYS_EndCheck()) {
  func_021E4888(p);BG_SYS_SetSubVisiblePlanes(4);WIPE_ResetBrightness(4);
  ++*(volatile unsigned char *)&((struct Obj13901 *)p)->f11FA;
  if(*(volatile unsigned char *)&((struct Obj13901 *)p)->f11FA>=3) {func_021D89CC(p);func_021D8E84(p,(int)func_021D9434);return;}
  func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),31,8);func_021D8E84(p,(int)func_021DF0B8);
 }
}
