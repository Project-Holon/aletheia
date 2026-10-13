/*
 * function: FIELD_GROUND_ANIME_AnmSetInit
 * address:  0x021A7420
 * packet:   pkt_ov021_021A7420
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *   NNS_G3dGetAnmByIdx  0x0206E9A4  arm
 *   func_02030734  0x02030734  arm
 *   FIELD_GROUND_ANIME_AnmEntryInit  0x021A7508  thumb  ov021
 *   _FieldGroundAnimeFileName     0x021DDF7C  data  ov021  a1
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char _FieldGroundAnimeFileName;
extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
extern u8 *NNS_G3dGetAnmByIdx(u8 *p, u32 idx);
extern void *func_02030734(u32 heap, u32 size, int one, const char *file, u16 line);
extern void FIELD_GROUND_ANIME_AnmEntryInit(u32 a, u32 b, u32 c);

void FIELD_GROUND_ANIME_AnmSetInit(u32 *s, u32 a, u32 b, u32 n, u32 heap)
{
    u32 i;
    u32 h;
    i = 0;
    s[2] = ARC_UTIL_LoadMember(a, b, 0, heap);
    h = (u32)NNS_G3dGetAnmByIdx((u8 *)s[2], 0);
    s[0] = (u32)func_02030734(heap, n * 12, 1, &_FieldGroundAnimeFileName, 0x196);
    s[1] = n;
    for (i = 0; i < s[1]; i++)
        FIELD_GROUND_ANIME_AnmEntryInit(s[0] + i * 12, h, heap);
}
