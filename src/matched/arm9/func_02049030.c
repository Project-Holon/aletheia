/*
 * function: ARC_TOOL_GetArchiveFileCount
 * address:  0x02049030
 * packet:   pkt_02049030
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   ARC_TOOL_OpenArchive  0x02048DDC  arm
 *   FS_CloseFile  0x02078A80  arm
 *   func_02078B44  0x02078B44  arm
 *   FS_ReadFile  0x02078B70  arm
 */

typedef unsigned int u32;
typedef unsigned short u16;

struct ArcFile;
extern void ARC_TOOL_OpenArchive(struct ArcFile *arc, u32 id);
extern void FS_CloseFile(void *p);
typedef signed int     s32;
struct FSFile;
extern int func_02078B44(struct FSFile *file, long offset, int origin);
extern s32 FS_ReadFile(struct FSFile *file, void *buffer, s32 length);

u32 ARC_TOOL_GetArchiveFileCount(u32 a)
{
    char buf[0x48];
    int off;
    u16 hdr[3];

    off = 0;
    ARC_TOOL_OpenArchive((struct ArcFile *)buf, a);
    func_02078B44((struct FSFile *)buf, 0xc, 0);
    FS_ReadFile((struct FSFile *)buf, &off, 2);
    func_02078B44((struct FSFile *)buf, off + 4, 0);
    FS_ReadFile((struct FSFile *)buf, hdr, 6);
    FS_CloseFile(buf);
    return hdr[2];
}
