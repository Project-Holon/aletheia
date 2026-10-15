/*
 * unit:     no
 * function: ARC_TOOL_LoadHandleMember
 * address:  0x02049250
 * packet:   pkt_02049250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02030734      0x02030734  arm
 *   func_02034734      0x02034734  arm
 *   FS_SeekFile      0x02078B44  arm
 *   FS_ReadFile      0x02078B70  arm
 *   arc_tool_file 0x020A7EE0  data
 *   arc_tool_msg_member_bounds  0x020A7F18  data
 *
 * Read one member out of an open archive into a fresh heap block.  The
 * handle is an FSFile (0x48 bytes) with the archive's own bookkeeping
 * appended: the FAT offset at +0x4c and the member count at +0x4e, both
 * halfwords, and the image base at +0x48.
 *
 * The FAT entry is a pair of words (start, end) at
 * `fatOffset + 0xc + member * 8`, read into an on-stack two-word buffer;
 * the member's bytes then start at `imageBase + 8 + start` and run
 * `end - start` long.  The difference is written out twice, not cached in a
 * local: the original recomputes `sub r2, r3, r2` after the allocation from
 * two fresh stack loads.
 *
 * The assertion's variadic tail is two values, the count and the member,
 * not one.  The tell is that r3 is never written on the assert path: the
 * `ldrh r3, [r5, #0x4e]` that fed the guard's own `cmp` is still live, so
 * the first variadic argument costs no instruction at all, and only the
 * second reaches the stack.  Declared with a single variadic argument the
 * member lands in r3 instead and the `str r7, [sp]` disappears; see
 * docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md.
 *
 * 0x020A7EE0 is the arc_tool.c anchor this translation unit already uses in
 * ARC_TOOL_LoadMemberRangeImpl; 0x020A7F18 is the assertion message, attested by the
 * terminator of the string in front of it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_LoadHandleMember.c \
 *       --func ARC_TOOL_LoadHandleMember --addr 0x02049250 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct ArcFile {
    u8  file[0x48];
    u32 imageBase;
    u16 fatOffset;
    u16 count;
};

extern const char arc_tool_file[];
extern const char arc_tool_msg_member_bounds[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02034734(const char *file, u32 line, const char *msg, ...);
typedef signed int     s32;
struct FSFile;
extern int FS_SeekFile(struct FSFile *file, long offset, int origin);
extern s32 FS_ReadFile(struct FSFile *file, void *buffer, s32 length);

void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap)
{
    u32 range[2];
    void *buf;

    if (arc->count <= member) {
        func_02034734(arc_tool_file, 613, arc_tool_msg_member_bounds,
                      arc->count, member);
    }

    FS_SeekFile((struct FSFile *)arc, arc->fatOffset + 0xc + member * 8, 0);
    FS_ReadFile((struct FSFile *)arc, range, 8);
    FS_SeekFile((struct FSFile *)arc, arc->imageBase + 8 + range[0], 0);

    buf = func_02030734(heap, range[1] - range[0], 0, arc_tool_file, 619);
    if (buf != 0) {
        FS_ReadFile((struct FSFile *)arc, buf, range[1] - range[0]);
    }
    return buf;
}
