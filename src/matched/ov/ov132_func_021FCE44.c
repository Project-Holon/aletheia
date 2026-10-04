/*
 * unit: yes
 * function: func_021FCE44, func_021FCE60, func_021FCE64, func_021FCE68
 * address: 0x021FCE44
 * packet: pkt_ov132_021FCE44
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:

 */
#include "../include/Obj23274.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
int func_021FCE44(char *p,u32 index) {if(((struct Obj23274 *)p)->f4C!=0 && *(int *)((u32)p+index*0x30+0x68)==1)return *(int *)((u32)p+index*0x30+0x88);return 0;}
char *func_021FCE60(char *p){return p+0x20;}
u32 func_021FCE64(void){return 40;}
int func_021FCE68(int a,int b){if(a==b)return 1;return 0;}
