/*
 * function: MBi_ReadIconInfo
 * address:  0x021F3DF4
 * packet:   pkt_ov107_021F3DF4
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_ReadIconInfo (libmb.TWL.HYB.a(mb_gameinfo.o))
 *
 * symbols:
 *   FS_InitFile  0x020788AC  arm
 *   func_020789FC  0x020789FC  arm
 *   func_02078A94  0x02078A94  arm
 *   FS_CloseFile  0x02078A80  arm
 *   FS_ReadFile  0x02078B70  arm
 */

typedef struct {
    unsigned char b[0x48];
} FSFile;

extern void FS_InitFile(FSFile *file);
typedef signed int     s32;
typedef unsigned int   u32;
struct FSFile;
extern int func_020789FC(struct FSFile *file, const char *path, u32 mode);
extern u32 func_02078A94(struct FSFile *file);
extern int FS_CloseFile(FSFile *file);
extern s32 FS_ReadFile(struct FSFile *file, void *buffer, s32 length);

int MBi_ReadIconInfo(char *filePathp, unsigned char *iconp, int char_flag)
{
    FSFile file;
    long size;

    if (char_flag)
        size = 0x200;
    else
        size = 0x20;
    if (char_flag)
        iconp += 0x20;
    if (filePathp == 0)
        return 0;
    FS_InitFile(&file);
    if (!func_020789FC((struct FSFile *)(&file), filePathp, 1))
        return 0;
    if (size != func_02078A94((struct FSFile *)(&file))) {
        FS_CloseFile(&file);
        return 0;
    }
    FS_ReadFile((struct FSFile *)(&file), iconp, size);
    FS_CloseFile(&file);
    return 1;
}
