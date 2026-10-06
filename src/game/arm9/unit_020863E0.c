/*
 * file:     unit_020863E0.c
 * unit:     yes
 * function: func_020863E0, func_020864FC, func_0208656C, func_02086580, func_02086594, func_02086694, func_02086760, func_02086774, func_02086788
 * address:  0x020863E0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02151264  0x02151264  data
 *   OS_GetConsoleType         0x02085CBC  arm
 *   OS_SetArenaHi             0x02086760  arm
 *   OS_SetArenaLo             0x02086774  arm
 *   OS_IsRunOnTwl             0x02085D3C  arm
 *   OS_SetProtectionRegionEx  0x02086DB0  arm
 *   OSi_InitArenaEx_ltdmain   0x027312B4  arm
 *   func_02085D3C 0x02085D3C arm
 *   func_02085CBC 0x02085CBC arm
 */
typedef unsigned int u32_020863E0;

typedef unsigned long u32_020864FC;

typedef long s32;

typedef unsigned char u8;

typedef int BOOL;

typedef u32_020864FC OSIntrMode;

typedef enum OSArenaId {
    OS_ARENA_MAIN = 0,
    OS_ARENA_MAIN_SUBPRIV = 1,
    OS_ARENA_MAINEX = 2,
    OS_ARENA_ITCM = 3,
    OS_ARENA_DTCM = 4,
    OS_ARENA_SHARED = 5,
    OS_ARENA_WRAM_MAIN = 6,
    OS_ARENA_WRAM_SUB = 7,
    OS_ARENA_WRAM_SUBPRIV = 8,
    OS_ARENA_MAX = 9
} OSArenaId;

typedef struct Cell Cell;

struct Cell {
    Cell *prev;
    Cell *next;
    long size;
};

typedef struct HeapDesc {
    long size;
    Cell *free;
    Cell *allocated;
} HeapDesc;

typedef struct OSHeapInfo {
    volatile int currentHeap;
    int numHeaps;
    void *arenaStart;
    void *arenaEnd;
    HeapDesc *heapArray;
} OSHeapInfo;

typedef unsigned int u32_0208656C;

typedef unsigned int u32_02086580;

typedef unsigned int   u32_4;

typedef unsigned int   u32_5;

typedef unsigned int u32_02086760;

typedef unsigned int u32_02086774;

typedef unsigned int u32_02086788;

extern u32_020863E0  func_02086594(u32_020863E0 a0);
extern u32_020863E0  func_02086694(u32_020863E0 a0);
extern OSIntrMode OS_DisableInterrupts(void);
extern OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
extern u32_020864FC OS_GetConsoleType(void);
extern void OS_SetArenaHi(OSArenaId id, void *newHi);
extern void OS_SetArenaLo(OSArenaId id, void *newLo);
extern BOOL OS_IsRunOnTwl(void);
extern void OS_SetProtectionRegionEx(int regionNo, u32_020864FC address, u32_020864FC sizeDef);
extern void OSi_InitArenaEx_ltdmain(void);
extern void func_02085D3C(void);
extern u32_4 func_02085CBC(void);
void func_020863E0(void);
void func_020864FC(void);
u32_0208656C func_0208656C(u32_0208656C idx);
u32_02086580 func_02086580(u32_02086580 idx);
asm void *OS_GetInitArenaHi(int id);
asm void *OS_GetInitArenaLo(int id);
void func_02086760(u32_02086760 idx, u32_02086760 val);
void func_02086774(u32_02086774 idx, u32_02086774 val);
u32_02086788 func_02086788(u32_02086788 r7, u32_02086788 r6, u32_02086788 r5);
extern u32_020863E0 g_02151264;
extern OSHeapInfo *OSiHeapInfo[OS_ARENA_MAX];


void func_020863E0(void)
{
    u32_020863E0 r5;
    u32_020863E0 r4;

    if (g_02151264 != 0) {
        return;
    }
    r5 = 0;
    g_02151264 = 1;

    func_02086760(r5, func_02086594(r5));
    func_02086774(r5, func_02086694(r5));

    r4 = 2;
    func_02086774(r4, r5);
    func_02086760(r4, r5);

    r4 = 3;
    func_02086760(r4, func_02086594(r4));
    func_02086774(r4, func_02086694(r4));

    r4 = 4;
    func_02086760(r4, func_02086594(r4));
    func_02086774(r4, func_02086694(r4));

    r4 = 5;
    func_02086760(r4, func_02086594(r4));
    func_02086774(r4, func_02086694(r4));

    r4 = 6;
    func_02086760(r4, func_02086594(r4));
    func_02086774(r4, func_02086694(r4));
}


#define OSi_ROUND(n, a)     (((u32_020864FC)(n) + (a) - 1) & ~((a) - 1))

#define OSi_TRUNC(n, a)     (((u32_020864FC)(n)) & ~((a) - 1))


/*
 * sdk:      OS_InitArenaEx (os_arena.o)
 */
void func_020864FC(void)
{
    (void)OS_GetConsoleType();

    OS_SetArenaHi(OS_ARENA_MAINEX, OS_GetInitArenaHi(OS_ARENA_MAINEX));
    OS_SetArenaLo(OS_ARENA_MAINEX, OS_GetInitArenaLo(OS_ARENA_MAINEX));

    if (!OS_IsRunOnTwl()) {
        OS_SetProtectionRegionEx(1, 0x02000000, 0x2A);
        OS_SetProtectionRegionEx(2, 0x027FF000, 0x16);
    } else {
        OSi_InitArenaEx_ltdmain();
    }
}


