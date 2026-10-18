/*
 * function: BACKUP_SYSTEM_LoadSingleCopy
 * address:  0x02032688
 * packet:   pkt_02031FE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   svsys     0x02146994  data
 *   BACKUP_SYSTEM_ClearBlockAreas  0x020333F8  arm
 *   BACKUP_SYSTEM_GetAreaAddr  0x02031EAC  arm
 *   FLASH_ACCESS_Read  0x020335E8  arm
 *   BACKUP_SYSTEM_FillBlockAreas  0x02033410  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   BACKUP_SYSTEM_GetFooterInfo  0x02031F9C  arm
 *   BACKUP_SYSTEM_SetBlockArea  0x0203331C  arm
 *   MATH_CalcCRC16CCITT  0x02081B8C  arm
 *   func_02033BF0  0x02033BF0  arm
 *   SAVEDATA_GetBlockOffset  0x02033B68  arm
 *   SAVEDATA_GetBlockSize  0x02033BAC  arm
 *   BACKUP_SYSTEM_SetSaveCount  0x02031F94  arm
 *   BACKUP_SYSTEM_GetBlockArea  0x020332FC  arm
 *
 * backup_system.c.  The one-copy load: read copy 1 of the save area into the
 * staging buffer self->f34 (FLASH_ACCESS_Read at BACKUP_SYSTEM_GetAreaAddr(self, 1)); on a
 * read failure clear the marks (BACKUP_SYSTEM_FillBlockAreas(self, 1)), zero the buffer and
 * answer 0.  Otherwise check the footer (BACKUP_SYSTEM_GetFooterInfo; with mode == 1 a
 * generation other than arg3 counts as bad), answer 3 or 0 for a bad footer,
 * then walk every record checking its stored CRC against the footer's CRC
 * table and recomputing it (MATH_CalcCRC16CCITT over svsys's inline table),
 * marking each record 0, or 1 on a recompute mismatch.  A completed walk marks
 * the two trailing slots 1 and commits the footer's generation
 * (BACKUP_SYSTEM_SetSaveCount); a broken one answers 3.  The one-copy twin of
 * BACKUP_SYSTEM_LoadDoubleCopy (docs/notes/pkt_02031FE0.c.txt holds the history).
 *
 * Closed wave 12 by the callee's real argument list: BACKUP_SYSTEM_ClearBlockAreas takes
 * self ONLY (src/matched/BACKUP_SYSTEM_ClearBlockAreas.c forwards self->+0x138/+0x13C to a
 * clear and never reads its other parameters).  Passing (self, mode, arg3)
 * as every earlier draft did left four instructions of the first read's
 * argument setup in the wrong order (10 bytes).  The redundant re-test
 * `if (crc == base[i])` after the `!= ... goto done` is in the image (a dead
 * second compare), and `u8 *h` first / `u32 i` last in the declarations set
 * the loop's registers.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/BACKUP_SYSTEM_LoadSingleCopy.c \
 *       --func BACKUP_SYSTEM_LoadSingleCopy --addr 0x02032688 --arm
 */
#include "../include/Obj08819.h"
#include "../include/G_SaveMain.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct Save Save;
struct Save {
    u8   pad00[0x2c];
    u8  *f2c;
    u32  f30;
    u8  *f34;
    u8   pad38[0x108];
    u32  f140;
};

extern struct SaveMain *svsys;

extern void BACKUP_SYSTEM_ClearBlockAreas(Save *self);
struct Obj020332FC;
struct Obj02033410;
struct Obj02033BF0;
extern u32 BACKUP_SYSTEM_GetAreaAddr(u32 *p, u32 sel);
struct MATHCRC16Table;
extern int FLASH_ACCESS_Read(u32 a0, u32 a1, u32 a2, void (*a3)(void));
extern void BACKUP_SYSTEM_FillBlockAreas(struct Obj02033410 *p, u32 val);
extern void MIi_CpuClear32(int a, void *b, u32 c);
extern void BACKUP_SYSTEM_GetFooterInfo(u32 *out, void *p, void *buf, u32 sel);
extern void BACKUP_SYSTEM_SetBlockArea(struct Obj020332FC *p, u32 idx, u32 val);
extern u16 MATH_CalcCRC16CCITT(struct MATHCRC16Table *table, void *data, u32 dataLength);
extern u32 func_02033BF0(struct Obj02033BF0 *p);
extern u32  SAVEDATA_GetBlockOffset(u8 *p, u32 idx);
extern u32  SAVEDATA_GetBlockSize(u8 *p, u32 idx);
extern void BACKUP_SYSTEM_SetSaveCount(int *p, int v);
extern u32 BACKUP_SYSTEM_GetBlockArea(struct Obj020332FC *p, u32 idx);

int BACKUP_SYSTEM_LoadSingleCopy(Save *self, int mode, int arg3)
{
    u32 pair[2];
    u8 *h;
    u32 j, A, B;
    int saved;
    u8 *base;
    u8 *gp;
    u32 i;

    BACKUP_SYSTEM_ClearBlockAreas(self);
    h = self->f34;
    if (FLASH_ACCESS_Read(BACKUP_SYSTEM_GetAreaAddr((u32 *)self, 1), (u32)h, self->f30,
                      (void (*)(void))svsys->unk204) == 0) {
        BACKUP_SYSTEM_FillBlockAreas((struct Obj02033410 *)self, 1);
        MIi_CpuClear32(0, h, self->f30);
        return 0;
    }
    BACKUP_SYSTEM_GetFooterInfo(pair, self, h, 0);
    if (mode == 1) {
        if ((s32)pair[1] != arg3)
            pair[0] = 2;
    }
    if (pair[0] != 0) {
        if (pair[0] == 1) {
            BACKUP_SYSTEM_FillBlockAreas((struct Obj02033410 *)self, 1);
            return 3;
        }
        BACKUP_SYSTEM_FillBlockAreas((struct Obj02033410 *)self, 1);
        return 0;
    }

    base = h + (self->f30 - 0x10 - self->f140);
    saved = (s32)pair[1];
    for (i = 0; i < func_02033BF0((struct Obj02033BF0 *)self->f2c); i++) {
        A = SAVEDATA_GetBlockOffset(self->f2c, i);
        B = SAVEDATA_GetBlockSize(self->f2c, i);
        gp = h + (A + B);
        BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)self, i, 0);
        if (((struct Obj08819 *)gp)->f2 != *(u16 *)(base + i * 2))
            goto done;
        if (((struct Obj08819 *)gp)->f2 == *(u16 *)(base + i * 2)) {
            if (((struct Obj08819 *)gp)->f2 != MATH_CalcCRC16CCITT((struct MATHCRC16Table *)((u8 *)svsys + 4), h + A, B)) {
                BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)self, i, 1);
                goto done;
            }
        }
    }
done:
    if (i >= func_02033BF0((struct Obj02033BF0 *)self->f2c)) {
        BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)self, func_02033BF0((struct Obj02033BF0 *)self->f2c) + 1, 1);
        BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)self, func_02033BF0((struct Obj02033BF0 *)self->f2c), 1);
    } else {
        BACKUP_SYSTEM_FillBlockAreas((struct Obj02033410 *)self, 1);
        return 3;
    }
    BACKUP_SYSTEM_SetSaveCount((int *)self, saved);
    for (j = 0; j < func_02033BF0((struct Obj02033BF0 *)self->f2c); j++)
        BACKUP_SYSTEM_GetBlockArea((struct Obj020332FC *)self, j);
    return 1;
}
