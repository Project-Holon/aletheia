/*
 * function: func_02187F00
 * address: 0x02187F00
 * packet: pkt_ov096_02187F00
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
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
 * 2026-10-05 (wD7 lane20): still DIFF 14 bytes. Tried: a dead label before the alloc call (no block split,
 *   same 14); c and d as one 8-byte struct parameter (homes r0-r3, 156 bytes); the tag as the address of a
 *   data symbol at 0x1D9 with a u32 callee parameter (same 14: pool loads are hoisted either way). The image
 *   keeps both pool loads (tag, site) below the parameter homing and the heap load, as if the homing code
 *   were scheduled apart from the body.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02020F14 0x02020F14 thumb
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_0201121C 0x0201121C thumb
 *   func_0201126C 0x0201126C thumb
 *   func_0201C408 0x0201C408 thumb
 *   func_0201C328 0x0201C328 thumb
 *   func_0218A41C 0x0218A41C thumb ov096
 *   D_0218A7A0 0x0218A7A0 data
 *   D_0218A574 0x0218A574 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02020F14(u32 heap);
extern u32 func_021B8588(void **p);
extern void *func_021B86B8(void ***p);
extern void *func_0201121C(u32 heap, void *params);
extern void func_0201126C(void *vm, void *user);
extern u32 func_0201C408(void);
extern void func_0201C328(u32, u32);
extern void func_0218A41C(unsigned int a);
extern const char D_0218A7A0[];
extern u8 D_0218A574[];
void *func_02187F00(void **a, u32 b, u32 c, u32 d, u32 heap)
{
    u8 *p;
    void *v;
    p = func_02030734(heap, 0xD8, 1, D_0218A7A0, 0x1D9);
    *(u16 *)(p + 0xA0) = heap;
    *(u32 *)(p + 0xC4) = 1;
    *(u32 *)(p + 0x40) = d;
    *(void **)(p + 0xA4) = func_020490F4(0xAB, heap);
    *(void **)(p + 0xA8) = func_02020F14(heap);
    *(void ***)(p + 0xB0) = a;
    *(u32 *)(p + 0xB4) = b;
    *(u32 *)(p + 0xB8) = c;
    *(u32 *)(p + 0x98) = func_021B8588(a);
    *(void **)(p + 0x9C) = func_021B86B8((void ***)a);
    v = func_0201121C(heap, D_0218A574);
    func_0201126C(v, p);
    if (func_0201C408() == 0)
        func_0201C328(0x30, heap);
    func_0218A41C(*(u16 *)(p + 0xA0));
    return v;
}
