/*
 * function: func_021C1D1C
 * address:  0x021C1D1C
 * packet:   pkt_021C1D1C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * 2026-10-04 (wave D3 lane 20): 596 of 600 bytes. Everything up to the loop matches. In the loop
 * body the original keeps x = ((i >> 1) / 4) << 4 in r5 and spills q = p + i*4 to sp+0x14;
 * this draft does the reverse (x spilled to sp+0x18, q in r5). i sits at sp+0x20 in the
 * original and sp+0x1c here: the original has one more spilled loop invariant. Tried: local
 * declaration order, no q local, a struct with a[8] and b[8][2] arrays (identical output).
 * Zero stack arguments come from i = 0 (ldr from the i slot), kept. y = (i % 4) * 6.
 *
 * 2026-10-05 (wave D4 lane 04): DIFF, 313 bytes. func_020450F0 third parameter is u8 here (the
 * original truncates y + 1 with lsls/lsrs #0x18 in both calls and hoists the inner (u8)(y + 1) to
 * [sp,#0x24]); x written inline as (i / 4 << 4) (a CSE temp in r5, as in the original); q and r
 * locals removed. i is now at [sp,#0x20] as in the original. Residue: y = (i % 4) * 6 spilled to
 * [sp,#0x1c]; the original keeps y in r7 and spills p + i*4 to [sp,#0x14]; size still 596 vs 600.
 * Tried: y inline too (y + 1 then CSEs, wrong), y declared first or last, register y.
 * 2026-10-05 (wave D5 lane 08): DIFF, 284 bytes (size still 596 vs 600). Logic fix: the original computes
 *   x = (i / 4) << 4 (asrs #1; lsrs #0x1e; adds; asrs #2 is the signed /4 idiom), not (i >> 1) / 4.
 *   Named locals x and q = p + i*4 now give the original order (u8)(y + 1), x, q. Residue: y spilled to
 *   [sp,#0x18] with x in r7 and q in r5; the original keeps y in r7, x in r5 and spills q to [sp,#0x14]
 *   (i at [sp,#0x20]). With x and q inline (no locals) x is in r5 and i at [sp,#0x20] but y is spilled.
 * symbols:
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   func_02049658  0x02049658  arm
 *   func_02049990  0x02049990  arm
 *   func_02049EF4  0x02049EF4  arm
 *   func_021C1FE8  0x021C1FE8  thumb  ov099
 *   func_02049B40  0x02049B40  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void *func_02049EF4(void *h, u32 a1, u32 a2, void **out, u16 heap);
extern void func_021C1FE8(u16 *p, u16 d);
extern void func_02049B40(u32 h, u32 a, u32 c, u32 d, u32 e, u16 heap);
extern void *func_020450F0(int, u8, u8, int, u8, u8, u8);
extern void *func_02045770(void *p);
extern void func_02043B5C(void *buf, u8 value);
extern void func_02045334(void *d);
extern void func_02045374(void *cfg);
extern void func_020409B4(u32 index);

void func_021C1D1C(u8 *p, void *a, u32 heap)
{
    int i;
    int j;
    int x;
    int y;
    u8 *q;
    u8 *q2;
    u8 *r;

    i = 0;
    func_02049B68(a, 6, 4, 0, 0x100, heap);
    *(u32 *)(p + 0x9A8) = func_02049740(a, 0xe, 4, 0, i, heap);
    func_02049658(a, 0xf, 6, 0x80, i, i, heap);
    func_02049990(a, 0x16, 4, 0, (u16)*(u32 *)(p + 0x9A8), i, i, heap);
    *(void **)(p + 0x8B4) = func_02049EF4(a, 0x17, 0, (void **)(p + 0x8B8), heap);
    func_021C1FE8(*(u16 **)(p + 0x8B8), 0x80);
    *(void **)(p + 0x8BC) = func_02049EF4(a, 0x19, 0, (void **)(p + 0x8C0), heap);
    func_021C1FE8(*(u16 **)(p + 0x8C0), 0x80);
    func_02049B40(0x17, 5, 4, 0xf << 5, 0x20, heap);
    for (i = 0; i < 8; i++) {
        y = (i % 4) * 6;
        x = i / 4 << 4;
        q = p + i * 4;
        *(void **)(q + 0x8F8) = func_020450F0(7, x + 4, y + 1, 9, 3, 0xf, 1);
        func_02043B5C(func_02045770(*(void **)(q + 0x8F8)), 0);
        func_02045334(*(void **)(q + 0x8F8));

        for (j = 0; j < 2; j++) {
            *(void **)(p + i * 8 + j * 4 + 0x918) = func_020450F0(5, x + 1 + j * 12, y + 1, 2, 3, 0xf, 1);
            func_02043B5C(func_02045770(*(void **)(p + i * 8 + j * 4 + 0x918)), 0);
            func_02045334(*(void **)(p + i * 8 + j * 4 + 0x918));
        }
    }
    *(void **)(p + 0x958) = func_020450F0(7, 1, 1, 0x1e, 2, 0xf, 1);
    func_02043B5C(func_02045770(*(void **)(p + 0x958)), 0);
    func_02045374(*(void **)(p + 0x958));
    func_02045334(*(void **)(p + 0x958));
    *(void **)(p + 0x95C) = func_020450F0(7, 1, 5, 0x1e, 0x11, 0xf, 1);
    func_02043B5C(func_02045770(*(void **)(p + 0x95C)), 0);
    func_02045374(*(void **)(p + 0x95C));
    func_02045334(*(void **)(p + 0x95C));
    func_020409B4(4);
    func_020409B4(7);
}
