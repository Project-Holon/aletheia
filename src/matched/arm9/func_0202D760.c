/*
 * unit:     no
 * function: POKEGRA_LoadCharData
 * address:  0x0202D760
 * packet:   pkt_0202D6F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds a sprite/resource request: POKEGRA_GetCgrArcIndex turns the mon
 * descriptor (species/form/gender plus the three stack words) into a
 * resource id, which ARC_UTIL_LoadScreenDataFromArchive instantiates with the caller's
 * out-slot `a0` as its a3 payload.  When the species word a1 is the
 * sentinel 0x147 the freshly filled *a0 is additionally run through the
 * POKEGRA_ConvertCharTo2D / POKEGRA_DrawSpindaSpots / POKEGRA_ConvertCharTo1D triple, which is why
 * `*a0` is re-read before each of them (POKEGRA_DrawSpindaSpots may store through
 * it, so the load cannot be cached).  This answers the open question in
 * docs/notes/POKEGRA_RegisterCgr.c.txt: a0 is a genuine out-parameter, written
 * by ARC_UTIL_LoadScreenDataFromArchive via its a3, not read-only.
 *
 * Blocked at MATCH: every concrete byte is identical.  2026-09-21, unblock
 * lane: ONE OF THE TWO BLOCKING SITES IS NOW CLEARED.  POKEGRA_ConvertCharTo1D was
 * filed EXACT (src/matched/POKEGRA_ConvertCharTo1D.c, shard arm9/pkt_0202D2EC.json),
 * so the +0x58 THM_CALL resolves `matched`.  Only +0x50, the call to
 * POKEGRA_DrawSpindaSpots, is still wildcarded: this function is that address's only
 * caller image-wide, so no evidence class (label/matched) can attest it and
 * nothing but an EXACT at 0x0202D3D0 will promote this file.  That function
 * is a documented near miss, now at 29 concrete mismatches (down from 41)
 * and stuck on one register-assignment decision -- see
 * docs/notes/POKEGRA_DrawSpindaSpots.c.txt, which records the lever that halved it
 * and the twelve spellings that do not move it further.
 *
 * symbols:
 *   POKEGRA_GetArcID   0x0202D060  thumb
 *   POKEGRA_GetCgrArcIndex   0x0202D064  thumb
 *   POKEGRA_ConvertCharTo2D   0x0202D214  thumb
 *   POKEGRA_ConvertCharTo1D   0x0202D2EC  thumb
 *   POKEGRA_DrawSpindaSpots   0x0202D3D0  thumb
 *   ARC_UTIL_LoadScreenDataFromArchive   0x02049E34  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
extern int POKEGRA_GetArcID(void);
extern s32 POKEGRA_GetCgrArcIndex(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern void *ARC_UTIL_LoadScreenDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
struct Obj;
extern void POKEGRA_ConvertCharTo2D(void *p, u32 v);
extern void POKEGRA_DrawSpindaSpots(struct Obj *obj, u32 a1);
extern void POKEGRA_ConvertCharTo1D(u32 *obj, u32 heap);

void *POKEGRA_LoadCharData(u32 *out, u32 a1, u32 a2, u32 a3,
                    u32 s0, u32 s1, u32 s2, u32 s3, volatile u16 s4)
{
    u32 id;
    void *res;

    id = POKEGRA_GetCgrArcIndex(POKEGRA_GetArcID(), a1, a2, a3, s0, s1, s2);
    res = ARC_UTIL_LoadScreenDataFromArchive(POKEGRA_GetArcID(), id, 1, (u32)out, s4);
    if (a1 == 0x147) {
        POKEGRA_ConvertCharTo2D((void *)(*out), s4);
        POKEGRA_DrawSpindaSpots((struct Obj *)(*out), s3);
        POKEGRA_ConvertCharTo1D((u32 *)(*out), s4);
    }
    return res;
}
