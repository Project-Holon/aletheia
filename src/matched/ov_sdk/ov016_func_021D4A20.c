/*
 * function: DWCi_ARClEnd
 * address:  0x021D4A20
 * packet:   pkt_ov016_021D4A20
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ARClEnd (libdwcutil.TWL.HYB.a(archive.o))
 *
 * The vendor pools MemArchive twice (+0x6C, +0x70); the second word is spelled
 * through the alias MemArchive_b at the same address (w6_nm).
 *
 * symbols:
 *   FS_ChangeDir                   0x02078C34  arm
 *   FS_UnloadArchiveTables         0x0207A708  arm
 *   FS_UnloadArchive               0x0207A51C  arm
 *   FS_ReleaseArchiveName          0x02078484  arm
 *   OS_ReleaseLockID               0x02084F10  arm
 *   DWCi_HEAPlFree_                0x021D6438  arm ov016
 *   @12219                         0x021DBFD8  data
 *   MemArchive                     0x021DE66C  data
 *   MemArchive_b                   0x021DE66C  data
 */

struct FSArchive {
    char b[0x5c];
};

struct tagMEMARCHIVE {
    void *table;
    void *file[32];
    void *unused;
    struct FSArchive archive;
    unsigned short lockId;
};

extern void FS_ChangeDir(const char *path);
extern void *FS_UnloadArchiveTables(struct FSArchive *arc);
extern int FS_UnloadArchive(struct FSArchive *arc);
extern void FS_ReleaseArchiveName(struct FSArchive *p_arc);
extern void OS_ReleaseLockID(unsigned short lockID);
extern void DWCi_HEAPlFree_(void **mem);

extern struct tagMEMARCHIVE *MemArchive;
extern struct tagMEMARCHIVE *MemArchive_b;

#define DWCi_HEAPlFree(p) DWCi_HEAPlFree_((void **)&(p))

void DWCi_ARClEnd(void)
{
    FS_ChangeDir("rom:/");
    FS_UnloadArchiveTables(&MemArchive->archive);
    FS_UnloadArchive(&MemArchive->archive);
    FS_ReleaseArchiveName(&MemArchive->archive);
    OS_ReleaseLockID(MemArchive->lockId);
    MemArchive->lockId = 0;
    DWCi_HEAPlFree(MemArchive->table);
    MemArchive->table = 0;
    DWCi_HEAPlFree(MemArchive_b);
}
