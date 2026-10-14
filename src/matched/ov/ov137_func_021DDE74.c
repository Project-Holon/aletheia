/*
 * function: GURU2_RECEIPT_StateQuitDelay
 * address: 0x021DDE74
 * packet: pkt_ov137_021DDE74
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_RECEIPT_Noop 0x021DD924 thumb ov137
 */
#include "../include/Obj14217.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GURU2_RECEIPT_Noop(char *);
int GURU2_RECEIPT_StateQuitDelay(char *p,int state) {if(++((struct Obj14217 *)p)->f124>45) ((struct Obj14217 *)p)->f118=15;GURU2_RECEIPT_Noop(p);return state;}
