/*
 * function: func_0206EE60
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
 * scalar channels (func_0206F214 / func_0206F36C) or the rotation-less
 * flags, the rotation (func_0206F844 / func_0206FC5C, or one packed key
 * through func_0206FFA0 with row 2 rebuilt by the cross product), and the
 * three vector-2 channels (func_0206F4C8 / func_0206F6B0) into the result
 * block, then emits through the stash's four-argument hook.  A dead node
 * (flags bit 0) emits with out->f00 = 7; the 0x600-guarded "stash" arm
 * hands off to func_0206EC50, which emits on its own.
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
 *   g_02148DB0       0x02148DB0  data  a4
 *   func_0206EBB8    0x0206EBB8  arm
 *   func_0206EC50    0x0206EC50  arm
 *   func_0206ECE0    0x0206ECE0  arm
 *   func_0206F214    0x0206F214  arm
 *   func_0206F36C    0x0206F36C  arm
 *   func_0206F4C8    0x0206F4C8  arm
 *   func_0206F6B0    0x0206F6B0  arm
 *   func_0206F844    0x0206F844  arm
 *   func_0206FC5C    0x0206FC5C  arm
 *   func_0206FFA0    0x0206FFA0  arm
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206EE60.c \
 *       --func func_0206EE60 --addr 0x0206EE60 --arm --cc ../2.0/sp2p2
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

extern struct Root *g_02148DB0;

typedef signed short   s16;
extern void func_0206EBB8(u32 *out);
extern void func_0206EC50(void *arg);
extern void func_0206ECE0(Out *o);
extern void func_0206F214(u32 *out, u32 t, u32 *rec, Root *base);
extern void func_0206F36C(u32 *out, u32 t, u32 *rec, Root *base);
extern void func_0206F4C8(u32 *out, u32 t, u32 *rec, Root *base);
extern void func_0206F6B0(u32 *out, u32 t, u32 *rec, Root *base);
extern void func_0206F844(u32 *out, u32 t, u32 *rec, Root *base);
extern void func_0206FC5C(u32 *out, u32 t, u32 *rec, Root *base);
extern int func_0206FFA0(int *out, s16 *a, s16 *b, u32 id);

void func_0206EE60(Root *root, u32 idx, u32 t, Out *out)
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
                    func_0206F36C(&out->f4c, t, p, root);
                else
                    func_0206F214(&out->f4c, t, p, root);
                p = p + 2;
            } else {
                out->f4c = *p++;
            }
            if ((f & 0x10) == 0) {
                if (lerp != 0)
                    func_0206F36C(&out->f50, t, p, root);
                else
                    func_0206F214(&out->f50, t, p, root);
                p = p + 2;
            } else {
                out->f50 = *p++;
            }
            if ((f & 0x20) == 0) {
                if (lerp != 0)
                    func_0206F36C(&out->f54, t, p, root);
                else
                    func_0206F214(&out->f54, t, p, root);
                p = p + 2;
            } else {
                out->f54 = *p++;
            }
        } else if ((f & 2) != 0) {
            out->f00 = out->f00 | 4;
        } else {
            func_0206EBB8((u32 *)out);
        }

        if ((f & 0xc0) == 0) {
            if ((f & 0x100) == 0) {
                if (lerp != 0)
                    func_0206FC5C((u32 *)&out->f28, t, p, root);
                else
                    func_0206F844((u32 *)&out->f28, t, p, root);
                p = p + 2;
            } else {
                u32 *axis = (u32 *)((u8 *)root + root->f0c);
                u32 *rows = (u32 *)((u8 *)root + root->f10);
                if (func_0206FFA0((int *)((u32 *)&out->f28), (s16 *)axis, (s16 *)rows, *p) != 0) {
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
            func_0206ECE0(out);
        }

        if ((f & 0x600) == 0) {
            if ((f & 0x800) == 0) {
                if (lerp != 0)
                    func_0206F6B0(&tmp[4], t, p, root);
                else
                    func_0206F4C8(&tmp[4], t, p, root);
                res[0] = tmp[4];
                res[3] = tmp[5];
            } else {
                res[0] = p[0];
                res[3] = p[1];
            }
            if ((f & 0x1000) == 0) {
                if (lerp != 0)
                    func_0206F6B0(&tmp[2], t, p + 2, root);
                else
                    func_0206F4C8(&tmp[2], t, p + 2, root);
                res[1] = tmp[2];
                res[4] = tmp[3];
            } else {
                res[1] = p[2];
                res[4] = p[3];
            }
            if ((f & 0x2000) == 0) {
                if (lerp != 0)
                    func_0206F6B0(&tmp[0], t, p + 4, root);
                else
                    func_0206F4C8(&tmp[0], t, p + 4, root);
                res[2] = tmp[0];
                res[5] = tmp[1];
            } else {
                res[2] = p[4];
                res[5] = p[5];
            }
        } else if ((f & 0x200) != 0) {
            out->f00 = out->f00 | 1;
        } else {
            func_0206EC50(out);
            return;
        }
    }

    {
        u32 k = (out->f00 & 1) ? 4 : 0;
        Disp *d = ((Disp *)g_02148DB0);
        d->hook(out, &res[0], d->first, k);
    }
}
