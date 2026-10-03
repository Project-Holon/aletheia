/*
 * function: func_021F253C
 * address: 0x021F253C
 * packet: pkt_ov194_021F253C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * volatile: count field +0x1e re-read at 021F253C and 021F2558
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
int func_021F253C(u8 *p) {int i,spaces,n;n=*(volatile u16 *)(p+30);if(!n) return 0;spaces=0;i=0;while(i<n) {if(*(u16 *)(p+i*2)==32) spaces++;n=*(volatile u16 *)(p+30);i++;}return i!=spaces;}
