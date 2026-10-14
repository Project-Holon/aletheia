/*
 * function: DWCi_ARClInit
 * address:  0x021D486C
 * packet:   pkt_ov016_021D486C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ARClInit (libdwcutil.TWL.HYB.a(archive.o))
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   FS_InitFile  0x020788AC  arm
 *   FS_OpenFile  0x02078C18  arm
 *   OS_Terminate  0x02088234  arm
 *   OS_GetLockID  0x02084EB8  arm
 *   FS_GetFileImageTop  0x0207A7BC  arm
 *   FS_ReadFile  0x02078B70  arm
 *   FS_CloseFile  0x02078A80  arm
 *   FS_InitArchive  0x02078360  arm
 *   FS_RegisterArchiveName  0x02078384  arm
 *   FS_SetArchiveProc  0x0207A5A8  arm
 *   FS_LoadArchive  0x0207A4B0  arm
 *   FS_LoadArchiveTables  0x0207A5C8  arm
 *   DWCi_QUElFormEx  0x021D5410  arm  ov016
 *   OS_SPrintf  0x02084F40  arm
 *   FS_ChangeDir  0x02078C34  arm
 *   func_021D4A94  0x021D4A94  arm  ov016
 *   func_021D4AFC  0x021D4AFC  arm  ov016
 *   DWCi_ARClCbWrite  0x021D4B60  arm  ov016
 *   gMemArchive  0x021DE66C  data
 *   sArchiveTable1  0x021DAA60  data
 *   @12216  0x021DBFB8  data
 *   @12217  0x021DBFD0  data
 *
 * notes:    the ABS32 pool word at 0x021D4A18 (cbWrite, 0x021D4B60) attests through the
 *           new symbols_sdk.json row and the seeded start (DWCi_ARClCbWrite, EXACT).
 */

typedef unsigned short u16;
typedef unsigned long u32;

typedef struct CARDRomRegion {
    u32 offset;
    u32 length;
} CARDRomRegion;

typedef struct FSFile {
    char pad[0x48];
} FSFile;

typedef struct FSArchive {
    char pad[0x5c];
} FSArchive;

typedef struct tagMEMARCHIVE {
    void *table;            /* +0x00 */
    void *file[32];         /* +0x04 */
    void *unused;           /* +0x84 */
    FSArchive archive;      /* +0x88 */
    u16 lockId;             /* +0xe4 */
} MEMARCHIVE;

extern MEMARCHIVE *gMemArchive;
extern char sArchiveTable1[4];

extern void *DWCi_HEAPlAllocEx(u32 size, int alignment);
extern void FS_InitFile(FSFile *file);
extern int FS_OpenFile(FSFile *file, const char *path);
extern void OS_Terminate(void);
extern long OS_GetLockID(void);
extern void *FS_GetFileImageTop(char *p);
extern long FS_ReadFile(FSFile *file, void *buffer, long length);
extern int FS_CloseFile(FSFile *file);
extern void FS_InitArchive(FSArchive *arc);
extern int FS_RegisterArchiveName(FSArchive *arc, const char *name, u32 name_len);
extern void FS_SetArchiveProc(FSArchive *arc, int (*proc)(FSFile *, u32), u32 flags);
extern int FS_LoadArchive(FSArchive *arc, u32 base, u32 fat, u32 fat_size, u32 fnt, u32 fnt_size,
                         int (*read_func)(FSArchive *, void *, u32, u32),
                         int (*write_func)(FSArchive *, void *, u32, u32));
extern u32 FS_LoadArchiveTables(FSArchive *arc, void *mem, u32 max_size);
extern void *DWCi_QUElFormEx(long size, void *data, long dataSize);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int FS_ChangeDir(const char *path);
extern int func_021D4A94(int unused, unsigned long cmd);
extern int func_021D4AFC(void *arc, void *dst, unsigned long pos, unsigned long size);
extern int DWCi_ARClCbWrite(void);

void DWCi_ARClInit(void)
{
    FSFile file;
    CARDRomRegion fnt;
    CARDRomRegion fat;
    u32 base;
    u32 size;
    int rs;
    char pass[128];

    gMemArchive = DWCi_HEAPlAllocEx(sizeof(MEMARCHIVE), 4);
    FS_InitFile(&file);
    if (!FS_OpenFile(&file, "rom:/dwc/utility.bin"))
        OS_Terminate();
    gMemArchive->lockId = OS_GetLockID();
    base = (u32)FS_GetFileImageTop((char *)(&file));
    FS_ReadFile(&file, &fnt, sizeof(fnt));
    FS_ReadFile(&file, &fat, sizeof(fat));
    FS_CloseFile(&file);
    FS_InitArchive(&gMemArchive->archive);
    if (!FS_RegisterArchiveName(&gMemArchive->archive, sArchiveTable1, 3))
        OS_Terminate();
    FS_SetArchiveProc(&gMemArchive->archive, (int (*)(FSFile *, u32))func_021D4A94, 0x602);
    if (!FS_LoadArchive(&gMemArchive->archive, base, fat.offset, fat.length, fnt.offset, fnt.length,
                       (int (*)(FSArchive *, void *, u32,  u32))func_021D4AFC, (int (*)(FSArchive *, void *, u32,  u32))DWCi_ARClCbWrite))
        OS_Terminate();
    size = FS_LoadArchiveTables(&gMemArchive->archive, 0, 0);
    gMemArchive->table = DWCi_HEAPlAllocEx(size, 4);
    rs = FS_LoadArchiveTables(&gMemArchive->archive, gMemArchive->table, size);
    gMemArchive->unused = DWCi_QUElFormEx(32, gMemArchive->file, 4);
    OS_SPrintf(pass, "%s:/", sArchiveTable1);
    FS_ChangeDir(pass);
}
