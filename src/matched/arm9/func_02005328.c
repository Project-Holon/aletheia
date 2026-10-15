/*
 * function: GFL_USE_InitSdk
 * address:  0x02005328
 * packet:   pkt_02005328
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  none, needs a second caller.  Every concrete byte reproduces;
 *           nine relocation sites stay wildcarded because this function is
 *           the ONLY branch anywhere in the image to GX_Init (0x0207D204),
 *           SCFG_SetCpuSpeed (0x0208C988), FS_TryLoadTable (0x0207ACB4,
 *           two sites, both here), PM_GetAmp (0x0208C030) and the veneer at
 *           0x020053E4, and the only pool reference to _TwlServiceBuf,
 *           GFL_USE_OnPreExit and _PreExitCallbackInfo.  --suggest-split reports
 *           "0 piece(s), 1 function left out": no cut frees any site,
 *           because the single witness for each is the call inside this
 *           function.  Unblocks only when a second caller of any of these
 *           is filed EXACT, or when 0x02005440 leaves src/pending/.
 *
 * symbols:
 *   OS_Init       0x02086368  arm
 *   OS_InitTick         0x02086FE8  arm
 *   OS_InitAlarm        0x02087208  arm
 *   RTC_Init            0x02088788  arm
 *   GX_Init             0x0207D204  arm
 *   FX_Init       0x0207D148  arm
 *   OS_GetConsoleType   0x02085CBC  arm
 *   SCFG_SetCpuSpeed    0x0208C988  arm
 *   FS_Init             0x0207AD04  arm
 *   FS_TryLoadTable  0x0207ACB4  arm
 *   OS_AllocFromArenaLo 0x02086788  arm
 *   NNS_GfdInitVramTransferTaskQueue        0x02061C0C  arm
 *   APP_ENV_IsRunOnTwl        0x0202EB0C  thumb
 *   GFL_USE_OnPreExit       0x02005440  thumb
 *   func_020053E4       0x020053E4  arm
 *   PM_GetAmp           0x0208C030  arm
 *   PM_SetAmp           0x0208BEF0  arm
 *   _TwlServiceBuf          0x020A9E94  data
 *   _PreExitState          0x020A9E80  data
 *   _PreExitCallbackInfo          0x020A9E84  data
 *
 * The ARM9 entry's hardware bring-up: SDK init sequence, then the TWL-only
 * clock bump (OS_GetConsoleType & 0x03000000 selects the DSi consoles), two
 * SCFG register masks, the IME reset, FS_Init, the heap arena grab, and the
 * amplifier check.
 *
 * 0x020053E4 is a four-byte ARM long-branch veneer (ldr pc,[pc,#-4]; .word
 * 0x0273154C), not compiled C, so it is declared as an ordinary extern at
 * the stub's address, marked arm; see
 * docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_USE_InitSdk.c \
 *       --func GFL_USE_InitSdk --addr 0x02005328 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void OS_Init(void);
extern void OS_InitTick(void);
extern void OS_InitAlarm(void);
extern void RTC_Init(void);
extern void GX_Init(void);
extern void FX_Init(void);
extern u32  OS_GetConsoleType(void);
extern void SCFG_SetCpuSpeed(int speed);
extern void FS_Init(int dma);
extern void *FS_TryLoadTable(int a, void *b);
extern void *OS_AllocFromArenaLo(int id, void *size, int align);
extern void NNS_GfdInitVramTransferTaskQueue(void *p, u32 capacity);
extern u32 APP_ENV_IsRunOnTwl(void);
extern void GFL_USE_OnPreExit(void);
extern void func_020053E4(void *p);
extern void PM_GetAmp(u32 *out);
extern void PM_SetAmp(int on);

extern u32 _TwlServiceBuf[];
extern u32 _PreExitState[];
extern u32 _PreExitCallbackInfo[];

void GFL_USE_InitSdk(void)
{
    u32 amp;
    void *arena;

    OS_Init();
    OS_InitTick();
    OS_InitAlarm();
    RTC_Init();
    GX_Init();
    FX_Init();
    if (OS_GetConsoleType() & 0x03000000) {
        SCFG_SetCpuSpeed(1);
        *(volatile u32 *)0x04004008 &= 0xFFFFDFFF;
        *(volatile u32 *)0x02FFFDF0 &= 0xFFFFDFFF;
    }
    *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 1;
    FS_Init(1);
    arena = FS_TryLoadTable(0, 0);
    FS_TryLoadTable((int)OS_AllocFromArenaLo(0, arena, 4), arena);
    NNS_GfdInitVramTransferTaskQueue(_TwlServiceBuf, 0x30);
    if (APP_ENV_IsRunOnTwl()) {
        _PreExitState[0] = 0;
        _PreExitState[1] = (u32)GFL_USE_OnPreExit;
        _PreExitState[2] = 0;
        func_020053E4(_PreExitCallbackInfo);
    }
    PM_GetAmp(&amp);
    if (amp == 1)
        PM_SetAmp(0);
}
