/*
 * function: DUP_FITTING_SetTextMon
 * address: 0x021B9C90
 * packet: pkt_ov133_021B9C90
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotMonNickname 0x0201EEF4 thumb
 *   DUP_FITTING_SetText 0x021B9C08 thumb ov133
 *   WORDSET_Delete 0x0201ED04 thumb
 */
#include "../include/Obj00004.h"
#include "../include/Obj23324.h"
#include "../include/Obj23325.h"
typedef unsigned int   u32;
struct WordSet;
extern struct WordSet *WORDSET_CreateDefault(u32 heap); extern void WORDSET_SetSlotMonNickname(void *,unsigned int,void *); extern void DUP_FITTING_SetText(unsigned char *,unsigned int,void *); extern void WORDSET_Delete(void *);
void DUP_FITTING_SetTextMon(unsigned char *p) {void *r=WORDSET_CreateDefault(((struct Obj00004 *)p)->f0);WORDSET_SetSlotMonNickname(r,0,((struct Obj23325 *)(*(unsigned char * *)&((struct Obj23324 *)(*(unsigned char * *)&((struct Obj00004 *)p)->f4))->f4))->f4);DUP_FITTING_SetText(p,0,r);WORDSET_Delete(r);}
