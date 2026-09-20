/*
 * unit:     no
 * address:  0x02030534
 * packet:   pkt_02030534
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * function: sub_02030534
 *
 * BLOCKED on one relocation site: all 144 concrete bytes are correct, but
 * the call to OS_CreateHeap at +0068 has no witness. 0x02086AF8 is called
 * exactly once in the whole image, here, so no `label` witness exists
 * outside the compared range, and a single function section cannot be cut,
 * so --suggest-split offers nothing. It closes only when some other TwlSDK
 * caller of OS_CreateHeap turns up, or when the SDK library block around
 * 0x02086AF8 is itself matched.
 *
 * Heap-4 bring-up: this is what carves the heap that func_020305C4
 * (0x020305C4, this packet, EXACT) allocates from.
 *
 *   BOOL sub_02030534(u32 size)
 *
 * Take the current arena low mark, pin the arena high mark at 0x02FE3000,
 * hand OS_InitAlloc a single heap of `size` bytes off the low mark, push
 * the low mark past whatever the allocator claimed, then create the heap
 * over the same span. The handle lands in g_EnvHeapModule (0x02146964),
 * the second module-like global whose id table src/matched/sub_020305E4.c
 * frees; the +4 slot is an OSHeapHandle, which is why the failure test is
 * against -1.
 *
 * Shape notes:
 *
 *  - 0x02FE3000 is *not* one pool word. It is a pool word holding
 *    0x02FE0000, the base of the arm9_autoload1_main_twl region, plus an
 *    `add r1, r1, #0x3000`. Writing the constant, or an extern array at
 *    0x02FE0000 plus 0x3000, folds the offset into the relocation addend
 *    and loses four bytes; declaring the base as a *code* symbol and
 *    casting is what keeps the add, which is the tell that the original
 *    named a linker-defined region symbol rather than an address literal
 *    (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 *    47 other pool sites in the image hold 0x02FE3000 outright, so this
 *    site is the odd one out and the split is real evidence, not noise.
 *  - The store to g_EnvHeapModule is written *before* the -1 test even
 *    though the `str` is scheduled after the `moveq`: writing the test
 *    first delays the pool load of the global past the compare and costs
 *    four bytes of diff without changing the instruction count.
 *  - `arenaLo + size` is spelled twice, once for OS_InitAlloc and once for
 *    OS_CreateHeap, and the compiler recomputes `add r2, r5, r8` each
 *    time; binding it to a local costs a callee-saved register.
 *  - The success flag and OS_InitAlloc's heap count share the constant 1
 *    in r7, and -1 is then derived from it as `sub r1, r7, #2`
 *    (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *  - The 0x2f80 bound is an inline `movhi r0, #0` / `pophi`: nothing
 *    precedes it, so no shared exit and no goto.
 *
 * symbols:
 *   g_EnvHeapModule              0x02146964  data
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  arm
 *   OS_GetArenaLo                0x02086580  arm
 *   OS_SetArenaHi                0x02086760  arm
 *   OS_SetArenaLo                0x02086774  arm
 *   OS_InitAlloc                 0x02086A50  arm
 *   OS_CreateHeap                0x02086AF8  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02030534.c  *       --func sub_02030534 --addr 0x02030534 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef signed int BOOL;

struct EnvHeapModule {
    void *unk0;
    s32 heapHandle;
};

extern struct EnvHeapModule g_EnvHeapModule;
extern void SDK_AUTOLOAD_MAIN_TWL_START(void);

extern void *OS_GetArenaLo(u32 id);
extern void OS_SetArenaHi(u32 id, void *hi);
extern void OS_SetArenaLo(u32 id, void *lo);
extern void *OS_InitAlloc(u32 id, void *lo, void *hi, s32 heapCount);
extern s32 OS_CreateHeap(u32 id, void *start, void *end);

BOOL sub_02030534(u32 size)
{
    void *arenaLo;
    void *start;
    s32 heap;
    BOOL ok;

    if (size > 0x2F80) {
        return 0;
    }

    arenaLo = OS_GetArenaLo(4);
    OS_SetArenaHi(4, (u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3000);
    ok = 1;
    start = OS_InitAlloc(4, arenaLo, (u8 *)arenaLo + size, 1);
    OS_SetArenaLo(4, start);
    heap = OS_CreateHeap(4, start, (u8 *)arenaLo + size);
    g_EnvHeapModule.heapHandle = heap;
    if (heap == -1) {
        ok = 0;
    }
    return ok;
}
