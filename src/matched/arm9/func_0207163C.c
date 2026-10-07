/*
 * function: func_0207163C
 * address:  0x0207163C
 * packet:   pkt_02071360
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   MIi_CpuCopy32  0x02082A90  arm
 *   g_02148DB0     0x02148DB0  data
 *   g_02149BB4     0x02149BB4  data
 *
 * The matrix-slot propagation step of the cluster_02071360 transform
 * stage.  `idx` names two slots of the 0x18-byte record table at
 * 0x02149BB4 (a = idx[1], b = idx[2]); the owner at *0x02148DB0 carries
 * a per-slot bitmask at +0xC4.
 *   flags & 4:  set o->flags bit 0; if b's bit is set, set a's bit and
 *               o->flags |= 0x18; otherwise copy record b over record a
 *               and into o->mtx.
 *   otherwise:  copy m[0..2] into o->f04..f0c; if b's bit is set, copy m
 *               into record a, clear a's bit, o->flags |= 0x18; otherwise
 *               clear a's bit, record a = m * record b component-wise in
 *               1.12 ((s64)x*y >> 12, six terms) and copy record b into
 *               o->mtx.
 *
 * THE SIX POOL WORDS.  The image's pool holds 0x02149BB4, ...BB8, ...BBC,
 * ...BC0, ...BC4, ...BC8: not six objects but ONE `s32 [][6]` table,
 * whose column k is addressed as symbol+4k because a register-offset
 * `ldr r, [base, ip]` has no room for a further immediate.  The single
 * 2-D extern reproduces all six words (sole-ref/self per site).
 *
 * The callee is MIi_CpuCopy32 (src, dst, size), SOURCE FIRST: the first
 * argument of every call here is the record being read.
 *
 * Pin evidence (2.0): "kept constants".  The image rematerialises the
 * copy size `mov r2, #0x18` before each call; dsi/1.1p1 keeps 0x18 in a
 * callee-saved register and copies it (`mov r2, r6`), 536 bytes against
 * 540 with 362 concrete bytes out.  Under ../2.0/sp2 the same C is 540
 * bytes, 0 out, first compile.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0207163C.c \
 *       --func func_0207163C --addr 0x0207163C --arm --cc ../2.0/sp2
 */

#include "../include/G_Root.h"

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef int            s32;
typedef long long      s64;

struct Obj {
    u32 flags;
    s32 f04;
    s32 f08;
    s32 f0c;
    s32 mtx[6];
};

struct Idx {
    u8 f0;
    u8 a;
    u8 b;
};

extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
extern struct Root *g_02148DB0;
extern s32 g_02149BB4[][6];

void func_0207163C(struct Obj *o, s32 *m, struct Idx *idx, u32 flags)
{
    u32 a = idx->a;
    u32 b = idx->b;

    if (flags & 4) {
        o->flags |= 1;
        if (g_02148DB0->bits[b >> 5] & (1 << (b & 0x1f))) {
            g_02148DB0->bits[a >> 5] |= 1 << (a & 0x1f);
            o->flags |= 0x18;
            return;
        }
        MIi_CpuCopy32(g_02149BB4[b], g_02149BB4[a], 0x18);
        MIi_CpuCopy32(g_02149BB4[b], o->mtx, 0x18);
        return;
    }

    o->f04 = m[0];
    o->f08 = m[1];
    o->f0c = m[2];
    if (g_02148DB0->bits[b >> 5] & (1 << (b & 0x1f))) {
        MIi_CpuCopy32(m, g_02149BB4[a], 0x18);
        g_02148DB0->bits[a >> 5] &= ~(1 << (a & 0x1f));
        o->flags |= 0x18;
        return;
    }
    g_02148DB0->bits[a >> 5] &= ~(1 << (a & 0x1f));
    g_02149BB4[a][0] = (s32)(((s64)m[0] * g_02149BB4[b][0]) >> 12);
    g_02149BB4[a][1] = (s32)(((s64)m[1] * g_02149BB4[b][1]) >> 12);
    g_02149BB4[a][2] = (s32)(((s64)m[2] * g_02149BB4[b][2]) >> 12);
    g_02149BB4[a][3] = (s32)(((s64)m[3] * g_02149BB4[b][3]) >> 12);
    g_02149BB4[a][4] = (s32)(((s64)m[4] * g_02149BB4[b][4]) >> 12);
    g_02149BB4[a][5] = (s32)(((s64)m[5] * g_02149BB4[b][5]) >> 12);
    MIi_CpuCopy32(g_02149BB4[b], o->mtx, 0x18);
}
