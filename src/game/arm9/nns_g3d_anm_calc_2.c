/*
 * file:     nns_g3d_anm_calc_2.c
 * unit:     yes
 * function: func_0206EB7C, func_0206EBB8, func_0206EC50, func_0206ECE0, func_0206EE60, func_0206F214, func_0206F36C, func_0206F4C8, func_0206F6B0, func_0206F844, func_0206FC5C, func_0206FFA0
 * address:  0x0206EB7C
 * region:   arm9
 * compiler: dsi/../2.0/sp2p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02148DB0      0x02148DB0  data
 *   g_020A1998      0x020A1998  data  a1
 *   g_020A1999      0x020A1999  data  a1
 *   g_020A199A      0x020A199A  data  a1
 *   g_020A199B      0x020A199B  data  a1
 *   func_020834A8   0x020834A8  thumb
 *   VEC_Normalize   0x0207CCA4  arm
 */
#include "../../matched/include/Obj16622.h"
#include "../../matched/include/Obj05777.h"
#include "../../matched/include/Obj16634.h"
#include "../../matched/include/Obj04095.h"
#include "../../matched/include/Obj16636.h"

#define FX32_SHIFT 12
#define FX_Whole(a) ((s32_0206ECE0)((a) >> FX32_SHIFT))
#define NNS_G3D_JNTANM_SINFO_STEP_MASK       0xc0000000
#define NNS_G3D_JNTANM_SINFO_STEP_2          0x40000000
#define NNS_G3D_JNTANM_SINFO_STEP_4          0x80000000
#define NNS_G3D_JNTANM_SINFO_FX16ARRAY       0x20000000
#define NNS_G3D_JNTANM_SINFO_LASTINTERP_MASK 0x1fff0000
#define NNS_G3D_JNTANM_SINFO_LASTINTERP_SHIFT 16
typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int s32_0206EB7C;

typedef unsigned char u8;

typedef struct { u8 unk00; u8 idx01; } ResHdr;

typedef struct { u16 f0; } TabHdr;

typedef struct { u8 unk00; u8 cnt01; u8 unk02[4]; u16 off06; } Bank;

typedef struct Root { ResHdr *h; u8 pad[0xD0]; Bank *bank; u8 pad2[0x10];
                 void (*hook)(void *, void *, ResHdr *, u32); } Root;

typedef struct { u16 flags; u32 f04; u32 f08; u32 f0C; } Node;

typedef struct { u32 rel00; } Ent;

typedef struct { u32 f00; u16 cnt04; u16 pad06; u32 f08; u32 f0c; u32 f10; } Hdr;

typedef struct { u32 f00; u8 pad04[0x24]; int m[9]; u32 f4c; u32 f50; u32 f54; } Out;

typedef struct { u32 unk00; u32 unk04; Hdr *p08; } Cur;

typedef signed short s16;

typedef struct { u8 c; u8 pad[3]; } Perm;

typedef struct { u32 flags; u32 off04; } Rec;

typedef int            s32_0206ECE0;

typedef long long      s64;

typedef s16 fx16;

typedef s32_0206ECE0 fx32;

typedef s64 fx64;

typedef struct { u32 info; u32 offset; } NNSG3dJntAnmSInfo;

typedef struct { fx16 s; fx16 invs; } ScaleFx16;

typedef struct { fx32 s; fx32 invs; } ScaleFx32;

typedef struct { s16 x; s16 y; } V2s;

typedef struct { int x; int y; } V2i;

extern void func_020834A8(void *p);
extern void VEC_Normalize(const int *src, int *dst);
void func_0206EB7C(Out *a, Cur *c, u32 b);
void func_0206EBB8(u32 *out);
void func_0206EC50(void *arg);
void func_0206ECE0(Out *out);
void func_0206EE60(Hdr *root, u32 idx, u32 t, Out *out);
void func_0206F214(int *out, int t, Rec *r, u8 *base);
void func_0206F36C(int *out, int t, Rec *r, Hdr *h);
void func_0206F4C8(fx32 *s_invs, fx32 Frame, const NNSG3dJntAnmSInfo *pData, const u8 *pJntAnm);
void func_0206F6B0(int *out, int t, Rec *r, Hdr *h);
void func_0206F844(int *out, int t, Rec *r, Hdr *h);
void func_0206FC5C(int *out, int t, Rec *r, Hdr *h);
int func_0206FFA0(int *out, s16 *a, s16 *b, u32 id);
extern Root *g_02148DB0;
extern const Perm g_020A1998[];
extern const Perm g_020A1999[];
extern const Perm g_020A199A[];
extern const Perm g_020A199B[];




/*
 *           branch anywhere in the image to 0x0206EE60 is this one, so
 *           `label` refuses it and nothing else attests it. Filing 0x0206EE60
 *           (940 B, still OPEN in this packet) as EXACT promotes this file to
 *           EXACT with no change to the C. --suggest-split offers nothing:
 *           single function, the one site's only witness is inside the range.
 *
 * Clamps a 20.12 fixed-point cursor into [0, (count<<12)-1] and forwards.
 *
 * Shape note that cost the previous two passes: the callee takes FOUR
 * arguments and the caller's own first argument is the FOURTH, not the first
 * (the image's `mov r3, r0` at 0x0206EB80 is that argument being parked in
 * r3 before r0 is reloaded with the table pointer). Written as a three-
 * argument forward of r0 the compiler lands at 56 bytes against 60.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206EB7C.c \
 *       --func func_0206EB7C --addr 0x0206EB7C --cc 1.1p1 --arm
 */
void func_0206EB7C(Out *a, Cur *c, u32 b)
{
    s32_0206EB7C t;
    s32_0206EB7C lim;
    Hdr *tab;

    tab = c->p08;
    lim = (s32_0206EB7C)((u32)tab->cnt04 << 12);
    t = (s32_0206EB7C)c->unk00;
    if (t >= lim) {
        t = lim - 1;
    } else if (t < 0) {
        t = 0;
    }
    func_0206EE60(tab, b, t, a);
}





/*
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md).
 * The image keeps `tst r1, #1` at 0x0206EC18 and `beq 0x0206EC30` at
 * 0x0206EC1C over the four-instruction guard body at 0x0206EC20..0x0206EC2C
 * (`ldr r1,[r0]` / `orr r1,r1,#4` / `str r1,[r0]` / `bx lr`); dsi/1.1p1
 * -O4,p predicates it to ldrne/orrne/strne/bxne, giving 148 bytes against
 * the original's 152. Under ../2.0/sp2 the same C is 152 bytes, 0 mismatches.
 *
 * Same inlined two-step resolve as src/matched/unit_0206E394.c, but over the
 * global stash at 0x02148DB0: root -> bank (+0xD4), bank -> entry (indexed
 * table at bank+6), entry -> node (relative offset at entry+0).
 */
