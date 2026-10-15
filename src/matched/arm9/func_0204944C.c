/*
 * unit:     no
 * function: ARC_TOOL_ReadHandleMemberRange
 * address:  0x0204944C
 * packet:   pkt_02049250
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02034734      0x02034734  arm
 *   FS_SeekFile      0x02078B44  arm
 *   FS_ReadFile      0x02078B70  arm
 *   arc_tool_file 0x020A7EE0  data
 *   arc_tool_msg_member_bounds  0x020A7F18  data
 *
 * Read a window out of the middle of one archive member.  Only the FAT
 * entry's first word is fetched (a 4-byte read, not 8), because the end
 * offset is never needed: the caller supplies both the offset into the
 * member and the length.
 *
 * The seek target is `offset + (imageBase + 8 + start)`: the accumulator of
 * the final `add` is the register holding the computed base, which is what
 * puts the caller's offset on the left of the source expression
 * (docs/idioms/the-accumulator-of-a-commutative-chain-is-its-second-operand.md).
 *
 * The bounds assertion is the same five-argument call ARC_TOOL_LoadHandleMember uses:
 * the count is already in r3 from the guard's own `cmp`, so only the member
 * reaches the stack (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_ReadHandleMemberRange.c  *       --func ARC_TOOL_ReadHandleMemberRange --addr 0x0204944C --cc 1.1p1 --arm
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

extern void func_02034734(const char *file, u32 line, const char *msg, ...);
typedef signed int     s32;
struct FSFile;
extern int FS_SeekFile(struct FSFile *file, long offset, int origin);
extern s32 FS_ReadFile(struct FSFile *file, void *buffer, s32 length);

void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *arc, u32 member, u32 offset, u32 size,
                   void *dst)
{
    u32 start;

    if (arc->count <= member) {
        func_02034734(arc_tool_file, 689, arc_tool_msg_member_bounds,
                      arc->count, member);
    }

    FS_SeekFile((struct FSFile *)arc, arc->fatOffset + 0xc + member * 8, 0);
    FS_ReadFile((struct FSFile *)arc, &start, 4);
    FS_SeekFile((struct FSFile *)arc, offset + (arc->imageBase + 8 + start), 0);
    FS_ReadFile((struct FSFile *)arc, dst, size);
}
