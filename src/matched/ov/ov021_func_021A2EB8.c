/*
 * function: FIELD_PLAYER_SaveToPlayerWork
 * address:  0x021A2EB8
 * packet:   pkt_ov021_021A2EB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: relocation evidence, GAME_DATA_SetPlayerDirectionType (0x02012AD4, arm9 thumb leaf,
 * the integrator's) has no witness outside this range. Leaf C, verified EXACT
 * with match.py one --thumb --region arm9 (symbols: data_0209DFA8
 * 0x0209DFA8 data a2):
 *   extern const u16 data_0209DFA8[];
 *   void GAME_DATA_SetPlayerDirectionType(u8 *p, int i) { *(u16 *)(p + 0x18) = data_0209DFA8[i]; }
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetPlayerWork  0x021A3994  thumb
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   GAME_DATA_SetPlayerPosition  0x02012A90  thumb
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   GAME_DATA_SetPlayerDirectionType  0x02012AD4  thumb
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb
 *   GAME_DATA_SetPlayerMoveForm  0x02012ABC  thumb
 *   FLDMMDL_RAIL_GetNextLocation  0x0219E2F4  thumb
 *   GAME_DATA_SetPlayerRailLocation  0x02012AA4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct H4;
struct Rec44;
struct Vec12;
extern u32 FIELD_PLAYER_CORE_GetPlayerWork(u8 *p);
extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern void GAME_DATA_SetPlayerPosition(struct Rec44 *p, const struct Vec12 *src);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void GAME_DATA_SetPlayerDirectionType(u8 *p, int i);
extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern void GAME_DATA_SetPlayerMoveForm(struct Rec44 *p, u8 v);
extern void FLDMMDL_RAIL_GetNextLocation(void *o, void *out);
extern void GAME_DATA_SetPlayerRailLocation(struct Rec44 *p, const struct H4 *src);

void FIELD_PLAYER_SaveToPlayerWork(u32 *a)
{
    u8 b[12];
    u8 c[8];
    u32 d = FIELD_PLAYER_CORE_GetPlayerWork((u8 *)a[1]);
    void *e = FIELD_PLAYER_CORE_GetMmdl((u8 *)a[1]);

    FLDMMDL_GetPos(e, (struct VecFx32 *)b);
    GAME_DATA_SetPlayerPosition((struct Rec44 *)d, (const struct Vec12 *)b);
    GAME_DATA_SetPlayerDirectionType((u8 *)d, FLDMMDL_GetDirDisp(e));
    if (FIELDMAP_GetMoveKind((u8 *)a[0]) == 0) {
        GAME_DATA_SetPlayerMoveForm((struct Rec44 *)d, 0);
        return;
    }
    FLDMMDL_RAIL_GetNextLocation(e, c);
    GAME_DATA_SetPlayerRailLocation((struct Rec44 *)d, (const struct H4 *)c);
    GAME_DATA_SetPlayerMoveForm((struct Rec44 *)d, 1);
}
