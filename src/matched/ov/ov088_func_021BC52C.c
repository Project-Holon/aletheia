/*
 * function: STARTMENU_ConfigPromptEnd
 * address: 0x021BC52C
 * packet: pkt_ov088_021BC52C
 * region: ov088
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STARTMENU_ConfigPromptDeleteWindows 0x021BC84C thumb ov088
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj02128.h"
typedef unsigned char u8;
extern void STARTMENU_ConfigPromptDeleteWindows(u8 *p);
extern unsigned int GF_FONT_Delete(void *ptr);
extern void BMP_WIN_Exit(void);
typedef unsigned int   u32;
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BG_SYS_Delete(void);
struct Proc;
extern void func_020315D4(struct Proc *a);
extern void GFL_HEAP_DeleteChecked(u32 a);
int STARTMENU_ConfigPromptEnd(int a,int b,int c,u8 *p) { STARTMENU_ConfigPromptDeleteWindows(p);GF_FONT_Delete((void *)(((struct Obj02128 *)p)->f8));BMP_WIN_Exit();BG_SYS_FreeLayerBuf(3);BG_SYS_FreeLayerBuf(1);BG_SYS_FreeLayerBuf(5);BG_SYS_Delete();func_020315D4((struct Proc *)a);GFL_HEAP_DeleteChecked(0x39);return 1; }
