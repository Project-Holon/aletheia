/*
 * function: STARTMENU_ConfigPromptDeleteWindows
 * address: 0x021BC84C
 * packet: pkt_ov088_021BC84C
 * region: ov088
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj02128.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void STARTMENU_ConfigPromptDeleteWindows(u8 *p) { u8 i; BMP_WIN_Delete(((struct Obj02128 *)p)->fC); for(i=0;i<2;i++) BMP_WIN_Delete(*(void **)((u32)p+((u32)i*4)+16)); }
