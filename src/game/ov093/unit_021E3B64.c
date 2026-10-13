/*
 * file:     unit_021E3B64.c
 * unit:     yes
 * function: func_021E3B64, func_021E3BBC, func_021E3BF4, func_021E3C5C, func_021E3CB0, func_021E3D38, func_021E3D98, func_021E3DCC, func_021E3E00, func_021E3E30, func_021E3E64, func_021E3E84, func_021E3F08, func_021E3F38, func_021E3F44, func_021E3FB4, func_021E3FC0, func_021E4080
 * address:  0x021E3B64
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
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetCounter  0x021D69AC  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   func_021E8624  0x021E8624  thumb  ov093
 *   d_021F2856     0x021F2856  data   a1
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F2FF8     0x021F2FF8  data   a4
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Value  0x021E89D4  thumb  ov093
 *   func_021C83DC  0x021C83DC  thumb  ov093
 *   BTL_POKEPARAM_GetHitCount  0x021D6920  thumb  ov093
 *   BTL_POKEPARAM_GetHitRecord  0x021D6940  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_POKEPARAM_GetConsumedItem  0x021D6740  thumb  ov093
 *   d_021F27C4     0x021F27C4  data   a4
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_POKEPARAM_GetSickContRaw  0x021D6314  thumb  ov093
 *   BTLV_CORE_IsSlotKind1Index15  0x021E8A78  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Index15  0x021E8A58  thumb  ov093
 *   BTL_CALC_MakeDefaultSickCont  0x021D7D18  thumb  ov093
 *   d_021F27BC     0x021F27BC  data   a4
 *   data_021F27B4 0x021F27B4 data a4
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   d_021F27CC     0x021F27CC  data   ov093  a4
 */
#include "../../matched/include/Obj13514.h"
#include "../../matched/include/Obj06270.h"
#include "../../matched/include/Obj13515.h"
#include "../../matched/include/Obj07830.h"
#include "../../matched/include/Obj10088.h"
#include "../../matched/include/Obj03704.h"
#include "../../matched/include/Obj02790.h"

struct Node;
struct S;
struct QQ;
struct QI;
struct QK;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct Word { unsigned int v; } Word;

extern int BTL_EVENT_GetVar(int);
extern void *func_021C7CF4(int *p, int i);
extern unsigned char BTL_POKEPARAM_GetCounter(unsigned char *base, int idx);
extern u32 BTL_CALC_Random(u32 range);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int func_021E8624(int a, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void BTL_EVENT_RemoveFactor(struct Node *n);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, unsigned int a);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern Word BTLV_CORE_MakeSlotKind1Value(unsigned int a);
extern void func_021C83DC(char *p, int x);
extern int BTL_POKEPARAM_GetHitCount(u8 *p, u32 n);
extern int BTL_POKEPARAM_GetHitRecord(const u8 *p, int i, u32 j, u16 *out);
extern int func_021C7D00(u8 *p, int b);
extern int func_021C8010(u8 *p, unsigned int v);
extern u8 func_021C7F68(int *p, int b, u8 *out);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern u16 BTL_POKEPARAM_GetConsumedItem(struct QK *p);
extern Word BTL_POKEPARAM_GetMajorStatusIndex(void *q);
extern u32 BTL_POKEPARAM_GetSickContRaw(u8 *p, int i);
extern int BTLV_CORE_IsSlotKind1Index15(int s);
extern Word BTLV_CORE_MakeSlotKind1Index15(void);
extern int BTL_CALC_MakeDefaultSickCont(int k);
extern int func_021D59B4(u8 *p, int k);
void func_021E3B64(int u, void *a, int c);
void func_021E3BBC(void *u, int a, int b);
void func_021E3BF4(int u, void *a, int c);
void func_021E3C5C(void *a, int b, int c);
int *func_021E3CA4(int *p);
void func_021E3CB0(int u, void *a, int c, int *w);
void func_021E3D38(int u, int v, int c, int *w);
void func_021E3D98(int u, int a, int b, int *p);
void func_021E3DCC(int u, void *a, int b, int *p);
void func_021E3E00(int u, int a, int b, int *p);
void func_021E3E30(int u, void *a, int b, int *p);
void func_021E3E64(int u, void *a, int b, int *p);
int func_021E3E84(int u, void *a, int c, int *w);
void func_021E3F08(void *a, int b, int *p);
int *func_021E3F38(int *p);
void func_021E3F44(int u, void *a, int c);
int *func_021E3FB4(int *p);
void func_021E3FC0(int u, void *a, int c);
int *func_021E4074(int *p);
void func_021E4080(void *a, void *b, int c);
u32 *func_021E4148(u32 *p);
extern const u8 d_021F2856[];
extern int d_021F2FF8[];
extern int d_021F27C4[];
extern int d_021F27BC[];
extern u32 data_021F27B4[];
extern int d_021F27CC[];





