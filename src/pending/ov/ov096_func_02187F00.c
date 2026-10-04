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
 * note: 2026-10-04 Residue: one scheduling difference. Original loads the 0x1D9 tag pool word (ldr r0,[pc]) after 'ldr r5,[sp,#0x20]' and before the site-string ldr; ours loads it first. Everything else is byte-identical (176 bytes, same pool). Tried: decimal tag, u16 tag local, copy of heap.
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
