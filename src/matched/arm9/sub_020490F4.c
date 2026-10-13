/*
 * function: sub_020490F4
 * address:  0x020490F4
 * packet:   pkt_02048F9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   arc_tool_file  0x020A7EE0  data
 *   func_02030734      0x02030734  arm
 *   ARC_TOOL_OpenArchive      0x02048DDC  arm
 *   ARC_TOOL_ReadHandleHeader      0x0204919C  arm
 *
 * Constructor: take a 0x50-byte record from the debug allocator, tie it to
 * the caller's object through ARC_TOOL_OpenArchive, run the one-time init at
 * ARC_TOOL_ReadHandleHeader and hand the record back.  The allocator's __FILE__/__LINE__
 * pair is the usual ABS32 into the packed string area plus a pooled 0x209,
 * which is not an ARM rotated immediate.
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern const char arc_tool_file[];

typedef unsigned char  u8;
struct ArcFile;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void ARC_TOOL_OpenArchive(struct ArcFile *arc, u32 id);
extern void ARC_TOOL_ReadHandleHeader(u8 *p);

void *sub_020490F4(u32 id, u32 heap)
{
    void *rec = func_02030734(heap, 0x50, 0, arc_tool_file, 0x209);

    ARC_TOOL_OpenArchive(rec, id);
    ARC_TOOL_ReadHandleHeader(rec);
    return rec;
}