void func_021E3B64(int u, void *a, int c)
{
    unsigned x;

    if (c == BTL_EVENT_GetVar(2)) {
        x = BTL_POKEPARAM_GetCounter(func_021C7CF4(a, c), 3);
        if (x != 0) {
            if (x >= 10)
                x = 9;
            if (BTL_CALC_Random(d_021F2856[x]) != 0) {
                BTL_EVENT_OverwriteVar(0x22, 0x1a);
                return;
            }
        }
        if (func_021E8624((int)a, c) != 0)
            BTL_EVENT_OverwriteVar(0x22, 0x1a);
    }
}





void func_021E3BBC(void *u, int a, int b)
{
    u8 *s;

    if (b == BTL_EVENT_GetVar(2)) {
        s = func_021C88A4((char *)a, 0x26, b);
        s[4] = b;
        s[5] = 3;
        s[6] = 0;
        func_021C88C8((void *)a, s);
        BTL_EVENT_RemoveFactor(u);
    }
}





void func_021E3BF4(int u, void *a, int c)
{
    char *p;

    if (c == BTL_EVENT_GetVar(3)) {
        func_021C7CF4(a, c);
        p = func_021C88A4(a, 0x15, c);
        p[8] = c;
        ((struct Obj13514 *)p)->f4 = 7;
        func_021C88C8(a, p);
        func_021E3C5C(a, c, 0);
        p = func_021C88A4(a, 4, c);
        func_021C8838(p + 4, 2, 0x205);
        func_021C8860((struct S *)(p + 4), c);
        func_021C88C8(a, p);
    }
}





void func_021E3C5C(void *a, int b, int c)
{
    void *q;
    u8 *p;

    q = func_021C7CF4(a, b);
    p = func_021C88A4(a, 0x26, b);
    p[6] = BTL_POKEPARAM_GetCounter(q, 3) + 1;
    p[4] = b;
    p[5] = 3;
    ((struct Obj06270 *)p)->f0 = (((struct Obj06270 *)p)->f0 & 0xfeffffff) | ((c & 1) << 24);
    func_021C88C8(a, p);
}





int *func_021E3CA4(int *p)
{
    *p = 7;
    return d_021F2FF8;
}





void func_021E3CB0(int u, void *a, int c, int *w)
{
    char *p;

    if (c == BTL_EVENT_GetVar(2)) {
        switch (w[0]) {
        case 0:
            p = func_021C88A4(a, 0xc, c);
            ((struct Obj13515 *)p)->f4 = 0x19;
            *(Word *)(p + 8) = BTLV_CORE_MakeSlotKind1Value(BTL_EVENT_GetFactorKey((void *)u));
            p[0xf] = c;
            func_021C88C8(a, p);
            BTL_EVENT_OverwriteVar(0x3e, 2);
            w[6] = 1;
            w[0] = 1;
            w[1] = 0;
            break;
        case 1:
            BTL_EVENT_OverwriteVar(0x3e, 2);
            w[0] = 2;
            break;
        case 2:
        default:
            func_021C83DC(a, 1);
            func_021E3F08(a, c, w);
            break;
        }
    }
}





