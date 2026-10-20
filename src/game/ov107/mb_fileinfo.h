#ifndef GAME_OV107_MB_FILEINFO_H
#define GAME_OV107_MB_FILEINFO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of mb_fileinfo.c, prototypes copied from their definitions. */

struct MbSegmentHeaderInfo;
struct MBGameRegistry;
typedef struct MbSegmentHeaderInfo MbSegmentHeaderInfo;

#include "../types.h"
#include "../sdk_fs.h"
#include "../ov107/mb_parent.h"
#include "../sdk_mb.h"

u32 MB_GetSegmentLength(void *file);
int MB_ReadSegment(FSFile *file, void *buf, u32 len);
void MBi_ReadSegmentHeader(MbSegmentHeaderInfo *p, u32 top, u32 bottom, int clean);
int MB_RegisterFile(struct MBGameRegistry *game_reg, void *buf);
void MBi_MakeDownloadFileInfo(MbDownloadFileInfoHeader *mbdlFileInfop, const void *buf);
BOOL MBi_MakeBlockInfoTable(MB_BlockInfoTable *table, MbDownloadFileInfoHeader *mdfi);
BOOL MBi_get_blockinfo(MB_BlockInfo *bi, MB_BlockInfoTable *table, u32 block, MbDownloadFileInfoHeader *mdfi);
int MBi_IsAbleToRecv(u8 segment_no, u32 address, u32 size);
int IsAbleToLoad(u8 segment_no, u32 address, u32 size);
/* END mkheaders: generated region */

#endif
