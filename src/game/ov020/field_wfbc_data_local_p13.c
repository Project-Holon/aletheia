/*
 * file:     field_wfbc_data_local_p13.c
 * unit:     yes
 * function: func_021875B8, func_021875F4, func_02187684, func_0218768C
 * address:  0x021875B8
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021912F8 0x021912F8 thumb ov021
 *   func_0219131C 0x0219131C thumb ov021
 *   func_021909BC 0x021909BC thumb ov021
 *   func_02030734  0x02030734  arm
 *   func_0216FC4C  0x0216FC4C  thumb  ov010
 *   func_0216FAB4  0x0216FAB4  thumb  ov010
 *   d_02187EDC     0x02187EDC  data  ov020  a4
 *   func_020307B0 0x020307B0 arm
 *   func_021876B0 0x021876B0 thumb ov020
 */
#include "../../matched/include/Obj00128.h"
#include "../../matched/include/Obj02070.h"
#include "../../matched/include/Obj07404.h"

struct TexKey;
typedef unsigned short u16;

typedef unsigned int   u32;

struct P {
    u16 a;
    u16 x0;
    u16 b;
    u16 x1;
    u16 c;
    u16 x2;
};

struct L {
    u16 a;
    u16 b;
    int c;
    int d;
    int e;
    int f;
};

typedef struct { int index; char *base; } Pair;

extern int func_021912F8(void *p);
extern int func_0219131C(unsigned int a);
extern int func_021909BC(void *a);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern int func_0216FC4C(void);
extern int func_0216FAB4(void *file, const char *texName, void *extra, const char *plttName, u32 a4, u16 a5, u16 a6, u16 a7, u16 heap, struct TexKey *out);
extern u32 func_020307B0(void *p);
extern void func_021876B0(Pair *p, int tick);
int func_021875B8(char *p);
int *func_021875F4(int a0, int a1, int a2, int a3, struct P e);
void func_02187684(void *p);
void func_0218768C(char *p);
extern int d_02187EDC;

/*
 * lever: duplicate the zero store in both arms to retain the original branch stub.
 * regargs: high r2/r3 rows are conservative SDK-depth flags in owner callee 0219131C.
 * interface: 0219131C forwards them to 02045808 -> 020307B0 only; 0203046C
 * overwrites r2/r3, while 02030164's 0202FBAC overwrites r2 and no path reads incoming r3.
 */
int func_021875B8(char *p)
{
    if (((struct Obj00128 *)p)->f10 != 0) {
        if (((struct Obj00128 *)p)->f52 == 5) {
            if (func_021912F8(((struct Obj00128 *)p)->f10) == 0) return 0;
            ((struct Obj00128 *)p)->f10 = 0;
        } else {
            func_0219131C((unsigned int)(((struct Obj00128 *)p)->f10));
            ((struct Obj00128 *)p)->f10 = 0;
        }
    }
    if (((struct Obj00128 *)p)->f14 != 0) {
        func_021909BC((void *)(((struct Obj00128 *)p)->f14));
        ((struct Obj00128 *)p)->f14 = 0;
    }
    return 1;
}


int *func_021875F4(int a0, int a1, int a2, int a3, struct P e)
{
    struct L l;
    int *p;

    p = func_02030734(((u16 *)&e)[4], 0x1c, 1, (const char *)&d_02187EDC, 0x19c);
    p[0] = 0;
    ((struct Obj02070 *)p)->f4 = func_0216FC4C() - 1;
    ((struct Obj02070 *)p)->f6 = func_0216FC4C() - 1;
    p[4] = -1;
    p[5] = -1;
    if (func_0216FAB4((void *)a0, (const char *)a1, 0, (const char *)a2, a3, ((u16 *)&e)[0], ((u16 *)&e)[2], 0xC40, ((u16 *)&e)[4], (struct TexKey *)(&l)) != 0) {
        p[2] = l.c;
        p[3] = l.d;
        p[4] = l.e;
        ((struct Obj02070 *)p)->f4 = l.a;
        ((struct Obj02070 *)p)->f6 = l.b;
        p[5] = l.f;
        p[6] = 0;
    }
    return p;
}

void func_02187684(void *p) { func_020307B0(p); }

/*
 * lever: capture the base in a local before filling the stack pair, preserving the original r3 load.
 */
void func_0218768C(char *p)
{
    Pair pair;
    char *base;
    (((struct Obj07404 *)p)->f18)++;
    base = *(char * *)&((struct Obj07404 *)p)->f14;
    if (base != (char *)-1) {
        pair.index = ((struct Obj07404 *)p)->fC;
        pair.base = base;
        func_021876B0(&pair, ((struct Obj07404 *)p)->f18);
    }
}
