/*
 * file:     gfl_use_p01.c
 * unit:     yes
 * function: func_02005124, func_020051D8, func_02005204, func_0200520C, func_02005230, func_0200523C, func_020052EC, func_0200530C, func_02005328
 * address:  0x02005124
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_0200545C           0x0200545C  thumb
 *   OS_SetIrqFunction      0x02084774  arm
 *   OS_EnableIrqMask       0x02084968  arm
 *   GX_HBlankIntr          0x0207D3AC  arm
 *   GX_VBlankIntr          0x0207D3E4  arm
 *   OS_EnableInterrupts    0x02087974  arm
 *   func_020053EC          0x020053EC  thumb
 *   func_020055F8          0x020055F8  thumb
 *   sub_0200560C          0x0200560C  thumb
 *   func_02047990          0x02047990  arm
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_SleepThreadDirect   0x02085760  arm
 *   OS_WaitIrq             0x0208459C  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   g_020AA354             0x020AA354  data
 *   func_020392B8  0x020392B8  arm
 *   func_0203D26C  0x0203D26C  arm
 *   func_0203D29C  0x0203D29C  arm
 *   sub_02005610   0x02005610  thumb
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  data
 *   * 0x02006C01 and 0x02006C2D are two Thumb function pointers. Written as
 *   func_02034704   0x02034704  arm
 *   func_0200FB6C   0x0200FB6C  thumb
 *   func_02006C00   0x02006C00  thumb
 *   func_02006C2C   0x02006C2C  thumb
 *   ov010_id        0x0000000A  data
 *   ov011_id        0x0000000B  data
 *   func_02023FD8  0x02023FD8  thumb
 *   func_02022174  0x02022174  thumb
 *   func_0200F734  0x0200F734  thumb
 *   func_02005BC0  0x02005BC0  thumb
 *   func_020065FC  0x020065FC  thumb
 *   func_02026728  0x02026728  thumb
 *   func_02010DCC  0x02010DCC  thumb
 *   sub_02005C28  0x02005C28  thumb
 *   sub_02008390  0x02008390  thumb
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
 */
struct OSThread;
struct SaveCtrl;
struct Sub02007084Ctrl;
struct Sub02008700Obj;
struct Flags02008414;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef int            BOOL;

typedef unsigned char  u8;

extern void sub_0200545C(void);
extern void OS_SetIrqFunction(u32 mask, void (*fn)(void));
extern u32  OS_EnableIrqMask(u32 mask);
extern void GX_HBlankIntr(BOOL enable);
extern void GX_VBlankIntr(BOOL enable);
extern u32  OS_EnableInterrupts(void);
extern void func_020053EC(void);
extern void func_020055F8(void);
extern void sub_0200560C(void);
extern void func_02047990(void);
extern BOOL OS_IsThreadTerminated(struct OSThread *thread);
extern void OS_SleepThreadDirect(struct OSThread *thread, void *queue);
extern void OS_WaitIrq(BOOL clear, u32 mask);
extern void OS_WakeupThreadDirect(struct OSThread *thread);
extern int func_020392B8(void);
extern u32 func_0203D26C(void);
extern u32 func_0203D29C(void);
extern void sub_02005610(void);
extern void func_02005640(void);
extern void func_02082594(u32 dmaNo);
extern void func_02005430(void);
extern void func_0200567C(void);
extern int func_02034AC4(int handle);
extern void func_0201C41C(void *arg);
extern void func_0203CB34(u32 a, u32 b, u32 c, u32 d);
extern void func_02010794(u32 a0);
extern void func_020107CC(void);
extern void func_020312CC(u32 a0, u32 a1, u32 a2);
extern struct SaveCtrl *func_02006F20(int heap);
extern struct Sub02007084Ctrl *func_020070A4(void);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u8 func_02008414(const struct Flags02008414 *p);
extern void func_02012FF0(void *val);
extern void func_0200F6B8(void);
extern void func_0200F6D8(u32 kind);
extern void func_02034704(u32 a0);
extern void func_0201F344(u16 heap);
extern void func_020173D0(u32 heap);
extern void func_02005B24(void);
extern void func_02006544(u16 a0, u32 a1, u32 a2);
extern void func_0200530C(void *obj);
extern void func_020082DC(void);
extern void func_020266E0(u32 a0);
extern void func_02010DB4(void);
extern void func_0200FB6C(void);
extern void func_02006C00(u32 species, u32 form, u32 *out);
extern u32 func_02006C2C(u32 species, u32 form, void **rec, void **owner, u32 *rate1, u32 *rate2, u32 *addr, u8 *cryPitch);
extern void func_02023FD8(void);
extern void func_02022174(void);
extern void func_0200F734(void);
extern void func_02005BC0(void);
extern void func_020065FC(void);
extern void func_02026728(void);
extern void func_02010DCC(void);
extern unsigned int sub_02008390(char *a0);
extern void sub_02005C28(u32 on);
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
extern void sub_02061C0C(void *p, u32 capacity);
extern u32 sub_0202EB0C(void);
extern void func_02005440(void);
extern void func_020053E4(void *p);
extern void PM_GetAmp(u32 *out);
extern void PM_SetAmp(int on);
void NitroMain(void);
int func_020051D8(void);
void func_02005204(void);
void func_0200520C(void);
void func_02005230(void);
void func_0200523C(void);
void func_020052EC(void);
void sub_0200530C(void *obj);
void func_02005328(void);
extern struct OSThread g_020AA354;
extern u32  SDK_AUTOLOAD_MAIN_TWL_START[];
extern u8 ov010_id[];
extern u8 ov011_id[];
extern u32 g_020A9E94[];
extern u32 g_020A9E80[];
extern u32 g_020A9E84[];



