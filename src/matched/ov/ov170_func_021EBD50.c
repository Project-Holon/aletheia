/*
 * function: BOX2_SEQ_PrintBoxMonName
 * address: 0x021EBD50
 * packet: pkt_ov170_021EBD50
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb ov170
 *   WORDSET_SetSlotMonSpeciesAlt 0x0201EF14 thumb
 *   BOX2_SEQ_PrintMessageMsg 0x021EBA84 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23995.h"
extern int BOX2_MAIN_GetMonAt(void ***,int,unsigned); extern void WORDSET_SetSlotMonSpeciesAlt(void *,unsigned,void *); extern void BOX2_SEQ_PrintMessageMsg(unsigned char *,int,int);
void BOX2_SEQ_PrintBoxMonName(unsigned char *p){void *m=(void *)BOX2_MAIN_GetMonAt((void ***)p,p[20],p[22]);WORDSET_SetSlotMonSpeciesAlt(((struct Obj23995 *)(*(unsigned char * *)&((struct Obj00000 *)p)->f2C))->f84,0,m);BOX2_SEQ_PrintMessageMsg(p,50,27);}
