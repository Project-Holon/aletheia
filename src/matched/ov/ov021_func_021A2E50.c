/*
 * function: FIELD_PLAYER_Create
 * address:  0x021A2E50
 * packet:   pkt_ov021_021A2E50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   FIELD_PLAYER_CORE_Create  0x021A36E4  thumb  ov021
 *   gFieldPlayerFileName     0x021DDEA8  data  a4
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int gFieldPlayerFileName;

void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);
u32 FIELD_PLAYER_CORE_Create(int a, u32 b, int c, int d, u16 heap);

u32 *FIELD_PLAYER_Create(int a, u32 b, int c, int d, u16 heap)
{
    u32 *o = (u32 *)func_02030734(heap, 0x10, 1, (const char *)&gFieldPlayerFileName, 0x4C);

    o[0] = b;
    o[1] = FIELD_PLAYER_CORE_Create(a, b, c, d, heap);
    return o;
}
