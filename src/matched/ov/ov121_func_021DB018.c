/*
 * function: func_021DB018
 * address: 0x021DB018
 * packet: pkt_ov121_021DB018
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * closed 2026-10-05 (recoup integrator): func_02049658 returns u32 (its matched definition tail-returns ARC_UTIL_UploadBgChar); with the void declaration the later register zeros were copied from the pooled zero; with the real return type the
 *   bytes are EXACT in c99 and c.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_021D99A4 0x021D99A4 thumb ov121
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   func_021DCF54 0x021DCF54 thumb ov121
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorFlip 0x0204B604 arm
 *   func_02040588 0x02040588 arm
 *   data_021DF86E 0x021DF86E data a1
 * note (2026-10-05, lane P10): full body written; size is exact (976 bytes), 110 bytes differ.
 *   Fixed: heap is u16 with the matched u16 callee prototypes (no lsls/lsrs pairs); 0xAB4, 0xBA8
 *   and 320 held as int locals (off, off2, w) so the pool words and derived offsets matched.
 *   Residue 1: colour swap. Original has the early zero (and loop counter i) in r6 and arc in r4;
 *   the build has them swapped (j then takes r6 vs r4 the same way). Tried, no change: i,j and arc
 *   declaration order, separate arc names, loop-scoped i and j, named zero z (propagated),
 *   j = 0 at the top (worse). Pragmas opt_lifetimes/propagation/common_subs/dead_assignments/
 *   scheduling/peephole off: no help.
 *   Residue 2: the original uses movs for zero arguments in r0-r3 between 0xCC and 0x140 (before
 *   the first loop); the build copies the zero register there.
 *   Residue 3: in loop 2 the original forms add r0,sp,#0x44 once before the j test; the build
 *   adds it in each arm. A ternary for the x store and a real Tmp struct were worse.
 * note (2026-10-05, lane P10b): 110 -> 85 bytes, size exact (976). Fixed: loop 2 now writes
 *   the t stores in each if/else arm (x, y=0x10 and z=9 in both arms), so the &t add is hoisted
 *   above the j test and the tail shape matches (residue 3 closed, 110 -> 94). The locals off, off2
 *   and w were stand-ins (literals give identical bytes) and are gone. opt_dead_assignments off
 *   fixes the r0/r1 table-base colours in the i < 4 arm (94 -> 85).
 *   Left: the colour swap. Original W1 = early zero and loop-1 counter i in r6, arcs r4, W2 = copy
 *   of it (`adds r4,r6,#0` before loop 1) = zero args after the loop and loop-2 counter j in r4.
 *   Build: W1 r4, arcs and W2 r6. Likely W1 is coloured before W2 because W1 has about ten extra
 *   uses: between 0xCC and 0x140 the build copies zeros off W1 (adds rN,r4,#0) where the original
 *   has movs. Tried (no help): i=0 at the top of the function (hoists the movs above the first
 *   call, +12 B), `i = 0; j = i;` before loop 1 with empty for inits (+12 B, worse regs), pointer
 *   local for &t in loop 2 (hoisted to r7, worse), j/i and arc declaration order again with the
 *   new loop 2, pragmas opt_lifetimes, opt_propagation, scheduling, peephole (no change),
 *   opt_common_subs (much worse), lifetimes+dead_assignments (85, same), propagation+dead (worse).
 *   Parked per the human-written rule: not tried, a human-spelled zero local reused as the
 *   stack zero arguments (i passed as args 5 and 6) could explain r6 holding a live variable.
 * note (2026-10-05, lane P10c): still 85 B, no change kept. The pragma opt_dead_assignments off
 *   lines are present (the 85 B state). Callee prototypes already match the matched callers (u32
 *   args, u16 heap), so no argument type differs between the stack zeros and the register zeros.
 *   Facts: mine already uses movs for register zeros before +0xB0 and copies only from the last
 *   02049658/020498F4 pair on (+0xB0, +0xD0, +0xF6..+0x134); the original uses movs everywhere in
 *   W1's range, and the copy count raises W1's use count, which colours W1 before the arcs.
 *   Loop 2 original: k is a separate fresh `movs r7,#0`, j is r4.
 *   Tried (each one compile): (1) coordinator lead: i = 0 before the first call, i passed only as
 *   the two stack zero args of 02049658/020498F4, literal 0 for r1-r3 (87 B; the compiler folds
 *   i to 0 so register zeros still copy); (2) i = 0 early with `for (; i < 8; i++)` as in the
 *   matched twin ov099 021BE040 (87 B); (3) static inline helper pair(arc, x, y, heap) for the
 *   three 02049658/020498F4 pairs (85 B, +0xB0 now movs, others unchanged); (4) late zeros
 *   (02049B68 r2, 02040C14 r1/r3, 0201F5BC r0/r3, 0204ACEC r2) spelled 0u (85 B, no change);
 *   (5) first 23 lines of calls inside a static inline setup1(heap) helper (85 B); (6) helper
 *   variant with opt_propagation off (901 B) and opt_lifetimes off (85 B). Idea not done: a
 *   source where W1 is not provably 0 after the first loop-free section.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef struct { u16 h[4]; } Row;
typedef struct { u8 b[16]; } Tmp;
extern const Row data_021DF86E[];
struct Obj;
struct Actor;
struct Cfg;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern unsigned int func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_020409B4(u32);
extern void BG_SYS_Init(u32, u32, u32, u32);
extern void BMP_MENUWORK_LoadCharAndPltt(u32, u32, u32, u32, u16);
extern int func_0201BC3C(void);
extern int CLACT_RegisterPaletteCompressed(void *, u32, u32, u32, u16);
extern u32 BMP_WIN_Create(u32, u32, u32, u32, u8, u8, u8);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void *func_021D99A4(u32, u32, u16, u16, u8, u8, u8, u32, u16);
extern s32 CLACT_RegisterPaletteEx(void *, u32, u32, u32, u16, u16, u16);
extern s32 CLACT_RegisterCellAnim(void *, u32, u32, u32);
extern s32 CLACT_RegisterCharacter(void *, u32, u32, u32, u16);
extern void func_021DCF54(char *, void *, int, int, u8, u16);
extern void MI_CpuFill8(void *, int, int);
extern struct Obj *CLACT_CreateActor(void *, u32, u32, u32, const void *, u16, u16);
extern void CLACT_SetActorDrawEnable(struct Obj *, u32);
extern void CLACT_SetActorAutoAnim(struct Obj *, u32);
extern void CLACT_SetActorFlip(struct Actor *actor, u32 which, u32 set);
extern void func_02040588(unsigned char which, unsigned char enable);
#pragma opt_dead_assignments off
void func_021DB018(u8 *p, u16 heap)
{
    Tmp t;
    void *arc;
    int i, j;
    u32 k;
    arc = func_020490F4(34, heap);
    func_02049B68(arc, 1, 0, 0, 320, heap);
    func_02049658(arc, 10, 3, 0, 0, 0, heap);
    func_020498F4(arc, 17, 3, 0, 0, 0, heap);
    func_02049658(arc, 10, 1, 0, 0, 0, heap);
    func_020498F4(arc, 19, 1, 0, 0, 0, heap);
    func_020409B4(3);
    func_02049B68(arc, 1, 4, 0, 320, heap);
    func_02049658(arc, 10, 7, 0, 0, 0, heap);
    func_020498F4(arc, 18, 7, 0, 0, 0, heap);
    ARC_TOOL_DeleteHandle(arc);
    arc = func_020490F4(23, heap);
    func_02049B68(arc, 5, 0, 480, 32, heap);
    func_02049B68(arc, 5, 4, 480, 32, heap);
    ARC_TOOL_DeleteHandle(arc);
    BG_SYS_Init(1, 0, 1, 0);
    BG_SYS_Init(2, 0, 1, 0);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 13, 0, heap);
    arc = func_020490F4(7, heap);
    *(int *)(p + 0xBA8) = CLACT_RegisterPaletteCompressed(arc, func_0201BC3C(), 0, 384, heap);
    ARC_TOOL_DeleteHandle(arc);
    for (i = 0; i < 8; i++) {
        if (i >= 4) {
            *(u16 *)(t.b + 8) = data_021DF86E[i - 4].h[0];
            *(u16 *)(t.b + 10) = data_021DF86E[i - 4].h[1];
            *(u16 *)(t.b + 12) = data_021DF86E[i - 4].h[2];
            *(u16 *)(t.b + 14) = data_021DF86E[i - 4].h[3];
            t.b[8] += 0x20;
            t.b[10] += 0x20;
        } else {
            *(u16 *)(t.b + 8) = data_021DF86E[i].h[0];
            *(u16 *)(t.b + 10) = data_021DF86E[i].h[1];
            *(u16 *)(t.b + 12) = data_021DF86E[i].h[2];
            *(u16 *)(t.b + 14) = data_021DF86E[i].h[3];
        }
        *(u32 *)(p + i * 4 + 0xBA8 - 0xA0) = BMP_WIN_Create(2, t.b[10], t.b[11], 10, 2, 15, 0);
        BMP_WIN_MakeScreen(*(void **)(p + i * 4 + 0xBA8 - 0xA0));
        func_020409B4(2);
    }
    *(void **)(p + 0xAB4) = func_021D99A4(0, 1, 13, 22, 6, 2, 3, *(u32 *)(p + 0x14), heap);
    arc = func_020490F4(34, heap);
    *(s32 *)(p + 0xAB4 + 0x50) = CLACT_RegisterPaletteEx(arc, 0, 0, 0, 0, 6, heap);
    *(s32 *)(p + 0xAB4 + 0x4C) = CLACT_RegisterCellAnim(arc, 32, 35, heap);
    *(s32 *)(p + 0xAB4 + 0x48) = CLACT_RegisterCharacter(arc, 9, 0, 0, heap);
    func_021DCF54((char *)p + 0xBAE, arc, 0, 0, 1, heap);
    func_021DCF54((char *)p + 0xC0E, arc, 0, 2, 3, heap);
    ARC_TOOL_DeleteHandle(arc);
    MI_CpuFill8(&t, 0, 8);
    *(u16 *)(t.b) = 0;
    *(u16 *)(t.b + 2) = 24;
    t.b[7] = 1;
    t.b[6] = 1;
    {
        struct Obj *o = CLACT_CreateActor(*(void **)(p + 8), *(u32 *)(p + 0xAB4 + 0x48), *(u32 *)(p + 0xAB4 + 0x50), *(u32 *)(p + 0xAB4 + 0x4C), &t, 0, heap);
        *(struct Obj **)(p + 0xAB4 + 0x38) = o;
        *(u16 *)(t.b + 4) = 2;
        o = CLACT_CreateActor(*(void **)(p + 8), *(u32 *)(p + 0xAB4 + 0x48), *(u32 *)(p + 0xAB4 + 0x50), *(u32 *)(p + 0xAB4 + 0x4C), &t, 0, heap);
        *(struct Obj **)(p + 0xAB4 + 0x3C) = o;
        CLACT_SetActorDrawEnable(o, 0);
    }
    t.b[6] = 0;
    k = 0;
    for (j = 0; j < 2; j++) {
        struct Obj *o;
        u8 *q;
        if (j == 0) {
            *(u16 *)(t.b) = 0x10;
            *(u16 *)(t.b + 2) = 0x10;
            *(u16 *)(t.b + 4) = 9;
        } else {
            *(u16 *)(t.b) = 0xF0;
            *(u16 *)(t.b + 2) = 0x10;
            *(u16 *)(t.b + 4) = 9;
        }
        q = p + j * 4;
        o = CLACT_CreateActor(*(void **)(p + 8), *(u32 *)(p + 0xAB4 + 0x48), *(u32 *)(p + 0xAB4 + 0x50), *(u32 *)(p + 0xAB4 + 0x4C), &t, k, heap);
        *(struct Obj **)(q + 0xAB4 + 0x40) = o;
        CLACT_SetActorAutoAnim(*(struct Obj **)(q + 0xAB4 + 0x40), 1);
        CLACT_SetActorDrawEnable(*(struct Obj **)(q + 0xAB4 + 0x40), k);
        if (j == 0) CLACT_SetActorFlip((struct Actor *)(*(struct Obj **)(q + 0xAB4 + 0x40)), 1, 1);
        else CLACT_SetActorFlip((struct Actor *)(*(struct Obj **)(q + 0xAB4 + 0x40)), 1, 0);
    }
    func_02040588(2, 1);
}
#pragma opt_dead_assignments reset
