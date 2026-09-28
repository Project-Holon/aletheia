/*
 * function: func_02005328
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
 *           SCFG_SetCpuSpeed (0x0208C988), DWC_StartUtilityEx (0x0207ACB4,
 *           two sites, both here), PM_GetAmp (0x0208C030) and the veneer at
 *           0x020053E4, and the only pool reference to g_020A9E94,
 *           func_02005440 and g_020A9E84.  --suggest-split reports
 *           "0 piece(s), 1 function left out": no cut frees any site,
 *           because the single witness for each is the call inside this
 *           function.  Unblocks only when a second caller of any of these
 *           is filed EXACT, or when 0x02005440 leaves src/pending/.
 *
 * symbols:
 *   func_02086368       0x02086368  arm
 *   OS_InitTick         0x02086FE8  arm
 *   OS_InitAlarm        0x02087208  arm
 *   RTC_Init            0x02088788  arm
 *   GX_Init             0x0207D204  arm
 *   func_0207D148       0x0207D148  arm
 *   OS_GetConsoleType   0x02085CBC  arm
 *   SCFG_SetCpuSpeed    0x0208C988  arm
 *   FS_Init             0x0207AD04  arm
 *   DWC_StartUtilityEx  0x0207ACB4  arm
 *   OS_AllocFromArenaLo 0x02086788  arm
 *   sub_02061C0C        0x02061C0C  arm
 *   sub_0202EB0C        0x0202EB0C  thumb
 *   func_02005440       0x02005440  thumb
 *   func_020053E4       0x020053E4  arm
 *   PM_GetAmp           0x0208C030  arm
 *   PM_SetAmp           0x0208BEF0  arm
 *   g_020A9E94          0x020A9E94  data
 *   g_020A9E80          0x020A9E80  data
 *   g_020A9E84          0x020A9E84  data
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
 *   python tools/match.py one --src src/pending/func_02005328.c \
 *       --func func_02005328 --addr 0x02005328 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02086368(void);
extern void OS_InitTick(void);
extern void OS_InitAlarm(void);
extern void RTC_Init(void);
extern void GX_Init(void);
extern void func_0207D148(void);
extern u32  OS_GetConsoleType(void);
extern void SCFG_SetCpuSpeed(int speed);
extern void FS_Init(int dma);
extern void *DWC_StartUtilityEx(int a, void *b);
extern void *OS_AllocFromArenaLo(int id, void *size, int align);
extern void sub_02061C0C(void *p, int n);
extern int  sub_0202EB0C(void);
extern void func_02005440(void);
extern void func_020053E4(void *p);
extern void PM_GetAmp(u32 *out);
extern void PM_SetAmp(int on);

extern u32 g_020A9E94[];
extern u32 g_020A9E80[];
extern u32 g_020A9E84[];

void func_02005328(void)
{
    u32 amp;
    void *arena;

    func_02086368();
    OS_InitTick();
    OS_InitAlarm();
    RTC_Init();
    GX_Init();
    func_0207D148();
    if (OS_GetConsoleType() & 0x03000000) {
        SCFG_SetCpuSpeed(1);
        *(volatile u32 *)0x04004008 &= 0xFFFFDFFF;
        *(volatile u32 *)0x02FFFDF0 &= 0xFFFFDFFF;
    }
    *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 1;
    FS_Init(1);
    arena = DWC_StartUtilityEx(0, 0);
    DWC_StartUtilityEx((int)OS_AllocFromArenaLo(0, arena, 4), arena);
    sub_02061C0C(g_020A9E94, 0x30);
    if (sub_0202EB0C()) {
        g_020A9E80[0] = 0;
        g_020A9E80[1] = (u32)func_02005440;
        g_020A9E80[2] = 0;
        func_020053E4(g_020A9E84);
    }
    PM_GetAmp(&amp);
    if (amp == 1)
        PM_SetAmp(0);
}
