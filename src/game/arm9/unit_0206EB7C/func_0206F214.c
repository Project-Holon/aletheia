/*
 * function: func_0206F214
 * address:  0x0206F214
 * packet:   pkt_0206EB00
 * region:   arm9
 * compiler: ../2.0/sp2p2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Scalar keyframe sampler without the lerp (func_0206EE60 calls it for the
 * three scalar channels when the cursor has no fraction or root->f08 bit 0 is
 * clear): the same flag cascade as src/matched/func_02070524.c, writing the
 * key (plain), the mean of two keys (two:) or the 3:1 blend of two keys into
 * *out.  Flags bit 29 selects s16 keys over s32 keys; the s32 3:1 blend is a
 * 64-bit expression.
 *
 * Per-file compiler pin ../2.0/sp2p2, NOT the packet's ../2.0/sp2, on a new
 * front-end tell (docs/FRONTEND-PINS.md, "64-bit multiply by a constant"):
 * the image multiplies the sign-extended s32 key by 3 as
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
 *     offset o for s16, pointer w built in the arm for s32, (w+4) read first);
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
#include "../../../matched/include/Obj16634.h"
typedef unsigned int   u32;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned char  u8;

typedef struct { u32 flags; u32 off04; } Rec;

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
