/*
 * file:     btl_server_p39.c
 * unit:     yes
 * function: func_021C15AC, func_021C15D4, func_021C15E8, func_021C1624, func_021C1678, func_021C16F8, func_021C1758, func_021C1788, func_021C17CC, func_021C1828, func_021C1880, func_021C18D4, func_021C1910, func_021C195C, func_021C199C, func_021C19D8, func_021C1A10, func_021C1A54
 * address:  0x021C15AC
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
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D6848  0x021D6848  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   sub_0201C1BC   0x0201C1BC  thumb
 *   func_021C2CD8  0x021C2CD8  thumb  ov093
 *   func_021C232C  0x021C232C  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021C1CE4 0x021C1CE4 thumb ov093
 *   func_021C1B5C 0x021C1B5C thumb ov093
 *   func_021C1B2C 0x021C1B2C thumb ov093
 *   func_021C1B3C 0x021C1B3C thumb ov093
 *   func_021C1B4C 0x021C1B4C thumb ov093
 *   func_021C1C88 0x021C1C88 thumb ov093
 */
#include "../../matched/include/Obj13320.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj02778.h"
#include "../../matched/include/Obj21078.h"
#include "../../matched/include/Obj09968.h"
#include "../../matched/include/Obj13323.h"
#include "../../matched/include/Obj13324.h"

struct QI;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Rec { u16 a; u16 b; u8 c; u8 d; u8 e; };

extern void func_021CD64C(void *, u8, ...);
extern int func_021D59B4(u8 *p, int k);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int line);
extern void func_021D7630(int key, u32 val);
extern int func_021D775C(int key);
extern void func_021D6848(u8 *c, struct Rec *r);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern u32 sub_0201C1BC(u16 move);
extern void func_021C2CD8(u8 *p, u16 *q, u8 *a, u8 *b);
extern void func_021C232C(u8 *p, const u16 *a, u8 *b, u8 *c);
extern u16 func_021D5B40(struct QI *p);
extern void func_021C1CE4(u8 *p, u8 *q, u32 unused, u8 *w);
extern void func_021C1B5C(u8 *p, u8 *a, u8 *b, u8 *c, u32 d, u8 e, int f);
extern void func_021C1B2C(u8 *);
extern u8 *func_021C1B3C(u8 *);
extern u8 *func_021C1B4C(u8 *);
extern void func_021C1C88(u8 *p, u8 *a, u32 unused, u8 *q, u32 v);
void func_021C15AC(u8 *p, int k);
u32 func_021C15D4(void *p, u32 n);
void func_021C15E8(u8 *p, u8 *a, u8 *b, u16 *c);
void func_021C1624(u8 *p, u8 *a, u8 *b, u16 *c);
int func_021C1678(u8 *p, u8 *a, u8 *b, u32 c, u16 *d);
void func_021C16F8(u8 *p, u8 *a, int k);
void func_021C1758(u8 *p, u8 *q, int k);
void func_021C1788(u8 *p, u32 x, u8 *a, u32 n, u32 *arr);
void func_021C17CC(u8 *p, u32 x, u8 *a, u32 n, u8 **arr);
void func_021C1828(u8 *p, u8 b, u8 *x, u8 *c, u8 *q, u16 w);
void func_021C1880(u8 *p, u8 *q, u8 *a, u8 *b, u32 s0, int s1);
void func_021C18D4(u8 *p, u8 *a, u8 *q, u32 v);
void func_021C1910(u8 *p, u8 *a, u8 *q, u32 v);
void func_021C195C(u8 *p, u8 *q, u32 n);
void func_021C199C(u8 *p, u8 *q, u32 n);
void func_021C19D8(u8 *p, u8 *a, u8 *q);
void func_021C1A10(u8 *p, u8 *a, u8 *q);
void func_021C1A54(u8 *p, u8 *a, u8 *b, u8 *c, u32 unused, u32 d);





void func_021C15AC(u8 *p, int k)
{
    if (k < 3) {
        func_021CD64C(((struct Obj13320 *)p)->fC, 0x5a, 0x4f, 0xffff0000);
    } else if (k > 3) {
        func_021CD64C(((struct Obj13320 *)p)->fC, 0x5a, 0x4e, 0xffff0000);
    }
}






