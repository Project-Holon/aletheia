/*
 * function: FIELD_PLAYER_GRID_StartWalkOnFoot
 * address:  0x021A4DC0
 * packet:   pkt_ov021_021A4DC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_CORE_CheckFormModel  0x021A3A20  thumb  ov021
 *   FIELD_PLAYER_GRID_SetFlag  0x021A5304  thumb  ov021
 *   FIELD_PLAYER_GRID_ClearFlag  0x021A530C  thumb  ov021
 *   FIELD_PLAYER_CORE_GetPos  0x021A3898  thumb  ov021
 *   FLDMMDL_MOVE_GetMapAttr  0x02163E34  thumb  ov010
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   func_021AB44C  0x021AB44C  thumb  ov021
 *   FIELD_PLAYER_GRID_GetHeightStep  0x021A57C0  thumb  ov021
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FIELD_PLAYER_CORE_SetStepKind  0x021A3964  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04233.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_PLAYER_CORE_CheckFormModel(u32);
extern int FIELD_PLAYER_GRID_SetFlag(u32 a, u32 b);
extern int FIELD_PLAYER_GRID_ClearFlag(u32 a, u32 b);
struct VecFx32;
extern void FIELD_PLAYER_CORE_GetPos(unsigned char *, struct VecFx32 *);
extern int FLDMMDL_MOVE_GetMapAttr(u32, int *, u32 *);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern int func_021AB44C(u16 id);
extern int FIELD_PLAYER_GRID_GetHeightStep(u8 *p, int dir);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetAcmd(u32, u32);
extern void FIELD_PLAYER_CORE_SetStepKind(u8 *p, u32 v);

void FIELD_PLAYER_GRID_StartWalkOnFoot(u32 *a, u32 b, u32 *c)
{
    int buf[3];
    u32 v;
    u32 r;
    int f = 1;
    if (c[4] == 1) {
        r = 0x14;
        f = 0;
    } else if ((c[3] & 1) && (c[1] & 2)) {
        if (FIELD_PLAYER_CORE_CheckFormModel(a[3]) == 0) {
            r = 0x10;
        } else {
            r = 0x58;
            FIELD_PLAYER_GRID_SetFlag((u32)a, 0x20);
            FIELD_PLAYER_CORE_GetPos((unsigned char *)a[3], (struct VecFx32 *)buf);
            if (FLDMMDL_MOVE_GetMapAttr(b, buf, &v) != 0) {
                if (func_021AB44C(MAP_ATTR_GetTerrainId(v)) != 0) {
                    r = 0xc;
                    f = 0;
                    FIELD_PLAYER_GRID_ClearFlag((u32)a, 0x20);
                }
            }
        }
    } else {
        r = 0xc;
    }
    if (f == 1) {
        if (FIELD_PLAYER_GRID_GetHeightStep((u8 *)((u32)a), ((struct Obj04233 *)c)->f8) == 1) {
            switch (r) {
            case 0x10: r = 0x4c; break;
            case 0x58: r = 0xa3; break;
            case 0xc: r = 0xa7; break;
            }
        }
    }
    FLDMMDL_SetAcmd(b, FLDMMDL_ACMD_ConvertCodeByDir(((struct Obj04233 *)c)->f8, r));
    a[0] = 1;
    FIELD_PLAYER_CORE_SetStepKind((u8 *)a[3], 1);
}
