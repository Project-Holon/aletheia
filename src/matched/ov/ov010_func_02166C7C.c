/*
 * function: SYMBOL_MAP_ResolveZoneId
 * address:  0x02166C7C
 * packet:   pkt_ov010_02166C7C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02013E40  0x02013E40  thumb
 *   GAME_DATA_GetSpecialLocation  0x02012894  thumb
 *   g_ZoneRemapTable  0x02171F2C  data  ov010  a4
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct E {
    u32 val;
    u32 key;
};

struct P {
    u16 pad[2];
    u16 f4;
};

extern u32 func_02013E40(u32 a);
extern struct P *GAME_DATA_GetSpecialLocation(void *a);
extern struct E g_ZoneRemapTable[2];

u32 SYMBOL_MAP_ResolveZoneId(void *a, u32 b)
{
    u32 v = func_02013E40(b);
    u32 r;
    int i;
    if (v == 0x1A6)
        return func_02013E40(GAME_DATA_GetSpecialLocation(a)->f4);
    for (i = 0; i < 2; i++) {
        if (g_ZoneRemapTable[i].key == v) {
            r = (u16)*(u32 *)((char *)g_ZoneRemapTable + i * 8);
            goto done;
        }
    }
    r = 0xFFFF;
done:
    if (r != 0xFFFF)
        v = (u16)r;
    return v;
}
