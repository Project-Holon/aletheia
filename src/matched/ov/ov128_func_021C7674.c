/*
 * function: Wf2dmapFriend_CheckPrintStream
 * address: 0x021C7674
 * packet: pkt_ov128_021C7674
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   Wf2dmapFriend_UpdatePrintStream 0x021C7600 thumb ov128
 */
#include "../include/Obj23077.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int Wf2dmapFriend_UpdatePrintStream(void *,int *);
int Wf2dmapFriend_CheckPrintStream(void *p,int *q,u8 *r) {if(Wf2dmapFriend_UpdatePrintStream(((struct Obj23077 *)r)->f2C,(int *)(r+48))==0) {*q=0;return 1;}return 0;}
