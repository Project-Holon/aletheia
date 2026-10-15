/*
 * function: PSEL_SetupListAnime
 * address: 0x021B9854
 * packet: pkt_ov223_021B9854
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   PSEL_CreateRecords 0x021B95B0 thumb ov223
 *   func_020489F4 0x020489F4 arm
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   ICA_ANIME_CreateStream 0x02011510 thumb
 *   PSEL_GRAPHIC_GetCamera 0x021BC52C thumb ov223
 *   ICA_ANIME_SetCameraStatus 0x02011B8C thumb
 *   d_021BC7AC 0x021BC7AC data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 d_021BC7AC[];
extern u16 G3D_UTIL_AddUnit(void *, const void *);
struct G3dSys;
struct Record;
extern struct Record *PSEL_CreateRecords(u32 heap, u32 count);
extern u32 func_020489F4(u8 *a0, int i);
extern u32 func_02048A18(u8 *a0, int i);
extern int G3D_SYSTEM_GetObjectAnimeCount(int *p);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern void *ICA_ANIME_CreateStream(u32 heap, u32 b, u32 c, u32 d);
extern unsigned PSEL_GRAPHIC_GetCamera(u8 *p);
extern void ICA_ANIME_SetCameraStatus(void *, void *);
void PSEL_SetupListAnime(u8 *p)
{
    u16 i;
    u32 n;
    u16 j;
    u8 *rec;
    u32 r;
    void *h;
    *(u16 *)(p + 0x2C) = G3D_UTIL_AddUnit(*(void **)(p + 0x28), d_021BC7AC);
    *(u16 *)(p + 0x3A) = 1;
    *(void **)(p + 0x3C) = PSEL_CreateRecords(*(u16 *)p, *(u16 *)(p + 0x3A));
    r = func_020489F4(*(void **)(p + 0x28), *(u16 *)(p + 0x2C));
    *(u16 *)(p + 0x30) = 0;
    rec = *(u8 **)(p + 0x3C);
    *(u16 *)rec = r;
    *(u32 *)(rec + 0x40) = 1;
    for (i = 0; i < *(u16 *)(p + 0x3A); i++) {
        h = (void *)func_02048A18(*(void **)(p + 0x28), *(u16 *)(*(u8 **)(p + 0x3C) + i * 0x44));
        n = G3D_SYSTEM_GetObjectAnimeCount(h);
        for (j = 0; j < n; j++) {
            G3D_SYSTEM_EnableObjectAnime(h, j);
        }
    }
    *(void **)(p + 0x40) = ICA_ANIME_CreateStream(*(u16 *)p, 0xCD, 0x21, 0xA);
    ICA_ANIME_SetCameraStatus((void *)PSEL_GRAPHIC_GetCamera(*(u8 **)(p + 0x14)), *(void **)(p + 0x40));
    *(u32 *)(p + 0x50) = 0;
}