void func_0206EBB8(u32 *out)
{
    Root *r = g_02148DB0;
    Bank *b;
    Node *n;
    u8 *t;
    u32 idx;

    idx = r->h->idx01;
    b = r->bank;
    if (b == 0) goto none;
    if (b == 0) goto nullent;
    if (idx >= b->cnt01) goto nullent;
    t = (u8 *)b + b->off06;
    idx = (u32)(t + 4 + (((struct Obj16622 *)t)->f0) * idx);
    goto have;
nullent:
    idx = 0;
have:
    if (idx == 0) goto none;
    n = (Node *)((u8 *)b + ((Ent *)idx)->rel00);
    goto set;
none:
    n = 0;
set:
    if ((n->flags & 1) != 0) {
        out[0] |= 4;
        return;
    }
    out[0x13] = n->f04;
    out[0x14] = n->f08;
    out[0x15] = n->f0C;
}





static inline u8 *entry_of(Bank *b, u32 idx)
{
    u8 *t;
    if (b != 0 && idx < b->cnt01) {
        t = (u8 *)b + b->off06;
        return t + 4 + (((TabHdr *)t)->f0) * idx;
    }
    return 0;
}





static inline u8 *resolve(Bank *b, u32 idx)
{
    u8 *e;
    if (b != 0) {
        e = entry_of(b, idx);
        if (e != 0)
            return (u8 *)b + ((Ent *)e)->rel00;
    }
    return 0;
}





/*
 * Resolves the current node through the global stash at 0x02148DB0 (root ->
 * bank at +0xD4, bank -> entry through the halfword-indexed table at
 * bank+6, entry -> node by the relative offset at entry+0), skips the node's
 * optional header blocks by its flag bits, and hands the payload to the
 * root's hook at +0xE8.  func_0206EE60 calls it for the third flag group.
 *
 * Closing levers over the 23-30 byte register residue recorded in
 * docs/notes/pkt_0206EB00.c.txt (which no respelling of a flat goto body
 * could move):
 *   - the resolve is TWO NESTED INLINE HELPERS, entry_of() and resolve().
 *     Inlining is what renumbers the values so that the root lands in ip and
 *     the bank in r4; the same statements written flat in the body stay at
 *     7-16 bytes out whatever the declaration order (tools/permuter.py hill
 *     and anneal, 4000+ compiles, found nothing);
 *   - the hook takes FOUR arguments, (arg, payload, root->h, flags): the
 *     image loads root->h into r2 at 0x0206EC5C and never writes r2 again,
 *     and the flag word stays in r3 up to the `blx`.  The same four-argument
 *     hook, with root->h as its third argument, is what func_0206EE60 calls
 *     at its emit tail.  A three-argument call is 21 bytes out.
 *
 * Front end: filed under the packet's ../2.0/sp2 unit pin.  With the inline
 * helpers this function is compiler-neutral (EXACT under dsi/1.1p1 as well,
 * measured 2026-09-22): the "kept branches" double `beq` the earlier note
 * attributed to the front end is what the nested inline produces under both.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206EC50.c \
 *       --func func_0206EC50 --addr 0x0206EC50 --cc ../2.0/sp2 --arm
 */
void func_0206EC50(void *arg)
{
    Root *r = g_02148DB0;
    ResHdr *h = r->h;
    u8 *p;
    u32 f;

    p = resolve(r->bank, h->idx01);
    f = ((u16 *)p)[0];
    p = p + 4;
    if ((f & 1) == 0) p += 0xc;
    if ((f & 2) == 0) { if ((f & 8) != 0) p += 4; else p += 0x10; }
    r->hook(arg, p, h, f);
}







/*
 * NitroSystem joint-rotation fetch from NNSG3dResNodeData (docs/notes/
 * pkt_0206EB00.c.txt): flag bit 1 trans zero, 2 rot zero, 8 pivot-compressed
 * (0xf0 the pivot index, 0x100 / 0x200 / 0x400 the pivot sign and the C / D
 * sign reversals over the four pivot-column tables at 0x020A1998..B), else
 * the nine rotation entries copied out.  func_020834A8 is MI_Zero36B.
 *
 * THE LEVER (wave 18, lane ties_a; it was DIFF 384/384, 14 bytes out for
 * seven waves): the pivot index k is `long`, not int.  With int, node and
 * k swap r4 / r5 at every use; mwcc colours long and int as different
 * types.  EXACT under ../2.0/sp2 as well.
 */
void func_0206ECE0(Out *out)
{
    Root *r = g_02148DB0;
    u8 *node;
    u32 f;
    s16 *p;
    long k;
    int u;
    int v;

    node = resolve(r->bank, r->h->idx01);
    f = ((u16 *)node)[0];
    p = (s16 *)(node + 4);
    if ((f & 1) == 0) p = (s16 *)((u8 *)p + 0xc);
    if ((f & 2) == 0) {
        if ((f & 8) != 0) {
            k = (int)(f & 0xf0) >> 4;
            u = p[0];
            v = p[1];
            func_020834A8(out->m);
            out->m[k] = (((struct Obj05777 *)node)->f0 & 0x100) ? -0x1000 : 0x1000;
            out->m[g_020A1998[k].c] = u;
            out->m[g_020A1999[k].c] = v;
            out->m[g_020A199A[k].c] = (((struct Obj05777 *)node)->f0 & 0x200) ? -v : v;
            out->m[g_020A199B[k].c] = (((struct Obj05777 *)node)->f0 & 0x400) ? -u : u;
        } else {
            out->m[0] = ((s16 *)node)[1];
            out->m[1] = p[0];
            out->m[2] = p[1];
            out->m[3] = p[2];
            out->m[4] = p[3];
            out->m[5] = p[4];
            out->m[6] = p[5];
            out->m[7] = p[6];
            out->m[8] = p[7];
        }
    } else {
        out->f00 |= 2;
    }
}








