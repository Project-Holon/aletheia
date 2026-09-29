/*
 * function: func_021D4A20
 * address:  0x021D4A20
 * packet:   pkt_ov016_021D4A20
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (3 bytes, 4 short)
 *
 * sdk:      DWCi_ARClEnd (libdwcutil.TWL.HYB.a(archive.o))
 *
 * blocker (w5_nm): the vendor pools MemArchive twice (+0x6C for the r4 base
 * and +0x70 for the last `&MemArchive` argument); 1.1p1 reuses r4 and emits one
 * word, so the image is 4 bytes longer and +0x58 differs.  MemArchive is a local
 * (static) data symbol of archive.o.  Tried: the DWCi_HEAPlFree(p) macro form
 * `DWCi_HEAPlFree_((void **)&(p))`, a direct cast, a pointer-to-pointer local,
 * extern vs static definition, and cc 1.2p2, 1.3p1, 1.6sp2, 2.0 sp2/sp1p2 (2.0
 * gives 132 B).  Not tried: a second extern name for the same address (the
 * duplicated-pool idiom); the vendor relocates both words against one name.
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

static struct tagMEMARCHIVE *MemArchive;

#define DWCi_HEAPlFree(p) DWCi_HEAPlFree_((void **)&(p))

void func_021D4A20(void)
{
    FS_ChangeDir("rom:/");
    FS_UnloadArchiveTables(&MemArchive->archive);
    FS_UnloadArchive(&MemArchive->archive);
    FS_ReleaseArchiveName(&MemArchive->archive);
    OS_ReleaseLockID(MemArchive->lockId);
    MemArchive->lockId = 0;
    DWCi_HEAPlFree(MemArchive->table);
    MemArchive->table = 0;
    DWCi_HEAPlFree(MemArchive);
}
