/*
 * function: FIELD_PLAYER_SearchFrontMmdl
 * address:  0x021A3250
 * packet:   pkt_ov021_021A3250
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb
 *   FIELD_PLAYER_GetFrontGridPos  0x021A3460  thumb
 *   FLDMMDL_SysSearchGridPos  0x0216DDC0  thumb  ov010
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb
 *   FLDMMDL_RAIL_GetFrontLocation  0x0219E634  thumb
 *   FLDMMDL_RAIL_SearchMmdlByLocation  0x0219E570  thumb
 * Addresses are Black-image addresses.
 * FLDMMDL_SysSearchGridPos forwards r0-r3 to FLDMMDL_SysSearchGridPosList, so it takes four
 * arguments; the fourth is the literal 0 whose register the compiler also
 * uses as the v[0] index.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern int FIELD_PLAYER_GetFrontGridPos(u32 a, u32 b, u32 c, u32 d);
extern void *FLDMMDL_SysSearchGridPos(u32 a, u32 b, u32 c, u32 d);
extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
extern void FLDMMDL_RAIL_GetFrontLocation();
extern u32 FLDMMDL_RAIL_SearchMmdlByLocation(u32 o, u32 k, u32 flag);

void FIELD_PLAYER_SearchFrontMmdl(u32 *a)
{
    s16 v[8];
    void *h = FIELDMAP_GetMmdlSys((u8 *)a[0]);

    if (FIELDMAP_GetMoveKind((u8 *)a[0]) == 0) {
        FIELD_PLAYER_GetFrontGridPos((u32)a, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
        FLDMMDL_SysSearchGridPos((u32)h, v[2], v[0], 0);
        return;
    }
    FLDMMDL_RAIL_GetFrontLocation(FIELD_PLAYER_CORE_GetMmdl((u8 *)a[1]), &v[3]);
    FLDMMDL_RAIL_SearchMmdlByLocation((u32)h, (u32)(&v[3]), 0);
}
