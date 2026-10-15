/*
 * unit: yes
 * function: MUS_COMM_FUNC_GetSlotValueB, MUS_COMM_FUNC_GetRecordPtr, MUS_COMM_FUNC_GetRecordSize, MUS_COMM_FUNC_Equals
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
int MUS_COMM_FUNC_GetSlotValueB(char *p,u32 index) {if(((struct Obj23274 *)p)->f4C!=0 && *(int *)((u32)p+index*0x30+0x68)==1)return *(int *)((u32)p+index*0x30+0x88);return 0;}
char *MUS_COMM_FUNC_GetRecordPtr(char *p){return p+0x20;}
u32 MUS_COMM_FUNC_GetRecordSize(void){return 40;}
int MUS_COMM_FUNC_Equals(int a,int b){if(a==b)return 1;return 0;}
