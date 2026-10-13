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
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_0219E348  0x0219E348  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A2F6C  0x021A2F6C  thumb  ov021
 *   func_0216DB4C  0x0216DB4C  thumb  ov010
 *   func_0216DC98  0x0216DC98  thumb  ov010
 *   func_0216DAE0  0x0216DAE0  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 *   func_02188D30  0x02188D30  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_021F377C  0x021F377C  thumb  ov063
 *   d_021F3D80     0x021F3D80  data  a1
 *   func_02030EAC  0x02030EAC  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../ov021/fldmmdl_rail_types.h"
#include "rail_slipdown_types.h"

extern u16 func_02188C84(void *fieldMap);
extern struct FieldNogridMapper *func_02188C5C(void *fieldMap);
extern struct RailWork *func_0219E348(struct Mmdl *mmdl);
extern struct FieldEffectSys *func_02188CD0(void *fieldMap);
extern struct FieldCamera *func_02188C58(void *fieldMap);
extern struct FieldPlayer *func_02188CB4(void *fieldMap);
extern void func_021A2F6C(struct FieldPlayer *player);
extern int func_0216DB4C(struct Mmdl *mmdl, int value);
extern int func_0216DC98(struct Mmdl *mmdl, int value);
extern void func_0216DAE0(struct Mmdl *mmdl, unsigned int value);
extern void func_0216DAF8(struct Mmdl *mmdl);
extern void *func_02188D30(void *fieldMap);
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

    slipdown = func_02030734(func_02188C84(fieldMap), 0x84, 1, d_021F3D80, 0x80);
    slipdown->nogridMapper = func_02188C5C(fieldMap);
    slipdown->mmdl = mmdl;
    slipdown->railWork = func_0219E348(mmdl);
    slipdown->effectSys = func_02188CD0(fieldMap);
    slipdown->camera = func_02188C58(fieldMap);
    if (isPlayer != 0) {
        slipdown->player = func_02188CB4(fieldMap);
        func_021A2F6C(slipdown->player);
    } else {
        slipdown->player = 0;
    }
    func_0216DB4C(slipdown->mmdl, 1);
    func_0216DC98(slipdown->mmdl, 1);
    func_0216DAE0(slipdown->mmdl, 0);
    func_0216DAF8(slipdown->mmdl);
    slipdown->task = func_02030DA8(func_02188D30(fieldMap), func_021F377C, slipdown, 0);
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
