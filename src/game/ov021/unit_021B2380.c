/*
 * file:     unit_021B2380.c
 * unit:     yes
 * function: func_021B2380, func_021B23B8, func_021B23E0, func_021B23F0, func_021B240C, func_021B2444, func_021B247C, func_021B24B8, func_021B24F4, func_021B252C, func_021B2568, func_021B25A4, func_021B25DC, func_021B2614, func_021B2650, func_021B268C, func_021B269C, func_021B26AC, func_021B26E4, func_021B271C, func_021B273C, func_021B277C, func_021B27B4, func_021B27F8
 * address:  0x021B2380
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from scrcmd_screeneffects.c at 0x021B2380 (lane L135, ov043 launcher command handlers; original unknown).
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_021F3E24  0x021F3E24  thumb  ov039
 *   func_021F4134  0x021F4134  thumb  ov039
 *   func_021F3D74  0x021F3D74  thumb  ov039
 *   func_021F37A4  0x021F37A4  thumb  ov040
 *   func_021F37C8  0x021F37C8  thumb  ov040
 *   func_021F37EC  0x021F37EC  thumb  ov040
 *   func_021F3834  0x021F3834  thumb
 *   func_021F3888  0x021F3888  thumb  ov042
 *   func_021F4184  0x021F4184  thumb  ov039
 *   func_021F41B0  0x021F41B0  thumb  ov038
 *   func_021F41DC  0x021F41DC  thumb  ov038
 *   func_021F398C  0x021F398C  thumb  ov043
 *   func_021F3A28  0x021F3A28  thumb  ov043
 *   func_021F3770  0x021F3770  thumb  ov044
 *   func_021F42A8  0x021F42A8  thumb  ov043
 *   func_021F3970  0x021F3970  thumb  ov044
 *   func_021F384C  0x021F384C  thumb  ov045
 *   func_021F38C4  0x021F38C4  thumb  ov045
 *   func_021F3A88  0x021F3A88  thumb  ov038
 *   func_021F3B5C  0x021F3B5C  thumb  ov046
 *   func_021F3AD0  0x021F3AD0  thumb  ov046
 *   func_021F3B18  0x021F3B18  thumb  ov046
 */
#include "../arm9/script_vm_types.h"

struct ScrcmdWork;
struct GameSystem;

