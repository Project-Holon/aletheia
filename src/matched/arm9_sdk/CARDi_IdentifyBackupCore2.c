/*
 * function: CARDi_IdentifyBackupCore2
 * address:  0x020766D8
 * packet:   pkt_020766D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libcard card_backup.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Static in the vendor object: fills the command block's backup spec
 * (page, sector and address sizes, timings, capability bits) from a
 * CARDBackupType word, or marks the type unsupported.  Body as in the
 * vendor source (sdk/TwlSDK/build/libraries/card), comments dropped.
 *
 * symbols:
 *   MI_CpuFill8                      0x02082BCC  arm
 *   cardi_common                     0x02150200  data
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef enum CARDBackupType {
    CARD_BACKUP_TYPE_NOT_USE = 0
} CARDBackupType;

#define CARD_BACKUP_TYPE_DEVICE_SHIFT  0
#define CARD_BACKUP_TYPE_DEVICE_MASK   0xFF
#define CARD_BACKUP_TYPE_DEVICE_EEPROM 1
#define CARD_BACKUP_TYPE_DEVICE_FLASH  2
#define CARD_BACKUP_TYPE_DEVICE_FRAM   3
#define CARD_BACKUP_TYPE_SIZEBIT_SHIFT 8
#define CARD_BACKUP_TYPE_SIZEBIT_MASK  0xFF
#define CARD_BACKUP_TYPE_VENDER_SHIFT  16
#define CARD_BACKUP_TYPE_VENDER_MASK   0xFF

#define CARD_BACKUP_CAPS_AVAILABLE       0x003F
#define CARD_BACKUP_CAPS_READ            0x0040
#define CARD_BACKUP_CAPS_WRITE           0x0080
#define CARD_BACKUP_CAPS_PROGRAM         0x0100
#define CARD_BACKUP_CAPS_VERIFY          0x0200
#define CARD_BACKUP_CAPS_ERASE_PAGE      0x0400
#define CARD_BACKUP_CAPS_ERASE_SECTOR    0x0800
#define CARD_BACKUP_CAPS_ERASE_CHIP      0x1000
#define CARD_BACKUP_CAPS_READ_STATUS     0x2000
#define CARD_BACKUP_CAPS_WRITE_STATUS    0x4000
#define CARD_BACKUP_CAPS_ERASE_SUBSECTOR 0x8000

#define CARD_RESULT_UNSUPPORTED 3

typedef struct CARDBackupTypeInfo {
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

typedef struct CARDiCommandArg {
    int result;
    CARDBackupType type;
    u32 id;
    u32 src;
    u32 dst;
    u32 len;
    CARDBackupTypeInfo spec;
} CARDiCommandArg;

typedef struct CARDiCommon {
    CARDiCommandArg *cmd;
} CARDiCommon;

extern CARDiCommon cardi_common;

void MI_CpuFill8(void *dstp, u8 data, u32 size);

static void CARDi_IdentifyBackupCore2(CARDBackupType type)
{
    {
        CARDiCommandArg *const p = cardi_common.cmd;
        MI_CpuFill8(&p->spec, 0, sizeof(p->spec));
        p->type = type;
        p->spec.caps = (CARD_BACKUP_CAPS_AVAILABLE | CARD_BACKUP_CAPS_READ_STATUS);
        if (type != CARD_BACKUP_TYPE_NOT_USE)
        {
            const u32 size = (u32)(1 << ((type >> CARD_BACKUP_TYPE_SIZEBIT_SHIFT) &
                                         CARD_BACKUP_TYPE_SIZEBIT_MASK));
            const int device =
                ((type >> CARD_BACKUP_TYPE_DEVICE_SHIFT) & CARD_BACKUP_TYPE_DEVICE_MASK);
            const int vender =
                ((type >> CARD_BACKUP_TYPE_VENDER_SHIFT) & CARD_BACKUP_TYPE_VENDER_MASK);
            p->spec.total_size = size;
            p->spec.initial_status = 0xFF;
            if (device == CARD_BACKUP_TYPE_DEVICE_EEPROM)
            {
                switch (size)
                {
                default:
                    goto invalid_type;
                case 0x000200:
                    p->spec.page_size = 0x10;
                    p->spec.addr_width = 1;
                    p->spec.program_page = 5;
                    p->spec.initial_status = 0xF0;
                    break;
                case 0x002000:
                    p->spec.page_size = 0x0020;
                    p->spec.addr_width = 2;
                    p->spec.program_page = 5;
                    p->spec.initial_status = 0x00;
                    break;
                case 0x010000:
                    p->spec.page_size = 0x0080;
                    p->spec.addr_width = 2;
                    p->spec.program_page = 10;
                    p->spec.initial_status = 0x00;
                    break;
                case 0x020000:
                    p->spec.page_size = 0x0100;
                    p->spec.addr_width = 3;
                    p->spec.program_page = 5;
                    p->spec.initial_status = 0x00;
                    break;
                }
                p->spec.sect_size = p->spec.page_size;
                p->spec.caps |= CARD_BACKUP_CAPS_READ;
                p->spec.caps |= CARD_BACKUP_CAPS_PROGRAM;
                p->spec.caps |= CARD_BACKUP_CAPS_VERIFY;
                p->spec.caps |= CARD_BACKUP_CAPS_WRITE_STATUS;
            }
            else if (device == CARD_BACKUP_TYPE_DEVICE_FLASH)
            {
                switch (size)
                {
                default:
                    goto invalid_type;
                case 0x040000:
                case 0x080000:
                case 0x100000:
                    p->spec.write_page = 25;
                    p->spec.write_page_total = 300;
                    p->spec.erase_page = 300;
                    p->spec.erase_sector = 5000;
                    p->spec.caps |= CARD_BACKUP_CAPS_WRITE;
                    p->spec.caps |= CARD_BACKUP_CAPS_ERASE_PAGE;
                    break;
                case 0x200000:
                    p->spec.write_page = 23;
                    p->spec.write_page_total = 300;
                    p->spec.erase_sector = 500;
                    p->spec.erase_sector_total = 5000;
                    p->spec.erase_chip = 10000;
                    p->spec.erase_chip_total = 60000;
                    p->spec.initial_status = 0x00;
                    p->spec.caps |= CARD_BACKUP_CAPS_WRITE;
                    p->spec.caps |= CARD_BACKUP_CAPS_ERASE_PAGE;
                    p->spec.caps |= CARD_BACKUP_CAPS_ERASE_CHIP;
                    p->spec.caps |= CARD_BACKUP_CAPS_WRITE_STATUS;
                    break;
                case 0x400000:
                    p->spec.erase_sector = 600;
                    p->spec.erase_sector_total = 3000;
                    p->spec.erase_subsector = 70;
                    p->spec.erase_subsector_total = 150;
                    p->spec.erase_chip = 23000;
                    p->spec.erase_chip_total = 800000;
                    p->spec.initial_status = 0x00;
                    p->spec.subsect_size = 0x1000;
                    p->spec.caps |= CARD_BACKUP_CAPS_ERASE_SUBSECTOR;
                    p->spec.caps |= CARD_BACKUP_CAPS_ERASE_CHIP;
                    p->spec.caps |= CARD_BACKUP_CAPS_WRITE_STATUS;
                    break;
                case 0x800000:
                    if (vender == 0)
                    {
                        p->spec.erase_sector = 1000;
                        p->spec.erase_sector_total = 3000;
                        p->spec.erase_chip = 68000;
                        p->spec.erase_chip_total = 160000;
                        p->spec.initial_status = 0x00;
                        p->spec.caps |= CARD_BACKUP_CAPS_ERASE_CHIP;
                        p->spec.caps |= CARD_BACKUP_CAPS_WRITE_STATUS;
                    }
                    else if (vender == 1)
                    {
                        p->spec.erase_sector = 1000;
                        p->spec.erase_sector_total = 3000;
                        p->spec.erase_chip = 68000;
                        p->spec.erase_chip_total = 160000;
                        p->spec.initial_status = 0x84;
                        p->spec.caps |= CARD_BACKUP_CAPS_ERASE_CHIP;
                        p->spec.caps |= CARD_BACKUP_CAPS_WRITE_STATUS;
                    }
                    break;
                }
                p->spec.sect_size = 0x010000;
                p->spec.page_size = 0x0100;
                p->spec.addr_width = 3;
                p->spec.program_page = 5;
                p->spec.caps |= CARD_BACKUP_CAPS_READ;
                p->spec.caps |= CARD_BACKUP_CAPS_PROGRAM;
                p->spec.caps |= CARD_BACKUP_CAPS_VERIFY;
                p->spec.caps |= CARD_BACKUP_CAPS_ERASE_SECTOR;
            }
            else if (device == CARD_BACKUP_TYPE_DEVICE_FRAM)
            {
                switch (size)
                {
                default:
                    goto invalid_type;
                case 0x002000:
                case 0x008000:
                    break;
                }
                p->spec.page_size = size;
                p->spec.sect_size = size;
                p->spec.addr_width = 2;
                p->spec.initial_status = 0x00;
                p->spec.caps |= CARD_BACKUP_CAPS_READ;
                p->spec.caps |= CARD_BACKUP_CAPS_PROGRAM;
                p->spec.caps |= CARD_BACKUP_CAPS_VERIFY;
                p->spec.caps |= CARD_BACKUP_CAPS_WRITE_STATUS;
            }
            else
            {
              invalid_type:
                p->type = CARD_BACKUP_TYPE_NOT_USE;
                p->spec.total_size = 0;
                cardi_common.cmd->result = CARD_RESULT_UNSUPPORTED;
                return;
            }
        }
    }
}
