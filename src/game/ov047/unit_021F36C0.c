/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F370C, func_021F3740, func_021F3800, func_021F381C
 * address:  0x021F36C0
 * region:   ov047
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_0216D8E0 0x0216D8E0 thumb ov010
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021F381C  0x021F381C  thumb  ov047
 *   func_02005728  0x02005728  thumb
 *   func_0203F684  0x0203F684  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _ll_mul        0x0209C054  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021F3840     0x021F3840  data  ov047  a1
 *   func_02082BCC 0x02082BCC arm
 *   func_021A30C8  0x021A30C8  thumb  ov021
 *   func_021AB100  0x021AB100  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB44C  0x021AB44C  thumb  ov021
 */
#include "unit_021F36C0_types.h"

extern u8 d_021F3840[];

/* Sway amplitudes (in tiles) picked at random at the start of each cycle. */
#define BRIDGE_SWAY_AMPLITUDE_COUNT 4
/* Degrees added to the sway phase per frame. */
#define BRIDGE_SWAY_ANGLE_STEP 8

#define FX32_FROM_INT(x) ((fx32)(((x) > 0) ? ((x) * (1 << 12) + .5f) : ((x) * (1 << 12) - .5f)))

/* Gimmick start: allocates the sway work and stores the player and its model in it. */
void func_021F36C0(FieldMap *fieldMap)
{
    BridgeSwayWork *work;

    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), FIELD_GIMMICK_ID_BRIDGE_SWAY);
    func_02189764(fieldMap, BRIDGE_SWAY_WORK_ID, func_02188C84(fieldMap), sizeof(BridgeSwayWork));
    work = func_021897BC(fieldMap, BRIDGE_SWAY_WORK_ID);
    work->player = func_02188CB4(fieldMap);
    work->playerMmdl = func_021A3074(work->player);
    work->drawOffset.x = 0;
    work->drawOffset.y = 0;
    work->drawOffset.z = 0;
}

/* Gimmick end: applies the last draw offset to the player model and frees the sway work. */
void func_021F370C(FieldMap *fieldMap)
{
    BridgeSwayWork *work;

    func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), FIELD_GIMMICK_ID_BRIDGE_SWAY);
    work = func_021897BC(fieldMap, BRIDGE_SWAY_WORK_ID);
    func_0216D8E0(work->playerMmdl, &work->drawOffset);
    func_021897A0(fieldMap, BRIDGE_SWAY_WORK_ID);
}

/* Per frame: while the player stands on a no-dash tile, bob the player model on a sine of the sway phase. */
void func_021F3740(FieldMap *fieldMap)
{
    BridgeSwaySave *save;
    BridgeSwayWork *work;
    fx32 height;
    int amplitude;
    fx32 sine;

    save = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(fieldMap))), FIELD_GIMMICK_ID_BRIDGE_SWAY);
    work = func_021897BC(fieldMap, BRIDGE_SWAY_WORK_ID);
    if (func_021F381C(work) == 0) {
        work->drawOffset.y = 0;
        save->angle = 0;
        func_0216D8E0(work->playerMmdl, &work->drawOffset);
        return;
    }
    if (save->angle == 0) {
        save->amplitude = d_021F3840[func_02005728(BRIDGE_SWAY_AMPLITUDE_COUNT)];
    }
    amplitude = save->amplitude;
    height = FX32_FROM_INT(amplitude);
    sine = func_0203F684((u16)save->angle);
    work->drawOffset.y = (fx32)(((s64)sine * height + 0x800) >> 12);
    func_0216D8E0(work->playerMmdl, &work->drawOffset);
    save->angle = (save->angle + BRIDGE_SWAY_ANGLE_STEP) % 360;
}

/* Gimmick save reset: clears the sway state. */
void func_021F3800(struct GameSystem *gameSystem)
{
    func_02082BCC(func_0200B3A4(func_02012EC4(func_020120F4(gameSystem)), FIELD_GIMMICK_ID_BRIDGE_SWAY), 0, sizeof(BridgeSwaySave));
}

/* The player stands on a tile whose terrain is the no-dash terrain (checked through the attribute predicates). */
int func_021F381C(BridgeSwayWork *work)
{
    u32 attr = func_021A30C8(work->player);

    if (func_021AB100(attr) == 0) {
        return 0;
    }
    return func_021AB44C(func_021AB0F0(attr));
}
