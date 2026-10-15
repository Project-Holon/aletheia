/*
 * function: BOX2_MAIN_SetSceneSlots
 * address: 0x021DF0D4
 * packet: pkt_ov170_021DF0D4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb ov170
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 */
#include "../include/Obj14263.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank; struct CharBuf; struct Descriptor; struct Rec; struct Node; struct Blk37;
extern void BOX2_SEQ_SetActorAnimSeq(char *p, int i, int v);
extern void BOX2_SEQ_SetActorDrawEnable(char *,int,int);
void BOX2_MAIN_SetSceneSlots(char *p,int base,u32 bits) { u16 i,v;for(i=0;i<6;i++){if(bits & (1<<i))v=i*2+1;else v=i*2;BOX2_SEQ_SetActorAnimSeq(*(char * *)&((struct Obj14263 *)p)->f2C,base+i,v);BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj14263 *)p)->f2C,base+i,1);} }
