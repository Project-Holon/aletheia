/*
 * function: func_021B9B84
 * address: 0x021B9B84
 * packet: pkt_ov222_021B9B84
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_02045C04 0x02045C04 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;struct Rec;
extern void func_020452E8(struct Descriptor *),func_02045C04(struct Rec *);
void func_021B9B84(char *p) { u8 i;for(i=0;i<5;i++){struct Descriptor *q=*(struct Descriptor **)((u32)p+(u32)i*4+28);if(q)func_020452E8(q);}if(*(struct Rec **)(p+24))func_02045C04(*(struct Rec **)(p+24)); }
