/*
 * function: NNSi_G3dAnmCalcJntAnmNode
 * address:  0x0206EE60
 * packet:   pkt_0206EB00
 * region:   arm9
 * compiler: ../2.0/sp2p2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The per-node channel decoder of the animation player (docs/families/
 * cluster_0206EB00.h, the driver).  Finds the node's record through the
 * u16 table at root+0x14, then walks the record's flag groups: the three
 * scalar channels (NNSi_G3dAnmGetTransData / NNSi_G3dAnmGetTransDataEx) or the rotation-less
 * flags, the rotation (NNSi_G3dAnmGetRotData / NNSi_G3dAnmGetRotDataEx, or one packed key
 * through NNSi_G3dAnmDecodeRotKey with row 2 rebuilt by the cross product), and the
 * three vector-2 channels (NNSi_G3dAnmGetScaleData / NNSi_G3dAnmGetScaleDataEx) into the result
 * block, then emits through the stash's four-argument hook.  A dead node
 * (flags bit 0) emits with out->f00 = 7; the 0x600-guarded "stash" arm
 * hands off to NNSi_G3dGetNodeScaleFromMdl, which emits on its own.
 *
 * The 2026-09-21 source (docs/notes/pkt_0206EB00.c.txt) was 948/63, a
 * p/lerp register swap at 22 sites.  Two levers closed it (wave 10):
 *   - lerp is ONE conditional expression,
 *       lerp = ((t & 0xfff) != 0 && (root->f08 & 1) != 0) ? 1 : 0;
 *     which keeps the image's `movne r6,#1 / bne / mov r6,#0` shape and
 *     gives the cursor r5 (the goto form and the if/else form give the
 *     swap, the bare `&&` value is 944 bytes);
 *   - the cofactor block is FC5C's: three temporaries from direct field
 *     reads, stored after all three are computed (the six bound locals
 *     are 23 bytes of register naming out once lerp is right).
 * The flag groups are plain nested if/else (the earlier goto ladder
 * compiles identically).  Every group puts the call arm first.
 *
 * symbols:
 *   gCurrentRS       0x02148DB0  data  a4
 *   NNSi_G3dGetNodeTransFromMdl    0x0206EBB8  arm
 *   NNSi_G3dGetNodeScaleFromMdl    0x0206EC50  arm
 *   NNSi_G3dGetNodeRotFromMdl    0x0206ECE0  arm
 *   NNSi_G3dAnmGetTransData    0x0206F214  arm
 *   NNSi_G3dAnmGetTransDataEx    0x0206F36C  arm
 *   NNSi_G3dAnmGetScaleData    0x0206F4C8  arm
 *   NNSi_G3dAnmGetScaleDataEx    0x0206F6B0  arm
 *   NNSi_G3dAnmGetRotData    0x0206F844  arm
 *   NNSi_G3dAnmGetRotDataEx    0x0206FC5C  arm
 *   NNSi_G3dAnmDecodeRotKey    0x0206FFA0  arm
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_G3dAnmCalcJntAnmNode.c \
 *       --func NNSi_G3dAnmCalcJntAnmNode --addr 0x0206EE60 --arm --cc ../2.0/sp2p2
 */

#include "../include/G_Root.h"

typedef unsigned int   u32;
typedef unsigned short u16;
typedef unsigned char  u8;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
} Root;

typedef struct {
    u32 f00;
    u8  pad04[0x24];
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    u32 f4c;
    u32 f50;
    u32 f54;
} Out;

typedef struct {
    u32  first;
    u8   pad2[0xE4];
    void (*hook)(Out *, u32 *, u32, u32);
} Disp;

extern struct Root *gCurrentRS;

typedef signed short   s16;
extern void NNSi_G3dGetNodeTransFromMdl(u32 *out);
extern void NNSi_G3dGetNodeScaleFromMdl(void *arg);
extern void NNSi_G3dGetNodeRotFromMdl(Out *o);
extern void NNSi_G3dAnmGetTransData(u32 *out, u32 t, u32 *rec, Root *base);
extern void NNSi_G3dAnmGetTransDataEx(u32 *out, u32 t, u32 *rec, Root *base);
extern void NNSi_G3dAnmGetScaleData(u32 *out, u32 t, u32 *rec, Root *base);
extern void NNSi_G3dAnmGetScaleDataEx(u32 *out, u32 t, u32 *rec, Root *base);
extern void NNSi_G3dAnmGetRotData(u32 *out, u32 t, u32 *rec, Root *base);
extern void NNSi_G3dAnmGetRotDataEx(u32 *out, u32 t, u32 *rec, Root *base);
extern int NNSi_G3dAnmDecodeRotKey(int *out, s16 *a, s16 *b, u32 id);

