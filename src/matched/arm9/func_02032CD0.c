/*
 * function: BACKUP_SYSTEM_SaveSeqMain
 * address:  0x02032CD0
 * packet:   pkt_02032CD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   svsys     0x02146994  data
 *   str_020A7848   0x020A7848  data  a1
 *   str_020A7888   0x020A7888  data  a1
 *   BACKUP_SYSTEM_CompareRecordStep   0x02032A9C  arm
 *   BACKUP_SYSTEM_WriteRecord   0x02032BF8  arm
 *   BACKUP_SYSTEM_WriteCrcTable   0x02032C84  arm
 *   BACKUP_SYSTEM_WriteFooterBody   0x020328E0  arm
 *   BACKUP_SYSTEM_WriteFooterLastByte   0x02032930  arm
 *   BACKUP_SYSTEM_IncRecordCount   0x02033264  arm
 *   BACKUP_SYSTEM_SwapBlockAreas   0x0203335C  arm
 *   BACKUP_SYSTEM_GetBlockArea  0x020332FC  arm
 *   BACKUP_SYSTEM_SetBlockArea  0x0203331C  arm
 *   BACKUP_SYSTEM_ClearBlockAreas  0x020333F8  arm
 *   FLASH_ACCESS_PollWrite  0x020337B8  arm
 *   SAVEDATA_GetBlockSize  0x02033BAC  arm
 *
 * The backup_system.c save-write state machine, one step per call, on the
 * state byte at +0x18 (docs/families/backup_system.h's unk18).  States:
 *   0-1   pump every not-yet-resident record through BACKUP_SYSTEM_CompareRecordStep (the
 *         resumable Flash copy; `done` is its yield flag), refreshing each
 *         record's counter with BACKUP_SYSTEM_IncRecordCount; a 0 answer without the yield
 *         flag raises the backup_system.c line 0x72A assertion
 *   2-4   for every marked record, start its write (BACKUP_SYSTEM_WriteRecord) and poll
 *         it (FLASH_ACCESS_PollWrite on the handle kept at svsys+0x20C), summing
 *         the written sizes into +0x144
 *   5-6   the trailing block (BACKUP_SYSTEM_WriteCrcTable), 7-8 the footer (BACKUP_SYSTEM_WriteFooterBody,
 *         returns 1 when committed), 9-10 the footer's last byte
 *         (BACKUP_SYSTEM_WriteFooterLastByte); state 10 then either restarts at state 2 for the
 *         second copy (BACKUP_SYSTEM_SwapBlockAreas swaps the 1/2 marks, *out = 1) or
 *         finishes (BACKUP_SYSTEM_ClearBlockAreas) and answers 2
 *   11    answers 2
 * A failed poll answers 3, or 2 once the first copy has been written (+0x19).
 * Wave 11, 2026-09-23 -- first transcription, EXACT after one declaration
 * swap (`st` before `done`: later declaration, lower address).  The constants
 * 0/1/2/3 live in callee-saved registers across the whole switch, which is
 * dsi/1.1p1's own habit (../2.0/sp2 is 957 bytes out).
 */

#include "../include/G_SaveMain.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Save Save;
struct Save {
    u32  f00;
    u32  f04;
    u8   pad08[0xc];
    u32  f14;
    u8   f18;
    u8   f19;
    u8   pad1A[0x12];
    u8  *f2c;
    u8   pad30[0x114];
    u32  f144;
    u32  f148;
    u32  f14c;
    u32  f150;
};

extern struct SaveMain *svsys;
extern const char str_020A7848[];
extern const char str_020A7888[];

struct Obj020332FC;
struct Obj0203335C;
struct Obj02033BF0;
struct SaveBackup;
extern u32 BACKUP_SYSTEM_GetBlockArea(struct Obj020332FC *p, u32 idx);
extern void BACKUP_SYSTEM_SetBlockArea(struct Obj020332FC *p, u32 idx, u32 val);
extern u32 BACKUP_SYSTEM_CompareRecordStep(struct SaveBackup *p, u32 id, u32 mode, u32 *pa, u32 *pb, u32 *pc, u32 *pd);
extern void func_02034714(const char *file, u32 line, const char *msg);
extern u16 BACKUP_SYSTEM_IncRecordCount(struct SaveBackup *p, u32 id);
extern u32 func_02033BF0(struct Obj02033BF0 *p);
extern u16  BACKUP_SYSTEM_WriteRecord(Save *p, u32 id, u32 v, u32 f);
extern int FLASH_ACCESS_PollWrite(u16 a0, u32 *a1, u32 a2);
extern u32  SAVEDATA_GetBlockSize(u8 *tbl, u32 idx);
extern int BACKUP_SYSTEM_WriteCrcTable(struct SaveBackup *p, u32 sel);
extern int BACKUP_SYSTEM_WriteFooterBody(struct SaveBackup *p, u32 sel);
extern int BACKUP_SYSTEM_WriteFooterLastByte(struct SaveBackup *p, u32 sel);
extern void BACKUP_SYSTEM_SwapBlockAreas(struct Obj0203335C *p);
extern void BACKUP_SYSTEM_ClearBlockAreas(Save *p);

