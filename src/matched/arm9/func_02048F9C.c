/*
 * function: ARC_TOOL_LoadMemberFromPath
 * address:  0x02048F9C
 * packet:   pkt_02048F9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   arc_tool_file 0x020A7EE0  data
 *   ARC_TOOL_SeekMember  0x02048E34  arm
 *   FS_InitFile  0x020788AC  arm
 *   FS_CloseFile  0x02078A80  arm
 *   FS_ReadFile  0x02078B70  arm
 *   FS_OpenFile  0x02078C18  arm
 *
 * Promote-first callee of src/pending/G3D_SYSTEM_CreateResourcePath.c (parks lane 2).
 * Open one member of an archive by path, size it, allocate the block from
 * the debug allocator, read the bytes in and close.  Same shape as its
 * sibling ARC_TOOL_LoadHandleMember in the same cluster; the 0x4c frame is the 0x48
 * ArcFile handle at sp+4 plus the allocator's one outgoing stack word.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_LoadMemberFromPath.c \
 *       --func ARC_TOOL_LoadMemberFromPath --addr 0x02048F9C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct ArcFile {
    u8 file[0x48];
};

extern const char arc_tool_file[];

extern void FS_InitFile(struct ArcFile *f);
extern void FS_OpenFile(struct ArcFile *f, const char *path);
struct ArcHandle;
extern u32 ARC_TOOL_SeekMember(struct ArcHandle *arc, u32 member, u32 base, u32 size);
typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
typedef signed int     s32;
struct FSFile;
extern s32 FS_ReadFile(struct FSFile *file, void *buffer, s32 length);
extern void FS_CloseFile(struct ArcFile *f);

void *ARC_TOOL_LoadMemberFromPath(const char *path, u32 a, u32 heap)
{
    struct ArcFile file;
    void *p;
    u32 size;

    FS_InitFile(&file);
    FS_OpenFile(&file, path);
    size = ARC_TOOL_SeekMember((struct ArcHandle *)(&file), a, 0, 0);
    p = func_02030734(heap, size, 0, arc_tool_file, 0x182);
    FS_ReadFile((struct FSFile *)(&file), p, size);
    FS_CloseFile(&file);
    return p;
}
