/*
 * file:     tr_ai_p14.c
 * unit:     yes
 * function: func_02189620, func_02189630, func_02189640, func_02189668, func_02189694, func_021896E0, func_02189718, func_02189758, func_0218979C, func_021897CC, func_02189800, func_0218989C, func_02189978, func_021899C4, func_021899DC, func_02189A2C, func_02189A44, func_02189A6C, func_02189A9C
 * address:  0x02189620
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D57FC  0x021D57FC  thumb  ov093
 *   func_021E8CFC  0x021E8CFC  thumb  ov093
 *   func_021E8D04  0x021E8D04  thumb  ov093
 *   func_0218A220  0x0218A220  thumb  ov096
 *   func_020113B0  0x020113B0  thumb
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021EF948  0x021EF948  thumb  ov093
 *   func_021C82D0  0x021C82D0  thumb  ov093
 *   func_0218A308  0x0218A308  thumb  ov096
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021B99B8  0x021B99B8  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5C44  0x021D5C44  thumb  ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D554C 0x021D554C thumb ov093
 *   func_0218A3F4  0x0218A3F4  thumb  ov096
 *   func_021D5584 0x021D5584 thumb ov093
 *   func_021D5478  0x021D5478  thumb  ov093
 *   func_0218A378 0x0218A378 thumb ov096
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_021C81D0  0x021C81D0  thumb  ov093
 *   func_021D5BA4  0x021D5BA4  thumb  ov093
 */
#include "../../matched/include/Obj21966.h"
#include "../../matched/include/Obj21967.h"
#include "../../matched/include/Obj21968.h"
#include "../../matched/include/Obj10185.h"
#include "../../matched/include/Obj13664.h"
#include "../../matched/include/Obj13665.h"
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj21969.h"
#include "../../matched/include/Obj21970.h"
#include "../../matched/include/Obj21971.h"
#include "../../matched/include/Obj10186.h"
#include "../../matched/include/Obj07925.h"
#include "../../matched/include/Obj07926.h"
#include "../../matched/include/Obj10187.h"
#include "../../matched/include/Obj07927.h"
#include "../../matched/include/Obj21972.h"
#include "../../matched/include/Obj10188.h"
#include "../../matched/include/Obj10189.h"
#include "../../matched/include/Obj10190.h"
#include "../../matched/include/Obj13666.h"

