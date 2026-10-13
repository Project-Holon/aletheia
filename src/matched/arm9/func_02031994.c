/*
 * function: BACKUP_SYSTEM_GetWork
 * address:  0x02031994
 * packet:   pkt_0203195C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_GetWork.c \\
 *       --func BACKUP_SYSTEM_GetWork --addr 0x02031994 --arm --cc 1.1p1
 *
 * symbols:
 *   BACKUP_SYSTEM_FillBlockAreas  0x02033410  arm
 *   SAVEDATA_DeleteTable  0x020339B4  arm
 *   SAVEDATA_InitBuffer  0x020339D0  arm
 *   SAVEDATA_GetBlockOffset  0x02033B68  arm
 */
#include "../include/Obj11324.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_020307B0(void *p);
struct Obj02033410;
extern void SAVEDATA_DeleteTable(int *p);
extern u32 SAVEDATA_GetBlockOffset(u8 *p, u32 i);
extern void SAVEDATA_InitBuffer(u32 a, u32 b);
extern void BACKUP_SYSTEM_FillBlockAreas(struct Obj02033410 *p, u32 val);

u32 BACKUP_SYSTEM_GetWork(u8 *p, u32 *out)
{
    *out = ((struct Obj11324 *)p)->f30;
    return ((struct Obj11324 *)p)->f34;
}
