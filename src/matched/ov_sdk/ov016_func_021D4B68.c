/*
 * function: DWCi_ARClReadEx
 * address:  0x021D4B68
 * packet:   pkt_ov016_021D4B68
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ARClReadEx (libdwcutil.TWL.HYB.a archive.o)
 *
 * symbols:
 *   DWCi_QUElPopBack  0x021D54C4  arm  ov016
 *   FS_InitFile  0x020788AC  arm
 *   FS_OpenFile  0x02078C18  arm
 *   OS_Terminate  0x02088234  arm
 *   FS_GetLength  0x02078C28  arm
 *   func_021D4C9C  0x021D4C9C  arm  ov016
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   FS_ReadFile  0x02078B70  arm
 *   FS_CloseFile  0x02078A80  arm
 *   MI_UncompressLZ8  0x020834C0  arm
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   gMemArchive  0x021DE66C  data
 *   sArchiveTable2  0x021DBFE0  data
 */

#include "../include/G_MemArc.h"

typedef struct { unsigned char b[0x48]; } FSFile;
typedef struct { unsigned char pad[0x84]; void *queue; } MemArc;

extern void *DWCi_QUElPopBack(void *queue);
extern void FS_InitFile(FSFile *file);
extern int FS_OpenFile(FSFile *file, char *path);
extern void OS_Terminate(void);
typedef unsigned int   u32;
struct FSFile;
extern u32 FS_GetLength(struct FSFile *a0);
extern int func_021D4C9C(char *a, char *b, int n);
extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
typedef signed int     s32;
struct FSFile;
extern s32 FS_ReadFile(struct FSFile *file, void *buffer, s32 length);
extern int FS_CloseFile(FSFile *file);
extern void MI_UncompressLZ8(void *src, void *dst);
extern void DWCi_HEAPlFree_(void **mem);
extern struct MemArc *gMemArchive;
extern char sArchiveTable2[];

void *DWCi_ARClReadEx(char *path, unsigned long *size, int alignment)
{
    unsigned long siz;
    int align;
    FSFile file;
    void *fle;
    void *buf;

    DWCi_QUElPopBack(gMemArchive->queue);
    FS_InitFile(&file);
    if (!FS_OpenFile(&file, path))
        OS_Terminate();
    siz = FS_GetLength((struct FSFile *)(&file));
    if (size)
        *size = siz;
    if (func_021D4C9C(path, sArchiveTable2, 2))
        align = -4;
    else
        align = alignment;
    buf = DWCi_HEAPlAllocEx(siz, align);
    FS_ReadFile((struct FSFile *)(&file), buf, siz);
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
