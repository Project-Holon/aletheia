/*
 * function: MOVE_POKEMON_MoveToNeighbor
 * address: 0x0215E740
 * packet: pkt_ov010_0215E740
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: slot c is u16 in the function and both receiving externs,
 * causing its immediate home reload; the selected byte remains u8.
 * symbols:
 *   func_0200D478 0x0200D478 thumb
 *   TIMEZONE_GetNowTimeZone 0x020113D8 thumb
 *   func_02005728 0x02005728 thumb
 *   MOVE_POKEMON_SetEntryLocation 0x0215E7DC thumb ov010
 *   d_021711A8 0x021711A8 data ov010 a2
 *   d_021711C6 0x021711C6 data ov010 a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ent { u16 n; u8 v[4]; };
extern struct Ent d_021711A8[];
extern u16 d_021711C6[];
struct Blk38;
extern u8 func_0200D478(struct Blk38 *p, u32 i);
extern u32 TIMEZONE_GetNowTimeZone(u32 b);
extern u32 func_02005728(u32 n);
extern void MOVE_POKEMON_SetEntryLocation(void *p, u32 i, u8 v, u32 n);
void MOVE_POKEMON_MoveToNeighbor(void *a, u32 b, u16 c, int d)
{
    struct Ent *e;
    int s;
    u8 buf[4];
    u8 w;
    int v;
    int k;
    int i;
    s = func_0200D478(a, c);
    e = &d_021711A8[(u16)TIMEZONE_GetNowTimeZone(b)];
    if (s != 0x10 && func_02005728(100) < 20) {
        MOVE_POKEMON_SetEntryLocation(a, c, 0x10, 0xffff);
        return;
    }
    k = 0;
    for (i = 0; i < e->n; i++) {
        v = e->v[i];
        if (v != s && v != d) {
            buf[k++] = v;
        }
    }
    w = buf[func_02005728(k)];
    MOVE_POKEMON_SetEntryLocation(a, c, w, w > 0x10 ? 0x13f : d_021711C6[w]);
}
