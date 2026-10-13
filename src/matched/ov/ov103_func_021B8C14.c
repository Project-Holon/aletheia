/*
 * function: func_021B8C14
 * address: 0x021B8C14
 * packet: pkt_ov103_021B8C14
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021B7D4C 0x021B7D4C thumb ov103
 *   func_021B7F60 0x021B7F60 thumb ov103
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MI_CpuFill8(void *,int,int);
extern u8 *func_021B7D4C(u8 *,u16);
extern void func_021B7F60(u8 *,int);
void func_021B8C14(u8 **p,u8 *q) { int i; MI_CpuFill8(p,0,16); for(i=0;i<2;i++) { p[i]=func_021B7D4C(q,i); func_021B7F60(p[i],0); } }
