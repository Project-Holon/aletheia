/*
 * function: ARC_TOOL_LoadMemberRangeImpl
 * address:  0x02048D54
 * packet:   pkt_02048F4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   arc_tool_file  0x020A7EE0  data
 *   func_02030734       0x02030734  arm
 *   ARC_TOOL_OpenArchive       0x02048DDC  arm
 *   ARC_TOOL_SeekMember       0x02048E34  arm
 *   func_02078A80       0x02078A80  arm
 *   func_02078B70       0x02078B70  arm
 *
 * The allocating twin of ARC_TOOL_ReadMemberRangeImpl: bind a temporary 0x48-byte archive
 * handle to `archive_id`, size the member, take a block of exactly that size
 * from the caller's heap, read the member into it, close the handle and hand
 * the block back.  The __FILE__ argument is "arc_tool.c" at 0x020A7EE0, the
 * same string src/matched/sub_020490F4.c already pins, with line 0xbb.
 *
 * This is the function the whole map-model path goes through: func_02048F60
 * calls it as ARC_TOOL_LoadMemberRangeImpl(9, matrix_id, heap, 0, NULL), and ov010's
 * func_02159B94 is what supplies archive id 9 (a/0/0/9) and the matrix id
 * read out of the zone record's +0x04 lane.  See docs/ASSETS.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_LoadMemberRangeImpl.c \
 *       --func ARC_TOOL_LoadMemberRangeImpl --addr 0x02048D54 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct ArcHandle {
    u8 raw[0x48];
};

extern const char arc_tool_file[];

typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct ArcFile;
extern void ARC_TOOL_OpenArchive(struct ArcFile *arc, u32 id);
typedef signed int     s32;
struct FSFile;
extern u32 ARC_TOOL_SeekMember(struct ArcHandle *arc, u32 member, u32 base, u32 size);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);
extern void func_02078A80(struct ArcHandle *h);

void *ARC_TOOL_LoadMemberRangeImpl(u32 archive_id, u32 member, u32 heap, u32 mode,
                    u32 *size_out)
{
    struct ArcHandle h;
    u32 size;
    void *buf;

    ARC_TOOL_OpenArchive((struct ArcFile *)(&h), archive_id);
    size = ARC_TOOL_SeekMember(&h, member, mode, (u32)size_out);
    buf = func_02030734(heap, size, 0, arc_tool_file, 0xbb);
    func_02078B70((struct FSFile *)(&h), buf, size);
    func_02078A80(&h);
    return buf;
}