u32_0208656C func_0208656C(u32_0208656C idx)
{
    return *(u32_0208656C *)((idx << 2) + 0x02FFFDC4);
}


u32_02086580 func_02086580(u32_02086580 idx)
{
    return *(u32_02086580 *)((idx << 2) + 0x02FFFDA0);
}


asm void *OS_GetInitArenaHi(int id)
{
    stmfd sp!, {r4, lr}
    cmp r0, #6
    addls pc, pc, r0, lsl #2
    b loc_default

    b case_0
    b loc_default
    b case_2
    b case_3
    b case_4
    b case_5
    b case_6

case_0:
    bl func_02085D3C
    cmp r0, #0
    movne r0, #0x2f80000
    ldreq r0, [pc, #0xa4]
    ldmfd sp!, {r4, pc}

case_2:
    ldr r0, [pc, #0xa0]
    ldr r0, [r0, #4]
    cmp r0, #0
    moveq r0, #0
    ldmeqfd sp!, {r4, pc}
    bl func_02085CBC
    and r4, r0, #0xf
    bl func_02085D3C
    cmp r0, #0
    mov r0, #0
    beq loc_twl_nitro
    cmp r4, #4
    movne r0, #0xdf00000
    ldmfd sp!, {r4, pc}

loc_twl_nitro:
    cmp r4, #1
    movne r0, #0x2700000
    ldmfd sp!, {r4, pc}

case_3:
    mov r0, #0x2000000
    ldmfd sp!, {r4, pc}

case_4:
    ldr r0, [pc, #0x58]
    ldr r1, [pc, #0x58]
    ldr r2, [pc, #0x58]
    add r3, r0, #0x3f80
    cmp r1, #0
    sub r2, r3, r2
    bne loc_stack_nonzero
    ldr r1, [pc, #0x48]
    cmp r0, r1
    movlo r0, r1
    ldmfd sp!, {r4, pc}

loc_stack_nonzero:
    cmp r1, #0
    ldrlt r0, [pc, #0x34]
    sublt r0, r0, r1
    subge r0, r2, r1
    ldmfd sp!, {r4, pc}

case_5:
    ldr r0, [pc, #0x28]
    ldmfd sp!, {r4, pc}

case_6:
    mov r0, #0x3040000
    ldmfd sp!, {r4, pc}

loc_default:
    mov r0, #0
    ldmfd sp!, {r4, pc}

    dcd 0x023E0000
    dcd g_02151264
    dcd 0x02FE0000
    dcd 0x00001800
    dcd 0x00000800
    dcd 0x02FE00C0
    dcd 0x02FFF680
}


asm void *OS_GetInitArenaLo(int id)
{
    stmfd sp!, {r4, lr}
    cmp r0, #6
    addls pc, pc, r0, lsl #2
    b loc_default

    b case_0
    b loc_default
    b case_2
    b case_3
    b case_4
    b case_5
    b case_6

case_0:
    bl func_02085D3C
    cmp r0, #0
    ldrne r0, [pc, #0x70]
    ldreq r0, [pc, #0x70]
    ldmfd sp!, {r4, pc}

case_2:
    ldr r0, [pc, #0x6c]
    ldr r0, [r0, #4]
    cmp r0, #0
    moveq r0, #0
    ldmeqfd sp!, {r4, pc}
    bl func_02085CBC
    and r4, r0, #0xf
    bl func_02085D3C
    cmp r0, #0
    mov r0, #0
    beq loc_twl_nitro
    cmp r4, #4
    ldrne r0, [pc, #0x40]
    ldmfd sp!, {r4, pc}

loc_twl_nitro:
    cmp r4, #1
    ldrne r0, [pc, #0x38]
    ldmfd sp!, {r4, pc}

case_3:
    ldr r0, [pc, #0x34]
    ldmfd sp!, {r4, pc}

case_4:
    ldr r0, [pc, #0x30]
    ldmfd sp!, {r4, pc}

case_5:
    ldr r0, [pc, #0x2c]
    ldmfd sp!, {r4, pc}

case_6:
    mov r0, #0x3040000
    ldmfd sp!, {r4, pc}

loc_default:
    mov r0, #0
    ldmfd sp!, {r4, pc}

    dcd 0x02735B40
    dcd 0x02213D20
    dcd g_02151264
    dcd 0x0D000000
    dcd 0x02400060
    dcd 0x01FF8820
    dcd 0x02FE00C0
    dcd 0x02FFF000
}


void func_02086760(u32_02086760 idx, u32_02086760 val)
{
    *(u32_02086760 *)((idx << 2) + 0x02FFFDC4) = val;
}


void func_02086774(u32_02086774 idx, u32_02086774 val)
{
    *(u32_02086774 *)((idx << 2) + 0x02FFFDA0) = val;
}


u32_02086788 func_02086788(u32_02086788 r7, u32_02086788 r6, u32_02086788 r5)
{
    u32_02086788 r0 = func_02086580(r7);
    u32_02086788 r1, r2, r4;

    if (r0 == 0) {
        return 0;
    }
    r1 = r5 - 1;
    r2 = ~r1;
    r0 = r0 + r5 - 1;
    r4 = r2 & r0;

    r0 = r4 + r6;
    r0 = r0 + r5 - 1;
    r5 = r2 & r0;

    if (r5 > func_0208656C(r7)) {
        return 0;
    }

    func_02086774(r7, r5);
    return r4;
}
