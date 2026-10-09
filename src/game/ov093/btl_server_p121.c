/*
 * file:     btl_server_p121.c
 * unit:     yes
 * function: func_021CEEB8, func_021CEFFC, func_021CF078, func_021CF220, func_021CF2F0, func_021CF360, func_021CF37C, func_021CF3B8, func_021CF3F8, func_021CF41C, func_021CF430, func_021CF448, func_021CF470, func_021CF524, func_021CF58C, func_021CF5B0, func_021CF81C, func_021CF89C, func_021CF8D4, func_021CF918, func_021CF9B4, func_021CFAC4, func_021CFADC, func_021CFB8C, func_021CFBA4, func_021CFBBC, func_021CFBE0, func_021CFBF0
 * address:  0x021CEEB8
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
 *   func_021E9D04 0x021E9D04 thumb ov093
 *   func_021CE0BC 0x021CE0BC thumb ov093
 *   func_021E9E70 0x021E9E70 thumb ov093
 *   func_021E9E80 0x021E9E80 thumb ov093
 *   func_021EA01C 0x021EA01C thumb ov093
 *   func_021EA044 0x021EA044 thumb ov093
 *   func_021EA030 0x021EA030 thumb ov093
 *   func_021EA04C 0x021EA04C thumb ov093
 *   func_021D8358 0x021D8358 thumb ov093
 *   func_021EA058 0x021EA058 thumb ov093
 *   func_021D805C 0x021D805C thumb ov093
 *   func_021CE150 0x021CE150 thumb ov093
 *   func_021CE4D0 0x021CE4D0 thumb ov093
 *   func_021CE3C8 0x021CE3C8 thumb ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021B9AF8  0x021B9AF8  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B8670  0x021B8670  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5C30  0x021D5C30  thumb  ov093
 *   func_021B86E4 0x021B86E4 thumb ov093
 *   func_021EAF18 0x021EAF18 thumb ov093
 *   func_021EAF50 0x021EAF50 thumb ov093
 *   func_021EAF78 0x021EAF78 thumb ov093
 *   func_021CE3B4 0x021CE3B4 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_021CE0F8 0x021CE0F8 thumb ov093
 *   func_021EA65C 0x021EA65C thumb ov093
 *   func_021EA720 0x021EA720 thumb ov093
 *   func_021EABC4 0x021EABC4 thumb ov093
 *   func_021EAC54 0x021EAC54 thumb ov093
 *   func_021CE08C 0x021CE08C thumb ov093
 *   func_021D8414 0x021D8414 thumb ov093
 *   func_021E9964 0x021E9964 thumb ov093
 *   func_021E9974 0x021E9974 thumb ov093
 *   func_021B990C 0x021B990C thumb ov093
 *   func_021D8434 0x021D8434 thumb ov093
 *   func_021B86C0  0x021B86C0  thumb  ov093
 *   func_021EA7FC  0x021EA7FC  thumb  ov093
 *   func_021EA814  0x021EA814  thumb  ov093
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021CE0E0  0x021CE0E0  thumb  ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021B9090 0x021B9090 thumb ov093
 *   func_021B90BC 0x021B90BC thumb ov093
 *   func_02082BCC 0x02082BCC arm
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021D8444  0x021D8444  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D6314  0x021D6314  thumb  ov093
 *   func_021E8B80  0x021E8B80  thumb  ov093
 *   func_021D67C4  0x021D67C4  thumb  ov093
 *   func_021D82D0  0x021D82D0  thumb  ov093
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_021D5778  0x021D5778  thumb  ov093
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 *   func_021D5584  0x021D5584  thumb  ov093
 *   func_021D81F8 0x021D81F8 thumb ov093
 *   func_021D5750 0x021D5750 thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_0201C314 0x0201C314 thumb
 *   func_021D67B8 0x021D67B8 thumb ov093
 *   func_021D62D8 0x021D62D8 thumb ov093
 *   func_0201BEB8 0x0201BEB8 thumb
 *   func_021EFCE4 0x021EFCE4 thumb ov093
 *   func_021EFC1C 0x021EFC1C thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021B8D38 0x021B8D38 thumb ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_021B9B98 0x021B9B98 thumb ov093
 *   func_021CFD50 0x021CFD50 thumb ov093
 *   func_021D6C24 0x021D6C24 thumb ov093
 *   func_021B937C 0x021B937C thumb ov093
 *   func_021CFDCC 0x021CFDCC thumb ov093
 *   func_021CFE08 0x021CFE08 thumb ov093
 *   func_021CFE98 0x021CFE98 thumb ov093
 *   func_021CFFAC 0x021CFFAC thumb ov093
 *   func_021D0100 0x021D0100 thumb ov093
 *   func_021D0248 0x021D0248 thumb ov093
 *   func_021D0304 0x021D0304 thumb ov093
 *   func_021D0980 0x021D0980 thumb ov093
 *   func_021D09E0 0x021D09E0 thumb ov093
 */
