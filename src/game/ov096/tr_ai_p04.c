/*
 * file:     tr_ai_p04.c
 * unit:     yes
 * function: func_021887E4, func_021887F4, func_0218883C, func_0218884C, func_0218885C, func_0218889C, func_021888AC, func_021888BC, func_02188904, func_02188914, func_02188924, func_02188980, func_02188990, func_021889A0, func_021889E8, func_021889F8, func_02188A08, func_02188A54, func_02188A64
 * address:  0x021887E4
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
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   func_021D5C44  0x021D5C44  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D6314  0x021D6314  thumb  ov093
 *   func_021E8A78  0x021E8A78  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021C82D0  0x021C82D0  thumb  ov093
 *   func_02188AB4 0x02188AB4 thumb ov096
 */
#include "../../matched/include/Obj21923.h"
#include "../../matched/include/Obj21924.h"
#include "../../matched/include/Obj21925.h"
#include "../../matched/include/Obj21926.h"
#include "../../matched/include/Obj21927.h"
#include "../../matched/include/Obj21928.h"
#include "../../matched/include/Obj21929.h"
#include "../../matched/include/Obj21930.h"
#include "../../matched/include/Obj21931.h"
#include "../../matched/include/Obj21932.h"
#include "../../matched/include/Obj21933.h"
#include "../../matched/include/Obj21934.h"
#include "../../matched/include/Obj21935.h"
#include "../../matched/include/Obj21936.h"

struct Cursor;
struct Rat;
struct Unk021D62A8;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Slot { u32 a : 3; u32 rest : 29; } Slot;

extern u32 func_0201134C(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);
extern int func_021D5C44(struct Rat *p);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern Slot func_021D6314(void *, int);
extern int func_021E8A78(Slot);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern int func_021C82D0(int unused, unsigned int v, int k);
extern int func_02188AB4(struct Cursor *a, unsigned char *b, int c);
int func_021887E4(struct Cursor *a, int b);
int func_021887F4(struct Cursor *a, int b, int c);
int func_0218883C(struct Cursor *a, int b);
int func_0218884C(struct Cursor *a, int b);
int func_0218885C(struct Cursor *a, int b, int c);
int func_0218889C(struct Cursor *a, int b);
int func_021888AC(struct Cursor *a, int b);
int func_021888BC(struct Cursor *a, int b, int c);
int func_02188904(struct Cursor *a, int b);
int func_02188914(struct Cursor *a, int b);
int func_02188924(struct Cursor *a, int b, int c);
int func_02188980(struct Cursor *a, int b);
int func_02188990(struct Cursor *a, int b);
int func_021889A0(struct Cursor *a, int b, int c);
int func_021889E8(struct Cursor *a, int b);
int func_021889F8(struct Cursor *a, int b);
int func_02188A08(struct Cursor *a, int b, int c);
int func_02188A54(int a, int b);
int func_02188A64(int a, int b);

int func_021887E4(struct Cursor *a, int b)
{
    func_021887F4(a, b, 3);
    return ((struct Obj21923 *)((unsigned int)b))->fC4;
}


int func_021887F4(struct Cursor *a, int b, int c)
{
    int t1;
    int t2;
    int t3;
    int r;
    u8 s;

    t1 = func_0201134C(a);
    t2 = func_0201134C(a);
    t3 = func_0201134C(a);
    s = func_0218A160((u8 *)b, t1);
    r = func_021D5C44((struct Rat *)func_0218A2FC((u8 *)b, s));
    return func_0218A0F4((u8 *)a, c, r >> 12, t2, t3);
}

int func_0218883C(struct Cursor *a, int b)
{
    func_0218885C(a, b, 3);
    return ((struct Obj21924 *)((unsigned int)b))->fC4;
}

int func_0218884C(struct Cursor *a, int b)
{
    func_0218885C(a, b, 2);
    return ((struct Obj21925 *)((unsigned int)b))->fC4;
}


