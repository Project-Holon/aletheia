/*
 * file:     os_init.c
 * unit:     yes
 * function: OSi_WaitVCount0, OS_Init, OSi_InitCommon
 * address:  0x02086348
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      OSi_WaitVCount0 (libos.TWL.HYB.a os_init.o)
 * asm:      no-prologue code on r12 that writes the register base itself (0x04000000, bit 0 clear) to IME to disable interrupts; the DWARF subprogram has no DW_TAG_variable children.
 *   (none)
 * blocker:  02086374 -- a tail call through a pool word
 *           (docs/idioms/tail-call-is-a-pool-word-and-bx.md), and that pool
 *           word is the only reference to 0x02086374 anywhere in the image,
 *           so the `literal` class discards its only witness and no cut
 *           helps: the pool is inside this function's own 12-byte extent.
 *           OSi_InitCommon is itself MATCH-capped (eleven callees each called
 *           from exactly one site), so the `matched` class cannot reach it
 *           either.  Every concrete byte is right: `ldr ip, [pc] ; bx ip`
 *           plus the pool word, 8 bytes of code.
 * A one-line forwarder to the driver at 0x02086374; mwccarm emits exactly
 * this shape for an ARM tail call, which is why the eight bytes are
 * reproducible at all.
 *
 * symbols:
 *   PXI_Init  0x02088498  arm
 *   OS_InitArena  0x020863E0  arm
 *   OS_InitLock  0x02084B90  arm
 *   OS_InitArenaEx  0x020864FC  arm
 *   func_0208475C  0x0208475C  arm
 *   OS_SetIrqStackChecker  0x020849F4  arm
 *   OS_InitException  0x02086DD8  arm
 *   MI_Init  0x0208361C  arm
 *   OS_InitVAlarm  0x02087578  arm
 *   OSi_InitVramExclusive  0x02087EA8  arm
 *   OS_InitThread  0x02085264  arm
 *   OS_InitReset  0x02087B78  arm
 *   GFL_USE_CtrdgDummyInit  0x02005438  thumb
 *   CARD_Init  0x02075CAC  arm
 *   MI_InitWramManager  0x02082198  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   SCFG_Init  0x0208C960  arm
 *   PM_Init  0x0208B8B0  arm
 *   OSi_InitPrevTitleId  0x020883D4  arm
 */
extern void PXI_Init(void);
extern void OS_InitArena(void);
extern void OS_InitLock(void);
extern void OS_InitArenaEx(void);
extern void func_0208475C(void);
extern void OS_SetIrqStackChecker(void);
extern void OS_InitException(void);
extern void MI_Init(void);
extern void OS_InitVAlarm(void);
extern void OSi_InitVramExclusive(void);
extern void OS_InitThread(void);
extern void OS_InitReset(void);
extern void GFL_USE_CtrdgDummyInit(void);
extern void CARD_Init(void);
extern void MI_InitWramManager(void);
extern int  OS_IsRunOnTwl(void);
extern void SCFG_Init(void);
extern void PM_Init(void);
extern void OSi_InitPrevTitleId(void);
asm void OSi_WaitVCount0(void);
void OS_Init(void);
void OSi_InitCommon(void);

/* hand-written in the original: no-prologue code on r12 that stores its own register base to IME */
asm void OSi_WaitVCount0(void)
{
    mov r12, #0x4000000
    ldr r1, [r12, #0x208]
    str r12, [r12, #0x208]
@_wait:
    ldrh r0, [r12, #6]
    cmp r0, #0
    bne @_wait
    str r1, [r12, #0x208]
    bx lr
}


void OS_Init(void)
{
    OSi_InitCommon();
}


void OSi_InitCommon(void)
{
    PXI_Init();
    OS_InitArena();
    OS_InitLock();
    OS_InitArenaEx();
    func_0208475C();
    OS_SetIrqStackChecker();
    OS_InitException();
    MI_Init();
    OS_InitVAlarm();
    OSi_InitVramExclusive();
    OS_InitThread();
    OS_InitReset();
    GFL_USE_CtrdgDummyInit();
    CARD_Init();
    MI_InitWramManager();
    if (OS_IsRunOnTwl() == 1)
        SCFG_Init();
    PM_Init();
    OSi_WaitVCount0();
    if (OS_IsRunOnTwl() != 1)
        return;
    OSi_InitPrevTitleId();
}
