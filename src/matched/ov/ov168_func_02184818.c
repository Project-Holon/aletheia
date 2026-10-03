/*
 * function: func_02184818
 * address: 0x02184818
 * packet: pkt_ov168_02184818
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank; struct CharBuf; struct Descriptor; struct Rec; struct Node; struct Blk37;
extern void func_02030EAC(struct Node *);
void func_02184818(char *p) { int i; char *q;for(i=0;i<3;i++){q=p+i*0x30;if(*(struct Node **)(q+0x7c)){func_02030EAC(*(struct Node **)(q+0x7c));*(struct Node **)(q+0x7c)=0;}} }
