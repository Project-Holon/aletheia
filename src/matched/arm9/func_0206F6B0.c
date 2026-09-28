/*
 * function: func_0206F6B0
 * address:  0x0206F6B0
 * packet:   pkt_0206EB00
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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
typedef unsigned int   u32;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned char  u8;

typedef struct { u32 flags; u32 off04; } Rec;
typedef struct { u32 f00; u16 cnt04; u16 pad06; u32 f08; } Hdr;
typedef struct { s16 x; s16 y; } V2s;
typedef struct { int x; int y; } V2i;

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
