/*
 * function: func_021B6AB0
 * address: 0x021B6AB0
 * packet: pkt_ov180_021B6AB0
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfword stores at 0x04000050 and 0x04001050.
 * symbols:
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   func_0207D534 0x0207D534 arm
 *   func_021B621C 0x021B621C thumb ov180
 *   func_021B6474 0x021B6474 thumb ov180
 *   func_021B64D0 0x021B64D0 thumb ov180
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_021B621C(void);
extern void func_021B6474(char *);
extern void func_021B64D0(char *);
int func_021B6AB0(char *p) {
    func_021B64D0(p); func_021B6474(p); func_021B621C();
    func_0207D534((void *)0x0400006c,-16);
    func_0207D534((void *)0x0400106c,-16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    BG_SYS_SetMainVisiblePlanes(0); BG_SYS_SetSubVisiblePlanes(0);
    return 10;
}
