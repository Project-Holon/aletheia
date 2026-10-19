/*
 * file:     system_data.c
 * unit:     yes
 * function: SYSTEM_DATA_GetSize, SYSTEM_DATA_Init, SYSTEM_DATA_GetMyStatus, SYSTEM_DATA_GetConfig, SYSTEM_DATA_GetPlayTime, SYSTEM_DATA_IsActive, SYSTEM_DATA_SetActive, SYSTEM_DATA_ClearActive, SYSTEM_DATA_IsMarked, SYSTEM_DATA_SetMark, SYSTEM_DATA_ClearMark, SYSTEM_DATA_GetWordSlot, SYSTEM_DATA_SetMyStatus, SYSTEM_DATA_CopyMyStatus
 * address:  0x02008700
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from playtime.c by tools/splitfile.py.
 *
 * symbols:
 *   MIi_CpuClear32  0x02082A7C  arm
 *   PLAYTIME_Init    0x020085A0  thumb
 *   SAVE_CONTROL_GetBlock    0x020071CC  thumb
 *   CONFIG_Init 0x02008320 thumb arm9
 *   MYSTATUS_Init 0x020084A0 thumb arm9
 */
#include "config_shared_types.h"
#include "playtime_shared_types.h"

/* Save block 0x1B, 0x68 bytes. */
struct SystemData {
    struct Config config;
    struct MyStatus mystatus;
    struct PlayTime playtime;
    u8  active;
    u8  reserved2D[3];
    u16 marks[10];      /* each 0 or 0xC21E */
    u32 words[9];
};

/* The carrier a MyStatus is copied to and from, 0x20 bytes into a larger record. */
struct MyStatusHolder {
    u8 head[0x20];
    struct MyStatus mystatus;
};

#define BLOCK_ID_1B 0x1B

extern void MIi_CpuClear32(u32 data, void *dest, u32 size);

/* Save-block lookup: returns the block with the given id. */
extern void *SAVE_CONTROL_GetBlock(void *save, u32 id);

void CONFIG_Init(struct Config *config);

void MYSTATUS_Init(struct MyStatus *mystatus);

void PLAYTIME_Init(struct PlayTime *playtime);

/*
 * Save block 0x1B.  Every accessor reaches the block with
 * SAVE_CONTROL_GetBlock(save, 0x1B).  The block holds a Config, a MyStatus and a
 * PlayTime, then a flag byte, a table of marks and a table of words.
 *
 * SYSTEM_DATA_SetMyStatus and SYSTEM_DATA_CopyMyStatus copy the 0x20-byte MyStatus with four ldm/stm
 * pairs: mwccarm inlines an aggregate copy of this size, using the padded
 * sizeof (0x20).  SYSTEM_DATA_GetConfig is a tail call through a pool word with the
 * second argument set up first.
 */
u32 SYSTEM_DATA_GetSize(void)
{
    return sizeof(struct SystemData);
}

void SYSTEM_DATA_Init(struct SystemData *sys_data)
{
    MIi_CpuClear32(0, sys_data, sizeof(struct SystemData));
    CONFIG_Init(&sys_data->config);
    MYSTATUS_Init(&sys_data->mystatus);
    PLAYTIME_Init(&sys_data->playtime);
    sys_data->active = 0;
}

struct MyStatus *SYSTEM_DATA_GetMyStatus(void *save)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    return &sys_data->mystatus;
}

struct Config *SYSTEM_DATA_GetConfig(void *save)
{
    return SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
}

struct PlayTime *SYSTEM_DATA_GetPlayTime(void *save)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    return &sys_data->playtime;
}

u8 SYSTEM_DATA_IsActive(void *save)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    return sys_data->active;
}

void SYSTEM_DATA_SetActive(void *save)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    sys_data->active = 1;
}

void SYSTEM_DATA_ClearActive(void *save)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    sys_data->active = 0;
}

int SYSTEM_DATA_IsMarked(void *save, u32 index)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    if (sys_data->marks[index] == 0xC21E) {
        return 1;
    }
    return 0;
}

void SYSTEM_DATA_SetMark(void *save, u32 index)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    sys_data->marks[index] = 0xC21E;
}

void SYSTEM_DATA_ClearMark(void *save, u32 index)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    sys_data->marks[index] = 0;
}

u32 *SYSTEM_DATA_GetWordSlot(void *save, u32 index)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    return &sys_data->words[index];
}

void SYSTEM_DATA_SetMyStatus(void *save, const struct MyStatusHolder *src)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    sys_data->mystatus = src->mystatus;
}

void SYSTEM_DATA_CopyMyStatus(void *save, struct MyStatusHolder *dest)
{
    struct SystemData *sys_data = SAVE_CONTROL_GetBlock(save, BLOCK_ID_1B);
    dest->mystatus = sys_data->mystatus;
}