/*
 * The per-node channel decoder of the animation player (docs/families/
 * cluster_0206EB00.h, the driver).  Finds the node's record through the
 * u16 table at root+0x14, then walks the record's flag groups: the three
 * scalar channels (func_0206F214 / func_0206F36C) or the rotation-less
 * flags, the rotation (func_0206F844 / func_0206FC5C, or one packed key
 * through func_0206FFA0 with row 2 rebuilt by the cross product), and the
 * three vector-2 channels (func_0206F4C8 / func_0206F6B0) into the result
 * block, then emits through the stash's four-argument hook.  A dead node
 * (flags bit 0) emits with out->f00 = 7; the 0x600-guarded "stash" arm
 * hands off to func_0206EC50, which emits on its own.
 *
 * The 2026-09-21 source (docs/notes/pkt_0206EB00.c.txt) was 948/63, a
 * p/lerp register swap at 22 sites.  Two levers closed it (wave 10):
 *   - lerp is ONE conditional expression,
 *       lerp = ((t & 0xfff) != 0 && (root->f08 & 1) != 0) ? 1 : 0;
 *     which keeps the image's `movne r6,#1 / bne / mov r6,#0` shape and
 *     gives the cursor r5 (the goto form and the if/else form give the
 *     swap, the bare `&&` value is 944 bytes);
 *   - the cofactor block is FC5C's: three temporaries from direct field
 *     reads, stored after all three are computed (the six bound locals
 *     are 23 bytes of register naming out once lerp is right).
 * The flag groups are plain nested if/else (the earlier goto ladder
 * compiles identically).  Every group puts the call arm first.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206EE60.c \
 *       --func func_0206EE60 --addr 0x0206EE60 --arm --cc ../2.0/sp2p2
 */
void func_0206EE60(Hdr *root, u32 idx, u32 t, Out *out)
{
    u32 *p;
    u32 f;
    u32 *rec;
    int lerp;
    u32 res[6];
    u32 tmp[6];

    rec = (u32 *)((u8 *)root + *(u16 *)((u8 *)root + idx * 2 + 0x14));
    f = rec[0];
    if ((f & 1) != 0) {
        out->f00 = 7;
    } else {
        p = rec + 1;
        lerp = ((t & 0xfff) != 0 && (root->f08 & 1) != 0) ? 1 : 0;
        out->f00 = 0;

        if ((f & 6) == 0) {
            if ((f & 8) == 0) {
                if (lerp != 0)
                    func_0206F36C((int *)(&out->f4c), t, (Rec *)p, root);
                else
                    func_0206F214((int *)(&out->f4c), t, (Rec *)p, (u8 *)root);
                p = p + 2;
            } else {
                out->f4c = *p++;
            }
            if ((f & 0x10) == 0) {
                if (lerp != 0)
                    func_0206F36C((int *)(&out->f50), t, (Rec *)p, root);
                else
                    func_0206F214((int *)(&out->f50), t, (Rec *)p, (u8 *)root);
                p = p + 2;
            } else {
                out->f50 = *p++;
            }
            if ((f & 0x20) == 0) {
                if (lerp != 0)
                    func_0206F36C((int *)(&out->f54), t, (Rec *)p, root);
                else
                    func_0206F214((int *)(&out->f54), t, (Rec *)p, (u8 *)root);
                p = p + 2;
            } else {
                out->f54 = *p++;
            }
        } else if ((f & 2) != 0) {
            out->f00 = out->f00 | 4;
        } else {
            func_0206EBB8((u32 *)out);
        }

        if ((f & 0xc0) == 0) {
            if ((f & 0x100) == 0) {
                if (lerp != 0)
                    func_0206FC5C(&out->m[0], t, (Rec *)p, root);
                else
                    func_0206F844(&out->m[0], t, (Rec *)p, root);
                p = p + 2;
            } else {
                u32 *axis = (u32 *)((u8 *)root + root->f0c);
                u32 *rows = (u32 *)((u8 *)root + root->f10);
                if (func_0206FFA0((int *)((u32 *)&out->m[0]), (s16 *)axis, (s16 *)rows, *p) != 0) {
                    int a, b, c;
                    a = (out->m[1] * out->m[5] - out->m[2] * out->m[4]) >> 12;
                    b = (out->m[2] * out->m[3] - out->m[0] * out->m[5]) >> 12;
                    c = (out->m[0] * out->m[4] - out->m[1] * out->m[3]) >> 12;
                    out->m[6] = a;
                    out->m[7] = b;
                    out->m[8] = c;
                }
                p = p + 1;
            }
        } else if ((f & 0x40) != 0) {
            out->f00 = out->f00 | 2;
        } else {
            func_0206ECE0(out);
        }

        if ((f & 0x600) == 0) {
            if ((f & 0x800) == 0) {
                if (lerp != 0)
                    func_0206F6B0((int *)(&tmp[4]), t, (Rec *)p, root);
                else
                    func_0206F4C8((fx32 *)(&tmp[4]), t, (const NNSG3dJntAnmSInfo *)p, (const u8 *)root);
                res[0] = tmp[4];
                res[3] = tmp[5];
            } else {
                res[0] = p[0];
                res[3] = p[1];
            }
            if ((f & 0x1000) == 0) {
                if (lerp != 0)
                    func_0206F6B0((int *)(&tmp[2]), t, (Rec *)(p + 2), root);
                else
                    func_0206F4C8((fx32 *)(&tmp[2]), t, (const NNSG3dJntAnmSInfo *)(p + 2), (const u8 *)root);
                res[1] = tmp[2];
                res[4] = tmp[3];
            } else {
                res[1] = p[2];
                res[4] = p[3];
            }
            if ((f & 0x2000) == 0) {
                if (lerp != 0)
                    func_0206F6B0((int *)(&tmp[0]), t, (Rec *)(p + 4), root);
                else
                    func_0206F4C8((fx32 *)(&tmp[0]), t, (const NNSG3dJntAnmSInfo *)(p + 4), (const u8 *)root);
                res[2] = tmp[0];
                res[5] = tmp[1];
            } else {
                res[2] = p[4];
                res[5] = p[5];
            }
        } else if ((f & 0x200) != 0) {
            out->f00 = out->f00 | 1;
        } else {
            func_0206EC50(out);
            return;
        }
    }

    {
        u32 k = (out->f00 & 1) ? 4 : 0;
        Root *d = g_02148DB0;
        d->hook(out, &res[0], d->h, k);
    }
}








