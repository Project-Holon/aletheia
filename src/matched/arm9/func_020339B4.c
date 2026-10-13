/*
 * unit:     no
 * function: SAVEDATA_DeleteTable
 * address:  0x020339B4
 * packet:   pkt_02033908
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Destructor for one record: release the pointer held at +0x14, then the
 * record itself.  Both releases go through the overruled SDK address
 * 0x020307B0, which is already matched, so both PC24 sites attest on the
 * `matched` class.  This function is itself the only blocker for
 * src/matched/BACKUP_SYSTEM_Delete.c and the parked save-backup file
 * src/pending/BACKUP_SYSTEM_CancelSaveSeq.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SAVEDATA_DeleteTable.c \
 *       --func SAVEDATA_DeleteTable --addr 0x020339B4 --arm --cc 1.1p1
 */

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void SAVEDATA_DeleteTable(int *p)
{
    func_020307B0((void *)p[5]);
    func_020307B0(p);
}
