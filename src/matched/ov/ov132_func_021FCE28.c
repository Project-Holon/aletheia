/*
 * function: func_021FCE28
 * address: 0x021FCE28
 * packet: pkt_ov132_021FCE28
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
int func_021FCE28(char *p,u32 index) {if(*(int *)(p+0x4c)!=0 && *(int *)((u32)p+index*0x30+0x68)==1)return *(int *)((u32)p+index*0x30+0x84);return 0;}
