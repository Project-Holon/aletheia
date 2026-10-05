/*
 * function: func_021C8F88
 * address: 0x021C8F88
 * packet: pkt_ov128_021C8F88
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-05 (wave P5 lane T2): written from the listing, 460 bytes, same size, same
 *   instruction stream. Only residue: the loop counter i and the text buffer are in swapped
 *   callee-saved registers (original text r4, i/const 10 r5; build text r5, i/10 r4), 38 bytes
 *   of register operands plus entry-prologue order. Spill slots match (w1, buf2, gfx, pal, n
 *   declared in that order). Tried: six per-function pragmas (opt_lifetimes, opt_propagation,
 *   opt_common_subs, opt_dead_assignments, scheduling, peephole; none helps, opt_propagation
 *   is worse), decl order of i/x/t/text, do-while loop, i assigned before pal, ctx fields read
 *   inline in the loop (worse), int n. 17 compiles used.
 *   Struct: p is two 8-byte windows (desc at +0, +8), p+0x10 = archive handle, p+0x14 = out ptr;
 *   q+4 holds the save object; ctx+4 bank, +8 archive, +0x34 / +0x17c gfx args. Friend code
 *   screen: u64 key, 12 digits (u64 /10, %10), gap of 8 after every 4th digit.
 *   All callee prototypes already match the arity of the call sites.
 * symbols:
 *   func_021C63AC 0x021C63AC thumb ov128
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_021CA4B4 0x021CA4B4 thumb ov128
 *   func_020457B0 0x020457B0 arm
 *   func_0201283C 0x0201283C thumb
 *   func_02009860 0x02009860 thumb
 *   func_0205994C 0x0205994C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045738 0x02045738 arm
 *   func_0204581C 0x0204581C arm
 *   func_02045AFC 0x02045AFC arm
 *   func_02045808 0x02045808 arm
 *   func_02049EF4 0x02049EF4 arm
 *   _ll_udiv 0x0209C00C arm
 *   _ull_mod 0x0209C018 arm
 *   d_021CA674 0x021CA674 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct { u16 v[10]; } Tbl;
extern const Tbl d_021CA674;
extern void func_021C63AC(void *, u32 *, u32, u32, u8, u8, u8, u8, u32, u8);
extern void func_021B6AE4(u8 *p, u32 a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern void func_021CA4B4(char *p);
extern void *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_0201283C(void *p);
extern void *func_02009860(void *p);
extern u64 func_0205994C(void *userdata);
extern void func_02045CAC(void *bank, u32 index, void *dest);
extern u32 func_02045738(void *p);
extern void func_0204581C(void *buf);
extern void func_02045AFC(void *buf, u32 c);
extern void func_02045808(void *p);
extern void *func_02049EF4(void *arc, u32 id, u32 comp, void **out, u32 heap);
static inline u8 *second(u8 *p)
{
    return p + 8;
}
void func_021C8F88(u8 *p, u8 *q, u8 *ctx, u32 heap)
{
    u8 *w1;
    void *buf2;
    u32 gfx;
    u32 pal;
    u32 n;
    void *text;
    u64 key;
    Tbl t;
    int x;
    int i;
    func_021C63AC(ctx, (u32 *)p, 3, 2, 10, 0x1e, 8, 10, 1, 0);
    func_021C63AC(ctx, (u32 *)(p + 8), 3, 9, 6, 0xe, 2, 10, 0xf1, 0);
    text = func_020457B0(0xc0, heap);
    buf2 = func_020457B0(0x80, heap);
    key = func_0205994C(func_02009860((void *)func_0201283C(*(void **)(q + 4))));
    if (key != 0) {
        func_02045CAC(*(void **)(ctx + 4), 0x35, text);
        func_021B6AE4(p, *(u32 *)(ctx + 0x34), 4, 0, (u32)text, *(u32 *)(ctx + 0x17c), 0x440, 0);
        func_021CA4B4(*(char **)p);
        pal = *(u32 *)(ctx + 0x17c);
        gfx = *(u32 *)(ctx + 0x34);
        t = d_021CA674;
        x = 0;
        n = func_02045738(*(void **)(p + 8));
        w1 = second(p);
        for (i = 1; i <= 12; i++) {
            func_0204581C(text);
            func_02045AFC(text, t.v[key % 10]);
            func_021B6AE4(w1, gfx, (u16)((n - i) * 8 - x + 1), 0, (u32)text, pal, 0x3c40, 0);
            if (i % 4 == 0)
                x += 8;
            key = key / 10;
        }
        func_021CA4B4(*(char **)(p + 8));
    } else {
        func_02045CAC(*(void **)(ctx + 4), 0x36, text);
        func_021B6AE4(p, *(u32 *)(ctx + 0x34), 4, 0, (u32)text, *(u32 *)(ctx + 0x17c), 0x440, 0);
        func_021CA4B4(*(char **)p);
    }
    func_02045808(text);
    func_02045808(buf2);
    *(void **)(p + 0x10) = func_02049EF4(*(void **)(ctx + 8), 6, 0, (void **)(p + 0x14), heap);
}
