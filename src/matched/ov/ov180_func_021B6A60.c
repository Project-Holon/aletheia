/*
 * function: HALL_OF_FAME_StateInit
 * address: 0x021B6A60
 * packet: pkt_ov180_021B6A60
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
 *   HALL_OF_FAME_InitGraphicsSystem 0x021B6210 thumb ov180
 *   HALL_OF_FAME_InitText 0x021B6418 thumb ov180
 *   HALL_OF_FAME_StartBgm 0x021B64AC thumb ov180
 *   HALL_OF_FAME_CollectPartyMons 0x021B64DC thumb ov180
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void HALL_OF_FAME_InitGraphicsSystem(void);
extern void HALL_OF_FAME_InitText(char *);
extern void HALL_OF_FAME_StartBgm(char *);
extern void HALL_OF_FAME_CollectPartyMons(unsigned char *p);
int HALL_OF_FAME_StateInit(char *p) {
    BG_SYS_SetMainVisiblePlanes(0); BG_SYS_SetSubVisiblePlanes(0);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    func_0207D534((void *)0x0400006c,-16);
    func_0207D534((void *)0x0400106c,-16);
    HALL_OF_FAME_InitGraphicsSystem(); HALL_OF_FAME_InitText(p); HALL_OF_FAME_StartBgm(p); HALL_OF_FAME_CollectPartyMons((unsigned char *)p);
    return 4;
}
