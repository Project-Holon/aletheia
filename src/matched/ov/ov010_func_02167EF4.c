/*
 * function: func_02167EF4
 * address: 0x02167EF4
 * packet: pkt_ov010_02167EF4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: named temporaries keep Q+0x30 live across0201A364; bounded permuter47 compiles found byte-correct192.
 * blocker: ARM90201A364 (thumb) has no witness outside02167EF4..02167FB4; the integrator owns it. No owner-leaf compile under assigned scope.
 * Interface evidence: ov019_func_0217BA10.c records r0->r2, r1->r0, r1=0x69, jump via02048F4C. Original caller supplies d in r0 and p->buf in r1.
 * TU: MATCH192,9/10 relocations; suggest-split leaves sole function OUT.
 * checks: 1 020124E8 takes live hd from122C0, own matched accessor reads+0xc; 2 family/neighbours reread, no full twin; 3 unsigned b/c each retain31 before search; 4 pointer-copy idiom read; 5 neighbours/idioms reread, frame is scalar spills, no stack aggregate.
 * permuter: once budget300 types, emitted baseline agreed31/192; stopped at47 with MATCH; fixed one confirmsMATCH192.
 * symbols:
 *   func_0201210C 0x0201210C thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0201A364 0x0201A364 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0200CA38 0x0200CA38 thumb
 *   func_02167FB4 0x02167FB4 thumb
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
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
struct Blk37;
struct Ctx;
struct Desc;
struct Obj;
extern void *func_0201210C(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0201A364(int a, unsigned int b);
extern void *func_020120F4(const struct Ctx *p);
extern int func_0200CA1C(void);
extern void func_02082BCC(void *, int, int);
extern u32 func_0201AA18(void *p);
extern u32 func_0200CA38(struct Blk37 *p);
struct SeqWork;
extern int func_02167FB4(void *evt, u32 *seq, struct SeqWork *w);
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
