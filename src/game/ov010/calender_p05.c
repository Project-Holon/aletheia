/*
 * file:     calender_p05.c
 * unit:     yes
 * function: func_021647A0, func_021647D8, func_021647E8, func_021647F0, func_021647FC, func_0216480C, func_0216481C, func_02164844, func_02164890, func_021648A8, func_021648CC, func_02164910, func_02164978, func_02164994, func_021649C8, func_021649E8, func_02164A2C
 * address:  0x021647A0
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
 *   func_02030734 0x02030734 arm
 *   d_021729B0 0x021729B0 data ov010 a1
 *   func_020307B0  0x020307B0  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   func_021690D0 0x021690D0 thumb ov010
 *   func_021690E0 0x021690E0 thumb ov010
 *   func_02013C10  0x02013C10  thumb
 *   func_0204944C  0x0204944C  arm
 *   d_02171C20  0x02171C20  data  ov010  a1
 *   func_0215A5F4  0x0215A5F4  thumb ov010
 *   func_0215A5DC  0x0215A5DC  thumb ov010
 *   func_02011330  0x02011330  thumb
 *   func_02159144  0x02159144  thumb ov010
 *   func_02034AC4  0x02034AC4  arm
 *   func_021F5260  0x021F5260  thumb ov082
 *   func_0215897C  0x0215897C  thumb ov010
 *   ov_id_52       0x00000052  data
 *   func_0201210C  0x0201210C  thumb
 *   func_021F558C  0x021F558C  thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_021F5578 0x021F5578 thumb ov082
 *   func_02159168 0x02159168 thumb ov010
 *   func_02034A5C 0x02034A5C arm
 *   func_020124E4  0x020124E4  thumb
 *   func_02012374  0x02012374  thumb
 *   func_021F5550  0x021F5550  thumb  ov082
 *   func_020120F4  0x020120F4  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_020144DC  0x020144DC  thumb
 *   func_020297AC  0x020297AC  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_02029690  0x02029690  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_021A0F40  0x021A0F40  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02029CC0  0x02029CC0  thumb
 *   ov216_id       0x000000D8  data
 *   d_021BDB40     0x021BDB40  data  a1 ov216
 */
#include "../../matched/include/Obj04133.h"
#include "../../matched/include/Obj12049.h"
#include "../../matched/include/Obj12360.h"
#include "../../matched/include/Obj18978.h"
#include "../../matched/include/Obj18979.h"

struct ArcFile;
struct Stream;
struct Ctx;
struct Desc;
struct Evt;
struct Obj;
struct IcaAnime;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 b[13]; } Days;

typedef struct SubArgs {
    void *sys;          /* 0x0C */
    u32 f04;            /* 0x10 */
    u8 f08;             /* 0x14 */
    u8 flag;            /* 0x15 */
    u8 pad[2];
} SubArgs;

