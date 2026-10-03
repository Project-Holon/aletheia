/*
 * function: func_021B87C8
 * address: 0x021B87C8
 * packet: pkt_ov102_021B87C8
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B8A90 0x021B8A90 thumb ov102
 *   func_02041EE4 0x02041EE4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B8A90(void *);
extern void func_02041EE4(u32,u32,u32);
void func_021B87C8(u8 *p) { if(*(u32 *)(p+24)) { if(func_021B8A90(p))*(u32 *)(p+24)=0; func_02041EE4(4,3,88-*(u32 *)p); func_02041EE4(7,3,88-*(u32 *)p); } }
