/*
 * file:     archive.c
 * unit:     yes
 * function: DWCi_ARClInit, DWCi_ARClEnd, userProc, cbRead, cbReadRom, DWCi_ARClCbWrite, DWCi_ARClReadEx, DWCi_ARClRelease, cmpBack
 * address:  0x021D486C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      cbWrite (libdwcutil.TWL.HYB.a(archive.o))
 * notes:    `mov r0, #1; bx lr`; DWCi_ARClInit's relocation at +0x1AC (ABS32 cbWrite)
 *           is the pool word at 0x021D4A18.  Seeded in layout/function_starts.txt.
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
 *   sArchiveTable1  0x021DAA60  data
 *   FS_UnloadArchiveTables         0x0207A708  arm
 *   FS_UnloadArchive               0x0207A51C  arm
 *   FS_ReleaseArchiveName          0x02078484  arm
 *   OS_ReleaseLockID               0x02084F10  arm
 *   DWCi_HEAPlFree_                0x021D6438  arm ov016
 *   MemArchive                     0x021DE66C  data
 *   MemArchive_b                   0x021DE66C  data
 *   CARD_LockRom  0x02075E10  arm
 *   CARD_UnlockRom  0x02075E80  arm
 *   FS_GetArchiveBase  0x0207A78C  arm
 *   CARDi_ReadRom  0x020771B4  arm
 *   cbReadRom  0x021D4B50  arm  ov016
 *   FS_NotifyArchiveAsyncEnd     0x02078734  arm
 *   @12216  0x021DBFB8  data
 *   @12217  0x021DBFD0  data
 *   @12219                         0x021DBFD8  data
 *   DWCi_QUElPopBack  0x021D54C4  arm  ov016
 *   FS_GetLength  0x02078C28  arm
 *   MI_UncompressLZ8  0x020834C0  arm
 *   sArchiveTable2  0x021DBFE0  data
 *   DWCi_QUElPushBack  0x021D546C  arm  ov016
 *   strlen  0x0209477C  arm
 *   memcmp  0x020923F0  arm
 */
#define DWCi_HEAPlFree(p) DWCi_HEAPlFree_((void **)&(p))
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
    void *queue;            /* +0x84 */
    FSArchive archive;      /* +0x88 */
    u16 lockId;             /* +0xe4 */
} MEMARCHIVE;

typedef unsigned char  u8;

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
extern void *FS_UnloadArchiveTables(FSArchive *arc);
extern int FS_UnloadArchive(FSArchive *arc);
extern void FS_ReleaseArchiveName(FSArchive *p_arc);
extern void OS_ReleaseLockID(unsigned short lockID);
extern void DWCi_HEAPlFree_(void **mem);
extern void CARD_LockRom(u16 lock_id);
extern void CARD_UnlockRom(u32 id);
extern void *FS_GetArchiveBase(void *arc);
extern void CARDi_ReadRom(unsigned int dma, void *src, void *dst, unsigned int len, void (*cb)(void *), void *arg, int is_async);
extern void FS_NotifyArchiveAsyncEnd(struct FSArchive *arc, int ret);
extern void *DWCi_QUElPopBack(void *queue);
extern u32 FS_GetLength(FSFile *file);
extern void MI_UncompressLZ8(void *src, void *dst);
extern void DWCi_QUElPushBack(void *que, void *elem);
extern int strlen(const u8 *s);
extern int memcmp(u8 *s1, u8 *s2, u32 n);
void DWCi_ARClInit(void);
void DWCi_ARClEnd(void);
int DWCi_ARClCbWrite(void);
void *DWCi_ARClReadEx(char *path, unsigned long *size, int alignment);
void DWCi_ARClRelease(void *file);
extern char sArchiveTable1[4];
extern MEMARCHIVE *MemArchive;
extern MEMARCHIVE *MemArchive_b;
extern char sArchiveTable2[];


/*
 * sdk:      DWCi_ARClInit (libdwcutil.TWL.HYB.a(archive.o))
 *
 * notes:    the ABS32 pool word at 0x021D4A18 (cbWrite, 0x021D4B60) attests through the
 *           new symbols_sdk.json row and the seeded start (DWCi_ARClCbWrite, EXACT).
 */

