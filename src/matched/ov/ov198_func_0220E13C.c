/*
 * unit: no
 * function: B_PLIST_DRAW_ClearAndPrintStream
 * address: 0x0220E13C
 * packet: pkt_ov198_0220E13C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   B_PLIST_DRAW_PrintStream 0x0220E168 thumb ov198
 */
#include "../include/Obj02247.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct CharBuf;extern void BMP_MENUWORK_DrawWindow(void *,int,int,int);extern void *BMP_WIN_GetBmp(struct Descriptor *);extern void BMP_Clear(struct CharBuf *,u8);extern void B_PLIST_DRAW_PrintStream(char *);
void B_PLIST_DRAW_ClearAndPrintStream(u8 *p){BMP_MENUWORK_DrawWindow(((struct Obj02247 *)p)->f1F68,2,1,14);BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj02247 *)p)->f1F68),15);B_PLIST_DRAW_PrintStream((char *)p);}
