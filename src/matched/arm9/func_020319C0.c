/*
 * function: BACKUP_SYSTEM_ClearWork
 * address:  0x020319C0
 * packet:   pkt_0203195C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_ClearWork.c \\
 *       --func BACKUP_SYSTEM_ClearWork --addr 0x020319C0 --arm --cc 1.1p1
 *
 * symbols:
 *   BACKUP_SYSTEM_FillBlockAreas  0x02033410  arm
 *   SAVEDATA_DeleteTable  0x020339B4  arm
 *   SAVEDATA_InitBuffer  0x020339D0  arm
 *   SAVEDATA_GetBlockOffset  0x02033B68  arm
 */
#include "../include/Obj02604.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_020307B0(void *p);
extern void SAVEDATA_DeleteTable(int *p);
extern u32 SAVEDATA_GetBlockOffset(u8 *p, u32 i);
extern void SAVEDATA_InitBuffer(u32 a, u32 b);
struct Obj02033410;
extern void BACKUP_SYSTEM_FillBlockAreas(struct Obj02033410 *p, u32 val);

void BACKUP_SYSTEM_ClearWork(u8 *p)
{
    SAVEDATA_InitBuffer(((struct Obj02604 *)p)->f34, *(u32 *)&((struct Obj02604 *)p)->f2C);
    BACKUP_SYSTEM_FillBlockAreas((struct Obj02033410 *)p, 1);
}
