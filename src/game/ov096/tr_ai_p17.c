/*
 * file:     tr_ai_p17.c
 * unit:     yes
 * function: func_02189ED0, func_02189EF8, func_02189F34, func_02189F58, func_02189F68, func_02189F78, func_02189F88, func_02189F98, func_02189FC0
 * address:  0x02189ED0
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
 *   func_0201134C 0x0201134C thumb
 *   func_0218A160 0x0218A160 thumb ov096
 *   func_0218A2FC 0x0218A2FC thumb ov096
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_020113B0 0x020113B0 thumb
 *   func_021D6D7C 0x021D6D7C thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_0218A0F4 0x0218A0F4 thumb ov096
 *   func_021895AC  0x021895AC  thumb  ov096
 *   func_0218A378  0x0218A378  thumb  ov096
 */
#include "../../matched/include/Obj13667.h"
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj21978.h"
#include "../../matched/include/Obj13668.h"
#include "../../matched/include/Obj21979.h"
#include "../../matched/include/Obj21980.h"
#include "../../matched/include/Obj21981.h"
#include "../../matched/include/Obj21982.h"
#include "../../matched/include/Obj21983.h"
#include "../../matched/include/Obj13669.h"

struct Cursor;
struct Cur;
struct QF;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern u32 func_0201134C(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_021D59B4(u8 *p, int k);
extern void func_020113B0(struct Cur *c, u32 v);
extern u32 func_021D6D7C(u8 *p);
extern u16 func_021D5444(struct QF *p);
extern int func_0218A0F4(unsigned char *, int, int, int, int);
extern int func_021895AC(u8 *, u8 *);
extern int func_0218A378(u8 *, int, int);
int func_02189ED0(struct Cursor *a, u8 *b);
int func_02189EF8(struct Cursor *a, u8 *b);
int func_02189F34(struct Cursor *a, u8 *b);
int func_02189F58(u8 *a, u8 *b);
int func_02189F68(unsigned char *a, unsigned char *b);
int func_02189F78(unsigned char *a, unsigned char *b);
int func_02189F88(unsigned char *a, unsigned char *b);
int func_02189F98(unsigned char *a, unsigned char *b, int c);
int func_02189FC0(struct Cursor *a, u8 *b);

int func_02189ED0(struct Cursor *a, u8 *b)
{
    int t; u8 s; t = func_0201134C(a); s = func_0218A160(b,t); ((struct Obj13667 *)b)->f38 = func_021D59B4(func_0218A2FC(b,s),17); return ((struct Obj13667 *)b)->fC4;
}

int func_02189EF8(struct Cursor *a, u8 *b)
{
    int t; u32 n; u8 s; t = func_0201134C(a); n = func_0201134C(a); s = func_0218A160(b,t); if (func_021D6D7C(func_0218A2FC(b,s))) func_020113B0((struct Cur *)a, *(u32 *)&((struct Obj00005 *)a)->f14 + n); return ((struct Obj21978 *)b)->fC4;
}

int func_02189F34(struct Cursor *a, u8 *b)
{
    int t; u8 s; t = func_0201134C(a); s = func_0218A160(b,t); ((struct Obj13668 *)b)->f38 = func_021D5444((struct QF *)func_0218A2FC(b,s)); return ((struct Obj13668 *)b)->fC4;
}

int func_02189F58(u8 *a, u8 *b)
{
    func_02189F98(a,b,0); return ((struct Obj21979 *)b)->fC4;
}

int func_02189F68(unsigned char *a, unsigned char *b) { func_02189F98(a,b,1); return ((struct Obj21980 *)b)->fC4; }

int func_02189F78(unsigned char *a, unsigned char *b) { func_02189F98(a,b,2); return ((struct Obj21981 *)b)->fC4; }

int func_02189F88(unsigned char *a, unsigned char *b) { func_02189F98(a,b,3); return ((struct Obj21982 *)b)->fC4; }

/*
 * Two-byte zero alignment padding follows the compiled function.
 */
int func_02189F98(unsigned char *a, unsigned char *b, int c) { int x,y; x=func_0201134C((struct Cursor *)a); y=func_0201134C((struct Cursor *)a); return func_0218A0F4(a,c,((struct Obj21983 *)b)->fCC,x,y); }


int func_02189FC0(struct Cursor *a, u8 *b)
{
    int t;
    int u;
    int w;
    u16 *base;
    int m;
    int flag;
    t = func_0201134C(a);
    u = func_0201134C(a);
    w = func_0201134C(a);
    base = (u16 *)(*(u8 * *)&((struct Obj00005 *)a)->f14 + w);
    flag = 0;
    if (t == 0) {
        m = func_0218A378(b, ((struct Obj13669 *)b)->f2, 0x1c) * 2;
        if (m / 2 > u)
            flag = 1;
    } else {
        flag = 1;
    }
    if (flag == 1)
        return func_021895AC((u8 *)a, b);
    func_020113B0((struct Cur *)a, (u32)((u8 *)base + (base[m] | (base[m + 1] << 16))));
    return ((struct Obj13669 *)b)->fC4;
}
