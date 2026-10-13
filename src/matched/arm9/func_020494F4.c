/*
 * unit:     no
 * function: ARC_TOOL_GetHandleMemberOffsetOut
 * address:  0x020494F4
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
 *   func_02078B44      0x02078B44  arm
 *   func_02078B70      0x02078B70  arm
 *   arc_tool_file 0x020A7EE0  data
 *   arc_tool_msg_member_bounds  0x020A7F18  data
 *
 * Store the absolute image offset of one archive member through an out
 * parameter.  Only the FAT entry's start word is read; the end word is
 * never touched, which is the 4-byte read rather than 8.
 *
 * The bounds assertion is the same five-argument call func_02049250
 * uses: the count is already in r3 from the guard's own `cmp`, so only
 * the member reaches the stack
 * (docs/idioms/a-free-variadic-argument-is-the-value-the-guard-compared.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_TOOL_GetHandleMemberOffsetOut.c  *       --func ARC_TOOL_GetHandleMemberOffsetOut --addr 0x020494F4 --cc 1.1p1 --arm
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
extern int func_02078B44(struct FSFile *file, long offset, int origin);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);

void ARC_TOOL_GetHandleMemberOffsetOut(struct ArcFile *arc, u32 member, u32 *out)
{
    u32 start;

    if (arc->count <= member) {
        func_02034734(arc_tool_file, 713, arc_tool_msg_member_bounds,
                      arc->count, member);
    }

    func_02078B44((struct FSFile *)arc, arc->fatOffset + 0xc + member * 8, 0);
    func_02078B70((struct FSFile *)arc, &start, 4);
    *out = arc->imageBase + 8 + start;
}
