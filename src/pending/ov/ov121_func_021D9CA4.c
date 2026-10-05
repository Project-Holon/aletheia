/*
 * function: func_021D9CA4
 * address: 0x021D9CA4
 * packet: pkt_ov121_021D9CA4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * lang: c99
 * residue: 8 of 168 bytes differ. Size equal. Only the order differs: the original has
 *   movs r0,#0x61; str r3,[sp,#0x10]; adds r7,r1,#0; str r2,[sp,#0xc]; ldr r5,[sp,#0x28]; lsls r0,r0,#2; str r0,[sp]
 *   and the build puts `lsls r0,r0,#2` right after the `movs`.
 * recoup 2026-10-05 (lane C8, wave P14): 0203101C declared (u32,u32,u32,u32) and heap u32 (the old u16 form
 *   added a shift pair, 164 B off): 168 B, 8 B off. Same 8 B with: direct call instead of inline helper,
 *   int heap, u32 a, u16 or int line local, u32 line parameter of 02030734, heap copied to a local, local
 *   order p/q swapped, pragmas scheduling, peephole, opt_propagation, opt_lifetimes, opt_common_subs,
 *   opt_dead_assignments off. c/d copied to locals: 148 B off. u8 a: 120 B off. Const c/d: compile error.
 *   Callee return types (matched definitions): 02030734 void*, 0203101C void*, 020450F0 u32, 020457B0 void*,
 *   02045730 int in most callers (u8 here, unchanged), 02045770 void*. No void-return problem.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020457B0 0x020457B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0203101C 0x0203101C arm
 *   d_021DFBA0 0x021DFBA0 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021DFBA0[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02082BCC(void *, int, u32);
extern void *func_020457B0(u32, u32);
extern u32 func_020450F0(u32, u32, u32, u32, u8, u8, u8);
extern void *func_02045770(void *);
extern void func_02043B5C(void *, u8);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern u8 func_02045730(void *);
extern void func_020409B4(u32);
extern void *func_0203101C(u32, u32, u32, u32);
static inline void *allocate(u32 heap, u32 size, const char *site, u16 line)
{
    return func_02030734(heap, size, 0, site, line);
}
void *func_021D9CA4(int a, u8 b, void *c, void *d, u32 heap)
{
    u8 *p;
    void *q;
    p = allocate(heap, 0x40, d_021DFBA0, 0x184);
    func_02082BCC(p, 0, 0x40);
    *(u16 *)(p + 0x18) = 15;
    *(void **)(p + 4) = d;
    *(void **)(p + 0x24) = c;
    *(u32 *)(p + 0x28) = 3;
    *(void **)(p + 0x14) = func_020457B0(0x300, heap);
    q = (void *)func_020450F0((u8)a, 1, 19, 30, 4, b, 1);
    *(void **)(p + 0x10) = q;
    *(void **)(p + 0x1c) = q;
    p[0x20] = 0;
    func_02043B5C(func_02045770(*(void **)(p + 0x10)), *(u16 *)(p + 0x18));
    q = *(void **)(p + 0x10);
    func_02045334(q);
    func_02045374(q);
    func_020409B4(func_02045730(q));
    *(void **)(p + 0xc) = func_0203101C(heap, heap, 1, 32);
    return p;
}
