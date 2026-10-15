/*
 * function: LOCAL_TVT_SYS_SetupDisplay
 * address: 0x021B63DC
 * packet: pkt_ov174_021B63DC
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 020434CC is omitted from unit_0204349C.c's function header.
 *   one --arm, no region: MATCH, 16 bytes, blocker434CC.log; concrete bytes agree,
 *   unresolved 020434B4 is also omitted from that owner unit's function header.
 *   Scratch copy of owner unit also verifies TU EXACT: blocker434unit.log.
 *   extern void BG_SYS_ClearMainBgPlanes(void),BG_SYS_ClearMainObjPlane(void);
 *   void BG_SYS_ClearMainPlanes(void) {BG_SYS_ClearMainBgPlanes();BG_SYS_ClearMainObjPlane();}
 * blocker: ARM9 02043588 is omitted from unit_02043570.c's function header.
 *   one --arm, no region: EXACT, 16 bytes, blocker43588.log.
 *   extern void BG_SYS_ClearSubBgPlanes(void),BG_SYS_ClearSubObjPlane(void);
 *   void BG_SYS_ClearSubPlanes(void) {BG_SYS_ClearSubBgPlanes();BG_SYS_ClearSubObjPlane();}
 * blocker: ARM9 data 020A1448 has no witness outside this caller; extern a4
 *   retained without an overlay token, ROM pool +0128 names 020A1448.
 * volatile: DISPCNT reads/writes 021B63EE..021B63FE; blend writes 021B6420/6424; POWCNT1 read/write 021B6426..642E.
 * symbols:
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   WIPE_ResetWndMask 0x02022224 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   LOCAL_TVT_SYS_SetupBgLayer 0x021B6538 thumb ov174
 *   func_02082A7C 0x02082A7C arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_0207D63C 0x0207D63C arm
 *   d_021B7450 0x021B7450 data a4
 *   d_021B7388 0x021B7388 data a4
 *   d_021B73D0 0x021B73D0 data a4
 *   d_021B73B0 0x021B73B0 data a4
 *   d_021B7410 0x021B7410 data a4
 *   d_021B7430 0x021B7430 data a4
 *   d_021B73F0 0x021B73F0 data a4
 *   gClActorInitParam 0x020A1448 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
typedef struct { u32 w[7]; } Config;
extern void BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void);
struct Bank;
struct Cfg;
struct DispConfig;
struct DispVram;
extern void WIPE_SetBrightnessFadeOut(u32 a, u32 color);
extern u32 WIPE_ResetWndMask(void *win);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_Create(u16),BMP_WIN_Init(u16);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
struct BgTemplate;
extern void LOCAL_TVT_SYS_SetupBgLayer(const struct BgTemplate *p, int i, int type);
extern void func_02082A7C(int,int,u32);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void func_0207D63C(void *,int,int,int,int);
extern const u32 d_021B7450[],d_021B7388[],d_021B73D0[],d_021B73B0[],d_021B7410[],d_021B7430[],d_021B73F0[];
extern const Config gClActorInitParam;
void LOCAL_TVT_SYS_SetupDisplay(u8 *p)
{
    Config c;
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)0x04000000 &= ~0x1F00;
    *(volatile u32 *)0x04001000 &= ~0x1F00;
    WIPE_SetBrightnessFadeOut(0,0);
    WIPE_SetBrightnessFadeOut(1,0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask((void *)1);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u16 *)0x04000304 |=0x8000;
    BG_SYS_SetVramBanks((const struct DispVram *)d_021B7450);
    BG_SYS_Create(*(u16 *)p);
    BMP_WIN_Init(*(u16 *)p);
    BG_SYS_SetGraphicsMode((void *)d_021B7388);
    LOCAL_TVT_SYS_SetupBgLayer((const struct BgTemplate *)d_021B73D0,0,0);
    LOCAL_TVT_SYS_SetupBgLayer((const struct BgTemplate *)d_021B73B0,1,0);
    LOCAL_TVT_SYS_SetupBgLayer((const struct BgTemplate *)d_021B7410,2,2);
    LOCAL_TVT_SYS_SetupBgLayer((const struct BgTemplate *)d_021B7430,3,2);
    LOCAL_TVT_SYS_SetupBgLayer((const struct BgTemplate *)d_021B73F0,7,0);
    func_02082A7C(0,0x06000000,0x40000);
    c=gClActorInitParam;
    CLACT_InitSystem((const struct Cfg *)(&c),(u32)d_021B7450,*(u16 *)p);
    BG_SYS_SetMainPlaneVisible(16,1);
    BG_SYS_SetSubPlaneVisible(16,1);
    *(void **)(p+80)=CLACT_CreateUnit(16,0,*(u16 *)p);
    CLACT_SetUnitDefaultRenderer(*(void **)(p+80));
    func_0207D63C((void *)0x04000050,1,30,16,4);
}
