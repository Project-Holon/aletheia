/*
 * function: func_021D6E50
 * address: 0x021D6E50
 * packet: pkt_ov120_021D6E50
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: following clamp leaf filed separately as ov120_func_021D6E70.c.
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int func_021D6E50(void *unused,int *p){int idx=p[1];int ret=0;if(idx>0){p[1]=idx-1;return 1;}else if(idx==0 && p[2]!=0){p[2]=p[2]-1;ret=2;}return ret;}
