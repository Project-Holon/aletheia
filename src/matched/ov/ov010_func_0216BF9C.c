/*
 * function: FIELD_G3D_MAP_CheckBeaconTrainerKey
 * address: 0x0216BF9C
 * packet: pkt_ov010_0216BF9C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: named second call-result local preserves the original comparison registers.
 * symbols:
 *   func_02008530 0x02008530 thumb
 *   MISC_GetHashedId 0x0200C39C thumb
 *   g_BeaconTrainerKeys 0x02172508 data a4
 */
typedef unsigned int u32;
typedef signed int     s32;
struct Blk34;
struct Sub0200852CObj;
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u32 MISC_GetHashedId(struct Blk34 *p, s32 i);
extern const u32 g_BeaconTrainerKeys[];
int FIELD_G3D_MAP_CheckBeaconTrainerKey(void *a, int i, void *b) {
    u32 v; u32 x;
    if(i>=8) return 0;
    v=func_02008530(b);
    x=MISC_GetHashedId(a,i);
    if((x^v)==*(const u32 *)((u32)g_BeaconTrainerKeys+(u32)i*4)) return 1;
    return 0;
}