#define reg_EXMEMCNT (*(volatile u16 *)0x04000204)


#define reg_IME      (*(volatile u16 *)0x04000208)



static inline u16 OS_EnableIrq(void)
{
    u16 prep = reg_IME;
    reg_IME = 1;
    return prep;
}



static inline void MI_SetMainMemoryPriority(u32 proc)
{
    reg_EXMEMCNT = (u16)((reg_EXMEMCNT & ~0x8000) | (proc << 15));
}



void NitroMain(void)
{
    BOOL busy;

    func_02005328();
    sub_0200545C();
    OS_SetIrqFunction(2, func_02005204);
    OS_SetIrqFunction(1, func_0200520C);
    (void)OS_EnableIrqMask(3);
    (void)OS_EnableIrq();
    GX_HBlankIntr(1);
    GX_VBlankIntr(1);
    (void)OS_EnableInterrupts();
    func_0200523C();
    for (;;) {
        func_020053EC();
        func_020055F8();
        func_020052EC();
        sub_0200560C();
        func_02047990();
        busy = func_020051D8();
        if (busy)
            MI_SetMainMemoryPriority(0);
        if (!OS_IsThreadTerminated(&g_020AA354))
            OS_SleepThreadDirect(&g_020AA354, 0);
        OS_WaitIrq(1, 1);
        func_02005230();
        if (!OS_IsThreadTerminated(&g_020AA354))
            OS_WakeupThreadDirect(&g_020AA354);
        if (busy)
            MI_SetMainMemoryPriority(1);
    }
}



/*
 * Boot path, 0x020051D8..0x0200520C: a three-step readiness test (each
 * step its own early `return 0`, per the image's four epilogues) and the
 * unlabelled forwarding thunk func_02005204 to sub_02005610
 * (src/matched/unit_0200560C.c), a pool-word tail call.
 *
 * Rewritten wave 16 from src/pending/func_020051D8.c, a one-line generated
 * body with implicit declarations that was EXACT* on its own.
 * Integrator: seed 0x02005204 (unlabelled follower, member of this unit).
 */
int func_020051D8(void)
{
    if (func_020392B8() > 1)
        return 0;
    if (func_0203D26C() != 0)
        return 0;
    if (func_0203D29C() == 0)
        return 1;
    return 0;
}



void func_02005204(void)
{
    sub_02005610();
}



/*
 * One of the three callers of the boot path's scene switch (.text init
 * helpers): run func_02005640, set bit 0 of the word at the end of the
 * arm9_autoload1_main_twl region, then enter mode 3.
 *
 * The address is *two* pool words, not one: the listing writes
 * 0x02FE0000 (`arm9_autoload1_main_twl+0x0`) and the plain literal 0x3FF8,
 * and the load is a register-offset `ldr r2, [r3, r1]`.  That split is the
 * tell that the source named the linker-defined region symbol and added a
 * byte offset to it rather than writing the absolute address: a constant
 * 0x02FE3FF8 pools as a single word with no relocation at all (47 other
 * sites in the image hold 0x02FE3000 outright).  Same finding as
 * src/pending/sub_02030534.c's header, where the base is 0x02FE0000 and the
 * offset 0x3000 fits an `add`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200520C.c \
 *       --func func_0200520C --addr 0x0200520C --cc 1.1p1 --thumb
 */
