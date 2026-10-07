/*
 * file:     comm_player_p09.c
 * unit:     yes
 * function: func_02167E54, func_02167E88, func_02167EAC, func_02167ED0, func_02167EF4, func_02167FB4
 * address:  0x02167E54
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
 *   func_02039338 0x02039338 arm
 *   func_0201210C 0x0201210C thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0201A364 0x0201A364 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0200CA38 0x0200CA38 thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0201AA14  0x0201AA14  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201A98C  0x0201A98C  thumb
 */
#include "../../matched/include/Obj07315.h"
#include "../../matched/include/Obj12375.h"
#include "../../matched/include/Obj12376.h"
#include "../../matched/include/Obj12377.h"

struct Blk37;
struct Ctx;
struct Desc;
struct Obj;
struct SeqWork;
struct Evt;
struct Party;
struct PartyMon;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct 
{
  u8 pad0[8];
  int f8;
  u8 fc;
  u8 fd;
  u8 fe;
  u8 ff;
  u8 f10;
  u8 pad11[7];
  int f18;
} T;

typedef struct 
{
  u8 pad0[0x14];
  u8 *f14;
  u8 pad18[0x1c];
  int f34;
  int f38;
} Q;

typedef struct 
{
  int f0;
  int f4;
  int f8;
  u8 padc[0x30 - 0xc];
  int f30;
  u8 pad34[0xc8 - 0x34];
  u8 buf[0x184 - 0xc8];
  int f184;
  int f188;
  int f18c;
  int f190;
  int f194;
} P;

typedef struct SeqWork {
    u32 heap;           /* 0x000 */
    void *arg;          /* 0x004 */
    u8 f08[0x28];       /* 0x008 */
    u8 f30[0x3C];       /* 0x030 */
    u32 f6c;            /* 0x06C */
    u32 f70;            /* 0x070 */
    u8 pad74[5];
    u8 order[6];        /* 0x079 */
    u8 pad7F[0x105];
    u32 *out184;        /* 0x184 */
    u32 *out188;        /* 0x188 */
    u8 *order18c;       /* 0x18C */
    void *party190;     /* 0x190 */
    void *party194;     /* 0x194 */
} SeqWork;

