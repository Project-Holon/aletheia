/*
 * file:     tr_ai_p05.c
 * unit:     yes
 * function: func_02188A74, func_02188A84, func_02188A94, func_02188AA4, func_02188AB4, func_02188AD8, func_02188AE8, func_02188AF8, func_02188B1C
 * address:  0x02188A74
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
 *   func_0218A0F4 0x0218A0F4 thumb ov096
 *   func_020113B0  0x020113B0  thumb
 */
#include "../../matched/include/Obj21937.h"
#include "../../matched/include/Obj21938.h"
#include "../../matched/include/Obj21939.h"
#include "../../matched/include/Obj21940.h"
#include "../../matched/include/Obj21941.h"
#include "../../matched/include/Obj21942.h"
#include "../../matched/include/Obj21943.h"
#include "../../matched/include/Obj21944.h"
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj13651.h"

struct Cursor;
struct Cur;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern unsigned int func_0201134C(struct Cursor *);
extern int func_0218A0F4(unsigned char *,int,int,int,int);
extern void func_020113B0(struct Cur *c, u32 v);
int func_02188A74(int a, int b);
int func_02188A84(int a, int b);
int func_02188A94(int a, int b);
int func_02188AA4(int a, int b);
int func_02188AB4(struct Cursor *a, unsigned char *b, int c);
int func_02188AD8(void *a, unsigned char *b);
int func_02188AE8(void *a, unsigned char *b);
int func_02188AF8(struct Cursor *a, unsigned char *b, int c);
int func_02188B1C(struct Cursor *a, int b);

int func_02188A74(int a, int b)
{
    func_02188AB4((struct Cursor *)a, (unsigned char *)b, 2);
    return ((struct Obj21937 *)b)->fC4;
}

int func_02188A84(int a, int b)
{
    func_02188AB4((struct Cursor *)a, (unsigned char *)b, 3);
    return ((struct Obj21938 *)b)->fC4;
}

int func_02188A94(int a, int b)
{
    func_02188AB4((struct Cursor *)a, (unsigned char *)b, 4);
    return ((struct Obj21939 *)b)->fC4;
}

int func_02188AA4(int a, int b)
{
    func_02188AB4((struct Cursor *)a, (unsigned char *)b, 5);
    return ((struct Obj21940 *)b)->fC4;
}

int func_02188AB4(struct Cursor *a, unsigned char *b, int c) { int x,y; x=func_0201134C(a); y=func_0201134C(a); return func_0218A0F4((unsigned char *)a,c,((struct Obj21941 *)b)->f38,x,y); }

int func_02188AD8(void *a, unsigned char *b) { func_02188AF8(a,b,2); return ((struct Obj21942 *)b)->fC4; }

int func_02188AE8(void *a, unsigned char *b) { func_02188AF8(a,b,3); return ((struct Obj21943 *)b)->fC4; }

int func_02188AF8(struct Cursor *a, unsigned char *b, int c) { int x,y; x=func_0201134C(a); y=func_0201134C(a); return func_0218A0F4((unsigned char *)a,c,((struct Obj21944 *)b)->f2,x,y); }


int func_02188B1C(struct Cursor *a, int b)
{
    u16 *p;
    int m;
    int i;
    int v;

    p = (u16 *)(*(int *)&((struct Obj00005 *)a)->f14 + func_0201134C(a));
    m = func_0201134C(a);
    i = 0;
    do {
        v = p[i] | (p[i + 1] << 16);
        if (((struct Obj13651 *)b)->f38 == v) {
            func_020113B0((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + m);
            break;
        }
        i += 2;
    } while (v != -1);
    return ((struct Obj13651 *)b)->fC4;
}
