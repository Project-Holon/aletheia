/*
 * function: func_021B9FF0
 * address: 0x021B9FF0
 * packet: pkt_ov220_021B9FF0
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   sub_020452E8 0x020452E8 arm
 *   func_02045C04 0x02045C04 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;struct Rec;
extern void sub_020452E8(struct Descriptor*);
extern void func_02045C04(struct Rec*);
void func_021B9FF0(u8*p){u8 i;for(i=0;i<4;i++)if(*(struct Descriptor**)(p+96+i*4))sub_020452E8(*(struct Descriptor**)(p+96+i*4));if(*(struct Rec**)(p+92))func_02045C04(*(struct Rec**)(p+92));}
