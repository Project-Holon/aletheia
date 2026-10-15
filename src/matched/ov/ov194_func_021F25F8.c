/*
 * function: NAMEIN_GRAPHIC_LoadGrid
 * address:  0x021F25F8
 * packet:   pkt_021F25F8
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   NAMEIN_GRAPHIC_GetWord 0x021F4D94 thumb
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 NAMEIN_GRAPHIC_GetWord(const u8 *p, u32 i);

void NAMEIN_GRAPHIC_LoadGrid(int *a, int b, int c)
{
    *a = NAMEIN_GRAPHIC_GetWord((const u8 *)c, b);
}
