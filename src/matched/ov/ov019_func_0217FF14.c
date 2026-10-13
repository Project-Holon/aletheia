/*
 * function: COLOSSEUM_IsOnCounterPos
 * address:  0x0217FF14
 * packet:   pkt_ov019_0217FF14
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   d_021807AC     0x021807AC  data  ov019  a4
 *   d_021807C0     0x021807C0  data  ov019  a4
 */

typedef short s16;

typedef unsigned short u16;
typedef unsigned char  u8;
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *v);
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern s16 d_021807AC[][2];
extern s16 d_021807C0[][2];

int COLOSSEUM_IsOnCounterPos(void *a)
{
    int v[3];
    s16 (*t)[2];
    int i;
    int n;

    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(a), (struct VecFx32 *)v);
    v[0] >>= 12;
    v[2] >>= 12;
    if (FIELDMAP_GetZoneId(a) == 0x96) {
        t = d_021807AC;
        n = 5;
    } else {
        t = d_021807C0;
        n = 5;
    }
    for (i = 0; i < n; i++) {
        if (v[0] == t[i][0] && v[2] == t[i][1])
            return 1;
    }
    return 0;
}
