/*
 * unit: no
 * function: BTL_REC_SEL_DeleteUiActor
 * address: 0x021BAE88
 * packet: pkt_ov214_021BAE88
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_REC_SEL_DeleteActor 0x021BABA4 thumb ov214
 */
#include "../include/Obj00182.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern void BTL_REC_SEL_DeleteActor(void *,void *);
void BTL_REC_SEL_DeleteUiActor(int unused,u8 *p){BTL_REC_SEL_DeleteActor(p+0x2c4,((struct Obj00182 *)p)->f2D4);}
