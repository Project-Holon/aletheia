/*
 * function: NNSi_G3dAnmGetTransDataEx
 * address:  0x0206F36C
 * packet:   pkt_0206EB00
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Scalar lerp sampler over the animation record (flags word, data offset)
 * and the animation root (key count at +4, flags at +8).  NNSi_G3dAnmCalcJntAnmNode
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
 * arms are spelled exactly as src/matched/NNSi_G3dAnmGetTexSRTScalarData.c's `two:` block
 * (s16 via a byte offset `k << 1` plus a pointer `g`, word via a pointer
 * `w` built inside the arm); and in `last:` the mask is assigned before
 * `mul = 1`.
 *
 * No relocation sites.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G3dAnmGetTransDataEx.c \
 *       --func NNSi_G3dAnmGetTransDataEx --addr 0x0206F36C --cc ../2.0/sp2 --arm
 */
#include "../include/Obj04095.h"
#include "../include/Obj16636.h"
typedef unsigned int   u32;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned char  u8;

typedef struct { u32 flags; u32 off04; } Rec;
typedef struct { u32 f00; u16 cnt04; u16 pad06; u32 f08; } Hdr;

void NNSi_G3dAnmGetTransDataEx(int *out, int t, Rec *r, Hdr *h)
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

