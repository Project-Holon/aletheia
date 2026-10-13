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
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb  arm9
 */
#include "../include/Obj01404.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef struct { int f00, f04, f08, f0c; } Row;
typedef struct { char pad00[0x10]; void *f10[11]; } Object;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct StrObj;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_0201F7A8(void *, unsigned);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void PRINTSYS_PrintColor(void *, s16, s16, void *, void *, u16);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021D44BC(int i, Object *p, Row *row, const int *xs, const int *ys)
{
    int x, y;
    if (p->f10[i]) {
        BMP_WIN_ClearScreen(p->f10[i]);
        func_0201F7A8(p->f10[i], 2);
        func_020452E8(p->f10[i]);
        p->f10[i] = 0;
    }
    p->f10[i] = (void *)BMP_WIN_Create(7, (u8)row->f00, (u8)row->f04, (u8)row->f08, row->f0c, 13, 0);
    x = 0;
    BMP_Clear(func_02045770(p->f10[i]), 0);
    if (xs) x = xs[i] - (func_0201D304(((struct Obj01404 *)p)->f54, *(u32 *)&((struct Obj01404 *)p)->f4C, 0) >> 1);
    if (ys) y = ys[i] - (func_0201D42C(((struct Obj01404 *)p)->f54, ((struct Obj01404 *)p)->f4C) >> 1);
    else y = 0;
    PRINTSYS_PrintColor(func_02045770(p->f10[i]), x, y, ((struct Obj01404 *)p)->f54, ((struct Obj01404 *)p)->f4C, 0x39e3);
    BMP_WIN_TransferChars(p->f10[i]);
    BMP_WIN_MakeScreen(p->f10[i]);
    func_02041B6C(7);
}
