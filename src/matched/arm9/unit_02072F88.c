/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: func_02072F88, func_02072FA8, func_02072FC8, func_02072FE8, func_02073018, func_02073038, func_02073058, func_02073078, func_02073098
 * address:  0x2072F88
 * packet:   pkt_02072EA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  0x020893E8/0x02089580/0x020895B0/0x02089400/0x0208941C/0x02089438/0x02089454/0x02089470/0x020893B8 each have no witness outside this range: every one of them has exactly one caller and it is the member here that calls it (label-class refusal, and `--suggest-split` cannot help because the call is inside the only function that needs it)
 * symbols:
 *   g_020A5D08       0x20A5D08  data
 *
 * Nine members of one dispatch family: a null guard on o->p, then a call that
 *  * passes the object's byte at +0x3c plus the member's own leftover argument
 *  * registers.
 *  *
 *  * The arity is read off the guard's scratch register, which is the only thing
 *  * that distinguishes the members: a two-argument member (r1 live) loads the
 *  * guard into r2, a three-argument one (r1 and r2 live) into r3. Writing the
 *  * unused parameters is what buys the byte:
 *  *
 *  *   struct Obj * volatile p  -> the guard's load and the use's load are two
 *  *   loads; a plain field folds them into one and the member is four bytes
 *  *   short.
 *  *
 *  * func_020730B8 (0x020730B8), an otherwise identical two-statement member of
 *  * the same family, is NOT in this unit: this front end if-converts a
 *  * two-statement arm and the original used `bxeq lr`, so it stays a DIFF near
 *  * miss. See docs/notes/pkt_02072EA8.c.txt.
 *  *
 *  * Verified with:
 *  *   python tools/match.py tu --src src/pending/unit_02072F88.c --addr 0x02072F88 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub { u8 pad00[0x2c]; u8 b2c; u8 pad2[0x3c - 0x2d]; u8 b3c; };
struct Obj { struct Sub * volatile p; };

extern short g_020A5D08[];
extern void func_020893E8(u8, u32);
extern void func_02089580(u8, u32, u32);
extern void func_020895B0(u8, u32, u32);
extern void func_02089400(u8, u32, int);
extern void func_0208941C(u8, u32, u32);
extern void func_02089438(u8, u32, u32);
extern void func_02089454(u8, u32, u32);
extern void func_02089470(u8, u32, u32);
extern void func_020893B8(u8, u32);
extern int  func_02072894(u8, u32, u32);

void func_02072F88(struct Obj *o, u32 v)
{
    if (o->p == 0) return;
    func_020893E8(o->p->b3c, v);
}

void func_02072FA8(struct Obj *o, u32 v, u32 w)
{
    if (o->p == 0) return;
    func_02089580(o->p->b3c, v, w);
}

void func_02072FC8(struct Obj *o, u32 v, u32 w)
{
    if (o->p == 0) return;
    func_020895B0(o->p->b3c, v, w);
}

void func_02072FE8(struct Obj *o, u32 v, int a)
{
    if (o->p == 0) return;
    func_02089400(o->p->b3c, v, g_020A5D08[a]);
}

void func_02073018(struct Obj *o, u32 v, u32 w)
{
    if (o->p == 0) return;
    func_0208941C(o->p->b3c, v, w);
}

void func_02073038(struct Obj *o, u32 v, u32 w)
{
    if (o->p == 0) return;
    func_02089438(o->p->b3c, v, w);
}

void func_02073058(struct Obj *o, u32 v, u32 w)
{
    if (o->p == 0) return;
    func_02089454(o->p->b3c, v, w);
}

void func_02073078(struct Obj *o, u32 v, u32 w)
{
    if (o->p == 0) return;
    func_02089470(o->p->b3c, v, w);
}

void func_02073098(struct Obj *o, u32 v)
{
    if (o->p == 0) return;
    func_020893B8(o->p->b3c, v);
}
