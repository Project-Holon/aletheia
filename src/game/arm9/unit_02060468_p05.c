/*
 * file:     unit_02060468_p05.c
 * unit:     yes
 * function: func_0206074C, func_02060764, func_02060790, func_020607B8, func_020607E8
 * address:  0x0206074C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020606A8   0x020606A8  arm
 *   func_020605B4   0x020605B4  arm
 */
#include "../../matched/include/Obj00512.h"
#include "../../matched/include/Obj00512.h"

struct DList;
typedef unsigned int   u32;

typedef unsigned short u16;

extern void *func_020606A8(u32 a);
extern void func_020605B4(volatile struct DList *list, void *elem);
void NHTTP_CleanupAsync(void *p);
void func_02060764(int *out, int *blk);
void *func_02060790(int *p, int *node);
void *func_020607B8(int *p, void *node, int *a);
void *func_020607E8(int *p, int v);




void NHTTP_CleanupAsync(void *p)
{
    func_020605B4(func_020606A8((u32)p), p);
}




/*
 * Block extent: writes the two ends of a heap block into a two-word result.
 * out[0] is the block's own start, recovered from the size of the preceding
 * block, which the header packs into the top seven bits of the flag halfword
 * as (flags >> 8) & 0x7f.  out[1] is the block's end: the block plus the
 * 0x10-byte header plus the free-space word at +4.
 *
 * The flag halfword is loaded zero-extended but shifted arithmetically, which
 * is what an int temporary gives: the mask forces the top byte down to seven
 * bits, and re-narrowing the result to u16 is the lsl/lsr pair the sub then
 * folds into its operand.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02060764.c \
 *       --func func_02060764 --addr 0x02060764 --cc 1.1p1 --arm
 */
void func_02060764(int *out, int *blk)
{
    int f = ((struct Obj00512 *)blk)->f2;

    out[0] = (int)blk - (u16)((f >> 8) & 0x7f);
    out[1] = blk[1] + (int)(blk + 4);
}



void *func_02060790(int *p, int *node)
{
    int *a = (int *)node[2];
    int *b = (int *)node[3];
    if (a != 0)
        a[3] = (int)b;
    else
        p[0] = (int)b;
    if (b != 0)
        b[2] = (int)a;
    else
        p[1] = (int)a;
    return a;
}




void *func_020607B8(int *p, void *node, int *a)
{
    int *b;
    ((struct Obj00512 *)node)->f8 = (int)a;
    if (a != 0) {
        b = (int *)a[3];
        a[3] = (int)node;
    } else {
        b = (int *)p[0];
        p[0] = (int)node;
    }
    *(int *)&((struct Obj00512 *)node)->fC = (int)b;
    if (b != 0)
        b[2] = (int)node;
    else
        p[1] = (int)node;
    return node;
}


void *func_020607E8(int *p, int v)
{
    int *q = (int *)p[0];
    ((struct Obj00512 *)q)->f0 = (unsigned short)v;
    ((struct Obj00512 *)q)->f2 = 0;
    ((struct Obj00512 *)q)->f4 = (int)((char *)p[1] - ((char *)q + 0x10));
    ((struct Obj00512 *)q)->f8 = 0;
    *(int *)&((struct Obj00512 *)q)->fC = 0;
    return q;
}
