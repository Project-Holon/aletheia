/*
 * file:     btl_server_p48.c
 * unit:     yes
 * function: func_021C1624, func_021C1678, func_021C16F8, func_021C1758
 * address:  0x021C1624
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int line);
extern int func_021D59B4(u8 *p, int k);
extern void func_021D7630(int key, u32 val);
extern int func_021D775C(int key);
extern void func_021CD64C(void *w, u8 id, ...);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021CC95C(u32 *p, u32 v, int line);
void func_021C1624(u8 *p, u8 *a, u8 *b, u16 *c);
int func_021C1678(u8 *p, u8 *a, u8 *b, u32 c, u16 *d);
void func_021C16F8(u8 *p, u8 *a, int k);
void func_021C1758(u8 *p, u8 *q, int k);


void func_021C1624(u8 *p, u8 *a, u8 *b, u16 *c)
{
    func_021D74F8(0x19bd);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x12, c[0]);
    func_021D75EC(0x16, ((u8 *)c)[6]);
    func_021D70F0(p, 0x45);
    func_021D7540(0x19bd + 7);
}


int func_021C1678(u8 *p, u8 *a, u8 *b, u32 c, u16 *d)
{
    int r;
    if (func_021D59B4(b, 13) > *d) return 0;
    func_021D74F8(0x19df);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x51, c);
    func_021D7630(0x3a, 0);
    func_021D70F0(p, 0x74);
    r = func_021D775C(0x3a);
    func_021D7540(0x19df + 7);
    if (r != 0) *d = func_021D59B4(b, 13) - 1;
    return r;
}


/*
 * The empty `case 3: break;` is what keeps the `cmp r4, #3` and the
 * unconditional branch; a plain `if (k == 3) {}` compiles differently.
 */
void func_021C16F8(u8 *p, u8 *a, int k)
{
    u32 s;
    u8 n = func_021D5440(a);
    switch (k) {
    case 1:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x202, n, 0xffff0000);
        return;
    case 3:
        break;
    }
    s = func_021CC8D8(p + 0x1d74, 0x1a04);
    func_021C1758(p, a, k);
    func_021CC95C((u32 *)(p + 0x1d74), s, 0x1a07);
}


void func_021C1758(u8 *p, u8 *q, int k)
{
    func_021D74F8(0x1a17);
    func_021D75EC(2, func_021D5440(q));
    func_021D70F0(p, 0x75);
    func_021D7540(0x1a17 + 3);
}
