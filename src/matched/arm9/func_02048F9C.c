/*
 * function: func_02048F9C
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
 *   func_02048F9C_File 0x020A7EE0  data
 *
 * Promote-first callee of src/pending/func_02046E90.c (parks lane 2).
 * Open one member of an archive by path, size it, allocate the block from
 * the debug allocator, read the bytes in and close.  Same shape as its
 * sibling func_02049250 in the same cluster; the 0x4c frame is the 0x48
 * ArcFile handle at sp+4 plus the allocator's one outgoing stack word.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02048F9C.c \
 *       --func func_02048F9C --addr 0x02048F9C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct ArcFile {
    u8 file[0x48];
};

extern const char func_02048F9C_File[];

extern void func_020788AC(struct ArcFile *f);
extern void func_02078C18(struct ArcFile *f, const char *path);
extern u32 func_02048E34(struct ArcFile *f, u32 a, u32 b, u32 c);
typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02078B70(struct ArcFile *f, void *dst, u32 size);
extern void func_02078A80(struct ArcFile *f);

void *func_02048F9C(const char *path, u32 a, u32 heap)
{
    struct ArcFile file;
    void *p;
    u32 size;

    func_020788AC(&file);
    func_02078C18(&file, path);
    size = func_02048E34(&file, a, 0, 0);
    p = func_02030734(heap, size, 0, func_02048F9C_File, 0x182);
    func_02078B70(&file, p, size);
    func_02078A80(&file);
    return p;
}
