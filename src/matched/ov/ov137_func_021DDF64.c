/*
 * function: GURU2_RECEIPT_StateWaitMessageToStart
 * address: 0x021DDF64
 * packet: pkt_ov137_021DDF64
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_RECEIPT_IsMessageDone 0x021DE55C thumb ov137
 *   GURU2_RECEIPT_Noop 0x021DD924 thumb ov137
 */
#include "../include/Obj23726.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GURU2_RECEIPT_IsMessageDone(char *);
extern void GURU2_RECEIPT_Noop(char *);
int GURU2_RECEIPT_StateWaitMessageToStart(char *p,int state) {if(GURU2_RECEIPT_IsMessageDone(p)) ((struct Obj23726 *)p)->f118=10;GURU2_RECEIPT_Noop(p);return state;}
