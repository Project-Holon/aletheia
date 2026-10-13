/*
 * function: ENTRANCE_CAMERA_LoadRecord
 * address:  0x021BE148
 * packet:   pkt_021BE148
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with a constant and the argument less 7.
 *
 * symbols:
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);

void ENTRANCE_CAMERA_LoadRecord(u32 a, int b)
{
    ARC_TOOL_ReadMember((void *)a, 0xb3, b - 7);
}
