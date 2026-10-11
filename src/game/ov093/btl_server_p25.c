/*
 * file:     btl_server_p25.c
 * unit:     yes
 * function: func_021CEEB8, func_021CEFFC, func_021CF078, func_021CF220, func_021CF2F0, func_021CF360, func_021CF37C, func_021CF3B8, func_021CF3F8, func_021CF41C, func_021CF430, func_021CF448, func_021CF470, func_021CF524, func_021CF58C, func_021CF5B0, func_021CF81C, func_021CF89C, func_021CF8D4, func_021CF918, func_021CF9B4, func_021CFAC4, func_021CFADC, func_021CFB8C, func_021CFBA4, func_021CFBBC, func_021CFBE0, func_021CFBF0, func_021CFD50, func_021CFDCC, func_021CFE08, func_021CFE98, func_021CFFAC, func_021D0100, func_021D0248, func_021D0304, func_021D04E4, func_021D055C, func_021D05C4, func_021D0644, func_021D06C8, func_021D0770, func_021D0980, func_021D09E0, func_021D0B10
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
 *   func_021D6C24 0x021D6C24 thumb ov093
 *   func_021B937C 0x021B937C thumb ov093
 *   _ull_mul       0x0209C054  arm
 *   func_021E8AFC 0x021E8AFC thumb ov093
 *   func_021D631C 0x021D631C thumb ov093
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_0201C1C8 0x0201C1C8 thumb
 *   func_021D799C 0x021D799C thumb ov093
 *   func_021D6940 0x021D6940 thumb ov093
 *   d_021EFFC2 0x021EFFC2 data ov093 a2
 *   func_021D5C44  0x021D5C44  thumb  ov093
 *   func_021D7F2C 0x021D7F2C thumb ov093
 *   func_021D5B7C  0x021D5B7C  thumb  ov093
 *   func_021B9AB0  0x021B9AB0  thumb  ov093
 *   func_021D3DC4 0x021D3DC4 thumb ov093
 *   func_021D8394 0x021D8394 thumb ov093
 *   func_021D83FC 0x021D83FC thumb ov093
 *   func_021880BC 0x021880BC thumb ov096
 *   func_02187FB0 0x02187FB0 thumb ov096
 *   func_02188134 0x02188134 thumb ov096
 *   func_02188140 0x02188140 thumb ov096
 *   func_0201C1D8 0x0201C1D8 thumb
 *   func_021D0B3C 0x021D0B3C thumb ov093
 *   func_021D0B4C 0x021D0B4C thumb ov093
 *   func_021D0B5C 0x021D0B5C thumb ov093
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
#include "../../matched/include/Obj01690.h"
#include "../../matched/include/Obj00340.h"
#include "../../matched/include/Obj03197.h"
#include "../../matched/include/Obj00464.h"
#include "../../matched/include/Obj13364.h"

#define M (*(void **)(p+8))
#define R (*(u8 **)(p+12))
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
struct Rat;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef enum { VALUE_ZERO, VALUE_ONE } Value;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 v; } Word_021CEEB8;

struct Unk021D82D0 { u32 kind : 4; u32 sub : 3; u32 id : 16; u32 rest : 9; };

typedef unsigned long long u64;

struct G_021CFD50 {
    void *p0;
    void *p1;
    u8 pad0[0xec];
    u64 seed;
    u64 mul;
    u64 add;
};

struct G_021CFE08 {
    void *p0;
    u8 pad0[0xf0];
    u64 seed;
    u64 mul;
    u64 add;
};

struct G_021CFE98 { u8 pad[0xf4]; u64 seed; u64 mul; u64 add; };

struct G_021CFFAC { u8 pad[0xf4]; u64 seed; u64 mul; u64 add; };

struct G_021D0100 { u8 pad[0xf4]; u64 seed; u64 mul; u64 add; };

struct Row { u8 kind; u8 pad; u16 ids[4]; };

struct G_021D0248 {
    u8 pad0[0xf4];
    u64 seed;
    u64 mul;
    u64 add;
};

struct G_021D0304 { void *p0; u8 pad[0xf0]; u64 seed; u64 mul; u64 add; u8 pad2[0xc]; void *list; u8 start; };

struct G {
    u8 pad0[0xf4];
    u64 seed;
    u64 mul;
    u64 add;
    u8 pad1[0xc];
    void *list;
};

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
extern Word_021CEEB8 func_021D6314(void *q, int i);
extern u16 func_021E8B80(Word_021CEEB8 v);
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
extern int func_021D6C24(struct R4 *p);
extern u8 *func_021B937C(int, char *, u8 *);
extern u8 func_021E8AFC(Word_021CEEB8);
extern u8 func_021D631C(u8 *p, int i);
extern u32 func_021B8588(void **p);
extern u16 func_021D57FC(void *);
extern u8 func_0201C1C8(void *p);
extern int func_021D799C(int, u16);
extern int func_021D6940(const u8 *p, int i, u32 j, u16 *out);
extern int func_021D5C44(struct Rat *p);
extern u8 func_021D7F2C(u32 a, u8 b);
extern int func_021D5B7C(void *m);
extern int func_021B9AB0(int k);
extern u32 func_021D3DC4(u8 *, void *, void *);
extern void func_021D8394(void *, u8, u32);
extern void func_021D83FC(u32 *p, u32 sub);
extern void func_021880BC(int, u8 *, int);
extern int func_02187FB0(u8 *);
extern u8 func_02188134(u8 *);
extern u8 func_02188140(u8 *);
extern u16 func_0201C1D8(void *);
extern void func_021D0B3C(void *, u32, u32, u32);
extern void func_021D0B4C(void *, u32);
extern void func_021D0B5C(void *, void *);
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
u8 *func_021CFD50(struct G_021CFD50 *g, int k);
int func_021CFDCC(void *p, void *q);
int func_021CFE08(struct G_021CFE08 *g, void *a, void *b);
int func_021CFE98(struct G_021CFE98 *g, void *a, void *b);
int func_021CFFAC(struct G_021CFFAC *g, void *mon, void *target);
int func_021D0100(struct G_021D0100 *g, void *mon, void *target, u8 *out);
int func_021D0248(struct G_021D0248 *g, void *m, u8 *out);
int func_021D0304(struct G_021D0304 *g, void *mon, void *target, u8 *out);
int func_021D04E4(u8 *g, u16 a, u8 *out);
int func_021D055C(u8 *g, void *a, int b);
int func_021D05C4(u8 *g, u8 a, int b, u8 *out);
int func_021D0644(void *g, void *m, void *a, int b);
u8 func_021D06C8(struct G *g);
int func_021D0770(u8 *p, u32 *state);
u8 func_021D0980(u8 *g, u8 *out);
void func_021D09E0(u8 *p, u8 *order, u8 count, void *target);
void func_021D0B10(u8 *p, u32 a, u32 b, void *q, void *out);
extern const struct Row d_021EFFC2[4];









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
    Word_021CEEB8 t;
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
    Word_021CEEB8 w;
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
    q = func_021CFD50((struct G_021CFD50 *)g, func_021B8D8C(((struct Obj00489 *)g)->f0, ((struct Obj00489 *)g)->f4, func_021D5440(m)));
    if (!q) return 0;
    if (func_021D6C24((struct R4 *)q))
        q = func_021B937C(*(int *)&((struct Obj00489 *)g)->f0, *(char * *)&((struct Obj00489 *)g)->f4, q);
    if (func_021CFDCC(g, m)) ok = 1;
    else if (func_021CFE08((struct G_021CFE08 *)g, m, q)) ok = 1;
    else if (func_021CFE98((struct G_021CFE98 *)g, m, q)) ok = 1;
    else if (func_021CFFAC((struct G_021CFFAC *)g, m, q)) ok = 1;
    else if (func_021D0100((struct G_021D0100 *)g, m, q, &choice)) ok = 1;
    else if (func_021D0248((struct G_021D0248 *)g, m, &choice)) ok = 1;
    else if (func_021D0304((struct G_021D0304 *)g, m, q, &choice)) ok = 1;
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






u8 *func_021CFD50(struct G_021CFD50 *g, int k)
{
    u8 buf[4];
    u8 n;
    u32 v;

    n = func_021B8D38(g->p0, (int)g->p1, (u16)(k | 0x100), buf);
    if (n) {
        g->seed = g->mul * g->seed + g->add;
        if (n == 0) {
            v = (u32)(g->seed >> 32);
        } else {
            v = (u32)(((g->seed >> 32) * (u32)n) >> 32);
        }
        return func_021B9934(g->p1, buf[(u8)v]);
    }
    return 0;
}





/*
 * lever: explicit aggregate return local reserves the original eight-byte frame;
 *   named incremented accessor result gives cmp r0,r4.
 */