/*
 * Scalar keyframe sampler without the lerp (func_0206EE60 calls it for the
 * three scalar channels when the cursor has no fraction or root->f08 bit 0 is
 * clear): the same flag cascade as src/matched/func_02070524.c, writing the
 * key (plain), the mean of two keys (two:) or the 3:1 blend of two keys into
 * *out.  Flags bit 29 selects s16 keys over s32_0206ECE0 keys; the s32_0206ECE0 3:1 blend is a
 * 64-bit expression.
 *
 * Per-file compiler pin ../2.0/sp2p2, NOT the packet's ../2.0/sp2, on a new
 * front-end tell (docs/FRONTEND-PINS.md, "64-bit multiply by a constant"):
 * the image multiplies the sign-extended s32_0206ECE0 key by 3 as
 * `mov r2, #3` / `umull lr, ip, r3, r2` / `asr r3, r3, #0x1f` /
 * `mla ip, r3, r2, ip` at 0x0206F2CC..0x0206F2D8, i.e. it knows the
 * constant's high word is zero.  ../2.0/sp2 (and 2.0 base/sp1/sp1p5) never
 * fold it: every spelling adds `mov ip, #0` / `mla hi, lo, ip, hi`, which
 * costs two more callee-saved registers (`push {r3, r4, r5, lr}` against the
 * image's `push {r4, lr}`) and the same C is 352 bytes / 184 concrete bytes
 * out.  dsi/1.1p1 folds the multiply but predicates the image's kept
 * branches (336 bytes, 82 out).  ../2.0/sp2p2 (and sp2p3/sp2p4) do both:
 * 344 bytes, 0 mismatches.  Every other matched member of this family is
 * also EXACT under sp2p2, so this is a refinement of the family pin rather
 * than a different compiler.
 *
 * Source levers (the permuter, tools/permuter.py, found the last two):
 *   - statements in the order off, k, p, flags: k must be taken from t
 *     before p is formed so that p reuses t's register (r1) and k lands in r4;
 *   - `plain:` is written s16-arm first with its own return; 2.0 inverts it
 *     into the image's `ldreq/streq/popeq` word arm.  Word-arm-first is
 *     predicated whole and four bytes short;
 *   - `two:` spelled as func_02070524's `two:` block (pointer g / byte
 *     offset o for s16, pointer w built in the arm for s32_0206ECE0, (w+4) read first);
 *   - the `k & 2` arm goes through a named temporary `q` (`k = k >> 2`
 *     directly is 77 bytes out: the value numbering moves k out of r4);
 *   - the 64-bit product is bound to a function-scope `w3` before the sum, so
 *     the `adds` takes the product as its first operand.
 *
 * No relocation sites.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206F214.c \
 *       --func func_0206F214 --addr 0x0206F214 --cc ../2.0/sp2p2 --arm
 */
void func_0206F214(int *out, int t, Rec *r, u8 *base)
{
    int *p;
    u32 f;
    u32 k;
    u32 off;
    u32 n, i0, q;
    int a, b;
    long long w3;

    off = r->off04;
    k = (u32)(t >> 12);
    p = (int *)(base + off);
    f = r->flags;

    if (f & 0xc0000000) {
        n = (f & 0x1fff0000) >> 16;
        if (f & 0x40000000) {
            if (k & 1) {
                if (k > n) {
                    k = (n >> 1) + 1;
                    goto plain;
                }
                k = k >> 1;
                goto two;
            }
            k = k >> 1;
            goto plain;
        } else {
            u32 m = k & 3;
            if (m != 0) {
                if (k > n) { k = m + (n >> 2); goto plain; }
                if (k & 1) {
                    if (k & 2) { q = k >> 2; k = q; i0 = k + 1; }
                    else { i0 = k >> 2; k = i0 + 1; }
                    if (f & 0x20000000) {
                        a = ((s16 *)p)[i0];
                        b = ((s16 *)p)[k];
                        a *= 3;
                        a += b;
                        *out = a >> 2;
                        return;
                    }
                    w3 = (long long)p[i0] * 3;
                    *out = (int)((w3 + p[k]) >> 2);
                    return;
                }
                k = k >> 2;
                goto two;
            }
            k = k >> 2;
        }
    }
    goto plain;

two:
    if (f & 0x20000000) {
        s16 *g = (s16 *)p + k;
        u32 o = k << 1;
        a = *(s16 *)((u8 *)p + o);
        b = g[1];
        a = (a + b) >> 1;
    } else {
        int *w = p + k;
        b = ((struct Obj16634 *)w)->f4;
        a = p[k];
        a = (a >> 1) + (b >> 1);
    }
    *out = a;
    return;

plain:
    if (f & 0x20000000) {
        *out = ((s16 *)p)[k];
        return;
    }
    *out = p[k];
}






/*
 * Scalar lerp sampler over the animation record (flags word, data offset)
 * and the animation root (key count at +4, flags at +8).  func_0206EE60
 * calls it for the three scalar channels when the cursor has a fraction and
 * root->f08 bit 0 is set.  The last key either wrap-blends against key 0
 * (root->f08 bit 1) or is fetched plain; every other key picks a
 * (mask, mul, shift) triple per stride and falls into one shared lerp tail.
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md): the
 * image predicates the wrap blend's word arm and BRANCHES over the s16 arm
 * (`ldreq r3,[ip,lr,lsl #2]` / `ldreq r1,[ip]` / `beq 0x0206F3DC` at
 * 0x0206F3C4..0x0206F3CC); dsi/1.1p1 -O4,p predicates both arms, giving 340
 * bytes against 348, 232 concrete bytes out.  Under ../2.0/sp2 the same C
 * is 348 bytes, 0 mismatches.
 *
 * Closing levers over the earlier 185-byte residue in
 * docs/notes/pkt_0206EB00.c.txt: every width choice is written s16-arm
 * FIRST as a plain if/else (no goto to a shared label); the lerp tail's two
 * arms are spelled exactly as src/matched/func_02070524.c's `two:` block
 * (s16 via a byte offset `k << 1` plus a pointer `g`, word via a pointer
 * `w` built inside the arm); and in `last:` the mask is assigned before
 * `mul = 1`.
 *
 * No relocation sites.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206F36C.c \
 *       --func func_0206F36C --addr 0x0206F36C --cc ../2.0/sp2 --arm
 */
