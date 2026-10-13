/*
 * function: FIELD_PALACE_SYS_SetupPalTable
 * address:  0x021D33FC
 * packet:   pkt_ov021_021D33FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-02: EXACT.  The prologue and final call-setup residue of the
 * earlier draft was parameter width: a1 and a2 are u16 (a1 is the u16 key
 * FIELD_PALACE_SYS_IsZoneFlagSet compares, a2 the u16 heap id of FIELD_PALACE_SYS_LoadPalTable), which pins
 * their home stores to the front of the prologue
 * (docs/idioms/a-narrow-parameter-pins-its-home-store-to-the-front-of-the-prologue.md).
 *
 * Recursive MATCH unblocker attempt: non-SDK dep of the matched FIELD_PALACE_SYS_Create
 * (its +0010 branch target in the field_palace_sys.c tree).  Every relocation
 * resolves (0x0215850C / 0x02158468 as EXACT ov010 `matched`, 0x021D3478 as
 * `sole-ref`), the size is exact, and the logic is recovered.  The residue
 * that remained was scheduling, closed by the u16 parameters above.
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   ZONEDATA_IsZoneGroup118To13C  0x02013D74  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FIELD_PALACE_SYS_IsZoneFlagSet  0x021D3554  thumb  ov021
 *   INTRUDE_COMM_GetAreaOwnerVersionClass  0x0215850C  thumb  ov010
 *   INTRUDE_COMM_GetAreaSlotFlag  0x02158468  thumb  ov010
 *   FIELD_PALACE_SYS_LoadPalTable  0x021D3478  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07605.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int ZONEDATA_IsZoneGroup118To13C(u32 key);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int FIELD_PALACE_SYS_IsZoneFlagSet(void *, int);
extern int INTRUDE_COMM_GetAreaOwnerVersionClass(int a0, int a1);
extern int INTRUDE_COMM_GetAreaSlotFlag(int);
extern void FIELD_PALACE_SYS_LoadPalTable(u8 *a, u32 id, int c, int d, u16 heap);

void FIELD_PALACE_SYS_SetupPalTable(u8 *a0, u16 a1, u16 a2)
{
    int r6;
    int r7;
    void *r4;
    int t;
    int s;

    r6 = (int)GAMESYSTEM_GetGameComm(((struct Obj07605 *)a0)->f0);
    if (ZONEDATA_IsZoneGroup118To13C(a1) != 1)
        return;
    if (r6 == 0)
        return;
    r4 = GAMESYSTEM_GetGameData(((struct Obj07605 *)a0)->f0);
    r7 = FIELD_PALACE_SYS_IsZoneFlagSet(r4, a1);
    t = INTRUDE_COMM_GetAreaOwnerVersionClass(r6, (int)r4);
    s = 0xffff;
    if (t == 2) {
        if (r7 == 1)
            s = 1;
        else
            s = 0;
    } else if (t == 1) {
        if (r7 == 1)
            s = 3;
        else
            s = 2;
    }
    if (s == 0xffff)
        return;
    FIELD_PALACE_SYS_LoadPalTable(a0, s, a1, INTRUDE_COMM_GetAreaSlotFlag(r6), a2);
}
