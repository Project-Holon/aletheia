/*
 * function: func_021F56BC
 * address:  0x021F56BC
 * packet:   pkt_ov112_021F56BC
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note (2026-10-04, wave D3 lane 03): first complete structural draft, not tuned.
 *   Listing extent 021F56BC..021F5EDC (2080 bytes), frame 0x254, mid pool at 021F5A24
 *   (0x04000444, 02148D8C/98/A4, 021F8310/1C/04, 02148B98, 0xFFFFF000, 0xFFFA0000,
 *   02148B54, 0x04000470, 020A1B38 sin/cos table, 0x0400046C) and tail pool 021F5ED0.
 *   Shape: G3 setup (push, mode 0, store 0, mode 3, identity, mode 2); camera pick by
 *   p->f8 bit 0; outer loop i < p[0] over p[1][i] objects, skip null or (fEC >> 2) & 1;
 *   per object a 16-byte pose rec at sp+0x244 filled by kind 0/1/2 of
 *   obj+0x28 -> [0x1c] -> f4; translation/rotation/scale writes; func_021F65EC;
 *   polygon attr word built from bitfields at obj+0x90; inner loop j over parts of
 *   p->f6C->f4[rec.id]; second pose rec at sp+0x234; two func_021F5EDC calls;
 *   innermost k < 8 over bytes ent[0x30+k] != 0xFF with s64 fixed point math and
 *   an indirect call through p->fF8.
 *   Known hard parts: the compiler derives small constants from register-held I/O
 *   addresses (lsrs r1, r0, #0x13 = 0x80 from 0x04000470; lsrs #0xe = 0x1000 from
 *   0x0400046C; r0 >> 0x12 = 0x100), the float rounding idiom
 *   (v > 0 ? (float)(v << 12) + 0.5f : (float)(v << 12) - 0.5f) then _ffix, and the
 *   many spilled loop-invariant offsets at sp+0x80..0xAC (0x80 constants and
 *   field offsets r5-8, r5-4 with r5 = 0x10C).
 *   The innermost k-loop math is an approximation of the listing (021F5BD4..021F5E8C),
 *   re-derive it from the listing before tuning.
 *   Verdict of this draft: DIFF, compiled 1680 bytes vs 2080, 1623 bytes differ, 52 of 55
 *   relocations resolved. Prologue already differs (push r3 extra, frame 0x198 vs 0x254):
 *   the original keeps more stack locals (spilled invariants at sp+0x80..0xAC, s64 halves
 *   at sp+0x68..0x74, sub-pose rec at sp+0x234, 0x5C-byte source records).
 *   Siblings: func_021F5EDC (callee, 13 args, see 021F5B6A..021F5BCC for the stack layout).
 *
 * note (2026-10-05, wave D4 lane 06): p->f8 bit 0 is now read through a one-bit bitfield
 *   (Bits.b0): the camera pick now gives the original lsls #0x1f; lsrs #0x1f test (1623 -> 1611
 *   bytes differ, compiled 1684 vs 2080).  Still open: the frame (0x254 vs 0x198, push without
 *   r3), the zero local stored at [sp] at entry, the spilled invariants, and the innermost k-loop
 *   which still needs re-deriving from the listing (021F5BD4..021F5E8C).
 *
 * note (2026-10-05, wave D5 lane 06): body rewritten from a fresh reading of the listing
 *   (the code after the mid pool needs `show --addr 0x021F5A5C --size 0x480 --thumb`, the
 *   default show desyncs at 021F5A44).  Fixes: r4 is obj for the whole loop, so the j/k loops
 *   read obj+0x6C/0x68/0x20/0x24/0xF8, func_021F5EDC takes obj (not p) and &cb.z (sp+0xB8,
 *   zeroed per object), and the indirect call goes through the second parameter `arg`
 *   (`arg((u8)pt->f4, &cb.pos, obj->fF8)`); a 0x3C-byte callback record at sp+0xB4 (w out
 *   word, z, pos with y negated, x2/y2 scaled by obj->fD4/16 and fD8/16, z, obj+0xD4 vec,
 *   obj+0x100 vec, obj->fFC, ang + (pt->f10 << 11)); on pt->f4 == 5 the result goes to
 *   obj+0x100/0x104/0x108.  k loop: two rotations (part by pose.rot + sub.rot scaled by the
 *   pose*sub scale, then the table entry (x, z at +2/+4) plus pose.dx/dz by pose.rot scaled by
 *   pose.sx/sy), operand order (s64)vec * scale.  Else-branch: a local 4x4 matrix filled with
 *   constants at sp+0x114, func_0207B5C0(&d_02148B98, &m4), func_0207BE14(&m4, &d_02148B54,
 *   &m4), second func_021F660C uses that matrix.  Sub-pose kind 0 leaves dz unset.  obj skip
 *   test reads p[1][i] twice and bit 2 of obj->fEC as a bitfield; obj+0x90 and obj+0x68 are
 *   loop-level pointer locals (sp+0x5C, sp+0x50).  Result: compiled 1996 vs 2080 (was 1684),
 *   frame 0x248 vs 0x254, prologue and the obj test now line up modulo slot numbers.
 *   Open: the zero stored at [sp] at entry (push without r3 in the original), the i slot
 *   (0x5C vs 0x58), mid-pool placement (original after the attr word at 021F5A20), LoadPose
 *   register shape (original keeps src = obj+0x28 in r0), the eight spilled 0x800 rounding
 *   words at sp+0x80..0x94/0x9C/0xA0 and the 0x100/0x10C offsets at sp+0x98/0xA4..0xAC.
 * note (2026-10-05, wave D6 lane 01): three fixes from a fresh reading of the head and the pose loader.
 *   (1) func_0207D7C4 takes a fifth argument (NULL, as in the matched callers): the zero stored at [sp]
 *   at entry is that stack argument, written once before the camera-pick branch. The prologue now
 *   matches to 021F56F8 apart from the frame size. (2) LoadPose is a switch on the u16 kind with a
 *   compare chain (beq 0, cmp 1, cmp 2, b out), and the id is a u16 read (ldrh) through a
 *   {u16 id; u16 pad; s16 dx; s16 dz} source record. (3) obj+0x90, obj+0x68 and obj+0x28 come from
 *   static inline accessors (ObjAttr, ObjSrcs, ObjAnim): the parameter copy gives the original
 *   `adds r0,r4,#0; str [sp,#K]; adds r0,#0x90; str [sp,#K]` double store for srcs and keeps src =
 *   obj+0x28 in r0 for the kind load (`ldr r3,[r0,#0x1c]`). Compiled 2008 vs 2080 (was 1996).
 *   Open: frame 0x24C vs 0x254 (8 bytes of locals missing, every sp offset is 8 low), attr (obj+0x90)
 *   stays in r5 where the original spills it to sp+0x5C, the zero/kind registers in the obj head
 *   (original zero r2, kind r3; ours zero r3, kind r1), and everything after 021F57BC not re-checked.
 * note (2026-10-05, wave D7 lane 01): read only, no new build. The original spills attr (obj+0x90) to
 *   sp+0x5C and reloads it three times for the attr word (021F59EE, 021F59F0, 021F5A00); r5 is a
 *   short-lived temp there (0x10C offset at 021F59A6). So the original has more long-lived values than
 *   ours; the 8 missing frame bytes are likely two more spilled locals. Also: the callback arg is
 *   ov112 func_021F546C (mode = (u8)pt->f4, in = &cb.pos, p = obj->fF8), see that draft for the
 *   0x38-byte slot layout of obj->fF8.
 * note (2026-10-05, wave D8 lane 01): three local shape fixes from the listing at 021F58C4..021F591E.
 *   (1) The pos and (ox, oy, 0) MTX_TRANS writes are a G3_Translate(x, y, z) static inline: the
 *   original loads all three values before the three stores (ldr r3,[sp,#0x230]; ldr r2; ldr r1;
 *   str; str; str); 0x0400046C writes are G3_Scale(sx, sy, 0x1000). (2) The flag increment is
 *   `flag++` on the u8 local: the original reloads the spilled zero and does adds/lsls/lsrs, where
 *   `flag = (u8)(flag + 1)` folds to movs #1. (3) The rotation ternary has no inner (u16) cast:
 *   `u16 a = (flag & 1) ? 0x10000 - pose.rot : pose.rot;` truncates once after the join, as in the
 *   original. Compiled 2012 vs 2080 (byte count is not comparable, every later offset shifts).
 *   Still open: frame 0x24C vs 0x254. The original spill area is 8 bytes larger (struct locals start
 *   at sp+0xB4 in the original, sp+0xAC in ours), so the original spills two more values; attr
 *   (obj+0x90) is one of them (sp+0x5C, ours keeps it in r5). G3_Translate(pos) still takes r2/r1/r0
 *   for z/y/x and r3 for the register base, the original r3/r2/r1 and r0. The rounding constant
 *   0x800 is derived from the halfword offset 2 held in r6 (`movs r6,#2; ldrsh r1,[r2,r6]` then
 *   `lsls r2,r6,#0xa`), ours does the same from r7. The k-loop past 021F5A5C was not re-checked.
 * note (2026-10-05, wave D9 lane 04): six fixes from a fresh reading of the j/k loops (compiled 2064 vs
 *   2080; on a register-blind instruction diff 94 lines differ, was 210).  (1) obj->f6C has one more
 *   level: the record table is at obj->f6C->f4 (as in matched func_021F5EDC, struct H/E1/E2), both in
 *   the j-loop test and for the entry reads.  (2) The sub-pose uses the same LoadPose switch: kind 0
 *   also zeroes dz, by cross-jumping into the kind 2 tail (listing 021F5AE6 b 021F5B1A).  The entry
 *   te and the part pt are not locals: j*8 and b*0x14 are spilled CSE values and every read is
 *   written inline.  (3) The 0x1D write goes to 0x0400044C (MTX_STORE), not 0x04000450.  (4) Every
 *   fixed-point product is a FxMul(s64 a, s64 b) static inline: it puts the vector in r0:r1 and the
 *   scale in r2:r3 and spills fx/fz with s/c in r5/r6, as in the original.  psx/psy are s64 locals
 *   assigned before the first product (the original sign-extends both before the first _ll_mul).
 *   (5) obj->fEC bit 0 is a one-bit bitfield.  (6) Declaration order `fx, fz, c, s, X, c2, Z, s2`
 *   gives the original registers in both rotations; the attr word is written right-nested
 *   a7 | (0xF0000 | (a4 | (a3 | (a5 | a0 | 0x40000000)))) to get the original OR order.
 *   Still open: frame 0x250 + push r3 vs 0x254. The original spills attr (obj+0x90) to sp+0x5C and
 *   keeps &pos in r7 across the two func_021F660C calls; ours keeps attr in r5 and rematerialises
 *   &pos.  Tried without effect: attr declaration position, block scope, a struct type, a PolyAttr
 *   inline, a Persp inline and a `Vec *pp` local for the 660C calls.  A separate `int w` local (not
 *   cb.w) gives the 0x254 frame but puts w at sp+0xB0, not 0xB4, so it is not the answer.  The k-loop
 *   head schedules the fx/fz loads before `ang` (original: ang first); `ent->parts[k]` inline instead
 *   of `b` is worse.  `j = 0` sits after the first scale product in the original; only an unnatural
 *   split of the sy/sx block reproduces it.
 * note (2026-10-05, wave D9r lane 22): 94 -> 0 instruction lines differ; 5 bytes left (two spill slots).
 *   (1) The 0x040004A8 word is the SDK inline G3_TexImageParam with enum parameter types, as in the
 *   matched sibling arm9 func_02014D2C (same renderer: same matrix calls, Pose switch, TexInfo record
 *   at obj+0x90 with addr/s/t/fmt/pltt0 at 0/0xC/0x10/0x14/0x1C).  With it, attr spills to sp+0x5C and
 *   &pos stays in r7 across the func_021F660C calls; the frame is 0x254 and the push has no r3.
 *   (2) attr, srcs and a new ctrl (obj+0x28) are plain assignments in the order attr, ctrl, srcs (the
 *   accessor inlines are gone; they made no difference once attr spills).  (3) Declaration order
 *   ent, attr, i, j, srcs, k gives the original slots.  (4) for (j = 0; ...) without the early
 *   j = 0 statement: the 0 is shared with the first FxMul high word, as in the original.  (5) ang is an int
 *   (u16 cast at the assignment).  (6) X = te.x; X += pose.dx; (same for Z) gives the te.x-first load
 *   order.  (7) c2 (the cos of pr) is written inline at both uses: the original spills it as a CSE
 *   temp (lowest slot, reload with no copy).  (8) The obj+0x100 write is VEC_Set(v, x2, y2, 0), which
 *   loads y2 before x2.
 *   Residue: the CSE temps j*8 and c2 have swapped slots (original j*8 sp+0x34, c2 sp+0x30; ours the
 *   reverse).  A diagnostic without the j-loop use of ents[j] gives the original order, so the j*8
 *   temp is created later than c2 in ours.  Tried without effect: s2 inline too, c/s inline (worse),
 *   an idx local, operand order of the c2 products, k-loop locals at function scope, a te local in
 *   the k loop, src passed straight to LoadPose, named c2 in any scope (goes to the named slots).
 * note (2026-10-05, wave D9r lane 53): residue unchanged at 5 bytes (j*8 CSE temp at sp+0x30, cos(pr) temp
 *   at sp+0x34; original reverse).  One clean-up: the `one` local (0x1000 for the sub-pose LoadPose) is
 *   gone; LoadPose(&sub, src, 0x1000) gives the same bytes (the 0x1000 reload from sp+0x64 is the
 *   compiler's own hoisted constant).  Tried without effect on the slot pair (each a real compile): a TabEnt
 *   pointer or a u16 h local for the head read; `int id = j` alias at head or in the k loop; the j loop and the
 *   k loop as if/do-while; pose.rot inline (no pr local; same bytes); s2 load moved above the X/Z reads; X/Z
 *   reads as (ents + j)->x, as a Cell() inline, or as byte offsets (j * 8 + 2) in both head and k loop
 *   (byte offsets in the k loop only stop the j*8 CSE and LICM-hoist a second copy); cos(pr) spelled four
 *   other ways (1 + idx, (T + idx)[1], &T[idx][1], idx << 1) and through a Cos() inline; RotX/RotZ inlines and
 *   an FX_MUL-style macro for the second rotation (worse); a `const s16 *sc` pointer for s2/cos (worse);
 *   k-loop declaration order.  The pair stays swapped in every variant, so its order is probably fixed by the
 *   colouring tie-break, not by source position of the two expressions.
 * note (2026-10-05, wave D9r lane 90): residue unchanged at 5 bytes (same slot pair).  Compared with the
 *   matched twin arm9 func_02014D2C line by line and tested new forms, each a real compile.  Same 5 bytes:
 *   outer i loop as the twin's `i = 0; if (n > 0) do { } while (++i < n);`; a typed MAnim/Frame chain
 *   (`((Obj *)obj)->anim->frames[pose.id]`) instead of the raw obj+0x6C casts; the node as a 0x5C-byte
 *   struct array (`&(*nodes)[idx]`, as the twin); a frame-cells pointer local at the head; a named int
 *   node index at the head; SDK FX_SinIdx/FX_CosIdx inlines (int idx, fx16 return) for every table
 *   read; the break test as `if (ent->parts[k] == 0xFF) break; b = ent->parts[k];`; the rotated vector
 *   in vx/vz locals before the two FxMul calls.  Worse: the head index through a NodeIdx() inline
 *   (loses the loop-condition entry pointer, 1056 B); the k loop as a static inline (not inlined,
 *   1832 B); `k < 8 && parts[k] != 0xFF` in the for condition (744 B); X/Z as one expression each
 *   (64 B).  Diagnostics (not candidates): a third use of the cos(pr) temp, X/Z reads moved to the top
 *   of the k loop, and no Z read all keep ours order (j*8 below cos(pr), b*0x14 lowest), so the order
 *   does not follow use count or program position of the k-loop reads.
 * symbols:
 *   func_0207D7C4 0x0207D7C4 arm
 *   func_0207B67C 0x0207B67C arm
 *   func_02082B60 0x02082B60 arm
 *   func_0207ADE8 0x0207ADE8 arm
 *   func_0207B5C0 0x0207B5C0 arm
 *   func_0207BE14 0x0207BE14 arm
 *   func_0207C768 0x0207C768 arm
 *   func_0207D8FC 0x0207D8FC arm
 *   func_0207D888 0x0207D888 arm
 *   func_0207AF38 0x0207AF38 thumb
 *   func_0207B51C 0x0207B51C arm
 *   func_0207CA00 0x0207CA00 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   func_021F660C 0x021F660C thumb ov112
 *   func_021F65EC 0x021F65EC thumb ov112
 *   func_021F5EDC 0x021F5EDC thumb ov112
 *   d_02148D8C 0x02148D8C data
 *   d_02148D98 0x02148D98 data
 *   d_02148DA4 0x02148DA4 data
 *   d_021F8310 0x021F8310 data ov112
 *   d_021F831C 0x021F831C data ov112
 *   d_021F8304 0x021F8304 data ov112
 *   d_02148B98 0x02148B98 data
 *   d_020A1B38 0x020A1B38 data
 *   d_02148B54 0x02148B54 data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef long long      s64;
#define REG(a) (*(volatile u32 *)(a))

typedef struct { int x, y, z; } Vec;

typedef struct {
    u16 id;
    u16 rot;
    int sx;
    int sy;
    s16 dx;
    s16 dz;
} Pose;

typedef struct {
    u32 f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C;
    u8 parts[8];
} Ent;

typedef struct {
    u32 f0;
    u32 f4;
    int x;
    int z;
    u32 f10;
} Part;

typedef struct {
    u16 f0;
    s16 x;
    s16 z;
    u16 h;
} TabEnt;

typedef struct {
    u16 count;
    u16 pad;
    TabEnt *ents;
} Tab;

typedef struct {
    int w;
    int z;
    Vec pos;
    int x2;
    int y2;
    int z2;
    Vec scale;
    Vec v100;
    u16 rot;
    u16 ang;
} CB;

typedef struct { int m[12]; } Mtx43;
typedef struct { int m[16]; } Mtx44;
typedef struct { int m[9]; } Mtx33;

extern const s16 d_020A1B38[];
extern const Vec d_02148D8C, d_02148D98, d_02148DA4;
extern const Vec d_021F8310, d_021F831C, d_021F8304;
extern const Mtx43 d_02148B98;
extern const Mtx44 d_02148B54;

extern void func_0207D7C4(const Vec *a, const Vec *b, const Vec *c, int d, void *e);
extern void func_0207B67C(const Mtx43 *a, Mtx43 *m);
extern void func_02082B60(Mtx43 *a, Mtx33 *b);
extern void func_0207ADE8(Mtx33 *a, Mtx44 *b);
extern void func_0207B5C0(const Mtx43 *src, Mtx44 *dst);
extern void func_0207BE14(const Mtx44 *a, const Mtx44 *b, Mtx44 *ab);
extern int func_0207C768(int a, int b);
extern void func_0207D8FC(Mtx44 *m);
extern void func_0207D888(int s, int c);
extern void func_0207AF38(Mtx33 *m, int s, int c);
extern void func_0207B51C(void *v, Mtx33 *m, void *out);
extern void func_0207CA00(void *a, void *b, void *c);
extern void func_021F660C(Vec *p, void *m, Vec *out, int *w);
extern void func_021F65EC(void);
extern void func_021F5EDC(char *obj, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, Pose *q, Pose *r,
                          int j, int flag, int *w, int h);

typedef struct { u32 b0 : 1; u32 rest : 31; } Bits;
typedef struct { u32 b0 : 1; u32 b1 : 1; u32 b2 : 1; u32 rest : 29; } Bits3;
static inline int FxMul(s64 a, s64 b)
{
    return (int)((a * b + 0x800) >> 12);
}
static inline int RoundF(int v)
{
    return (int)(v > 0 ? (float)(v << 12) + 0.5f : (float)(v << 12) - 0.5f);
}

typedef struct { u16 id; u16 pad; s16 dx; s16 dz; } PoseSrc;
static inline void LoadPose(Pose *r, char *src, int one)
{
    switch ((u16)*(u32 *)(*(char **)(src + 0x1c) + 4)) {
    case 0: {
        const PoseSrc *s = **(PoseSrc ***)src;
        r->id = s->id;
        r->rot = 0;
        r->sx = one;
        r->sy = one;
        r->dx = 0;
        r->dz = 0;
        break;
    }
    case 1:
        *r = ***(Pose ***)src;
        break;
    case 2: {
        const PoseSrc *s = **(PoseSrc ***)src;
        r->id = s->id;
        r->rot = 0;
        r->sx = one;
        r->sy = one;
        r->dx = s->dx;
        r->dz = s->dz;
        break;
    }
    }
}

typedef struct { u32 addr; u32 f04; u32 f08; u32 s; u32 t; u32 fmt; u32 f18; u32 pltt0; } TexInfo;
typedef enum { GX_TEXFMT_NONE = 0, GX_TEXFMT_PLTT4 = 2 } GXTexFmt;
typedef enum { GX_TEXGEN_NONE = 0, GX_TEXGEN_TEXCOORD = 1 } GXTexGen;
typedef enum { GX_TEXSIZE_S8 = 0 } GXTexSizeS;
typedef enum { GX_TEXSIZE_T8 = 0 } GXTexSizeT;
typedef enum { GX_TEXREPEAT_NONE = 0, GX_TEXREPEAT_ST = 3 } GXTexRepeat;
typedef enum { GX_TEXFLIP_NONE = 0, GX_TEXFLIP_ST = 3 } GXTexFlip;
typedef enum { GX_TEXPLTTCOLOR0_USE = 0, GX_TEXPLTTCOLOR0_TRNS = 1 } GXTexPlttColor0;
static inline void G3_TexImageParam(GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS s, GXTexSizeT t, GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr)
{
    REG(0x040004A8) = (u32)((addr >> 3) | (texFmt << 26) | (texGen << 30) | (s << 20) |
                                  (t << 23) | (repeat << 16) | (flip << 18) | (pltt0 << 29));
}
static inline void VEC_Set(Vec *a, int x, int y, int z)
{
    a->x = x;
    a->y = y;
    a->z = z;
}
static inline void G3_Translate(int x, int y, int z)
{
    REG(0x04000470) = (u32)x;
    REG(0x04000470) = (u32)y;
    REG(0x04000470) = (u32)z;
}
static inline void G3_Scale(int x, int y, int z)
{
    REG(0x0400046C) = (u32)x;
    REG(0x0400046C) = (u32)y;
    REG(0x0400046C) = (u32)z;
}
void func_021F56BC(int *p, void (*arg)(u8, Vec *, u32))
{
    Pose pose;
    Pose sub;
    Vec pos;
    Mtx44 m3;
    Mtx43 m1;
    Mtx33 m2;
    Mtx44 m4;
    Mtx44 proj;
    Mtx33 m5;
    CB cb;
    Ent *ent;
    TexInfo *attr;
    int i, j;
    char **srcs;
    u8 k;
    char *obj;
    char *ctrl;
    int ox, oy;
    u8 flag;

    REG(0x04000444) = 0;
    REG(0x04000440) = 0;
    REG(0x0400044C) = 0;
    REG(0x04000440) = 3;
    REG(0x04000454) = 0;
    REG(0x04000440) = 2;
    if ((((Bits *)&p[2])->b0) == 0)
        func_0207D7C4(&d_02148D8C, &d_02148D98, &d_02148DA4, 1, 0);
    else
        func_0207D7C4(&d_021F8310, &d_021F831C, &d_021F8304, 1, 0);
    func_0207B67C(&d_02148B98, &m1);
    func_02082B60(&m1, &m2);
    func_0207ADE8(&m2, &m3);

    for (i = 0; i < p[0]; i++) {
        if (((char **)p[1])[i] == 0 || ((Bits3 *)(((char **)p[1])[i] + 0xEC))->b2)
            continue;
        REG(0x04000444) = 0;
        obj = ((char **)p[1])[i];
        attr = (TexInfo *)(obj + 0x90);
        ctrl = obj + 0x28;
        srcs = (char **)(obj + 0x68);
        cb.z = 0;
        LoadPose(&pose, ctrl, 0x1000);
        pos.x = *(int *)(obj + 0xC8);
        pos.y = *(int *)(obj + 0xCC);
        pos.z = *(int *)(obj + 0xD0);
        if ((((Bits *)&p[2])->b0) == 0) {
            ox = pose.dx << 8;
            oy = -pose.dz << 8;
        } else {
            proj.m[0] = 0x80000;
            proj.m[1] = 0;
            proj.m[2] = 0;
            proj.m[3] = 0x80000;
            proj.m[4] = 0;
            proj.m[5] = 0x60000;
            proj.m[6] = 0;
            proj.m[7] = (int)0xFFFA0000;
            proj.m[8] = 0;
            proj.m[9] = 0;
            proj.m[10] = (int)0xFFFFF000;
            proj.m[11] = 0x1000;
            proj.m[12] = 0;
            proj.m[13] = 0;
            proj.m[14] = 0;
            proj.m[15] = (int)0xFFFFF000;
            func_0207B5C0(&d_02148B98, &m4);
            func_0207BE14(&m4, &d_02148B54, &m4);
            func_021F660C(&pos, &m4, &pos, &cb.w);
            pos.x = func_0207C768(pos.x, cb.w);
            pos.y = func_0207C768(pos.y, cb.w);
            func_021F660C(&pos, &proj, &pos, &cb.w);
            ox = RoundF(pose.dx);
            oy = RoundF(-pose.dz);
        }
        pos.z = *(int *)(obj + 0xD0);
        flag = 0;
        if (*(int *)(obj + 0xD4) < 0)
            flag++;
        G3_Translate(pos.x, pos.y, pos.z);
        if ((((Bits *)&p[2])->b0) == 0)
            func_0207D8FC(&m3);
        G3_Translate(ox, oy, 0);
        {
            u16 a = (flag & 1) ? 0x10000 - pose.rot : pose.rot;
            func_0207D888(-d_020A1B38[(a >> 4) * 2], d_020A1B38[(a >> 4) * 2 + 1]);
        }

        {
            int sy = FxMul(pose.sy, *(int *)(obj + 0xD8));
            int sx = FxMul(pose.sx, *(int *)(obj + 0xD4));
            G3_Scale(sx, sy, 0x1000);
        }
        {
            u16 a = *(u16 *)(obj + 0xFC);
            func_0207AF38(&m5, -d_020A1B38[(a >> 4) * 2], d_020A1B38[(a >> 4) * 2 + 1]);
            func_0207B51C(obj + 0x100, &m5, obj + 0x10C);
            func_0207CA00(obj + 0x100, obj + 0x10C, obj + 0x10C);
            *(int *)(obj + 0x10C) = func_0207C768(*(int *)(obj + 0x10C), *(int *)(obj + 0xD4));
            *(int *)(obj + 0x110) = func_0207C768(*(int *)(obj + 0x110), *(int *)(obj + 0xD8));
        }
        REG(0x0400044C) = 0x1D;
        func_021F65EC();
        {
            G3_TexImageParam(attr->fmt, GX_TEXGEN_TEXCOORD, attr->s, attr->t, GX_TEXREPEAT_ST, GX_TEXFLIP_ST, attr->pltt0, attr->addr);
        }
        for (j = 0; j < (*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].count; j++) {
            char *src;
            src = *srcs + (((*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].ents[j].h & 0xFF00) >> 8) * 0x5C;
            LoadPose(&sub, src, 0x1000);
            ent = (Ent *)(*(char **)(obj + 0x20) + 4 + sub.id * 0x38);
            if (ent->f20 != 0) {
                if (((Bits *)(obj + 0xEC))->b0)
                    func_021F5EDC(obj, ent->f18, ent->f1C, ent->f20, ent->f24, ent->f28,
                                  ent->f2C + ent->f24, &sub, &pose, j, ((Bits *)&p[2])->b0, &cb.z, flag);
                else
                    func_021F5EDC(obj, ent->f18, ent->f1C, ent->f20, ent->f24, ent->f28,
                                  ent->f2C, &sub, &pose, j, ((Bits *)&p[2])->b0, &cb.z, flag);
            }
            func_021F5EDC(obj, ent->f0, ent->f4, ent->f8, ent->fC, ent->f10, ent->f14,
                          &sub, &pose, j, ((Bits *)&p[2])->b0, &cb.z, flag);
            for (k = 0; k < 8; k++) {
                u8 b = ent->parts[k];
                int ang, fx, fz, c, s, X, Z, s2, rx, rz;
                u16 pr;
                s64 psx, psy;
                if (b == 0xFF)
                    break;
                pr = pose.rot;
                ang = (u16)(pr + sub.rot);
                fx = (*(Part **)(obj + 0x24))[b].x;
                fz = (*(Part **)(obj + 0x24))[b].z;
                s = d_020A1B38[(ang >> 4) * 2];
                c = d_020A1B38[(ang >> 4) * 2 + 1];
                psx = pose.sx;
                psy = pose.sy;
                rx = FxMul(fx * c - fz * s, FxMul(psx, sub.sx));
                rz = FxMul(fx * s + fz * c, FxMul(psy, sub.sy));
                X = (*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].ents[j].x;
                X += pose.dx;
                Z = (*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].ents[j].z;
                Z += pose.dz;
                s2 = d_020A1B38[(pr >> 4) * 2];
                rx += FxMul(X * d_020A1B38[(pr >> 4) * 2 + 1] - Z * s2, psx);
                rz += FxMul(X * s2 + d_020A1B38[(pr >> 4) * 2 + 1] * Z, psy);
                rx += RoundF(sub.dx);
                rz += RoundF(sub.dz);
                cb.pos = pos;
                cb.pos.y = -cb.pos.y;
                cb.x2 = FxMul(rx, *(int *)(obj + 0xD4) / 16);
                cb.y2 = FxMul(rz, *(int *)(obj + 0xD8) / 16);
                cb.z2 = cb.z;
                cb.v100 = *(Vec *)(obj + 0x100);
                cb.rot = *(u16 *)(obj + 0xFC);
                cb.scale = *(Vec *)(obj + 0xD4);
                cb.ang = (u16)(ang + ((*(Part **)(obj + 0x24))[b].f10 << 11));
                arg((u8)(*(Part **)(obj + 0x24))[b].f4, &cb.pos, *(u32 *)(obj + 0xF8));
                if ((*(Part **)(obj + 0x24))[b].f4 == 5) {
                    VEC_Set((Vec *)(obj + 0x100), cb.x2, cb.y2, 0);
                }
            }
        }
        REG(0x04000448) = 1;
    }
    REG(0x04000448) = 1;
}
