/*
 * function: func_02046E90
 * address:  0x02046E90
 * packet:   pkt_02046CE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A5C      0x02146A5C  data
 *   sG3dSystemFile  0x020A7EA8  data
 *   func_02030734   0x02030734  arm
 *   func_02048F9C  0x02048F9C  arm
 *   func_02046CE0   0x02046CE0  arm
 *
 * g3d_system.c's eight-byte-node allocators.  Three siblings, identical but
 * for the loader they call and the source line: read the size from the
 * global's +0x18 halfword, allocate eight bytes with file name and line, run
 * the loader for (arg0, arg1, that same halfword) and hand its result to
 * func_02046CE0 together with the new node.  The global is re-read after the
 * allocator call - the callee may have replaced it - which is why the second
 * `ldr r1, [r4]` is there.
 *
 * Promoted by parks lane 2: the loader 0x02048F9C was filed first as an
 * EXACT entry (src/matched/func_02048F9C.c, shard pkt_02048F9C) and the call
 * at +0x48 now resolves through the `matched` class.  No change to the C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046E90.c \
 *       --func func_02046E90 --addr 0x02046E90 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct G3dSys {
    u8  pad00[0x18];
    u16 h18;            /* +0x18 */
};

extern struct G3dSys *g_02146A5C;
extern u8 sG3dSystemFile;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct S02046CE0;
extern void *func_02048F9C(const char *path, u32 a, u32 heap);
extern void func_02046CE0(struct S02046CE0 *out, u32 *tag);

void *func_02046E90(u32 a0, u32 a1)
{
    u8 *node = func_02030734(g_02146A5C->h18, 8, 0,
                             (const char *)&sG3dSystemFile, 0x2dc);

    func_02046CE0((struct S02046CE0 *)node, func_02048F9C((const char *)a0, a1, g_02146A5C->h18));
    return node;
}
