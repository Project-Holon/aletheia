/*
 * function: Wf2dmapFriend_CheckEntryPrintStream
 * address: 0x021C873C
 * packet: pkt_ov128_021C873C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the compiled function.
 * symbols:
 *   Wf2dmapFriend_UpdatePrintStream 0x021C7600 thumb ov128
 */
#include "../include/Obj23087.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int Wf2dmapFriend_UpdatePrintStream(void *,int *);
int Wf2dmapFriend_CheckEntryPrintStream(void *p,int *state,u8 *q) {if(Wf2dmapFriend_UpdatePrintStream(((struct Obj23087 *)q)->f2C,(int *)(q+48))==0) {*state=0;return 1;}return 0;}
