/*
 * function: FIELD_PLAYER_GRID_EVENT_GetFrontTileAttr
 * address:  0x021C19B4
 * packet:   pkt_ov021_021C19B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GRID_GetMmdl  0x021A572C  thumb  ov021
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 *   FLDMMDL_GetPosY  0x0216D8AC  thumb  ov010
 *   FLDMMDL_SysSearchGridPosHeight  0x0216DDDC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *FIELD_PLAYER_GRID_GetMmdl(u8 *p);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_MOVE_GetDirAddGridX(int a);
extern int FLDMMDL_GetGridNowZ(void *p);
extern int FLDMMDL_MOVE_GetDirAddGridZ(int a);
extern u32 FLDMMDL_GetPosY(void *p);
typedef signed int     s32;
extern u8 *FLDMMDL_SysSearchGridPosHeight(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);

u32 FIELD_PLAYER_GRID_EVENT_GetFrontTileAttr(u8 *a, u32 b)
{
    u32 r6;
    u32 h;
    int x;
    int y;

    r6 = (u32)FIELD_PLAYER_GRID_GetMmdl(a);
    h = (u32)FLDMMDL_GetMmdlSys((void *)r6);
    x = FLDMMDL_GetGridNowX((void *)r6);
    x += FLDMMDL_MOVE_GetDirAddGridX(b);
    y = FLDMMDL_GetGridNowZ((void *)r6);
    y += FLDMMDL_MOVE_GetDirAddGridZ(b);
    return (u32)FLDMMDL_SysSearchGridPosHeight(h, (s16)x, (s16)y, (u32)FLDMMDL_GetPosY((void *)r6), (u32)1, 0);
}