void func_0206F36C(int *out, int t, Rec *r, Hdr *h)
{
    u8 *p = (u8 *)h + r->off04;
    u32 f = r->flags;
    int k = t >> 12;
    u32 n, frac, mul, sh;
    int a, b;

    if ((int)(h->cnt04 - 1) != (t >> 12)) goto general;

    if ((f & 0xc0000000) != 0) {
        if ((f & 0x40000000) != 0) {
            k = (k & 1) + ((u32)k >> 1);
        } else {
            k = (k & 3) + ((u32)k >> 2);
        }
    }
    if ((h->f08 & 2) != 0) {
        frac = t & 0xfff;
        if ((f & 0x20000000) != 0) {
            a = ((s16 *)p)[k];
            b = *(s16 *)&((struct Obj04095 *)p)->f0;
        } else {
            a = ((int *)p)[k];
            b = ((struct Obj04095 *)p)->f0;
        }
        *out = a + (((b - a) * (int)frac) >> 12);
        return;
    }
    if ((f & 0x20000000) != 0) {
        *out = ((s16 *)p)[k];
    } else {
        *out = ((int *)p)[k];
    }
    return;

general:
    if ((f & 0xc0000000) == 0) goto last;
    {
        u32 w = f & 0x1fff0000;
        n = w >> 16;
    }
    if ((f & 0x40000000) != 0) {
        if ((u32)k >= n) {
            k = n >> 1;
            goto last;
        }
        k = (u32)k >> 1;
        t = t & (int)(0x1fff0000u >> 16);
        mul = 2;
        sh = 1;
        goto lerp;
    }
    if ((u32)k >= n) {
        k = (k & 3) + ((u32)k >> 2);
        goto last;
    }
    k = (u32)k >> 2;
    t = t & 0x3fff;
    mul = 4;
    sh = 2;
    goto lerp;
last:
    t = t & 0xfff;
    mul = 1;
    sh = 0;
lerp:
    if ((f & 0x20000000) != 0) {
        s16 *g = (s16 *)p + k;
        u32 o = (u32)k << 1;
        a = *(s16 *)(p + o);
        b = g[1];
    } else {
        int *w = (int *)p + k;
        a = ((int *)p)[k];
        b = ((struct Obj16636 *)w)->f4;
    }
    *out = (int)((a * (int)mul + (((b - a) * t) >> 12)) >> sh);
}





/*
 * Vector-2 keyframe sampler without the lerp (func_0206EE60 calls it when the
 * cursor has no fraction or root->f08 bit 0 is clear): the NitroSystem G3D
 * joint-animation scale fetch, which reads a (scale, inverse scale) pair per
 * key.  Written from the start in the library's shape (wave 20, lane
 * nns_fresh): the NNS_G3D_JNTANM_SINFO_* step / last-interp / fx16 flags,
 * the frame through FX_Whole, one pArray base, the goto SCALE_NONINTERP /
 * SCALE_INTERP_2 tails and the inline 1:3 blend, keys as (s, invs) pair
 * structs.  The NitroSystem name of the routine is not attested in this
 * repository; the identifiers follow the library's style only.
 *
 * Compiler pin ../2.0/sp2p2, the family pin (docs/families/cluster_0206EB00.h,
 * "64-bit multiply by a constant"): ../2.0/sp2 and dsi/1.1p1 both DIFF.
 *
 * Source levers, all read off the image:
 *   - frame taken before pArray and info, so pArray reuses Frame's r1;
 *   - keys indexed through pair structs (a flat fx16/fx32 array with 2 * idx
 *     emits an extra lsl per key, 556 bytes);
 *   - SCALE_INTERP_2 through one element pointer `base + idx` read at [0]
 *     and [1] (array subscripts at idx and idx + 1 form idx + 1 separately);
 *   - fx32 1:3 blend through element pointers for idx and idx_sub and the
 *     64-bit product named, `w = (fx64)v * 3; (w + v_sub) >> 2`, which puts
 *     the product first in the adds (the unnamed sum canonicalises to
 *     v_sub first, the old 2-byte residue);
 *   - fx16 1:3 blend by array subscript with the base advanced to the
 *     idx_sub element for the second key, so that address forms in the
 *     base's dying register.
 *
 * No relocation sites.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206F4C8.c \
 *       --func func_0206F4C8 --addr 0x0206F4C8 --cc ../2.0/sp2p2 --arm
 */
void func_0206F4C8(fx32 *s_invs, fx32 Frame, const NNSG3dJntAnmSInfo *pData, const u8 *pJntAnm)
{
    u32 frame = (u32)FX_Whole(Frame);
    const void *pArray = (const void *)(pJntAnm + pData->offset);
    u32 info = pData->info;
    u32 last_interp;
    u32 idx;
    u32 idx_sub;

    if (!(info & NNS_G3D_JNTANM_SINFO_STEP_MASK))
    {
        idx = frame;
        goto SCALE_NONINTERP;
    }

    last_interp = (info & NNS_G3D_JNTANM_SINFO_LASTINTERP_MASK) >> NNS_G3D_JNTANM_SINFO_LASTINTERP_SHIFT;

    if (info & NNS_G3D_JNTANM_SINFO_STEP_2)
    {
        if (frame & 1)
        {
            if (frame > last_interp)
            {
                idx = (last_interp >> 1) + 1;
                goto SCALE_NONINTERP;
            }
            else
            {
                idx = frame >> 1;
                goto SCALE_INTERP_2;
            }
        }
        else
        {
            idx = frame >> 1;
            goto SCALE_NONINTERP;
        }
    }
    else
    {
        if (frame & 3)
        {
            if (frame > last_interp)
            {
                idx = (last_interp >> 2) + (frame & 3);
                goto SCALE_NONINTERP;
            }

            if (frame & 1)
            {
                fx32 v, v_sub;

                if (frame & 2)
                {
                    idx_sub = frame >> 2;
                    idx = idx_sub + 1;
                }
                else
                {
                    idx = frame >> 2;
                    idx_sub = idx + 1;
                }

                if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY)
                {
                    const ScaleFx16 *p_fx16 = (const ScaleFx16 *)pArray;

                    v = p_fx16[idx].s;
                    v_sub = p_fx16[idx_sub].s;
                    s_invs[0] = (v * 3 + v_sub) >> 2;

                    v = p_fx16[idx].invs;
                    p_fx16 += idx_sub;
                    v_sub = p_fx16->invs;
                    s_invs[1] = (v * 3 + v_sub) >> 2;
                }
                else
                {
                    const ScaleFx32 *p_fx32 = (const ScaleFx32 *)pArray + idx;
                    const ScaleFx32 *p_fx32_sub = (const ScaleFx32 *)pArray + idx_sub;

                    fx64 w;

                    v = p_fx32->s;
                    v_sub = p_fx32_sub->s;
                    w = (fx64)v * 3;
                    s_invs[0] = (fx32)((w + v_sub) >> 2);

                    v = p_fx32->invs;
                    v_sub = p_fx32_sub->invs;
                    w = (fx64)v * 3;
                    s_invs[1] = (fx32)((w + v_sub) >> 2);
                }

                return;
            }
            else
            {
                idx = frame >> 2;
                goto SCALE_INTERP_2;
            }
        }
        else
        {
            idx = frame >> 2;
            goto SCALE_NONINTERP;
        }
    }

