/*
 * function: func_0204913C
 * address:  0x0204913C
 * packet:   pkt_0204913C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0204913C_File      0x020A7EE0  data
 *   FS_InitFile             0x020788AC  arm
 *   FS_CreateFileFromMemory 0x0207A940  arm
 *
 * arc_tool.c's memory-file opener: carve a 0x50-byte FSFile with the
 * three-argument allocator (the heap id is this function's THIRD parameter
 * and reaches the allocator first), initialise it, bind it to the caller's
 * buffer and length, run the reader over it, and hand the FSFile back.
 *
 * The __FILE__ argument is the arc_tool.c anchor at 0x020A7EE0 that
 * src/matched/func_02048D54.c and the rest of the 0x02049xxx run already
 * pin; the stacked fifth argument is __LINE__ = 0x21f.  Its own pool word
 * (0x02049198) sits inside the compared range, so the site resolves through
 * the `string` class - the anchor's address is fixed by the terminator of the
 * string in front of it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204913C.c \
 *       --func func_0204913C --addr 0x0204913C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern const char func_0204913C_File[];

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  FS_InitFile(void *file);
extern void  FS_CreateFileFromMemory(void *file, void *src, u32 size);
extern void func_0204919C(u8 *p);

void *func_0204913C(void *a0, u32 a1, u32 heap)
{
    void *f = func_02030734(heap, 0x50, 0, func_0204913C_File, 0x21f);

    FS_InitFile(f);
    FS_CreateFileFromMemory(f, a0, a1);
    func_0204919C(f);
    return f;
}
