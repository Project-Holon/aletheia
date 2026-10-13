/*
 * function: WIFICLUBACTOR_LoadPalette
 * address:  0x021B9E0C
 * packet:   pkt_ov099_021B9E0C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049B40  0x02049B40  arm
 *   func_02040EBC  0x02040EBC  arm
 *   ARC_UTIL_UploadBgCharFromArchive  0x02049624  arm
 */
typedef unsigned int u32;
typedef unsigned short u16;

extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02040EBC(u32 a, u32 b);
extern u32 ARC_UTIL_UploadBgCharFromArchive(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);

void WIFICLUBACTOR_LoadPalette(void *a, u32 b, u32 c, u32 d)
{
    u32 z = 0;
    func_02049B40(d, 7, 0, 0, 0x100, b);
    func_02040EBC(0, 0);
    ARC_UTIL_UploadBgCharFromArchive((void *)d, (void *)0x10, 0, 0, z, z, b);
}
