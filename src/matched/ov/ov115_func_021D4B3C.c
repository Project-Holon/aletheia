/*
 * function: func_021D4B3C
 * address: 0x021D4B3C
 * packet: pkt_ov115_021D4B3C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202208C 0x0202208C thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D4A98 0x021D4A98 thumb ov115
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_02005E30(u32 a);
extern void func_021D426C(u8 *,u32);
extern void func_021D4A98(u8 *);
#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
void func_021D4B3C(u8 *p) {
 func_0202208C(0,0,0,0,6,1,*(u16 *)(p+0xc)); if(!*(int *)(P(0x40)+4) && !*(int *)(P(0x40)+0x18)) func_02005E30(8); func_021D426C(p,(u32)func_021D4A98);
}
