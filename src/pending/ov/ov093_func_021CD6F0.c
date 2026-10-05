/*
 * function: func_021CD6F0
 * address: 0x021CD6F0
 * packet: pkt_ov093_021CD6F0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note: final push 2026-10-05 G8L5: 496 B (same size as the original), 37 B differ, was 108 B
 *   differing at 492 B. Fix found: the 4-iteration loop stores the constant 0, not i (the copy
 *   adds r2,r3,#0 sits before the loop label; docs/idioms/a-copy-of-the-counter-before-the-loop-
 *   label-is-a-stored-zero.md). Remaining residue is only the entry schedule (+0006..+0054):
 *   the original puts the flag constant in r2 (movs r2,#1; str r2,[sp,#0xc]) so the heap
 *   write-back str [sp,#0x40] sinks below it and idx is loaded early (ldr r7); ours puts the
 *   constant in r0, which pins the write-back right after its load and moves ldr r7 last, and
 *   ldr r3 (heap) above strb e. Tried with no change in the 37 B: flag as 3rd alloc arg, flag=1
 *   inside the call args (3rd, 4th, 5th), decl initialiser, u8/u16/u32 flag, locals order,
 *   one = flag = 1, named locals with opt_propagation off (do-while loop), all six pragmas,
 *   halloc static inline, second extern name for the second alloc, u32 copy of heap, idx as
 *   int/u32/u8, c/d as u32, const on h and on a/b. heap as int, const u32, u16 or u8 drops the
 *   write-back or changes the frame (worse). Matched-assembly search for the same entry
 *   sequence (str r3; movs r2,#1; str r2) hit only ov021 02199B38 (outgoing stack args, not
 *   the same shape) and ov195 022083EC.
 *   Earlier: 2026-10-05 (wave P4 lane S10, pengy share) 492 B vs 496 B (the extra 2 B are the
 *   pool-alignment nop). Body, calls, field offsets and the callee argument order match. Residue
 *   1: prologue schedule: original orders adds r6/ldr r7 idx/ldr r0 heap/adds r4/str r3/movs r2,1/
 *   str flag, then the heap write-back str [sp,#0x40] after the pool load; ours puts the heap
 *   write-back and a movs r0,1 earlier. Residue 2: the 4-iteration byte-id loop has i in r3 and a
 *   copy r2=r3 stored after the increment is scheduled; ours uses i in r2 with no copy. Tried:
 *   u32 heap (fixes the heap word load, str write-back), u16 heap, flag as 3rd alloc arg vs literal
 *   1, locals k for the 021B9FBC result (fixes call order), i declared first, do-while loop,
 *   i++ in the store (UB form, wrong), all six per-function pragmas (opt_propagation off gives
 *   496 B but adds a loop guard; none helps). Params: 5th is u16 idx, 6th u16, 7th u8, 8th and 9th
 *   read as words (int), 11th read as word.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F3A88 0x021F3A88 data a4
 *   func_021EEA58 0x021EEA58 thumb ov093
 *   func_021B9AF8 0x021B9AF8 thumb ov093
 *   func_021CDA18 0x021CDA18 thumb ov093
 *   func_021BA08C 0x021BA08C thumb ov093
 *   func_021D8230 0x021D8230 thumb ov093
 *   func_021D3F04 0x021D3F04 thumb ov093
 *   func_021D3D9C 0x021D3D9C thumb ov093
 *   func_021B9FBC 0x021B9FBC thumb ov093
 *   func_021BA820 0x021BA820 thumb ov093
 *   func_02187F00 0x02187F00 thumb ov096
 *   func_021B90F8 0x021B90F8 thumb ov093
 *   func_021EE5E4 0x021EE5E4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 f0:1,f1:1,f2:1,f3:1,f4:1,f5:1,rest:2; } Flags;
struct Copy24 { int x[6]; };
extern u8 d_021F3A88[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_021EEA58(u32, int, u32, u32);
extern char *func_021B9AF8(char *, int);
extern int func_021CDA18(u8 *);
extern u32 func_021BA08C(void *);
extern void func_021D8230(u8 *);
extern void func_021D3F04(u8 *);
extern void func_021D3D9C(u8 *);
extern int func_021B9FBC(char *, int);
extern u32 func_021BA820(int *);
extern void *func_02187F00(void **, u32, u32, u32, u16);
extern int func_021B90F8(u8 *);
extern void *func_021EE5E4(u32);

u8 *func_021CD6F0(u8 *a, u8 *b, int c, int d, u16 idx, u16 kind, u8 e, int f, int g, struct Copy24 *h, u32 heap)
{
    u8 *p;
    u32 i;
    int flag, k;
    flag = 1;
    p = func_02030734(heap, 0x1b8, 1, (const char *)d_021F3A88, 0x209);
    if (c == 0 || e != 0)
        flag = 0;
    p[0x1a6] = idx;
    *(u16 *)(p + 0x19a) = heap;
    p[0x1a7] = e;
    *(void **)(p + 0x50) = func_021EEA58(d, (u8)idx, flag, heap);
    *(char **)(p + 0x118) = func_021B9AF8((char *)b, idx);
    *(u8 **)p = a;
    *(u8 **)(p + 4) = b;
    p[0x11c] = kind;
    p[0x11d] = 0;
    p[0x121] = idx;
    p[0xc4] = 0;
    *(int *)(p + 0x54) = 0;
    *(u16 *)(p + 0x19c) = 0;
    *(void **)(p + 0x134) = func_02030734(heap, 0xbc0, 1, (const char *)d_021F3A88, 0x21a);
    *(void **)(p + 0x28) = (void *)func_021CDA18;
    p[0x1a8] = 0;
    *(int *)(p + 0xa0) = 0;
    ((Flags *)(p + 0x1b2))->f3 = 0;
    p[0x1ae] = 0;
    p[0x1a9] = 0;
    p[0x1ab] = 0;
    *(u16 *)(p + 0xe4) = 0;
    *(u16 *)(p + 0xe6) = 0;
    p[0x1ad] = 0;
    ((Flags *)(p + 0x1b2))->f0 = 0;
    ((Flags *)(p + 0x1b2))->f1 = 0;
    ((Flags *)(p + 0x1b2))->f4 = 0;
    ((Flags *)(p + 0x1b2))->f5 = 0;
    *(u32 *)(p + 0x34) = func_021BA08C(a);
    p[0x1aa] = f;
    func_021D8230(p + 0x2c);
    func_021D3F04(p + 0x18);
    func_021D3D9C(p);
    *(struct Copy24 *)(p + 0xf4) = *h;
    if (p[0x1a7] == 1 && g == 0) {
        k = func_021B9FBC(*(char **)p, p[0x1a6]);
        *(void **)(p + 0xf0) = func_02187F00(*(void ***)p, func_021BA820(*(int **)p), *(u32 *)(p + 4), k, *(u16 *)(p + 0x19a));
    } else {
        *(int *)(p + 0xf0) = 0;
    }
    for (i = 0; i < 4; i++)
        p[0x112 + i] = 0;
    if (p[0x1a7] == 0 && func_021B90F8(*(u8 **)p))
        *(void **)(p + 0x10) = func_021EE5E4(heap);
    else
        *(void **)(p + 0x10) = 0;
    return p;
}
