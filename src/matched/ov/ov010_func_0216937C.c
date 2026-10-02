/*
 * function: func_0216937C
 * address: 0x0216937C
 * packet: pkt_ov010_0216937C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0216990C 0x0216990C thumb ov010
 *   func_021693A0 0x021693A0 thumb ov010
 *   func_020490F4 0x020490F4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0216990C(u8 *);
extern void func_021693A0(void *);
extern u32 func_020490F4(int,int);
void func_0216937C(u8 *p,int a,int b) { func_0216990C(p); func_021693A0(p); *(u32 *)(*(u8 **)(p+0x2c)+4)=0; *(u32 *)(p+0x10)=func_020490F4(a,b); }
