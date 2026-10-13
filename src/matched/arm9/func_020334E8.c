/*
 * function: BACKUP_SYSTEM_ReadRecordFromFlash
 * address:  0x020334E8
 * packet:   pkt_020334E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   svsys    0x02146994  data
 *   BACKUP_SYSTEM_GetAreaAddr 0x02031EAC  arm
 *   SAVEDATA_GetBlockOffset 0x02033B68  arm
 *   FLASH_ACCESS_Read 0x020335E8  arm
 */
#include "../include/Obj15882.h"
#include "../include/G_SaveMain.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct SaveMain *svsys;
extern u32 BACKUP_SYSTEM_GetAreaAddr(u32 *p, u32 sel);
extern u32 SAVEDATA_GetBlockOffset(u8 *p, u32 i);
extern int FLASH_ACCESS_Read(u32 a0, u32 a1, u32 a2, void (*a3)(void));

int BACKUP_SYSTEM_ReadRecordFromFlash(u8 *p, u32 b, u32 c, u32 d, u32 e)
{
    u32 n = BACKUP_SYSTEM_GetAreaAddr((u32 *)p, c + 1);
    u32 m = SAVEDATA_GetBlockOffset(*(u8 * *)&((struct Obj15882 *)p)->f2C, b);

    return FLASH_ACCESS_Read(n + m, d, e, (void (*)(void))*(u32 *)(((u8 *)svsys) + 0x204));
}
