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

/* Cartridge ROM header (0x160 bytes, the DS part of the header). */
typedef struct CARDRomHeader
{
    char game_name[12];             /* 0x00 */
    u32 game_code;                  /* 0x0C */
    u16 maker_code;                 /* 0x10 */
    u8 product_id;                  /* 0x12 */
    u8 device_type;                 /* 0x13 */
    u8 game_size;                   /* 0x14 */
    u8 reserved_A[9];               /* 0x15 */
    u8 rom_version;                 /* 0x1E */
    u8 property;                    /* 0x1F */
    u32 main_rom_offset;            /* 0x20 */
    u32 main_entry_address;         /* 0x24 */
    u32 main_ram_address;           /* 0x28 */
    u32 main_size;                  /* 0x2C */
    u32 sub_rom_offset;             /* 0x30 */
    u32 sub_entry_address;          /* 0x34 */
    u32 sub_ram_address;            /* 0x38 */
    u32 sub_size;                   /* 0x3C */
    CARDRomRegion fnt;              /* 0x40 */
    CARDRomRegion fat;              /* 0x48 */
    CARDRomRegion main_ovt;         /* 0x50 */
    CARDRomRegion sub_ovt;          /* 0x58 */
    u32 game_cmd_param;             /* 0x60 */
    u32 secure_cmd_param;           /* 0x64 */
    u32 banner_offset;              /* 0x68 */
    u16 secure_area_crc;            /* 0x6C */
    u16 secure_cmd_latency;         /* 0x6E */
    u32 main_autoload_done;         /* 0x70 */
    u32 sub_autoload_done;          /* 0x74 */
    u8 secure_disable[8];           /* 0x78 */
    u32 rom_size;                   /* 0x80 */
    u32 header_size;                /* 0x84 */
    u8 reserved_B[10];              /* 0x88 */
    u16 twl_ltd_area_rom_offset;    /* 0x92 */
    u8 reserved_C[0x2C];            /* 0x94 */
    u8 logo_data[0x9C];             /* 0xC0 */
    u16 logo_crc;                   /* 0x15C */
    u16 header_crc;                 /* 0x15E */
} CARDRomHeader;

/* Cartridge ROM header with the TWL extension: only access_control is read. */
typedef struct CARDRomHeaderTWL
{
    CARDRomHeader ntr;              /* 0x000 */
    u8 twl_reserved[0x54];          /* 0x160 */
    struct
    {
        u32 keyAndSlotAccess : 5;
        u32 gameCardPowerOn : 1;
        u32 sharedFileAccess : 2;
        u32 gameCardNitroMode : 1;
        u32 sdAndPhotoAccess : 6;
        u32 backupAccess : 1;
        u32 romAccess : 1;
        u32 reserved : 15;
    } access_control;               /* 0x1B4 */
} CARDRomHeaderTWL;

typedef enum CARDTarget
{
    CARD_TARGET_NONE,
    CARD_TARGET_ROM,
    CARD_TARGET_BACKUP
} CARDTarget;

#endif
