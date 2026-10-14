/*
 * function: UNION_ONESELF_IsPlayerAtReceptionSpot
 * address:  0x0217F7E4
 * packet:   pkt_ov019_0217F7E4
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   GAME_DATA_GetPlayerDirection  0x02012AD0  thumb
 *   d_02180718     0x02180718  data   ov019 a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct P16 { short x; short z; };
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct Rec44;
extern void *FIELDMAP_GetGameSystem(void *p);
struct Ctx;
extern u8 *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *a, struct VecFx32 *v);
extern u16 GAME_DATA_GetPlayerDirection(const struct Rec44 *p);
extern struct P16 d_02180718[];

int UNION_ONESELF_IsPlayerAtReceptionSpot(u32 arg)
{
    int v[3];
    u32 r4;
    void *h5;
    u32 i;
    int x, z;

    h5 = FIELDMAP_GetFieldPlayer((void *)arg);
    r4 = (u32)GAMESYSTEM_GetMyPlayerWork((const struct Ctx *)FIELDMAP_GetGameSystem((void *)arg));
    FIELD_PLAYER_GetPos(h5, (struct VecFx32 *)v);
    v[0] = (v[0] >> 4) / 4096;
    v[2] = (v[2] >> 4) / 4096;
    GAME_DATA_GetPlayerDirection((const struct Rec44 *)r4);
    x = v[0];
    z = v[2];
    for (i = 0; i < 1; i++) {
        if (x == d_02180718[i].x && z == d_02180718[i].z) {
            return 1;
        }
    }
    return 0;
}
