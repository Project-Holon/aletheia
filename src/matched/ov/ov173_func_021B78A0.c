/*
 * function: func_021B78A0
 * address: 0x021B78A0
 * packet: pkt_ov173_021B78A0
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02049E74 0x02049E74 arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sub0204A9D0;
extern void *func_02049E74(u32,u32,u32,struct Sub0204A9D0 **,u16);
extern void func_0204A9D0(int,struct Sub0204A9D0 *);
extern void func_020307B0(void *);
void func_021B78A0(u32 a,int b,u32 c,u32 d,u16 heap) {void *raw;struct Sub0204A9D0 *out;raw=func_02049E74(a,c,d,&out,heap);func_0204A9D0(b,out);func_020307B0(raw);}