extern u16 func_02039338(void);
extern void *func_0201210C(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0201A364(int a, unsigned int b);
extern void *func_020120F4(const struct Ctx *p);
extern int func_0200CA1C(void);
extern void func_02082BCC(void *, int, int);
extern u32 func_0201AA18(void *p);
extern u32 func_0200CA38(struct Blk37 *p);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020144DC(int a0, int a1);
extern void *func_02014910(char *a0, int a1, int a2, int a3);
extern void *func_020145CC(void *a0);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32 func_0201AA14(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
void func_02167E54(u16 a, int b, u16 *c, u8 *p);
void func_02167E88(u16 a, int b, u16 *c, u8 *p);
void func_02167EAC(u16 a, int b, u16 *c, u8 *p);
void func_02167ED0(u16 a, int b, u16 *c, u8 *p);
int func_02167EF4(int a, int b, int c, int d, int e, int f, int g, int h, int i);
int func_02167FB4(void *evt, u32 *seq, SeqWork *w);

void func_02167E54(u16 a, int b, u16 *c, u8 *p)
{
    p[0x724]++;
    if (a != func_02039338()) {
        if (p[9] != *c)
            ((struct Obj07315 *)p)->f728 = 0;
        else
            ((struct Obj07315 *)p)->f728 = 1;
    }
}

void func_02167E88(u16 a, int b, u16 *c, u8 *p)
{
    p[0x724]++;
    if (a != func_02039338())
        ((struct Obj12375 *)p)->f728 = *c;
}

void func_02167EAC(u16 a, int b, u16 *c, u8 *p)
{
    p[0x724]++;
    if (a != func_02039338())
        ((struct Obj12376 *)p)->f728 = *c;
}

void func_02167ED0(u16 a, int b, u16 *c, u8 *p)
{
    p[0x724]++;
    if (a != func_02039338())
        ((struct Obj12377 *)p)->f728 = *c;
}

/*
 * lever: named temporaries keep Q+0x30 live across0201A364; bounded permuter47 compiles found byte-correct192.
 * Interface evidence: ov019_func_0217BA10.c records r0->r2, r1->r0, r1=0x69, jump via02048F4C. Original caller supplies d in r0 and p->buf in r1.
 * TU: MATCH192,9/10 relocations; suggest-split leaves sole function OUT.
 * checks: 1 020124E8 takes live hd from122C0, own matched accessor reads+0xc; 2 family/neighbours reread, no full twin; 3 unsigned b/c each retain31 before search; 4 pointer-copy idiom read; 5 neighbours/idioms reread, frame is scalar spills, no stack aggregate.
 * permuter: once budget300 types, emitted baseline agreed31/192; stopped at47 with MATCH; fixed one confirmsMATCH192.
 */
int func_02167EF4(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
  P *p;
  Q *q;
  T *t;
  int r7;
  int s;
  int hd;
  int x;
  Q *tmp1;
  u8 *tmp2;
  P *tmp3;
  u8 tmp;
  x = (int)func_0201210C((const struct Ctx *)a);
  hd = (int)func_020122C0((void *)a, 0, func_02167FB4, 0x198);
  tmp3 = func_020124E8((struct Obj *)hd);
  p = tmp3;
  q = (Q *) p;
  p->f0 = a;
  p->f4 = x;
  p->f18c = f;
  p->f188 = g;
  p->f184 = h;
  p->f190 = e;
  tmp2 = ((u8 *) q) + 0x30;
  p->f194 = i;
  tmp1 = (Q *) tmp2;
  func_0201A364(d, (unsigned int)p->buf);
  q = tmp1;
  p->f30 = e;
  q->f14 = p->buf;
  q->f38 = b;
  q->f34 = c;
  t = (T *) (((u8 *) p) + 8);
  r7 = (int)func_020120F4((const struct Ctx *)a);
  s = func_0200CA1C();
  func_02082BCC(t, 0, 0x28);
  p->f8 = e;
  t->fc = 1;
  tmp = func_0201AA18((void *)e);
  t->fe = tmp;
  t->fd = 0;
  t->f10 = 0;
  t->f8 = r7;
  t->f18 = func_0200CA38((struct Blk37 *)s);
  return hd;
}


/*
 * Sub-process sequence: runs five child processes one after another
 * (two from ov021, three from arm9), copying the result of the fifth
 * back and re-adding the chosen party members.
 *
 * First draft plus one lever (2026-09-28 tree_ov010_4): w->heap read into
 * a local before the switch. The member index is taken before the range
 * fix-up, so a reset slot still passes its old index (the image does not
 * reload it).
 */
int func_02167FB4(void *evt, u32 *seq, SeqWork *w)
{
    int n;
    int i;
    int idx;
    u32 heap;

    heap = w->heap;
    switch (*seq) {
    case 0:
        func_02012374(evt, (struct Evt **)func_021BE8D4((void *)heap, (int)w->arg, 0, 0));
        (*seq)++;
        break;
    case 1:
        func_02012374(evt, (struct Evt **)func_020144DC(heap, (int)w->arg));
        (*seq)++;
        break;
    case 2:
        func_02012374(evt, func_02014910((char *)heap, (int)w->arg, (int)w->f30, (int)w->f08));
        (*seq)++;
        break;
    case 3:
        func_02012374(evt, func_020145CC((void *)heap));
        (*seq)++;
        break;
    case 4:
        func_02012374(evt, (struct Evt **)func_021BE92C((void *)heap, (int)w->arg, 0, 0, 1, 0, 0));
        MI_CpuCopy8(w->order, w->order18c, 6);
        *w->out188 = w->f6c;
        *w->out184 = w->f70;
        if (*w->out188 != 7 && *w->out188 != 8 && w->party194 != 0) {
            n = func_0201AA14(w->party194);
            for (i = 0; i < n; i++) {
                idx = w->order18c[i] - 1;
                if (idx >= 6)
                    w->order18c[i] = 1;
                func_0201A98C(w->party194, func_0201AB28(w->party190, idx));
            }
        }
        (*seq)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}
