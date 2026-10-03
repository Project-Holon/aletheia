/*
 * function: func_021D4C98
 * address: 0x021D4C98
 * packet: pkt_ov120_021D4C98
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_020355D8 0x020355D8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D69F4(u8 *,void *,u32); extern void func_020355D8(int);
void func_021D4C98(void *p,int n,u8 *s) { if (n==0 && *(u32 *)(s+4)) { func_021D69F4(*(u8 **)(s+60),*(void **)(s+52),9); func_020355D8(1); if ((*(int (**)(void *,void *))(s+4))(p,s)==0) return; } }
