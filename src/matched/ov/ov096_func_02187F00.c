/*
 * function: TR_AI_Create
 * address: 0x02187F00
 * packet: pkt_ov096_02187F00
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (wD9r lane35): EXACT. Fix: heap is a u16 parameter and the heap-taking callees
 *   (func_02030734, func_020490F4, FILE_UTIL_Create_0F14, VM_Create, WAZA_TOOL_CreateCache) take u16 heap, the house
 *   heap-id form. With u16 consumers mwcc loads the u16 stack parameter with a word ldr (no add/ldrh) and
 *   the tag pool load is no longer hoisted above the parameter homing.
 * 2026-10-05 (wD9 lane09): still DIFF 14 bytes. Tried an unprototyped alloc callee
 *   (`extern void *func_02030734();`, K&R argument promotion): same 14, the 0x1D9 pool load stays first.
 * 2026-10-05 (wD8 lane03): still DIFF 14 bytes. Tried `u16 heap` as in the matched siblings
 *   ov021 0218E018 and ov093 021BA9C8 (they ldrh the stack argument; the image here uses a word ldr, 165 bytes,
 *   rejected). The ov093 caller (021CD87E) passes a ldrh value for heap and a word (func_021B9FBC returns a word)
 *   for d. Reading: our tag pool load goes first because its chain (ldr r0, str [sp], adds r0,r5, bl) is the
 *   longest after the r0 reuse; the image order has no such hoist.
 * 2026-10-04 (wave D2 lane 08): re-tested, still DIFF (14 bytes, one scheduling difference: the 0x1D9 tag pool load is hoisted above 'str r3,[sp,#8]' in ours, after 'ldr r5,[sp,#0x20]' in the image). Also tried tag parameter as u32 and a 0x1D9u literal; no change.
 * note: 2026-10-04 Residue: one scheduling difference. Original loads the 0x1D9 tag pool word (ldr r0,[pc]) after 'ldr r5,[sp,#0x20]' and before the site-string ldr; ours loads it first. Everything else is byte-identical (176 bytes, same pool). Tried: decimal tag, u16 tag local, copy of heap.
 * note: 2026-10-05 (wD4 lane20): re-tested with a u32 heap copy local (h = heap) passed as the first argument; same 14 bytes, the 0x1D9 pool load still hoisted above the parameter spills. Residue unchanged: tag ldr r0 order only.
 * 2026-10-05 (wD5 lane20): tried the callee tag parameter as int and the clear/tag parameters as u32 (same 14 bytes, the 0x1D9 pool load stays first). The image order is spills, ldr r5 (heap), tag pool word, site pool word; ours emits the tag pool load before the spills.
 * 2026-10-05 (wD6 lane15): still DIFF 14 bytes (tag pool load hoisted to +0006). Tried: alloc in a
 *   static inline helper (heap only, and heap/size/site/line parameters), int heap, a block-local heap copy:
 *   same 14. Test only: d as u16 pins the d home store first (12 bytes, tag then lands after str r3);
 *   c u16 pins str r2 to the very front. Not adopted: the ov093 caller (021CD87E) passes an int
 *   (func_021B9FBC result) for d, so the parameter is word. The image order a, d, b, c, heap, tag, site
 *   looks like an unscheduled prologue; no source form found that keeps the tag load below the heap load.
 * 2026-10-05 (wD9r lane11): still DIFF 14. Reading: the image looks like an IR order homing, heap load,
 *   tag, site with the scheduler only filling the tag ldr->str delay with the site ldr; ours hoists the
 *   tag ldr above the homing, as if heap were loaded at its first use (call setup) and not at entry.
 *   No new source form tested closes it (no code-free way to force the heap load first).
 * 2026-10-05 (wD7 lane20): still DIFF 14 bytes. Tried: a dead label before the alloc call (no block split,
 *   same 14); c and d as one 8-byte struct parameter (homes r0-r3, 156 bytes); the tag as the address of a
 *   data symbol at 0x1D9 with a u32 callee parameter (same 14: pool loads are hoisted either way). The image
 *   keeps both pool loads (tag, site) below the parameter homing and the heap load, as if the homing code
 *   were scheduled apart from the body.
 * 2026-10-05 (wD9r lane21): still DIFF 14. Tried (compiled): a K&R (old-style) definition of
 *   TR_AI_Create itself (parameter homing unchanged, same 14, tag ldr still at +0006).
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   FILE_UTIL_Create_0F14 0x02020F14 thumb
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 *   VM_Create 0x0201121C thumb
 *   VM_Init 0x0201126C thumb
 *   WAZA_TOOL_IsCacheCreated 0x0201C408 thumb
 *   WAZA_TOOL_CreateCache 0x0201C328 thumb
 *   TR_AI_InitScriptCache 0x0218A41C thumb ov096
 *   gTrAiAllocSite 0x0218A7A0 data
 *   gTrAiVmParams 0x0218A574 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
struct ScriptVm;
struct ScriptVmParams;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(u32 id, u16 heap);
extern void *FILE_UTIL_Create_0F14(u16 heap);
extern u32 BTL_MAIN_GetRule(void **p);
extern void *BTL_MAIN_GetCompetitor(void ***p);
extern struct ScriptVm *VM_Create(u32 heapId, const struct ScriptVmParams *params);
extern void VM_Init(struct ScriptVm *vm, void *user);
extern u32 WAZA_TOOL_IsCacheCreated(void);
extern void WAZA_TOOL_CreateCache(s32 n, u32 heap);
extern void TR_AI_InitScriptCache(unsigned int a);
extern const char gTrAiAllocSite[];
extern u8 gTrAiVmParams[];
void *TR_AI_Create(void **a, u32 b, u32 c, u32 d, u16 heap)
{
    u8 *p;
    void *v;
    p = func_02030734(heap, 0xD8, 1, gTrAiAllocSite, 0x1D9);
    *(u16 *)(p + 0xA0) = heap;
    *(u32 *)(p + 0xC4) = 1;
    *(u32 *)(p + 0x40) = d;
    *(void **)(p + 0xA4) = func_020490F4(0xAB, heap);
    *(void **)(p + 0xA8) = FILE_UTIL_Create_0F14(heap);
    *(void ***)(p + 0xB0) = a;
    *(u32 *)(p + 0xB4) = b;
    *(u32 *)(p + 0xB8) = c;
    *(u32 *)(p + 0x98) = BTL_MAIN_GetRule(a);
    *(void **)(p + 0x9C) = BTL_MAIN_GetCompetitor((void ***)a);
    v = VM_Create(heap, (const struct ScriptVmParams *)gTrAiVmParams);
    VM_Init(v, p);
    if (WAZA_TOOL_IsCacheCreated() == 0)
        WAZA_TOOL_CreateCache(0x30, heap);
    TR_AI_InitScriptCache(*(u16 *)(p + 0xA0));
    return v;
}
