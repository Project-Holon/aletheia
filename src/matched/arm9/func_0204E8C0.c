/*
 * function: DOUBLE3DDISP_Init
 * address:  0x0204E8C0
 * packet:   pkt_0204E6F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TU: double3Ddisp.c.  The __FILE__ pointer at 0x020A7F94 reads
 * "double3Ddisp.c" (line 63 here), and it is the first reference to that
 * string in the image, so this function is the start of the translation
 * unit.  The block just before it belongs to fade.c (0x020A7F8C, referenced
 * from 0x0204E630), which is the file src/matched/unit_0204E720.c and its
 * neighbours are in.
 *
 * Blocked at MATCH on the `label`/`matched` classes: all 68 concrete bytes
 * are right, but DOUBLE3DDISP_InitOam (0x0204E914) has exactly one branch
 * reference image-wide, the call at the end of this function, so the site
 * has no witness and no cut frees it.  0x0204E914 is closed to a register
 * allocation residue, see docs/notes/DOUBLE3DDISP_InitOam.c.txt, which also
 * carries the C for it.
 *
 * Constructor: allocate the 0x6c-byte singleton on the caller's heap and
 * publish it at 0x02146A80.  The `mov r4, #1` is shared between the
 * allocator's third argument and the store to +0x04.  Only the first store
 * uses the pointer the allocator returned; the two after it re-read the
 * global, because a store through it could have overwritten the global
 * itself.
 *
 * symbols:
 *   func_02030734       0x02030734  arm
 *   DOUBLE3DDISP_InitOam       0x0204E914  arm
 *   double3Ddisp_File   0x020A7F94  data
 *   g_02146A80          0x02146A80  data
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/DOUBLE3DDISP_Init.c \
 *       --func DOUBLE3DDISP_Init --addr 0x0204E8C0 --cc 1.1p1 --arm
 */

#include "../include/G_Double3Ddisp.h"

typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;

extern struct Double3Ddisp *g_02146A80;
extern const char double3Ddisp_File[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  DOUBLE3DDISP_InitOam(void);

void DOUBLE3DDISP_Init(u32 heap)
{
    g_02146A80 = func_02030734(heap, 0x6c, 1, double3Ddisp_File, 63);

    g_02146A80->heap = heap;
    g_02146A80->unk04 = 1;
    g_02146A80->unk08 = 0;

    DOUBLE3DDISP_InitOam();
}
