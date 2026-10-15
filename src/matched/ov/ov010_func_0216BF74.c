/*
 * function: FIELD_G3D_MAP_StoreBeaconTrainerKey
 * address: 0x0216BF74
 * packet: pkt_ov010_0216BF74
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02008530 0x02008530 thumb
 *   BEACON_SetHashedId 0x0200C38C thumb
 *   g_BeaconTrainerKeys 0x02172508 data a4
 */
typedef unsigned int u32;
typedef signed int     s32;
struct Blk34;
struct Sub0200852CObj;
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void BEACON_SetHashedId(struct Blk34 *p, s32 i, u32 v);
extern const u32 g_BeaconTrainerKeys[];
void FIELD_G3D_MAP_StoreBeaconTrainerKey(void *a, int i, void *b) {
    if(i<8) BEACON_SetHashedId(a,i,func_02008530(b)^*(const u32 *)((u32)g_BeaconTrainerKeys+(u32)i*4));
}
