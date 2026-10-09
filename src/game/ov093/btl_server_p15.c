/*
 * file:     btl_server_p15.c
 * unit:     yes
 * function: func_021BD9D4, func_021BDA00
 * address:  0x021BD9D4
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
 *   func_021BD8F0 0x021BD8F0 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021BDB28 0x021BDB28 thumb ov093
 *   func_021BD2B4 0x021BD2B4 thumb ov093
 *   func_021BD34C 0x021BD34C thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021BDB38 0x021BDB38 thumb ov093
 *   func_021BDB48 0x021BDB48 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021BDBEC 0x021BDBEC thumb ov093
 *   func_021C88E4 0x021C88E4 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021BDB58 0x021BDB58 thumb ov093
 *   func_021BDB68 0x021BDB68 thumb ov093
 *   func_021BDB88 0x021BDB88 thumb ov093
 *   func_021BDB78 0x021BDB78 thumb ov093
 *   func_021BDC0C 0x021BDC0C thumb ov093
 */
#include "../../matched/include/Obj00003.h"

typedef unsigned char u8;

typedef unsigned int u32;

struct Cursor { u8 a, b, c, d; };

enum Offset { queue = 0x1a68 };

extern void func_021BD8F0(u8 *, u8, u8, u8);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021BDB28(void *);
extern void func_021BD2B4(u8 *p, u8 **q);
extern int func_021BD34C(u8 *p, u8 **q, u8 **out);
extern u8 func_021D5440(u8 *p);
extern void func_021BDB38(void *, u8 *);
extern void func_021BDB48(void *, u8 *);
extern u32 func_021CC8D8(void *, int);
extern void func_021BDBEC(u8 *);
extern int func_021C88E4(u8 *);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021BDB58(void *);
extern u8 *func_021BDB68(void *);
extern void func_021BDB88(u8 *, u8 *);
extern u8 *func_021BDB78(void *);
extern void func_021BDC0C(u8 *);
void func_021BD9D4(u8 *p, u8 i, u8 a, u8 b, int c);
int func_021BDA00(u8 *p);

/*
 * extent: 42-byte function followed by 2-byte zero alignment padding.
 */
void func_021BD9D4(u8 *p, u8 i, u8 a, u8 b, int c)
{
    func_021BD8F0(p, i, a, b);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 61, i, a, b, (u8)c);
}

/*
 * lever: enum queue offset declared after the live locals retains r7;
 * cursor declared before out places cursor at sp+8 and out at sp+4.
 */
int func_021BDA00(u8 *p)
{
    int result = 0;
    struct Cursor cursor;
    u8 *out;
    u32 lock;
    u8 *flag;
    enum Offset q = queue;
    func_021BDB28(p + q);
    func_021BD2B4((u8 *)(&cursor), (u8 **)p);
    while (func_021BD34C((u8 *)(&cursor), (u8 **)p, &out) != 0) {
        flag = p + func_021D5440(out);
        if (flag[0x7c1] != 0) {
            func_021BDB38(p + q, out);
            flag[0x7c1] = 0;
        }
    }
    func_021BDB48(p + q, p);
    lock = func_021CC8D8(p + 0x1d74, 3096);
    func_021BDBEC(p);
    if (func_021C88E4(p) != 0) result = 1;
    func_021CC95C((u32 *)(p + 0x1d74), lock, 3102);
    func_021BDB58(p + q);
    out = func_021BDB68(p + q);
    while (out != 0) {
        lock = func_021CC8D8(p + 0x1d74, 3108);
        func_021BDB88(p, out);
        if (func_021C88E4(p) != 0) result = 1;
        func_021CC95C((u32 *)(p + 0x1d74), lock, 3114);
        out = func_021BDB78(p + q);
    }
    lock = func_021CC8D8(p + 0x1d74, 3117);
    func_021BDC0C(p);
    if (func_021C88E4(p) != 0) result = 1;
    func_021CC95C((u32 *)(p + 0x1d74), lock, 3123);
    return result;
}
