/*
 * function: func_021D6E1C
 * address: 0x021D6E1C
 * packet: pkt_ov120_021D6E1C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: name the p[2]+3 bound and reread p[2] for the increment;
 * retaining a named offset instead exchanges r3 and r4 (4-byte DIFF).
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int func_021D6E1C(void *unused,int *p){int idx=p[1];int ret=0;if(idx<2 && idx<p[0]-1){p[1]=idx+1;return 1;}else if(idx==2){int bound=p[2]+3;if(bound<p[0]){p[2]=p[2]+1;ret=2;}}return ret;}
