/*
 * function: FIELD_PLAYER_GRID_EVENT_StartBoulderDrop
 * address:  0x021C0DDC
 * packet:   pkt_ov021_021C0DDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GRID_EVENT_GetFrontTileAttr  0x021C19B4  thumb  ov021
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_IsMovedPosObjCode  0x0216E5FC  thumb  ov010
 *   FIELD_PLAYER_GRID_GetCore  0x021A5728  thumb  ov021
 *   FIELD_PLAYER_CORE_GetFieldMap  0x021A395C  thumb  ov021
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_PLAYER_GRID_EVENT_GetHoleCoverage  0x021C0D08  thumb  ov021
 *   FLDMMDL_MOVE_HitCheckMoveDir  0x021639C0  thumb  ov010
 *   FIELD_PLAYER_GRID_EVENT_CreateBoulderDropEvent  0x021C0E4C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_PLAYER_GRID_EVENT_GetFrontTileAttr(u8 *a, u32 b);
extern u16 FLDMMDL_GetObjCode(void *p);
extern int FLDMMDL_IsMovedPosObjCode(u16 id);
extern u32 FIELD_PLAYER_GRID_GetCore(u8 *p);
extern u32 FIELD_PLAYER_CORE_GetFieldMap(u8 *p);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
extern int FIELD_PLAYER_GRID_EVENT_GetHoleCoverage(void *obj, u32 dir, void *map);
extern u32 FLDMMDL_MOVE_HitCheckMoveDir(u32 a, u32 b);
extern void *FIELD_PLAYER_GRID_EVENT_CreateBoulderDropEvent(u32 a, u32 b, u32 c, u32 d);

int FIELD_PLAYER_GRID_EVENT_StartBoulderDrop(u8 *a, u32 b, int c)
{
    u32 r6;
    u32 r4;
    u32 f;

    if (c == 1) {
        r6 = FIELD_PLAYER_GRID_EVENT_GetFrontTileAttr(a, b);
        if (r6 != 0) {
            if (FLDMMDL_IsMovedPosObjCode(FLDMMDL_GetObjCode((void *)r6)) == 1) {
                r4 = FIELD_PLAYER_GRID_EVENT_GetHoleCoverage((void *)r6, b, (void *)FIELDMAP_GetG3dMapper((u8 *)FIELD_PLAYER_CORE_GetFieldMap((u8 *)FIELD_PLAYER_GRID_GetCore((u8 *)a))));
                f = FLDMMDL_MOVE_HitCheckMoveDir(r6, b);
                f &= ~1;
                if ((f & 2) && r4 - 2 <= 1)
                    f &= ~2;
                if (f == 0) {
                    int k = 0;
                    if (r4 == 3)
                        k = 1;
                    return (int)FIELD_PLAYER_GRID_EVENT_CreateBoulderDropEvent((u32)a, b, r6, k);
                }
            }
        }
    }
    return 0;
}
