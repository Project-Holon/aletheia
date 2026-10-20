/*
 * file:     config.c
 * unit:     yes
 * function: CONFIG_InitKeyControlTable, CONFIG_Create, CONFIG_Copy, CONFIG_Init, CONFIG_GetTextSpeed, CONFIG_SetTextSpeed, CONFIG_GetSoundMode, CONFIG_SetSoundMode, CONFIG_GetBattleScene, CONFIG_SetBattleScene, CONFIG_GetBattleStyle, CONFIG_SetBattleStyle, CONFIG_GetTextLanguage, CONFIG_SetTextLanguage, CONFIG_ApplyTextLanguage, CONFIG_GetButtonMode, CONFIG_SetButtonMode, CONFIG_GetBattleFlag, CONFIG_SetBattleFlag, MYSTATUS_GetSize
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
 *   MSGDATA_SetLanguage  0x020461D4  arm
 *   MI_CpuCopy8         0x02082D44  arm
 *   MI_CpuFill8   0x02082BCC  arm
 *   KEY_SetControlModeTable  0x020362A4  arm
 */
#include "config_shared_types.h"

#include "mi_memory.h"


/* The debug allocator: heap, size, clear, __FILE__ string, __LINE__. */
#include "gfl_heap_wrap.h"

#include "key.h"

#include "msgdata.h"

extern char g_save_block_table[];

extern char config_file_name[];

void CONFIG_Init(struct Config *config);

void CONFIG_InitKeyControlTable(void)
{
    KEY_SetControlModeTable((const KeyConvEntry *)g_save_block_table);
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
    config->textLanguage    = 0;
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

int CONFIG_GetTextLanguage(const struct Config *config)
{
    return config->textLanguage;
}

/* Sets textLanguage from the low bit of value, then passes the stored flag to
 * MSGDATA_SetLanguage. */
void CONFIG_SetTextLanguage(struct Config *config, unsigned int value)
{
    config->textLanguage = (u16)value;

    MSGDATA_SetLanguage((u8)config->textLanguage);
}

/* Calls MSGDATA_SetLanguage with textLanguage as it stands. */
void CONFIG_ApplyTextLanguage(const struct Config *config)
{
    MSGDATA_SetLanguage((u8)config->textLanguage);
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
