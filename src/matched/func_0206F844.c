/*
 * function: func_0206F844
 * address:  0x0206F844
 * packet:   pkt_0206EB00
 * region:   arm9
 * compiler: ../2.0/sp2p2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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
 * symbols:
 *   func_0206FFA0   0x0206FFA0  arm
 *   VEC_Normalize   0x0207CCA4  arm
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206F844.c \
 *       --func func_0206F844 --addr 0x0206F844 --arm --cc ../2.0/sp2p2
 */
typedef unsigned int   u32;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned char  u8;

typedef struct { u32 flags; u32 off04; } Rec;
typedef struct { u32 f00; u16 cnt04; u16 pad06; u32 f08; u32 f0c; u32 f10; } Hdr;

extern int  func_0206FFA0(int *out, s16 *a, s16 *b, u32 id);
extern void VEC_Normalize(const int *src, int *dst);

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
