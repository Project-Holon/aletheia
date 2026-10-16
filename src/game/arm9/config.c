/*
 * file:     config.c
 * unit:     yes
 * function: CONFIG_InitKeyControlTable, CONFIG_Create, CONFIG_Copy, CONFIG_Init, CONFIG_GetTextSpeed, CONFIG_SetTextSpeed, CONFIG_GetSoundMode, CONFIG_SetSoundMode, CONFIG_GetBattleScene, CONFIG_SetBattleScene, CONFIG_GetBattleStyle, CONFIG_SetBattleStyle, CONFIG_GetAppliedFlag, CONFIG_SetAppliedFlag, CONFIG_ApplyAppliedFlag, CONFIG_GetButtonMode, CONFIG_SetButtonMode, CONFIG_GetBattleFlag, CONFIG_SetBattleFlag, MYSTATUS_GetSize
 * address:  0x020082DC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from config.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc      0x02030734  arm
 *   g_save_block_table      0x0209DD64  data
 *   config_file_name      0x020A70A0  data
 *   func_020461D4  0x020461D4  arm
 *   MI_CpuCopy8         0x02082D44  arm
 *   MI_CpuFill8   0x02082BCC  arm
 *   KEY_SetControlModeTable  0x020362A4  arm
 */
#include "config_shared_types.h"

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

/* The debug allocator: heap, size, clear, __FILE__ string, __LINE__. */
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void KEY_SetControlModeTable(const void *arg);

extern u8 func_020461D4(u32 flag);

extern char g_save_block_table[];

extern char config_file_name[];

void CONFIG_Init(struct Config *config);

void CONFIG_InitKeyControlTable(void)
{
    KEY_SetControlModeTable(g_save_block_table);
}

void *CONFIG_Create(int heap_id)
{
    struct Config *config = GFL_HEAP_Alloc((u16)heap_id, sizeof(struct Config), 0, config_file_name, 0x4d);
    CONFIG_Init(config);
    return config;
}

void CONFIG_Copy(const struct Config *src, struct Config *dest)
{
    MI_CpuCopy8(src, dest, sizeof(struct Config));
}

void CONFIG_Init(struct Config *config)
{
    MI_CpuFill8(config, 0, sizeof(struct Config));
    config->text_speed = 1;
    config->sound_mode = 0;
    config->battle_style    = 0;
    config->battle_scene    = 0;
    config->applied_flag    = 0;
    config->button_mode    = 1;
    config->battle_flag   = 0;
}

unsigned int CONFIG_GetTextSpeed(const struct Config *config)
{
    return config->text_speed;
}

void CONFIG_SetTextSpeed(struct Config *config, unsigned int value)
{
    config->text_speed = (u16)value;
}

unsigned int CONFIG_GetSoundMode(const struct Config *config)
{
    return config->sound_mode;
}

void CONFIG_SetSoundMode(struct Config *config, unsigned int value)
{
    config->sound_mode = (u16)value;
}

unsigned int CONFIG_GetBattleScene(const struct Config *config)
{
    return config->battle_scene;
}

void CONFIG_SetBattleScene(struct Config *config, unsigned int value)
{
    config->battle_scene = (u16)value;
}

unsigned int CONFIG_GetBattleStyle(const struct Config *config)
{
    return config->battle_style;
}

void CONFIG_SetBattleStyle(struct Config *config, unsigned int value)
{
    config->battle_style = (u16)value;
}

int CONFIG_GetAppliedFlag(const struct Config *config)
{
    return config->applied_flag;
}

/* Sets applied_flag from the low bit of value, then passes the stored flag to
 * func_020461D4. */
void CONFIG_SetAppliedFlag(struct Config *config, unsigned int value)
{
    config->applied_flag = (u16)value;

    func_020461D4((u8)config->applied_flag);
}

/* Calls func_020461D4 with applied_flag as it stands. */
u8 CONFIG_ApplyAppliedFlag(const struct Config *config)
{
    return func_020461D4((u8)config->applied_flag);
}

int CONFIG_GetButtonMode(const struct Config *config)
{
    return config->button_mode;
}

void CONFIG_SetButtonMode(struct Config *config, unsigned int value)
{
    config->button_mode = (u16)value;
}

unsigned int CONFIG_GetBattleFlag(const struct Config *config)
{
    return config->battle_flag;
}

void CONFIG_SetBattleFlag(struct Config *config, int enabled)
{
    config->battle_flag = (u16)enabled;
}

int MYSTATUS_GetSize(void)
{
    return sizeof(struct MyStatus);
}