void func_021E3D38(int u, int v, int c, int *w)
{
    int p;

    if (c == BTL_EVENT_GetVar(2)) {
        p = BTL_EVENT_GetVar(0x3f);
        switch (w[0]) {
        case 1:
            func_021C8838((void *)p, 2, 0x2e9);
            func_021C8860((struct S *)p, c);
            BTL_EVENT_OverwriteVar(0x51, 1);
            break;
        case 2:
            func_021C8838((void *)p, 2, 0x2ec);
            func_021C8860((struct S *)p, c);
            BTL_EVENT_OverwriteVar(0x51, 1);
            break;
        }
    }
}





void func_021E3D98(int u, int a, int b, int *p)
{
    if (b == BTL_EVENT_GetVar(2)) {
        if (*p >= 2) {
            if (p[1] == 0)
                BTL_EVENT_OverwriteVar(0x22, 0x1a);
            else if (p[2] == 0x1f)
                BTL_EVENT_OverwriteVar(0x22, 0x1a);
            *p = 3;
        }
    }
}





void func_021E3DCC(int u, void *a, int b, int *p)
{
    int t;

    if (b == BTL_EVENT_GetVar(3)) {
        if (*p >= 2) {
            t = func_021E3E84(u, a, b, p);
            p[2] = t;
            BTL_EVENT_OverwriteVar(4, t);
        }
    }
}





void func_021E3E00(int u, int a, int b, int *p)
{
    if (b == BTL_EVENT_GetVar(4)) {
        if (BTL_EVENT_GetVar(0x46) == 0) {
            if (p[6] != 0)
                p[1] += BTL_EVENT_GetVar(0x32);
        }
    }
}





void func_021E3E30(int u, void *a, int b, int *p)
{
    int x;

    if (b == BTL_EVENT_GetVar(3)) {
        if (*p >= 2) {
            func_021C7CF4(a, b);
            x = p[1];
            if (x != 0)
                x *= 2;
            BTL_EVENT_OverwriteVar(0x37, x);
            *p = 3;
        }
    }
}





void func_021E3E64(int u, void *a, int b, int *p)
{
    if (b == BTL_EVENT_GetVar(2))
        func_021E3F08(a, b, p);
}





int func_021E3E84(int u, void *a, int c, int *w)
{
    u8 buf[16];
    void *q;
    unsigned i;
    int x;
    int t;
    int r;

    q = func_021C7CF4(a, c);
    for (i = 0; i < 3; i++) {
        if (BTL_POKEPARAM_GetHitCount(q, (u8)i) != 0) {
            BTL_POKEPARAM_GetHitRecord(q, (u8)i, (int)0, (u16 *)(&buf[6]));
            x = buf[0xb];
            if (func_021C7D00(a, x) == 6) {
                t = func_021C8010(a, c);
                r = func_021C7F68(a, (u16)(0x100 | t), buf);
                if (r != 0)
                    x = buf[(u8)BTL_CALC_Random(r)];
                else
                    x = 0x1f;
            }
            return x;
        }
    }
    return 0x1f;
}



void func_021E3F08(void *a, int b, int *p)
{
    u8 *s;

    if (p[6] != 0) {
        s = func_021C88A4(a, 0xb, b);
        ((struct Obj07830 *)s)->f4 = 0x19;
        s[0x14] = 1;
        s[8] = b;
        s[0x15] = 1;
        func_021C88C8(a, s);
        p[6] = 0;
    }
}


int *func_021E3F38(int *p)
{
    *p = 1;
    return d_021F27CC;
}


