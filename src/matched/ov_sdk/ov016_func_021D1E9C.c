/*
 * function: func_021D1E9C
 * address:  0x021D1E9C
 * packet:   pkt_ov016_021D1E9C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOV_MBP_RegistFile (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 *
 * symbols:
 *   FS_InitFile                      0x020788AC  arm
 *   FS_OpenFile                      0x02078C18  arm
 *   MB_GetSegmentLength              0x021F2F1C  arm
 *   MB_ReadSegment                   0x021F2FA0  arm
 *   MB_RegisterFile                  0x021F3544  arm
 *   FS_CloseFile                     0x02078A80  arm
 *   g_021DE65C                       0x021DE65C  data
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct { u8 b[0x48]; } FSFile;

typedef struct {
    char *romFilePathp;
    u8 pad[0x38];
} MBGameRegistry;

typedef struct {
    u8 pad0[0x2c];
    u8 boot_seg_buf[0x10000];
    u8 pad1[0x10040 - 0x1002c];
    u32 work_area_for_mb[11328];
    u32 *sCWork;
    u8 *sFilebuf;
} Wb;

extern Wb *g_021DE65C;
extern void FS_InitFile(FSFile *file);
extern int FS_OpenFile(FSFile *file, char *path);
extern u32 MB_GetSegmentLength(FSFile *file);
extern int MB_ReadSegment(FSFile *file, void *buf, u32 len);
extern int MB_RegisterFile(MBGameRegistry *game_reg, void *buf);
extern int FS_CloseFile(FSFile *file);

int func_021D1E9C(MBGameRegistry *gameInfo)
{
    FSFile file;
    FSFile *p_file;
    u32 bufferSize;
    int ret = 0;

    if (!gameInfo->romFilePathp) {
        p_file = 0;
    } else {
        p_file = &file;
        FS_InitFile(p_file);
        if (!FS_OpenFile(p_file, gameInfo->romFilePathp))
            return 0;
    }
    bufferSize = MB_GetSegmentLength(p_file);
    if (bufferSize) {
        g_021DE65C->sFilebuf = g_021DE65C->boot_seg_buf;
        if (g_021DE65C->sFilebuf) {
            if (MB_ReadSegment(p_file, g_021DE65C->sFilebuf, 0x10000)) {
                if (MB_RegisterFile(gameInfo, g_021DE65C->sFilebuf))
                    ret = 1;
            }
        }
    }
    if (p_file == &file)
        FS_CloseFile(&file);
    return ret;
}