SCALE_NONINTERP:
    if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY)
    {
        const ScaleFx16 *p_fx16 = (const ScaleFx16 *)pArray;
        s_invs[0] = p_fx16[idx].s;
        s_invs[1] = p_fx16[idx].invs;
    }
    else
    {
        const ScaleFx32 *p_fx32 = (const ScaleFx32 *)pArray;
        s_invs[0] = p_fx32[idx].s;
        s_invs[1] = p_fx32[idx].invs;
    }
    return;

SCALE_INTERP_2:
    if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY)
    {
        const ScaleFx16 *p_fx16 = (const ScaleFx16 *)pArray + idx;
        s_invs[0] = (p_fx16[0].s + p_fx16[1].s) >> 1;
        s_invs[1] = (p_fx16[0].invs + p_fx16[1].invs) >> 1;
    }
    else
    {
        const ScaleFx32 *p_fx32 = (const ScaleFx32 *)pArray + idx;
        s_invs[0] = (p_fx32[0].s + p_fx32[1].s) >> 1;
        s_invs[1] = (p_fx32[0].invs + p_fx32[1].invs) >> 1;
    }
}




/*
 * Vector-2 lerp sampler: the two-component sibling of func_0206F36C (same
 * record, same header, same flag cascade), called by func_0206EE60 for the
 * three vector channels when the cursor has a fraction and root->f08 bit 0 is
 * set.  Keys are V2i (8-byte stride) or, with flags bit 29, V2s (4-byte).
 * The last key either wraps against key 0 (hdr->f08 bit 1, k2 = 0 into the
 * shared lerp tail) or is fetched plain; otherwise the (mask, mul, shift)
 * triple is chosen per stride and one shared tail lerps both components.
 *
 * Per-file compiler pin, "kept branches" tell (docs/FRONTEND-PINS.md): the
 * image keeps `tst r2, #0x20000000` / `beq 0x0206F720` at 0x0206F700 /
 * 0x0206F704 over the six-instruction V2s plain-fetch arm; dsi/1.1p1 -O4,p
 * predicates the V2i arm instead (`ldreq/addeq/streq/ldreq`) and the same C
 * is 392 bytes against 404, 285 concrete bytes out.  Under ../2.0/sp2 the
 * same C is 404 bytes, 0 mismatches.
 *
 * Two source levers: keys indexed through the V2s/V2i struct types (an
 * `int` subscript `[k * 2]` emits an extra `lsl`), and in `last:` the mask
 * `t & 0xfff` assigned BEFORE `mul = 1` (the other order lets the compiler
 * derive 0xfff as `rsb r5, r4, #0x1000` and drop the pool word, 4 bytes).
 *
 * No relocation sites.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206F6B0.c \
 *       --func func_0206F6B0 --addr 0x0206F6B0 --cc ../2.0/sp2 --arm
 */
void func_0206F6B0(int *out, int t, Rec *r, Hdr *h)
{
    u8 *p = (u8 *)h + r->off04;
    u32 f = r->flags;
    int k = t >> 12;
    u32 n, k2, mul, sh;
    int a0, a1, b0, b1;

    if ((int)(h->cnt04 - 1) != (t >> 12)) goto general;

    if ((f & 0xc0000000) != 0) {
        if ((f & 0x40000000) != 0) {
            k = (k & 1) + ((u32)k >> 1);
        } else {
            k = (k & 3) + ((u32)k >> 2);
        }
    }
    if ((h->f08 & 2) != 0) {
        k2 = 0;
        goto last;
    }
    if ((f & 0x20000000) != 0) {
        out[0] = ((V2s *)p)[k].x;
        out[1] = ((V2s *)p)[k].y;
    } else {
        out[0] = ((V2i *)p)[k].x;
        out[1] = ((V2i *)p)[k].y;
    }
    return;

general:
    if ((f & 0xc0000000) == 0) goto next;
    {
        u32 w = f & 0x1fff0000;
        n = w >> 16;
    }
    if ((f & 0x40000000) != 0) {
        if ((u32)k >= n) {
            k = n >> 1;
            k2 = k + 1;
            goto last;
        }
        k = (u32)k >> 1;
        k2 = k + 1;
        t = t & (int)(0x1fff0000u >> 16);
        mul = 2;
        sh = 1;
        goto lerp;
    }
    if ((u32)k >= n) {
        k = (k & 3) + ((u32)k >> 2);
        k2 = k + 1;
        goto last;
    }
    k = (u32)k >> 2;
    k2 = k + 1;
    t = t & 0x3fff;
    mul = 4;
    sh = 2;
    goto lerp;
next:
    k2 = k + 1;
last:
    t = t & 0xfff;
    mul = 1;
    sh = 0;
lerp:
    if ((f & 0x20000000) != 0) {
        a0 = ((V2s *)p)[k].x;
        a1 = ((V2s *)p)[k].y;
        b0 = ((V2s *)p)[k2].x;
        b1 = ((V2s *)p)[k2].y;
    } else {
        a0 = ((V2i *)p)[k].x;
        a1 = ((V2i *)p)[k].y;
        b0 = ((V2i *)p)[k2].x;
        b1 = ((V2i *)p)[k2].y;
    }
    out[0] = (int)((a0 * (int)mul + (((b0 - a0) * t) >> 12)) >> sh);
    out[1] = (int)((a1 * (int)mul + (((b1 - a1) * t) >> 12)) >> sh);
}




/*
 * Rotation keyframe sampler without the lerp (docs/families/
 * cluster_0206EB00.h): func_0206F214's flag cascade with func_0206FFA0
 * decodes in place of key loads.  plain: decode key k into out, rebuild
 * row 2 by the cross product if the decode returned 1, else normalise it;
 * two: decode k2 into out and k2+1 into mb and sum; 3:1: decode i0 into out
 * and k2 into ma, out = ma + out * 3.  Rows 0 and 1 are normalised with
 * VEC_Normalize; row 2 is lerped and normalised only when neither decode
 * returned 1, else rebuilt by the cross product.
 *
 * Wave 9 left it at 1048/10 (k2 and ok of the 3:1 arm swapped, sb/sl).
 * Closed in wave 10: the 3:1 arm's decode accumulator is its OWN variable,
 * declared with its initialiser at the top of the `if (k & 1)` block
 * (`u32 ok2 = 0;`).  A separate function-scope variable assigned 0 at the
 * same point does not move the swap (six positions measured in wave 9).
 * The cross product is three temporaries from direct field reads, stored
 * after all three are computed; the two path's second decode indexes
 * `((u16 *)p + k2)[1]`.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206F844.c \
 *       --func func_0206F844 --addr 0x0206F844 --arm --cc ../2.0/sp2p2
 */
