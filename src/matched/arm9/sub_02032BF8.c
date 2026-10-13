/*
 * function: BACKUP_SYSTEM_WriteRecord
 * address:  0x02032BF8
 * packet:   pkt_020328E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BACKUP_SYSTEM_GetRecordWork  0x020319A4  arm
 *   BACKUP_SYSTEM_GetAreaAddr  0x02031EAC  arm
 *   BACKUP_SYSTEM_GetCrcTable  0x02031ECC  arm
 *   BACKUP_SYSTEM_UpdateRecordCrc  0x020332A4  arm
 *   SAVEDATA_GetBlockOffset  0x02033B68  arm
 *   SAVEDATA_GetBlockSize  0x02033BAC  arm
 *   FLASH_ACCESS_StartWrite  0x020336B8  arm
 *   unk_02146994   0x02146994  data
 *
 * savedata.c.  Commits one record of a backup generation: refresh the
 * record's CRC through BACKUP_SYSTEM_UpdateRecordCrc (src/matched/BACKUP_SYSTEM_UpdateRecordCrc.c) and file
 * it in the halfword table 0x02031ECC owns, then write the record itself,
 * four bytes longer than its payload, to the Flash offset that 0x02031EAC
 * and 0x02033B68 name between them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_WriteRecord.c \
 *       --func BACKUP_SYSTEM_WriteRecord --addr 0x02032BF8 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct SaveBackup {
    u8 pad00[0x2C];
    u32 unk2C;
};

extern struct { u8 pad000[0x208]; u32 unk208; } *unk_02146994;

extern u32 BACKUP_SYSTEM_GetRecordWork(u8 *p, u32 id);
extern u32 BACKUP_SYSTEM_GetAreaAddr(u32 *p, u32 sel);
extern int BACKUP_SYSTEM_GetCrcTable(int p0);
extern u16 BACKUP_SYSTEM_UpdateRecordCrc(struct SaveBackup *p, u32 id);
extern u32 SAVEDATA_GetBlockOffset(u8 *p, u32 i);
extern u32 SAVEDATA_GetBlockSize(u8 *p, u32 i);
extern int FLASH_ACCESS_StartWrite(u32 a0, u32 a1, u32 a2, void *a3);

void BACKUP_SYSTEM_WriteRecord(struct SaveBackup *p, u32 id, u32 x)
{
    u16 *tbl;
    u32 base;
    u32 off;
    u32 len;
    u32 src;

    tbl = (u16 *)BACKUP_SYSTEM_GetCrcTable((int)p);
    tbl[id] = BACKUP_SYSTEM_UpdateRecordCrc(p, id);
    base = BACKUP_SYSTEM_GetAreaAddr((u32 *)p, x);
    off = SAVEDATA_GetBlockOffset((u8 *)p->unk2C, id);
    len = SAVEDATA_GetBlockSize((u8 *)p->unk2C, id);
    src = BACKUP_SYSTEM_GetRecordWork((u8 *)p, id);
    FLASH_ACCESS_StartWrite(base + off, src, len + 4, (void *)unk_02146994->unk208);
}
