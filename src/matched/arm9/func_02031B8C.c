/*
 * function: BACKUP_SYSTEM_StartSave
 * address:  0x02031B8C
 * packet:   pkt_0203195C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_StartSave.c \\
 *       --func BACKUP_SYSTEM_StartSave --addr 0x02031B8C --arm --cc 1.1p1
 *
 * symbols:
 *   BACKUP_SYSTEM_InitSaveSeq  0x02032970  arm
 *   BACKUP_SYSTEM_CancelSaveSeq  0x020331D0  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct SaveBackup;
extern void BACKUP_SYSTEM_InitSaveSeq(struct SaveBackup *p, u32 flag);
struct SaveBackup;
extern void BACKUP_SYSTEM_CancelSaveSeq(struct SaveBackup *p);

void BACKUP_SYSTEM_StartSave(u8 *p)
{
    if (*(u32 *)(*(u32 *)0x02146994) != 0) {
        BACKUP_SYSTEM_InitSaveSeq((struct SaveBackup *)p, 1);
    }
}
