/*
 * function: IRC_RANKING_ClactInit
 * address: 0x021B7F88
 * packet: pkt_ov106_021B7F88
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gIrcRankingClactSysInit 0x021B94B8 data a4
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 */
extern char gIrcRankingClactSysInit[];
extern void MI_CpuFill8(void *, int, int);
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
void IRC_RANKING_ClactInit(void **p, int a, int b) {
    MI_CpuFill8(p,0,0x14);
    CLACT_InitSystem((const struct Cfg *)gIrcRankingClactSysInit,a,b);
    *p=CLACT_CreateUnit(128,0,b);
    CLACT_SetUnitDefaultRenderer(*p);
    BG_SYS_SetMainPlaneVisible(16,1);
    BG_SYS_SetSubPlaneVisible(16,1);
}
