/*
 * function: func_021F582C
 * address: 0x021F582C
 * packet: pkt_ov077_021F582C
 * region: ov077
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
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
extern const Vec d_021F5A58;
extern void func_0207AF1C(Matrix *, int, int);
extern void func_0207AF38(Matrix *, int, int);
extern void func_0207D934(const void *);

static inline void TexCoord(s32 s, s32 t)
{
    R(0x04000488) = (u32)(u16)(s16)(s >> 8) | ((u32)(u16)(s16)(t >> 8) << 16);
}
static inline void Vtx(s16 x, s16 y, s16 z)
{
    R(0x0400048C) = (u32)(u16)x | ((u32)(u16)y << 16);
    R(0x0400048C) = (u32)(u16)z;
}

void func_021F582C(u8 *p)
{
    u32 c = 0x7FFF7FFF;
    u32 nrm = 0x40004000;
    int w, h, n, a, b, i, k;
    R(0x04000444) = 0;
    R(0x040004C0) = c;
    R(0x040004C4) = 0x4210;
    R(0x040004CC) = c >> 16;
    R(0x040004A4) = 0x001F0081;
    Vec pos = {0, 0, 0};
    Vec sc = d_021F5A58;
    Matrix m;
    h = *(u16 *)(p + 0x300A);
    w = *(u16 *)(p + 0x3008);
    n = w * h;
    a = (0x20 / w) << 3;
    b = (0x18 / h) << 3;
    sc.x = (a / 8) << 12;
    sc.y = (b / 8) << 12;
    for (i = 0; i < n; i++) {
        int px, py;
        R(0x04000444) = 0;
        w = *(u16 *)(p + 0x3008);
        pos = *(Vec *)(p + i * 64);
        px = (a * (i % w)) << 12;
        py = (b * (i / w)) << 12;
        R(0x04000470) = pos.x;
        R(0x04000470) = pos.y;
        R(0x04000470) = pos.z;
        R(0x0400046C) = sc.x;
        R(0x0400046C) = sc.y;
        R(0x0400046C) = sc.z;
        k = *(s32 *)(p + i * 64 + 0x1C) >> 4;
        func_0207AF1C(&m, d_020A1B38[k * 2], d_020A1B38[k * 2 + 1]);
        func_0207D934(&m);
        k = *(s32 *)(p + i * 64 + 0x20) >> 4;
        func_0207AF38(&m, d_020A1B38[k * 2], d_020A1B38[k * 2 + 1]);
        func_0207D934(&m);
        R(0x04000500) = 1;
        R(0x04000484) = nrm << 15;
        TexCoord(px, py);
        R(0x0400048C) = 0x4000C000; R(0x0400048C) = 0;
        TexCoord(px, py + (b << 12));
        R(0x0400048C) = 0xC000C000; R(0x0400048C) = 0;
        TexCoord(px + (a << 12), py + (b << 12));
        R(0x0400048C) = 0xC0004000; R(0x0400048C) = 0;
        TexCoord(px + (a << 12), py);
        R(0x0400048C) = 0x40004000; R(0x0400048C) = 0;
        R(0x04000504) = 0;
        R(0x04000448) = 1;
    }
    R(0x04000448) = 1;
}
