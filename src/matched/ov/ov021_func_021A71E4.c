/*
 * function: FIELDMAP_CTRL_HYBRID_FindRailLocation
 * address:  0x021A71E4
 * packet:   pkt_ov021_021A71E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELD_NOGRID_MAPPER_GetRailMan  0x021BB480  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_RAIL_FindSegmentLocation  0x021B7A84  thumb  ov021
 *   ZONEDATA_DirToRailKey  0x0201441C  thumb
 *   FIELD_RAIL_TryStepLocation  0x021B7CD8  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct V { u32 x, y, z; } V;

extern u32 FIELDMAP_GetNogridMapper(u8 *p);
extern void *FIELD_NOGRID_MAPPER_GetRailMan(void *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *a, struct VecFx32 *b);
extern u32 FIELD_RAIL_FindSegmentLocation(u32 a, V *b, V *c, u16 *d, V *e);
extern u8 ZONEDATA_DirToRailKey(int i);
extern void FIELD_RAIL_TryStepLocation(u32 a, u16 *b, u32 c, u16 *d);

int FIELDMAP_CTRL_HYBRID_FindRailLocation(u32 a, u32 *b, u16 *c, u32 d)
{
    V w;
    V in;
    V q;
    u16 r[8];
    u32 h;
    h = (u32)FIELD_NOGRID_MAPPER_GetRailMan((void *)FIELDMAP_GetNogridMapper((u8 *)a));
    FIELD_PLAYER_GetPos((unsigned char *)b[1], (struct VecFx32 *)&in);
    q.x = in.x;
    q.y = in.y + 0x4000;
    q.z = in.z;
    in.y = in.y - 0x4000;
    if (FIELD_RAIL_FindSegmentLocation(h, &in, &q, &r[4], &w) != 0)
        FIELD_RAIL_TryStepLocation(h, &r[4], ZONEDATA_DirToRailKey(d), r);
    c[0] = r[4];
    c[1] = r[5];
    c[2] = r[6];
    c[3] = r[7];
}
