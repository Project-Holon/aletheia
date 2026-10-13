/*
 * unit:     no
 * function: func_0202C8B8
 * address:  0x0202C8B8
 * packet:   pkt_0202C8B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   ZONEDATA_IsZoneGroup118To13C  0x02013D74  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   INTRUDE_COMM_GetAreaOwnerVersion  0x0215843C  thumb
 *   gTbl_0209FFF4  0x0209FFF4  data
 *
 * blocker: MATCH, evidence class 'literal'. Every concrete byte matches.
 * The two ABS32 pool words holding 0x0209FFF4 / 0x0209FFF6 are both inside
 * this function; grep over asm/ finds no third pool word anywhere in the
 * image, so the data table has no witness outside the compared range and
 * both relocation sites stay wildcarded. Unstuck by any other function that
 * also points at gTbl_0209FFF4, or by a data-symbol table entry.
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int ZONEDATA_IsZoneGroup118To13C(u32 key);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern s32 INTRUDE_COMM_GetAreaOwnerVersion(u32 a);

struct Pair {
    u16 a;
    u16 b;
};

extern struct Pair gTbl_0209FFF4[];

s32 func_0202C8B8(void *a0, u32 a1, u32 a2)
{
    u32 r6;
    u32 r4;
    u32 i;

    r6 = GAME_DATA_GetEventWork((const struct BigObj *)a1);
    r4 = GAMESYSTEM_GetGameComm(a0);
    if (ZONEDATA_IsZoneGroup118To13C((u16)a2) == 0 || r4 == 0) {
        goto done;
    }
    for (i = 0; i < 0x19; i++) {
        if (a2 == gTbl_0209FFF4[i].a) {
            if (ZONEDATA_CheckEventFlag((void *)r6, gTbl_0209FFF4[i].b) == 0) {
                if (INTRUDE_COMM_GetAreaOwnerVersion(r4) == 0x14) return 0xd;
                return 0xe;
            }
            if (INTRUDE_COMM_GetAreaOwnerVersion(r4) == 0x14) return 0xa;
            return 0xb;
        }
    }
done:
    return 0xffff;
}
