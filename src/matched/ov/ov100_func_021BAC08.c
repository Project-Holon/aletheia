/*
 * function: IRCBATTLEMATCH_ExitScreen
 * address: 0x021BAC08
 * packet: pkt_ov100_021BAC08
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   IRCBATTLEMATCH_FreeMessageWindows 0x021BA5F4 thumb ov100
 *   func_02040DA8 0x02040DA8 arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   func_020403F4 0x020403F4 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_02040588 0x02040588 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   IRCBATTLEMATCH_ExitWindowSystem 0x021BA640 thumb ov100
 */
#include "../include/Obj05267.h"
typedef unsigned int   u32;
struct Rec;
struct TaskMenuState;
struct U16Vec;
extern void GF_FONT_SetDefaultTextColor(void);
extern void IRCBATTLEMATCH_FreeMessageWindows(unsigned a);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void func_020403F4(u32 i);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_02040588(unsigned char which, unsigned char enable);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void IRCBATTLEMATCH_ExitWindowSystem(int);
void IRCBATTLEMATCH_ExitScreen(int a) {
 GF_FONT_SetDefaultTextColor();
 IRCBATTLEMATCH_FreeMessageWindows(a);
 func_02040DA8(5,1,0);
 {
  unsigned int v=((struct Obj05267 *)a)->f304;
  unsigned int w=v>>16;
  BG_SYS_DeleteHalf(5,(unsigned short)v,(unsigned short)w);
 }
 func_020403F4(5);
 MSGDATA_Delete((struct Rec *)(((struct Obj05267 *)a)->f288));
 GF_FONT_Delete((void *)(((struct Obj05267 *)a)->f290));
 STRBUF_Delete((struct U16Vec *)(((struct Obj05267 *)a)->f294));
 STRBUF_Delete((struct U16Vec *)(((struct Obj05267 *)a)->f298));
 func_02040588(5,0);
 APP_TASKMENU_RES_Delete((struct TaskMenuState *)(((struct Obj05267 *)a)->fCC4));
 IRCBATTLEMATCH_ExitWindowSystem(a);
}
