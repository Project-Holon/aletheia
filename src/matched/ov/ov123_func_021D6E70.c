/*
 * unit: no
 * function: func_021D6E70
 * address: 0x021D6E70
 * packet: pkt_ov123_021D6E70
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern int func_0203CD98(void);
int func_021D6E70(u8 *p){u8 *q=*(u8 **)(p+0x20);if(*(int *)(q+0x1c8)==2)return 0;if(*(int *)(q+0x50) && *(unsigned short *)(q+0xc)==4)return 0;if(func_0203CD98())return 1;return 0;}
