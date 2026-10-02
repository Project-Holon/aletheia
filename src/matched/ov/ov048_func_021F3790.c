/*
 * function: func_021F3790
 * address: 0x021F3790
 * packet: pkt_ov048_021F3790
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021897BC 0x021897BC thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int *func_021897BC(char *,int);
u8 func_021F3790(char *p) { return (u8)(*(int **)((char *)func_021897BC(p,0)+0x1c))[5]; }