int func_021CFDCC(void *p, void *q)
{
    u32 n;
    u32 id = 20;
    u32 m;
    Word_021CEEB8 t;
    if (func_021D62C4(q, id)) {
        t = func_021D6314(q, id);
        n = func_021E8AFC(t);
        m = func_021D631C(q, id) + 1;
        if (m == n) return 1;
    }
    return 0;
}






int func_021CFE08(struct G_021CFE08 *g, void *a, void *b)
{
    if (func_021B8588(g->p0) != 0)
        return 0;
    if (func_021D59B4(b, 0x11) == 0x19) {
        if (func_021D0644(g, a, b, 4) == 0 && func_021D055C((u8 *)g, b, 4) != 0) {
            g->seed = g->mul * g->seed + g->add;
            if ((u32)(((g->seed >> 32) * 3) >> 32) < 2)
                return 1;
        }
    }
    return 0;
}





/*
 * extent: two zero padding bytes at 0x021CFFAA, followed by labelled func_021CFFAC.
 */
int func_021CFE98(struct G_021CFE98 *g, void *a, void *b)
{
    u8 n;
    u16 k;
    u32 c;
    u32 i;
    u32 v;
    k = func_021D57FC(b);
    n = func_021D5448(a);
    c = 0;
    for (i = 0; i < n; i++) {
        v = (u32)func_021D54C0(a, (u8)i);
        if (func_0201C314((void *)v)) {
            if (func_021D799C(func_0201C1C8((void *)v), k))
                return 0;
            c++;
        }
    }
    if (c >= 2) {
        if (func_021D055C((u8 *)g, b, 4)) {
            g->seed = g->mul * g->seed + g->add;
            return (u32)(((g->seed >> 32) * 3) >> 32) < 2;
        }
        if (func_021D055C((u8 *)g, b, 3)) {
            g->seed = g->mul * g->seed + g->add;
            return (u32)(((g->seed >> 32) * 2) >> 32) < 1;
        }
    }
    return 0;
}




