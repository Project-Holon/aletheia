/*
 * function: func_021B6A60
 * address: 0x021B6A60
 * packet: pkt_ov180_021B6A60
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfword stores at 0x04000050 and 0x04001050.
 * symbols:
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0207D534 0x0207D534 arm
 *   func_021B6210 0x021B6210 thumb ov180
 *   func_021B6418 0x021B6418 thumb ov180
 *   func_021B64AC 0x021B64AC thumb ov180
 *   func_021B64DC 0x021B64DC thumb ov180
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_021B6210(void);
extern void func_021B6418(char *);
extern void func_021B64AC(char *);
extern void func_021B64DC(char *);
int func_021B6A60(char *p) {
    func_02043534(0); func_020435F4(0);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    func_0207D534((void *)0x0400006c,-16);
    func_0207D534((void *)0x0400106c,-16);
    func_021B6210(); func_021B6418(p); func_021B64AC(p); func_021B64DC(p);
    return 4;
}
