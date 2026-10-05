/*
 * function: func_021D4384
 * address: 0x021D4384
 * packet: pkt_ov122_021D4384
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 wave P7 lane V6. Shape taken from the ov122 twin 021D44BC (same callees, same object). Struct with real fields (pad at 0x3c) closed it; earlier drafts used raw offsets.
 * symbols:
 *   func_02049B40 0x02049B40 arm
 *   func_020456F8 0x020456F8 arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020452E8 0x020452E8 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02051C6C 0x02051C6C arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { int f00, f04, f08, f0c; } Row;
typedef struct { char pad00[0xc]; u16 heap; u16 pad0e; void *f10[11]; int pad3c; void *f40; void *f44; int pad48; void *f4C; int pad50; void *f54; char pad58[0x348-0x58]; int f348; } Object;
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern void func_020456F8(void *);
extern void func_0201F7A8(void *, unsigned);
extern void func_020452E8(void *);
extern void *func_020450F0(u32, u8, u8, u8, u8, u8, u8);
extern void *func_02045770(void *);
extern void func_02043B5C(void *, u8);
extern void func_02045CAC(void *, int, void *);
extern u32 func_0201D304(void *, u32, u32);
extern u32 func_0201D42C(void *, void *);
extern void func_0201C7D0(void *, s16, s16, void *, void *, u16);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern void func_02051C6C(void *);
extern void func_02041B6C(u32);
void func_021D4384(int count, int *values, Object *p, Row *rows, const int *xs, const int *ys)
{
    int i, x, y;
    p->f348 = count;
    func_02049B40(23, 5, 4, 384, 32, p->heap);
    for (i = 0; i < 11; i++) {
        if (p->f10[i]) {
            func_020456F8(p->f10[i]);
            func_0201F7A8(p->f10[i], 2);
            func_020452E8(p->f10[i]);
        }
        p->f10[i] = 0;
    }
    for (i = 0; i < count; i++) {
        p->f10[i] = func_020450F0(7, rows[i].f00, rows[i].f04, rows[i].f08, rows[i].f0c, 13, 0);
        func_02043B5C(func_02045770(p->f10[i]), 0);
        func_02045CAC(p->f44, values[i], p->f54);
        if (xs) x = xs[i] - (func_0201D304(p->f54, (u32)p->f4C, 0) >> 1);
        else x = 0;
        if (ys) y = ys[i] - (func_0201D42C(p->f54, p->f4C) >> 1);
        else y = 0;
        func_0201C7D0(func_02045770(p->f10[i]), x, y, p->f54, p->f4C, 0x39e3);
        func_02045334(p->f10[i]);
        func_02045374(p->f10[i]);
    }
    if (p->f40) func_02051C6C(p->f40);
    p->f40 = 0;
    func_02041B6C(7);
}
