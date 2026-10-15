/*
 * function: DIGITALCARDCHECK_IsRecord3DoneA,DIGITALCARDCHECK_IsRecord3DoneB
 * address: 0x0217D2A4
 * packet: pkt_ov176_0217D2A4
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * unit: yes
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_VIEW_StepPartyWindow 0x021E8338 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_StepPartyWindowAlt 0x021E8420 thumb ov177
 */
#include "../include/Obj24425.h"
#include "../include/Obj24426.h"
typedef unsigned char u8;
extern int WIFIBATTLEMATCH_VIEW_StepPartyWindow(void *);
extern int WIFIBATTLEMATCH_VIEW_StepPartyWindowAlt(void *);
int DIGITALCARDCHECK_IsRecord3DoneA(u8 *p){return WIFIBATTLEMATCH_VIEW_StepPartyWindow(((struct Obj24425 *)p)->f18);}
int DIGITALCARDCHECK_IsRecord3DoneB(u8 *p){return WIFIBATTLEMATCH_VIEW_StepPartyWindowAlt(((struct Obj24426 *)p)->f18);}