void func_0206F844(int *out, int t, Rec *r, Hdr *h)
{
    u32 f;
    u32 k;
    u32 n, i0;
    u32 ob;
    u32 oa;
    u8 *p;
    u32 ok;
    u32 k2;
    int ma[9];
    int mb[9];

    f = r->flags;
    k = (u32)(t >> 12);
    p = (u8 *)h + r->off04;
    oa = h->f0c;
    ob = h->f10;

    if (f & 0xc0000000) {
        n = (f & 0x1fff0000) >> 16;
        if (f & 0x40000000) {
            if (k & 1) {
                if (k > n) {
                    k = (n >> 1) + 1;
                    goto plain;
                }
                k2 = k >> 1;
                goto two;
            }
            k = k >> 1;
            goto plain;
        } else {
            u32 m = k & 3;
            if (m != 0) {
                if (k > n) { k = m + (n >> 2); goto plain; }
                if (k & 1) {
                    u32 ok2 = 0;

                    if (k & 2) { k2 = k >> 2; i0 = k2 + 1; }
                    else { i0 = k >> 2; k2 = i0 + 1; }
                    ok2 |= func_0206FFA0(out, (s16 *)((u8 *)h + oa), (s16 *)((u8 *)h + ob), ((u16 *)p)[i0]);
                    ok2 |= func_0206FFA0(ma, (s16 *)((u8 *)h + oa), (s16 *)((u8 *)h + ob), ((u16 *)p)[k2]);
                    out[0] = ma[0] + out[0] * 3;
                    out[1] = ma[1] + out[1] * 3;
                    out[2] = ma[2] + out[2] * 3;
                    out[3] = ma[3] + out[3] * 3;
                    out[4] = ma[4] + out[4] * 3;
                    out[5] = ma[5] + out[5] * 3;
                    VEC_Normalize(out, out);
                    VEC_Normalize(out + 3, out + 3);
                    if (ok2 == 0) {
                        out[6] = ma[6] + out[6] * 3;
                        out[7] = ma[7] + out[7] * 3;
                        out[8] = ma[8] + out[8] * 3;
                        VEC_Normalize(out + 6, out + 6);
                    } else {
                        int a, b, c;
                        a = (out[1] * out[5] - out[2] * out[4]) >> 12;
                        b = (out[2] * out[3] - out[0] * out[5]) >> 12;
                        c = (out[0] * out[4] - out[1] * out[3]) >> 12;
                        out[6] = a;
                        out[7] = b;
                        out[8] = c;
                    }
                    return;
                }
                k2 = k >> 2;
                goto two;
            }
            k = k >> 2;
        }
    }
    goto plain;

two:
    ok = 0;
    ok |= func_0206FFA0(out, (s16 *)((u8 *)h + oa), (s16 *)((u8 *)h + ob), ((u16 *)p)[k2]);
    ok |= func_0206FFA0(mb, (s16 *)((u8 *)h + oa), (s16 *)((u8 *)h + ob), ((u16 *)p + k2)[1]);
    out[0] = out[0] + mb[0];
    out[1] = out[1] + mb[1];
    out[2] = out[2] + mb[2];
    out[3] = out[3] + mb[3];
    out[4] = out[4] + mb[4];
    out[5] = out[5] + mb[5];
    VEC_Normalize(out, out);
    VEC_Normalize(out + 3, out + 3);
    if (ok == 0) {
        out[6] = out[6] + mb[6];
        out[7] = out[7] + mb[7];
        out[8] = out[8] + mb[8];
        VEC_Normalize(out + 6, out + 6);
    } else {
        int a, b, c;
        a = (out[1] * out[5] - out[2] * out[4]) >> 12;
        b = (out[2] * out[3] - out[0] * out[5]) >> 12;
        c = (out[0] * out[4] - out[1] * out[3]) >> 12;
        out[6] = a;
        out[7] = b;
        out[8] = c;
    }
    return;

plain:
    if (func_0206FFA0(out, (s16 *)((u8 *)h + oa), (s16 *)((u8 *)h + ob), ((u16 *)p)[k]) != 0) {
        int a, b, c;
        a = (out[1] * out[5] - out[2] * out[4]) >> 12;
        b = (out[2] * out[3] - out[0] * out[5]) >> 12;
        c = (out[0] * out[4] - out[1] * out[3]) >> 12;
        out[6] = a;
        out[7] = b;
        out[8] = c;
    } else {
        VEC_Normalize(out + 6, out + 6);
    }
}




/*
 * Rotation keyframe sampler with the lerp (docs/families/cluster_0206EB00.h),
 * the NitroSystem nsbca rotation-sampler shape: the func_0206F6B0 flag
 * cascade, keys decoded by func_0206FFA0 from the two key arrays of the
 * header (rot3 at +0x0c, rot9 at +0x10), rows 0 and 1 lerped and
 * VEC_Normalize'd, row 2 rebuilt by the cross product when either decode
 * returned 1, else lerped and normalised.  Same C under ../2.0/sp2p2 (the
 * family pin, docs/FRONTEND-PINS.md func_0206F214 row); dsi/1.1p1 is 824
 * bytes against 836.
 *
 * Closed in wave 17 (was 8 out, p and oa swapped): the two key arrays are
 * POINTER locals computed once at the top, `oa = (s16 *)((u8 *)h +
 * h->f0c)`, as NitroSystem spells pArrayRot3 / pArrayRot9, not u32
 * offsets added at each call (the compiler still re-forms the address at
 * every call site, so the bytes do not show the difference), plus the
 * declaration order below, found by sampling 200 orders of the ten scalar
 * locals of the pointer form (several orders reach 0; the u32-offset form
 * was flat at 8 over 650+ orders in waves 9 to 16).
 */
