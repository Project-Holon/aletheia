/*
 * function: PSEL_GRAPHIC_SetFadeSource, PSEL_GRAPHIC_IsReady
 * unit: yes
 * extent: copy helper followed by unlabelled return-one stub at 021BB9DC.
 * address: 0x021BB9A4
 * packet: pkt_ov223_021BB9A4
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 */
#include "../include/Obj00084.h"
extern void MI_CpuCopy8(const void *,void *,unsigned);
void PSEL_GRAPHIC_SetFadeSource(unsigned char *p,int value){if(p[2161]!=value){((struct Obj00084 *)p)->f86C=1;p[2160]=0;p[2161]=value;MI_CpuCopy8(p+1898,p+1642,256);}}
int PSEL_GRAPHIC_IsReady(void){return 1;}
