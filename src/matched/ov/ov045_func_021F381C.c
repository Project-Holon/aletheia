/*
 * function: func_021F381C
 * address: 0x021F381C
 * packet: pkt_ov045_021F381C
 * region: ov045
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_021BE580 0x021BE580 thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;
struct Ctx;
extern int func_02188D2C(int *p);
extern int *func_021897BC(char *,int);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern int *func_0200B3A4(u32,u32);
extern void func_021BE580(void *);
void func_021F381C(u32 a) { u32 p; p=func_02188D2C((int *)a); func_021897BC((char *)a,1); func_0200B3A4((u32)func_02012EC4(func_020120F4(func_02188C80((void *)a))),9); func_021BE580((void *)p); }
