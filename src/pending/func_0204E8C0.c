/*
 * function: func_0204E8C0
 * address:  0x0204E8C0
 * packet:   pkt_0204E6F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * TU: double3Ddisp.c.  The __FILE__ pointer at 0x020A7F94 reads
 * "double3Ddisp.c" (line 63 here), and it is the first reference to that
 * string in the image, so this function is the start of the translation
 * unit.  The block just before it belongs to fade.c (0x020A7F8C, referenced
 * from 0x0204E630), which is the file src/matched/unit_0204E720.c and its
 * neighbours are in.
 *
 * Blocked at MATCH on the `label`/`matched` classes: all 68 concrete bytes
 * are right, but func_0204E914 (0x0204E914) has exactly one branch
 * reference image-wide, the call at the end of this function, so the site
 * has no witness and no cut frees it.  0x0204E914 is closed to a register
 * allocation residue, see docs/notes/func_0204E914.c.txt, which also
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
 *   func_0204E914       0x0204E914  arm
 *   double3Ddisp_File   0x020A7F94  data
 *   g_02146A80          0x02146A80  data
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204E8C0.c \
 *       --func func_0204E8C0 --addr 0x0204E8C0 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;

struct Double3Ddisp {
    u16 heap;   /* 0x00 */
    u16 pad02;  /* 0x02 */
    s32 unk04;  /* 0x04 */
    s32 unk08;  /* 0x08 */
    u32 pad0c[24];
};

extern struct Double3Ddisp *g_02146A80;
extern const char double3Ddisp_File[];

extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file,
                           u32 line);
extern void  func_0204E914(void);

void func_0204E8C0(u32 heap)
{
    g_02146A80 = func_02030734(heap, 0x6c, 1, double3Ddisp_File, 63);

    g_02146A80->heap = heap;
    g_02146A80->unk04 = 1;
    g_02146A80->unk08 = 0;

    func_0204E914();
}
