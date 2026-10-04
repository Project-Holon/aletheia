/*
 * function: func_0216481C
 * address: 0x0216481C
 * packet: pkt_ov010_0216481C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021690D0 0x021690D0 thumb ov010
 *   func_021690E0 0x021690E0 thumb ov010
 *   func_02164844 0x02164844 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021690D0(int a0);
extern int func_021690E0(int a0);
extern u8 func_02164844(u8 *,u32,u8,u8);
u8 func_0216481C(u8 *p,u32 b){int c=func_021690D0((int)(*(void **)(p+4)));int d=func_021690E0((int)(*(void **)(p+4)));return func_02164844(p,b,c,d);}
