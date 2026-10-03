/*
 * function: func_021845E0
 * address: 0x021845E0
 * packet: pkt_ov168_021845E0
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank; struct CharBuf; struct Descriptor; struct Rec; struct Node; struct Blk37;

int func_021845E0(char *p) { int i;for(i=0;i<3;i++)if(*(void **)(p+i*0x30+0x7c))return 0;return 1; }
