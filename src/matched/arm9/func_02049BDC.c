/*
 * function: ARC_UTIL_UploadPaletteFromHandle
 * address:  0x02049BDC
 * packet:   pkt_02049B90
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 *   ARC_UTIL_UploadPalette  0x02049C28  arm
 *
 * The second half of the pair described in src/matched/ARC_UTIL_UploadPaletteFromArchive.c: same
 * seven-argument shape, reaching ARC_UTIL_LoadHandleMember rather than ARC_UTIL_LoadMember
 * before forwarding into 0x02049C28.
 *
 * Kept as its own file deliberately.  Both halves call 0x02049C28, and
 * 0x02049C28 has five branch references image wide with three of them inside
 * 0x02049C28 itself, so a `tu` span over both wrappers has no witness left
 * for either call and caps at MATCH; as two single-function ranges each is the
 * other's witness and both are EXACT.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *ARC_UTIL_LoadHandleMember(void *a0, u32 a1, u32 a2, u32 a3);
extern void ARC_UTIL_UploadPalette(void *file, u32 kind, u32 offset, u32 dest, u32 size);

void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6)
{
    u32 r = (u32)ARC_UTIL_LoadHandleMember(a0, a1, 0, (u16)((a6 & 0x7fff) | 0x8000));
    ARC_UTIL_UploadPalette((void *)r, a2, a3, a4, a5);
}
