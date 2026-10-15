/*
 * unit:     no
 * address:  0x020213AC
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: FILE_UTIL_GetItemId
 *
 * symbols:
 *   g_0209E8EC     0x0209E8EC  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_GetItemId.c  *       --func FILE_UTIL_GetItemId --addr 0x020213AC --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u16 g_0209E8EC[];

u16 FILE_UTIL_GetItemId(u32 i)
{
    if (i >= 0xC) {
        return 0;
    }
    return g_0209E8EC[i];
}
