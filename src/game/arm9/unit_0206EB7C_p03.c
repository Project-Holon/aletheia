/*
 * file:     unit_0206EB7C_p03.c
 * unit:     yes
 * function: func_0206F844, func_0206FC5C, func_0206FFA0
 * address:  0x0206F844
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
 *   VEC_Normalize   0x0207CCA4  arm
 *   g_020A1998      0x020A1998  data  a1
 *   g_020A1999      0x020A1999  data  a1
 *   g_020A199A      0x020A199A  data  a1
 *   g_020A199B      0x020A199B  data  a1
 */
typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned char  u8;

typedef struct { u32 flags; u32 off04; } Rec;

typedef struct { u32 f00; u16 cnt04; u16 pad06; u32 f08; u32 f0c; u32 f10; } Hdr;

typedef struct { u8 c; u8 pad[3]; } Perm;

extern void VEC_Normalize(const int *src, int *dst);
void func_0206F844(int *out, int t, Rec *r, Hdr *h);
void func_0206FC5C(int *out, int t, Rec *r, Hdr *h);
int func_0206FFA0(int *out, s16 *a, s16 *b, u32 id);
extern const Perm g_020A1998[];
extern const Perm g_020A1999[];
extern const Perm g_020A199A[];
extern const Perm g_020A199B[];



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
