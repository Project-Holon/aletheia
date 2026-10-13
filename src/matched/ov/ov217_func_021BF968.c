/*
 * function: func_021BF968
 * address: 0x021BF968
 * packet: pkt_ov217_021BF968
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing 00 00 at 021BF9CA is two-byte alignment padding.
 * prototype: 02012FCC legacy trailing arguments omitted: full 12-byte body only reads r0, then returns its field at 0x6ac; no forwarding.
 * symbols:
 *   func_021BF740 0x021BF740 thumb ov217
 *   GAME_DATA_GetPlayTime 0x02012FCC thumb
 *   func_0200864C 0x0200864C thumb
 * prototype: full 02012FCC body only reads r0, does not forward r1-r3; legacy trailing inputs omitted.
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern u32 func_021BF740(u8 *);
extern int GAME_DATA_GetPlayTime(int);
typedef unsigned short u16;
struct PlayTime;
extern u16 func_0200864C(const struct PlayTime *p);
u32 func_021BF968(u8 *p)
{
    u32 v = func_0200864C((const struct PlayTime *)GAME_DATA_GetPlayTime(func_021BF740(p)));
    if (v < 10) return 135;
    if (v < 20) return 136;
    if (v < 30) return 137;
    if (v < 40) return 138;
    if (v < 50) return 139;
    if (v < 60) return 140;
    if (v < 70) return 141;
    if (v < 80) return 142;
    if (v < 90) return 143;
    if (v < 100) return 144;
    return 145;
}
