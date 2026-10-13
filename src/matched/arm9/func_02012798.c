/*
 * function: GAME_DATA_GetPlayerWork
 * address:  0x02012798
 * packet:   pkt_02012798
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 */

typedef unsigned char u8;
typedef struct S { u8 pad00[4]; int f04; } S;

u8 *GAME_DATA_GetPlayerWork(u8 *p, int i)
{
    return p + 4 + i * 0x44;
}