struct Cursor;
struct Unk021D62A8;
struct Cur;
struct UtilWork;
struct QI;
struct Q1;
struct Rat;
struct QG;
struct Work;
struct QL;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern u32 func_0201134C(struct Cursor *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern u16 func_021D57FC(void *);
extern u8 func_021E8CFC(int);
extern int func_021E8D04(int x);
extern int func_0218A220(u8 *p, int k, int slot);
extern void func_020113B0(struct Cur *c, u32 v);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern u16 func_021D5B40(struct QI *p);
extern int func_021EF948(int);
extern int func_021C82D0(int unused, unsigned int v, int k);
extern u8 *func_0218A308(void *, u32);
extern u8 func_021B8DE4(char *p, int i);
extern char *func_021B9AF8(char *p, int i);
extern int func_021B99B8(void *pp, unsigned int b);
extern u8 func_021B9B94(struct Q1 *p);
extern int func_021D5B68(void *);
extern int func_021D5C44(struct Rat *p);
extern u8 func_021D5448(struct QG *p);
extern u8 func_021D554C(u8 *p, u8 i);
extern int func_0218A3F4(int a, int b, int c);
extern u8 func_021D5584(struct UtilWork *p, u32 i);
extern u8 func_021D5478(struct Work *p);
extern int func_0218A378(int, int, int);
extern u16 func_021D67A8(struct QL *p);
extern u16 func_021C81D0(u8 *p, u8 *a, u32 y);
extern unsigned short func_021D5BA4(int *p);
int func_02189620(u8 *a, u8 *b);
int func_02189630(u8 *a, u8 *b);
int func_02189640(struct Cursor *a, int b, int c);
int func_02189668(struct Cursor *a, int b);
int func_02189694(struct Cursor *a, int b);
int func_021896E0(struct Cursor *a, int b);
int func_02189718(struct Cursor *a, int b);
int func_02189758(struct Cursor *a, int b);
int func_0218979C(struct Cursor *a, int b);
int func_021897CC(struct Cursor *a, int b);
int func_02189800(struct Cursor *a, int b);
int func_0218989C(struct Cursor *a, int b);
int func_02189978(struct Cursor *a, int b);
int func_021899C4(u8 *a, u8 *b);
int func_021899DC(struct Cursor *a, int b);
int func_02189A2C(u8 *a, u8 *b);
int func_02189A44(int a, int b);
int func_02189A6C(struct Cursor *a, int b);
int func_02189A9C(struct Cursor *a, int b);

int func_02189620(u8 *a, u8 *b)
{
    func_02189640((struct Cursor *)a, (int)b, 2); return ((struct Obj21966 *)b)->fC4;
}

int func_02189630(u8 *a, u8 *b)
{
    func_02189640((struct Cursor *)a, (int)b, 3); return ((struct Obj21967 *)b)->fC4;
}


int func_02189640(struct Cursor *a, int b, int c) {
    int r;
    int t;
    r = func_0201134C(a);
    t = func_021D62C4((struct Unk021D62A8 *)(*(u8 * *)&((struct Obj21968 *)b)->fC0), 0xb);
    return func_0218A0F4((u8 *)a, c, t, 1, r);
}


int func_02189668(struct Cursor *a, int b) {
    int r;
    r = func_0201134C(a);
    func_0218A0F4((u8 *)a, 2, ((u8 *)b)[0x94] & 1, ((u8 *)b)[0x95] & 1, r);
    return ((struct Obj10185 *)b)->fC4;
}


int func_02189694(struct Cursor *a, int b) {
    int r;
    u8 k;
    int t;
    int p;
    u8 s;
    r = func_0201134C(a);
    k = func_0201134C(a);
    s = func_0218A160((u8 *)b, r);
    p = func_021D57FC(func_0218A2FC((u8 *)b, s));
    if (k == func_021E8CFC(p) || k == func_021E8D04(p)) {
        t = 1;
    } else {
        t = 0;
    }
    ((struct Obj13664 *)b)->f38 = t;
    return ((struct Obj13664 *)b)->fC4;
}


int func_021896E0(struct Cursor *a, int b) {
    int r;
    int r2;
    int t;
    r = func_0201134C(a);
    r2 = func_0201134C(a);
    t = func_0218A160((u8 *)b, r);
    t = func_0218A220((u8 *)b, r, t);
    if (t == r2) {
        t = 1;
    } else {
        t = 0;
    }
    ((struct Obj13665 *)b)->f38 = t;
    return ((struct Obj13665 *)b)->fC4;
}


int func_02189718(struct Cursor *a, int b) {
    int r7;
    int r6;
    u8 *t;
    u8 s;
    r7 = func_0201134C(a);
    r6 = func_0201134C(a);
    s = func_0218A160((u8 *)b, r7);
    t = func_0218A2FC((u8 *)b, s);
    if (func_021D5BDC((struct UtilWork *)t, 13)) {
        func_020113B0((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + r6);
    }
    return ((struct Obj21969 *)b)->fC4;
}


int func_02189758(struct Cursor *a, int b) {
    int r0;
    int r6;
    int r7;
    u8 *t;
    u8 s;
    r0 = func_0201134C(a);
    r6 = func_0201134C(a);
    r7 = func_0201134C(a);
    s = func_0218A160((u8 *)b, r0);
    t = func_0218A2FC((u8 *)b, s);
    if (r6 == func_021D5B40((struct QI *)t)) {
        func_020113B0((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + r7);
    }
    return ((struct Obj21970 *)b)->fC4;
}


int func_0218979C(struct Cursor *a, int b) {
    int r;
    int r2;
    int t;
    r = func_0201134C(a);
    r2 = func_0201134C(a);
    t = func_021EF948(r);
    func_0218A0F4((u8 *)a, 2, t, 1, r2);
    return ((struct Obj21971 *)b)->fC4;
}


int func_021897CC(struct Cursor *a, int b) {
    int r6;
    int r4;
    int t;
    r6 = func_0201134C(a);
    r4 = func_0201134C(a);
    t = func_0218A160((u8 *)b, r6);
    t = func_021C82D0(((struct Obj10186 *)b)->fB4, t, r4);
    ((struct Obj10186 *)b)->f38 = t;
    return ((struct Obj10186 *)b)->fC4;
}


int func_02189800(struct Cursor *a, int b) {
    int r4;
    int x;
    u8 y;
    int r5;
    int t;
    r4 = func_0201134C(a);
    x = func_0201134C(a);
    y = func_0218A160((u8 *)b, r4);
    r5 = func_021B8DE4((char *)(((struct Obj07925 *)b)->fB0), y);
    r4 = (int)func_021B9AF8(*(char * *)&((struct Obj07925 *)b)->fB8, r5);
    r5 = func_021B99B8((void *)(((struct Obj07925 *)b)->fB0), r5);
    for (; r5 < func_021B9B94((struct Q1 *)r4); r5++) {
        if (func_021D5B68(func_0218A308((void *)r4, (u8)r5)) == 0) {
            t = func_021D5C44((struct Rat *)func_0218A2FC((u8 *)b, y));
            if (func_0218A0F4((u8 *)a, 0, t, 100, x) != 0) {
                break;
            }
        }
    }
    return ((struct Obj07925 *)b)->fC4;
}

/*
 * Caller-visible return/second arguments override tail-forwarder declarations.
 */
int func_0218989C(struct Cursor *a, int b)
{
    int x, z, n;
    char *p;
    int i, j;
    u8 y;
    x = func_0201134C(a);
    z = func_0201134C(a);
    y = func_0218A160((u8 *)b, x);
    n = func_021B8DE4((char *)(((struct Obj07926 *)b)->fB0), y);
    p = func_021B9AF8(*(char * *)&((struct Obj07926 *)b)->fB8, n);
    i = func_021B99B8((void *)(((struct Obj07926 *)b)->fB0), n);
    for (; i < func_021B9B94((struct Q1 *)p); i++) {
        if (func_021D5B68(func_0218A308(p, (u8)i)) == 0) {
            for (j = 0; j < func_021D5448((struct QG *)func_0218A2FC((u8 *)b, y)); j++) {
                if (func_0218A0F4((u8 *)a, 3, func_021D554C(func_0218A2FC((u8 *)b, y), j), 0, z) != 0)
                    break;
            }
            if (j != func_021D5448((struct QG *)func_0218A2FC((u8 *)b, y)))
                break;
        }
    }
    return ((struct Obj07926 *)b)->fC4;
}


int func_02189978(struct Cursor *a, int b) {
    int r;
    u8 t;
    int s;
    r = func_0201134C(a);
    t = func_0218A160((u8 *)b, r);
    ((struct Obj10187 *)b)->f38 = 0;
    if (func_021D62C4((struct Unk021D62A8 *)func_0218A2FC((u8 *)b, t), 0x13) == 0) {
        s = func_021D5B40((struct QI *)func_0218A2FC((u8 *)b, t));
        ((struct Obj10187 *)b)->f38 = func_0218A3F4(b, (u16)s, 10);
    }
    return ((struct Obj10187 *)b)->fC4;
}

int func_021899C4(u8 *a, u8 *b)
{
    ((struct Obj07927 *)b)->f38 = func_021D5584(((struct Obj07927 *)b)->fBC, b[1]); return ((struct Obj07927 *)b)->fC4;
}


int func_021899DC(struct Cursor *a, int b) {
    int r4;
    int r7;
    u8 t;
    u8 *s;
    r4 = func_0201134C(a);
    r7 = func_0201134C(a);
    t = func_0218A160((u8 *)b, r4);
    s = func_0218A2FC((u8 *)b, t);
    if (func_021D5478((struct Work *)s) >= func_021D5448((struct QG *)s) && func_021D5448((struct QG *)s) > 1) {
        func_020113B0((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + r7);
    }
    return ((struct Obj21972 *)b)->fC4;
}

int func_02189A2C(u8 *a, u8 *b)
{
    ((struct Obj10188 *)b)->f38 = func_0218A378((int)b, ((struct Obj10188 *)b)->f2, 2); return ((struct Obj10188 *)b)->fC4;
}


int func_02189A44(int a, int b) {
    int t;
    t = func_021D67A8((struct QL *)(*(u8 * *)&((struct Obj10189 *)b)->fC0));
    if (t != 0) {
        t = func_0218A378(b, t, 2);
    } else {
        t = 0;
    }
    ((struct Obj10189 *)b)->f38 = t;
    return ((struct Obj10189 *)b)->fC4;
}


int func_02189A6C(struct Cursor *a, int b) {
    int t;
    u8 s;
    t = func_0201134C(a);
    s = func_0218A160((u8 *)b, t);
    t = func_021C81D0((u8 *)(((struct Obj10190 *)b)->fB4), func_0218A2FC((u8 *)b, s), 1);
    ((struct Obj10190 *)b)->f38 = t;
    return ((struct Obj10190 *)b)->fC4;
}


/*
 *           unlabelled Thumb leaf in ov093 (it sits in a .word run in the
 *           ov093 listing), so neither `label` nor `sole-ref/code` can attest
 *           it, and the call at 0x02189AB4 is its only referrer image-wide.
 */
int func_02189A9C(struct Cursor *a, int b) {
    int t;
    u8 s;
    t = func_0201134C(a);
    s = func_0218A160((u8 *)b, t);
    t = func_021D5BA4((int *)func_0218A2FC((u8 *)b, s));
    ((struct Obj13666 *)b)->f38 = t;
    return ((struct Obj13666 *)b)->fC4;
}