#include "../../matched/include/Obj00967.h"
#include "../../matched/include/Obj09993.h"
#include "../../matched/include/Obj02136.h"
#include "../../matched/include/Obj00888.h"
#include "../../matched/include/Obj07772.h"
#include "../../matched/include/Obj06234.h"
#include "../../matched/include/Obj05200.h"
#include "../../matched/include/Obj01894.h"
#include "../../matched/include/Obj07774.h"
#include "../../matched/include/Obj00489.h"

struct QV;
struct Q1;
struct S2;
struct UtilWork;
struct L;
struct H;
struct Unk021D82D0;
struct QL;
struct Unk021D62A8;
struct QG;
struct QI;
struct UtilSlots;
struct G;
struct R4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { VALUE_ZERO, VALUE_ONE } Value;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 v; } Word;

struct Unk021D82D0 { u32 kind : 4; u32 sub : 3; u32 id : 16; u32 rest : 9; };

extern void func_021E9D04(void *, int, int, int, u32, u32);
extern int func_021CE0BC(u8 *p, void *q);
extern void func_021E9E70(u8 *p);
extern int func_021E9E80(u8 *p);
extern u16 func_021EA01C(u8 *p);
extern u8 func_021EA044(struct QV *p);
extern u8 func_021EA030(u8 *p);
extern u8 func_021EA04C(u8 *p);
extern void func_021D8358(u32 *p, u32 id, u32 sub, u32 val);
extern void func_021EA058(char *p);
extern u32 func_021D805C(void *p, u32 n);
extern void func_021CE150(u8 *p, void *q);
extern int func_021CE4D0(u8 *p, u32 *st);
extern int func_021CE3C8(u8 *p, int *state);
extern void *func_021B86B8(void ***p);
extern char *func_021B9AF8(char *p, int i);
extern u8 func_021B9B94(struct Q1 *p);
extern unsigned int func_021B8670(unsigned int **p);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *m);
extern int func_021D5C30(struct UtilWork *p);
extern int func_021B86E4(unsigned int **p);
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EAF78(u8 *, u8);
extern void func_021CE3B4(u8 *p, void *q);
extern int func_021EA710(u32 *p);
extern void func_021CE0F8(u8 *, u8 *, u8 *);
extern void func_021EA65C(char *p, struct H *h);
extern int func_021EA720(u32 *p);
extern void func_021EABC4(u8 *a, u32 x, u32 y, u32 z);
extern int func_021EAC54(void *, int *);
extern int func_021CE08C(u8 *);
extern void func_021D8414(u32 *p);
extern void func_021E9964(u32);
extern int func_021E9974(u32);
extern void *func_021B990C(char *p, unsigned int i, unsigned int j);
extern void func_021D8434(u32 *p);
extern u8 func_021B86C0(u8 **p);
extern void func_021EA7FC(char *p);
extern int func_021EA814(u32 *p);
extern int func_021F7EB4(void);
extern void func_021CE0E0(u8 *p);
extern u8 func_021B8FF4(u8 *);
extern void func_021B9090(u8 *p, u32 k, u32 x);
extern void func_021B90BC(u8 *p, u8 k, u32 v);
extern void func_02082BCC(void *,int,u32);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void func_021D8444(u32 *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern Word func_021D6314(void *q, int i);
extern u16 func_021E8B80(Word v);
extern u8 func_021D67C4(u8 *p);
extern void func_021D82D0(struct Unk021D82D0 *out, u32 id, u32 sub);
extern u16 func_021D67A8(struct QL *p);
extern u8 func_021D5778(void *q, u32 id);
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(u8 *p, int i);
extern u8 func_021D5584(struct UtilWork *p, u32 i);
extern u32 func_021D81F8(void *, void *, void *, u32, void *);
extern int func_021D5750(void *, u32);
extern u16 func_021D5B40(struct QI *p);
extern u8 func_021D5440(u8 *p);
extern u32 func_0201C314(void *p);
extern u16 func_021D67B8(u8 *p);
extern u16 func_021D62D8(struct UtilSlots *p, int i);
extern int func_0201BEB8(u32, int);
extern void *func_021EFCE4(char *arg0, int arg1);
extern int func_021EFC1C(int, int, void *, u32);
extern int func_021D59B4(u8 *p, int k);
extern int func_021B8D8C(void *, void *, u32);
extern u8 func_021B8D38(void *p, int a, int k, u8 *out);
extern u8 *func_021B9934(char *p, int i);
extern int func_021D5814(void *m, int k);
extern u8 func_021B9B98(u8 *p);
extern u8 *func_021CFD50(struct G *g, int k);
extern int func_021D6C24(struct R4 *p);
extern u8 *func_021B937C(int, char *, u8 *);
extern int func_021CFDCC(void *, void *);
extern int func_021CFE08(struct G *g, void *a, void *b);
extern int func_021CFE98(struct G *g, void *a, void *b);
extern int func_021CFFAC(struct G *g, void *mon, void *target);
extern int func_021D0100(struct G *g, void *mon, void *target, u8 *out);
extern int func_021D0248(struct G *g, void *m, u8 *out);
extern int func_021D0304(struct G *g, void *mon, void *target, u8 *out);
extern u8 func_021D0980(u8 *, u8 *);
extern void func_021D09E0(u8 *p, u8 *order, u8 count, void *target);
u32 func_021CEEB8(u8 *p, int *st);
u32 func_021CEFFC(u8 *p);
u32 func_021CF078(u8 *p, u32 *st);
u32 func_021CF220(u8 *p, int *st);
u32 func_021CF2F0(u8 *p, s32 *st);
void func_021CF360(u8 *p);
void func_021CF37C(u8 *p,u32 i,u32 v);
void func_021CF3B8(u8 *p, u32 i);
void func_021CF3F8(u8 *p);
void func_021CF41C(u8 *p);
void func_021CF430(u8 *p, u32 i, u32 v);
u8 func_021CF43C(u8 *p, u32 i);
u8 func_021CF448(u8 *p);
u32 func_021CF470(u8 *p, void *q, u8 *o);
u32 func_021CF524(u32 x, void *q, u32 y);
void func_021CF58C(struct Unk021D82D0 *out, u8 *p, void *q);
int func_021CF5B0(u8 *g, void *m, u32 move, void *out);
u32 func_021CF81C(u8 *p, void *q, u8 *out);
int func_021CF89C(u8 *p, void *q);
u32 func_021CF8D4(u8 *p, void *q, u8 *a, u16 *b);
u32 func_021CF918(u8 *g, u8 *a, u16 *b);
u32 func_021CF9B4(u8 *g, void *m, u8 *a, u16 *b);
int func_021CFAC4(void *p, void *q);
int func_021CFADC(u8 *g, void *m);
int func_021CFB8C(void *p, void *q);
void func_021CFBA4(s8 *p);
int func_021CFBBC(s8 *p, int v);
void func_021CFBE0(u8 *p, u32 i, u32 v);
int func_021CFBF0(u8 *g, void *m, u32 slot, u8 *out);





static inline u8 same_index(u8 *p)
{
    return p[0x11d] == p[0x11f] ? 1 : 0;
}





/*
 * lever: u16 b/d retain the spilled reload and narrow only at the u8 call;
 *        enum same retains the early ternary truncation.
 */
u32 func_021CEEB8(u8 *p, int *st)
{
    u32 a, c, z;
    u16 b, d;
    Value same;
    u32 flag;
    switch (*st) {
    case 0:
        a = func_021CF448(p);
        same = same_index(p);
        flag = (u8)func_021CEFFC(p);
        func_021E9D04(((struct Obj00967 *)p)->f54, p[0x1aa], p[0x1ab], a, same, flag);
        ++*st;
        break;
    case 1:
        z = 0;
        if (func_021CE0BC(p, 0)) {
            func_021E9E70(((struct Obj00967 *)p)->f54);
            *st = 2;
            return z;
        }
        if (func_021E9E80(((struct Obj00967 *)p)->f54)) {
            a = func_021EA01C(((struct Obj00967 *)p)->f54);
            b = func_021EA044(((struct Obj00967 *)p)->f54);
            if (a && b != 6) {
                c = func_021EA030(((struct Obj00967 *)p)->f54);
                d = func_021EA04C(((struct Obj00967 *)p)->f54);
                if (p[0x1ab] >= c) p[0x1ab] = p[0x1ab] - c;
                else {
                    p[0x1ab] = z;
                    c = p[0x1ab];
                }
                func_021CF430(p, p[0x11d], c);
                func_021D8358(((struct Obj00967 *)p)->fC, a, (u8)b, (u8)d);
                func_021EA058(((struct Obj00967 *)p)->f54);
                if (func_021D805C((void *)a, 0xf) == 4) p[0x1b2] |= 4;
                func_021CF37C(p, p[0x11d], a);
                func_021CE150(p, (void *)((u32)func_021CF220));
            } else func_021CE150(p, (void *)((u32)func_021CE4D0));
        }
        break;
    case 2:
        if (func_021E9E80(((struct Obj00967 *)p)->f54)) func_021CE150(p, (void *)((u32)func_021CE3C8));
        break;
    }
    return 0;
}





u32 func_021CEFFC(u8 *p)
{
    char *arr;
    u32 lim;
    u32 flag;
    u32 i;
    u32 c;
    u8 *w;
    u32 cnt;
    if (func_021B86B8(*(void *** *)&((struct Obj09993 *)p)->f0) == 0) {
        arr = func_021B9AF8(*(char * *)&((struct Obj09993 *)p)->f4, 1);
        cnt = func_021B9B94((struct Q1 *)arr);
        lim = func_021B8670((unsigned int **)(*(void *** *)&((struct Obj09993 *)p)->f0));
        if (lim > cnt) {
            lim = cnt;
        }
        flag = 0;
        c = 0;
        for (i = 0; i < lim; i++) {
            w = func_021B9C00((struct S2 *)arr, (u8)i);
            if (func_021D5B68(w) == 0) {
                c++;
                if (func_021D5C30((struct UtilWork *)w) != 0) {
                    flag = 1;
                }
            }
        }
        if (c == 1 && flag != 0) {
            return 1;
        }
    }
    return 0;
}




u32 func_021CF078(u8 *p, u32 *st)
{
    u8 id;
    u16 k;
    int result;
    switch (*st) {
    case 0:
        switch (func_021B86E4(((struct Obj02136 *)p)->f0)) {
        default:
        case 0:
            if (func_021CF918(p, &id, &k) == 4) {
                *st = 5;
                break;
            }
            if (k) {
                func_021EAF18((struct L *)(p + 0x58), 2, 0x365);
                func_021EAF50((struct L *)(p + 0x58), id);
                func_021EAF50((struct L *)(p + 0x58), k);
            } else {
                func_021EAF18((struct L *)(p + 0x58), 1, 0x4a);
            }
            func_021CE3B4(p, p + 0x58);
            *st = 1;
            break;
        case 1:
            func_021EAF18((struct L *)(p + 0x58), 1, 0x4c);
            func_021CE3B4(p, p + 0x58);
            *st = 1;
            break;
        case 2:
            func_021EAF18((struct L *)(p + 0x58), 1, 0x4d);
            func_021EAF78(p + 0x58, 0xff);
            func_021CE3B4(p, p + 0x58);
            *st = 3;
            break;
        }
        break;
    case 1:
        if (func_021EA710(((struct Obj02136 *)p)->f54)) {
            func_021CE0F8(p, *(u8 * *)&((struct Obj02136 *)p)->f8, p + 0x58);
            func_021EA65C(((struct Obj02136 *)p)->f54, (struct H *)(p + 0x58));
            *st = 2;
        }
        break;
    case 2:
        if (func_021EA710(((struct Obj02136 *)p)->f54))
            func_021CE150(p, (void *)((u32)func_021CE4D0));
        break;
    case 3:
        func_021EA710(((struct Obj02136 *)p)->f54);
        if (func_021EA720(((struct Obj02136 *)p)->f54)) {
            func_021EAF18((struct L *)(p + 0x58), 3, 8);
            func_021EAF18((struct L *)(p + 0x7c), 3, 9);
            func_021EABC4(((struct Obj02136 *)p)->f54, (u32)(p + 0x58), (u32)(p + 0x7c), 1);
            *st = 4;
        }
        break;
    case 4:
        if (func_021EA710(((struct Obj02136 *)p)->f54)) {
            if (func_021EAC54(((struct Obj02136 *)p)->f54, &result)) {
                if (result == 0)
                    *st = 5;
                else
                    func_021CE150(p, (void *)((u32)func_021CE4D0));
            } else if (func_021CE08C(p)) {
                func_021CE150(p, (void *)((u32)func_021CE3C8));
            }
        }
        break;
    case 5:
        func_021D8414(((struct Obj02136 *)p)->fC);
        p[0x1b2] |= 4;
        func_021CE150(p, (void *)((u32)func_021CF220));
        break;
    }
    return 0;
}




u32 func_021CF220(u8 *p, int *st)
{
    u8 n;
    void *q;
    switch (*st) {
    case 0:
        func_021E9964(((struct Obj00888 *)p)->f54);
        ++*st;
        break;
    case 1:
        if (func_021E9974(((struct Obj00888 *)p)->f54)) {
            ++p[0x11d];
            if (p[0x11d] < p[0x11c]) {
                if ((((u32)p[0x1b2] << 29) >> 31) == 0) {
                    func_021CE150(p, (void *)((u32)func_021CE4D0));
                    break;
                }
                while (p[0x11d] < p[0x11c]) {
                    q = func_021B990C((char *)(((struct Obj00888 *)p)->f4), p[0x1a6], p[0x11d]);
                    if (!func_021CF470(p, q, p + 0x124 + p[0x11d] * 4))
                        func_021D8434((u32 *)(p + 0x124 + p[0x11d] * 4));
                    ++p[0x11d];
                }
            }
            if (p[0x11d] >= p[0x11c]) {
                n = p[0x11c] + p[0x1af];
                p[0x1af] = 0;
                *(u8 * *)&((struct Obj00888 *)p)->fD8 = p + 0x124;
                ((struct Obj00888 *)p)->fDC = n * 4;
                func_021CE150(p, (void *)((u32)func_021CF2F0));
            }
        }
        break;
    }
    return 0;
}





u32 func_021CF2F0(u8 *p, s32 *st)
{
    switch (*st) {
    case 0:
        func_021CF3F8(p);
        if (func_021B86C0(*(u8 ** *)&((struct Obj07772 *)p)->f0) != 0) {
            p[0x1a9] = 1;
            func_021EA7FC((char *)(*(u32 *)&((struct Obj07772 *)p)->f54));
            *st = *st + 1;
        } else {
            *st = *st + 2;
        }
        break;
    case 1:
        if (func_021EA814(*(u32 * *)&((struct Obj07772 *)p)->f54) != 0) {
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            func_021CE0E0(p);
            *st = *st + 1;
            return 1;
        }
        break;
    default:
        return 1;
    }
    return 0;
}




void func_021CF360(u8 *p) { u32 i; for(i=0;i<3;i++) *(u16 *)(p+0x1a0+i*2)=0; }




void func_021CF37C(u8 *p,u32 i,u32 v) { if(p[0x1aa]==0) { if(p[0x1a6]==func_021B8FF4(*(u8 * *)&((struct Obj06234 *)p)->f0)) { *(u16 *)(p+0x1a0+i*2)=v; func_021B9090(*(u8 * *)&((struct Obj06234 *)p)->f0,p[0x1a6],v); } } }




/*
 * lever: func_021B90BC consumes the live r2 halfword as its third argument;
 * its matched body forwards it to func_02007E50.
 */
void func_021CF3B8(u8 *p, u32 i)
{
    if (p[0x1aa] == 0) {
        if (p[0x1a6] == func_021B8FF4(*(u8 * *)&((struct Obj05200 *)p)->f0)) {
            u16 *a = (u16 *)(p + 0x1a0);
            u32 v = a[i];
            if (v != 0) {
                a[i] = 0;
                func_021B90BC(*(u8 * *)&((struct Obj05200 *)p)->f0, p[0x1a6], v);
            }
        }
    }
}




void func_021CF3F8(u8 *p) { u32 i; if(p[0x1aa]==0) for(i=0;i<3;i++) func_021CF3B8(p,(u8)i); }




void func_021CF41C(u8 *p) { func_02082BCC(p+0x130,0,3); }



/*
 * follower: unlabelled byte accessor at 0x021CF43C.
 */
void func_021CF430(u8 *p, u32 i, u32 v)
{
    (p + i)[0x130] = v;
}



u8 func_021CF43C(u8 *p, u32 i)
{
    return (p + i)[0x130];
}



u8 func_021CF448(u8 *p)
{
    u32 i;
    u32 sum;
    u32 n;
    sum = 0;
    n = p[0x11d];
    i = 0;
    for (; i < n; i++) sum += p[0x130+i];
    return sum;
}




u32 func_021CF470(u8 *p, void *q, u8 *o)
{
    u32 id;
    u32 a;
    u32 b;
    Word t;
    if (func_021D5B68(q) != 0) {
        if (o != 0) {
            func_021D8434((u32 *)o);
        }
        return 1;
    }
    if (func_021D5BDC(q, 0xc) != 0) {
        if (o != 0) {
            func_021D8444((u32 *)o);
        }
        return 1;
    }
    id = 0x19;
    if (func_021D62C4(q, id) != 0) {
        t = func_021D6314(q, id);
        id = func_021E8B80(t);
        b = func_021D67C4(q);
        if (o != 0) {
            func_021D82D0((struct Unk021D82D0 *)o, id, b);
        }
        return 1;
    }
    if (func_021D62C4(q, 0x1a) != 0) {
        a = func_021D67A8(q);
        b = func_021D67C4(q);
        func_021D5778(q, a);
        if (o != 0) {
            func_021D82D0((struct Unk021D82D0 *)o, a, b);
        }
        return 1;
    }
    return 0;
}




u32 func_021CF524(u32 x, void *q, u32 y)
{
    u32 n = func_021D5448(q);
    u32 c = 0;
    u32 i = 0;
    for (; i < n; i++) {
        if (func_021CF5B0((u8 *)x, q, (u32)func_021D54C0(q, (u8)i), 0) == 0) {
            if ((u32)func_021D5584(q, (u8)i) != 0) {
                c++;
            }
        }
    }
    if (c == 0) {
        func_021CF58C((struct Unk021D82D0 *)y, (u8 *)x, q);
        return 1;
    }
    return 0;
}



void func_021CF58C(struct Unk021D82D0 *out, u8 *p, void *q)
{
    u32 v;
    v = func_021D81F8(((struct Obj01894 *)p)->f0, ((struct Obj01894 *)p)->f4, q, 165, p+0x38);
    func_021D82D0(out, 165, v);
}



int func_021CF5B0(u8 *g, void *m, u32 move, void *out)
{
    u32 k;
    u32 k2;
    Word w;
    if (move == 0xa5) return 0;
    if (func_021CF89C(g, m) && func_021D62C4(m, 0x1b)) {
        w = func_021D6314(m, 0x1b);
        k = func_021E8B80(w);
        if (func_021D5750(m, k) && k != move) {
            if (out) {
                func_021EAF18(out, 1, 0x63);
                func_021EAF50(out, func_021D5B40(m));
                func_021EAF50(out, k);
            }
            return 1;
        }
    }
    if (func_021D62C4(m, 0x17)) {
        k2 = func_021E8B80(func_021D6314(m, 0x17));
        if (move != k2) {
            if (out) {
                func_021EAF18(out, 1, 0x64);
                func_021EAF50(out, func_021D5440(m));
                func_021EAF50(out, k2);
            }
            return 1;
        }
    }
    if (func_021D62C4(m, 0xb) && func_0201C314((void *)move) == 0) {
        if (out) {
            func_021EAF18(out, 2, 0x23b);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021D62C4(m, 0xc) && move == func_021D67B8(m)) {
        if (out) {
            func_021EAF18(out, 2, 0x244);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021D62C4(m, 0xd) && move == func_021D62D8(m, 0xd) && move != 0xa5) {
        if (out) {
            func_021EAF18(out, 2, 0x253);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021D62C4(m, 0xf) && func_0201BEB8(move, 0xc)) {
        if (out) {
            func_021EAF18(out, 2, 0x37a);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021EFCE4((char *)(*(int *)&((struct Obj01894 *)g)->f34), 3) && func_021EFC1C(*(int *)&((struct Obj01894 *)g)->f34, *(int *)&((struct Obj01894 *)g)->f4, m, move)) {
        if (out) {
            func_021EAF18(out, 2, 0x24d);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021EFCE4((char *)(*(int *)&((struct Obj01894 *)g)->f34), 2) && func_0201BEB8(move, 9)) {
        if (out) {
            func_021EAF18(out, 2, 0x43e);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    return 0;
}




u32 func_021CF81C(u8 *p, void *q, u8 *out)
{
    u8 n = func_021D5448(q);
    u32 r = 4;
    u8 i = 0;
    for (; i < n; i++) {
        if (func_021D5584(q, i) != 0) {
            out[i] = (func_021CF5B0(p, q, func_021D54C0(q, i), 0) == 0) ? 1 : 0;
            if (r == 4 && out[i] != 0) {
                r = i;
            }
        } else {
            out[i] = 0;
        }
    }
    for (; i < 4; i++) {
        out[i] = 0;
    }
    return r;
}



int func_021CF89C(u8 *p, void *q)
{
    if (func_021EFCE4(*(char * *)&((struct Obj01894 *)p)->f34, 7)) return 0;
    if (func_021D62C4(q, 19)) return 0;
    if (func_021D59B4(q, 17) != 103) return 1;
    return 0;
}




u32 func_021CF8D4(u8 *p, void *q, u8 *a, u16 *b)
{
    u32 r;
    if (func_021CF89C(p, q) != 0) {
        if (func_021D5B40(q) == 0x127) {
            return 4;
        }
    }
    r = func_021CF9B4(p, q, a, b);
    if (r == 4) {
        *a = 0x1f;
        *b = 0;
        r = 4;
    }
    return r;
}




u32 func_021CF918(u8 *g, u8 *a, u16 *b)
{
    u32 i;
    u8 *m;
    u32 r;

    for (i = 0; i < g[0x11c]; i++) {
        m = func_021B9C00(((struct Obj07774 *)g)->f118, (u8)i);
        if (func_021D5B68(m) == 0) {
            if (func_021CF89C(g, m) != 0 && func_021D5B40((struct QI *)m) == 0xe4)
                return 4;
            if (func_021D59B4(m, 0x11) == 0x32)
                return 4;
        }
    }
    for (i = 0; i < g[0x11c]; i++) {
        r = func_021CF9B4(g, func_021B9C00(((struct Obj07774 *)g)->f118, (u8)i), a, b);
        if (r != 4)
            return r;
    }
    return 4;
}



u32 func_021CF9B4(u8 *g, void *m, u8 *a, u16 *b)
{
    u8 buf[4];
    u8 n;
    u8 i;
    u8 *q;
    u16 k;
    n = func_021B8D38(((struct Obj01894 *)g)->f0, *(int *)&((struct Obj01894 *)g)->f4, (u16)(func_021B8D8C(((struct Obj01894 *)g)->f0, ((struct Obj01894 *)g)->f4, func_021D5440(m)) | 0x100), buf);
    for (i = 0; i < n; i++) {
        q = func_021B9934(((struct Obj01894 *)g)->f4, buf[i]);
        k = func_021D59B4(q, 0x11);
        func_021D5440(q);
        if (k == 0x17 && func_021CFAC4(g, m)) {
            *a = func_021D5440(q);
            *b = k;
            return 0;
        }
        if (k == 0x47 && func_021CFADC(g, m)) {
            *a = func_021D5440(q);
            *b = k;
            return 0;
        }
        if (k == 0x2a && func_021CFB8C(g, m)) {
            *a = func_021D5440(q);
            *b = k;
            return 0;
        }
    }
    if (func_021D62C4(m, 0x16) || func_021D62C4(m, 8) || func_021D62C4(m, 0x15)) {
        *a = func_021D5440(m);
        *b = 0;
        return 3;
    }
    return 4;
}



int func_021CFAC4(void *p, void *q)
{
    if (func_021D59B4(q, 17) != 23) return 1;
    return 0;
}




int func_021CFADC(u8 *g, void *m)
{
    u32 a;

    a = func_021CF89C(g, m);
    if (func_021EFCE4((char *)(*(int *)&((struct Obj01894 *)g)->f34), 2) != 0)
        return 1;
    if (func_021D62C4(m, 0x1f) != 0)
        return 1;
    if (func_021D62C4(m, 0x15) != 0)
        return 1;
    if (a != 0 && func_021D5B40(m) == 0x116)
        return 1;
    if (func_021D59B4(m, 0x11) == 0x1a)
        return 0;
    if (func_021D5814(m, 2) != 0)
        return 0;
    if (func_021D62C4(m, 0x1e) != 0)
        return 0;
    if (func_021D62C4(m, 0x20) != 0)
        return 0;
    if (a != 0 && func_021D5B40(m) == 0x21d)
        return 0;
    return 1;
}



/*
 * extent: follower 0x021CFBA4 already has its own matched source/shard.
 */
int func_021CFB8C(void *p, void *q)
{
    if (func_021D5814(q, 8)) return 1;
    return 0;
}



/*
 * semantic: signed byte -1 has the original stored bits 0xff. The body
 *   only writes bytes and never reads through p. Six stores cover p10c..p111.
 */
void func_021CFBA4(s8 *p)
{
    u32 i = 0;
    s8 fill = -1;
    for (; i < 6; i++) p[0x10c+i] = fill;
}


int func_021CFBBC(s8 *p, int v)
{
    u32 i = 0;
    for (; i < 6; i++) {
        if ((p+i)[0x10c] == v) return 1;
    }
    return 0;
}


void func_021CFBE0(u8 *p, u32 i, u32 v)
{
    if (i < 6) (p + i)[0x10c] = v;
}


int func_021CFBF0(u8 *g, void *m, u32 slot, u8 *out)
{
    u8 choice;
    u8 id;
    u16 k;
    u8 buf[6];
    u8 *q;
    u32 n;
    u32 i;
    u8 ok;
    choice = 6;
    if (func_021CF8D4(g, m, &id, &k) != 4) return 0;
    if (func_021B9B98(((struct Obj00489 *)g)->f118) <= g[0x11c]) return 0;
    q = func_021CFD50((struct G *)g, func_021B8D8C(((struct Obj00489 *)g)->f0, ((struct Obj00489 *)g)->f4, func_021D5440(m)));
    if (!q) return 0;
    if (func_021D6C24((struct R4 *)q))
        q = func_021B937C(*(int *)&((struct Obj00489 *)g)->f0, *(char * *)&((struct Obj00489 *)g)->f4, q);
    if (func_021CFDCC(g, m)) ok = 1;
    else if (func_021CFE08((struct G *)g, m, q)) ok = 1;
    else if (func_021CFE98((struct G *)g, m, q)) ok = 1;
    else if (func_021CFFAC((struct G *)g, m, q)) ok = 1;
    else if (func_021D0100((struct G *)g, m, q, &choice)) ok = 1;
    else if (func_021D0248((struct G *)g, m, &choice)) ok = 1;
    else if (func_021D0304((struct G *)g, m, q, &choice)) ok = 1;
    else return 0;
    if (!ok) return 0;
    if (choice == 6) {
        n = func_021D0980(g, buf);
        func_021D09E0(g, buf, n, q);
        for (i = 0; i < n; i++) {
            if (!func_021CFBBC((s8 *)g, buf[i])) {
                choice = buf[i];
                break;
            }
        }
    }
    if (choice == 6) return 0;
    func_021CFBE0(g, slot, choice);
    *out = choice;
    return 1;
}
