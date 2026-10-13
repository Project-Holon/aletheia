/*
 * function: ARC_TOOL_GetMemberSize
 * address:  0x020490A8
 * packet:   pkt_02049030
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   ARC_TOOL_OpenArchive  0x02048DDC  arm
 *   ARC_TOOL_SeekMember  0x02048E34  arm
 *   FS_CloseFile  0x02078A80  arm
 */

typedef unsigned int u32;

struct ArcFile;
struct ArcHandle;
extern void ARC_TOOL_OpenArchive(struct ArcFile *arc, u32 id);
extern u32 ARC_TOOL_SeekMember(struct ArcHandle *arc, u32 member, u32 base, u32 size);
extern void FS_CloseFile(void *p);

u32 ARC_TOOL_GetMemberSize(u32 a, u32 b)
{
    char buf[0x48];
    u32 r;

    ARC_TOOL_OpenArchive((struct ArcFile *)buf, a);
    r = ARC_TOOL_SeekMember((struct ArcHandle *)buf, b, 0, 0);
    FS_CloseFile(buf);
    return r;
}
