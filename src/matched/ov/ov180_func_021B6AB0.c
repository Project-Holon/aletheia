/*
 * function: HALL_OF_FAME_StateExit
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
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   HALL_OF_FAME_ExitGraphicsSystem 0x021B621C thumb ov180
 *   HALL_OF_FAME_ExitText 0x021B6474 thumb ov180
 *   HALL_OF_FAME_ReleaseWaveArc 0x021B64D0 thumb ov180
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern void HALL_OF_FAME_ExitGraphicsSystem(void);
extern void HALL_OF_FAME_ExitText(char *);
extern void HALL_OF_FAME_ReleaseWaveArc(char *);
int HALL_OF_FAME_StateExit(char *p) {
    HALL_OF_FAME_ReleaseWaveArc(p); HALL_OF_FAME_ExitText(p); HALL_OF_FAME_ExitGraphicsSystem();
    GXx_SetMasterBrightness_((void *)0x0400006c,-16);
    GXx_SetMasterBrightness_((void *)0x0400106c,-16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    BG_SYS_SetMainVisiblePlanes(0); BG_SYS_SetSubVisiblePlanes(0);
    return 10;
}
