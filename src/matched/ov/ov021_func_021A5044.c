/*
 * function: FIELD_PLAYER_GRID_StartWalkOnCycle
 * address:  0x021A5044
 * packet:   pkt_ov021_021A5044
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLAYER_GRID_GetAttrAtDir  0x021A5788  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   func_021AB41C  0x021AB41C  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_KEMURI_Start  0x021AC528  thumb  ov021
 *   FIELD_PLAYER_GRID_GetHeightStep  0x021A57C0  thumb  ov021
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FIELD_PLAYER_CORE_SetStepKind  0x021A3964  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06012.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_PLAYER_GRID_GetAttrAtDir(u32, u32, u32 *);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern int func_021AB41C(u16 id);
extern u32 FIELDMAP_GetEffect(u8 *p);
extern void FLDEFF_KEMURI_Start(u32, u32);
extern int FIELD_PLAYER_GRID_GetHeightStep(u8 *p, int dir);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetAcmd(u32, u32);
extern void FIELD_PLAYER_CORE_SetStepKind(u8 *p, u32 v);

void FIELD_PLAYER_GRID_StartWalkOnCycle(u32 *a, u32 b, u32 *c)
{
    u32 v;
    u32 r;
    int f = 1;
    if (c[4] == 1) {
        r = 0x14;
        f = 0;
    } else {
        r = 0x14;
        if (FIELD_PLAYER_GRID_GetAttrAtDir((u32)a, 9, &v) == 1) {
            if (func_021AB41C(MAP_ATTR_GetTerrainId(v)) == 1) {
                r = 0x9b;
                FLDEFF_KEMURI_Start(b, FIELDMAP_GetEffect((u8 *)a[4]));
            }
        }
    }
    if (f == 1) {
        if (FIELD_PLAYER_GRID_GetHeightStep((u8 *)((u32)a), ((struct Obj06012 *)c)->f8) == 1) {
            if (r == 0x14) {
                r = 0x10;
            }
        }
    }
    FLDMMDL_SetAcmd(b, FLDMMDL_ACMD_ConvertCodeByDir(((struct Obj06012 *)c)->f8, r));
    a[0] = 1;
    FIELD_PLAYER_CORE_SetStepKind((u8 *)a[3], 1);
}