void func_0206FC5C(int *out, int t, Rec *r, Hdr *h)
{
    int k;
    u32 ok;
    s16 *oa;
    u32 k2;
    int frac;
    u32 mul;
    u32 n;
    u32 f;
    u8 *p;
    s16 *ob;
    int m0[9];
    int m1[9];

    p = (u8 *)h + r->off04;
    k = t >> 12;
    oa = (s16 *)((u8 *)h + h->f0c);
    ob = (s16 *)((u8 *)h + h->f10);
    f = r->flags;

    if ((int)(h->cnt04 - 1) != (t >> 12)) goto general;

    if ((f & 0xc0000000) != 0) {
        if ((f & 0x40000000) != 0) {
            k = (k & 1) + ((u32)k >> 1);
        } else {
            k = (k & 3) + ((u32)k >> 2);
        }
    }
    if ((h->f08 & 2) != 0) {
        k2 = 0;
        goto last;
    }
    if (func_0206FFA0(out, oa, ob, ((u16 *)p)[k]) != 0) {
        {
            int a, b, c;
            a = (out[1] * out[5] - out[2] * out[4]) >> 12;
            b = (out[2] * out[3] - out[0] * out[5]) >> 12;
            c = (out[0] * out[4] - out[1] * out[3]) >> 12;
            out[6] = a;
            out[7] = b;
            out[8] = c;
        }
    } else {
        VEC_Normalize(out + 6, out + 6);
    }
    return;

general:
    if ((f & 0xc0000000) == 0) goto next;
    {
        u32 w = f & 0x1fff0000;
        n = w >> 16;
    }
    if ((f & 0x40000000) != 0) {
        if ((u32)k >= n) {
            k = n >> 1;
            k2 = k + 1;
            goto last;
        }
        k = (u32)k >> 1;
        k2 = k + 1;
        frac = t & (int)(0x1fff0000u >> 16);
        mul = 2;
        goto lerp;
    }
    if ((u32)k >= n) {
        k = (k & 3) + ((u32)k >> 2);
        k2 = k + 1;
        goto last;
    }
    k = (u32)k >> 2;
    k2 = k + 1;
    frac = t & 0x3fff;
    mul = 4;
    goto lerp;
next:
    k2 = k + 1;
last:
    frac = t & 0xfff;
    mul = 1;
lerp:
    ok = 0;
    ok |= func_0206FFA0(m0, oa, ob, ((u16 *)p)[k]);
    ok |= func_0206FFA0(m1, oa, ob, ((u16 *)p)[k2]);
    out[0] = m0[0] * (int)mul + (((m1[0] - m0[0]) * frac) >> 12);
    out[1] = m0[1] * (int)mul + (((m1[1] - m0[1]) * frac) >> 12);
    out[2] = m0[2] * (int)mul + (((m1[2] - m0[2]) * frac) >> 12);
    out[3] = m0[3] * (int)mul + (((m1[3] - m0[3]) * frac) >> 12);
    out[4] = m0[4] * (int)mul + (((m1[4] - m0[4]) * frac) >> 12);
    out[5] = m0[5] * (int)mul + (((m1[5] - m0[5]) * frac) >> 12);
    VEC_Normalize(out, out);
    VEC_Normalize(out + 3, out + 3);
    if (ok == 0) {
        out[6] = m0[6] * (int)mul + (((m1[6] - m0[6]) * frac) >> 12);
        out[7] = m0[7] * (int)mul + (((m1[7] - m0[7]) * frac) >> 12);
        out[8] = m0[8] * (int)mul + (((m1[8] - m0[8]) * frac) >> 12);
        VEC_Normalize(out + 6, out + 6);
    } else {
            int a, b, c;
            a = (out[1] * out[5] - out[2] * out[4]) >> 12;
            b = (out[2] * out[3] - out[0] * out[5]) >> 12;
            c = (out[0] * out[4] - out[1] * out[3]) >> 12;
            out[6] = a;
            out[7] = b;
            out[8] = c;
        }
}



/*
 * Decodes one packed rotation key into a 3x3 matrix (docs/families/
 * cluster_0206EB00.h, section 5).  id bit 15 set: an axis permutation --
 * clear the matrix, put +-1.0 (bit 4 of the row's first word) on the axis
 * nibble's slot and the two remaining row values (negated by bits 5 and 6)
 * on the slots the four Perm columns name; returns 0.  Bit 15 clear: five
 * quantised s16 row values (>> 3 each) whose low three bits pack a 13-bit
 * sixth value (row 1 col 2, sign-extended); returns 1, and the caller
 * rebuilds row 2 by the cross product.
 *
 * Two levers closed it (75 -> 0 bytes, wave 10):
 *   - the Perm columns are `const`: mwcc then knows a store through `out`
 *     cannot modify them and hoists each column's `ldrb` above the earlier
 *     stores, which is the image's order (load 1998, store out[k], load 1999,
 *     store, store).  Non-const, the loads stay after the stores (32 out);
 *   - the packed arm is written row by row (load, store >> 3, fold into p),
 *     not as five loads followed by the packing chain (53 -> 0 in that arm).
 * The whole-matrix clear is written highest element first.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206FFA0.c \
 *       --func func_0206FFA0 --addr 0x0206FFA0 --arm --cc ../2.0/sp2p2
 */
int func_0206FFA0(int *out, s16 *a, s16 *b, u32 id)
{
    if (id & 0x8000) {
        u32 i;
        s16 *row;
        int h0, h1, h2, k;

        out[8] = 0;
        out[7] = 0;
        out[6] = 0;
        out[5] = 0;
        out[4] = 0;
        out[3] = 0;
        out[2] = 0;
        out[1] = 0;
        out[0] = 0;
        i = (id & 0x7fff) * 3;
        row = a + i;
        h0 = a[i];
        h1 = row[1];
        h2 = row[2];
        k = h0 & 0xf;
        out[k] = (h0 & 0x10) ? -0x1000 : 0x1000;
        out[g_020A1998[k].c] = h1;
        out[g_020A1999[k].c] = h2;
        out[g_020A199A[k].c] = (row[0] & 0x20) ? -h2 : h2;
        out[g_020A199B[k].c] = (row[0] & 0x40) ? -h1 : h1;
        return 0;
    } else {
        u32 i = (id & 0x7fff) * 5;
        s16 *row = b + i;
        s16 v0, v1, v2, v3, v4, p;

        v4 = row[4];
        out[4] = v4 >> 3;
        p = v4 & 7;
        v0 = b[i];
        out[0] = v0 >> 3;
        p = (v0 & 7) | (p << 3);
        v1 = row[1];
        out[1] = v1 >> 3;
        p = (v1 & 7) | (p << 3);
        v2 = row[2];
        out[2] = v2 >> 3;
        p = (v2 & 7) | (p << 3);
        v3 = row[3];
        out[3] = v3 >> 3;
        p = (v3 & 7) | (p << 3);
        out[5] = (p << 19) >> 19;
        return 1;
    }
}