void func_0200520C(void)
{
    func_02005640();
    *(u32 *)((u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3FF8) |= 1;
    func_02082594(3);
}


void func_02005230(void)
{
    func_02005430();
    func_0200567C();
}



/*
 * Blocking class: label. Seven `bl` sites in this range have no branch witness
 * anywhere else in the image, so their relocation fields stay wildcarded:
 *   0x02006F20 (row of this lane, still unfiled), 0x02034704, 0x02005B24,
 *   0x02006544, 0x020082DC, 0x020266E0, 0x02010DB4.
 * Every other site resolves (label / matched) and every concrete byte in the
 * 152-byte body plus its 24-byte pool reproduces: compiled 176 bytes against
 * the original's 176, 0 concrete differences.
 *
 * Two spellings the original needs and that are not guessable from the bytes:
 *   * the first two calls pass FS_OVERLAY_ID-style absolute symbols, not the
 *     numbers 10 and 11. `func_02034AC4(10)` compiles `movs r0, #0xa` (2 bytes,
 *     no pool word) where the original has `ldr r0, [pc, #0x94]` over a pool
 *     word 0x0000000A; declaring `extern u8 ov010_id[]` at 0x0000000A in the
 *     symbols block is what puts the pool word back. Same for 0x0000000B.
 *     (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md)
 *   * 0x02006C01 and 0x02006C2D are two Thumb function pointers. Written as
 *     plain integers mwcc folds the second to `adds r2, r1, #0x2c` off the
 *     first; written as `&func_02006C00` / `&func_02006C2C` the two ABS32
 *     relocations keep both pool words, which is the original's shape.
 */
void func_0200523C(void)
{
    int v = 0xC;

    func_02034AC4((int)ov010_id);
    func_02034AC4((int)ov011_id);
    func_0201C41C(0);
    func_0203CB34(1, 0, 1, v);
    func_02010794(v);
    func_020107CC();
    func_020312CC(v - 0xD, (u32)(void *)0x020A0480, 0);
    func_02006F20(7);
    func_02008414((const struct Flags02008414 *)func_0200873C(func_020070A4()));
    func_02012FF0(func_020070A4());
    func_0200F6B8();
    func_0200F6D8(8);
    func_02034704((u32)&func_0200FB6C);
    func_0201F344(0);
    func_020173D0(0);
    func_02005B24();
    func_02006544(1, (u32)&func_02006C00, (u32)&func_02006C2C);
    func_0200530C(func_0200873C(func_020070A4()));
    func_020082DC();
    func_020266E0(1);
    func_02010DB4();
}



/*
 * Seven unconditional calls in a row, no arguments and no return value: the
 * tail of the boot sequence, run immediately after func_0200520C.  Every
 * callee is an ordinary Thumb `bl` (the second halfword's bit 12 is set in
 * all seven encodings, so none of them is a BLX to ARM code).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020052EC.c \
 *       --func func_020052EC --addr 0x020052EC --cc 1.1p1 --thumb
 */
void func_020052EC(void)
{
    func_02023FD8();
    func_02022174();
    func_0200F734();
    func_02005BC0();
    func_020065FC();
    func_02026728();
    func_02010DCC();
}



/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * One function of the boot path, 26 bytes: a test on a two-bit field of the
 * object passed in r0 (sub_02008390 reads it), whose two arms pass 1 and 0
 * to the same one argument routine.  Both arms keep their own call and their
 * own `pop`, which is what an `if`/`else` with a call in each arm compiles to;
 * they are not tail merged, so the call is inside the arms in the source and
 * not written once after the test.
 *
 * The polarity is fixed by the fall through, per
 * docs/idioms/the-fall-through-arm-is-the-source-order.md: the branch is
 * `bne`, so the `== 0` arm is the one the source wrote first and it is the arm
 * that passes 1.
 *
 * It is a range of one function because both of its neighbours are held open
 * by attestation, not because the original file stops here.  See the near miss
 * register in the header of src/matched/unit_020056A0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200530C.c \
 *       --addr 0x0200530C --thumb
 */
void sub_0200530C(void *obj)
{
    if (sub_02008390(obj) == 0) {
        sub_02005C28(1);
    } else {
        sub_02005C28(0);
    }
}


/*
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