int BACKUP_SYSTEM_SaveSeqMain(Save *p, u32 *out)
{
    u32 st;
    u32 done;
    u32 v;
    u32 r;

    *out = 0;
    switch (p->f18) {
    case 0:
        p->f148 = 0;
        p->f14c = 0;
        p->f150 = 0;
        p->f18++;
    case 1:
        done = 0;
        do {
            if (done == 1)
                return 0;
            if (BACKUP_SYSTEM_GetBlockArea((struct Obj020332FC *)p, p->f14) == 0) {
                r = BACKUP_SYSTEM_CompareRecordStep((struct SaveBackup *)p, p->f14, 1, &p->f148, &p->f14c, &p->f150, &done);
                if (r == 1) {
                    BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)p, p->f14, 1);
                } else if (r == 0) {
                    if (done != 1)
                        func_02034714(str_020A7848, 0x72A, str_020A7888);
                    return 0;
                } else {
                    goto next;
                }
            }
            BACKUP_SYSTEM_IncRecordCount((struct SaveBackup *)p, p->f14);
        next:
            p->f14++;
        } while (p->f14 < func_02033BF0((struct Obj02033BF0 *)p->f2c));
        p->f18++;
        break;
    case 2:
        p->f14 = 0;
        p->f18++;
    case 3:
        for (; p->f14 < func_02033BF0((struct Obj02033BF0 *)p->f2c); p->f14++) {
            v = BACKUP_SYSTEM_GetBlockArea((struct Obj020332FC *)p, p->f14);
            if (v != 0) {
                svsys->unk20C = BACKUP_SYSTEM_WriteRecord(p, p->f14, v, p->f19);
                p->f18++;
                break;
            }
        }
        if (p->f14 >= func_02033BF0((struct Obj02033BF0 *)p->f2c)) {
            p->f14 = 0;
            p->f18 = 5;
        }
        break;
    case 4:
        if (FLASH_ACCESS_PollWrite(svsys->unk20C, &st, svsys->unk208) == 0)
            break;
        if (st == 0)
            return p->f19 == 0 ? 3 : 2;
        p->f144 += SAVEDATA_GetBlockSize(p->f2c, p->f14);
        p->f14++;
        p->f18 = 3;
        break;
    case 5:
        v = BACKUP_SYSTEM_GetBlockArea((struct Obj020332FC *)p, func_02033BF0((struct Obj02033BF0 *)p->f2c));
        if (v == 0) {
            v = 1;
            BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)p, func_02033BF0((struct Obj02033BF0 *)p->f2c), v);
        }
        svsys->unk20C = BACKUP_SYSTEM_WriteCrcTable((struct SaveBackup *)p, v);
        p->f18++;
    case 6:
        if (FLASH_ACCESS_PollWrite(svsys->unk20C, &st, svsys->unk208) == 0)
            break;
        if (st == 0)
            return p->f19 == 0 ? 3 : 2;
        p->f18++;
        break;
    case 7:
        v = BACKUP_SYSTEM_GetBlockArea((struct Obj020332FC *)p, func_02033BF0((struct Obj02033BF0 *)p->f2c) + 1);
        if (v == 0) {
            v = 1;
            BACKUP_SYSTEM_SetBlockArea((struct Obj020332FC *)p, func_02033BF0((struct Obj02033BF0 *)p->f2c) + 1, v);
        }
        svsys->unk20C = BACKUP_SYSTEM_WriteFooterBody((struct SaveBackup *)p, v);
        p->f18++;
    case 8:
        if (FLASH_ACCESS_PollWrite(svsys->unk20C, &st, svsys->unk208) == 0)
            break;
        if (st == 0)
            return p->f19 == 0 ? 3 : 2;
        p->f18++;
        return 1;
    case 9:
        svsys->unk20C = BACKUP_SYSTEM_WriteFooterLastByte((struct SaveBackup *)p, BACKUP_SYSTEM_GetBlockArea((struct Obj020332FC *)p, func_02033BF0((struct Obj02033BF0 *)p->f2c) + 1));
        p->f18++;
    case 10:
        if (FLASH_ACCESS_PollWrite(svsys->unk20C, &st, svsys->unk208) == 0)
            break;
        if (st == 0)
            return p->f19 == 0 ? 3 : 2;
        if (++p->f19 == 1 && p->f00 != p->f04) {
            BACKUP_SYSTEM_SwapBlockAreas((struct Obj0203335C *)p);
            p->f18 = 2;
            *out = 1;
            return 0;
        }
        BACKUP_SYSTEM_ClearBlockAreas(p);
        p->f18++;
        return 2;
    case 11:
        return 2;
    }
    return 0;
}
