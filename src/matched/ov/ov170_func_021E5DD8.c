/*
 * function: BOX2_SEQ_StateOpenItemD
 * address: 0x021E5DD8
 * packet: pkt_ov170_021E5DD8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb ov170
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb ov170
 *   BOX2_SEQ_PrintPrompt 0x021EBC58 thumb ov170
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb ov170
 */
#include "../include/Obj00000.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BOX2_SEQ_ShowWindowObject(char *,int);
extern void BOX2_MAIN_RefreshCursorBox(char *);
extern void BOX2_SEQ_PrintPrompt(u8 *,int,int,int);
extern void BOX2_UI_DeleteSlotObjects(char *,int,int,int);
int BOX2_SEQ_StateOpenItemD(u8 *p){BOX2_SEQ_ShowWindowObject(*(char * *)&((struct Obj00000 *)p)->f2C,24);BOX2_MAIN_RefreshCursorBox((char *)p);BOX2_SEQ_PrintPrompt(p,0,3,26);BOX2_UI_DeleteSlotObjects((char *)p,0,1,1);return 53;}
