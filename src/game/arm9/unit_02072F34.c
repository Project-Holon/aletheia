/*
 * file:     unit_02072F34.c
 * unit:     yes
 * function: func_02072F34, func_02072F48, func_02072F5C, func_02072F88, func_02072FA8, func_02072FC8, func_02072FE8, func_02073018, func_02073038, func_02073058, func_02073078, func_02073098
 * address:  0x02072F34
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02075BAC  0x02075BAC  arm
 */
struct Obj02075BAC;
struct SNDTrackInfo;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Sub { u8 pad00[0x2c]; u8 b2c; u8 pad2d[0x3c - 0x2d]; u8 b3c; u8 pad3d[0x40 - 0x3d]; u8 b40; u8 b41; };

struct Obj { struct Sub * volatile p; };

typedef struct Obj02072F5C {
    u8  unk00[0x1c];
    u32 env[4];
    u8  state;
} Obj02072F5C;

extern void func_02075BAC(struct Obj02075BAC *o, u32 a, u32 b);
extern void func_020893E8(u8, u32);
extern void func_02089580(int playerNo, u32 trackBitMask, int flag);
extern void func_020895B0(int playerNo, u32 trackBitMask, int mute);
extern void func_02089400(u8, u32, int);
extern void func_0208941C(u8, u32, u32);
extern void func_02089438(u8, u32, u32);
extern void func_02089454(u8, u32, u32);
extern void func_02089470(u8, u32, u32);
extern void func_020893B8(u8, u32);
extern int func_02072894(int playerNo, int trackNo, struct SNDTrackInfo *trackInfo);
void func_02072F34(struct Obj *o, u8 v);
void func_02072F48(struct Obj *o, u8 v);
void func_02072F5C(Obj02072F5C *volatile *pp, u32 a, u32 b);
void func_02072F88(struct Obj *o, u32 v);
void func_02072FA8(struct Obj *o, u32 v, u32 w);
void func_02072FC8(struct Obj *o, u32 v, u32 w);
void func_02072FE8(struct Obj *o, u32 v, int a);
void func_02073018(struct Obj *o, u32 v, u32 w);
void func_02073038(struct Obj *o, u32 v, u32 w);
void func_02073058(struct Obj *o, u32 v, u32 w);
void func_02073078(struct Obj *o, u32 v, u32 w);
void func_02073098(struct Obj *o, u32 v);
extern short g_020A5D08[];


void func_02072F34(struct Obj *o, u8 v)
{
    if (o->p) o->p->b41 = v;
}


void func_02072F48(struct Obj *o, u8 v)
{
    if (o->p) o->p->b40 = v;
}



/*
 * Wave 17 lane untried_small. Callee arity read from func_02075BAC's body
 * (three parameters, r2 stored to +0x0C): the wrapper forwards its own third
 * parameter untouched, so r0..r2 are all live and the null test's load lands
 * in r3, the register the earlier two-parameter spellings could not reach.
 * The re-load after the null test is the volatile slot.
 */
void func_02072F5C(Obj02072F5C *volatile *pp, u32 a, u32 b)
{
    Obj02072F5C *o;

    if (*pp == 0) {
        return;
    }
    o = *pp;
    if (o->state == 2) {
        return;
    }
    func_02075BAC((struct Obj02075BAC *)o->env, a << 8, b);
}



/*
 * A whole translation unit, matched as one byte range.
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
