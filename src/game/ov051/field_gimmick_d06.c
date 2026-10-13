/*
 * file:     field_gimmick_d06.c
 * unit:     yes
 * function: func_021F36C0, func_021F36E0, func_021F36EC, func_021F36F8, func_021F3718, func_021F3724, func_021F3730, func_021F3868, func_021F38A0, func_021F38A4, func_021F3958, func_021F39F8, func_021F3AB4, func_021F3B44, func_021F3B88, func_021F3BC4, func_021F3C84, func_021F3C98, func_021F3CCC, func_021F3D04, func_021F3D38, func_021F3D6C
 * address:  0x021F36C0
 * region:   ov051
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F3DB4 0x021F3DB4 data a4
 *   d_021F3DFC 0x021F3DFC data a4
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021F3D94  0x021F3D94  thumb  ov051
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02030734  0x02030734  arm
 *   func_021ABE30  0x021ABE30  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb
 *   func_0216DD1C  0x0216DD1C  thumb
 *   func_0216D588  0x0216D588  thumb
 *   d_021F40A0     0x021F40A0  data  ov051  a4
 *   func_020307B0 0x020307B0 arm
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3038  0x021A3038  thumb
 *   func_02164208  0x02164208  thumb
 *   func_0216DDC0  0x0216DDC0  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082C60  0x02082C60  arm
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D3CC  0x0216D3CC  thumb
 *   func_02197E7C  0x02197E7C  thumb
 *   func_0216D410  0x0216D410  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D454  0x0216D454  thumb
 *   func_0216D480  0x0216D480  thumb
 *   func_021C909C  0x021C909C  thumb
 *   func_021C90AC  0x021C90AC  thumb
 *   func_021C90D0  0x021C90D0  thumb
 *   func_0216D88C  0x0216D88C  thumb
 *   func_021C9064  0x021C9064  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_0216D83C  0x0216D83C  thumb
 *   func_0216D854  0x0216D854  thumb
 *   func_0216D86C  0x0216D86C  thumb
 *   func_02164240  0x02164240  thumb
 *   func_02163994  0x02163994  thumb
 *   func_02164280  0x02164280  thumb
 *   func_0216D8AC  0x0216D8AC  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB3F8  0x021AB3F8  thumb
 *   func_021C9258 0x021C9258 thumb ov021
 *   func_021C928C 0x021C928C thumb ov021
 *   func_0216CE6C 0x0216CE6C thumb ov010
 */
#include "../ov021/fld_exp_obj_types.h"
#include "field_gimmick_d06_types.h"

const GimmickD06ZoneTable *func_021F36C0(int zoneId);
const GimmickD06GridPos *func_021F36E0(int zoneId);
int func_021F36EC(int zoneId);
const GimmickD06ZoneTable *func_021F36F8(int zoneId);
const GimmickD06GridPos *func_021F3718(int zoneId);
int func_021F3724(int zoneId);
void func_021F3730(struct FieldMap *fieldMap);
void func_021F3868(struct FieldMap *fieldMap);
void func_021F38A0(void);
struct GameEvent *func_021F38A4(struct FieldMap *fieldMap, int facingDir);
struct GameEvent *func_021F3958(struct FieldMap *fieldMap, struct Mmdl *stone, int direction);
int func_021F39F8(struct GameEvent *event, int *seq, void *work);
int func_021F3AB4(struct GameEvent *event, int *seq, void *work);
void func_021F3B44(GimmickD06Work *work, GimmickD06StoneSlot *slot, int gridX, int gridZ);
void func_021F3B88(GimmickD06Work *work, GimmickD06StoneSlot *slot, struct Mmdl *mmdl);
int func_021F3BC4(GimmickD06Work *work, GimmickD06StoneSlot *slot, int direction, unsigned short maxSteps, unsigned int *steps);
int func_021F3C84(GimmickD06Work *work, GimmickD06StoneSlot *slot, int direction);
int func_021F3C98(GimmickD06Work *work, GimmickD06StoneSlot *slot);
void func_021F3CCC(GimmickD06Work *work, struct FieldEffectObj **pulse, int gridX, int gridY, int gridZ);
void func_021F3D04(struct FieldMap *fieldMap, int panelIndex);
struct Mmdl *func_021F3D38(struct FieldMap *fieldMap, int gridX, int gridZ);
GimmickD06Work *func_021F3D6C(struct FieldMap *fieldMap);

