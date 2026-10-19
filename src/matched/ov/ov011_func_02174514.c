/*
 * function: INTRUDE_COMM_RecvSupportMode
 * address:  0x02174514
 * packet:   pkt_ov011_02174514
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-05 (D8 lane19): re-verified, MATCH; only unresolved relocations are arm9 leaves 0x0202E7E0 and 0x0202E7C4 (no witness outside range). Needs labels seeded. Source is byte-correct; no C change possible.
 *
 * Blocked: MATCH*, two unlabelled arm9 leaves have no witness outside the range (the integrator's):
 *   0x0202E7E0 thumb `int f(int *p) { return *p; }` (ldr r0,[r0]; bx lr)
 *   0x0202E7C4 thumb leaf, ldm/stm struct copy of 0x18 bytes (words at 0202E7C4..0202E7DC)
 * Everything else in the file compiles byte-correct (88 of 90 B listed, tail is pad).
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GAME_DATA_GetPmsWork  0x02012F20  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   FIELD_STATUS_GetSeasonDispFlag  0x02014484  thumb
 *   COMM_PLAYER_SUPPORT_GetMode  0x0202E7E0  thumb
 *   GAME_DATA_GetMyStatusPlayer  0x02012950  thumb
 *   COMM_PLAYER_SUPPORT_SetModeAndCurrent  0x0202E7C4  thumb
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Rec44;
struct Sub02014444Obj;
struct Sub24;
u32 GAME_COMM_GetGameData(void *obj);
int GAME_DATA_GetPmsWork(int a);
void *GAME_DATA_GetMoveModelSys(const struct BigObj *p);
u8 FIELD_STATUS_GetSeasonDispFlag(struct Sub02014444Obj *o);
int COMM_PLAYER_SUPPORT_GetMode(int a);
struct Rec44 *GAME_DATA_GetMyStatusPlayer(struct Sub24 *p, u32 i);
void COMM_PLAYER_SUPPORT_SetModeAndCurrent(int a, int b, int c);

void INTRUDE_COMM_RecvSupportMode(int a, int b, int *c, char *d)
{
    int p;
    int q;
    int t;

    p = GAME_COMM_GetGameData((void *)(((int *)d)[1]));
    q = GAME_DATA_GetPmsWork(p);
    if ((unsigned char)d[0x8fb] & (1 << a)) {
        if (FIELD_STATUS_GetSeasonDispFlag(GAME_DATA_GetMoveModelSys((const struct BigObj *)p)) == 1) {
            t = COMM_PLAYER_SUPPORT_GetMode(q);
            if (t == 0 || t == 3) {
                COMM_PLAYER_SUPPORT_SetModeAndCurrent(q, *c, (int)GAME_DATA_GetMyStatusPlayer((struct Sub24 *)p, a));
            }
        }
    }
}