static int userProc(int unused, unsigned long cmd);
static int cbRead(void *arc, void *dst, unsigned long pos, unsigned long size);
static void cbReadRom(void *arc);
static int cmpBack(char *str0, char *str1, int n);
void DWCi_ARClInit(void)
{
    FSFile file;
    CARDRomRegion fnt;
    CARDRomRegion fat;
    u32 base;
    u32 size;
    int rs;
    char pass[128];

    MemArchive = DWCi_HEAPlAllocEx(sizeof(MEMARCHIVE), 4);
    FS_InitFile(&file);
    if (!FS_OpenFile(&file, "rom:/dwc/utility.bin"))
        OS_Terminate();
    MemArchive->lockId = OS_GetLockID();
    base = (u32)FS_GetFileImageTop((char *)(&file));
    FS_ReadFile(&file, &fnt, sizeof(fnt));
    FS_ReadFile(&file, &fat, sizeof(fat));
    FS_CloseFile(&file);
    FS_InitArchive(&MemArchive->archive);
    if (!FS_RegisterArchiveName(&MemArchive->archive, sArchiveTable1, 3))
        OS_Terminate();
    FS_SetArchiveProc(&MemArchive->archive, (int (*)(FSFile *, u32))userProc, 0x602);
    if (!FS_LoadArchive(&MemArchive->archive, base, fat.offset, fat.length, fnt.offset, fnt.length,
                       (int (*)(FSArchive *, void *, u32,  u32))cbRead, (int (*)(FSArchive *, void *, u32,  u32))DWCi_ARClCbWrite))
        OS_Terminate();
    size = FS_LoadArchiveTables(&MemArchive->archive, 0, 0);
    MemArchive->table = DWCi_HEAPlAllocEx(size, 4);
    rs = FS_LoadArchiveTables(&MemArchive->archive, MemArchive->table, size);
    MemArchive->queue = DWCi_QUElFormEx(32, MemArchive->file, 4);
    OS_SPrintf(pass, "%s:/", sArchiveTable1);
    FS_ChangeDir(pass);
}


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


static int userProc(int unused, unsigned long cmd)
{
	switch (cmd) {
	case 9:
		CARD_LockRom(MemArchive->lockId);
		return 0;
	case 10:
		CARD_UnlockRom(MemArchive->lockId);
		return 0;
	case 1:
		return 4;
	default:
		return 0x102;
	}
}


static int cbRead(void *arc, void *dst, unsigned long pos, unsigned long size)
{
	unsigned long base = (unsigned int)FS_GetArchiveBase(arc);
	CARDi_ReadRom(-1, (void *)(pos + base), dst, size, cbReadRom, arc, 1);
	return 0x100;
}


static void cbReadRom(void *arc)
{
    FS_NotifyArchiveAsyncEnd(arc, 0);
}

int DWCi_ARClCbWrite(void)
{
    return 1;
}


/*
 * sdk:      DWCi_ARClReadEx (libdwcutil.TWL.HYB.a archive.o)
 */
void *DWCi_ARClReadEx(char *path, unsigned long *size, int alignment)
{
    unsigned long siz;
    int align;
    FSFile file;
    void *fle;
    void *buf;

    DWCi_QUElPopBack(MemArchive->queue);
    FS_InitFile(&file);
    if (!FS_OpenFile(&file, path))
        OS_Terminate();
    siz = FS_GetLength(&file);
    if (size)
        *size = siz;
    if (cmpBack(path, sArchiveTable2, 2))
        align = -4;
    else
        align = alignment;
    buf = DWCi_HEAPlAllocEx(siz, align);
    FS_ReadFile(&file, buf, siz);
    FS_CloseFile(&file);
    if (align > 0)
        return buf;
    siz = *(unsigned long *)buf >> 8;
    if (size)
        *size = siz;
    fle = DWCi_HEAPlAllocEx(siz, alignment);
    MI_UncompressLZ8(buf, fle);
    DWCi_HEAPlFree_(&buf);
    return fle;
}


/*
 * sdk:      DWCi_ARClRelease (libdwcutil.TWL.HYB.a(archive.o))
 */
void DWCi_ARClRelease(void *file)
{
	DWCi_HEAPlFree_(&file);
	DWCi_QUElPushBack(MemArchive->queue, file);
}


/*
 * sdk:      cmpBack (libdwcutil.TWL.HYB.a(archive.o))
 */
static int cmpBack(char *str0, char *str1, int n)
{
	int len0;
	int len1;
	int rs;
	len0 = strlen((const u8 *)str0);
	len1 = strlen((const u8 *)str1);
	if (len0 < n || len1 < n)
		return 0;
	rs = memcmp((u8 *)(str0 + (len0 - n)), (u8 *)(str1 + (len1 - n)), n);
	return rs == 0;
}