int func_021CFFAC(struct G_021CFFAC *g, void *mon, void *target)
{
    u32 id;
    int valid;
    u32 kind;
    Word_021CEEB8 slot;
    if (func_021D62C4(mon, 0x1b)) {
        slot = func_021D6314(mon, 0x1b);
        id = func_021E8B80(slot);
        if (id) {
            valid = func_0201C314((void *)id);
            kind = func_0201C1C8((void *)id);
            if (func_021D799C(kind, func_021D57FC(target)) == 0 && valid) {
                if (func_021D055C((u8 *)g, target, 4)) {
                    g->seed = g->mul * g->seed + g->add;
                    return (u32)(((g->seed >> 32) * 3) >> 32) < 2;
                }
                if (func_021D055C((u8 *)g, target, 3)) {
                    g->seed = g->mul * g->seed + g->add;
                    return (u32)(((g->seed >> 32) * 2) >> 32) < 1;
                }
            }
            if (!valid) {
                g->seed = g->mul * g->seed + g->add;
                return (u32)(((g->seed >> 32) * 2) >> 32) < 1;
            }
        }
    }
    return 0;
}




int func_021D0100(struct G_021D0100 *g, void *mon, void *target, u8 *out)
{
    u16 hist[5];
    u32 i;
    u8 pos;
    u32 j;
    const struct Row *row;
    pos = 0;
    if (func_021D0644(g, mon, target, 4)) {
        g->seed = g->mul * g->seed + g->add;
        if ((u32)(((g->seed >> 32) * 3) >> 32) == 0) return 0;
    }
    while (func_021D6940(mon, 1, pos++, hist + 1)) {
        for (i = 0; i < 4; i++) {
            row = &d_021EFFC2[i];
            if (((u8 *)hist)[6] == row->kind) {
                for (j = 0; j < 4; j++) {
                    if (!row->ids[j]) break;
                    if (func_021D04E4((u8 *)g, row->ids[j], (u8 *)hist)) {
                        g->seed = g->mul * g->seed + g->add;
                        if ((u32)(((g->seed >> 32) * 2) >> 32) == 0) {
                            *out = ((u8 *)hist)[0];
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}





int func_021D0248(struct G_021D0248 *g, void *m, u8 *out)
{
    u16 t[4];
    u8 idx;

    if (func_021D59B4(m, 0x11) == 0x1e) {
        if (func_021D62C4(m, 2) || func_021D62C4(m, 3)) {
            if (func_021D5C44(m) >= 0x32000) {
                if (func_021D6940(m, 1, 0, t)) {
                    if (func_021D05C4((u8 *)g, ((u8 *)t)[4], 2, &idx)) {
                        *out = idx;
                        return 1;
                    }
                } else {
                    g->seed = g->mul * g->seed + g->add;
                    return (u32)(((g->seed >> 32) * 2) >> 32) ? 0 : 1;
                }
            }
        }
    }
    return 0;
}




int func_021D0304(struct G_021D0304 *g, void *mon, void *target, u8 *out)
{
    u16 hist[4];
    u32 sum;
    u32 i;
    u32 n;
    u8 *other;
    int affinity;
    if (func_021D0644(g, mon, target, 4)) {
        g->seed = g->mul * g->seed + g->add;
        if ((u32)(((g->seed >> 32) * 10) >> 32) != 0) return 0;
    }
    sum = 0;
    for (i = 1; i <= 7; i++) sum += func_021D59B4(mon, i);
    if (sum >= 4) return 0;
    if (func_021D6940(mon, 1, 0, hist)) {
        n = func_021B9B94(g->list);
        i = func_021D7F2C(func_021B8588(g->p0), g->start);
        for (; i < n; i++) {
            if (!func_021CFBBC((s8 *)g, (u8)i)) {
                other = func_021B9C00(g->list, (u8)i);
                if (func_021D0644(g, other, target, 4)) {
                    affinity = func_021D799C(((u8 *)hist)[4], func_021D57FC(other));
                    if (affinity == 0) {
                        g->seed = g->mul * g->seed + g->add;
                        if ((u32)(((g->seed >> 32) * 2) >> 32) == 0) {
                            *out = i;
                            return 1;
                        }
                    } else if (affinity < 3) {
                        g->seed = g->mul * g->seed + g->add;
                        if ((u32)(((g->seed >> 32) * 3) >> 32) == 0) {
                            *out = i;
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}





int func_021D04E4(u8 *g, u16 a, u8 *out)
{
    u32 n;
    u32 i;
    u8 *m;

    n = func_021B9B94(((struct Obj01690 *)g)->f118);
    i = func_021D7F2C(func_021B8588(((struct Obj01690 *)g)->f0), g[0x11c]);
    for (; i < n; i++) {
        if (func_021CFBBC((s8 *)g, (u8)i) == 0) {
            m = func_021B9C00(((struct Obj01690 *)g)->f118, (u8)i);
            if (func_021D5B68(m) == 0 && a == func_021D59B4(m, 0x11)) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}





int func_021D055C(u8 *g, void *a, int b)
{
    u32 n;
    u32 i;

    n = func_021B9B94(((struct Obj00340 *)g)->f118);
    i = func_021D7F2C(func_021B8588(((struct Obj00340 *)g)->f0), g[0x11c]);
    for (; i < n; i++) {
        if (func_021CFBBC((s8 *)g, (u8)i) == 0) {
            if (func_021D0644(g, func_021B9C00(((struct Obj00340 *)g)->f118, (u8)i), a, b))
                return 1;
        }
    }
    return 0;
}





int func_021D05C4(u8 *g, u8 a, int b, u8 *out)
{
    u32 n;
    u32 i;
    u8 *m;

    n = func_021B9B94(((struct Obj03197 *)g)->f118);
    i = func_021D7F2C(func_021B8588(((struct Obj03197 *)g)->f0), g[0x11c]);
    for (; i < n; i++) {
        if (func_021CFBBC((s8 *)g, (u8)i) == 0) {
            m = func_021B9C00(((struct Obj03197 *)g)->f118, (u8)i);
            if (func_021D5B7C(m) != 0 && func_021D799C(a, func_021D57FC(m)) <= b) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}





int func_021D0644(void *g, void *m, void *a, int b)
{
    u16 x;
    u8 n;
    u32 i;
    u32 q;

    if (func_021D5B68(m) == 0) {
        x = func_021D57FC(a);
        n = func_021D5448(m);
        for (i = 0; i < n; i++) {
            q = func_021D54C0(m, (u8)i);
            if (func_021D5584(m, (u8)i) && func_0201C314((void *)q)
                && func_021CF5B0(g, m, q, 0) == 0) {
                if (func_021D799C(func_0201C1C8((void *)q), x) >= b)
                    return 1;
            }
        }
    }
    return 0;
}





u8 func_021D06C8(struct G *g)
{
    u8 buf[2];
    u32 cnt;
    u32 v;

    cnt = 1;
    buf[0] = 1;
    if (func_021D5B68(func_021B9C00(g->list, (u8)func_021B9AB0(2))) == 0) {
        buf[cnt++] = 2;
    }
    if (func_021D5B68(func_021B9C00(g->list, (u8)func_021B9AB0(3))) == 0) {
        buf[cnt++] = 3;
    }
    if (cnt > 1) {
        g->seed = g->mul * g->seed + g->add;
        if (cnt == 0) {
            v = (u32)(g->seed >> 32);
        } else {
            v = (u32)(((g->seed >> 32) * (u32)cnt) >> 32);
        }
        return buf[v];
    }
    return 1;
}




/*
 * lever: nested one-word aggregate return removes its extra frame word;
 *   named count/bytes reproduce original final read/store order. Three
 *   iteration runs, two scheduling variants; no prior compiles.
 * semantic: state/cursor arithmetic is unsigned; byte counters promote
 *   safely and narrow on store. CF81C writes all four availability bytes
 *   before return; CFBF0 writes the single output byte on every nonzero
 *   return path. Full-width pointer payloads retain their original bits.
 */
int func_021D0770(u8 *p, u32 *state)
{
    u8 available[4];
    u8 choice;
    u32 move;
    u32 slot;
    u32 sub;
    u32 result;
    u32 count;
    u32 bytes;
    switch (*state) {
    case 0:
        func_021CFBA4((s8 *)p);
        p[0x11d] = 0;
        p[0x1af] = 0;
        *state = 1;
    case 1:
        if (p[0x11d] >= p[0x11c]) break;
        M = func_021B9C00(((struct Obj00464 *)p)->f118, p[0x11d]);
        R = p+0x124+p[0x11d]*4;
        if (func_021D5B68(M)) {
            func_021D8434((u32 *)R);
            goto complete;
        }
        if (func_021CF470(p,M,R)) goto complete;
        move = func_021D3DC4(p,M,((struct Obj00464 *)p)->f118);
        if (move) {
            func_021D8358((u32 *)R,move,p[0x11d],0);
            goto complete;
        }
        if (func_021B86B8(*(void *** *)&((struct Obj00464 *)p)->f0) && func_021CFBF0(p,M,p[0x11d],&choice)) {
            func_021D8394(R,p[0x11d],choice);
            goto complete;
        }
        if (func_021B8588(((struct Obj00464 *)p)->f0) == 3) {
            slot = func_021D06C8((struct G *)p);
            if (slot != 1) {
                sub = func_021B9AB0(slot);
                func_021D83FC((u32 *)R,slot);
                M = func_021B9C00(((struct Obj00464 *)p)->f118,sub);
                p[0x1af] = 1;
                R = (u8 *)((u32)R+4U);
            }
        }
        if (func_021D62C4(M,0x19)) {
            move = func_021E8B80(func_021D6314(M,0x19));
            result = func_021D81F8(((struct Obj00464 *)p)->f0,((struct Obj00464 *)p)->f4,M,move,p+0xf4);
            func_021D82D0((struct Unk021D82D0 *)R,move,result);
            goto complete;
        }
        if (func_021CF524((u32)p,M,(u32)R)) *state = 3;
        func_021D5448(M);
        slot = func_021CF81C(p,M,available);
        if (slot != 4) {
            result = func_021B8D8C(((struct Obj00464 *)p)->f0,((struct Obj00464 *)p)->f4,func_021D5440(M));
            func_021880BC(*(int *)&((struct Obj00464 *)p)->fF0,available,result);
            *state = 2;
        } else {
            func_021CF58C((struct Unk021D82D0 *)((u32)R),(u8 *)((u32)p),M);
            goto complete;
        }
        break;
    case 2:
        if (func_02187FB0(*(u8 * *)&((struct Obj00464 *)p)->fF0)) break;
        slot = func_02188134(*(u8 * *)&((struct Obj00464 *)p)->fF0);
        if (slot != 4) {
            sub = func_02188140(*(u8 * *)&((struct Obj00464 *)p)->fF0);
            move = func_021D54C0(M,slot);
            func_021D82D0((struct Unk021D82D0 *)R,move,sub);
        } else func_021D8414((u32 *)R);
complete:
        *state = 3;
        break;
    case 3:
        p[0x11d]++;
        count = p[0x11c];
        if (p[0x11d] >= count) {
            bytes = (count+p[0x1af])*4;
            *(u8 * *)&((struct Obj00464 *)p)->fD8 = p+0x124;
            ((struct Obj00464 *)p)->fDC = bytes;
            p[0x1af] = 0;
            return 1;
        }
        *state = 1;
        break;
    }
    return 0;
}





u8 func_021D0980(u8 *g, u8 *out)
{
    u32 n;
    u8 c;
    u32 i;

    n = func_021B9B94(((struct Obj00489 *)g)->f118);
    i = func_021D7F2C(func_021B8588(((struct Obj00489 *)g)->f0), g[0x11c]);
    c = 0;
    for (; i < n; i = (u8)(i + 1)) {
        if (func_021D5B7C(func_021B9C00(((struct Obj00489 *)g)->f118, i))) {
            if (out)
                out[c] = i;
            c = (u8)(c + 1);
        }
    }
    return c;
}


/*
 * pass 6 2026-10-06 P6L01: EXACT* (302 B code plus 2 B pad), also EXACT* under -lang c99. The
 * closing change is u16 type with func_021D799C declared (int, u16). The callee
 * (ov093_func_021D799C.c) also matches EXACT with a u16 second parameter, so the prototype is consistent.
 * Why it closes (seen in a debugger capture of the post-RA scheduler of mwccarm): a word-sized spill of a
 * narrow variable gets the "narrow locals" alias set. With int type, the type store after the call
 * has its own alias, so the count home store has a height of 6 and 'adds r0,r3' (height 7) goes before
 * it. With u16 type (no int conversion, so no hoisted int temp), the type store is in the same set, the
 * count store gets an edge to it (height 7), and it issues second, as in the original. Passes 1 to 5
 * (all 5 B or more) tried every source shape of the entry block; none can change this edge.
 */
void func_021D09E0(u8 *p, u8 *order, u8 count, void *target)
{
    u16 scores[6];
    u16 type;
    u8 i;
    u8 j;
    void *mon;
    u16 move;
    u16 power;
    u16 temp;
    u8 tempid;
    type = func_021D57FC(target);
    for (i = 0; i < count; i++) {
        scores[i] = 0;
        mon = func_021B9C00(*(void **)(p + 0x118), order[i]);
        if (!func_021D5B68(mon)) {
            u8 n;
            n = func_021D5448(mon);
            for (j = 0; j < n; j++) {
                if (func_021D5584(mon, j)) {
                    move = func_021D54C0(mon, j);
                    if (func_0201C314((void *)(u32)move)) {
                        int kind;
                        kind = func_0201C1C8((void *)(u32)move);
                        power = func_0201C1D8((void *)(u32)move);
                        if (power < 10) power = 60;
                        switch (func_021D799C(kind, type)) {
                        case 5: power *= 4; break;
                        case 4: power *= 2; break;
                        case 2: power /= 2; break;
                        case 1: power /= 4; break;
                        case 0: power = 0; break;
                        case 3: break;
                        }
                        if (scores[i] < power) scores[i] = power;
                    }
                }
            }
        }
    }
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            if (scores[i] < scores[j]) {
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
                tempid = order[i];
                order[i] = order[j];
                order[j] = tempid;
            }
        }
    }
}


void func_021D0B10(u8 *p, u32 a, u32 b, void *q, void *out)
{
    func_021D0B3C(q, ((struct Obj13364 *)p)->f118, b, a);
    func_021D0B4C(q, p[0x11c]);
    func_021D0B5C(out, q);
}
