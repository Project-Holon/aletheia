/*
 * function: FIELD_PLAYER_GetMoveOffsetInDir
 * address:  0x021A3484
 * packet:   pkt_ov021_021A3484
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 *   VEC_Normalize  0x0207CCA4  arm
 *   FLDMMDL_RAIL_GetDrawOffsetByDir  0x0219E784  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void *FIELD_PLAYER_CORE_GetMmdl(unsigned char *p);
extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern int FLDMMDL_MOVE_GetDirAddGridX(int a);
extern int FLDMMDL_MOVE_GetDirAddGridZ(int a);
extern void VEC_Normalize();
extern void FLDMMDL_RAIL_GetDrawOffsetByDir(u32 o, u32 idx, s16 *v);

void FIELD_PLAYER_GetMoveOffsetInDir(unsigned char **a, int b, s32 *c)
{
    s16 v[4];
    s32 t1;
    s32 t2;
    s32 t3;
    void *h = FIELD_PLAYER_CORE_GetMmdl(a[1]);

    if (FIELDMAP_GetMoveKind(a[0]) == 0) {
        s32 t;

        c[1] = 0;
        c[0] = FLDMMDL_MOVE_GetDirAddGridX(b);
        t = FLDMMDL_MOVE_GetDirAddGridZ(b);
        c[0] = c[0] << 16;
        c[2] = t << 16;
        VEC_Normalize(c, c);
        return;
    }
    FLDMMDL_RAIL_GetDrawOffsetByDir((u32)h, b, v);
    t3 = v[2];
    t2 = v[1];
    t1 = v[0];
    c[0] = t1;
    c[1] = t2;
    c[2] = t3;
}
