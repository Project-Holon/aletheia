/*
 * function: func_021D44BC
 * address: 0x021D44BC
 * packet: pkt_ov122_021D44BC
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: x initialized after construction lets its zero share the outgoing stack argument.
 * symbols:
 *   func_020456F8 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { int f00, f04, f08, f0c; } Row;
typedef struct { char pad00[0x10]; void *f10[11]; } Object;
extern void func_020456F8(void *);
extern void func_0201F7A8(void *, unsigned);
extern void func_020452E8(void *);
extern void *func_020450F0(u32, u8, u8, u8, u8, u8, u8);
extern void *func_02045770(void *);
extern void func_02043B5C(void *, int);
extern u32 func_0201D304(void *, u32, u32);
extern u32 func_0201D42C(void *, void *);
extern void func_0201C7D0(void *, s16, s16, void *, void *, u16);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern void func_02041B6C(u8);
void func_021D44BC(int i, Object *p, Row *row, const int *xs, const int *ys)
{
    int x, y;
    if (p->f10[i]) {
        func_020456F8(p->f10[i]);
        func_0201F7A8(p->f10[i], 2);
        func_020452E8(p->f10[i]);
        p->f10[i] = 0;
    }
    p->f10[i] = func_020450F0(7, row->f00, row->f04, row->f08, row->f0c, 13, 0);
    x = 0;
    func_02043B5C(func_02045770(p->f10[i]), 0);
    if (xs) x = xs[i] - (func_0201D304(*(void **)((char *)p + 0x54), *(u32 *)((char *)p + 0x4c), 0) >> 1);
    if (ys) y = ys[i] - (func_0201D42C(*(void **)((char *)p + 0x54), *(void **)((char *)p + 0x4c)) >> 1);
    else y = 0;
    func_0201C7D0(func_02045770(p->f10[i]), x, y, *(void **)((char *)p + 0x54), *(void **)((char *)p + 0x4c), 0x39e3);
    func_02045334(p->f10[i]);
    func_02045374(p->f10[i]);
    func_02041B6C(7);
}
