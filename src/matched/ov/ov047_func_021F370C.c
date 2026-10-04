/*
 * function: func_021F370C
 * address: 0x021F370C
 * packet: pkt_ov047_021F370C
 * region: ov047
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_0216D8E0 0x0216D8E0 thumb ov010
 *   func_021897A0 0x021897A0 thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;
struct Ctx;
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern int *func_0200B3A4(u32,u32);
extern int *func_021897BC(char *,int);
extern void func_0216D8E0(u8 *,void *);
extern void func_021897A0(u8 *,int);
void func_021F370C(u32 a) { u8 *p; func_0200B3A4((u32)func_02012EC4(func_020120F4(func_02188C80((void *)a))),31); p=(u8 *)func_021897BC((char *)a,1); func_0216D8E0(*(u8 **)(p+4),p+8); func_021897A0((u8 *)a,1); }
