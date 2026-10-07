/*
 * file:     btlv_effvm_p46.c
 * unit:     yes
 * function: func_021FC148, func_021FC20C, func_021FC2DC, func_021FC334
 * address:  0x021FC148
 * region:   ov094
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
 *   func_0202142C  0x0202142C  thumb
 *   func_0206DF3C  0x0206DF3C  arm
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021F86F0  0x021F86F0  thumb  ov094
 *   func_021FCF2C  0x021FCF2C  thumb  ov094
 *   func_021FF3F4  0x021FF3F4  thumb  ov094
 *   func_02201B20  0x02201B20  thumb  ov094
 *   func_020113B4 0x020113B4 thumb
 *   func_02048F60 0x02048F60 arm
 *   func_020307B0  0x020307B0  arm
 *   func_020113C4  0x020113C4  thumb
 *   func_020113B0 0x020113B0 thumb
 */
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj21682.h"

struct Cursor;
struct Ring;
struct Cur;
typedef unsigned short u16;

typedef short s16;

typedef struct {
    char pad[0xcc];
    int t[92];
    int f23c;
    char pad2[0x254 - 0x240];
    u16 f254;
} State_021FC148;

typedef struct {
    int x;
    int y;
    int z;
} Pt;

typedef unsigned int   u32;

typedef struct {
    int pad0;
    int f4;
    char pad1[0xdc - 8];
    int fdc;
    int fe0;
    int a0[16];
    int a1[16];
    int a2[16];
    int a3[16];
    int f1e4;
    int *f1e8;
    char pad2[0x238 - 0x1ec];
    u16 h238;
    char pad3[2];
    int f23c;
    char pad4[0x260 - 0x240];
    int f260;
} State_021FC20C;

typedef struct {
    int pad0;
    int f4;
    char pad1[0xdc - 8];
    int fdc;
    int fe0;
    int a0[16];
    int a1[16];
    int a2[16];
    int a3[16];
    int f1e4;
    void *f1e8;
    char pad2[0x23c - 0x1ec];
    int f23c;
    char pad3[0x260 - 0x240];
    int f260;
} State_021FC2DC;

extern unsigned int func_0201134C(struct Cursor *p);
extern unsigned short func_0202142C(int a0);
extern void func_0206DF3C(Pt *p, int *a, int *b);
extern int func_021F8694(void);
extern int func_021F86F0(void);
extern int func_021FCF2C(int a, int idx);
extern void func_021FF3F4(void *obj, void *out, int idx);
extern int func_02201B20(char *p, u32 archiveId, int a, u32 b, int c, int d, s16 x, s16 y, u32 e, u32 f);
extern void func_020113B4(struct Ring *r, unsigned int v);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern u32 func_020307B0(void *p);
extern u32 func_020113C4(struct Ring *r);
extern void func_020113B0(struct Cur *c, u32 v);
int func_021FC148(struct Cursor *a, State_021FC148 *s);
int func_021FC20C(struct Ring *a, State_021FC20C *s);
int func_021FC2DC(int a, State_021FC2DC *s);
int func_021FC334(struct Cursor *a, char *s);


int func_021FC148(struct Cursor *a, State_021FC148 *s)
{
    int idx = func_0201134C(a);
    int q = func_021FCF2C((int)a, func_0201134C(a));
    int dx = func_0201134C(a);
    int dy = func_0201134C(a);
    int p5 = func_0201134C(a);
    int p6 = func_0201134C(a);
    Pt pt;
    int o1;
    int o2;
    int m;

    func_021FF3F4((void *)func_021F8694(), &pt, q);
    pt.x += dx;
    pt.y += dy;
    func_0206DF3C(&pt, &o1, &o2);
    m = func_0202142C(s->f254);
    m = (m == 0 || m > 0x19) ? 4 : m;
    m = (m == 0x19) ? 0x11 : m;
    m *= 2;
    s->t[idx] = (int)func_02201B20((char *)func_021F86F0(), 0x5f, m + 0x81, m + 0x82, 0x81, 0x82, o1, o2, p5, p6);
    return s->f23c;
}


int func_021FC20C(struct Ring *a, State_021FC20C *s)
{
    int n = func_0201134C((struct Cursor *)a);
    int v = func_0201134C((struct Cursor *)a);
    int w = func_0201134C((struct Cursor *)a);
    int *p;

    s->a0[s->f260] = s->fdc;
    s->a1[s->f260] = s->fe0;
    s->a2[s->f260] = (int)s->f1e8;
    s->a3[s->f260] = s->f4;
    if (v != 14) s->fdc = v;
    if (w != 16) s->fe0 = w;
    s->f4 = 0;
    p = func_02048F60(0x43, n - 0x231, (u16)((s->h238 & 0x7fff) | 0x8000));
    s->f1e8 = p;
    func_020113B4(a, (unsigned int)((char *)p + p[1]));
    s->f260++;
    return s->f23c;
}


int func_021FC2DC(int a, State_021FC2DC *s)
{
    int n;

    s->f260--;
    func_020307B0(s->f1e8);
    n = s->f260;
    s->fdc = s->a0[n];
    s->fe0 = s->a1[n];
    s->f1e8 = (void *)s->a2[n];
    s->f4 = s->a3[n];
    func_020113C4((struct Ring *)a);
    return s->f23c;
}


/*
 * Script command: jumps the reader by a relative offset.
 */
int func_021FC334(struct Cursor *a, char *s)
{
    int off = func_0201134C(a);
    func_020113B0((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + off);
    return ((struct Obj21682 *)s)->f23C;
}
