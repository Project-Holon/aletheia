/*
 * function: ENCEFF_DrawCellGrid
 * address: 0x021F582C
 * packet: pkt_ov077_021F582C
 * region: ov077
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-06 (integrator): EXACT once tools/match.py accepts a game-code compiler template (the scale vector at 0x021F5A58, our compile's bytes, the only declared data within 0x40 bytes after the function).
 * 2026-10-05 (wP4 lane S3): first source for this function (pengy share, user-approved for this
 *   function only). Draws a w*h grid of textured quads through the geometry engine registers
 *   (MTX_PUSH 0x04000444, material/light 0x040004C0..0x040004CC, POLYGON_ATTR 0x040004A4,
 *   MTX_TRANS 0x04000470, MTX_SCALE 0x0400046C, NORMAL 0x04000484, TEXCOORD 0x04000488,
 *   VTX_16 0x0400048C, BEGIN 0x04000500, END 0x04000504, MTX_POP 0x04000448). The element
 *   record is 0x40 bytes; word 0x1C and 0x20 are the X and Z angles (index = angle >> 4 into
 *   the sin/cos table 0x020A1B38). Logic is complete; 560 B against 508 B, 372 B differ.
 *   Residue is register allocation: the original keeps the constant 0x300A in r7 (loads W
 *   with subs r1,r7,#2, H with [r0,r7], later hoists the loop-invariant 0x3008 as r7-2) and
 *   gives r7 to the loop value py; the draft puts the MTX_TRANS pointer in r7 and spills px
 *   and py, so the frame is 0x84 with a 5-register push instead of 0x80 with r3 pushed.
 *   Tried: raw literals (W first gives pool 0x3008 plus adds #2; H first gives pool 0x300A plus
 *   subs #2 as the original, and the loop then hoists r7-2 into a spill slot as the original);
 *   int off = 0x300A local (folds in the loop); struct with u16 w, h fields (same as raw);
 *   u16 and int w/h locals; px/py declared inside and outside the loop, both orders; the six
 *   per-function pragmas (opt_lifetimes off 370 B differ, others 372..450). The 12-byte stack
 *   scale vector is copied from 0x021F5A58, which is compiler-emitted data after the pool (it
 *   shows as the unresolved d_021F5A58 relocation). Not tried: a dedicated pointer local for
 *   each GX register (the original spills five of them with the str/adds/str pattern, which the
 *   draft already reproduces), different statement order of the register stores.
 *   Callees: func_0207AF1C and func_0207AF38 (Matrix *, int sin, int cos), func_0207D934
 *   (const void *): all prototypes match the callers' argument counts.
 * 2026-10-05 (wP4 lane S3): first source for this function (pengy share, user-approved for this
 *   function only). Draws a w*h grid of textured quads through the geometry engine registers
 *   (MTX_PUSH 0x04000444, material/light 0x040004C0..0x040004CC, POLYGON_ATTR 0x040004A4,
 *   MTX_TRANS 0x04000470, MTX_SCALE 0x0400046C, NORMAL 0x04000484, TEXCOORD 0x04000488,
 *   VTX_16 0x0400048C, BEGIN 0x04000500, END 0x04000504, MTX_POP 0x04000448). The element
 *   record is 0x40 bytes; word 0x1C and 0x20 are the X and Z angles (index = angle >> 4 into
 *   the sin/cos table 0x020A1B38). Logic is complete; 560 B against 508 B, 372 B differ.
 *   Residue is register allocation: the original keeps the constant 0x300A in r7 (loads W
 *   with subs r1,r7,#2, H with [r0,r7], later hoists the loop-invariant 0x3008 as r7-2) and
 *   gives r7 to the loop value py; the draft puts the MTX_TRANS pointer in r7 and spills px
 *   and py, so the frame is 0x84 with a 5-register push instead of 0x80 with r3 pushed.
 *   Tried: raw literals (W first gives pool 0x3008 plus adds #2; H first gives pool 0x300A plus
 *   subs #2 as the original, and the loop then hoists r7-2 into a spill slot as the original);
 *   int off = 0x300A local (folds in the loop); struct with u16 w, h fields (same as raw);
 *   u16 and int w/h locals; px/py declared inside and outside the loop, both orders; the six
 *   per-function pragmas (opt_lifetimes off 370 B differ, others 372..450). The 12-byte stack
 *   scale vector is copied from 0x021F5A58, which is compiler-emitted data after the pool (it
 *   shows as the unresolved d_021F5A58 relocation). Not tried: a dedicated pointer local for
 *   each GX register (the original spills five of them with the str/adds/str pattern, which the
 *   draft already reproduces), different statement order of the register stores.
 *   Callees: func_0207AF1C and func_0207AF38 (Matrix *, int sin, int cos), func_0207D934
 *   (const void *): all prototypes match the callers' argument counts.
 * 2026-10-05 final push G10L6 (36 compiles, 3 rounds): now 564 B vs 508 B, 449 B differ (the draft above did not compile
 *   without --lang c99; it was 560 B, 372 differ). New forms kept: Trans/Scale as SDK-style inline helpers (args first, as
 *   the original loads z,y,x before the three stores); element pointer local u8 *e = p + i * 64 as the first loop statement
 *   (reproduces the original loop top: pointer spilled before the MTX_PUSH store, w load, pos copy); px, py declared at
 *   function scope before n, a, b (reproduces the spill slots of n, a, b).
 *   Residue is one allocation choice: the original gives r7 to the pool constant 0x300A, then w, then py, and spills the
 *   MTX_TRANS pointer; here the TRANS pointer (3 stores) outscores them (mwcc spill score = cost/degree, use 2, def 1,
 *   loop weight) and takes r7. Probes (not filed): TRANS with 2 stores gives the original allocation and frame (push r3-r7,
 *   frame 0x80); one more use of py or w also does. No natural source form found that adds that margin. Tried, no
 *   change: mul operand order, col/row locals, *0x1000 for <<12, px <<= 12 in place, off=0x300A local, block-local w,
 *   block-local pos, helper with pointer local, both helpers direct stores, s0/t0/s1/t1 locals, six per-function pragmas
 *   (opt_propagation off with do-while and named locals gave r7 = 0x300A as the original but 434 B differ).
 *   Still differs after allocation: mul destination (original muls into the reloaded a/b register), hoist order of aa, bb, sc.z.
 * 2026-10-06 pass 2 P2L58 (25 compiles, 3 rounds): MATCH, every concrete byte equal; the one wildcard is the
 *   scale vector template (0x021F5A58 = 0x1000 x3, compiler data right after the pool, read only by this
 *   function), now written as the initialiser `Vec sc = {0x1000, 0x1000, 0x1000}` (mwcc copies its @40
 *   template; no vendor object names it, and the old extern d_021F5A58 had no outside witness either).
 *   The forms that closed it: (1) the far texture corner as locals right after px/py,
 *   `qx = px + (a << 12); qy = py + (b << 12);` (propagated to the vertex block; it gives the original
 *   hoist order a<<12, b<<12, sc.z and the original spill slots); (2) named col/row locals with the
 *   column first in the products, `col = i % w; px = (col * a) << 12; row = i / w; py = (row * b) << 12;`
 *   (product into the reloaded a/b register, and r7 to 0x300A, w and py with MTX_TRANS spilled, frame
 *   0x80 push r3-r7). Plain literals for 0x7FFF7FFF / 0x7FFF / 0x20000000 give the same derived constants.
 *   The aggregates sit in an inner block after the five setup stores so the file also compiles (MATCH)
 *   with --lang c; with the declarations at the top the zero and template copies move above the stores.
 * symbols:
 *   func_0207AF1C 0x0207AF1C thumb
 *   func_0207AF38 0x0207AF38 thumb
 *   func_0207D934 0x0207D934 arm
 *   d_020A1B38 0x020A1B38 data a2
 *   d_021F5A58 0x021F5A58 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { s32 x, y, z; } Vec;
typedef struct { s32 words[9]; } Matrix;

#define R(a) (*(volatile u32 *)(a))
extern s16 d_020A1B38[];
extern void func_0207AF1C(Matrix *, int, int);
extern void func_0207AF38(Matrix *, int, int);
extern void func_0207D934(const void *);

static inline void Trans(s32 x, s32 y, s32 z)
{
    R(0x04000470) = (u32)x;
    R(0x04000470) = (u32)y;
    R(0x04000470) = (u32)z;
}
static inline void Scale(s32 x, s32 y, s32 z)
{
    R(0x0400046C) = (u32)x;
    R(0x0400046C) = (u32)y;
    R(0x0400046C) = (u32)z;
}
static inline void TexCoord(s32 s, s32 t)
{
    R(0x04000488) = (u32)(u16)(s16)(s >> 8) | ((u32)(u16)(s16)(t >> 8) << 16);
}
void ENCEFF_DrawCellGrid(u8 *p)
{
    R(0x04000444) = 0;
    R(0x040004C0) = 0x7FFF7FFF;
    R(0x040004C4) = 0x4210;
    R(0x040004CC) = 0x7FFF;
    R(0x040004A4) = 0x001F0081;
    {
        Vec pos = {0, 0, 0};
        Vec sc = {0x1000, 0x1000, 0x1000};
        Matrix m;
        int px, py, qx, qy;
        int w, h, n, a, b, i, k, col, row;
        h = *(u16 *)(p + 0x300A);
        w = *(u16 *)(p + 0x3008);
        n = w * h;
        a = (0x20 / w) << 3;
        b = (0x18 / h) << 3;
        sc.x = (a / 8) << 12;
        sc.y = (b / 8) << 12;
        for (i = 0; i < n; i++) {
            u8 *e = p + i * 64;
            R(0x04000444) = 0;
            w = *(u16 *)(p + 0x3008);
            pos = *(Vec *)e;
            col = i % w;
            px = (col * a) << 12;
            row = i / w;
            py = (row * b) << 12;
            qx = px + (a << 12);
            qy = py + (b << 12);
            Trans(pos.x, pos.y, pos.z);
            Scale(sc.x, sc.y, sc.z);
            k = *(s32 *)(e + 0x1C) >> 4;
            func_0207AF1C(&m, d_020A1B38[k * 2], d_020A1B38[k * 2 + 1]);
            func_0207D934(&m);
            k = *(s32 *)(e + 0x20) >> 4;
            func_0207AF38(&m, d_020A1B38[k * 2], d_020A1B38[k * 2 + 1]);
            func_0207D934(&m);
            R(0x04000500) = 1;
            R(0x04000484) = 0x20000000;
            TexCoord(px, py);
            R(0x0400048C) = 0x4000C000; R(0x0400048C) = 0;
            TexCoord(px, qy);
            R(0x0400048C) = 0xC000C000; R(0x0400048C) = 0;
            TexCoord(qx, qy);
            R(0x0400048C) = 0xC0004000; R(0x0400048C) = 0;
            TexCoord(qx, py);
            R(0x0400048C) = 0x40004000; R(0x0400048C) = 0;
            R(0x04000504) = 0;
            R(0x04000448) = 1;
        }
        R(0x04000448) = 1;
    }
}