extern void *func_0215A5F4(struct ScrcmdWork *cmdWork);
extern u16 func_02159B10(ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern void func_0215897C(void *scriptWork, void *event);
extern struct GameSystem *func_0215A5DC(struct ScrcmdWork *cmdWork);
extern u16 *func_02159AE8(ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern void *func_0201210C(struct GameSystem *gameSystem);
extern u16 func_02011330(ScriptVm *vm);
extern void *func_021F3E24(struct GameSystem *gameSystem, u32 param);
extern void func_021F4134(struct GameSystem *gameSystem, u32 value);
extern void func_021F3D74(struct GameSystem *gameSystem);
extern void func_021F37A4(void *fieldMap);
extern int func_021F37C8(void *fieldMap);
extern void *func_021F37EC(struct GameSystem *gameSystem, u32 param);
extern void *func_021F3834(struct GameSystem *gameSystem, u8 param, u32 flag);
extern void *func_021F3888(struct GameSystem *gameSystem, u32 param);
extern void *func_021F4184(struct GameSystem *gameSystem, u16 param);
extern void *func_021F41B0(struct GameSystem *gameSystem, int param);
extern void *func_021F41DC(struct GameSystem *gameSystem, int param);
extern void *func_021F398C(struct GameSystem *gameSystem, int param);
extern void *func_021F3A28(struct GameSystem *gameSystem, u32 flag);
extern void *func_021F3770(struct GameSystem *gameSystem, u32 flag);
extern void func_021F42A8(struct GameSystem *gameSystem);
extern void func_021F3970(struct GameSystem *gameSystem);
extern void *func_021F384C(struct GameSystem *gameSystem, int param);
extern void func_021F38C4(struct GameSystem *gameSystem, int param);
extern void *func_021F3A88(struct GameSystem *gameSystem, int paramA, int paramB);
extern void *func_021F3B5C(struct GameSystem *gameSystem, int param);
extern void *func_021F3AD0(struct GameSystem *gameSystem, int paramA, int paramB);
extern void *func_021F3B18(struct GameSystem *gameSystem, u32 param);

int func_021B2380(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B23B8(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B23E0(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B23F0(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B240C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2444(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B247C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B24B8(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B24F4(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B252C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2568(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B25A4(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B25DC(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2614(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B2650(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B268C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B269C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B26AC(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B26E4(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B271C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B273C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B277C(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B27B4(ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021B27F8(ScriptVm *vm, struct ScrcmdWork *cmdWork);

/*
 * The handlers below start a field gimmick overlay event (ov038 to ov046,
 * one entry point each). Most read their parameter from the script, create
 * the event through the overlay and hand it to the script system; they
 * return 1 so the script waits. A null event means nothing to run, so the
 * script still waits one step.
 */

/* Script command: start the ov039 event for a parameter byte. */
int func_021B2380(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    u8 param = func_02011330(vm);
    void *event = func_021F3E24(gameSystem, param);

    if (event == 0) {
        return 1;
    }
    func_0215897C(scriptWork, event);
    return 1;
}

/* Script command: store a value byte in the ov039 gimmick state (slot 2). */
int func_021B23B8(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u8 value;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    value = func_02011330(vm);
    func_021F4134(gameSystem, value);
    return 0;
}

/* Script command: ov039 sound slot transfer (no arguments). */
int func_021B23E0(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    func_021F3D74(func_0215A5DC(cmdWork));
    return 0;
}

/* Script command: set the ov040 gimmick flag of the current map (no arguments). */
int func_021B23F0(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    func_0215A5F4(cmdWork);
    func_021F37A4(func_0201210C(func_0215A5DC(cmdWork)));
    return 0;
}

/* Script command: write the ov040 gimmick flag of the current map to a script variable (0 or 1). */
int func_021B240C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *fieldMap;
    u16 *result;

    func_0215A5F4(cmdWork);
    fieldMap = func_0201210C(func_0215A5DC(cmdWork));
    result = func_02159AE8(vm, cmdWork);
    if (func_021F37C8(fieldMap) != 0) {
        *result = 1;
    } else {
        *result = 0;
    }
    return 0;
}

/* Script command: start the ov040 event for a parameter byte. */
int func_021B2444(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    u8 param = func_02011330(vm);
    void *event = func_021F37EC(gameSystem, param);

    if (event == 0) {
        return 1;
    }
    func_0215897C(scriptWork, event);
    return 1;
}

/* Script command: start the ov042 event for a parameter byte with its flag set. */
int func_021B247C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    u8 param = func_02011330(vm);
    u32 flag = 1;
    void *event = func_021F3834(gameSystem, param, flag);

    if (event == 0) {
        return flag;
    }
    func_0215897C(scriptWork, event);
    return flag;
}

/* Same as func_021B247C with the flag clear. */
int func_021B24B8(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    u8 param = func_02011330(vm);
    void *event = func_021F3834(gameSystem, param, 0);

    if (event == 0) {
        return 1;
    }
    func_0215897C(scriptWork, event);
    return 1;
}

/* Script command: start the ov042 second event for a parameter byte. */
int func_021B24F4(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    u8 param = func_02011330(vm);
    void *event = func_021F3888(gameSystem, param);

    if (event == 0) {
        return 1;
    }
    func_0215897C(scriptWork, event);
    return 1;
}

/* Script command: start the ov039 second event for a script variable value. */
int func_021B252C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    void *event = func_021F4184(gameSystem, *func_02159AE8(vm, cmdWork));

    if (event == 0) {
        return 1;
    }
    func_0215897C(scriptWork, event);
    return 1;
}

/* Script command: start the ov038 event for a script variable value. */
int func_021B2568(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    void *event = func_021F41B0(gameSystem, *func_02159AE8(vm, cmdWork));

    if (event == 0) {
        return 1;
    }
    func_0215897C(scriptWork, event);
    return 1;
}

/* Script command: start the ov038 second event for an immediate value. */
int func_021B25A4(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    void *event = func_021F41DC(gameSystem, func_02011330(vm));

    if (event == 0) {
        return 1;
    }
    func_0215897C(scriptWork, event);
    return 1;
}

/* Script command: start the ov043 event for an immediate value. */
int func_021B25DC(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    void *event = func_021F398C(gameSystem, func_02011330(vm));

    if (event == 0) {
        return 1;
    }
    func_0215897C(scriptWork, event);
    return 1;
}

/* Script command: start the ov043 second event; the immediate value is reduced to a flag. */
int func_021B2614(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    void *event = func_021F3A28(gameSystem, func_02011330(vm) ? 1 : 0);

    if (event == 0) {
        return 1;
    }
    func_0215897C(scriptWork, event);
    return 1;
}

/* Script command: start the ov044 event; the immediate value is reduced to a flag. */
int func_021B2650(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    void *event = func_021F3770(gameSystem, func_02011330(vm) ? 1 : 0);

    if (event == 0) {
        return 1;
    }
    func_0215897C(scriptWork, event);
    return 1;
}

/* Script command: ov043 cleanup (no arguments). */
int func_021B268C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    func_021F42A8(func_0215A5DC(cmdWork));
    return 0;
}

/* Script command: ov044 cleanup (no arguments). */
int func_021B269C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    func_021F3970(func_0215A5DC(cmdWork));
    return 0;
}

/* Script command: start the ov045 event for an immediate value. */
int func_021B26AC(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    void *event = func_021F384C(gameSystem, func_02011330(vm));

    if (event == 0) {
        return 1;
    }
    func_0215897C(scriptWork, event);
    return 1;
}

/* Script command: start the ov042 second event for an immediate value. */
int func_021B26E4(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    void *event = func_021F3888(gameSystem, func_02011330(vm));

    if (event == 0) {
        return 1;
    }
    func_0215897C(scriptWork, event);
    return 1;
}

/* Script command: ov045 state change for an immediate value. */
int func_021B271C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    func_021F38C4(func_0215A5DC(cmdWork), func_02011330(vm));
    return 0;
}

/* Script command: start the ov038 check event for two immediate values. */
int func_021B273C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    int paramA = func_02011330(vm);
    int paramB = func_02011330(vm);
    void *event = func_021F3A88(gameSystem, paramA, paramB);

    if (event == 0) {
        return 1;
    }
    func_0215897C(scriptWork, event);
    return 1;
}

/* Script command: start the ov046 event for an immediate value. */
int func_021B277C(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    void *event = func_021F3B5C(gameSystem, func_02011330(vm));

    if (event == 0) {
        return 1;
    }
    func_0215897C(scriptWork, event);
    return 1;
}

/* Script command: start the ov046 second event for two script values. */
int func_021B27B4(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    int paramA = (int)func_02159B10(vm, cmdWork);
    int paramB = (int)func_02159B10(vm, cmdWork);
    void *event = func_021F3AD0(gameSystem, paramA, paramB);

    if (event == 0) {
        return 1;
    }
    func_0215897C(scriptWork, event);
    return 1;
}

/* Script command: start the ov046 third event for a script value. */
int func_021B27F8(ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    void *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    void *event = func_021F3B18(gameSystem, func_02159B10(vm, cmdWork));

    if (event == 0) {
        return 1;
    }
    func_0215897C(scriptWork, event);
    return 1;
}
