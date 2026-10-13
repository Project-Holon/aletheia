/*
 * function: func_021D486C
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
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_020788AC  0x020788AC  arm
 *   func_02078C18  0x02078C18  arm
 *   func_02088234  0x02088234  arm
 *   func_02084EB8  0x02084EB8  arm
 *   FS_GetFileImageTop  0x0207A7BC  arm
 *   func_02078B70  0x02078B70  arm
 *   func_02078A80  0x02078A80  arm
 *   func_02078360  0x02078360  arm
 *   func_02078384  0x02078384  arm
 *   func_0207A5A8  0x0207A5A8  arm
 *   func_0207A4B0  0x0207A4B0  arm
 *   func_0207A5C8  0x0207A5C8  arm
 *   func_021D5410  0x021D5410  arm  ov016
 *   func_02084F40  0x02084F40  arm
 *   func_02078C34  0x02078C34  arm
 *   func_021D4A94  0x021D4A94  arm  ov016
 *   func_021D4AFC  0x021D4AFC  arm  ov016
 *   func_021D4B60  0x021D4B60  arm  ov016
 *   g_021DE66C  0x021DE66C  data
 *   g_021DAA60  0x021DAA60  data
 *   @12216  0x021DBFB8  data
 *   @12217  0x021DBFD0  data
 *
 * notes:    the ABS32 pool word at 0x021D4A18 (cbWrite, 0x021D4B60) attests through the
 *           new symbols_sdk.json row and the seeded start (func_021D4B60, EXACT).
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

extern MEMARCHIVE *g_021DE66C;
extern char g_021DAA60[4];

extern void *func_021D6414(u32 size, int alignment);
extern void func_020788AC(FSFile *file);
extern int func_02078C18(FSFile *file, const char *path);
extern void func_02088234(void);
extern long func_02084EB8(void);
extern void *FS_GetFileImageTop(char *p);
extern long func_02078B70(FSFile *file, void *buffer, long length);
extern int func_02078A80(FSFile *file);
extern void func_02078360(FSArchive *arc);
extern int func_02078384(FSArchive *arc, const char *name, u32 name_len);
extern void func_0207A5A8(FSArchive *arc, int (*proc)(FSFile *, u32), u32 flags);
extern int func_0207A4B0(FSArchive *arc, u32 base, u32 fat, u32 fat_size, u32 fnt, u32 fnt_size,
                         int (*read_func)(FSArchive *, void *, u32, u32),
                         int (*write_func)(FSArchive *, void *, u32, u32));
extern u32 func_0207A5C8(FSArchive *arc, void *mem, u32 max_size);
extern void *func_021D5410(long size, void *data, long dataSize);
extern int func_02084F40(char *dst, const char *fmt, ...);
extern int func_02078C34(const char *path);
extern int func_021D4A94(int unused, unsigned long cmd);
extern int func_021D4AFC(void *arc, void *dst, unsigned long pos, unsigned long size);
extern int func_021D4B60(void);

void func_021D486C(void)
{
    FSFile file;
    CARDRomRegion fnt;
    CARDRomRegion fat;
    u32 base;
    u32 size;
    int rs;
    char pass[128];

    g_021DE66C = func_021D6414(sizeof(MEMARCHIVE), 4);
    func_020788AC(&file);
    if (!func_02078C18(&file, "rom:/dwc/utility.bin"))
        func_02088234();
    g_021DE66C->lockId = func_02084EB8();
    base = (u32)FS_GetFileImageTop((char *)(&file));
    func_02078B70(&file, &fnt, sizeof(fnt));
    func_02078B70(&file, &fat, sizeof(fat));
    func_02078A80(&file);
    func_02078360(&g_021DE66C->archive);
    if (!func_02078384(&g_021DE66C->archive, g_021DAA60, 3))
        func_02088234();
    func_0207A5A8(&g_021DE66C->archive, (int (*)(FSFile *, u32))func_021D4A94, 0x602);
    if (!func_0207A4B0(&g_021DE66C->archive, base, fat.offset, fat.length, fnt.offset, fnt.length,
                       (int (*)(FSArchive *, void *, u32,  u32))func_021D4AFC, (int (*)(FSArchive *, void *, u32,  u32))func_021D4B60))
        func_02088234();
    size = func_0207A5C8(&g_021DE66C->archive, 0, 0);
    g_021DE66C->table = func_021D6414(size, 4);
    rs = func_0207A5C8(&g_021DE66C->archive, g_021DE66C->table, size);
    g_021DE66C->unused = func_021D5410(32, g_021DE66C->file, 4);
    func_02084F40(pass, "%s:/", g_021DAA60);
    func_02078C34(pass);
}
