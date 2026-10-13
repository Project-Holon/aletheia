/*
 * function: MAP_REPLACE_LoadRecord
 * address:  0x02159DCC
 * packet:   pkt_ov010_02159DCC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reads record n (16 bytes) from the archive at p+4 into p+0x1a through
 * ARC_TOOL_ReadHandleMemberRange, then returns the halfword read.
 *
 * symbols:
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct ArcFile;
extern void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);

u32 MAP_REPLACE_LoadRecord(u8 *p, int n)
{
    ARC_TOOL_ReadHandleMemberRange(*(struct ArcFile **)(p + 4), 0, n << 4, 0x10, p + 0x1a);
    return *(u16 *)(p + 0x1a);
}
