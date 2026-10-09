/*
 * file:     btl_server_p71.c
 * unit:     yes
 * function: func_021C5BE4, func_021C5C1C, func_021C5C74, func_021C5D88, func_021C5DAC, func_021C5E48, func_021C5EFC, func_021C5F98, func_021C604C, func_021C6080, func_021C60D4, func_021C60EC, func_021C6110, func_021C6134, func_021C6158, func_021C6190, func_021C62D8, func_021C6350, func_021C6394, func_021C63D0, func_021C6458, func_021C64B4, func_021C6564, func_021C65A8
 * address:  0x021C5BE4
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
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D5FB8 0x021D5FB8 thumb ov093
 *   func_021D6034  0x021D6034  thumb  ov093
 *   func_021E8A78  0x021E8A78  thumb  ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021B911C 0x021B911C thumb ov093
 *   func_021D5F90 0x021D5F90 thumb ov093
 *   func_021D56A0  0x021D56A0  thumb  ov093
 *   func_021D5674  0x021D5674  thumb  ov093
 *   func_021D5FE4 0x021D5FE4 thumb ov093
 *   func_021D6008 0x021D6008 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B9D10 0x021B9D10 thumb ov093
 *   func_021E02DC 0x021E02DC thumb ov093
 *   func_021E03D8 0x021E03D8 thumb ov093
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7A44  0x021D7A44  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021C1678  0x021C1678  thumb  ov093
 *   func_021C5540  0x021C5540  thumb  ov093
 *   func_021C16F8  0x021C16F8  thumb  ov093
 *   func_021C8810  0x021C8810  thumb  ov093
 *   sub_0201C1C8   0x0201C1C8  thumb
 *   sub_0201C1E8   0x0201C1E8  thumb
 *   sub_0201BD28   0x0201BD28  thumb
 *   func_021D57FC  0x021D57FC  thumb  ov093
 *   func_021C6648  0x021C6648  thumb  ov093
 *   func_021C6658  0x021C6658  thumb  ov093
 */
#include "../../matched/include/Obj13336.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj01688.h"
#include "../../matched/include/Obj09972.h"
#include "../../matched/include/Obj21104.h"

#define OBJECT(i) (*(u8 **)((u32)p + (i) * 16 + 0x7e0))
#define SKIP(i) p[(i) * 16 + 0x7ed]
#define FLAG(i) p[(i) * 16 + 0x7ee]
struct UtilWork;
struct Arr;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { int x; } S;

typedef struct { u8 *p; u32 type:4; u32 pad:3; u32 key:16; u32 rest:9; u8 bytes[5]; u8 skip; u8 flag; u8 unused; } Entry;

struct O { u16 h; u8 b; };

struct Out64B4 {
    u16 h0;
    u16 h2;
    u16 h4;
    u8 b6;
    u8 pad7;
    u32 w8;
    u32 wC;
    u32 w10;
};