/* The __FILE__ string of the allocation in the setup function. */
extern char d_021F40A0[];
/* The stone cells and the panel cells of the three zones. */
extern const GimmickD06ZoneTable d_021F3DB4[GIMMICK_D06_ZONE_COUNT];
extern const GimmickD06ZoneTable d_021F3DFC[GIMMICK_D06_ZONE_COUNT];

/* The row of the stone table for a zone; the first row for an unknown zone. */
const GimmickD06ZoneTable *func_021F36C0(int zoneId)
{
    unsigned int i;
    const GimmickD06ZoneTable *table = d_021F3DB4;

    for (i = 0; i < GIMMICK_D06_ZONE_COUNT; i++, table++)
        if (table->zoneId == zoneId)
            return table;
    return d_021F3DB4;
}

/*
 * Two accessors over the result of func_021F36C0: the cells and their count.
 */
const GimmickD06GridPos *func_021F36E0(int zoneId)
{
    return func_021F36C0(zoneId)->positions;
}

int func_021F36EC(int zoneId)
{
    return func_021F36C0(zoneId)->count;
}

/* The row of the panel table for a zone; the first row for an unknown zone. */
const GimmickD06ZoneTable *func_021F36F8(int zoneId)
{
    unsigned int i;
    const GimmickD06ZoneTable *table = d_021F3DFC;

    for (i = 0; i < GIMMICK_D06_ZONE_COUNT; i++, table++)
        if (table->zoneId == zoneId)
            return table;
    return d_021F3DFC;
}

/*
 * Two accessors over the result of func_021F36F8: the cells and their count.
 */
const GimmickD06GridPos *func_021F3718(int zoneId)
{
    return func_021F36F8(zoneId)->positions;
}

int func_021F3724(int zoneId)
{
    return func_021F36F8(zoneId)->count;
}

/*
 * Gimmick setup: allocate the work and put the stones and the panel effects of
 * the zone on the map. The first visit creates the stones from the table;
 * later visits pick up the stone objects the map holds.
 *
 * note:     the flag test reads the placed byte as unsigned char (ldrb); a plain char
 *           test gives ldrsb with a zero register hoisted above the branch.
 */
void func_021F3730(struct FieldMap *fieldMap)
{
    int effectId;
    u32 iterator;
    struct Mmdl *mmdl;
    int heapId;
    struct GimmickWork *gimmickWork;
    struct FieldEffectSys *effects;
    int zoneId;
    GimmickD06Save *save;
    GimmickD06Work *work;
    unsigned int i;
    unsigned int count;
    const GimmickD06GridPos *pos;
    struct MmdlSys *mmdlSys;

    heapId = func_02188C84(fieldMap);
    gimmickWork = func_02012EC4(func_020120F4(func_02188C80(fieldMap)));
    effects = func_02188CD0(fieldMap);
    zoneId = func_02188C9C(fieldMap);
    save = func_0200B3A4(gimmickWork, func_021F3D94(zoneId));
    work = func_02030734(heapId, sizeof(GimmickD06Work), 1, d_021F40A0, 0xca);
    save->work = work;
    work->save = save;
    work->fieldMap = fieldMap;
    work->zoneId = zoneId;
    effectId = 0xb;
    func_021ABE30(effects, &effectId, 1);
    if (save->placed == 0) {
        count = func_021F36EC(work->zoneId);
        pos = func_021F36E0(work->zoneId);
        i = 0;
        if (i < count)
            for (; i < count; i++) {
                func_021F3B44(work, &work->stones[i], pos->x, pos->z);
                pos++;
            }
    } else {
        i = 0;
        iterator = 0;
        mmdlSys = func_02188C7C(fieldMap);
        while (func_0216DD1C(mmdlSys, &mmdl, &iterator)) {
            if (func_0216D588(mmdl) == GIMMICK_D06_STONE_OBJ_ID) {
                func_021F3B88(work, &work->stones[i], mmdl);
                i++;
                if (i >= GIMMICK_D06_STONE_MAX)
                    break;
            }
        }
    }
    count = func_021F3724(work->zoneId);
    pos = func_021F3718(work->zoneId);
    i = 0;
    if (i < count)
        for (; i < count; i++) {
            func_021F3CCC(work, &work->panelPulse[i], pos->x, pos->y, pos->z);
            pos++;
        }
    save->placed = 1;
}

