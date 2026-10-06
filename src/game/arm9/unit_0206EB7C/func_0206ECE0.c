/*
 * function: func_0206ECE0
 * address:  0x0206ECE0
 * packet:   pkt_0206EB00
 * region:   arm9
 * compiler: ../2.0/sp2p2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02148DB0      0x02148DB0  data  a4
 *   g_020A1998      0x020A1998  data  a1
 *   g_020A1999      0x020A1999  data  a1
 *   g_020A199A      0x020A199A  data  a1
 *   g_020A199B      0x020A199B  data  a1
 *   func_020834A8   0x020834A8  thumb
 *
 * NitroSystem joint-rotation fetch from NNSG3dResNodeData (docs/notes/
 * pkt_0206EB00.c.txt): flag bit 1 trans zero, 2 rot zero, 8 pivot-compressed
 * (0xf0 the pivot index, 0x100 / 0x200 / 0x400 the pivot sign and the C / D
 * sign reversals over the four pivot-column tables at 0x020A1998..B), else
 * the nine rotation entries copied out.  func_020834A8 is MI_Zero36B.
 *
 * THE LEVER (wave 18, lane ties_a; it was DIFF 384/384, 14 bytes out for
 * seven waves): the pivot index k is `long`, not int.  With int, node and
 * k swap r4 / r5 at every use; mwcc colours long and int as different
 * types.  EXACT under ../2.0/sp2 as well.
 */
#include "../../../matched/include/Obj05777.h"
#include "../../../matched/include/Obj16628.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short s16;

typedef struct { u8 unk00; u8 idx01; } Hdr;
typedef struct { u8 unk00; u8 cnt01; u8 unk02[4]; u16 off06; } Bank;
typedef struct { Hdr *h; u8 pad[0xD0]; Bank *bank; } Root;
typedef struct { u32 rel00; } Ent;

typedef struct { u8 c; u8 pad[3]; } Perm;

typedef struct { u32 f00; u8 pad04[0x24]; int m[9]; } Out;

extern Root *g_02148DB0;
extern const Perm g_020A1998[];
extern const Perm g_020A1999[];
extern const Perm g_020A199A[];
extern const Perm g_020A199B[];

extern void func_020834A8(void *p);


static inline u8 *entry_of(Bank *b, u32 idx)
{
    u8 *t;
    if (b != 0 && idx < b->cnt01) {
        t = (u8 *)b + b->off06;
        return t + 4 + (((struct Obj16628 *)t)->f0) * idx;
    }
    return 0;
}

static inline u8 *resolve(Bank *b, u32 idx)
{
    u8 *e;
    if (b != 0) {
        e = entry_of(b, idx);
        if (e != 0)
            return (u8 *)b + ((Ent *)e)->rel00;
    }
    return 0;
}

void func_0206ECE0(Out *out)
{
    Root *r = g_02148DB0;
    u8 *node;
    u32 f;
    s16 *p;
    long k;
    int u;
    int v;

    node = resolve(r->bank, r->h->idx01);
    f = ((u16 *)node)[0];
    p = (s16 *)(node + 4);
    if ((f & 1) == 0) p = (s16 *)((u8 *)p + 0xc);
    if ((f & 2) == 0) {
        if ((f & 8) != 0) {
            k = (int)(f & 0xf0) >> 4;
            u = p[0];
            v = p[1];
            func_020834A8(out->m);
            out->m[k] = (((struct Obj05777 *)node)->f0 & 0x100) ? -0x1000 : 0x1000;
            out->m[g_020A1998[k].c] = u;
            out->m[g_020A1999[k].c] = v;
            out->m[g_020A199A[k].c] = (((struct Obj05777 *)node)->f0 & 0x200) ? -v : v;
            out->m[g_020A199B[k].c] = (((struct Obj05777 *)node)->f0 & 0x400) ? -u : u;
        } else {
            out->m[0] = ((s16 *)node)[1];
            out->m[1] = p[0];
            out->m[2] = p[1];
            out->m[3] = p[2];
            out->m[4] = p[3];
            out->m[5] = p[4];
            out->m[6] = p[5];
            out->m[7] = p[6];
            out->m[8] = p[7];
        }
    } else {
        out->f00 |= 2;
    }
}
