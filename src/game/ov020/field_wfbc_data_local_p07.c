/*
 * file:     field_wfbc_data_local_p07.c
 * unit:     yes
 * function: func_02186878, func_02186898, func_021868A0, func_021868B8, func_021869AC, func_021869B0, func_021869B8, func_021869BC, func_021869D0, func_021869D4, func_021869D8, func_021869DC, func_021869E0, func_02186A2C
 * address:  0x02186878
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
 *   func_02186854  0x02186854  thumb  ov020
 *   func_02030734  0x02030734  arm
 *   func_021867C4  0x021867C4  thumb  ov020
 *   func_02186830  0x02186830  thumb  ov020
 *   func_0218684C  0x0218684C  thumb  ov020
 *   func_0216E618  0x0216E618  thumb  ov010
 *   func_0218683C  0x0218683C  thumb  ov020
 *   func_02186804  0x02186804  thumb  ov020
 *   d_02187EB4     0x02187EB4  data  ov020  a1
 *   d_02187DE0     0x02187DE0  data  ov020  a4
 *   func_0218682C  0x0218682C  thumb
 *   func_02186818  0x02186818  thumb
 *   func_02186A58 0x02186A58 thumb ov020
 */
#include "../../matched/include/Obj19469.h"
#include "../../matched/include/Obj19470.h"

struct ArcFile;
typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 fA;
    int f0C[6];
} Tmpl;

extern int func_02186854(u16 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int *func_021867C4(int a, int id);
extern void *func_02186830(struct ArcFile **p, int b, unsigned int heap);
extern u8 *func_0218684C(u8 *t, int i);
extern void func_0216E618(Tmpl *, u16, u16, int);
extern void func_0218683C(void *p);
extern void func_02186804(void **p);
extern char *func_0218682C(char *p);
extern void func_02186818(u32 *p, u32 member);
extern int func_02186A58(char *p, int id);
int func_02186878(u16 *p, u16 v, int i);
u16 func_02186898(u16 *p, int i);
int func_021868A0(u16 *p, int i);
Tmpl *func_021868B8(void *p, int a1, int a2, int id);
u16 func_021869AC(u16 *p);
void func_021869B0(u16 *p);
u16 func_021869B8(u16 *p);
void func_021869BC(u16 *p);
u16 func_021869D0(char *p);
void func_021869D4(char *p, u16 v);
u16 func_021869D8(u16 *p);
void func_021869DC(u16 *p, u16 v);
char *func_021869E0(char *a, int limit, char *h, int *out);
int func_02186A2C(char *p, int id);
extern const char d_02187EB4[];
extern const Tmpl d_02187DE0;

int func_02186878(u16 *p, u16 v, int i) { if (p[i] == 0xFFFF) { p[i] = v; return 1; } return 0; }


u16 func_02186898(u16 *p, int i)
{
    return p[i];
}

int func_021868A0(u16 *p, int i) { if (p[i] != 0xFFFF) return 1; return 0; }


Tmpl *func_021868B8(void *p, int a1, int a2, int id)
{
    Tmpl *buf;
    int h;
    u8 *t;
    u8 *q;
    int heap;
    int n;
    int k;
    Tmpl *e;
    int i;
    Tmpl tmp;

    if (a1 != 0)
        return 0;
    if (a2 == 0)
        return 0;
    heap = (u16)((id & 0x7FFF) | 0x8000);
    n = func_02186854(p);
    k = 0;
    buf = func_02030734(heap, n * 0x24, 1, d_02187EB4, 0x561);
    h = (int)func_021867C4(0, heap);
    t = func_02186830((struct ArcFile **)h, a2, heap);
    i = 0;
    tmp = d_02187DE0;
    for (; i < 10; i++) {
        if (func_021868A0(p, i)) {
            q = func_0218684C(t, i);
            e = &buf[k];
            *e = tmp;
            e->f0 = i + 0xa0;
            e->fA = func_02186898(p, i);
            e->f8 = i + 0xaa0;
            func_0216E618(e, q[0], q[1], 0);
            k++;
        }
    }
    func_0218683C(t);
    func_02186804((void **)h);
    return buf;
}


/*
 * Unlabelled leaf (saves nothing, so disasm.py prints it as .word data);
 * filed as the blocker of func_02186D48 (ov020).
 */
u16 func_021869AC(u16 *p)
{
    return p[0];
}


void func_021869B0(u16 *p)
{
    (*p)++;
}


u16 func_021869B8(u16 *p)
{
    return p[1];
}


void func_021869BC(u16 *p)
{
    if (p[1] < 0x2710)
        p[1] += 10;
}


u16 func_021869D0(char *p)
{
    return ((struct Obj19469 *)p)->f2;
}


void func_021869D4(char *p, u16 v)
{
    ((struct Obj19470 *)p)->f2 = v;
}


u16 func_021869D8(u16 *p)
{
    return p[0];
}


void func_021869DC(u16 *p, u16 v)
{
    *p = v;
}


char *func_021869E0(char *a, int limit, char *h, int *out)
{
    char *q;
    int i;
    u32 sum;
    int r;

    sum = 0;
    q = func_0218682C(h);
    for (i = 0; i < 30; i++) {
        r = func_02186A2C(a, i);
        func_02186818((u32 *)h, r);
        sum += *(u16 *)(q + 0x2C);
        if (sum > limit) {
            *out = r;
            return q;
        }
    }
    return q;
}

int func_02186A2C(char *p, int id) { int i; int n; n = 0; for (i = 0; i < 30; i++) { if (func_02186A58(p, i) == 0) { if (n == id) return i; n++; } } return 0; }
