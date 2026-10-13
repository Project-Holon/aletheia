/*
 * function: ARC_TOOL_ReadMemberRangeImpl
 * address:  0x02048D00
 * packet:   pkt_02048F4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ARC_TOOL_OpenArchive  0x02048DDC  arm
 *   ARC_TOOL_SeekMember  0x02048E34  arm
 *   func_02078A80  0x02078A80  arm
 *   func_02078B70  0x02078B70  arm
 *
 * Read one sub-file of one archive into a buffer the caller owns.  The whole
 * archive handle is a 0x48 byte stack local: ARC_TOOL_OpenArchive binds it to the
 * archive named by `archive_id` (it indexes the 235-entry a/x/y/z name table
 * at 0x020A6C58), ARC_TOOL_SeekMember seeks the member and returns its byte size,
 * func_02078B70 is the read and func_02078A80 closes the handle again.
 *
 * Nothing survives the call, so this is the one-shot form: a caller that wants
 * the archive to stay open uses func_020490F4 instead.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_ReadMemberRangeImpl.c \
 *       --func ARC_TOOL_ReadMemberRangeImpl --addr 0x02048D00 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct ArcHandle {
    u8 raw[0x48];
};

struct ArcFile;
extern void ARC_TOOL_OpenArchive(struct ArcFile *arc, u32 id);
typedef signed int     s32;
struct FSFile;
extern u32 ARC_TOOL_SeekMember(struct ArcHandle *arc, u32 member, u32 base, u32 size);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);
extern void func_02078A80(struct ArcHandle *h);

void ARC_TOOL_ReadMemberRangeImpl(void *dst, u32 archive_id, u32 member, u32 mode,
                   u32 *size_out)
{
    struct ArcHandle h;

    ARC_TOOL_OpenArchive((struct ArcFile *)(&h), archive_id);
    func_02078B70((struct FSFile *)(&h), dst, ARC_TOOL_SeekMember(&h, member, mode, (u32)size_out));
    func_02078A80(&h);
}
