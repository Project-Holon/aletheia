/*
 * function: func_0216FE04
 * address: 0x0216FE04
 * packet: pkt_ov010_0216FE04
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207FA0C 0x0207FA0C arm
 *   func_020862F0 0x020862F0 arm
 *   func_0207FA40 0x0207FA40 arm
 *   func_0207FADC 0x0207FADC arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0207FA0C(void);
extern void func_020862F0(void *,u32);
extern void func_0207FA40(void *,u32,u32);
extern void func_0207FADC(void);
void func_0216FE04(char *p,void *q) { u32 b,a; a=*(u32 *)(p+16); b=(u16)*(u32 *)(p+8)*8; func_0207FA0C(); func_020862F0(q,32); func_0207FA40(q,a+b,32); func_0207FADC(); }
