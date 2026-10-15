/*
 * function: GFL_USE_InitSystem
 * address:  0x0200545C
 * packet:   pkt_02005454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _GflUse      0x020AA194  data
 *   s_gfl_use_c     0x020A7004  data
 *   _ArenaTableTwl      0x0209D8A0  data
 *   _ArenaTableDs      0x0209D8B0  data
 *   _ArcPathTable      0x020A6C58  data
 *   GFL_USE_WaitInputReady    0x02005768  thumb
 *   APP_POWER_ClearCallback   0x0202F768  thumb
 *   APP_POWER_SetCallback   0x0202F774  thumb
 *   OS_IsRunOnTwl       0x02085D3C  arm
 *   OS_GetArenaHi       0x0208656C  arm
 *   OS_GetArenaLo       0x02086580  arm
 *   OS_InitAlloc        0x02086A50  arm
 *   OS_SetArenaLo       0x02086774  arm
 *   OS_CreateExtraHeap  0x02086B98  arm
 *   OS_AllocFromHeap    0x020868E0  arm
 *   OS_GetConsoleType   0x02085CBC  arm
 *   GFL_USE_InitRandom    0x020056D0  thumb
 *   GFL_USE_ClearVBlankHook    0x0200566C  thumb
 *   GFL_USE_SetSleepVolumeHooks   0x020057AC  thumb
 *   GFL_HEAP_Init  0x02030608  arm
 *   PROCSYS_CreateGlobal  0x0203129C  arm
 *   BACKUP_SYSTEM_Init  0x020316C8  arm
 *   ARC_TOOL_SetTable  0x02048CEC  arm
 *   TEXTPRINT_Init  0x0204E130  arm
 *   FADE_Create  0x0204E5E8  arm
 *   FADE_SetSpeed  0x0204E6F4  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   GFL_HEAP_RegisterBlockHeap  0x02030678  arm
 *   GF_STANDARD_Reset  0x0203F3B4  arm
 *   GFL_HEAP_InitSystemHeapChecked  0x02030BA4  arm
 *   GF_STANDARD_Init  0x0203EF5C  arm
 *
 * gfl_use.c, the file's __FILE__ anchor function: system boot set-up.  On a
 * non-TWL console, carve the main arena into the OS heap (Hi read before Lo,
 * hence the named local), create the extra heap and take a 0x3F00 block
 * from it; then the heap system on the console's arena table, the graphics,
 * card and sound bring-up, the three heap-tracked allocations at lines
 * 0x117 / 0x119 / 0x11C of gfl_use.c (s_gfl_use_c is the __FILE__ pointer),
 * and the task/callback installs.
 *
 * Closed in wave 14.  The pool was misread by one word in the older note
 * (docs/notes/GFL_USE_InitSystem.c.txt): 0x020A6C58 is ARC_TOOL_SetTable's argument
 * and 0x02005769 (GFL_USE_WaitInputReady, src/matched/unit_0200575C.c) is
 * func_020346EC's third, and the two words 0x0202F769 / 0x0202F775 are
 * Thumb pointers to two unlabelled callback leaves of time_icon.c, filed
 * EXACT this wave as src/matched/APP_POWER_ClearCallback.c and APP_POWER_SetCallback.c, which
 * is what attests them (`matched`).  _ArenaTableTwl / _ArenaTableDs now resolve on
 * sole-ref.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_USE_InitSystem.c \
 *       --func GFL_USE_InitSystem --addr 0x0200545C --cc 1.1p1 --thumb
 */

#include "../include/G_GflSys.h"

typedef unsigned char      u8;
typedef unsigned int       u32;
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

extern struct GflSys _GflUse;
extern u8 s_gfl_use_c[];
extern u8 _ArenaTableTwl[];
extern u8 _ArenaTableDs[];
extern u8 _ArcPathTable[];

extern u32   OS_IsRunOnTwl(void);
extern void *OS_GetArenaHi(u32 id);
extern void *OS_GetArenaLo(u32 id);
extern void *OS_InitAlloc(u32 id, void *lo, void *hi, u32 n);
extern void  OS_SetArenaLo(u32 id, void *lo);
extern u32   OS_CreateExtraHeap(u32 id);
extern void *OS_AllocFromHeap(u32 id, u32 heap, u32 size);
extern u32   OS_GetConsoleType(void);

