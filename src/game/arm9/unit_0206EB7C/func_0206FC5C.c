/*
 * function: func_0206FC5C
 * address:  0x0206FC5C
 * packet:   pkt_0206EB00
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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
 *
 * symbols:
 *   func_0206FFA0   0x0206FFA0  arm
 *   VEC_Normalize   0x0207CCA4  arm
 */
typedef unsigned int   u32;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned char  u8;

typedef struct { u32 flags; u32 off04; } Rec;
typedef struct { u32 f00; u16 cnt04; u16 pad06; u32 f08; u32 f0c; u32 f10; } Hdr;

extern int  func_0206FFA0(int *out, s16 *a, s16 *b, u32 id);
extern void VEC_Normalize(const int *src, int *dst);

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
