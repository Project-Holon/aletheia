/*
 * file:     rail_slipdown.c
 * unit:     yes
 * function: func_021F36C0, func_021F3758, func_021F376C
 * address:  0x021F36C0
 * region:   ov063
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FLDMMDL_RAIL_GetRailWork  0x0219E348  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_ResetMoveWork  0x021A2F6C  thumb  ov021
 *   FLDMMDL_SetStatusBitHeightGetOff  0x0216DB4C  thumb  ov010
 *   FLDMMDL_SetStatusBitAttrGetOff  0x0216DC98  thumb  ov010
 *   FLDMMDL_SetStatusBitFellowHit  0x0216DAE0  thumb  ov010
 *   FLDMMDL_OnMoveBitMovePause  0x0216DAF8  thumb  ov010
 *   FIELDMAP_GetTcblSys  0x02188D30  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_021F377C  0x021F377C  thumb  ov063
 *   d_021F3D80     0x021F3D80  data  a1
 *   func_02030EAC  0x02030EAC  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../ov021/fldmmdl_rail_types.h"
#include "rail_slipdown_types.h"

extern u16 FIELDMAP_GetHeapId(void *fieldMap);
extern struct FieldNogridMapper *FIELDMAP_GetNogridMapper(void *fieldMap);
extern struct RailWork *FLDMMDL_RAIL_GetRailWork(struct Mmdl *mmdl);
extern struct FieldEffectSys *FIELDMAP_GetEffect(void *fieldMap);
extern struct FieldCamera *FIELDMAP_GetCamera(void *fieldMap);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(void *fieldMap);
extern void FIELD_PLAYER_ResetMoveWork(struct FieldPlayer *player);
extern int FLDMMDL_SetStatusBitHeightGetOff(struct Mmdl *mmdl, int value);
extern int FLDMMDL_SetStatusBitAttrGetOff(struct Mmdl *mmdl, int value);
extern void FLDMMDL_SetStatusBitFellowHit(struct Mmdl *mmdl, unsigned int value);
extern void FLDMMDL_OnMoveBitMovePause(struct Mmdl *mmdl);
extern void *FIELDMAP_GetTcblSys(void *fieldMap);
extern RailSlipdown *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct TcbTask *func_02030DA8(void *tcblSys, void (*func)(void *tcb, RailSlipdown *slipdown), RailSlipdown *arg, u32 priority);
extern void func_021F377C(void *tcb, RailSlipdown *slipdown);
extern void func_02030EAC(struct TcbTask *task);
extern u32 func_020307B0(void *p);
RailSlipdown *func_021F36C0(void *gameSystem, void *fieldMap, struct Mmdl *mmdl, int isPlayer);
void func_021F3758(RailSlipdown *slipdown);
int func_021F376C(RailSlipdown *slipdown);
extern const char d_021F3D80[];

RailSlipdown *func_021F36C0(void *gameSystem, void *fieldMap, struct Mmdl *mmdl, int isPlayer)
{
    RailSlipdown *slipdown;

    slipdown = func_02030734(FIELDMAP_GetHeapId(fieldMap), 0x84, 1, d_021F3D80, 0x80);
    slipdown->nogridMapper = FIELDMAP_GetNogridMapper(fieldMap);
    slipdown->mmdl = mmdl;
    slipdown->railWork = FLDMMDL_RAIL_GetRailWork(mmdl);
    slipdown->effectSys = FIELDMAP_GetEffect(fieldMap);
    slipdown->camera = FIELDMAP_GetCamera(fieldMap);
    if (isPlayer != 0) {
        slipdown->player = FIELDMAP_GetFieldPlayer(fieldMap);
        FIELD_PLAYER_ResetMoveWork(slipdown->player);
    } else {
        slipdown->player = 0;
    }
    FLDMMDL_SetStatusBitHeightGetOff(slipdown->mmdl, 1);
    FLDMMDL_SetStatusBitAttrGetOff(slipdown->mmdl, 1);
    FLDMMDL_SetStatusBitFellowHit(slipdown->mmdl, 0);
    FLDMMDL_OnMoveBitMovePause(slipdown->mmdl);
    slipdown->task = func_02030DA8(FIELDMAP_GetTcblSys(fieldMap), func_021F377C, slipdown, 0);
    return slipdown;
}

void func_021F3758(RailSlipdown *slipdown)
{
    func_02030EAC(slipdown->task);
    func_020307B0(slipdown);
}

int func_021F376C(RailSlipdown *slipdown)
{
    if (slipdown->state == SLIPDOWN_STATE_DONE) {
        return 1;
    }
    return 0;
}