typedef struct SeqWork2 {
    void *sys;          /* 0x00 */
    u32 f04;            /* 0x04 */
    u32 f08;            /* 0x08 */
    SubArgs sub;        /* 0x0C */
    u8 f18;             /* 0x18 */
} SeqWork2;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_020307B0();
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049238(void *arc);
extern int func_021690D0(int a0);
extern int func_021690E0(int a0);
extern u8   func_02013C10(u32 b);
extern void func_0204944C(struct ArcFile *a, u32 b, u32 c, u32 d, void *e);
extern void *func_0215A5F4(void *a);
extern void *func_0215A5DC(void *a);
extern u16 func_02011330(struct Stream *s);
extern void func_02159144(int a);
extern int func_02034AC4(int a);
extern void *func_021F5260(int a0, int a1, int a2, void *a3, int a4);
extern void func_0215897C(void *vm, void *task);
extern void *func_0201210C(const struct Ctx *p);
extern int func_021F558C();
extern struct Desc *func_020122C0(void *,void *,void *,u32);
extern void func_021F5578(u8 *p);
extern void func_02159168(int);
extern void func_02034A5C(int handle);
extern void *func_020124E4(struct Obj *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_021F5550(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_020144DC(int a0, int a1);
extern void *func_020297AC(void *sys, u32 a, u32 b, u32 c);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern void *func_02029690(void *sys, u32 a, u32 b);
extern void *func_020145CC(void *sys);
extern u32 func_02188CCC(u8 *p);
extern void func_021A0F40(u32 *p, u32 v);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void *func_02029CC0(void *sys);
u8 *func_021647A0(void *a,u32 b);
int func_021647D8(int a0);
u32 func_021647E8(void *arg, unsigned int b);
int func_021647F0(int a0);
void *func_021647FC(int a0);
int func_0216480C(int a0);
u8 func_0216481C(u8 *p,u32 b);
u8 func_02164844(u8 *a, u32 b, u8 c, u8 d);
void func_02164890(u8 *p);
u32 func_021648A8(u8 *p,u32 n);
u16 func_021648CC(int n, int k);
int func_02164910(void *s, void *q);
int func_02164978(int a0, int a1);
int func_02164994(void *a,void *b);
int func_021649C8(void **p);
int func_021649E8(void *a, int *st);
int func_02164A2C(void *evt, u32 *seq, SeqWork2 *w);
extern const char d_021729B0[];
extern const Days d_02171C20;
extern u8 ov_id_52[];
extern u8 ov216_id[];
extern const u8 d_021BDB40[];

u8 *func_021647A0(void *a,u32 b){u8 *p=func_02030734(b,0x11c,0,d_021729B0,0x53);func_021647F0((int)p);((struct Obj04133 *)p)->f0=b;((struct Obj04133 *)p)->f4=a;func_021647FC((int)p);func_02164890(p);return p;}


int func_021647D8(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0216480C(a0);
loc_021647E0:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_021647E6:
    return a0;}


/*
 * Tail call to func_0216481C through a pool word and `bx r3`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  Unlabelled in the
 * listing: no prologue, and its only caller is func_0202C794 in arm9.
 */
u32 func_021647E8(void *arg, unsigned int b)
{
    return func_0216481C(arg, b);
}




int func_021647F0(int a0)
{
    int a1;

a1 = 0;
((struct Obj04133 *)((char *)a0))->f0 = a1;
*(int *)&((struct Obj04133 *)a0)->f4 = a1;
*(int *)&((struct Obj04133 *)a0)->f8 = a1;
    return a0;}


void *func_021647FC(int a0)
{
    int a1;
    int t4;
    void *rec;

t4 = a0 + 0;
a1 = ((struct Obj04133 *)((char *)t4))->f0;
a0 = 0x61;
    rec = func_020490F4(a0, a1);
loc_02164808:
((struct Obj04133 *)t4)->f8 = rec;
    return rec;}


int func_0216480C(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj12049 *)t4)->f8;
    func_02049238((void *)a0);
loc_02164816:
a0 = 0;
((struct Obj12049 *)t4)->f8 = a0;
    return a0;}

u8 func_0216481C(u8 *p,u32 b){int c=func_021690D0((int)(((struct Obj12360 *)p)->f4));int d=func_021690E0((int)(((struct Obj12360 *)p)->f4));return func_02164844(p,b,c,d);}


/*
 * Looks up a table entry; 0xFFFF means missing and forwards to
 * func_02013C10, otherwise reads one byte through func_0204944C.
 *
 * Addresses are Black-image addresses.
 */
u8 func_02164844(u8 *a, u32 b, u8 c, u8 d)
{
    u32 t = func_021648A8(a, b);
    u8 out;
    u16 s;
    if (t == 0xffff) {
        return func_02013C10(b);
    }
    s = t + func_021648CC(c, d);
    func_0204944C((struct ArcFile *)((struct Obj18978 *)a)->f8, 0, s, 1, &out);
    return out;
}

void func_02164890(u8 *p){func_0204944C((struct ArcFile *)((struct Obj18979 *)p)->f8,1,2,0x110,p+12);}

u32 func_021648A8(u8 *p,u32 n){int i;u32 out=0xffff;for(i=0;i<68;i++){if(n==*(u16 *)(p+12+i*4)){out=*(u16 *)(p+14+i*4);break;}}return out;}


