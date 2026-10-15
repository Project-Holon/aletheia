/*
 * function: OSi_InitCommon
 * address:  0x02086374
 * packet:   pkt_02086368
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   PXI_Init  0x02088498  arm
 *   OS_InitArena  0x020863E0  arm
 *   OS_InitLock  0x02084B90  arm
 *   OS_InitArenaEx  0x020864FC  arm
 *   func_0208475C  0x0208475C  arm
 *   func_020849F4  0x020849F4  arm
 *   OS_InitException  0x02086DD8  arm
 *   MI_Init  0x0208361C  arm
 *   OS_InitVAlarm  0x02087578  arm
 *   OSi_InitVramExclusive  0x02087EA8  arm
 *   OS_InitThread  0x02085264  arm
 *   OS_InitReset  0x02087B78  arm
 *   GFL_USE_CtrdgDummyInit  0x02005438  thumb
 *   CARD_Init  0x02075CAC  arm
 *   func_02082198  0x02082198  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   SCFG_Init  0x0208C960  arm
 *   PM_Init  0x0208B8B0  arm
 *   OSi_WaitVCount0  0x02086348  arm
 *   OSi_InitPrevTitleId  0x020883D4  arm
 */

extern void PXI_Init(void);
extern void OS_InitArena(void);
extern void OS_InitLock(void);
extern void OS_InitArenaEx(void);
extern void func_0208475C(void);
extern void func_020849F4(void);
extern void OS_InitException(void);
extern void MI_Init(void);
extern void OS_InitVAlarm(void);
extern void OSi_InitVramExclusive(void);
extern void OS_InitThread(void);
extern void OS_InitReset(void);
extern void GFL_USE_CtrdgDummyInit(void);
extern void CARD_Init(void);
extern void func_02082198(void);
extern int  OS_IsRunOnTwl(void);
extern void SCFG_Init(void);
extern void PM_Init(void);
extern void OSi_WaitVCount0(void);
extern void OSi_InitPrevTitleId(void);

void OSi_InitCommon(void)
{
    PXI_Init();
    OS_InitArena();
    OS_InitLock();
    OS_InitArenaEx();
    func_0208475C();
    func_020849F4();
    OS_InitException();
    MI_Init();
    OS_InitVAlarm();
    OSi_InitVramExclusive();
    OS_InitThread();
    OS_InitReset();
    GFL_USE_CtrdgDummyInit();
    CARD_Init();
    func_02082198();
    if (OS_IsRunOnTwl() == 1)
        SCFG_Init();
    PM_Init();
    OSi_WaitVCount0();
    if (OS_IsRunOnTwl() != 1)
        return;
    OSi_InitPrevTitleId();
}
