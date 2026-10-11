/*
 * file:     gfl_use.c
 * unit:     yes
 * function: func_02005124, func_020051D8, func_02005204, func_0200520C, func_02005230, func_0200523C, func_020052EC, func_0200530C, func_02005328, func_020053EC, sub_02005430, func_02005438, func_02005440, sub_0200545C, func_020055F8, func_0200560C, func_02005610, func_02005624, func_02005640, func_02005654, func_0200566C, func_0200567C, func_020056A0, func_020056BC, func_020056C8, func_020056D0, func_020056EC, func_02005728, func_0200575C, func_02005768, func_02005794, func_020057AC, func_020057C4, func_020057DC, func_020057E8, func_02005834, func_02005858, func_02005888, func_020058D0, func_02005900, func_0200590C, func_02005924, func_0200597C, func_020059A0, func_020059C8, func_02005A00, func_02005A4C, func_02005A98, func_02005B04, func_02005B24, func_02005B74
 * address:  0x02005124
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * The four 8-byte ARM linker veneers (`ldr pc, [pc, #-4]`) are asm functions under
 * `#pragma thumb off` ... `#pragma thumb reset`; their callers are Thumb, so the
 * interworking calls are BLX.
 *
 * symbols:
 *   OS_SetIrqFunction      0x02084774  arm
 *   OS_EnableIrqMask       0x02084968  arm
 *   GX_HBlankIntr          0x0207D3AC  arm
 *   GX_VBlankIntr          0x0207D3E4  arm
 *   OS_EnableInterrupts    0x02087974  arm
 *   func_02047990          0x02047990  arm
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_SleepThreadDirect   0x02085760  arm
 *   OS_WaitIrq             0x0208459C  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   g_020AA354             0x020AA354  data
 *   func_020392B8  0x020392B8  arm
 *   func_0203D26C  0x0203D26C  arm
 *   func_0203D29C  0x0203D29C  arm
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  data
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
 *   PM_GetAmp           0x0208C030  arm
 *   PM_SetAmp           0x0208BEF0  arm
 *   g_020A9E94          0x020A9E94  data
 *   g_020A9E80          0x020A9E80  data
 *   g_020A9E84          0x020A9E84  data
 *   func_020351D0  0x020351D0  arm
 *   func_02061C44  0x02061C44  arm
 *   func_020911A0  0x020911A0  arm
 *   g_020AA194      0x020AA194  data
 *   s_gfl_use_c     0x020A7004  data
 *   d_0209D8A0      0x0209D8A0  data
 *   d_0209D8B0      0x0209D8B0  data
 *   d_020A6C58      0x020A6C58  data
 *   func_0202F768   0x0202F768  thumb
 *   func_0202F774   0x0202F774  thumb
 *   OS_IsRunOnTwl       0x02085D3C  arm
 *   OS_GetArenaHi       0x0208656C  arm
 *   OS_GetArenaLo       0x02086580  arm
 *   OS_InitAlloc        0x02086A50  arm
 *   OS_SetArenaLo       0x02086774  arm
 *   OS_CreateExtraHeap  0x02086B98  arm
 *   OS_AllocFromHeap    0x020868E0  arm
 *   func_020057AC   0x020057AC  thumb
 *   func_02030D28     0x02030D28  arm
 *   func_02030DA8     0x02030DA8  arm
 *   func_0203F034     0x0203F034  arm
 *   func_0203F258     0x0203F258  arm
 *   _ull_mul          0x0209C054  arm
 *   sub_0200575C_Table  0x020A6C58  data
 *   func_02034F5C       0x02034F5C  arm
 *   func_0203630C       0x0203630C  arm
 *   veneer_02072788  0x02072788  arm
 *   func_0203508C    0x0203508C  arm
 *   func_02035108  0x02035108  arm
 *   sub_020057DC_Cur    0x020AA1AC  data
 *   sub_020057DC_Table  0x020AA1B8  data
 *   func_02072DB0       0x02072DB0  arm
 *   func_02072E9C       0x02072E9C  arm
 *   func_02072EA8       0x02072EA8  arm
 *   func_02074894       0x02074894  arm
 *   func_020748E0       0x020748E0  arm
 *   func_02074AC4       0x02074AC4  arm
 *   sub_02005A4C_Cur    0x020AA1AC  data
 *   sub_02005A4C_Table  0x020AA1B8  data
 *   sub_02005A98_Cur    0x020AA1AC  data
 *   sub_02005A98_Table  0x020AA1B8  data
 *   func_0207482C       0x0207482C  arm
 *   func_02074A6C       0x02074A6C  arm
 *   sub_02005B04_Cur  0x020AA1AC  data
 *   g_020AA9B4   0x020AA9B4  data
 *   g_020AA260   0x020AA260  data
 *   g_020A7010   0x020A7010  data
 *   g_020AA2BC   0x020AA2BC  data
 *   func_020726D0  0x020726D0  arm
 *   func_020746E8  0x020746E8  arm
 *   func_02073FB8  0x02073FB8  arm
 *   func_02085D3C  0x02085D3C  arm
 */
#define reg_EXMEMCNT (*(volatile u16 *)0x04000204)
#define reg_IME      (*(volatile u16 *)0x04000208)
struct OSThread;
struct SaveCtrl;
struct Sub02007084Ctrl;
struct Sub02008700Obj;
struct Flags02008414;
struct Ctx;
struct Node;
struct Lcg64;
struct S;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef int            BOOL;

typedef unsigned char  u8;

typedef unsigned long long u64;

struct GflHeaps {
    u64   seed;
    u64   mul;
    u64   add;
    void *unk18;
    void *unk1C;
    void *unk20;
    void *unk24;
};

struct GflSys {
    void *unk00;
    u32   unk04;
    void (*unk08)(void *);
    u32   unk0C;
    struct GflHeaps *heaps;
    void *unk14;
};

