/*
 * function: BACKUP_SYSTEM_CalcCrcTableCrc
 * address:  0x02031E7C
 * packet:   pkt_02031C30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MATH_CalcCRC16CCITT  0x02081B8C  arm
 *   unk_02146994         0x02146994  data
 *
 * backup_system.c.  The CRC-16/CCITT of one backup record: the table is the
 * CRC table that lives inline at +4 of the object at 0x02146994 (the same
 * `struct { u8 pad000[4]; u8 crcTable[1]; }` shape src/matched/BACKUP_SYSTEM_UpdateRecordCrc.c
 * uses), the data starts at `buf + p->unk30 - 0x10 - p->unk140` and runs for
 * p->unk140 bytes.  The result is what src/matched/BACKUP_SYSTEM_CheckFooter.c compares
 * against the footer halfword and what src/matched/BACKUP_SYSTEM_SetFooter.c stores
 * into it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_CalcCrcTableCrc.c \
 *       --func BACKUP_SYSTEM_CalcCrcTableCrc --addr 0x02031E7C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct SaveBackup {
    u8  pad00[0x2C];
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u8  pad38[0x108];
    u32 unk140;
};

extern struct { u8 pad000[4]; u8 crcTable[1]; } *unk_02146994;
extern u16 MATH_CalcCRC16CCITT(const void *table, const void *data, u32 len);

u16 BACKUP_SYSTEM_CalcCrcTableCrc(struct SaveBackup *p, u8 *buf)
{
    return MATH_CalcCRC16CCITT(unk_02146994->crcTable,
                               buf + (p->unk30 - 0x10 - p->unk140),
                               p->unk140);
}
