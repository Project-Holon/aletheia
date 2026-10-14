/*
 * function: DENDOU_VIEW_DeleteActors
 * address: 0x021DE368
 * packet: pkt_ov171_021DE368
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DENDOU_VIEW_DeleteActor 0x021DE34C thumb ov171
 *   CLACT_DeleteUnit 0x0204B1CC arm
 */
#include "../include/Obj08252.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void DENDOU_VIEW_DeleteActor(char *,int);
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
void DENDOU_VIEW_DeleteActors(char *p) { u32 i; for(i=0;i<16;i++) DENDOU_VIEW_DeleteActor(p,i); CLACT_DeleteUnit(((struct Obj08252 *)p)->fB70); }
