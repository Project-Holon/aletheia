/*
 * file:     btl_server_p43.c
 * unit:     yes
 * function: func_021C2204, func_021C2250, func_021C2314, func_021C232C, func_021C236C, func_021C2488
 * address:  0x021C2204
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
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021D5B44  0x021D5B44  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021C7AD0  0x021C7AD0  thumb  ov093
 *   func_021C7B0C  0x021C7B0C  thumb  ov093
 *   func_021C60EC  0x021C60EC  thumb  ov093
 *   func_021C6134  0x021C6134  thumb  ov093
 *   func_021DCF24  0x021DCF24  thumb  ov093
 *   func_021DCF5C  0x021DCF5C  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021D6730  0x021D6730  thumb  ov093
 *   func_021C5BE4 0x021C5BE4 thumb ov093
 *   func_021C4F64 0x021C4F64 thumb ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021C25A4  0x021C25A4  thumb  ov093
 *   sub_0201BD28 0x0201BD28 thumb
 *   sub_0201BF58 0x0201BF58 thumb
 *   func_021D7C70 0x021D7C70 thumb ov093
 *   func_021D75A8 0x021D75A8 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021B911C 0x021B911C thumb ov093
 *   func_021C2564 0x021C2564 thumb ov093
 *   func_021C2574 0x021C2574 thumb ov093
 *   func_021C2584 0x021C2584 thumb ov093
 *   func_021C2594 0x021C2594 thumb ov093
 *   func_021C5718 0x021C5718 thumb ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj21082.h"
#include "../../matched/include/Obj21083.h"

struct QI;
struct QK;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u16 v; } W;

typedef struct { u32 v; } Word;

typedef struct { u8 pad[5]; u8 f:1; } BF;

typedef struct { u8 pad[0x78a]; u8 low:4; u8 f:1; } State;

extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern u16 func_021D5B40(struct QI *p);
extern void func_021D5B44(struct QI *p, u16 v);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C7AD0(u8 *p, u8 *a, u32 b);
extern void func_021C7B0C(u8 *p, u8 *a);
extern void func_021C60EC(u8 *p, u8 *a, u32 n);
extern void func_021C6134(u8 *p, u8 *a, unsigned int n);
extern void func_021DCF24(u8 *a);
extern void *func_021DCF5C(void *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021D6730(struct QK *p, u16 v);
extern void func_021C5BE4(u8 *, u8 *, int);
extern int func_021C4F64(u8 *, u8 *);
extern int func_021D5B68(void *p);
extern int func_021C25A4(u8 *p, u8 *a, u8 *b, u32 unused, u32 s0, Word s1, u32 s2);
extern u32 sub_0201BD28(u16, u32);
extern W sub_0201BF58(u16);
extern void func_021D7C70(W, u32, Word *);
extern void func_021D75A8(int, u32);
extern u32 func_021D78AC(u32);
extern int func_021B911C(void *, int);
extern u32 func_021C2564(u32);
extern void func_021C2574(u32);
extern u8 *func_021C2584(u32);
extern u8 *func_021C2594(u32);
extern void func_021C5718(u8 *, u8 *, u32);
int func_021C2204(u8 *p, u8 *a, u16 c);
void func_021C2250(u8 *p, u8 *a, u16 b, u32 c);
int func_021C2314(u8 *p, u8 *a);
void func_021C232C(u8 *p, const u16 *a, u8 *b, u8 *c);
u32 func_021C236C(u8 *p, u16 id, u8 *a, u8 *b, Word *dest);
void func_021C2488(u8 *p, u16 id, u8 *a, u32 c);





int func_021C2204(u8 *p, u8 *a, u16 c)
{
    int r;
    func_021D74F8(7449);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x2d, c);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x90);
    r = func_021D775C(0x41);
    func_021D7540(7455);
    return r;
}






void func_021C2250(u8 *p, u8 *a, u16 b, u32 c)
{
    u32 s;
    u16 t;
    int name;
    name = func_021D5440(a);
    t = (u16)(int)func_021D5B40((struct QI *)a);
    s = func_021CC8D8(p + 0x1D74, 7469);
    func_021C7AD0(p, a, b);
    func_021CC95C((u32 *)(p + 0x1D74), s, 7471);
    if (b == 0)
        func_021C60EC(p, a, 15);
    func_021DCF24(a);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x1E, name, b);
    func_021D5B44((struct QI *)a, b);
    if (b != 0)
        func_021DCF5C(a);
    s = func_021CC8D8(p + 0x1D74, 7485);
    func_021C7B0C(p, a);
    func_021CC95C((u32 *)(p + 0x1D74), s, 7487);
    if (c != 0) {
        func_021D6730((struct QK *)a, t);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x17, name, t);
        func_021C6134(p, a, 8);
    }
}





/*
 * extent: two zero alignment bytes follow the return at 0x021C232A.
 * interface: func_021C5BE4 reads r0/r1/r2 and forwards r2 unchanged;
 * func_021C4F64 has two arguments in its existing DIFF note.
 */
int func_021C2314(u8 *p, u8 *a)
{
    func_021C5BE4(p, a, 0);
    return func_021C4F64(p, a);
}




void func_021C232C(u8 *p, const u16 *a, u8 *b, u8 *c)
{
    Word loc;
    u32 r;
    r = func_021C236C(p, *a, b, c, &loc);
    if (r != 0 && func_021D5B68(c) == 0)
        func_021C25A4(p, b, c, *a, r, loc, 0);
}


static inline int chance(u32 n)
{
    return func_021D78AC(100) < n;
}


u32 func_021C236C(u8 *p, u16 id, u8 *a, u8 *b, Word *dest)
{
    u32 s;
    W w;
    Word out;
    u8 rate;
    u32 result;
    u8 changedRate;
    u8 veto;
    s = sub_0201BD28(id, 11);
    w = sub_0201BF58(id);
    rate = sub_0201BD28(id, 12);
    func_021D7C70(w, (u32)a, &out);
    func_021D74F8(0x1d7c);
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x12, id);
    func_021D75A8(0x1d, s);
    func_021D7630(0x41, 0);
    func_021D7630(0x1e, out.v);
    func_021D75A8(0x26, rate);
    func_021D70F0(p, 0x64);
    result = func_021D775C(0x1d);
    rate = func_021D775C(0x26);
    veto = func_021D775C(0x41);
    if (result == 0xffff) result = 0;
    out.v = func_021D775C(0x1e);
    func_021D7540(0x1d8f);
    if (!veto && result) {
        if (chance(rate)) {
            *dest = out;
            return result;
        }
        if (func_021B911C(((struct Obj21082 *)p)->f4, 0)) {
            *dest = out;
            return result;
        }
    }
    return 0;
}

void func_021C2488(u8 *p, u16 id, u8 *a, u32 c)
{
    u32 s;
    W w;
    Word out;
    u8 *t;
    int got;
    s = sub_0201BD28(id, 11);
    w = sub_0201BF58(id);
    got = 0;
    if (func_021C2564(c)) {
        func_021C2574(c);
        for (t = func_021C2584(c); t; t = func_021C2594(c)) {
            func_021D7C70(w, (u32)a, &out);
            if (func_021C25A4(p, a, t, id, s, out, 1)) {
                BF *flag = *(BF * *)&((struct Obj21083 *)p)->f4A8;
                if (!flag->f) flag->f = 1;
                got = 1;
            }
        }
        if (!got && !((State *)p)->f) func_021C5718(p, a, id);
    } else {
        func_021C5718(p, a, id);
    }
}
