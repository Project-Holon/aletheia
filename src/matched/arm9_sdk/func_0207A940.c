/*
 * function: FS_CreateFileFromMemory
 * address:  0x0207A940
 * packet:   pkt_0207A940
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FS_CreateFileFromMemory (libfs.TWL.HYB.a fs_proc_mem.o)
 *
 * symbols:
 *   FSi_InitMemArchive  0x0207A890  arm
 *   FS_OpenFileDirect  0x02078964  arm
 *   fsi_arc_mem  0x02150D44  data
 */

#include "../include/G_FSArchive.h"

typedef unsigned long u32;
typedef int BOOL;

typedef struct FSFile FSFile;
typedef struct FSArchive FSArchive;

extern struct FSArchive fsi_arc_mem;
extern void FSi_InitMemArchive(void);
extern BOOL FS_OpenFileDirect(FSFile *file, FSArchive *arc, u32 image_top, u32 image_bottom, u32 id);

BOOL FS_CreateFileFromMemory(FSFile *p_file, void *buf, u32 size)
{
    FSi_InitMemArchive();
    return FS_OpenFileDirect(p_file, &(*(FSArchive *)&fsi_arc_mem), (u32)buf, (u32)buf + size, 0);
}
