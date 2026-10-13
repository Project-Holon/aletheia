/*
 * function: FIELDMAP_CTRL_HYBRID_UpdateGrid
 * address:  0x021A6F5C
 * packet:   pkt_ov021_021A6F5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_PLAYER_ChooseMoveDirFromKeys  0x021A2FA4  thumb  ov021
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FIELD_PLAYER_CheckMoveBusy  0x021A2FB0  thumb  ov021
 *   FIELD_PLAYER_GetNowAttribute  0x021A30C8  thumb  ov021
 *   FIELD_PLAYER_GetFrontAttribute  0x021A3128  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   RAIL_ATTR_IsJumpStart  0x021BB1A0  thumb  ov021
 *   MAP_ATTR_IsBlocked  0x021AB11C  thumb  ov021
 *   FIELDMAP_CTRL_HYBRID_FindRailLocation  0x021A71E4  thumb  ov021
 *   FIELDMAP_CTRL_HYBRID_SwitchToNogrid  0x021A70D0  thumb  ov021
 *   FIELD_PLAYER_CheckMoveRestrictFlag  0x021A35BC  thumb  ov021
 *   FIELD_PLAYER_SetupGrid  0x021A35F0  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern u16 FIELD_PLAYER_ChooseMoveDirFromKeys(u8 *p, u32 a1);
extern int FLDMMDL_CheckPossibleAcmd(int a0);
extern u32 FIELD_PLAYER_CheckMoveBusy(u32 a);
extern u32 FIELD_PLAYER_GetNowAttribute(void **ctx);
extern u32 FIELD_PLAYER_GetFrontAttribute(u32 *a, u32 b);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern int RAIL_ATTR_IsJumpStart(int x);
extern int MAP_ATTR_IsBlocked(u32 attr);
extern int FIELDMAP_CTRL_HYBRID_FindRailLocation(u32 a, u32 *b, u16 *c, u32 d);
extern void FIELDMAP_CTRL_HYBRID_SwitchToNogrid(u32 a, u32 *b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern int FIELD_PLAYER_CheckMoveRestrictFlag(int a);
extern int FIELD_PLAYER_SetupGrid(u32 a, u32 b, u32 c, u32 d);

void FIELDMAP_CTRL_HYBRID_UpdateGrid(u32 a, u32 *b)
{
    u16 out[4];
    u32 v1c;
    u32 v18;
    void *v14;
    u32 v10;
    u32 r7;
    u32 fl;
    u32 r4;
    v10 = func_020362DC();
    r7 = func_0203630C();
    fl = 0;
    v14 = FIELD_PLAYER_GetMmdl((unsigned char *)b[1]);
    r4 = FIELD_PLAYER_ChooseMoveDirFromKeys((u8 *)b[1], r7);
    if (FLDMMDL_CheckPossibleAcmd((int)v14) == 1 || FIELD_PLAYER_CheckMoveBusy(b[1]) == 1) {
        if (r4 != 9) {
            v18 = FIELD_PLAYER_GetNowAttribute((void **)b[1]);
            v1c = FIELD_PLAYER_GetFrontAttribute((u32 *)b[1], r4);
            if (RAIL_ATTR_IsJumpStart(MAP_ATTR_GetTerrainId(v18)) != 0) {
                if (MAP_ATTR_IsBlocked(v1c) != 0) {
                    if (FIELDMAP_CTRL_HYBRID_FindRailLocation(a, b, out, r4) != 0) {
                        FIELDMAP_CTRL_HYBRID_SwitchToNogrid(a, b, r4, 1, (u32)out, v10, r7);
                        return;
                    }
                }
            }
        }
    }
    if (FIELD_PLAYER_CheckMoveRestrictFlag(b[1]) == 1)
        fl |= 1;
    FIELD_PLAYER_SetupGrid(b[1], v10, r7, fl);
}
