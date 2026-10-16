/*
 * function: MICTEST_LevelToAnim
 * address: 0x021845AC
 * packet: pkt_ov168_021845AC
 * region: ov168
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
struct Bank; struct CharBuf; struct Descriptor; struct Rec; struct Node; struct Blk37;

int MICTEST_LevelToAnim(u8 n) { if(n<=150)return 0;if(n>=151 && n<=162)return 1;if(n>=163 && n<=176)return 2;if(n>=177 && n<=197)return 3;if(n>=198)n=4;return n; }
