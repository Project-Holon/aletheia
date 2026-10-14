/*
 * function: GURU2_RECEIPT_StateWaitMessageToError
 * address: 0x021DDF38
 * packet: pkt_ov137_021DDF38
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GURU2_RECEIPT_IsMessageDone 0x021DE55C thumb ov137
 *   GURU2_RECEIPT_PrintMessage 0x021DE4B4 thumb ov137
 *   GURU2_RECEIPT_Noop 0x021DD924 thumb ov137
 */
#include "../include/Obj23725.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GURU2_RECEIPT_IsMessageDone(char *);
extern void GURU2_RECEIPT_PrintMessage(char *,int,int),GURU2_RECEIPT_Noop(char *);
int GURU2_RECEIPT_StateWaitMessageToError(char *p,int state) {if(GURU2_RECEIPT_IsMessageDone(p)) {GURU2_RECEIPT_PrintMessage(p,7,0);((struct Obj23725 *)p)->f118=18;}GURU2_RECEIPT_Noop(p);return state;}
