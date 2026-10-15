/*
 * function: BOX2_SEQ_SetBox2MainC
 * address: 0x021E58D8
 * packet: pkt_ov170_021E58D8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_UI_OpenListPack 0x021EF57C thumb ov170
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb ov170
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb ov170
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb ov170
 *   BOX2_SEQ_SetState 0x021E8FE0 thumb ov170
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb ov170
 *   BOX2_MAIN_SceneWaitScroll 0x021E070C thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23904.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct WinMgr;
extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);
extern void BOX2_SEQ_SetSlotDim(char **,int);
extern void BOX2_SEQ_ShowWindowObject(char *,int);
extern void BOX2_MAIN_RefreshCursorBox(char *);
extern int BOX2_SEQ_SetState(char *,int);
extern int BOX2_SEQ_SetSeqThird(char *,int,int);
extern int BOX2_MAIN_SceneWaitScroll(char *p);
void BOX2_SEQ_SetBox2MainC(u8 *p){BOX2_UI_OpenListPack(*(struct WinMgr * *)&((struct Obj23904 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74);BOX2_SEQ_SetSlotDim((char **)p,0);BOX2_SEQ_ShowWindowObject(*(char * *)&((struct Obj00000 *)p)->f2C,24);BOX2_MAIN_RefreshCursorBox((char *)p);BOX2_SEQ_SetSeqThird((char *)p,(int)BOX2_MAIN_SceneWaitScroll,BOX2_SEQ_SetState((char *)p,49));}
