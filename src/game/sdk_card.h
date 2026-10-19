#ifndef GAME_SDK_CARD_H
#define GAME_SDK_CARD_H

#include "types.h"

/*
 * Card access layer of the SDK: backup device description, ROM region
 * and the target of a card command.
 */

typedef enum CARDBackupType {
    CARD_BACKUP_TYPE_NOT_USE = 0
} CARDBackupType;

typedef struct CARDBackupTypeInfo
{
    u32 total_size;
    u32 sect_size;
    u32 subsect_size;
    u32 page_size;
    u32 addr_width;
    u32 program_page;
    u32 write_page;
    u32 write_page_total;
    u32 erase_chip;
    u32 erase_chip_total;
    u32 erase_sector;
    u32 erase_sector_total;
    u32 erase_subsector;
    u32 erase_subsector_total;
    u32 erase_page;
    u8 initial_status;
    u8 padding1[3];
    u32 caps;
    u8 padding2[4];
} CARDBackupTypeInfo;

typedef struct CARDRomRegion
{
    u32 offset;
    u32 length;
} CARDRomRegion;

typedef enum CARDTarget
{
    CARD_TARGET_NONE,
    CARD_TARGET_ROM,
    CARD_TARGET_BACKUP
} CARDTarget;

#endif
