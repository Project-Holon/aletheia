/*
 * function: func_021F3A04
 * address: 0x021F3A04
 * packet: pkt_ov046_021F3A04
 * region: ov046
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *,int);
extern void func_021897A0(u8 *,int);
extern void func_021BE418(u8 *,u16);
void func_021F3A04(u32 a) { u32 p; p=func_02188D2C((int *)a); func_021897BC((char *)a,1); func_021897A0((u8 *)a,1); func_021BE418((u8 *)p,0); }
