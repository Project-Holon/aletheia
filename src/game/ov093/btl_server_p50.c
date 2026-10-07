/*
 * file:     btl_server_p50.c
 * unit:     yes
 * function: func_021C199C, func_021C19D8, func_021C1A10, func_021C1A54
 * address:  0x021C199C
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
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C1CE4 0x021C1CE4 thumb ov093
 *   func_021C1B5C 0x021C1B5C thumb ov093
 *   func_021C1B2C 0x021C1B2C thumb ov093
 *   func_021C1B3C 0x021C1B3C thumb ov093
 *   func_021C1B4C 0x021C1B4C thumb ov093
 *   func_021C195C 0x021C195C thumb ov093
 *   func_021C1C88 0x021C1C88 thumb ov093
 */
#include "../../matched/include/Obj13324.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int, u32);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C1CE4(u8 *p, u8 *q, u32 unused, u8 *w);
extern void func_021C1B5C(u8 *p, u8 *a, u8 *b, u8 *c, u32 d, u8 e, int f);
extern void func_021C1B2C(u8 *);
extern u8 *func_021C1B3C(u8 *);
extern u8 *func_021C1B4C(u8 *);
extern void func_021C195C(u8 *p, u8 *q, u32 n);
extern void func_021C1C88(u8 *p, u8 *a, u32 unused, u8 *q, u32 v);
void func_021C199C(u8 *p, u8 *q, u32 n);
void func_021C19D8(u8 *p, u8 *a, u8 *q);
void func_021C1A10(u8 *p, u8 *a, u8 *q);
void func_021C1A54(u8 *p, u8 *a, u8 *b, u8 *c, u32 unused, u32 d);


void func_021C199C(u8 *p, u8 *q, u32 n)
{
    func_021D74F8(0x1acf);
    func_021D75EC(2, func_021D5440(q));
    func_021D75EC(0x2e, n);
    func_021D70F0(p, 0x91);
    func_021D7540(0x1acf + 4);
}


/*
 * interface: Complete lock word returned in r0 at 021CC900; restore
 * 021CC95C stores the unchanged full r1 word. Scalar u32 preserves all bits.
 */
void func_021C19D8(u8 *p, u8 *a, u8 *q)
{
    u32 s = func_021CC8D8(p + 0x1d74, 6874);
    func_021C1A10(p, a, q);
    func_021CC95C((u32 *)(p + 0x1d74), s, 6874 + 2);
}


void func_021C1A10(u8 *p, u8 *a, u8 *q)
{
    func_021D74F8(6890);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, ((struct Obj13324 *)q)->f0);
    func_021D75EC(0x16, q[6]);
    func_021D70F0(p, 0x81);
    func_021D7540(6897);
}

void func_021C1A54(u8 *p, u8 *a, u8 *b, u8 *c, u32 unused, u32 d)
{
    u32 lock;
    u8 *x;
    func_021C1CE4(p, a, (u32)b, c);
    lock = func_021CC8D8(p + 0x1d74, 0x1b07);
    func_021C1B5C(p, b, c, a, d, 0, 0x84);
    func_021C1B5C(p, b, c, a, d, 1, 0x83);
    func_021C1B5C(p, b, c, a, d, 0, 0x85);
    func_021C1B2C(c);
    x = func_021C1B3C(c);
    while (x) {
        func_021C195C(p, x, 1);
        x = func_021C1B4C(c);
    }
    func_021C1B5C(p, b, c, a, d, 0, 0x86);
    func_021C1B5C(p, b, c, a, d, 1, 0x87);
    func_021C1C88(p, b, (u32)c, a, d);
    func_021CC95C((u32 *)(p + 0x1d74), lock, 0x1b1b);
}
