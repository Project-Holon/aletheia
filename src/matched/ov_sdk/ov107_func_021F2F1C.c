/*
 * function: MB_GetSegmentLength
 * address:  0x021F2F1C
 * packet:   pkt_ov107_021F2F1C
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MB_GetSegmentLength (libmb.TWL.HYB.a mb_fileinfo.o)
 *
 * symbols:
 *   FS_GetFilePosition  0x02078AEC  arm
 *   FS_ReadFile  0x02078B70  arm
 *   FS_SeekFile  0x02078B44  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    u8 pad0[0x2C];
    u32 arm9Size;
    u8 pad1[0x0C];
    u32 arm7Size;
} RomHeader;

typedef signed int     s32;
struct FSFile;
extern u32 FS_GetFilePosition(struct FSFile *file);
extern s32 FS_ReadFile(struct FSFile *file, void *buffer, s32 length);
extern int FS_SeekFile(struct FSFile *file, long offset, int origin);

u32 MB_GetSegmentLength(void *file)
{
    u8 rom[96];
    RomHeader *p;
    u32 ret;
    u32 bak_pos;

    p = 0;
    ret = 0;
    if (file) {
        bak_pos = FS_GetFilePosition(file);
        if ((u32)FS_ReadFile(file, rom, 96) >= 96)
            p = (RomHeader *)rom;
        FS_SeekFile(file, bak_pos, 0);
    } else {
        p = (RomHeader *)0x02FFFE00;
    }
    if (p) {
        ret = p->arm9Size + 0x268 + p->arm7Size;
        if (ret < 0x10000)
            ret = 0x10000;
    }
    return ret;
}
