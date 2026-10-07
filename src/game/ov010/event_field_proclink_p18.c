/*
 * file:     event_field_proclink_p18.c
 * unit:     yes
 * function: func_02160D6C, func_02160DDC
 * address:  0x02160D6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_02172978     0x02172978  data  a1
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02012134  0x02012134  thumb
 *   func_02029DBC  0x02029DBC  thumb
 *   func_02029DD8 0x02029DD8 thumb
 */
#include "../../matched/include/Obj12324.h"

struct Ctx;
struct BigObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct T { void *a; void *b; u8 *c; u16 h; } T;

typedef enum { FALSE = 0, TRUE = 1 } BOOL;

extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC();
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0200CA1C(void *a);
extern u8 *func_02012944(void *p);
extern u32 func_02012A30(const struct BigObj *p);
extern u32 func_02012134(u32 *p);
extern void func_02029DBC(u8 *a, u32 b);
extern int func_02029DD8(int,int);
T *func_02160D6C(int *a0, int a1);
BOOL func_02160DDC(u32 *a, u8 *b);
extern u8 d_02172978[];


T *func_02160D6C(int *a0, int a1)
{
    T *p;
    void *sys;
    int s;

    p = func_02030734(4, 0x10, 0, (const char *)d_02172978, 0x49b);
    func_02082BCC(p, 0, 0x10);
    sys = func_020120F4((const struct Ctx *)*(int *)a0[6]);
    p->a = sys;
    p->b = func_0200CA1C(sys);
    p->c = func_02012944(p->a);
    s = func_02012A30(p->a);
    func_02029DBC((u8 *)s, func_02012134((u32 *)(*(int *)a0[6])));
    if (a1 != -1) {
        p->h = a1;
    } else {
        p->h = 0;
    }
    return p;
}

BOOL func_02160DDC(u32 *a, u8 *b) { u32 s=func_02012A30(((struct Obj12324 *)b)->f0); func_02029DD8(s,func_02012134(*(u32 **)a[6])); if (((struct Obj12324 *)b)->fE==0) return FALSE; else return TRUE; }