u32 func_021C15D4(void *p, u32 n)
{
    u32 v = func_021D59B4(p, 13);
    if (n > v) n = v;
    return n;
}






/*
 * interface: Complete lock word returned in r0 at 021CC900; restore
 * 021CC95C stores the unchanged full r1 word. Scalar u32 preserves all bits.
 */
void func_021C15E8(u8 *p, u8 *a, u8 *b, u16 *c)
{
    u32 s = func_021CC8D8(p + 0x1d74, 6570);
    func_021C1624(p, a, b, c);
    func_021CC95C((u32 *)(p + 0x1d74), s, 6570 + 4);
}





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




void func_021C1788(u8 *p, u32 x, u8 *a, u32 n, u32 *arr)
{
    u32 s = func_021CC8D8(p + 0x1D74, 6697);
    func_021C17CC(p, x, a, n, (u8 **)arr);
    func_021CC95C((u32 *)(p + 0x1D74), s, 6702);
}




void func_021C17CC(u8 *p, u32 x, u8 *a, u32 n, u8 **arr)
{
    u32 i;
    func_021D74F8(6719);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(5, n);
    for (i = 0; i < n; i++) {
        func_021D75EC(6 + i, func_021D5440(arr[i]));
    }
    func_021D70F0(p, 0x44);
    func_021D7540(6727);
}




/*
 * The Rec build loads q[6] and q[0] first (ldrb, ldrh) only when both are
 * read into their own locals (c6 before a0), assigned after the second
 * func_021D5440 call; reading them straight into the fields interleaves
 * loads and stores.
 */
void func_021C1828(u8 *p, u8 b, u8 *x, u8 *c, u8 *q, u16 w)
{
    struct Rec r;
    u8 c6;
    u16 a0;
    u8 n = func_021D5440(x);
    u8 m = func_021D5440(c);
    c6 = q[6];
    a0 = ((struct Obj02778 *)q)->f0;
    r.a = a0;
    r.b = w;
    r.c = c6;
    r.d = n;
    r.e = b;
    func_021D6848(c, &r);
    func_021CD4B0(((struct Obj21078 *)p)->fC, 0x2d, m, n, b, q[6], ((struct Obj02778 *)q)->f0, w);
}




void func_021C1880(u8 *p, u8 *q, u8 *a, u8 *b, u32 s0, int s1)
{
    switch (sub_0201C1BC(((struct Obj09968 *)q)->f0)) {
    case 7:
        func_021C2CD8(p, (u16 *)q, a, a);
        break;
    case 6:
        if (s1 == 0) {
            func_021C2CD8(p, (u16 *)q, a, b);
        }
        break;
    case 4:
        if (s1 == 0) {
            func_021C232C(p, (const u16 *)q, a, b);
        }
        break;
    }
}




void func_021C18D4(u8 *p, u8 *a, u8 *q, u32 v)
{
    u32 s = func_021CC8D8(p + 0x1d74, 6802);
    func_021C1910(p, a, q, v);
    func_021CC95C((u32 *)(p + 0x1d74), s, 6802 + 3);
}




void func_021C1910(u8 *p, u8 *a, u8 *q, u32 v)
{
    func_021D74F8(6823);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, ((struct Obj13323 *)q)->f0);
    func_021D75EC(0x16, q[6]);
    func_021D75EC(0x32, v);
    func_021D70F0(p, 0x4d);
    func_021D7540(6829);
}




void func_021C195C(u8 *p, u8 *q, u32 n)
{
    if (func_021D5B40((struct QI *)q)) {
        u32 s = func_021CC8D8(p + 0x1D74, 6844);
        func_021C199C(p, q, n);
        func_021CC95C((u32 *)(p + 0x1D74), s, 6850);
    }
}



void func_021C199C(u8 *p, u8 *q, u32 n)
{
    func_021D74F8(0x1acf);
    func_021D75EC(2, func_021D5440(q));
    func_021D75EC(0x2e, n);
    func_021D70F0(p, 0x91);
    func_021D7540(0x1acf + 4);
}



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
