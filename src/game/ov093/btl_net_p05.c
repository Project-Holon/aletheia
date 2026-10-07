/*
 * file:     btl_net_p05.c
 * unit:     yes
 * function: func_021D4558, func_021D45B8
 * address:  0x021D4558
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_02030734   0x02030734  arm
 *   d_021F3B88     0x021F3B88  data  ov093
 *   d_021F3A98     0x021F3A98  data  ov093  a1
 */
#include "../../matched/include/Obj12142.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct S {
    u32 f00;
    u16 f04;
    u8 pad06[0x3ade];
    void *tblA[4];
};

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void *func_021D4558(int idx, int unused, u32 size);
void func_021D45B8(int a, int b);
extern struct S *d_021F3B88;
extern const char d_021F3A98[];


void *func_021D4558(int idx, int unused, u32 size)
{
    if (size == 4)
        return (u8 *)d_021F3B88 + 0xbf4 + idx * 0xbbc;
    d_021F3B88->tblA[idx] = sub_02030734((u16)((d_021F3B88->f04 & 0x7fff) | 0x8000), size, 1, d_021F3A98, 0x21f);
    return d_021F3B88->tblA[idx];
}


/*
 * Unlabelled leaf (hidden in the pool run after func_021D4558).  Setter
 * through d_021F3B88: a special value for b==4, otherwise a plain u32
 * store.
 */
void func_021D45B8(int a, int b)
{
    if (b == 4) {
        char *q = (char *)d_021F3B88 + 0xbf4 + a * 0xbbc;
        ((struct Obj12142 *)q)->fBB8 = b;
        ((struct Obj12142 *)q)->fBBA = 0;
    } else {
        *(int *)((char *)d_021F3B88 + a * 4 + 0x3af4) = b;
    }
}
