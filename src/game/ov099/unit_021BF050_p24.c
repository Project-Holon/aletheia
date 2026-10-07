/*
 * file:     unit_021BF050_p24.c
 * unit:     yes
 * function: func_021C2028, func_021C203C, func_021C2050, func_021C205C, func_021C207C, func_021C208C, func_021C2090, func_021C2224
 * address:  0x021C2028
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BB2F0  0x021BB2F0  thumb  ov099
 *   func_02009864 0x02009864 thumb
 *   func_021C2274 0x021C2274 thumb ov099
 *   func_021C22E8 0x021C22E8 thumb ov099
 *   func_020414AC 0x020414AC arm
 *   func_02045374 0x02045374 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02043598 0x02043598 arm
 *   func_020410D0  0x020410D0  arm
 */
#include "../../matched/include/Obj18285.h"
#include "../../matched/include/Obj18286.h"
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj12129.h"

struct Cfg;
struct CharBuf;
struct Descriptor;
struct Sub020097BCObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021C2028;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef unsigned long  u32_021C203C;

typedef unsigned long  u32_021C2050;

typedef unsigned long  u32_021C205C;

typedef unsigned long  u32_021C207C;

typedef unsigned int u32_021C2090;

typedef unsigned int u32_021C2224;

extern void func_021BB2F0(char *p, int v);
extern u32_021C2090 func_02009864(const struct Sub020097BCObj *obj, u32_021C2090 i, u32_021C2090 field);
extern void func_021C2274(char *p, void *window, int id, int slot, int i);
extern void func_021C22E8(char *p, void *window, int id, int flag, int x, int y);
extern void func_020414AC(u32_021C2090 a);
extern void func_02045374(struct Cfg *cfg);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02041B6C(u32_021C2090 bit);
extern void func_02043598(u32_021C2090 mask, u32_021C2090 enable);
extern void func_020410D0(u32_021C2224 index, u32_021C2224 a1, u32_021C2224 a2, u32_021C2224 a3, u8 a4, u32_021C2224 a5, u8 a6, u8 a7, u8 a8, u8 a9);
void func_021C2028(char *p, int i, u8 v);
void func_021C203C(char *p, int i);
u8 func_021C2050(char *p, int i);
void func_021C205C(u8 *p, int v);
void func_021C207C(char *p);
void func_021C208C(char *a0);
void func_021C2090(char *p);
void func_021C2224(char *p, u32_021C2224 a1, u32_021C2224 a2, u32_021C2224 mode, u8 slot);


/*
 * Byte setter at index i of the 0x8CB table, then sets the byte at +0x8F1.
 */
void func_021C2028(char *p, int i, u8 v)
{
    *(u8 *)(p + i + 0x8CB) = v;
    ((struct Obj18285 *)p)->f8F1 = 1;
}


/*
 * Clears the byte at index i of the 0x8CB table, then sets the byte at +0x8F1.
 */
void func_021C203C(char *p, int i)
{
    *(u8 *)(p + i + 0x8CB) = 0;
    ((struct Obj18286 *)p)->f8F1 = 1;
}


u8 func_021C2050(char *p, int i)
{
    return *(u8 *)(p + i + 0x8CB);
}


/*
 * Routes on the flag byte 0x8EF bytes in: hands the selector on to func_021BB2F0
 * when it is set, otherwise raises the word at +0x8F4 and calls func_021C2090.
 * The selector stays live into the first branch, which is what keeps the 0x8EF
 * constant out of r1 and gives the image its `adds r1, r2, #5`.
 */
void func_021C205C(u8 *p, int v)
{
    if (p[0x8EF] != 0) {
        func_021BB2F0((char *)p, v);
        return;
    }

    *(u32_021C205C *)&((struct Obj00008 *)p)->f8F4 = 1;
    func_021C2090((char *)p);
}


/*
 * Sets the word at +0x8F4 and the byte at +0x8F1.
 */
void func_021C207C(char *p)
{
    ((struct Obj12129 *)p)->f8F4 = 1;
    ((struct Obj12129 *)p)->f8F1 = 1;
}

/*
 * Empty body: the original is a bare `bx lr`.  disasm.py labels it only
 * because something branches to it.
 */
void func_021C208C(char *a0)
{
}


void func_021C2090(char *p)
{
    int i;
    int flag;
    int idx;
    int mode;
    int slot;
    int px;
    int py;
    int sel;

    if (*(int *)(p + 0x8F4) == 1) {
        *(int *)(p + 0x8F4) = 0;
        flag = 1;
        func_020414AC(7);
    } else {
        flag = 0;
    }
    for (i = 0; i < 8; i++) {
        idx = i + *(u8 *)(p + 0x8EC) * 8 + 1;
        if (*(u8 *)(p + 0x8CB + idx) != 0) {
            if (func_02009864(*(void **)(p + 4), idx - 1, 9) == 0) {
                mode = 0;
            } else {
                mode = 1;
            }
        } else {
            mode = 2;
        }
        px = i / 4;
        py = i % 4;
        if (idx == *(u8 *)(p + 0x8ED)) {
            slot = *(u8 *)(p + 0x8EE);
        } else {
            slot = 0;
        }
        if (idx == *(u8 *)(p + 0x8ED) || idx == *(u8 *)(p + 0x8F3)) {
            sel = 1;
        } else {
            sel = 0;
        }
        if (flag == 1 || sel == 1) {
            func_021C2224(p, (u8)(px * 16), (u8)(py * 6), (u8)mode, (u8)slot);
            if (mode != 2) {
                func_021C2274(p, *(void **)(p + i * 4 + 0x8F8), idx, slot, i);
                func_02045374(*(void **)(p + i * 4 + 0x8F8));
                func_021C22E8(p, p + 0x918 + i * 8, idx, slot, px * 16, py * 6);
            } else {
                int j;
                func_02043B5C(func_02045770(*(void **)(p + i * 4 + 0x8F8)), 0);
                func_02045334(*(void **)(p + i * 4 + 0x8F8));
                for (j = 0; j < 2; j++) {
                    func_02043B5C(func_02045770(*(void **)(p + i * 8 + j * 4 + 0x918)), 0);
                    func_02045334(*(void **)(p + i * 8 + j * 4 + 0x918));
                }
            }
        }
    }
    func_02041B6C(7);
    func_02041B6C(6);
    func_02043598(2, 1);
    func_02043598(8, 1);
}


void func_021C2224(char *p, u32_021C2224 a1, u32_021C2224 a2, u32_021C2224 mode, u8 slot)
{
    u16 x;
    u16 y;
    if (mode == 2) {
        x = 0;
        y = 0x12;
    } else {
        x = (u16)(mode << 4);
        y = (u16)(slot * 6);
    }
    func_020410D0(6, a1, a2, 0x10, 6, *(u32_021C2224 *)(p + 0x8B8) + 0xC, x, y, 0x20, 0x18);
}
