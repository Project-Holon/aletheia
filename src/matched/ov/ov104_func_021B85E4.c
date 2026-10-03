/*
 * function: func_021B85E4
 * address: 0x021B85E4
 * packet: pkt_ov104_021B85E4
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02087058 0x02087058 arm
 *   func_02086FE8 0x02086FE8 arm
 *   func_020870D0 0x020870D0 arm
 *   _ll_udiv 0x0209C00C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02087058(void);
extern void func_02086FE8(void);
extern unsigned long long func_020870D0(void);
void func_021B85E4(u8 *p) { if(func_02087058()) func_02086FE8(); *(unsigned long long *)(p+0x7c)=(func_020870D0()<<6)/33514; }
