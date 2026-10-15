/*
 * function: B_BAG_MAIN_StateWaitPrintRedraw
 * address: 0x0220CFF0
 * packet: pkt_ov197_0220CFF0
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   B_BAG_MAIN_ShowWindows 0x0220B990 thumb ov197
 *   B_BAG_MAIN_SetDisplayMode 0x0220C4EC thumb ov197
 *   B_BAG_MAIN_LayoutFrames 0x0220BD24 thumb ov197
 */
#include "../include/Obj10837.h"
struct PrintSys;
extern unsigned PRINTSYS_QUE_IsFinished(const struct PrintSys *),B_BAG_MAIN_ShowWindows(unsigned char *);
extern void B_BAG_MAIN_SetDisplayMode(char *,int),B_BAG_MAIN_LayoutFrames(char *,int);
int B_BAG_MAIN_StateWaitPrintRedraw(char *p){if(PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj10837 *)p)->f18)==1){B_BAG_MAIN_ShowWindows((unsigned char *)p);B_BAG_MAIN_SetDisplayMode(p,((struct Obj10837 *)p)->f532);B_BAG_MAIN_LayoutFrames(p,((struct Obj10837 *)p)->f532);return 5;}return 12;}
