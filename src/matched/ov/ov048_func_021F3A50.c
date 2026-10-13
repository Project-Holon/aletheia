/*
 * function: FIELD_GIMMICK_GATE_LogMessage
 * address: 0x021F3A50
 * packet: pkt_ov048_021F3A50
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
#include "../include/Obj20528.h"
#include "../include/Obj20529.h"
typedef unsigned char u8;
void FIELD_GIMMICK_GATE_LogMessage(char *p,int a,int b) { char *q; int i; q=p+0x28; i=((struct Obj20528 *)p)->f28; if(i<7) { *(int *)(q+i*4+4)=a; *(int *)(q+i*4+0x20)=b; ((struct Obj20529 *)q)->f0=i+1; } }