/*
 * Sums the first n entries of a 13-byte days-per-month table, plus k - 1.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021648CC(int n, int k)
{
    Days t = d_02171C20;
    int i;
    u16 s = 0;
    for (i = 0; i < n; i++) {
        s = s + t.b[i];
    }
    return s + (u16)(k - 1);
}


/*
 * Reads three values off a stream, loads overlay 82 and calls into it.
 *
 * Addresses are Black-image addresses.
 */
int func_02164910(void *s, void *q)
{
    void *x = func_0215A5F4(q);
    void *y = func_0215A5DC(q);
    u8 a = func_02011330(s);
    u8 b = func_02011330(s);
    u32 c = func_02011330(s);
    int r;
    func_02159144(7);
    func_02034AC4((int)ov_id_52);
    r = (int)func_021F5260(a, b, c, y, (int)q);
    if (r == 0) {
        return 1;
    }
    func_0215897C(x, (void *)r);
    return 1;
}


int func_02164978(int a0, int a1)
{
    int t4;
    void *v0;
    void *v1;
    void *v2;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_02164982:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_02164988:
    v2 = func_0201210C(v1);
loc_0216498C:
    a0 = func_021F558C(v2);
loc_02164990:
a0 = 0;
    return a0;}

int func_02164994(void *a,void *b){void *v=func_0215A5F4(b);void *t=func_020122C0(func_0215A5DC(b),0,(void *)func_021649E8,0);if(t==0)return 1;func_0215897C(v,t);return 1;}

int func_021649C8(void **p){func_021F5578(func_0201210C(*p));func_02159168(7);func_02034A5C((int)ov_id_52);return 1;}


/*
 * Two-step state machine on *st: step 0 starts a request, step 1 finishes.
 *
 * Addresses are Black-image addresses.
 */
int func_021649E8(void *a, int *st)
{
    int r = (int)func_020124E4(a);
    switch (*st) {
    case 0:
        func_02012374(a, func_021F5550((void *)r));
        (*st)++;
        break;
    case 1:
        func_02159168(7);
        func_02034A5C((int)ov_id_52);
        return 1;
    }
    return 0;
}


/*
 * Sub-process sequence of the ov010 program: eight steps, each starting
 * one child process (two from ov021, the ov216 one through
 * func_020120B4 with a 12-byte hand-off), then done. Step 2 falls
 * through into step 3.
 *
 * MATCH, first draft (2026-09-28 tree_ov010_4): the one wildcard is the
 * pooled 0x021BDB40, the ov216 process template, which has no other
 * reference in the image (ov216_id itself resolves by the overlay_id
 * class).
 *
 * 2026-10-05 (D8 lane 15): the process template d_021BDB40 lives in ov216; the data line now carries the ov216 token and the relocation resolves.
 */
int func_02164A2C(void *evt, u32 *seq, SeqWork2 *w)
{
    void *sys;
    void *p;

    sys = w->sys;
    func_020120F4(sys);
    p = func_0201210C(sys);
    switch (*seq) {
    case 0:
        func_02012374(evt, (struct Evt **)func_021BE8D4(sys, (int)p, 0, 0));
        (*seq)++;
        break;
    case 1:
        func_02012374(evt, (struct Evt **)func_020144DC((int)sys, (int)p));
        (*seq)++;
        break;
    case 2:
        func_02012374(evt, func_020297AC(sys, 0x483, 6, 0));
        (*seq)++;
    case 3:
        MI_CpuFill8(&w->sub, 0, sizeof(SubArgs));
        w->sub.sys = w->sys;
        w->sub.f04 = w->f04;
        w->sub.f08 = w->f18;
        func_020120B4(sys, (u32)ov216_id, (void *)d_021BDB40, &w->sub);
        (*seq)++;
        break;
    case 4:
        if (func_020120F0(sys) == 0) {
            func_02012374(evt, func_02029690(sys, 6, 0x3C));
            (*seq)++;
        }
        break;
    case 5:
        func_02012374(evt, func_020145CC(sys));
        (*seq)++;
        break;
    case 6:
        if (w->sub.flag != 0)
            func_021A0F40((u32 *)func_02188CCC(p), 0);
        func_02012374(evt, (struct Evt **)func_021BE92C(sys, (int)p, 0, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 7:
        func_02012374(evt, func_02029CC0(sys));
        (*seq)++;
        break;
    case 8:
        return 1;
    }
    return 0;
}
