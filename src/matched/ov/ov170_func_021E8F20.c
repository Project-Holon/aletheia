/*
 * function: BOX2_SEQ_HideCursorSlot
 * address: 0x021E8F20
 * packet: pkt_ov170_021E8F20
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 *   BOX2_SEQ_SetWindow9 0x021ED508 thumb ov170
 *   BOX2_SEQ_PrintMessageB 0x021EBADC thumb ov170
 *   BOX2_SEQ_DeleteSlotWindows 0x021EA984 thumb ov170
 *   BOX2_SEQ_OpenYesNo 0x021E8FE8 thumb ov170
 */
#include "../include/Obj23941.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BOX2_SEQ_SetActorDrawEnable(char *,int,int);
extern void BOX2_SEQ_SetWindow9(u8 *,int,int);
extern void BOX2_SEQ_PrintMessageB(char *,int);
extern void BOX2_SEQ_DeleteSlotWindows(u8 *);
extern int BOX2_SEQ_OpenYesNo(u8 *,int);
void BOX2_SEQ_HideCursorSlot(u8 *p){BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj23941 *)p)->f2C,4,0);BOX2_SEQ_SetWindow9(p,14,0);BOX2_SEQ_PrintMessageB((char *)p,24);BOX2_SEQ_DeleteSlotWindows(p);BOX2_SEQ_OpenYesNo(p,4);}
