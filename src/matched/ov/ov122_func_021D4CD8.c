/*
 * function: func_021D4CD8
 * address: 0x021D4CD8
 * packet: pkt_ov122_021D4CD8
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   data_021D58E0 0x021D58E0 data a4
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct { int f00, f04, f08, f0c; } Row;
typedef struct { char pad00[0x10]; void *f10[11]; } Object;
extern Row data_021D58E0[];
extern void *func_020450F0(int, u8, u8, u8, u8, int, int);
extern void *func_02045770(void *);
extern void func_02043B5C(void *, int);
extern void func_02045CAC(void *, int, void *);
extern void func_0201F250(void *, void *, void *);
extern void func_0201C7D0(void *, s16, s16, void *, void *, u16);
extern void func_02045334(void *);
extern void func_02045374(void *);
void func_021D4CD8(int i, int value, int force, int mode, Object *p)
{
    if (p->f10[i] && !force) return;
    if (!p->f10[i])
        p->f10[i] = func_020450F0(7, data_021D58E0[i].f00, data_021D58E0[i].f04,
            data_021D58E0[i].f08, data_021D58E0[i].f0c, 13, 0);
    func_02043B5C(func_02045770(p->f10[i]), 0);
    if (mode) {
        func_02045CAC(*(void **)((char *)p + 0x44), value, *(void **)((char *)p + 0x50));
        func_0201F250(*(void **)((char *)p + 0x48), *(void **)((char *)p + 0x54), *(void **)((char *)p + 0x50));
    } else {
        func_02045CAC(*(void **)((char *)p + 0x44), value, *(void **)((char *)p + 0x54));
    }
    func_0201C7D0(func_02045770(p->f10[i]), 0, 0, *(void **)((char *)p + 0x54), *(void **)((char *)p + 0x4c), 0x39e3);
    func_02045334(p->f10[i]);
    func_02045374(p->f10[i]);
}
