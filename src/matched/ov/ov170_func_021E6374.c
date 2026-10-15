/*
 * function: BOX2_SEQ_StateCloseBoxC
 * address: 0x021E6374
 * packet: pkt_ov170_021E6374
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb ov170
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb ov170
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb ov170
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb ov170
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb ov170
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb ov170
 *   BOX2_MAIN_Check0F4C 0x021E0F4C thumb ov170
 */
#include "../include/Obj00000.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BOX2_SEQ_SetSlotDim(char **,int);
extern void BOX2_SEQ_ShowWindowObject(char *,int);
extern void BOX2_MAIN_RefreshCursorBox(char *);
extern void BOX2_UI_ShowWindowA(char *);
extern void BOX2_UI_ShowWindowB(char *);
extern int BOX2_SEQ_SetSeqThird(char *,int,int);
extern int BOX2_MAIN_Check0F4C(u8 *);
void BOX2_SEQ_StateCloseBoxC(u8 *p){BOX2_SEQ_SetSlotDim((char **)p,0);BOX2_SEQ_ShowWindowObject(*(char * *)&((struct Obj00000 *)p)->f2C,24);BOX2_MAIN_RefreshCursorBox((char *)p);if(p[0x16]<30)BOX2_UI_ShowWindowA(*(char * *)&((struct Obj00000 *)p)->f2C);else BOX2_UI_ShowWindowB(*(char * *)&((struct Obj00000 *)p)->f2C);BOX2_SEQ_SetSeqThird((char *)p,(int)BOX2_MAIN_Check0F4C,61);}
