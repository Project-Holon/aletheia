/*
 * function: DUP_FITTING_IsFrameOwned
 * address: 0x021B8B78
 * packet: pkt_ov133_021B8B78
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_GetIndex 0x021F50F4 thumb ov112
 *   DUP_FITTING_ITEM_ListGetHead 0x021BA184 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetFrameIndex 0x021BA258 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetNext 0x021BA208 thumb ov133
 */
#include "../include/Obj23314.h"
extern int MUSICAL_MCSS_GetIndex(unsigned int); extern unsigned char *DUP_FITTING_ITEM_ListGetHead(void *); extern int DUP_FITTING_ITEM_ElemGetFrameIndex(unsigned char *); extern unsigned char *DUP_FITTING_ITEM_ElemGetNext(unsigned char *);
int DUP_FITTING_IsFrameOwned(unsigned char *p,unsigned int id) {int key=MUSICAL_MCSS_GetIndex(id);unsigned char *q=DUP_FITTING_ITEM_ListGetHead(((struct Obj23314 *)p)->f1824);while(q){if(key==MUSICAL_MCSS_GetIndex(DUP_FITTING_ITEM_ElemGetFrameIndex(q)))return 1;q=DUP_FITTING_ITEM_ElemGetNext(q);}return 0;}
