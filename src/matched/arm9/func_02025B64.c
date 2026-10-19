/*
 * function: NATION_AREA_GetAreaCount
 * address:  0x02025B64
 * packet:   pkt_02025B64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  0209FA3D literal
 *
 * symbols:
 *   g_0209FA34  0x0209FA34  data
 *   g_0209FA3D  0x0209FA3D  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern u8 g_0209FA34[];
extern u8 g_0209FA3D[];

u8 NATION_AREA_GetAreaCount(u32 v)
{
    u32 i;

    for (i = 0; i < 0x13; i++) {
        if (v == g_0209FA34[i * 0xc]) {
            return g_0209FA3D[i * 0xc];
        }
    }
    return 0;
}