typedef signed int     s32;

struct Sub020057DCSlot {
    u32 unk00;
    u16 unk04;
    u16 unk06;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
};

struct Sub020057DCCur {
    u16   unk00;
    u16   unk02;
    int   index;
    u32 **unk08;
};

struct Sub02005A4CSlot {
    u32 unk00;
    u16 unk04;
    u16 unk06;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
};

struct Sub02005A4CCur {
    u16   unk00;
    u16   unk02;
    int   index;
    u32 **unk08;
};

struct Sub02005A98Slot {
    u32 unk00;
    u16 unk04;
    u16 unk06;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
};

struct Sub02005A98Cur {
    u16   unk00;
    u16   unk02;
    int   index;
    u32 **unk08;
};

struct Sub02005A98Hdr {
    u32 n;
    u32 status;
};

struct Sub02005B04Cur {
    u16   unk00;
    u16   unk02;
    int   index;
    u32 **unk08;
};

extern void OS_SetIrqFunction(u32 mask, void (*fn)(void));
extern u32  OS_EnableIrqMask(u32 mask);
extern void GX_HBlankIntr(BOOL enable);
extern void GX_VBlankIntr(BOOL enable);
extern u32  OS_EnableInterrupts(void);
extern void func_02047990(void);
extern BOOL OS_IsThreadTerminated(struct OSThread *thread);
extern void OS_SleepThreadDirect(struct OSThread *thread, void *queue);
extern void OS_WaitIrq(BOOL clear, u32 mask);
extern void OS_WakeupThreadDirect(struct OSThread *thread);
extern int func_020392B8(void);
extern u32 func_0203D26C(void);
extern u32 func_0203D29C(void);
extern void func_02005640(void);
extern void func_02082594(u32 dmaNo);
extern void func_02005430(void);
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
extern void func_0273154C(void *p);
extern void PM_GetAmp(u32 *out);
extern void PM_SetAmp(int on);
extern int func_020351D0(u32 mode);
extern int func_027315D0(void);
extern int func_027314F0(void);
/* ARM, and attested by a branch to it from an overlay. */
extern void func_02061C44(void);
extern void func_020911A0(void);
extern void func_027315C0(int v);
extern u32   OS_IsRunOnTwl(void);
extern void *OS_GetArenaHi(u32 id);
extern void *OS_GetArenaLo(u32 id);
extern void *OS_InitAlloc(u32 id, void *lo, void *hi, u32 n);
extern void  OS_SetArenaLo(u32 id, void *lo);
extern u32   OS_CreateExtraHeap(u32 id);
extern void *OS_AllocFromHeap(u32 id, u32 heap, u32 size);
extern void func_02030608(u32 a, u32 b, u32 c, u32 d);
extern void  func_02030BA4(u32 a);
extern void  func_0203064C(u32 a, u32 b, u32 c);
extern void  func_02030678(void *a, u32 b, u32 c);
extern void  func_0203EF5C(u32 a);
extern void func_02048CEC(u32 a, u32 b);
extern void func_02034E24(u32 heap, u8 mode);
extern void  func_02034978(void);
extern void func_020346EC(u32 a, u32 b, u32 c);
extern void func_0203499C(u32 heap, int n0, int n1, int n2);
extern void  func_0203129C(u32 a);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, unsigned short tag);
extern u32   func_02030CB0(u32 n);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void  func_0204E5E8(u32 a);
extern void func_020316C8(u32 a0, u32 a1, u32 a2);
extern void  func_0204E130(u32 a);
extern void  func_0203F3B4(void);
extern void  func_020057AC(void);
extern void func_0204E6F4(s32 a);
extern void  func_0202F768(void);
extern void func_0202F774(u32 on);
extern void func_02034F5C(void);
extern int func_0200F2D4(void);
extern int func_020312B4(void);
extern void func_0203F3F0(void);
extern int func_02030D28(struct Ctx *c);
extern struct Node *func_02030DA8(struct Ctx *c, void (*callback)(struct Node *, void *), void *work, u32 key);
extern int func_020419E4(int);
extern int func_02050A70(int);
extern int func_0204E638(int);
extern void  func_0203F034(u32 seed);
extern void func_0203F258(struct Lcg64 *out);
extern unsigned int func_0203630C(void);
/* The linker veneer in front of SND_SetMasterVolume; ARM. */
extern void veneer_02072788(u32 volume);
/* Registers a pair of callbacks.  ARM, and in another packet's territory. */
extern void func_0203508C(u32 a, u32 b, u32 c);
extern u32  func_02035108(void);
extern void func_02072DB0(int idx, int v);
extern void func_02072E9C(void **r0);
extern void func_02072EA8(u32 * volatile *pp);
extern int   func_02074894(struct S *a);
extern void  func_020748E0(u32 *a, u32 b);
extern u32 func_02074AC4(u32 a, u32 b, u32 c);
extern u32 func_0207482C(u32 *a, u32 b, u32 c, u32 d, u32 e);
extern u32   func_02074A6C(u32 a, u32 b);
extern void func_020726D0(void);
extern u32  func_020746E8(u32 off, u32 size);
extern void func_02073FB8(char *a, char *b, u32 c, u32 d);
extern int  func_02085D3C(void);
extern void func_02704364(void);
extern u32 func_020754C4(u32 a);
extern void func_020057DC(u32 **a);
extern void *func_02074518(int index);
extern void func_02074A54(int a, int b);
extern void func_02006118(void);
extern void func_02005888(u16 a);
extern void func_02005F5C(void);
void NitroMain(void);
int func_020051D8(void);
void func_02005204(void);
void func_0200520C(void);
void func_02005230(void);
void func_0200523C(void);
void func_020052EC(void);
void sub_0200530C(void *obj);
void func_02005328(void);
void func_020053EC(void);
void sub_02005430(void);
void func_02005438(void);
void func_02005440(void);
void sub_0200545C(void);
void func_020055F8(void);
void sub_0200560C(void);
void sub_02005610(void);
void *sub_02005624(void (*a)(struct Node *, void *), void *b, u32 c);
void sub_02005640(void);
u32 sub_02005654(void (*fn)(void *), void *arg);
void sub_0200566C(void);
void func_0200567C(void);
void *sub_020056A0(void (*callback)(struct Node *, void *), void *work, u32 key);
void *sub_020056BC(void);
void sub_020056C8(void *heap);
void sub_020056D0(void);
u32 sub_020056EC(u32 range);
u32 sub_02005728(u32 range);
void *sub_0200575C(u32 index);
void sub_02005768(void);
void sub_02005794(void);
void sub_020057A0(void);
void sub_020057AC(void);
int func_020057C4(void);
void sub_020057DC(u32 **a);
void sub_020057E8(u32 i);
void sub_02005834(u32 v);
void sub_02005858(void);
void sub_02005888(u16 a);
u16 sub_020058D0(void);
u32 sub_02005900(void);
u32 *sub_0200590C(void);
int sub_02005924(u32 a);
void sub_0200597C(void);
int sub_020059A0(u32 a);
void sub_020059C8(void);
int sub_02005A00(void);
int sub_02005A4C(void);
struct Sub02005A98Hdr *func_02005A98(const u32 *a0, u32 a1);
void sub_02005B04(const u32 *arg);
void func_02005B24(void);
void func_02005B74(int a0);
extern struct OSThread g_020AA354;
extern u32  SDK_AUTOLOAD_MAIN_TWL_START[];
extern u8 ov010_id[];
extern u8 ov011_id[];
extern u32 g_020A9E94[];
extern u32 g_020A9E80[];
extern u32 g_020A9E84[];
extern struct GflSys g_020AA194;
extern u8 s_gfl_use_c[];
extern u8 d_0209D8A0[];
extern u8 d_0209D8B0[];
extern u8 d_020A6C58[];
extern void *sub_0200575C_Table[];
extern struct Sub020057DCCur  sub_020057DC_Cur;
extern struct Sub020057DCSlot sub_020057DC_Table[];
extern struct Sub02005A4CCur  sub_02005A4C_Cur;
extern struct Sub02005A4CSlot sub_02005A4C_Table[];
extern struct Sub02005A98Cur  sub_02005A98_Cur;
extern struct Sub02005A98Slot sub_02005A98_Table[];
extern struct Sub02005B04Cur sub_02005B04_Cur;
extern char g_020AA9B4[];
extern char g_020AA260[];
extern char g_020A7010[];
extern char g_020AA2BC[];


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
        func_0273154C(g_020A9E84);
    }
    PM_GetAmp(&amp);
    if (amp == 1)
        PM_SetAmp(0);
}