extern u8 func_021D5440(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021D59B4(u8 *p, int k);
extern void func_021D5FB8(u8 *);
extern void func_021D6034(u8 *a, int k, S s);
extern int func_021E8A78(S s);
extern void func_021CD64C(void *, u8, ...);
extern int func_021B911C(void *, int);
extern void func_021D5F90(u8 *, u16);
extern void func_021D56A0(u8 *a, int b, int c);
extern void func_021D5674(u8 *a, int b, int c);
extern void func_021D5FE4(u8 *p, unsigned int n);
extern void func_021D6008(u8 *, unsigned int);
extern void func_021D5FC0(struct UtilWork *, unsigned int);
extern char *func_021B9AEC(char *p, int i);
extern void func_021B9D10(char *, struct Arr *, int);
extern int func_021E02DC(u8 *, u16, u32);
extern void func_021E03D8(u8 *a, int b);
extern void func_021D74F8(int);
extern void func_021D75EC(int, u32);
extern void func_021D70F0(void *a, int id);
extern void func_021D7540(int);
extern void func_021D75A8(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern int func_021D775C(int key);
extern u32 func_021D7A44(u32 a, u32 b, u32 c, u32 d);
extern u32 func_021D78AC(u32 range);
extern u32 _u32_div_f(u32, u32);
extern int func_021C1678(u8 *p, u8 *a, u8 *b, u32 c, u16 *d);
extern void func_021C5540(u8 *p, u8 *a, int c);
extern void func_021C16F8(u8 *p, u8 *q, int v);
extern void func_021C8810(u8 *p);
extern u8 sub_0201C1C8(void *p);
extern int sub_0201C1E8(int a);
extern u32 sub_0201BD28(u16 id, u32 field);
extern u16 func_021D57FC(void *p);
extern u32 func_021C6648(u8 *d);
extern u8 *func_021C6658(u8 *d, u32 i);
void func_021C5BE4(u8 *p, u8 *a, int c);
void func_021C5C1C(u8 *p, u8 *a, int k, S s);
void func_021C5C74(u8 *p, u8 *a, int kind, u32 v);
void func_021C5D88(u8 *p, u8 *a, int b);
void func_021C5DAC(u8 *p, u32 a, int n, const int *v);
void func_021C5E48(u8 *p, u32 a, u32 b, int n, int *v);
void func_021C5EFC(u8 *p, u32 a, int n, const int *v);
void func_021C5F98(u8 *p, u32 a, u32 b, int n, int *v);
void func_021C604C(u8 *p, u8 *a, int n);
void func_021C6080(u8 *p, u8 *a, int b, int c, int d);
void func_021C60D4(u8 *p, u8 *a);
void func_021C60EC(u8 *p, u8 *a, u32 n);
void func_021C6110(u8 *p, u8 *a, unsigned int n);
void func_021C6134(u8 *p, u8 *a, unsigned int n);
void func_021C6158(u8 *p, u8 *a);
int func_021C6190(u8 *p, u8 *a);
int func_021C62D8(u8 *p, u8 *a, u32 unused, u32 c, struct O *out);
u8 func_021C6350(u8 *p, u8 *a);
void func_021C6394(u8 *p, u8 *a, unsigned int n);
u32 func_021C63D0(u8 *p, u8 *q);
int func_021C6458(u8 *p, u8 *a, u32 c, u32 d, u8 *e);
void func_021C64B4(u8 *p, u16 q, u8 *a, struct Out64B4 *out);
void func_021C6564(u8 *p, u8 *a, u32 c, u32 d);
int func_021C65A8(u8 *p, u8 *a, u32 e, u8 *d);



void func_021C5BE4(u8 *p, u8 *a, int c)
{
    int n;
    func_021D59B4(a, 13);
    n = func_021D5440(a);
    func_021D5FB8(a);
    func_021CD4B0(((struct Obj13336 *)p)->fC, 3, n);
    func_021CD4B0(((struct Obj13336 *)p)->fC, 0x43, n, c);
}




void func_021C5C1C(u8 *p, u8 *a, int k, S s)
{
    u8 n = func_021D5440(a);
    func_021D6034(a, k, s);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0xf, n, (u8)k, s.x);
    if (k < 6) {
        if (k == 5 && func_021E8A78(s)) k = 6;
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x35, n, k);
    }
}



void func_021C5C74(u8 *p, u8 *a, int kind, u32 v)
{
    u8 n = func_021D5440(a);
    switch (kind) {
    case 1:
        switch (v) {
        case 5: func_021CD64C(((struct Obj01688 *)p)->fC, 0x5b, 0xf9, n, 0xffff0000); break;
        case 4: func_021CD64C(((struct Obj01688 *)p)->fC, 0x5b, 0x10b, n, 0xffff0000); break;
        case 1: func_021CD64C(((struct Obj01688 *)p)->fC, 0x5b, 0x11a, n, 0xffff0000); break;
        case 2: func_021CD64C(((struct Obj01688 *)p)->fC, 0x5b, 0x13b, n, 0xffff0000); break;
        case 3: func_021CD64C(((struct Obj01688 *)p)->fC, 0x5b, 0x129, n, 0xffff0000); break;
        case 6: func_021CD64C(((struct Obj01688 *)p)->fC, 0x5b, 0x162, n, 0xffff0000); break;
        case 15: func_021CD64C(((struct Obj01688 *)p)->fC, 0x5b, 0x18, n, 0xffff0000); break;
        case 20: return;
        default: func_021CD64C(((struct Obj01688 *)p)->fC, 0x5a, 0x47, 0xffff0000); break;
        }
        p[0x78a] |= 0x10;
        break;
    case 2:
        func_021CD64C(((struct Obj01688 *)p)->fC, 0x5b, 0xd2, n, 0xffff0000);
        p[0x78a] |= 0x10;
        break;
    default:
        func_021CD64C(((struct Obj01688 *)p)->fC, 0x5a, 0x47, 0xffff0000);
        p[0x78a] |= 0x10;
        break;
    }
}




void func_021C5D88(u8 *p, u8 *a, int b)
{
    func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, b, func_021D5440(a), 0xffff0000);
}