void NNSi_G3dAnmCalcJntAnmNode(Root *root, u32 idx, u32 t, Out *out)
{
    u32 *p;
    u32 f;
    u32 *rec;
    int lerp;
    u32 res[6];
    u32 tmp[6];

    rec = (u32 *)((u8 *)root + *(u16 *)((u8 *)root + idx * 2 + 0x14));
    f = rec[0];
    if ((f & 1) != 0) {
        out->f00 = 7;
    } else {
        p = rec + 1;
        lerp = ((t & 0xfff) != 0 && (root->f08 & 1) != 0) ? 1 : 0;
        out->f00 = 0;

        if ((f & 6) == 0) {
            if ((f & 8) == 0) {
                if (lerp != 0)
                    NNSi_G3dAnmGetTransDataEx(&out->f4c, t, p, root);
                else
                    NNSi_G3dAnmGetTransData(&out->f4c, t, p, root);
                p = p + 2;
            } else {
                out->f4c = *p++;
            }
            if ((f & 0x10) == 0) {
                if (lerp != 0)
                    NNSi_G3dAnmGetTransDataEx(&out->f50, t, p, root);
                else
                    NNSi_G3dAnmGetTransData(&out->f50, t, p, root);
                p = p + 2;
            } else {
                out->f50 = *p++;
            }
            if ((f & 0x20) == 0) {
                if (lerp != 0)
                    NNSi_G3dAnmGetTransDataEx(&out->f54, t, p, root);
                else
                    NNSi_G3dAnmGetTransData(&out->f54, t, p, root);
                p = p + 2;
            } else {
                out->f54 = *p++;
            }
        } else if ((f & 2) != 0) {
            out->f00 = out->f00 | 4;
        } else {
            NNSi_G3dGetNodeTransFromMdl((u32 *)out);
        }

        if ((f & 0xc0) == 0) {
            if ((f & 0x100) == 0) {
                if (lerp != 0)
                    NNSi_G3dAnmGetRotDataEx((u32 *)&out->f28, t, p, root);
                else
                    NNSi_G3dAnmGetRotData((u32 *)&out->f28, t, p, root);
                p = p + 2;
            } else {
                u32 *axis = (u32 *)((u8 *)root + root->f0c);
                u32 *rows = (u32 *)((u8 *)root + root->f10);
                if (NNSi_G3dAnmDecodeRotKey((int *)((u32 *)&out->f28), (s16 *)axis, (s16 *)rows, *p) != 0) {
                    int a, b, c;
                    a = (out->f2c * out->f3c - out->f30 * out->f38) >> 12;
                    b = (out->f30 * out->f34 - out->f28 * out->f3c) >> 12;
                    c = (out->f28 * out->f38 - out->f2c * out->f34) >> 12;
                    out->f40 = a;
                    out->f44 = b;
                    out->f48 = c;
                }
                p = p + 1;
            }
        } else if ((f & 0x40) != 0) {
            out->f00 = out->f00 | 2;
        } else {
            NNSi_G3dGetNodeRotFromMdl(out);
        }

        if ((f & 0x600) == 0) {
            if ((f & 0x800) == 0) {
                if (lerp != 0)
                    NNSi_G3dAnmGetScaleDataEx(&tmp[4], t, p, root);
                else
                    NNSi_G3dAnmGetScaleData(&tmp[4], t, p, root);
                res[0] = tmp[4];
                res[3] = tmp[5];
            } else {
                res[0] = p[0];
                res[3] = p[1];
            }
            if ((f & 0x1000) == 0) {
                if (lerp != 0)
                    NNSi_G3dAnmGetScaleDataEx(&tmp[2], t, p + 2, root);
                else
                    NNSi_G3dAnmGetScaleData(&tmp[2], t, p + 2, root);
                res[1] = tmp[2];
                res[4] = tmp[3];
            } else {
                res[1] = p[2];
                res[4] = p[3];
            }
            if ((f & 0x2000) == 0) {
                if (lerp != 0)
                    NNSi_G3dAnmGetScaleDataEx(&tmp[0], t, p + 4, root);
                else
                    NNSi_G3dAnmGetScaleData(&tmp[0], t, p + 4, root);
                res[2] = tmp[0];
                res[5] = tmp[1];
            } else {
                res[2] = p[4];
                res[5] = p[5];
            }
        } else if ((f & 0x200) != 0) {
            out->f00 = out->f00 | 1;
        } else {
            NNSi_G3dGetNodeScaleFromMdl(out);
            return;
        }
    }

    {
        u32 k = (out->f00 & 1) ? 4 : 0;
        Disp *d = ((Disp *)gCurrentRS);
        d->hook(out, &res[0], d->first, k);
    }
}
