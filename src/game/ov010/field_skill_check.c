/*
 * file:     field_skill_check.c
 * unit:     yes
 * function: func_02164480, func_021644C4
 * address:  0x02164480
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Field skill usability mask (guess).
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02028748  0x02028748  thumb
 *   func_02012B28  0x02012B28  thumb
 *   d_021714DC     0x021714DC  data
 */

struct GameData;
struct GameSystem;
struct PlayerWork;

#include "../ov021/fldmmdl_rail_types.h"
#include "fldmmdl_types.h"

typedef unsigned int u32;

/* Field skill use flags (0x18 bytes): bit i of usableMask set when field
 * skill i can be used now (func_021644C4). */
typedef struct FieldSkillUseFlags {
    u32 usableMask;     /* 0x00 */
    u32 playerObjCode;  /* 0x04 */
    u8 reserved[0x10];  /* 0x08: cleared, never read here */
} FieldSkillUseFlags;

typedef int (*SkillCheckHandler)(struct GameData *gameData, void *fieldMap, struct PlayerWork *player);

extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct PlayerWork *func_020127A4(struct GameData *gameData);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void func_02028748(FieldSkillUseFlags *flags, int skillIndex, int usable);
extern u32 func_02012B28(const struct PlayerWork *player);
void func_02164480(FieldSkillUseFlags *flags, struct GameSystem *gameSystem, void *fieldMap);
int func_021644C4(int skillIndex, struct GameSystem *gameSystem, void *fieldMap);
extern SkillCheckHandler d_021714DC[];

void func_02164480(FieldSkillUseFlags *flags, struct GameSystem *gameSystem, void *fieldMap)
{
    struct PlayerWork *player;
    int i;

    player = func_020127A4(func_020120F4(gameSystem));
    MI_CpuFill8(flags, 0, sizeof(FieldSkillUseFlags));
    for (i = 0; i < 10; i++)
        func_02028748(flags, i, func_021644C4(i, gameSystem, fieldMap));
    flags->playerObjCode = func_02012B28(player);
}

/*
 * Calls entry i of the handler table at 0x021714DC, or returns 1 when the
 * slot is empty.
 */
int func_021644C4(int skillIndex, struct GameSystem *gameSystem, void *fieldMap)
{
    struct GameData *gameData;
    struct PlayerWork *player;
    SkillCheckHandler handler;

    gameData = func_020120F4(gameSystem);
    player = func_020127A4(gameData);
    handler = d_021714DC[skillIndex];
    if (handler == 0)
        return 1;
    return handler(gameData, fieldMap, player);
}