extern void GFL_HEAP_Init(u32 a, u32 b, u32 c, u32 d);
extern void  GFL_HEAP_InitSystemHeapChecked(u32 a);
extern void  GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void  GFL_HEAP_RegisterBlockHeap(void *a, u32 b, u32 c);
extern void  GF_STANDARD_Init(u32 a);
extern void ARC_TOOL_SetTable(u32 a, u32 b);
typedef signed int     s32;
struct Ctx;
extern void func_02034E24(u32 heap, u8 mode);
extern void  func_02034978(void);
extern void func_020346EC(u32 a, u32 b, u32 c);
extern void func_0203499C(u32 heap, int n0, int n1, int n2);
extern void  PROCSYS_CreateGlobal(u32 a);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, unsigned short tag);
extern u32   func_02030CB0(u32 n);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void  GFL_USE_InitRandom(void);
extern void  FADE_Create(u32 a);
extern void BACKUP_SYSTEM_Init(u32 a0, u32 a1, u32 a2);
extern void  TEXTPRINT_Init(u32 a);
extern void  GF_STANDARD_Reset(void);
extern void  GFL_USE_ClearVBlankHook(void);
extern void  GFL_USE_SetSleepVolumeHooks(void);
extern void FADE_SetSpeed(s32 a);
extern void  GFL_USE_WaitInputReady(void);
extern void  APP_POWER_ClearCallback(void);
extern void APP_POWER_SetCallback(u32 on);

void GFL_USE_InitSystem(void)
{
    if (OS_IsRunOnTwl() == 0) {
        void *hi = OS_GetArenaHi(0);
        OS_SetArenaLo(0, OS_InitAlloc(0, OS_GetArenaLo(0), hi, 1));
        _GflUse.unk04 = OS_CreateExtraHeap(0);
        _GflUse.unk14 = OS_AllocFromHeap(0, _GflUse.unk04, 0x3F00);
    }

    if (OS_IsRunOnTwl() != 0) {
        GFL_HEAP_Init((u32)_ArenaTableTwl, 2, 0xAD, 0);
    } else {
        GFL_HEAP_Init((u32)_ArenaTableDs, 2, 0xAD, 0);
    }

    GFL_HEAP_InitSystemHeapChecked(0x2000);
    GFL_HEAP_CreateChildHeap(1, 7, 0x25000);

    if (OS_IsRunOnTwl() == 0) {
        GFL_HEAP_RegisterBlockHeap(_GflUse.unk14, 0x3F00, 9);
    } else {
        GFL_HEAP_CreateChildHeap(1, 9, 0x3F00);
    }

    GF_STANDARD_Init(0);
    ARC_TOOL_SetTable((u32)_ArcPathTable, 0xEB);
    func_02034E24(0, 0);

    if (OS_GetConsoleType() & 0x81000000) {
        func_02034978();
    } else {
        func_020346EC(0, 0, (u32)GFL_USE_WaitInputReady);
    }

    func_0203499C(0, 0x10, 4, 4);
    PROCSYS_CreateGlobal(0);

    _GflUse.heaps = func_02030734(0, 0x28, 0, (const char *)s_gfl_use_c, 0x117);
    _GflUse.heaps->unk1C = func_02030734(0, func_02030CB0(4), 0, (const char *)s_gfl_use_c, 0x119);
    _GflUse.heaps->unk18 = func_02030CBC(4, _GflUse.heaps->unk1C);
    _GflUse.heaps->unk24 = func_02030734(0, func_02030CB0(0x10), 0, (const char *)s_gfl_use_c, 0x11C);
    _GflUse.heaps->unk20 = func_02030CBC(0x10, _GflUse.heaps->unk24);

    GFL_USE_InitRandom();
    FADE_Create(0);
    BACKUP_SYSTEM_Init(7, (u32)APP_POWER_ClearCallback, (u32)APP_POWER_SetCallback);
    TEXTPRINT_Init(0);
    GF_STANDARD_Reset();
    _GflUse.unk0C = 0;
    GFL_USE_ClearVBlankHook();
    GFL_USE_SetSleepVolumeHooks();
    FADE_SetSpeed(2);
}
