/*
 * function: FIELDMAP_CTRL_HYBRID_SwitchToGrid
 * address:  0x021A712C
 * packet:   pkt_ov021_021A712C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_DRAW_GetBlactAnime  0x0219F058  thumb  ov021
 *   FIELD_PLAYER_UpdateNogrid  0x021A3674  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FIELDMAP_CTRL_HYBRID_SetMode  0x021A7258  thumb  ov021
 *   FIELD_PLAYER_CheckMoveRestrictFlag  0x021A35BC  thumb  ov021
 *   FIELD_PLAYER_MoveGrid  0x021A35F0  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern void FLDMMDL_DRAW_GetBlactAnime(u32 a, u16 *o1, u16 *o2);
extern void FIELD_PLAYER_UpdateNogrid(u8 *p, u32 b, u32 c);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void FIELDMAP_CTRL_HYBRID_SetMode(u32 a, u32 *b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern int FIELD_PLAYER_CheckMoveRestrictFlag(int a);
extern int FIELD_PLAYER_MoveGrid(u32 a, u32 b, u32 c, u32 d);

void FIELDMAP_CTRL_HYBRID_SwitchToGrid(u32 a, u32 *b, u32 c, u32 d, u32 e, u32 f, u32 g)
{
    u16 v[2];
    void *h;
    u32 fl;
    fl = 0;
    h = FIELD_PLAYER_GetMmdl((unsigned char *)b[1]);
    FLDMMDL_DRAW_GetBlactAnime((u32)h, &v[0], &v[1]);
    FIELD_PLAYER_UpdateNogrid((u8 *)b[1], 0, 0);
    if (d == 0)
        c = FLDMMDL_GetDirDisp(h);
    FIELDMAP_CTRL_HYBRID_SetMode(a, b, 0, e, c, v[0], v[1]);
    if (FIELD_PLAYER_CheckMoveRestrictFlag(b[1]) == 1)
        fl |= 1;
    FIELD_PLAYER_MoveGrid(b[1], f, g, fl);
}
