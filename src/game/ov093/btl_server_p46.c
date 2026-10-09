/*
 * file:     btl_server_p46.c
 * unit:     yes
 * function: func_021C2E4C, func_021C2E64, func_021C2F70, func_021C3008, func_021C312C, func_021C3184
 * address:  0x021C2E4C
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
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_0201C020 0x0201C020 thumb
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021C78A8 0x021C78A8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   sub_0201C0BC  0x0201C0BC  thumb
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021D5D14 0x021D5D14 thumb ov093
 *   func_021C5A4C 0x021C5A4C thumb ov093
 *   func_021D6D7C 0x021D6D7C thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021C77B0 0x021C77B0 thumb ov093
 *   func_021C5A8C 0x021C5A8C thumb ov093
 *   func_021C785C 0x021C785C thumb ov093
 *   func_021C7820 0x021C7820 thumb ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   sub_0201BD28  0x0201BD28  thumb
 *   sub_0201BF58  0x0201BF58  thumb
 *   func_021D7C70  0x021D7C70  thumb  ov093
 *   func_021C3244  0x021C3244  thumb  ov093
 *   func_021C3254  0x021C3254  thumb  ov093
 *   func_021C3264  0x021C3264  thumb  ov093
 *   func_021C25A4  0x021C25A4  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj13327.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int s32;

typedef struct { u32 x; } W_021C2E4C;

enum Kind { K0, K1, K10 = 10 };

struct Lock { u32 a:10; u32 b:9; u32 c:9; u32 d:1; u32 e:1; u32 f:1; u32 g:1; };

typedef signed char s8;

typedef signed short s16;


typedef struct { u8 pad[5]; u8 f : 1; } BF;

typedef struct { u16 v; } W_021C312C;

typedef struct { u32 x; } O;

typedef struct { u32 v; } Word;

extern u8 func_021D5440(u8 *p);
extern u8 func_0201C020(u16);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C78A8(u8 *, u8 *, u32, u32, u32);
extern u8 sub_0201C0BC(u16 id, u32 idx, s32 *out);
extern void func_021D74F8(int line);
extern void func_021D75EC(int key, u32 val);
extern void func_021D75A8(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern int func_021D5D14(s8 *p, int i, int sign);
extern void func_021C5A4C(u8 *p, u8 *a, int b, int c);
extern u32 func_021D6D7C(u8 *p);
extern void func_021CD64C(void *, u8, ...);
extern int func_021C77B0(u8 *, u8 *, u32, u32, u32, u32);
extern void func_021C5A8C(u8 *p, u8 *a, int c, int d, u16 msg, int flag);
extern void func_021C785C(u8 *, u32, u8 *, u32, u32);
extern void func_021C7820(u8 *, u8 *, u32);
extern void func_021D7630(int key, u32 val);
extern u32 sub_0201BD28(u16 id, u32 field);
extern W_021C312C sub_0201BF58(u16 id);
extern void func_021D7C70(W_021C312C, u32, Word *);
extern void func_021C3244(u32 c);
extern u32 func_021C3254(u32 c);
extern u32 func_021C3264(u32 c);
extern int func_021C25A4(u8 *p, u32 a, u32 b, u32 unused, u32 s0, O s1, u32 s2);
u32 func_021C2E4C(u8 *p);
int func_021C2E64(u8 *p, const u16 *q, u8 *a, u8 *b, int k);
void func_021C2F70(u8 *p, u16 x, u32 y, u8 *c, u8 *s0, s32 *s1, s32 *s2);
int func_021C3008(u8 *p, u8 b, u8 *a, enum Kind kind, int value, u8 f, u16 g, u32 h, int i, u32 j);
int func_021C312C(u8 *p, u8 *a, enum Kind b, u8 c, u16 e, int d);
void func_021C3184(u8 *p, const u16 *q, u32 r, u32 c);



u32 func_021C2E4C(u8 *p)
{
    if (++((struct Obj00003 *)p)->f778 == 0)
        ((struct Obj00003 *)p)->f778 = 1;
    return ((struct Obj00003 *)p)->f778;
}




/*
 * lever: enum Kind keeps the output guard in r0 and reloads it into r3 at the call.
 */
