/*
 * function: BACKUP_SYSTEM_CancelSave
 * address:  0x02031C04
 * packet:   pkt_0203195C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_CancelSave.c \\
 *       --func BACKUP_SYSTEM_CancelSave --addr 0x02031C04 --arm --cc 1.1p1
 *
 * symbols:
 *   BACKUP_SYSTEM_InitSaveSeq  0x02032970  arm
 *   BACKUP_SYSTEM_CancelSaveSeq  0x020331D0  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct SaveBackup;
extern void BACKUP_SYSTEM_InitSaveSeq(struct SaveBackup *p, u32 flag);
extern void BACKUP_SYSTEM_CancelSaveSeq(struct SaveBackup *p);

void BACKUP_SYSTEM_CancelSave(struct SaveBackup *a0)
{
    BACKUP_SYSTEM_CancelSaveSeq(a0);
}