void func_021E3F44(int u, void *a, int c)
{
    void *q;
    int h;
    char *p;

    if (c == BTL_EVENT_GetVar(3)) {
        q = func_021C7CF4(a, c);
        if (BTL_POKEPARAM_GetItem(q) == 0) {
            h = BTL_POKEPARAM_GetConsumedItem(q);
            if (h != 0) {
                p = func_021C88A4(a, 0x20, c);
                ((struct Obj10088 *)p)->f4 = h;
                p[6] = c;
                p[7] = 1;
                func_021C8838(p + 0xc, 2, 0x2dd);
                func_021C8860((struct S *)(p + 0xc), c);
                func_021C8860((struct S *)(p + 0xc), h);
                func_021C88C8(a, p);
            }
        }
    }
}



int *func_021E3FB4(int *p)
{
    *p = 1;
    return d_021F27C4;
}




/*
 * Frame: 0x1c bytes of locals needs the two BTL_POKEPARAM_GetMajorStatusIndex calls and
 * BTLV_CORE_MakeSlotKind1Index15 declared as returning a one-word struct (Word); see
 * docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md.
 * Word on BTL_POKEPARAM_GetSickContRaw or BTL_CALC_MakeDefaultSickCont as well gives a larger frame.
 */
void func_021E3FC0(int u, void *a, int c)
{
    void *q;
    int r;
    u8 k;
    int s;
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        q = func_021C7CF4(a, c);
        r = BTL_POKEPARAM_GetMajorStatusIndex(q).v;
        if (r != 0) {
            k = BTL_EVENT_GetVar(6);
            if (BTL_POKEPARAM_GetMajorStatusIndex(func_021C7CF4(a, k)).v == 0) {
                s = BTL_POKEPARAM_GetSickContRaw(q, r);
                p = func_021C88A4(a, 0xc, c);
                ((struct Obj03704 *)p)->f4 = r;
                if (r == 5 && BTLV_CORE_IsSlotKind1Index15(s) != 0)
                    *(Word *)(p + 8) = BTLV_CORE_MakeSlotKind1Index15();
                else
                    ((struct Obj03704 *)p)->f8 = BTL_CALC_MakeDefaultSickCont(r);
                p[0xf] = k;
                p[0xc] = 1;
                func_021C88C8(a, p);
                p = func_021C88A4(a, 0xb, c);
                ((struct Obj03704 *)p)->f4 = r;
                p[0x14] = 1;
                p[8] = c;
                ((struct Obj03704 *)p)->f0 |= 0x1000000;
                func_021C88C8(a, p);
                BTL_EVENT_OverwriteVar(0x51, 0);
            }
        }
    }
}




int *func_021E4074(int *p)
{
    *p = 1;
    return d_021F27BC;
}



/*
 * follower: 021E4148 store-and-return stub included after two padding bytes.
 */
void func_021E4080(void *a, void *b, int c)
{
    u8 k;
    void *m;
    void *n;
    u32 x;
    u32 y;
    u32 avg;
    u8 *p;
    if (c != BTL_EVENT_GetVar(3)) return;
    k = BTL_EVENT_GetVar(6);
    m = func_021C7CF4(b, c);
    n = func_021C7CF4(b, k);
    x = func_021D59B4(m, 13);
    y = func_021D59B4(n, 13);
    avg = (x + y) / 2;
    p = func_021C88A4(b, 8, c);
    p[4] = 2;
    p[7] = c;
    ((struct Obj02790 *)p)->f10 = avg - x;
    p[8] = k;
    ((struct Obj02790 *)p)->f14 = avg - y;
    p[6] = 1;
    func_021C88C8(b, p);
    p = func_021C88A4(b, 4, c);
    func_021C8838(p + 4, 1, 113);
    func_021C88C8(b, p);
    p = func_021C88A4(b, 33, c);
    p[4] = c;
    ((struct Obj02790 *)p)->f8 = 1;
    func_021C88C8(b, p);
    p = func_021C88A4(b, 33, c);
    p[4] = k;
    ((struct Obj02790 *)p)->f8 = 1;
    func_021C88C8(b, p);
}



u32 *func_021E4148(u32 *p)
{
    *p = 1;
    return data_021F27B4;
}
