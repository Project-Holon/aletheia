/*
 * function: func_021F3DF4
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
 *   func_020788AC  0x020788AC  arm
 *   func_020789FC  0x020789FC  arm
 *   func_02078A94  0x02078A94  arm
 *   func_02078A80  0x02078A80  arm
 *   func_02078B70  0x02078B70  arm
 */

typedef struct {
    unsigned char b[0x48];
} FSFile;

extern void func_020788AC(FSFile *file);
typedef signed int     s32;
typedef unsigned int   u32;
struct FSFile;
extern int func_020789FC(struct FSFile *file, const char *path, u32 mode);
extern u32 func_02078A94(struct FSFile *file);
extern int func_02078A80(FSFile *file);
extern s32 func_02078B70(struct FSFile *file, void *buffer, s32 length);

int func_021F3DF4(char *filePathp, unsigned char *iconp, int char_flag)
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
    func_020788AC(&file);
    if (!func_020789FC((struct FSFile *)(&file), filePathp, 1))
        return 0;
    if (size != func_02078A94((struct FSFile *)(&file))) {
        func_02078A80(&file);
        return 0;
    }
    func_02078B70((struct FSFile *)(&file), iconp, size);
    func_02078A80(&file);
    return 1;
}