void func_021C5DAC(u8 *p, u32 a, int n, const int *v)
{
    switch (n) {
    default:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, a, 0xffff0000);
        break;
    case 1:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, a, v[0], 0xffff0000);
        break;
    case 2:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, a, v[0], v[1], 0xffff0000);
        break;
    case 3:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, a, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5a, a, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}




void func_021C5E48(u8 *p, u32 a, u32 b, int n, int *v)
{
    switch (n) {
    default:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5c, a, b, 0xffff0000);
        break;
    case 1:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5c, a, b, v[0], 0xffff0000);
        break;
    case 2:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5c, a, b, v[0], v[1], 0xffff0000);
        break;
    case 3:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5c, a, b, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5c, a, b, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}




void func_021C5EFC(u8 *p, u32 a, int n, const int *v)
{
    switch (n) {
    default:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, a, 0xffff0000);
        break;
    case 1:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, a, v[0], 0xffff0000);
        break;
    case 2:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, a, v[0], v[1], 0xffff0000);
        break;
    case 3:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, a, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, a, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}




void func_021C5F98(u8 *p, u32 a, u32 b, int n, int *v)
{
    switch (n) {
    default:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5d, a, b, 0xffff0000);
        break;
    case 1:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5d, a, b, v[0], 0xffff0000);
        break;
    case 2:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5d, a, b, v[0], v[1], 0xffff0000);
        break;
    case 3:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5d, a, b, v[0], v[1], v[2], 0xffff0000);
        break;
    case 4:
        func_021CD64C(((struct Obj00003 *)p)->fC, 0x5d, a, b, v[0], v[1], v[2], v[3], 0xffff0000);
        break;
    }
}



void func_021C604C(u8 *p, u8 *a, int n)
{
    if (func_021B911C(((struct Obj00003 *)p)->f4, 4) == 0) {
        func_021D5F90(a, n);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 1, func_021D5440(a), (u16)n);
    }
}




void func_021C6080(u8 *p, u8 *a, int b, int c, int d)
{
    u8 n = func_021D5440(a);
    if (d) {
        func_021D56A0(a, b, c);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 8, n, b, c);
    } else {
        func_021D5674(a, b, c);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 7, n, b, c);
    }
}



void func_021C60D4(u8 *p, u8 *a)
{
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x42, func_021D5440(a));
}



void func_021C60EC(u8 *p, u8 *a, u32 n)
{
    func_021D5FE4(a, n);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x19, func_021D5440(a), n);
}



void func_021C6110(u8 *p, u8 *a, unsigned int n)
{
    func_021D6008(a, n);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x1a, func_021D5440(a), n);
}



void func_021C6134(u8 *p, u8 *a, unsigned int n)
{
    func_021D5FC0((struct UtilWork *)a, n);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x1b, func_021D5440(a), n);
}



void func_021C6158(u8 *p, u8 *a)
{
    unsigned int i;
    struct Arr *arr;
    for (i = 0; i < a[0]; i++) {
        arr = (struct Arr *)func_021B9AEC(*(char * *)&((struct Obj09972 *)p)->f8, a[i + 1]);
        func_021CD4B0(((struct Obj09972 *)p)->fC, 0x2a, a[i + 1]);
        func_021B9D10(*(char * *)&((struct Obj09972 *)p)->f4, arr, a[i + 1]);
    }
}



static inline u16 entry_key(Entry *e)
{
    if (e->type == 1) return e->key;
    return 0;
}



int func_021C6190(u8 *p, u8 *a)
{
    u32 i;
    for (i = 0; i < p[0x782]; i++) {
        u16 key;
        if (OBJECT(i) == a) continue;
        if (SKIP(i)) continue;
        key = entry_key((Entry *)(p + 0x7e0) + i);
        if (key == 228) {
            if (func_021E02DC(OBJECT(i), key, func_021D59B4(OBJECT(i), 12)))
                FLAG(i) = 1;
        }
    }
    p[0x788] = 0;
    func_021D74F8(11288);
    func_021D75EC(6, func_021D5440(a));
    func_021D70F0(p, 0x53);
    func_021D7540(11291);
    for (i = 0; i < p[0x782]; i++) {
        u16 key;
        if (FLAG(i)) {
            key = entry_key((Entry *)(p + 0x7e0) + i);
            if (key == 228) func_021E03D8(*(u8 **)(p + i * 16 + 0x7e0), key);
            FLAG(i) = 0;
        }
    }
    return p[0x788];
}



