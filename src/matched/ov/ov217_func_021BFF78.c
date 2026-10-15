/*
 * function: RESEARCH_GRAPH_InitScreen
 * address: 0x021BFF78
 * packet: pkt_ov217_021BFF78
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 0207DCF8 full body fixes r1/r2 and forwards only entry r0 to 02082A60; full target overwrites entry r3 and reads no stack arguments.
 * data: pool 021BFFC4 contains 5c 36 1c 02; contested ov217 hint removed per canonical rule, data a4 resolves sole-ref.
 * volatile: hardware stores 021BFF88/8C/90/94; 04000060 re-read at 021BFF96 and 021BFFA4.
 * symbols:
 *   func_0207D988 0x0207D988 arm
 *   func_0207DB1C 0x0207DB1C arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   d_021C365C 0x021C365C data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void func_0207D988(void);
extern void func_0207DB1C(void);
extern void func_0207DCF8(const void *);
extern const u16 d_021C365C[];
void RESEARCH_GRAPH_InitScreen(void)
{
    func_0207D988();
    func_0207DB1C();
    *(volatile u32 *)0x04000440 = 0;
    *(volatile u32 *)0x04000454 = 0;
    *(volatile u32 *)0x04000440 = 2;
    *(volatile u32 *)0x04000454 = 0;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x10;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x20;
    func_0207DCF8(d_021C365C);
}