/* Gimmick exit: free the work. */
void func_021F3868(struct FieldMap *fieldMap)
{
    struct GimmickWork *gimmickWork;

    func_02188C84(fieldMap);
    gimmickWork = func_02012EC4(func_020120F4(func_02188C80(fieldMap)));
    func_02188CD0(fieldMap);
    func_020307B0(func_0200B3A4(gimmickWork, func_021F3D94(func_02188C9C(fieldMap)))->work);
}

/*
 * Gimmick update: empty.
 * note: extent follower at 0x021F38A0 is an empty return stub; no existing same-region source or shard was found.
 */
void func_021F38A0(void)
{
}

/*
 * Check for a stone in front of the player: the cell ahead of the player is
 * on a stone, push it. Also pulse the panel when a panel cell is the one ahead.
 * Returns the slide event or null.
 */
struct GameEvent *func_021F38A4(struct FieldMap *fieldMap, int facingDir)
{
    VecFx32 pos;
    struct GameEvent *event;
    int gridX;
    int gridZ;
    struct Mmdl *mmdl;
    unsigned int i;
    const GimmickD06GridPos *panel;
    unsigned int count;
    GimmickD06Work *work;

    event = 0;
    work = func_021F3D6C(fieldMap);
    func_021A3038(func_02188CB4(fieldMap), &pos);
    func_02164208(facingDir, &pos, 1 << 16);
    gridX = (short)(((pos.x >> 4) / 4096));
    gridZ = (short)(((pos.z >> 4) / 4096));
    count = func_021F3724(work->zoneId);
    panel = func_021F3718(work->zoneId);
    i = 0;
    if (i < count)
        for (; i < count; i++) {
            if (panel->x == gridX && panel->z == gridZ)
                func_021F3D04(fieldMap, i);
            panel++;
        }
    mmdl = func_0216DDC0(func_02188C7C(fieldMap), gridX, gridZ, 0);
    if (mmdl != 0 && func_0216D588(mmdl) == GIMMICK_D06_STONE_OBJ_ID)
        event = func_021F3958(fieldMap, mmdl, facingDir);
    return event;
}

/*
 * Create the event of a push on one stone. A stone that already touches a panel
 * is not pushed. Without a panel to reach the stone does not move.
 */
struct GameEvent *func_021F3958(struct FieldMap *fieldMap, struct Mmdl *stone, int direction)
{
    int steps;
    struct GameSystem *gameSystem;
    struct GameEvent *event;
    unsigned short i;
    struct Mmdl *mmdl;
    GimmickD06Work *work;
    GimmickD06StoneSlot *slot;
    GimmickD06SlideEvent *slide;

    work = func_021F3D6C(fieldMap);
    gameSystem = func_02188C80(fieldMap);
    for (i = 0; i < GIMMICK_D06_STONE_MAX; i++) {
        mmdl = work->stones[i].mmdl;
        if (mmdl == stone)
            break;
    }
    if (i >= GIMMICK_D06_STONE_MAX)
        i = 0;
    slot = &work->stones[i];
    if (func_021F3C98(work, slot) == 1)
        return 0;
    steps = func_021F3C84(work, slot, direction);
    if (steps == 0)
        event = func_020122C0(gameSystem, 0, func_021F3AB4, 0x10);
    else
        event = func_020122C0(gameSystem, 0, func_021F39F8, 0x10);
    slide = func_020124E8(event);
    func_02082C60(slide, 0, 0x10);
    slide->direction = direction;
    slide->work = work;
    slide->slotIndex = i;
    slide->slot = slot;
    slide->stepsLeft = steps;
    return event;
}

/*
 * Event: the stone slides to a panel. The player bumps against it, the stone
 * moves one tile per step and slows down at the end, then both stop.
 */