int func_0218885C(struct Cursor *a, int b, int c)
{
    int t1;
    int t3;
    int r;
    u8 s;

    t1 = func_0201134C(a);
    t3 = func_0201134C(a);
    s = func_0218A160((u8 *)b, t1);
    r = func_021D62A8((struct Unk021D62A8 *)func_0218A2FC((u8 *)b, s));
    return func_0218A0F4((u8 *)a, c, r, 0, t3);
}

int func_0218889C(struct Cursor *a, int b)
{
    func_021888BC(a, b, 2);
    return ((struct Obj21926 *)((unsigned int)b))->fC4;
}

int func_021888AC(struct Cursor *a, int b)
{
    func_021888BC(a, b, 3);
    return ((struct Obj21927 *)((unsigned int)b))->fC4;
}


int func_021888BC(struct Cursor *a, int b, int c)
{
    int t1;
    int t2;
    int t3;
    int r;
    u8 s;

    t1 = func_0201134C(a);
    t2 = func_0201134C(a);
    t3 = func_0201134C(a);
    s = func_0218A160((u8 *)b, t1);
    r = func_021D62C4((struct Unk021D62A8 *)func_0218A2FC((u8 *)b, s), t2);
    return func_0218A0F4((u8 *)a, c, r, 1, t3);
}

int func_02188904(struct Cursor *a, int b)
{
    func_02188924(a, b, 2);
    return ((struct Obj21928 *)b)->fC4;
}

int func_02188914(struct Cursor *a, int b)
{
    func_02188924(a, b, 3);
    return ((struct Obj21929 *)b)->fC4;
}


int func_02188924(struct Cursor *a, int b, int c)
{
    int t1;
    int t3;
    u8 *r;
    u8 k;
    int x;
    Slot s;

    t1 = func_0201134C(a);
    t3 = func_0201134C(a);
    k = func_0218A160((u8 *)b, t1);
    r = func_0218A2FC((u8 *)b, k);
    x = 0;
    if (func_021D62C4((struct Unk021D62A8 *)r, 5) != 0) {
        s = func_021D6314(r, 5);
        if (func_021E8A78(s) != 0)
            x = 1;
    }
    return func_0218A0F4((u8 *)a, c, x, 1, t3);
}

int func_02188980(struct Cursor *a, int b)
{
    func_021889A0(a, b, 2);
    return ((struct Obj21930 *)b)->fC4;
}

int func_02188990(struct Cursor *a, int b)
{
    func_021889A0(a, b, 3);
    return ((struct Obj21931 *)b)->fC4;
}


int func_021889A0(struct Cursor *a, int b, int c)
{
    int t1;
    int t2;
    int t3;
    int r;
    u8 s;

    t1 = func_0201134C(a);
    t2 = func_0201134C(a);
    t3 = func_0201134C(a);
    s = func_0218A160((u8 *)b, t1);
    r = func_021D5BDC((struct UtilWork *)func_0218A2FC((u8 *)b, s), t2);
    return func_0218A0F4((u8 *)a, c, r, 1, t3);
}

int func_021889E8(struct Cursor *a, int b)
{
    func_02188A08(a, b, 2);
    return ((struct Obj21932 *)b)->fC4;
}

int func_021889F8(struct Cursor *a, int b)
{
    func_02188A08(a, b, 3);
    return ((struct Obj21933 *)b)->fC4;
}


int func_02188A08(struct Cursor *a, int b, int c)
{
    int t0;
    int t1;
    int t2;
    int r;

    t0 = func_0201134C(a);
    t1 = func_0201134C(a);
    t2 = func_0201134C(a);
    r = func_0218A160((u8 *)b, t0);
    r = func_021C82D0(((struct Obj21934 *)b)->fB4, r, t1);
    return func_0218A0F4((u8 *)a, c, r != 0, 1, t2);
}

int func_02188A54(int a, int b)
{
    func_02188AB4((struct Cursor *)a, (unsigned char *)b, 0);
    return ((struct Obj21935 *)b)->fC4;
}

int func_02188A64(int a, int b)
{
    func_02188AB4((struct Cursor *)a, (unsigned char *)b, 1);
    return ((struct Obj21936 *)b)->fC4;
}
