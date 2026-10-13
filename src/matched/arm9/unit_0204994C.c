/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: ARC_UTIL_UploadBgPaletteAddFromArchive, ARC_UTIL_UploadBgPaletteAddFromHandle, ARC_UTIL_UploadBgPaletteAddFromHandleExt
 * address:  0x0204994C
 * packet:   pkt_0204994C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 *   ARC_UTIL_UploadBgPalette  0x02049A18  arm
 *
 * Sound / audio event trigger wrappers.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204994C.c \
 *       --addr 0x0204994C --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
extern void *ARC_UTIL_LoadHandleMember(void *a0, u32 a1, u32 a2, u32 a3);
extern u32 ARC_UTIL_UploadBgPalette(void *file, u32 channel, u32 a2, u32 add, u32 size, u32 flag);

u32 ARC_UTIL_UploadBgPaletteAddFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7)
{
    u32 res = ARC_UTIL_LoadMember(a0, a1, a6, a7);
    return ARC_UTIL_UploadBgPalette((void *)res, a2, a3, a4, a5, 0);
}

u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7)
{
    u32 res = (u32)ARC_UTIL_LoadHandleMember(a0, a1, a6, a7);
    return ARC_UTIL_UploadBgPalette((void *)res, a2, a3, a4, a5, 0);
}

u32 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7)
{
    u32 res = (u32)ARC_UTIL_LoadHandleMember(a0, a1, a6, a7);
    return ARC_UTIL_UploadBgPalette((void *)res, a2, a3, a4, a5, 1);
}
