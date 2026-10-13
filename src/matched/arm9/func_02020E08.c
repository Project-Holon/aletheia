/*
 * unit:     no
 * function: FILE_UTIL_LoadRange
 * address:  0x02020E08
 * packet:   pkt_02020E08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FILE_UTIL_FILE_NAME     0x020A73B0  data
 *   FILE_UTIL_OpenById  0x02020DEC  thumb
 *   FS_CloseFile   0x02078A80  arm
 *   FS_SeekFile    0x02078B44  arm
 *   FS_ReadFile    0x02078B70  arm
 *   FS_GetLength   0x02078C28  arm
 *   sub_02030734   0x02030734  arm
 *
 * "Read a byte range out of a whole file, by archive id", the raw-file
 * counterpart to the arc_tool.c NARC member API.  FILE_UTIL_OpenById (already
 * EXACT) opens the file whose path is name-table entry `archive_id`; this
 * function then seeks to `offset`, allocates `size` bytes on `heap` and
 * reads them in.  A zero `size` means "the whole file", which is why the
 * FS_GetLength call is guarded rather than unconditional.
 *
 * FILE_UTIL_FILE_NAME is the __FILE__ argument of the allocation site.  Its bytes
 * spell "file_util.c", and the run is fixed from outside this function by
 * the terminator of "bmp_cursor.c" immediately before it
 * (docs/idioms/file-string-is-an-abs32-into-the-string-area.md), so the
 * enclosing translation unit for both this function and FILE_UTIL_OpenById is
 * file_util.c.
 *
 * The only caller in the image is ZONEDATA_CreateAreaData, the a/0/1/3 record reader
 * (src/matched/ZONEDATA_CreateAreaData.c), which passes archive_id 13 with size 10:
 * a/0/1/3 is a flat 2820-byte file, not a NARC, so it cannot go through
 * the member API at all.  See the "Archive readers traced by call graph"
 * section of docs/ASSETS.md.
 *
 * `size` has to stay live in its own local across the guarded call: the
 * compiler keeps r5 as both the parameter and the FS_GetLength result, so
 * writing the length into a fresh variable and selecting afterwards costs
 * an extra move.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_LoadRange.c \
 *       --func FILE_UTIL_LoadRange --addr 0x02020E08 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct FSFile {
    u8 raw[0x48];
};

extern char FILE_UTIL_FILE_NAME[];

typedef unsigned short u16;
extern void FILE_UTIL_OpenById(void *p, u32 x);
extern void  FS_CloseFile(struct FSFile *file);
extern u32   FS_SeekFile(struct FSFile *file, int offset, u32 origin);
extern u32   FS_ReadFile(struct FSFile *file, void *dst, u32 size);
extern u32   FS_GetLength(struct FSFile *file);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void *FILE_UTIL_LoadRange(u32 archive_id, u32 heap, u32 offset, u32 size)
{
    struct FSFile file;
    void *buf;

    FILE_UTIL_OpenById(&file, archive_id);
    if (size == 0) {
        size = FS_GetLength(&file);
    }
    buf = sub_02030734(heap, size, 0, FILE_UTIL_FILE_NAME, 0xAC);
    FS_SeekFile(&file, offset, 0);
    FS_ReadFile(&file, buf, size);
    FS_CloseFile(&file);
    return buf;
}
