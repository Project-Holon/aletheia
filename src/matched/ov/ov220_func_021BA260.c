/*
 * function: func_021BA260
 * address: 0x021BA260
 * packet: pkt_ov220_021BA260
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021BA458 0x021BA458 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02082BCC(void*,int,u32);
extern const u8 d_021BA458[];
void func_021BA260(void*p){u32 i;for(i=0;i<3;i++)func_020403F4((u8)(*(u32*)(d_021BA458+i*44)));func_020450C8();func_0203F9B4();func_02082BCC(p,0,4);}
