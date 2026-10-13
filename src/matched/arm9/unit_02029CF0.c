/*
 * unit:     yes
 * address:  0x02029CF0
 * packet:   pkt_020295D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: FIELD_SOUND_SYSTEM_PostZoneBgmChange
 *
 * The last function of pkt_020295D8, and not a task at all: it resolves a
 * sequence id for the request and issues one command 5 for it, with the fifth
 * argument 60 or 0 depending on a mode query.  FIELD_SOUND_SYSTEM_FindZoneBgmOverride answers 0xFFFFFFFF
 * when it has no id of its own and FIELD_SOUND_SYSTEM_GetZoneBgm is the fallback.
 *
 * The mode test's two arms leave `movs r3, #0x3c` duplicated and cross-jump
 * everything after it, which is what says both the fourth and the fifth
 * argument are locals assigned in each arm, and that the fourth is assigned
 * the same 60 in both.  Passing the literal 60 at a single call site after the
 * `if` hoists that `movs` out of the arms; writing the whole call in each arm
 * duplicates the call as well
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * VERSION SENSITIVITY: 60 is a frame count, not a content id.
 *
 * symbols:
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   FIELD_SOUND_SYSTEM_PostRequest  0x020289F8  thumb
 *   FIELD_SOUND_SYSTEM_GetPlayerObjectCode  0x02029E58  thumb
 *   FIELD_SOUND_SYSTEM_GetZoneBgm  0x02029E64  thumb
 *   FIELD_SOUND_SYSTEM_FindZoneBgmOverride  0x02029E74  thumb
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029CF0.c \
 *       --addr 0x02029CF0 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef unsigned char  u8;
struct BigObj;
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern u32   FIELD_SOUND_SYSTEM_FindZoneBgmOverride(void *a, void *b);
extern u32 FIELD_SOUND_SYSTEM_GetZoneBgm(void *unused, u32 id, u32 which);
extern int FIELD_SOUND_SYSTEM_GetPlayerObjectCode(void *a0);
struct Sys;
extern void FIELD_SOUND_SYSTEM_PostRequest(struct Sys *s, u32 a, u32 b, u16 c, u16 d);

void FIELD_SOUND_SYSTEM_PostZoneBgmChange(void *sys, void *a, void *b)
{
    void *pri = (void *)GAME_DATA_GetSeason(a);
    u32 id = FIELD_SOUND_SYSTEM_FindZoneBgmOverride(a, b);
    u16 c;
    u16 v;

    if (id == 0xFFFFFFFF) {
        id = FIELD_SOUND_SYSTEM_GetZoneBgm(a, (u32)b, (u32)pri);
    }
    if (FIELD_SOUND_SYSTEM_GetPlayerObjectCode(a) == 1) {
        c = 0x3C;
        v = 0x3C;
    } else {
        c = 0x3C;
        v = 0;
    }
    FIELD_SOUND_SYSTEM_PostRequest(sys, 5, id, c, v);
}
