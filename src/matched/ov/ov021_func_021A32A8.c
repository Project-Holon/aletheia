/*
 * function: FIELD_PLAYER_SearchFrontMmdlHeight
 * address:  0x021A32A8
 * packet:   pkt_ov021_021A32A8
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
 *   FLDMMDL_SysSearchGridPosHeight  0x0216DDDC  thumb  ov010
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb
 *   FLDMMDL_RAIL_GetFrontLocation  0x0219E634  thumb
 *   FLDMMDL_RAIL_SearchMmdlByLocation  0x0219E570  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern u32 FIELDMAP_GetMoveKind(u8 *p);
typedef signed int     s32;
extern int FIELD_PLAYER_GetFrontGridPos(u32 a, u32 b, u32 c, u32 d);
extern u8 *FLDMMDL_SysSearchGridPosHeight(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
extern void FLDMMDL_RAIL_GetFrontLocation();
extern u32 FLDMMDL_RAIL_SearchMmdlByLocation(u32 o, u32 k, u32 flag);

void FIELD_PLAYER_SearchFrontMmdlHeight(unsigned char **a, u32 b)
{
    s16 v[8];
    void *h = FIELDMAP_GetMmdlSys(a[0]);

    if (FIELDMAP_GetMoveKind(a[0]) == 0) {
        FIELD_PLAYER_GetFrontGridPos((u32)a, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
        FLDMMDL_SysSearchGridPosHeight((u32)h, v[2], v[0], v[1] << 16, b, 0);
        return;
    }
    FLDMMDL_RAIL_GetFrontLocation(FIELD_PLAYER_CORE_GetMmdl(a[1]), &v[3]);
    FLDMMDL_RAIL_SearchMmdlByLocation((u32)h, (u32)(&v[3]), 0);
}
