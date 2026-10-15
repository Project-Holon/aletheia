/*
 * unit:     yes
 * address:  0x0201F554
 * packet:   pkt_0201F020
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BMP_MENUWORK_LoadChar, BMP_MENUWORK_LoadPltt
 *
 * Two font-drawing wrappers, each turning a small id into a glyph-table index
 * through one of the two byte tables just before them and handing it to a
 * seven- and a six-argument SDK-style entry point.  The two table lookups are
 * BMP_MENUWORK_GetCharFileId and BMP_MENUWORK_GetPlttFileId, which are parked in
 * src/pending/sub_0201F53C.c because their tables have no outside witness;
 * the calls to them are ordinary `label` sites here, since BMP_MENUWORK_GetCharFileId is
 * also called from 0x0201F5EA outside this range and BMP_MENUWORK_GetPlttFileId from ten
 * overlays.
 *
 * BMP_MENUWORK_LoadPltt hoists the lookup above the `if`, so the source binds it to a
 * local once rather than calling it in both arms; written in both arms the
 * compiler emits the call twice.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201F554.c  *       --addr 0x0201F554 --thumb
 *
 * symbols:
 *   ARC_UTIL_UploadBgCharFromArchive  0x02049624  arm
 *   BMP_MENUWORK_GetCharFileId  0x0201F53C  thumb
 *   BMP_MENUWORK_GetPlttFileId  0x0201F548  thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u8 BMP_MENUWORK_GetCharFileId(int i);
extern u8 BMP_MENUWORK_GetPlttFileId(int i);
extern void ARC_UTIL_UploadBgCharFromArchive(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);

void BMP_MENUWORK_LoadChar(u32 a, u32 b, u32 c, u32 d)
{
    ARC_UTIL_UploadBgCharFromArchive(5, BMP_MENUWORK_GetCharFileId(c), a, b, 0, 0, d);
}

void BMP_MENUWORK_LoadPltt(u32 a, u32 b, u32 c, u32 d)
{
    u32 t = BMP_MENUWORK_GetPlttFileId(c);

    if (a < 4) {
        func_02049B40(5, t, 0, b * 32, 0x20, d);
    } else {
        func_02049B40(5, t, 4, b * 32, 0x20, d);
    }
}
