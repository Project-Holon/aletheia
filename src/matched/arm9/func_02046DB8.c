/*
 * function: G3D_SYSTEM_CreateResourceArc
 * address:  0x02046DB8
 * packet:   pkt_02046DB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _G3dSystem      0x02146A5C  data
 *   sG3dSystemFile  0x020A7EA8  data
 *   func_02030734   0x02030734  arm
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   G3D_SYSTEM_InitResourceByFile   0x02046CE0  arm
 *
 * g3d_system.c's eight-byte-node allocators.  Three siblings, identical but
 * for the loader they call and the source line: read the size from the
 * global's +0x18 halfword, allocate eight bytes with file name and line, run
 * the loader for (arg0, arg1, that same halfword) and hand its result to
 * G3D_SYSTEM_InitResourceByFile together with the new node.  The global is re-read after the
 * allocator call - the callee may have replaced it - which is why the second
 * `ldr r1, [r4]` is there.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_SYSTEM_CreateResourceArc.c \
 *       --func G3D_SYSTEM_CreateResourceArc --addr 0x02046DB8 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct G3dSys {
    u8  pad00[0x18];
    u16 h18;            /* +0x18 */
};

extern struct G3dSys *_G3dSystem;
extern u8 sG3dSystemFile;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct S02046CE0;
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern void G3D_SYSTEM_InitResourceByFile(struct S02046CE0 *out, u32 *tag);

void *G3D_SYSTEM_CreateResourceArc(u32 a0, u32 a1)
{
    u8 *node = func_02030734(_G3dSystem->h18, 8, 0,
                             (const char *)&sG3dSystemFile, 0x2b4);

    G3D_SYSTEM_InitResourceByFile((struct S02046CE0 *)node, ARC_TOOL_LoadMember(a0, a1, _G3dSystem->h18));
    return node;
}
