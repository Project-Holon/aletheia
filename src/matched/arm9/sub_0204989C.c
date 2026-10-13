/*
 * unit:     no
 * function: ARC_UTIL_UploadBgPaletteFromArchive
 * address:  0x0204989C
 * packet:   pkt_0204968C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *   ARC_UTIL_UploadBgPalette  0x02049A18  arm
 *
 * Seven-argument front end: load an archive member with the top allocation
 * bit forced on, exactly as src/matched/ARC_UTIL_RegisterObjCharFromArchive.c does, and forward the
 * buffer to ARC_UTIL_UploadBgPalette with two of its six arguments pinned to zero. The
 * handle is not released here; ARC_UTIL_UploadBgPalette does that itself (see its
 * near-miss note in docs/notes/ARC_UTIL_UploadBgPalette.c.txt, which is where its
 * six-argument shape comes from).
 *
 * The two zeros are one `mov r3, #0` reused for the register argument and
 * the stack argument, so the stack store of a4 has to be emitted between the
 * two: writing the zeros first costs a second materialisation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ARC_UTIL_UploadBgPaletteFromArchive.c \
 *       --func ARC_UTIL_UploadBgPaletteFromArchive --addr 0x0204989C --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
extern u32 ARC_UTIL_UploadBgPalette(void *file, u32 channel, u32 a2, u32 add, u32 size, u32 flag);

void ARC_UTIL_UploadBgPaletteFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags)
{
    ARC_UTIL_UploadBgPalette((void *)ARC_UTIL_LoadMember((u32)a0, (u32)a1, (u32)a5, (u16)((flags & 0x7FFF) | 0x8000)),
                  a2, a3, 0, a4, 0);
}