int func_021C62D8(u8 *p, u8 *a, u32 unused, u32 c, struct O *out)
{
    int t;
    int line = 11327;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0xE, c);
    func_021D75A8(0x12, 0);
    func_021D75A8(0xD, 6);
    func_021D7630(0x41, 0);
    func_021D70F0(p, 0x18);
    out->h = func_021D775C(0x12);
    out->b = func_021D775C(0xD);
    t = func_021D775C(0x41);
    func_021D7540(line + 13);
    return t == 0;
}



u8 func_021C6350(u8 *p, u8 *a)
{
    u8 r;
    func_021D74F8(11357);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x11, 1);
    func_021D70F0(p, 0xF);
    r = func_021D775C(0x11);
    func_021D7540(11362);
    return r;
}


void func_021C6394(u8 *p, u8 *a, unsigned int n)
{
    func_021D74F8(11378);
    func_021D75A8(2, func_021D5440(a));
    func_021D75A8(0x12, n);
    func_021D70F0(p, 0x15);
    func_021D7540(11382);
}



u32 func_021C63D0(u8 *p, u8 *q)
{
    u16 dmg;
    int r;
    int a = func_021D59B4(q, 8);
    int b = func_021D59B4(q, 9);
    int c = func_021D59B4(q, 0xF);

    dmg = func_021D7A44(0x28, a, c, b);
    dmg = _u32_div_f((100 - func_021D78AC(16)) * dmg, 100);
    if (dmg == 0) {
        dmg = 1;
    }
    r = func_021C1678(p, q, q, 0, &dmg);
    func_021C5540(p, q, dmg);
    if (r != 0) {
        func_021C16F8(p, q, r);
    }
    return dmg;
}



int func_021C6458(u8 *p, u8 *a, u32 c, u32 d, u8 *e)
{
    int r;
    int line = 11440;
    func_021C8810(e);
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x12, d);
    func_021D75EC(0x3F, (u32)e);
    func_021D7630(0x51, 0);
    func_021D70F0(p, 0x19);
    r = func_021D775C(0x51);
    func_021D7540(line + 7);
    return r;
}



/*
 * Byte-correct except the call to the unlabelled arm9 leaf 0x0201C1E8,
 * which has no witness outside this function (evidence class: none until the
 * leaf is filed; it is Ilias's, inside a labelled arm9 region). Verified C for
 * that leaf (`one` --thumb, no --region, EXACT, 12 bytes):
 *
 *   extern u32 sub_0201BD28(void *p, u32 id);   // symbols: sub_0201BD28 0x0201BD28 thumb
 *   u32 sub_0201C1E8(void *p) { return sub_0201BD28(p, 2); }
 *
 * Once the leaf's shard exists re-run this file; it should go EXACT.
 */
void func_021C64B4(u8 *p, u16 q, u8 *a, struct Out64B4 *out)
{
    int line = 11464;
    func_021D74F8(line);
    func_021D75EC(2, func_021D5440(a));
    func_021D7630(0x16, sub_0201C1C8((void *)q));
    func_021D75A8(0x1C, func_021D57FC(a));
    func_021D75A8(0x1A, sub_0201C1E8(q));
    func_021D75A8(0x1B, sub_0201BD28(q, 0x1B));
    func_021D7630(0x4B, 0);
    func_021D70F0(p, 0x28);
    out->h0 = q;
    out->h2 = q;
    out->b6 = func_021D775C(0x16);
    out->h4 = func_021D775C(0x1C);
    out->w8 = func_021D775C(0x1A);
    out->wC = func_021D775C(0x1B);
    out->w10 = 0;
    if (func_021D775C(0x4B) != 0) {
        out->b6 = 0x11;
    }
    func_021D7540(11493);
}



void func_021C6564(u8 *p, u8 *a, u32 c, u32 d)
{
    func_021D74F8(11508);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x12, c);
    func_021D75EC(0x22, d);
    func_021D70F0(p, 0x21);
    func_021D7540(11513);
}



int func_021C65A8(u8 *p, u8 *a, u32 e, u8 *d)
{
    u32 n;
    u32 i;
    int r;
    u16 t;
    n = func_021C6648(d);
    func_021D74F8(11533);
    func_021D75EC(2, func_021D5440(a));
    func_021D75EC(0x12, e);
    func_021D75EC(5, n);
    for (i = 0; i < n; i++) {
        func_021D75EC(i + 6, func_021D5440(func_021C6658(d, i)));
    }
    func_021D7630(0x3E, 0);
    func_021D7630(0x13, 0);
    func_021D70F0(p, 0x24);
    r = func_021D775C(0x3E);
    t = func_021D775C(0x13);
    func_021D7540(11550);
    if (t != 0) {
        **(u16 * *)&((struct Obj21104 *)p)->f4A8 = t;
    }
    return r;
}
