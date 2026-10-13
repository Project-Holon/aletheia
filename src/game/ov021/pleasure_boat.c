/*
 * file:     pleasure_boat.c
 * unit:     yes
 * function: func_021C87A0, func_021C87AC, func_021C87B8, func_021C87C8, func_021C87D4, func_021C87E0, func_021C8810, func_021C881C, func_021C8848, func_021C8868, func_021C88AC, func_021C88EC, func_021C8960
 * address:  0x021C87A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from bsubway_scr.c at 0x021C87A0: pleasure_boat.c tail; calls func_021C8608 (pleasure_boat.c __FILE__ anchor, in field_flash.c), func_021C86E8, func_021C8738.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012ED0  0x02012ED0  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021C8608  0x021C8608  thumb  ov021
 *   func_021666A4  0x021666A4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02011330  0x02011330  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021C8738  0x021C8738  thumb  ov021
 *   func_021C86E8  0x021C86E8  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

typedef struct ScriptVm ScriptVm;
typedef struct ScrCmdWork ScrCmdWork;
typedef struct GameSystem GameSystem;
typedef struct FieldMap FieldMap;
typedef struct GameData GameData;

#include "pleasure_boat_types.h"

extern GameSystem *func_0215A5DC(ScrCmdWork *scrCmdWork);
extern FieldMap *func_0201210C(GameSystem *gameSystem);
extern GameSystem *func_02188C80(FieldMap *fieldMap);
extern GameData *func_020120F4(GameSystem *gameSystem);
extern PleasureBoatHolder *func_02012ED0(GameData *gameData);
extern PleasureBoatWork *func_021C8608(void);
extern void func_021666A4(PleasureBoatHolder *holder);
extern void *func_0215A5F4(ScrCmdWork *scrCmdWork);
extern u16 func_02011330(ScriptVm *vm);
extern u16 *func_02159AE8(ScriptVm *vm, ScrCmdWork *scrCmdWork);
extern int func_021C8738(PleasureBoatWork *work, int kind);
extern void func_021C86E8(PleasureBoatWork *work, u32 seconds, u32 clamp);
extern u16 func_02159B10(ScriptVm *vm, ScrCmdWork *scrCmdWork);

u32 func_021C87A0(PleasureBoatWork *work, u32 index);
u32 func_021C87AC(PleasureBoatWork *work, u32 index);
u32 func_021C87B8(PleasureBoatWork *work, u32 index, u32 wordIndex);
u32 func_021C87C8(PleasureBoatWork *work, u32 index);
void func_021C87D4(PleasureBoatWork *work, int index, int occupied);
int func_021C87E0(PleasureBoatWork *work);
PleasureBoatWork *func_021C8810(PleasureBoatWork *work);
int func_021C881C(ScriptVm *vm, ScrCmdWork *scrCmdWork);
int func_021C8848(ScriptVm *vm, ScrCmdWork *scrCmdWork);
int func_021C8868(ScriptVm *vm, ScrCmdWork *scrCmdWork);
int func_021C88AC(ScriptVm *vm, ScrCmdWork *scrCmdWork);
int func_021C88EC(ScriptVm *vm, ScrCmdWork *scrCmdWork);
int func_021C8960(ScriptVm *vm, ScrCmdWork *scrCmdWork);

/* Script queries 5, 6, 7 and 8 read these passenger fields (see symbol_map.c, func_02166734). */
u32 func_021C87A0(PleasureBoatWork *work, u32 index)
{
    return work->passengers[index].param;
}

u32 func_021C87AC(PleasureBoatWork *work, u32 index)
{
    return work->passengers[index].type;
}

/*
 * lever: the passenger record pointer as its own local; the flat
 *   `p + i*0x1C + j*4 + 0x1C` spelling is DIFF4 (adds order).
 */
u32 func_021C87B8(PleasureBoatWork *work, u32 index, u32 wordIndex)
{
    BoatPassenger *passenger = &work->passengers[index];
    return passenger->extra[wordIndex];
}

u32 func_021C87C8(PleasureBoatWork *work, u32 index)
{
    return work->passengers[index].occupied;
}

void func_021C87D4(PleasureBoatWork *work, int index, int occupied)
{
    work->passengers[index].occupied = occupied;
}

/* Returns 2 when the trip is over (period 4, tick 5400), 1 at each period boundary, else 0. */
int func_021C87E0(PleasureBoatWork *work)
{
    if (work->timeTicks >= 5400 && work->periodCount >= 4)
        return 2;
    return work->timeTicks % 1350 == 0;
}

PleasureBoatWork *func_021C8810(PleasureBoatWork *work)
{
    work->locked = 1;
    return work;
}

/* Script command: creates the boat work in the event state unless it exists. */
int func_021C881C(ScriptVm *vm, ScrCmdWork *scrCmdWork)
{
    PleasureBoatHolder *holder = func_02012ED0(func_020120F4(func_02188C80(func_0201210C(func_0215A5DC(scrCmdWork)))));
    if (holder->boat == 0)
        holder->boat = func_021C8608();
    return 0;
}

/* Script command: frees the boat work. */
int func_021C8848(ScriptVm *vm, ScrCmdWork *scrCmdWork)
{
    func_021666A4(func_02012ED0(func_020120F4(func_02188C80(func_0201210C(func_0215A5DC(scrCmdWork))))));
    return 0;
}

/* Script command: reads the statistic selected by the next operand into the output variable. */
int func_021C8868(ScriptVm *vm, ScrCmdWork *scrCmdWork)
{
    PleasureBoatHolder *holder;
    int kind;
    u16 *out;

    func_0215A5F4(scrCmdWork);
    holder = func_02012ED0(func_020120F4(func_02188C80(func_0201210C(func_0215A5DC(scrCmdWork)))));
    kind = func_02011330(vm);
    out = func_02159AE8(vm, scrCmdWork);
    *out = func_021C8738(holder->boat, kind);
    return 0;
}

/* Script command: advances the boat clock by the seconds operand; the second operand is the clamp flag. */
int func_021C88AC(ScriptVm *vm, ScrCmdWork *scrCmdWork)
{
    func_0215A5F4(scrCmdWork);
    func_021C86E8(func_02012ED0(func_020120F4(func_02188C80(func_0201210C(func_0215A5DC(scrCmdWork)))))->boat, func_02011330(vm), func_02011330(vm));
    return 0;
}

/* Script command: sets a passenger field; only sub-command 8 (occupied flag) writes anything. */
int func_021C88EC(ScriptVm *vm, ScrCmdWork *scrCmdWork)
{
    PleasureBoatHolder *holder;
    int index;
    int subCommand;
    int value;

    func_0215A5F4(scrCmdWork);
    holder = func_02012ED0(func_020120F4(func_0215A5DC(scrCmdWork)));
    index = func_02159B10(vm, scrCmdWork);
    subCommand = func_02011330(vm);
    func_02011330(vm);
    value = func_02159B10(vm, scrCmdWork);
    switch (subCommand) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    case 8:
        func_021C87D4(holder->boat, index, value == 1);
        break;
    }
    return 0;
}

/* Script command: locks the boat clock and arrivals. */
int func_021C8960(ScriptVm *vm, ScrCmdWork *scrCmdWork)
{
    func_021C8810(func_02012ED0(func_020120F4(func_02188C80(func_0201210C(func_0215A5DC(scrCmdWork)))))->boat);
    return 0;
}
