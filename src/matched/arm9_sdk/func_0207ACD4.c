/*
 * function: func_0207ACD4
 * address:  0x0207ACD4
 * packet:   pkt_0207ACD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_CreateFileFromRom (libfs.TWL.HYB.a fs_proc_rom.o)
 *
 * symbols:
 *   FS_OpenFileDirect  0x02078964  arm
 *   fsi_arc_rom  0x02150DA8  data
 */

typedef unsigned long u32;
typedef int BOOL;

typedef struct FSFile FSFile;
typedef struct FSArchive FSArchive;

extern FSArchive fsi_arc_rom;
extern BOOL FS_OpenFileDirect(FSFile *file, FSArchive *arc, u32 image_top, u32 image_bottom, u32 id);

BOOL func_0207ACD4(FSFile *p_file, u32 offset, u32 size)
{
    return FS_OpenFileDirect(p_file, &fsi_arc_rom, offset, offset + size, 0xFFFF);
}
