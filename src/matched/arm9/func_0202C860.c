/*
 * function: ISS_SWITCH_RefreshSubscreenMode
 * address:  0x0202C860
 * packet:   pkt_0202C860
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     2026-09-23 (wave 15): EXACT with no C change; the ov010 call
 *           at +0x34 now resolves sole-ref/code.  The MATCH text below is history.
 *
 * Blocked at MATCH on the `label`/`matched` classes: all 82 concrete bytes
 * are correct (88-byte extent, the last 6 bytes being the pool word 0xffff),
 * but the PC-relative call at +0x0034 to MOVE_POKEMON_IsAnyEntryActive in ov010 has no
 * witness: 0x0215E6F8 has exactly one branch reference image-wide and it is
 * that call, so no cut frees it, and the address is inside BOTH ov009's and
 * ov010's windows, so the `label` class refuses it even with the ov010 hint
 * on the symbols: line.  The unblock is a `matched` entry at 0x0215E6F8
 * (or any additional caller of it anywhere in the image).
 *
 * The range check must wrap in 32 bits: `(u32)(r - 6) > 1`, `(r - 6) > 1u`
 * and `(unsigned)(r - 6) > 1` all give the original's bare
 * `subs r0, r1, #6; cmp r0, #1; bhi`.  The u16-cast spelling
 * `(u16)(r - 6) > 1` is wrong by two instructions: it re-truncates the
 * difference with `lsls r0, r0, #0x10; lsrs r0, r0, #0x10` first.
 *
 * The first call takes the actor pointer as well as the truncated id,
 * `MOVE_POKEMON_FindEntryByZone(a0, (u16)a1)`: r0 is still r0 at the call and the id is
 * built in r1.  Declaring it as a one-argument call puts the id in r0 and
 * shifts the whole prologue.
 *
 * symbols:
 *   MOVE_POKEMON_FindEntryByZone  0x0215E6A8  thumb ov010
 *   MOVE_POKEMON_IsAnyEntryActive  0x0215E6F8  thumb ov010
 *   GAME_DATA_GetSubscreenMode  0x02012994  thumb
 *   GAME_DATA_SetSubscreenMode  0x020129A0  thumb
 *   ZONEDATA_GetWeatherId  0x02013C10  thumb
 */


typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int MOVE_POKEMON_FindEntryByZone(void *a, int x);
extern int MOVE_POKEMON_IsAnyEntryActive(int a0);
struct BigObj;
extern u8 GAME_DATA_GetSubscreenMode(const struct BigObj *p);
struct BigObj;
extern void GAME_DATA_SetSubscreenMode(struct BigObj *p, u8 v);
extern u32 ZONEDATA_GetWeatherId(u32 id);

void ISS_SWITCH_RefreshSubscreenMode(u8 *a0, int a1)
{
    u32 v;
    u16 r;

    v = MOVE_POKEMON_FindEntryByZone(a0, (u16)a1);
    r = (u16)(u32)GAME_DATA_GetSubscreenMode((const struct BigObj *)a0);
    if (v != 0xffff) {
        GAME_DATA_SetSubscreenMode((struct BigObj *)a0, (u8)v);
        return;
    }
    if ((u32)(r - 6) > 1) {
        return;
    }
    if (MOVE_POKEMON_IsAnyEntryActive((int)a0) != 1) {
        return;
    }
    GAME_DATA_SetSubscreenMode((struct BigObj *)a0, (u8)ZONEDATA_GetWeatherId((u16)a1));
}