int func_021F39F8(struct GameEvent *event, int *seq, void *work)
{
    GimmickD06SlideEvent *slide = work;
    struct Mmdl *playerMmdl;

    playerMmdl = func_021A3074(func_02188CB4(slide->work->fieldMap));
    switch (*seq) {
    case 0:
        if (func_0216D3CC(playerMmdl) == 1) {
            func_0216D410(playerMmdl, func_02197E7C(slide->direction, GIMMICK_D06_ACMD_PLAYER_BUMP));
            func_020061E4(GIMMICK_D06_SE_PUSH_START);
            *seq = *seq + 1;
        }
        break;
    case 1:
        if (func_0216D3CC(slide->slot->mmdl) == 1) {
            if (slide->stepsLeft > 0) {
                int acmdBase = GIMMICK_D06_ACMD_SLIDE_FAST;
                if (slide->stepsLeft <= 1)
                    acmdBase = GIMMICK_D06_ACMD_SLIDE_SLOW;
                else if (slide->stepsLeft <= 2)
                    acmdBase = GIMMICK_D06_ACMD_SLIDE_SLOW;
                else if (slide->stepsLeft <= 4)
                    acmdBase = GIMMICK_D06_ACMD_SLIDE_MID;
                func_0216D410(slide->slot->mmdl, func_02197E7C(slide->direction, acmdBase));
                slide->stepsLeft = slide->stepsLeft - 1;
            } else {
                func_020061E4(GIMMICK_D06_SE_SLIDE_END);
                *seq = *seq + 1;
            }
        }
        break;
    case 2:
        if (func_0216D454(playerMmdl) == 1) {
            func_0216D480(slide->slot->mmdl);
            func_0216D480(playerMmdl);
            func_021C909C(slide->slot->follow);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Event: the stone cannot move. The player bumps against it and its effect
 * plays the ending. The first cases fall through on purpose.
 */
int func_021F3AB4(struct GameEvent *event, int *seq, void *work)
{
    GimmickD06SlideEvent *slide = work;
    struct Mmdl *playerMmdl;

    playerMmdl = func_021A3074(func_02188CB4(slide->work->fieldMap));
    switch (*seq) {
    case 0:
        if (func_0216D3CC(playerMmdl) == 1) {
            func_0216D410(playerMmdl, func_02197E7C(slide->direction, GIMMICK_D06_ACMD_PLAYER_BUMP));
            func_020061E4(GIMMICK_D06_SE_PUSH_BLOCKED);
            *seq = *seq + 1;
        }
    case 1:
        func_021C90AC(slide->slot->follow);
        *seq = *seq + 1;
        break;
    case 2:
        if (func_021C90D0(slide->slot->follow) == 0)
            break;
        *seq = *seq + 1;
    case 3:
        if (func_0216D454(playerMmdl) == 1) {
            func_0216D480(playerMmdl);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Create a stone at a cell and its follow effect. The effect freezes at once
 * when the stone already rests against a panel.
 */
void func_021F3B44(GimmickD06Work *work, GimmickD06StoneSlot *slot, int gridX, int gridZ)
{
    VecFx32 pos;

    slot->mmdl = func_021F3D38(work->fieldMap, gridX, gridZ);
    func_0216D88C(slot->mmdl, &pos);
    slot->follow = func_021C9064(func_02188CD0(work->fieldMap), &pos, slot->mmdl);
    if (func_021F3C98(work, slot) == 1)
        func_021C909C(slot->follow);
}

/*
 * Take over a stone object the map already holds, with a new follow effect.
 * note: two-byte alignment padding at 0x021F3BC2 follows the return.
 * note: func_021C9064's result is stored and read by caller; extern preserves r0 despite its void definition.
 */
void func_021F3B88(GimmickD06Work *work, GimmickD06StoneSlot *slot, struct Mmdl *mmdl)
{
    VecFx32 pos;

    slot->mmdl = mmdl;
    func_0216D88C(mmdl, &pos);
    slot->follow = func_021C9064(func_02188CD0(work->fieldMap), &pos, slot->mmdl);
    if (func_021F3C98(work, slot) == 1)
        func_021C909C(slot->follow);
}

/*
 * Look ahead from the stone, up to maxSteps tiles, in one direction. The scan
 * ends at the first tile that stops the stone; it reports 1 when that tile is
 * an electric panel, and then the number of tiles up to it in steps (0 when
 * the scan found no panel).
 */
int func_021F3BC4(GimmickD06Work *work, GimmickD06StoneSlot *slot, int direction, unsigned short maxSteps, unsigned int *steps)
{
    struct Mmdl *mmdl = slot->mmdl;
    unsigned short i = 0;
    VecFx32 vec;
    short gridX;
    short gridZ;
    int found = 0;
    struct G3dMapper *mapper;
    int gridY;
    int result;

    mapper = func_02188C98(work->fieldMap);
    gridX = func_0216D83C(mmdl);
    gridY = func_0216D854(mmdl);
    gridZ = func_0216D86C(mmdl);
    do {
        func_02164240(direction, &gridX, &gridZ, 1);
        result = func_02163994(mmdl, gridX, gridY, gridZ, direction) & ~GIMMICK_D06_MOVE_FAIL_IGNORED;
        if (result != 0) {
            if (result & GIMMICK_D06_MOVE_FAIL_TERRAIN) {
                func_02164280(gridX, gridZ, &vec);
                vec.y = func_0216D8AC(mmdl);
                result = func_021AB0D4(mapper, &vec);
                if (result != -1) {
                    if (func_021AB3F8(func_021AB0F0(result)) == 1)
                        found = 1;
                }
            }
            break;
        }
        i = i + 1;
    } while (i < maxSteps);
    if (found == 0)
        i = 0;
    *steps = i;
    return found;
}

/* Number of tiles the stone slides in a direction until it meets a panel (0 when it never does). */
int func_021F3C84(GimmickD06Work *work, GimmickD06StoneSlot *slot, int direction)
{
    unsigned int steps;

    func_021F3BC4(work, slot, direction, GIMMICK_D06_SLIDE_SCAN_MAX, &steps);
    return steps;
}

/* 1 when the stone rests against a panel in any of the four directions. */
int func_021F3C98(GimmickD06Work *work, GimmickD06StoneSlot *slot)
{
    unsigned short direction = 0;
    unsigned steps;

    do {
        if (func_021F3BC4(work, slot, direction, 1, &steps) == 1)
            return 1;
        direction++;
    } while (direction < 4);
    return 0;
}

/*
 * Start the pulse effect of one panel.
 * note: Original 021F3CFE stores r0 after 021C9258, whose filed void
 *       definition leaves its final call result live; caller uses unsigned.
 */
void func_021F3CCC(GimmickD06Work *work, struct FieldEffectObj **pulse, int gridX, int gridY, int gridZ)
{
    VecFx32 pos;

    func_02164280((short)gridX, (short)gridZ, &pos);
    pos.y = (int)(((unsigned)gridY << 16) + 0x8000u);
    *pulse = func_021C9258(func_02188CD0(work->fieldMap), &pos);
}

/* Trigger the pulse of one panel. */
void func_021F3D04(struct FieldMap *fieldMap, int panelIndex)
{
    struct GimmickWork *gimmickWork = func_02012EC4(func_020120F4(func_02188C80(fieldMap)));
    GimmickD06Work *work = func_0200B3A4(gimmickWork, func_021F3D94(func_02188C9C(fieldMap)))->work;

    func_021C928C(work->panelPulse[panelIndex]);
}

/* Add a stone object at a cell. */
struct Mmdl *func_021F3D38(struct FieldMap *fieldMap, int gridX, int gridZ)
{
    struct MmdlSys *mmdlSys = func_02188C7C(fieldMap);
    int zoneId = func_02188C9C(fieldMap);

    return func_0216CE6C(mmdlSys, gridX, gridZ, 0, GIMMICK_D06_STONE_OBJ_ID, 0, 0, zoneId);
}

/* The work of the gimmick of the current zone. */
GimmickD06Work *func_021F3D6C(struct FieldMap *fieldMap)
{
    struct GimmickWork *gimmickWork = func_02012EC4(func_020120F4(func_02188C80(fieldMap)));

    return func_0200B3A4(gimmickWork, func_021F3D94(func_02188C9C(fieldMap)))->work;
}