void func_020053EC(void)
{
    if (g_020A9E80[0] == 0) {
        return;
    }
    if (func_020351D0(2) != 0) {
        return;
    }
    if (func_027315D0() != 0) {
        return;
    }
    *(volatile u16 *)0x04000204 |= 0x8000;
    func_027314F0();
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * One eight byte tail call, the shape
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes: a pool word and a
 * `bx`, no prologue, no argument set up.  sub_02005230 calls it as the first
 * half of its two step init.
 *
 * The range is one function wide because of its neighbours rather than
 * because of itself.  Immediately before it is the linker veneer at
 * 0x02005428, which is not compiled code at all and cannot be inside any
 * unit.  Immediately after it, sub_02005438 is the same eight byte shape
 * around CTRDG_DummyInit at 0x020911A0, and the only word in the image that
 * holds 0x020911A0 is that function's own pool word, so the `literal` class
 * discards its only witness and no cut can help.  See the near miss register
 * in the header of src/matched/unit_020056A0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02005430.c \
 *       --addr 0x02005430 --thumb
 */
void sub_02005430(void)
{
    func_02061C44();
}


/*
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * A one-instruction forwarder: `ldr r3, [pc, #0]; bx r3` with the pool word
 * holding the callee.  The word is even, so the callee is ARM - the Thumb
 * tail call of the tail-call idiom, crossing the interworking boundary.  It
 * is four bytes of code plus its own two-word literal pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02005438.c \
 *       --func func_02005438 --addr 0x02005438 --cc 1.1p1 --thumb
 */
void func_02005438(void)
{
    func_020911A0();
}


void func_02005440(void)
{
    func_027315C0(0);
    g_020A9E80[0] = 1;
}


/*
 * gfl_use.c, the file's __FILE__ anchor function: system boot set-up.  On a
 * non-TWL console, carve the main arena into the OS heap (Hi read before Lo,
 * hence the named local), create the extra heap and take a 0x3F00 block
 * from it; then the heap system on the console's arena table, the graphics,
 * card and sound bring-up, the three heap-tracked allocations at lines
 * 0x117 / 0x119 / 0x11C of gfl_use.c (s_gfl_use_c is the __FILE__ pointer),
 * and the task/callback installs.
 *
 * Closed in wave 14.  The pool was misread by one word in the older note
 * (docs/notes/sub_0200545C.c.txt): 0x020A6C58 is func_02048CEC's argument
 * and 0x02005769 (sub_02005768, src/matched/unit_0200575C.c) is
 * func_020346EC's third, and the two words 0x0202F769 / 0x0202F775 are
 * Thumb pointers to two unlabelled callback leaves of time_icon.c, filed
 * EXACT this wave as src/matched/func_0202F768.c and func_0202F774.c, which
 * is what attests them (`matched`).  d_0209D8A0 / d_0209D8B0 now resolve on
 * sole-ref.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200545C.c \
 *       --func sub_0200545C --addr 0x0200545C --cc 1.1p1 --thumb
 */
void sub_0200545C(void)
{
    if (OS_IsRunOnTwl() == 0) {
        void *hi = OS_GetArenaHi(0);
        OS_SetArenaLo(0, OS_InitAlloc(0, OS_GetArenaLo(0), hi, 1));
        g_020AA194.unk04 = OS_CreateExtraHeap(0);
        g_020AA194.unk14 = OS_AllocFromHeap(0, g_020AA194.unk04, 0x3F00);
    }

    if (OS_IsRunOnTwl() != 0) {
        func_02030608((u32)d_0209D8A0, 2, 0xAD, 0);
    } else {
        func_02030608((u32)d_0209D8B0, 2, 0xAD, 0);
    }

    func_02030BA4(0x2000);
    func_0203064C(1, 7, 0x25000);

    if (OS_IsRunOnTwl() == 0) {
        func_02030678(g_020AA194.unk14, 0x3F00, 9);
    } else {
        func_0203064C(1, 9, 0x3F00);
    }

    func_0203EF5C(0);
    func_02048CEC((u32)d_020A6C58, 0xEB);
    func_02034E24(0, 0);

    if (OS_GetConsoleType() & 0x81000000) {
        func_02034978();
    } else {
        func_020346EC(0, 0, (u32)sub_02005768);
    }

    func_0203499C(0, 0x10, 4, 4);
    func_0203129C(0);

    g_020AA194.heaps = func_02030734(0, 0x28, 0, (const char *)s_gfl_use_c, 0x117);
    g_020AA194.heaps->unk1C = func_02030734(0, func_02030CB0(4), 0, (const char *)s_gfl_use_c, 0x119);
    g_020AA194.heaps->unk18 = func_02030CBC(4, g_020AA194.heaps->unk1C);
    g_020AA194.heaps->unk24 = func_02030734(0, func_02030CB0(0x10), 0, (const char *)s_gfl_use_c, 0x11C);
    g_020AA194.heaps->unk20 = func_02030CBC(0x10, g_020AA194.heaps->unk24);

    sub_020056D0();
    func_0204E5E8(0);
    func_020316C8(7, (u32)func_0202F768, (u32)func_0202F774);
    func_0204E130(0);
    func_0203F3B4();
    g_020AA194.unk0C = 0;
    sub_0200566C();
    func_020057AC();
    func_0204E6F4(2);
}


void func_020055F8(void)
{
    func_02034F5C();
    func_0200F2D4();
    func_020312B4();
    func_0203F3F0();
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 *           sub_02005654, sub_0200566C
 *
 * Six functions on the one system record at 0x020AA194 that the whole of this
 * packet reaches its state through.  Three of the six carry no label, because
 * they save nothing: sub_0200560C is two bytes of `bx lr` padded to four, the
 * empty hook shape
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md records;
 * sub_02005610 is a tail call through a pool word; and sub_02005654 is a two
 * arm register-and-return.
 *
 * sub_02005640 calls the hook at +8 with the argument at +0 when the hook is
 * present, sub_02005654 installs the pair only when the slot is free, and
 * sub_0200566C clears both.  In all three the store to +8 comes before the
 * store to +0, which is the source order.
 *
 * The record's +0x10 is the object src/matched/unit_020056A0.c calls its
 * heaps; the two files name it separately because each pins its own address
 * block.  The range stops at 0x0200567C because sub_0200567C is held open by
 * one unresolved call site; see the near miss register in the header of
 * src/matched/unit_020056A0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200560C.c \
 *       --addr 0x0200560C --thumb
 */
void sub_0200560C(void)
{
}


void sub_02005610(void)
{
    func_02030D28(g_020AA194.heaps->unk18);
}


void *sub_02005624(void (*a)(struct Node *, void *), void *b, u32 c)
{
    return func_02030DA8(g_020AA194.heaps->unk18, a, b, c);
}


void sub_02005640(void)
{
    if (g_020AA194.unk08 != 0) {
        g_020AA194.unk08(g_020AA194.unk00);
    }
}


u32 sub_02005654(void (*fn)(void *), void *arg)
{
    if (g_020AA194.unk08 != 0) {
        return 0;
    }
    g_020AA194.unk08 = fn;
    g_020AA194.unk00 = arg;
    return 1;
}


void sub_0200566C(void)
{
    g_020AA194.unk08 = 0;
    g_020AA194.unk00 = 0;
}


void func_0200567C(void)
{
    func_0204E638(func_02050A70(func_020419E4(func_02030D28((struct Ctx *)g_020AA194.heaps->unk20))));
    g_020AA194.unk0C++;
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * The tail of the packet: the second heap's allocator wrapper, the shutdown
 * pair, and the two random number draws.  0x020AA194 is the same system
 * record src/matched/unit_0200560C.c reaches, and the pointer at its +0x10 is
 * the same object; the two files name it separately because each pins its own
 * address block.
 *
 * The two draws are a 64 bit linear congruential generator.  0x0209C054 is
 * mwccarm's own `_ull_mul` runtime helper (`umull` plus two `mla`, ARM, at the
 * near end of the helper block that also holds `_u32_div_f`), so the pair of
 * calls in each function is one 64 bit multiply each and not an SDK call:
 *
 *   seed = mul * seed + add;
 *   return (u32)(((seed >> 32) * range) >> 32);
 *
 * The second multiply is what makes the shape readable.  `range` is a u32 and
 * so is the high half of the seed, but the helper is called with r1 and r3
 * both zeroed, which is two operands already widened to 64 bits; that is
 * `(seed >> 32) * range` on a `u64` seed and not a `umull` of two words, and
 * taking the returned r1 is the `>> 32`.  sub_020056EC is the same draw with
 * a range of zero meaning "the whole word", and its two arms merge on r1,
 * which is why the zero arm loads the high half into r1 and moves rather than
 * loading it into r0.
 *
 * sub_020056EC reloads the high half from memory after the step and
 * sub_02005728 keeps it in the register the `adcs` left it in.  That is not a
 * difference in the source: it falls out of the branch in the first one, and
 * both come from the same expression.
 *
 * Three of the six carry no label, all because they save nothing.
 * sub_020056BC is a two load getter and sub_020056C8 is a tail call through a
 * pool word.  sub_020056C8 is in this range rather than a range of its own
 * because sub_020056D0 is its only caller anywhere in the image, so the call
 * has to be the `local` class; splitting them leaves it with no witness at
 * all.
 *
 * ------------------------------------------------------------------------
 * The near miss register for pkt_020051D8
 *
 * This packet is the system boot path, and that is exactly the shape of code
 * the honesty rule is hardest on: it calls each subsystem's initialiser once
 * and nothing else in the 3.9 MB image calls it again, so the only witness
 * for the target address is the call under test.  Of the packet's 1160 code
 * bytes, 334 are matched in four files (0x0200530C, 0x02005430, 0x0200560C,
 * 0x020056A0) and the rest is listed here with the class and the census that
 * blocks it.  None of it is a codegen failure; nothing below was written and
 * then rejected for wrong bytes.
 *
 *   0x020051D8..0x02005202, 42 bytes.  `label`, 0x0203D26C has one witness
 *       image wide and it is the `blx` at 0x020051E6 inside the function.
 *   0x02005204..0x0200520C, 8 bytes.  A tail call whose pool word holds
 *       0x02005611.  0x02005610 has no `func_` label, because it saves
 *       nothing, and the word appears in exactly one literal pool in the
 *       image, its own at 0x02005208, so `label` has no label and `literal`
 *       discards its only witness.  Seeding the label would not help: nothing
 *       in the image branches to 0x02005610 either.
 *   0x0200520C..0x02005230, 36 bytes.  `label`, the only caller of
 *       sub_02005640 is the `bl` at 0x0200520E.  sub_02005640 is matched, in
 *       src/matched/unit_0200560C.c, but it is 0x434 bytes away with two
 *       blocked functions and three linker veneers in between, so no
 *       contiguous range makes the site `local`.
 *   0x02005230..0x0200523C, 12 bytes.  `label` twice: the only caller of
 *       sub_02005430 is the `bl` at 0x02005232 and the only caller of
 *       sub_0200567C is the `bl` at 0x02005236.  Same obstruction as above in
 *       both directions at once.
 *   0x0200523C..0x020052EC, 176 bytes.  19 unresolved sites, 18 of them
 *       `label` with a census of one, plus 0x020A0480 whose only literal
 *       witness is the pool word at 0x020052DC.  This is the once-per-boot
 *       call sequence itself.
 *   0x020052EC..0x0200530C, 32 bytes.  5 unresolved sites, all `label` with a
 *       census of one.
 *   0x02005328..0x020053E4, 188 bytes.  11 unresolved sites.  Two are
 *       structural rather than merely rare: the veneer at 0x020053E4, whose
 *       only witness is the `blx` at 0x020053AA, and the pool word at
 *       0x020053DC naming sub_02005440, an address no other word or branch in
 *       the image mentions.
 *   0x020053EC..0x02005420, 52 bytes.  The veneers at 0x02005420 and
 *       0x02005428, each witnessed only by its own call site at 0x02005400
 *       and 0x02005412, plus EL_Export at 0x020351D0 with a census of one.
 *   0x02005438..0x02005440, 8 bytes.  `literal`, CTRDG_DummyInit at
 *       0x020911A0 is named by exactly one word in the image and it is this
 *       function's own pool word at 0x0200543C.  It is a labelled SDK symbol,
 *       but no branch anywhere reaches it, so the `label` class has nothing.
 *   0x02005440..0x02005454, 20 bytes.  The veneer at 0x02005454, witnessed
 *       only by the `blx` at 0x02005444.
 *   0x0200545C..0x020055F8, 412 bytes.  19 unresolved sites; the packet's
 *       largest function and its arena, heap and DWC set up.
 *   0x020055F8..0x0200560C, 20 bytes.  3 unresolved sites, all with a census
 *       of one.
 *   0x0200567C..0x020056A0, 36 bytes.  One unresolved site: 0x02050A70,
 *       `label`, one witness image wide and it is the `blx` at 0x0200568C
 *       inside the function.  This is the single function that keeps
 *       src/matched/unit_0200560C.c and this file apart; the day anything
 *       else in the image calls 0x02050A70, the two files and it become one
 *       336 byte range.
 *
 * The four ARM stubs at 0x020053E4, 0x02005420, 0x02005428 and 0x02005454 are
 * not functions and are in no file here.  Each is `ldr pc, [pc, #-4]` and a
 * pointer word, and each pointer (0x0273154C, 0x027315D0, 0x027314F0,
 * 0x027315C0) lies outside every region of layout/layout.json, which is why
 * the `veneer` attestation class cannot carry them: its fourth condition
 * wants the pointer to name code in a known region.  See
 * docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md
 * for what they are and why they force the unit boundaries in this packet.
 * ------------------------------------------------------------------------
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020056A0.c \
 *       --addr 0x020056A0 --thumb
 */
void *sub_020056A0(void (*callback)(struct Node *, void *), void *work, u32 key)
{
    return func_02030DA8(g_020AA194.heaps->unk20, callback, work, key);
}


void *sub_020056BC(void)
{
    return g_020AA194.heaps->unk20;
}


void sub_020056C8(void *heap)
{
    func_0203F258(heap);
}


void sub_020056D0(void)
{
    sub_020056C8(g_020AA194.heaps);
    func_0203F034(sub_020056EC(0));
}


u32 sub_020056EC(u32 range)
{
    struct GflHeaps *p = g_020AA194.heaps;
    u32 v;

    p->seed = p->mul * p->seed + p->add;
    if (range == 0) {
        v = (u32)(p->seed >> 32);
    } else {
        v = (u32)(((p->seed >> 32) * range) >> 32);
    }
    return v;
}


u32 sub_02005728(u32 range)
{
    struct GflHeaps *p = g_020AA194.heaps;

    p->seed = p->mul * p->seed + p->add;
    return (u32)(((p->seed >> 32) * range) >> 32);
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * A pointer table lookup and a spin loop.  sub_0200575C was already matched
 * as a single function in arm9/legacy.json; it is the first function of this
 * range and is absorbed here.
 *
 * sub_02005768 waits until four bits of func_0203630C's result are all set,
 * pumping func_02034F5C once per turn.  The four masks are 0x200, 0x100,
 * 0x400 and 0x800 and none of them is materialised with a literal pool word:
 * the compiler builds 0x100 with `movs`/`lsls` and then derives the other
 * three from it with one `lsls` each, hoisted out of the loop.  Testing them
 * as one combined `(x & 0xF00) == 0xF00` gives a single `ldr` from a pool and
 * a different loop, so the four separate short circuited tests are in the
 * source, and their order in the source is 0x200, 0x100, 0x400, 0x800, not
 * the ascending order the hoisted constants suggest.
 */
void *sub_0200575C(u32 index)
{
    return sub_0200575C_Table[index];
}


void sub_02005768(void)
{
    u32 x;

    do {
        func_02034F5C();
        x = func_0203630C();
    } while (!(x & 0x200) || !(x & 0x100) || !(x & 0x400) || !(x & 0x800));
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * Two twelve byte thunks that set the master volume to its two extremes, and
 * the function that hands both of them to func_0203508C as a pair of
 * callbacks.  48 bytes, three sections, three literal pools.
 *
 * This range was the near miss recorded in the header of
 * src/matched/unit_020057DC.c, and what closes it is the `veneer` attestation
 * class.  Both thunks tail call 0x02072788, and the bytes there are not a
 * function the analysis can see:
 *
 *   02072788  E59FC000   ldr ip, [pc, #0]
 *   0207278C  E12FFF1C   bx  ip
 *   02072790  0208970C   .word SND_SetMasterVolume
 *
 * a linker veneer.  It has no prologue, so disasm.py's sweep never fires on
 * it and the listing prints the twelve bytes as data; nothing in the image
 * branches to it, so the `label` class has nothing to offer; and the only two
 * words in the 3.9 MB image that hold its address are the two pool words
 * inside this very range, so the `literal` class discards both.  The stub
 * itself is the evidence: a fixed twelve byte encoding that loads a constant
 * into ip and branches to it, with the constant naming SND_SetMasterVolume in
 * layout/symbols_sdk.txt, read entirely from outside the compared range.  See
 * "The veneer class" in docs/MATCHING.md and
 * docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md.
 *
 * The extern is declared at the veneer's address rather than at
 * SND_SetMasterVolume's, because that is the address the pool word holds and
 * a matched file has to reproduce the word the linker wrote.  It is declared
 * `arm`, which is what a veneer body is, so the ABS32 resolves with the Thumb
 * bit clear and the `bx r3` lands in ARM state.
 *
 * The function at 0x020057C4 immediately after this range stays open and is
 * not part of this file: it is the only caller of 0x02035108 anywhere in the
 * image, so the one witness for that call is the call itself and no cut can
 * put it outside the range under test.  It also needs sub_02005794 local, for
 * the pool word at 0x020057D8, which is why it cannot simply be given a range
 * of its own either.  `python tools/match.py tu --src ... --suggest-split`
 * reports both constraints.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02005794.c \
 *       --addr 0x02005794 --thumb
 */
void sub_02005794(void)
{
    veneer_02072788(0);
}


void sub_020057A0(void)
{
    veneer_02072788(0x7F);
}


void sub_020057AC(void)
{
    func_0203508C((u32)sub_02005794, (u32)sub_020057A0, 0);
}


/*
 * Promoted from src/pending/ in the third 0-64 byte band pass (lane 1).  It
 * was parked there on its one call site only - 0x02035108 is reached by the
 * `blx` inside this function and by nothing else in the image, so `label` had
 * no witness - and it needed no change to its C: 0x02035108 now has an EXACT
 * entry of its own (pkt_0203508C), the site resolves through the `matched`
 * class, and the file printed EXACT on the first re-run.  This is the chain
 * class of the band brief working exactly as described, one pass later than
 * the target list expected, because the callee is another lane's row.
 *
 * "Is the master volume callback still the initial one": the pool word is
 * sub_02005794 with its Thumb bit set (0x02005795) and is compared against the
 * word func_02035108 hands back, so the C compares the call's result with the
 * *address* of the thunk - which is why the constant is a relocation and not a
 * plain literal.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020057C4.c \
 *       --func func_020057C4 --addr 0x020057C4 --cc 1.1p1 --thumb
 */
int func_020057C4(void)
{
    u32 v;

    v = func_02035108();
    return v == (u32)sub_02005794;
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 *           sub_02005888, sub_020058D0, sub_02005900, sub_0200590C,
 *           sub_02005924, sub_0200597C, sub_020059A0, sub_020059C8,
 *           sub_02005A00
 *
 * The accessors of a six element table of 0x1C byte connection slots at
 * 0x020AA1B8 and of the one word "which slot is current" record at
 * 0x020AA1AC.  sub_0200590C, which returns the address of the current
 * slot's payload, was already matched as a single function in
 * arm9/legacy.json; it is the last function of this range and is absorbed
 * here.  func_02072E9C is NHTTPi_InitRequestInfo in layout/symbols_sdk.txt,
 * which is what the payload at offset 8 of a slot is.
 *
 * What the range teaches:
 *
 *  - a field of `table[i]` with a run time `i` puts the field offset in the
 *    relocation addend rather than in the instruction.  sub_020057E8 stores
 *    to five different fields of one slot and loads five different pool
 *    words, 0x020AA1B8, 0x020AA1BC, 0x020AA1C4, 0x020AA1C8, 0x020AA1CC and
 *    0x020AA1D0, which are the table's address plus 0, 4, 0xC, 0x10, 0x14
 *    and 0x18.  Thumb's register-offset `str` has no immediate to spare, so
 *    the compiler folds the member offset into the symbol instead.  Reading
 *    those pool words as six separate objects would be the wrong conclusion.
 *  - the constant -1 is never materialised on its own.  sub_020057E8 needs
 *    a 0 for the first store and derives the -1 for the next four from it
 *    with `subs r1, r4, #1`.
 *
 * The near miss this header used to record, the run
 * 0x02005794..0x020057D8, is now closed as far as the evidence allows.  The
 * `veneer` attestation class carries 0x02072788, so the two twelve byte
 * thunks and the function at 0x020057AC that passes both of their addresses
 * to func_0203508C are src/matched/unit_02005794.c and are EXACT.
 *
 * What is left open is 0x020057C4 alone, 20 bytes, and the reason is
 * unchanged and structural: func_02035108 has exactly one caller anywhere in
 * the 3.9 MB image and it is the `blx` at 0x020057C6 inside that very
 * function.  Shrinking the range cannot help, because the witness is the call
 * itself, and the target is ARM library code that cannot be made `local`.
 * The function also needs sub_02005794 `local`, for the pool word at
 * 0x020057D8 that holds its address.  It closes the day anything else in the
 * image calls 0x02035108.
 */
void sub_020057DC(u32 **a)
{
    sub_020057DC_Cur.unk08 = a;
}


void sub_020057E8(u32 i)
{
    sub_020057DC_Table[i].unk00 = 0;
    sub_020057DC_Table[i].unk04 = 0xFFFF;
    func_02072EA8((u32 * volatile*)(&sub_020057DC_Table[i].unk08));
    sub_020057DC_Table[i].unk0C = -1;
    sub_020057DC_Table[i].unk10 = -1;
    sub_020057DC_Table[i].unk14 = -1;
    sub_020057DC_Table[i].unk18 = -1;
}


void sub_02005834(u32 v)
{
    struct Sub020057DCSlot *slot =
        &sub_020057DC_Table[sub_020057DC_Cur.index];

    slot->unk0C = v;
    slot->unk10 = v;
    slot->unk14 = v;
    slot->unk18 = v;
    slot->unk00 = 1;
}


void sub_02005858(void)
{
    struct Sub020057DCSlot *slot =
        &sub_020057DC_Table[sub_020057DC_Cur.index];

    func_02072EA8((u32 * volatile*)(&slot->unk08));
    func_020748E0(*sub_020057DC_Cur.unk08, slot->unk0C);
    sub_020057E8(sub_020057DC_Cur.index);
}


void sub_02005888(u16 a)
{
    int i;

    sub_020057DC_Cur.unk00 = a;
    sub_020057DC_Cur.index = 0;
    for (i = 0; i < 6; i++) {
        sub_020057E8(i);
        func_02072E9C((void **)(&sub_020057DC_Table[i].unk08));
    }
    func_02072DB0(sub_020057DC_Cur.unk00, 6);
    sub_02005834(func_02074894((struct S *)*sub_020057DC_Cur.unk08));
}


u16 sub_020058D0(void)
{
    struct Sub020057DCSlot *slot =
        &sub_020057DC_Table[sub_020057DC_Cur.index];
    u16 v;

    if (slot->unk00 == 0) {
        return 0;
    }
    v = slot->unk04;
    if (v == 0xFFFF) {
        v = 0;
    }
    return v;
}


u32 sub_02005900(void)
{
    return sub_020057DC_Cur.index;
}


u32 *sub_0200590C(void)
{
    return &sub_020057DC_Table[sub_020057DC_Cur.index].unk08;
}


int sub_02005924(u32 a)
{
    struct Sub020057DCSlot *slot =
        &sub_020057DC_Table[sub_020057DC_Cur.index];
    int r;

    if (func_02074AC4(a, 3, (u32)(*sub_020057DC_Cur.unk08)) == 0) {
        return 0;
    }
    slot->unk14 = func_02074894((struct S *)*sub_020057DC_Cur.unk08);
    r = func_02074AC4(a, 4, (u32)(*sub_020057DC_Cur.unk08));
    if (r == 0) {
        return 0;
    }
    slot->unk18 = func_02074894((struct S *)*sub_020057DC_Cur.unk08);
    slot->unk04 = a;
    return r;
}


void sub_0200597C(void)
{
    struct Sub020057DCSlot *slot =
        &sub_020057DC_Table[sub_020057DC_Cur.index];

    slot->unk14 = func_02074894((struct S *)*sub_020057DC_Cur.unk08);
}


int sub_020059A0(u32 a)
{
    struct Sub020057DCSlot *slot =
        &sub_020057DC_Table[sub_020057DC_Cur.index];

    slot->unk18 = func_02074894((struct S *)*sub_020057DC_Cur.unk08);
    slot->unk04 = a;
    return 1;
}


void sub_020059C8(void)
{
    struct Sub020057DCSlot *slot =
        &sub_020057DC_Table[sub_020057DC_Cur.index];

    if (slot->unk00 == 0) {
        return;
    }
    slot->unk04 = 0xFFFF;
    func_020748E0(*sub_020057DC_Cur.unk08, slot->unk10);
    slot->unk14 = slot->unk10;
    slot->unk18 = slot->unk10;
}


int sub_02005A00(void)
{
    struct Sub020057DCSlot *slot =
        &sub_020057DC_Table[sub_020057DC_Cur.index];
    u32 v;

    if (sub_020057DC_Cur.index >= 5) {
        return 0;
    }
    if (slot->unk14 != -1) {
        func_020748E0(*sub_020057DC_Cur.unk08, slot->unk14);
        slot->unk18 = -1;
        v = slot->unk14;
    } else {
        v = slot->unk10;
    }
    sub_020057DC_Cur.index++;
    sub_02005834(v);
    return 1;
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * Pop one slot off the stack of connection slots that src/matched/
 * unit_020057DC.c pushes onto.  It is its own byte range rather than part
 * of that unit for an evidence reason and not a source one: func_02074AC4
 * is reached from exactly three `blx` sites image wide, 0x0200593A,
 * 0x02005958 and 0x02005A7A, and the first two are inside
 * unit_020057DC.c's range.  Splitting here leaves each file a witness for
 * the other's calls, which is what the honesty rule in docs/MATCHING.md
 * asks for.
 *
 * `Cur.index` is signed: the guard is `cmp r0, #0` / `bgt`, and written
 * against an unsigned field this compiler emits `bne` instead.
 */
int sub_02005A4C(void)
{
    struct Sub02005A4CSlot *slot;
    int i;
    u16 v;

    if (sub_02005A4C_Cur.index <= 0) {
        return 0;
    }
    sub_02005858();
    i = sub_02005A4C_Cur.index - 1;
    slot = &sub_02005A4C_Table[i];
    v = slot->unk04;
    sub_02005A4C_Cur.index = i;
    if (v != 0xFFFF) {
        func_02074AC4(v, 6, (u32)(*sub_02005A4C_Cur.unk08));
        slot->unk18 = func_02074894((struct S *)*sub_02005A4C_Cur.unk08);
    }
    return 1;
}


/*
 * promoted: from src/pending 2026-09-19, no C change: blocker 0x02074A6C is filed in layout/matched/arm9/pkt_02074A6C.json and every site resolves (gate: manifest --verify --shard layout/matched/arm9/pkt_02005A98.json, then 0 rewritten).
 * blocker (RESOLVED 2026-09-19):  02074A6C - the `blx` inside this function is the only branch to
 *           it anywhere in the image, so `label` has no witness outside the
 *           compared range and the callee is not matched.  Closes when
 *           0x02074A6C's own shard is written.  All 100 concrete bytes and
 *           every other site are right.
 *
 * Push one connection slot onto the stack unit_02005A4C.c pops from: take
 * the current slot's field at +0xC as the saved status word, close the
 * current slot, allocate an 8-byte-plus header block, copy `a1` handles in,
 * stamp the count and the saved word, and finally reset the current index.
 * The loop is a `for` rotated by the compiler (the entry test is on the
 * bound, the back edge on the counter), and `a1` is unsigned because the
 * skid test is `bls`.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02005A98.c \
 *       --func func_02005A98 --addr 0x02005A98 --cc 1.1p1 --thumb
 */
struct Sub02005A98Hdr *func_02005A98(const u32 *a0, u32 a1)
{
    struct Sub02005A98Slot *slot;
    struct Sub02005A98Hdr *p;
    u32 saved;
    u32 i;

    slot = &sub_02005A98_Table[sub_02005A98_Cur.index];
    saved = slot->unk0C;
    sub_02005858();
    i = 0;
    p = (struct Sub02005A98Hdr *)func_0207482C(*sub_02005A98_Cur.unk08, 8, 0, 0, 0);
    for (i = 0; i < a1; i++) {
        func_02074A6C(a0[i], (u32)*sub_02005A98_Cur.unk08);
    }
    p->n = a1;
    p->status = saved;
    sub_02005834(func_02074894((struct S *)*sub_02005A98_Cur.unk08));
    return p;
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * Close the current connection slot with a status word taken from the
 * second word of the argument block.  Its own byte range because the
 * function immediately before it, 0x02005A98, cannot be attested: the only
 * `blx` to func_02074A6C anywhere in the image is the one inside it.
 */
void sub_02005B04(const u32 *arg)
{
    u32 v = arg[1];

    sub_02005858();
    func_020748E0(*sub_02005B04_Cur.unk08, v);
    sub_02005834(v);
}


/*
 *           and its pointer word 0x02704364, which lies outside every region
 *           of layout/layout.json, so `veneer_at()`'s `names_known_code()`
 *           refuses it and the `veneer` class cannot attest the call.
 *
 * Network bring-up: take a block out of the static buffer at 0x020AA9B4
 * (0x95AD0 bytes, a pool word and not a `movs`-able constant), publish the
 * handle at +0x10 of the connection-slot global and hand the pair to the
 * handler installer, then run the console-type-specific tail.  The function
 * takes no arguments: its first call, func_020726D0 (sound init), is
 * `void (void)` and reads neither r0 nor r1, so the r0/r1 the caller
 * func_0200523C leaves behind are dead
 * (docs/idioms/an-argument-passed-through-a-register-must-be-named-in-the-c.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02005B24.c \
 *       --func func_02005B24 --addr 0x02005B24 --cc 1.1p1 --thumb
 */
void func_02005B24(void)
{
    u32 handle;

    func_020726D0();
    handle = func_020746E8((u32)g_020AA9B4, 0x95AD0);
    *(u32 *)(g_020AA260 + 0x10) = handle;
    func_02073FB8(g_020AA2BC, g_020A7010, handle, 0);
    func_02005B74(1);
    if (func_02085D3C() == 1) {
        func_02704364();
    }
}


void func_02005B74(int a0)
{
    func_020754C4(*(int *)(g_020AA260 + 0x10));
    func_020057DC((u32 **)(g_020AA260 + 0x10));
    if (a0 != 0) {
        func_02074518(0);
        func_02074A54(0, *(int *)(g_020AA260 + 0x10));
        *(int *)(g_020AA260 + 0x18) = 0;
    }
    func_02006118();
    func_02005888(0);
    func_02005F5C();
    *(short *)(g_020AA260 + 0) = 0;
    *(int *)(g_020AA260 + 8) = 0;
    *(int *)(g_020AA260 + 0x14) = 0;
    *(int *)(g_020AA260 + 4) = 0;
}
