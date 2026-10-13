/*
 * function: IRC_RANKING_InputGetKeys
 * address: 0x021B8FA8
 * packet: pkt_ov106_021B8FA8
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   KEY_GetCont 0x0203630C arm
 */
#include "../include/Obj22267.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 KEY_GetCont(void);
void *IRC_RANKING_InputGetKeys(u8 *p,int *out) { if(out) *out=((struct Obj22267 *)p)->f28; return (void *)KEY_GetCont(); }
