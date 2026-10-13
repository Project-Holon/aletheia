/*
 * function: BACKUP_SYSTEM_InitLinkedSave
 * address:  0x02031C10
 * packet:   pkt_0203195C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_InitLinkedSave.c \\
 *       --func BACKUP_SYSTEM_InitLinkedSave --addr 0x02031C10 --arm --cc 1.1p1
 *
 * symbols:
 *   BACKUP_SYSTEM_InitSaveSeq  0x02032970  arm
 *   BACKUP_SYSTEM_CancelSaveSeq  0x020331D0  arm
 */
#include "../include/Obj08815.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct SaveBackup;
extern void BACKUP_SYSTEM_InitSaveSeq(struct SaveBackup *p, u32 flag);
extern void BACKUP_SYSTEM_CancelSaveSeq(struct SaveBackup *p);

void BACKUP_SYSTEM_InitLinkedSave(u8 *a, u8 *b, u32 v)
{
    ((struct Obj08815 *)a)->f20 = v;
    a[0x1e] = 0;
    a[0x1f] = 2;
    b[0x1e] = 0;
    b[0x1f] = 2;
}