int func_021C2E64(u8 *p, const u16 *q, u8 *a, u8 *b, int k)
{
    u8 id;
    int result;
    u32 count, i;
    u32 serial;
    enum Kind kind;
    s32 value;
    int ok;
    u8 j;
    u32 lock;
    result = 0;
    id = func_021D5440(a);
    serial = func_021C2E4C(p);
    count = func_0201C020(*q);
    for (i = 0; i < count; i++) {
        ok = 0;
        func_021C2F70(p, *q, i, a, b, (s32 *)&kind, &value);
        if (kind != 0) {
            if (kind != 10) {
                ok = func_021C3008(p, id, b, kind, value, id, ok, serial, k, 1);
            } else {
                for (j = 1; j < 6; j++) {
                    if (func_021C3008(p, id, b, j, value, id, 0, serial, k, 1)) ok = 1;
                }
            }
            if (ok) {
                lock = func_021CC8D8((struct Lock *)(p + 0x1d74), 8247);
                func_021C78A8(p, b, *q, kind, value);
                func_021CC95C((u32 *)(p + 0x1d74), lock, 8249);
                result = 1;
            }
        }
    }
    return result;
}





void func_021C2F70(u8 *p, u16 x, u32 y, u8 *c, u8 *s0, s32 *s1, s32 *s2)
{
    u32 m;
    *s1 = sub_0201C0BC(x, y, s2);
    func_021D74F8(8275);
    func_021D75EC(3, func_021D5440(c));
    func_021D75EC(4, func_021D5440(s0));
    func_021D75A8(0x1F, *s1);
    func_021D75A8(0x20, *s2);
    func_021D75A8(0x35, 1);
    func_021D70F0(p, 0x59);
    *s1 = func_021D775C(0x1F);
    *s2 = func_021D775C(0x20);
    m = (u8)func_021D775C(0x35);
    if (m > 1)
        *s2 = *s2 * m;
    func_021D7540(8290);
    if (*s1 == 8)
        *s1 = 0;
}


/*
 * lever: reassigning value to the transformed result keeps it in its incoming register.
 */
int func_021C3008(u8 *p, u8 b, u8 *a, enum Kind kind, int value, u8 f, u16 g, u32 h, int i, u32 j)
{
    int result;
    u32 lock;
    value = func_021C312C(p, a, kind, f, g, value);
    if (!func_021D5D14((s8 *)a, kind, value)) {
        if (i) {
            func_021C5A4C(p, a, kind, value);
            ((struct Obj00003 *)p)->f78A |= 0x10;
        }
        return 0;
    }
    if (func_021D6D7C(a)) {
        u8 id;
        id = func_021D5440(a);
        if (b != id) {
            if (i) func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0xd2, id, 0xffff0000);
            return 0;
        }
    }
    result = 1;
    if (func_021C77B0(p, a, kind, b, value, h)) {
        func_021C5A8C(p, a, kind, value, g, j);
        lock = func_021CC8D8(p + 0x1d74, 8349);
        func_021C785C(p, b, a, kind, value);
        func_021CC95C((u32 *)(p + 0x1d74), lock, 8351);
    } else {
        if (i) {
            lock = func_021CC8D8(p + 0x1d74, 8358);
            func_021C7820(p, a, h);
            func_021CC95C((u32 *)(p + 0x1d74), lock, 8360);
        }
        result = 0;
    }
    return result;
}



/*
 * Note (final push 2026-10-05 G4L8): the script result is written back into the
 * stack parameter d (the caller func_021C3008 does value = func_021C312C(..., value)).
 * Assigning to a stack-passed parameter, instead of a fresh local r, keeps the end
 * line as its own pool word (no ldr + adds #7 fold). Both --lang c99 and c EXACT.
 */
int func_021C312C(u8 *p, u8 *a, enum Kind b, u8 c, u16 e, int d)
{
    func_021D74F8(8385);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(3, c);
    func_021D75EC(0x1F, b);
    func_021D7630(0x20, d);
    func_021D70F0(p, 0x5A);
    d = func_021D775C(0x20);
    func_021D7540(8392);
    return d;
}



/*
 * sub_0201BF58 is declared here as returning a one-halfword struct (the
 * store of r0 with no sign extension and the dead-looking second strh are
 * the struct-return temp plus its copy); its own file says s16.
 * func_021D7C70's first argument and func_021C25A4's sixth are structs
 * passed by value.
 */
void func_021C3184(u8 *p, const u16 *q, u32 r, u32 c)
{
    u32 t, s;
    O out;
    W_021C312C v;
    s = sub_0201BD28(*q, 0xB);
    v = sub_0201BF58(*q);
    func_021D7C70(v, r, (Word *)&out);
    func_021C3244(c);
    for (t = func_021C3254(c); t != 0; t = func_021C3264(c)) {
        if (func_021C2E64(p, (const u16 *)((u32)q), (u8 *)r, (u8 *)t, 1) != 0) {
            BF *f = *(BF * *)&((struct Obj13327 *)p)->f4A8;
            if (!f->f)
                f->f = 1;
        }
        if (func_021C25A4(p, r, t, *q, s, out, 1) != 0) {
            BF *f = *(BF * *)&((struct Obj13327 *)p)->f4A8;
            if (!f->f)
                f->f = 1;
        }
    }
}
