/*
 * file:     fldmmdl_blact_p30.c
 * unit:     yes
 * function: func_0219EB18, func_0219EB4C, func_0219EB90, func_0219EBA0
 * address:  0x0219EB18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0219E968  0x0219E968  thumb  ov021
 *   func_0219EA10  0x0219EA10  thumb  ov021
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb  ov010
 *   d_021D84AC     0x021D84AC  data
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0219EA24  0x0219EA24  thumb  ov021
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0219EA78  0x0219EA78  thumb  ov021
 *   func_0219EA94  0x0219EA94  thumb  ov021
 *   func_0219E2F4  0x0219E2F4  thumb  ov021
 */
#include "../../matched/include/Obj12689.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef struct {
    u8  pad[0xc];
    s16 cnt;
    u16 val;
} E_0219EB4C;

typedef signed char    s8;

typedef struct {
    u8 pad[0xc];
    u8 lo : 4;
    u8 hi : 4;
    u8 z;
    u8 c;
    u8 d;
} E_0219EBA0;

typedef struct {
    u16 a;
    u16 pad;
    s16 c;
    u16 d;
} S;

extern void *func_0219E968(u32 a, u32 size);
extern int func_0219EA10(u32 *a, int b);
extern void func_0216D674(void *p, u16 v);
extern void func_0216DA50(u8 *p);
extern void *func_0216D69C(void *p);
extern u32 func_0219EA24(u32 a, u32 b);
extern void func_0216D5E0(int a0, int a1);
extern int func_0219EA78();
extern u32 func_0219EA94(u32 a, u32 *b);
extern void func_0219E2F4(void *o, void *out);
void func_0219EB18(u32 a, u16 b);
int func_0219EB4C(u32 o);
int func_0219EB90(u32 *a);
void func_0219EBA0(u32 o, u32 k);
extern u32 d_021D84AC[];


/*
 * Addresses are Black-image addresses.
 */
void func_0219EB18(u32 a, u16 b)
{
    u8 *q = func_0219E968(a, 16);
    ((struct Obj12689 *)q)->fC = func_0219EA10(d_021D84AC, -1);
    ((struct Obj12689 *)q)->fE = b;
    func_0216D674((void *)a, 0);
    func_0216DA50((u8 *)a);
}


int func_0219EB4C(u32 o)
{
    E_0219EB4C *e;

    e = func_0216D69C((void *)o);
    e->cnt = e->cnt - 1;
    if (e->cnt <= 0) {
        e->cnt = func_0219EA10((u32 *)d_021D84AC, -1);
        func_0216D5E0((u32)o, (u16)func_0219EA24(e->val, 9));
    }
    return func_0219EA78(e, o);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219EB90(u32 *a)
{
return func_0219EA94((u32)func_0216D69C((void *)a), a);
}


void func_0219EBA0(u32 o, u32 k)
{
    E_0219EBA0 *e;
    S s;

    e = func_0219E968(o, 0x10);
    func_0219E2F4((void *)o, &s);
    e->lo = 0;
    e->z = 0;
    e->hi = k;
    e->d = s.d;
    e->c = s.c;
    func_0216D674((void *)o, 0);
    func_0216DA50((u8 *)o);
}
