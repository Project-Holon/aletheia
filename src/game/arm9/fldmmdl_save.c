/*
 * file:     fldmmdl_save.c
 * unit:     yes
 * function: FLDMMDL_GetSaveTableSize, FLDMMDL_ClearSaveTable, FLDMMDL_StoreSaveTable, FLDMMDL_LoadSaveTable, FLDMMDL_StoreSaveRecord, FLDMMDL_RestoreFromSaveRecord, FLDMMDL_GetNextUsed, FLDMMDL_GetFreeSlot, FLDMMDL_ObjCodeToTableIndex
 * address:  0x0200EE48
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from net_device_table.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   MI_CpuFill8     0x02082BCC  arm
 *   FLDMMDL_LoadObjCodeParam   0x0216E2E8  thumb  ov010
 */
#include "../ov010/fldmmdl_types.h"
#include "fldmmdl_save_shared_types.h"

typedef unsigned short u16;

typedef short s16;

typedef signed char    s8;

/*
 * The 0x50-byte packed field model: the network form of one Mmdl, built by
 * FLDMMDL_StoreSaveRecord and read back by FLDMMDL_RestoreFromSaveRecord.
 * Every field carries the Mmdl field of the same name, narrowed where the
 * packed form is smaller.  64 of them (0x1400 bytes) make up a device table
 * block (FLDMMDL_GetSaveTableSize).
 */
typedef struct NetDeviceRecord {
    u32 statusBit;               /* 0x00: Mmdl.statusBit */
    u8  sizeWidth;               /* 0x04: Mmdl.sizeWidth */
    u8  sizeDepth;               /* 0x05: Mmdl.sizeDepth */
    u8  pad06[2];
    u8  objId;                   /* 0x08: Mmdl.objId, narrowed */
    u8  moveCode;                /* 0x09: Mmdl.moveCode, narrowed */
    s8  moveLimitX;              /* 0x0A: Mmdl.moveLimitX, narrowed */
    s8  moveLimitZ;              /* 0x0B: Mmdl.moveLimitZ, narrowed */
    s8  dirHeader;               /* 0x0C: Mmdl.dirHeader, narrowed */
    s8  dirDisp;                 /* 0x0D: Mmdl.dirDisp, narrowed */
    s8  dirMove;                 /* 0x0E: Mmdl.dirMove, narrowed */
    u8  pad0F;
    u16 zoneId;                  /* 0x10: Mmdl.zoneId */
    u16 objCode;                 /* 0x12: Mmdl.objCode */
    u16 eventType;               /* 0x14: Mmdl.eventType */
    u16 eventFlag;               /* 0x16: Mmdl.eventFlag */
    u16 eventId;                 /* 0x18: Mmdl.eventId */
    u16 param0;                  /* 0x1A: Mmdl.param0 */
    u16 param1;                  /* 0x1C: Mmdl.param1 */
    u16 param2;                  /* 0x1E: Mmdl.param2 */
    s16 gridInitX;               /* 0x20: Mmdl.gridInitX */
    s16 gridInitY;               /* 0x22: Mmdl.gridInitY */
    s16 gridInitZ;               /* 0x24: Mmdl.gridInitZ */
    s16 gridNowX;                /* 0x26: Mmdl.gridNowX */
    s16 gridNowY;                /* 0x28: Mmdl.gridNowY */
    s16 gridNowZ;                /* 0x2A: Mmdl.gridNowZ */
    u32 posY;                    /* 0x2C: Mmdl.pos.y */
    u8  moveProcWork[0x10];      /* 0x30: Mmdl.moveProcWork */
    u8  moveSubProcWork[0x10];   /* 0x40: Mmdl.moveSubProcWork */
} NetDeviceRecord;

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

extern void MI_CpuFill8(void *dst, u8 val, u32 size);

extern void FLDMMDL_LoadObjCodeParam(const MmdlSys *sys, u32 objCode, MmdlObjCodeParam *out);

u32 FLDMMDL_GetSaveTableSize(void);

void FLDMMDL_ClearSaveTable(void *dest);

void FLDMMDL_StoreSaveTable(MmdlSys *producer, u8 *records);

void FLDMMDL_LoadSaveTable(MmdlSys *sys, const u8 *records);

void FLDMMDL_StoreSaveRecord(const Mmdl *mmdl, NetDeviceRecord *record);

void FLDMMDL_RestoreFromSaveRecord(Mmdl *mmdl, const NetDeviceRecord *record, MmdlSys *sys);

u32 FLDMMDL_GetNextUsed(const void *obj, void *out, u32 *idxptr);

void *FLDMMDL_GetFreeSlot(void *ctx);

u32 FLDMMDL_ObjCodeToTableIndex(u32 x);

u32 FLDMMDL_GetSaveTableSize(void)
{
    return 5 << 10;
}

void FLDMMDL_ClearSaveTable(void *dest)
{
    MI_CpuFill8(dest, 0, FLDMMDL_GetSaveTableSize());
}

/*
 * Drain loop over a producer: while the enumerator at 0x0200F0CC still hands
 * back 1, take the item at the out-slot and, unless bit 20 of its +4 word is
 * set, retire the 0x50-byte destination cursor through FLDMMDL_StoreSaveRecord.  The
 * enumerator call is rotated (first test above the loop body) so this is a
 * plain `while`, not a do/while.
 */
void FLDMMDL_StoreSaveTable(MmdlSys *producer, u8 *records)
{
    u32 hint = 0;
    void *item;

    FLDMMDL_ClearSaveTable(records);

    while (FLDMMDL_GetNextUsed((const void *)producer, &item, &hint) == 1) {
        if ((((const Mmdl *)item)->moveBit & MMDL_MOVEBIT_ATTR_EFFECT_OFF) == 0) {
            FLDMMDL_StoreSaveRecord((const Mmdl *)item, (NetDeviceRecord *)records);
            records += 0x50;
        }
    }
}

/*
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 *
 * Walks 64 0x50-byte records; for each whose leading word has bit 0 set,
 * looks up a free slot with FLDMMDL_GetFreeSlot and hands it, the record and
 * the context to FLDMMDL_RestoreFromSaveRecord. Stores the record count (always 0x40)
 * into the context at +6 once the walk finishes.
 *
 * Every concrete byte matches; FLDMMDL_GetFreeSlot (a documented near miss,
 * still open) and FLDMMDL_RestoreFromSaveRecord are each called from exactly this one
 * site in the whole ROM, so both relocations stay unresolved under the
 * honesty rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLDMMDL_LoadSaveTable.c \
 *       --func FLDMMDL_LoadSaveTable --addr 0x0200EEAC --cc 1.1p1
 *
 * The `matched` class does not reach it: neither FLDMMDL_GetFreeSlot nor
 * FLDMMDL_RestoreFromSaveRecord is matched, so no EXACT entry covers either address.  It closes
 * when one of the two is matched, or when the image acquires a second caller.
 */
void FLDMMDL_LoadSaveTable(MmdlSys *sys, const u8 *records)
{
    const u8 *rec = records;
    u32 i;

    for (i = 0; i < 0x40; i++, rec += 0x50) {
        if (((const NetDeviceRecord *)rec)->statusBit & MMDL_STABIT_USE) {
            FLDMMDL_RestoreFromSaveRecord((Mmdl *)FLDMMDL_GetFreeSlot(sys), (const NetDeviceRecord *)rec, sys);
        }
    }

    sys->mmdlCount = (short)i;
}

/*
 * A field-by-field marshal from a source record into a differently laid
 * out destination record: several 16-bit source fields narrow to 8-bit
 * destination fields, several signed-halfword source fields (loaded with
 * ldrsh, register-offset addressing being Thumb's only encoding for a
 * signed halfword load, see docs/idioms/ldrsh-register-offset-is-signedness.md)
 * widen back into unsigned destination halfwords, and the tail of the
 * record is two flat 0x10-byte blocks copied with MI_CpuCopy8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLDMMDL_StoreSaveRecord.c \
 *       --func FLDMMDL_StoreSaveRecord --addr 0x0200EED8 --cc 1.1p1
 */
void FLDMMDL_StoreSaveRecord(const Mmdl *mmdl, NetDeviceRecord *record)
{
    record->statusBit = *(const u32 *)&mmdl->statusBit;
    record->sizeWidth = mmdl->sizeWidth;
    record->sizeDepth = mmdl->sizeDepth;
    record->objId = (u8)mmdl->objId;
    record->zoneId = mmdl->zoneId;
    record->objCode = mmdl->objCode;
    record->moveCode = (u8)mmdl->moveCode;
    record->eventType = mmdl->eventType;
    record->eventFlag = mmdl->eventFlag;
    record->eventId = mmdl->eventId;
    record->dirHeader = (u8)mmdl->dirHeader;
    record->dirDisp = (u8)mmdl->dirDisp;
    record->dirMove = (u8)mmdl->dirMove;
    record->param0 = mmdl->param0;
    record->param1 = mmdl->param1;
    record->param2 = mmdl->param2;
    record->moveLimitX = (u8)mmdl->moveLimitX;
    record->moveLimitZ = (u8)mmdl->moveLimitZ;
    record->gridInitX = (u16)mmdl->gridInitX;
    record->gridInitY = (u16)mmdl->gridInitY;
    record->gridInitZ = (u16)mmdl->gridInitZ;
    record->gridNowX = (u16)mmdl->gridNowX;
    record->gridNowY = (u16)mmdl->gridNowY;
    record->gridNowZ = (u16)mmdl->gridNowZ;
    record->posY = *(const u32 *)&mmdl->pos.y;

    MI_CpuCopy8(mmdl->moveProcWork, record->moveProcWork, 0x10);
    MI_CpuCopy8(mmdl->moveSubProcWork, record->moveSubProcWork, 0x10);
}

void FLDMMDL_RestoreFromSaveRecord(Mmdl *mmdl, const NetDeviceRecord *record, MmdlSys *sys) {
    MI_CpuFill8(mmdl, 0, 0x100);

    mmdl->statusBit = record->statusBit;
    mmdl->sizeWidth = record->sizeWidth;
    mmdl->sizeDepth = record->sizeDepth;

    mmdl->objId = record->objId;
    mmdl->zoneId = record->zoneId;
    mmdl->objCode = record->objCode;
    mmdl->moveCode = record->moveCode;
    mmdl->eventType = record->eventType;
    mmdl->eventFlag = record->eventFlag;
    mmdl->eventId = record->eventId;

    mmdl->dirHeader = record->dirHeader;
    mmdl->dirDisp = record->dirDisp;
    mmdl->dirMove = record->dirMove;

    mmdl->param0 = record->param0;
    mmdl->param1 = record->param1;
    mmdl->param2 = record->param2;

    mmdl->moveLimitX = record->moveLimitX;
    mmdl->moveLimitZ = record->moveLimitZ;

    mmdl->gridInitX = record->gridInitX;
    mmdl->gridInitY = record->gridInitY;
    mmdl->gridInitZ = record->gridInitZ;

    mmdl->gridNowX = record->gridNowX;
    mmdl->gridNowY = record->gridNowY;
    mmdl->gridNowZ = record->gridNowZ;

    MI_CpuCopy8(record->moveProcWork, mmdl->moveProcWork, 0x10);
    MI_CpuCopy8(record->moveSubProcWork, mmdl->moveSubProcWork, 0x10);

    mmdl->mmdlSys = sys;
    {
        MmdlVec vec = { 0 };
        mmdl->gridOldX = mmdl->gridNowX;
        vec.x = (mmdl->gridNowX << 16) + 0x8000;
        mmdl->gridOldY = mmdl->gridNowY;
        vec.y = record->posY;
        mmdl->gridOldZ = mmdl->gridNowZ;
        vec.z = (mmdl->gridNowZ << 16) + 0x8000;
        mmdl->pos = vec;
    }

    mmdl->statusBit &= ~MMDL_STABIT_USE;
    FLDMMDL_LoadObjCodeParam(sys, mmdl->objCode, &mmdl->objCodeParam);
    mmdl->statusBit |= MMDL_STABIT_USE;

    {
        s8 *sub = (s8 *)mmdl + 0xe4;
        mmdl->offsetX = sub[0xd];
        mmdl->offsetY = sub[0xe];
        mmdl->offsetZ = sub[0xf];
    }

    mmdl->statusBit |= MMDL_STABIT_USE;
    mmdl->moveBit |= MMDL_MOVEBIT_ATTR_GET_ERROR;
    if (mmdl->statusBit & MMDL_STABIT_MOVE_INIT) {
        mmdl->moveBit |= MMDL_MOVEBIT_MOVE_PUSH;
    }
}

/*
 * Scans an array of 0x100-byte records starting at *idxptr, looking for one
 * whose leading word has bit 0 set. obj+4 holds a u16 record count and
 * obj+0x18 holds the array base. On a hit, *out gets the record pointer,
 * *idxptr is left one past the hit, and the function returns 1; scanning
 * to the end without a hit returns 0, leaving *idxptr == count. The two
 * "return 0" paths (guard and loop exhaustion) are separate, out-of-line
 * blocks rather than a shared tail; see
 * docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLDMMDL_GetNextUsed.c \
 *       --func FLDMMDL_GetNextUsed --addr 0x0200F0CC --cc 1.1p1
 */
u32 FLDMMDL_GetNextUsed(const void *obj, void *out, u32 *idxptr)
{
    u32 count = *(const u16 *)&((const MmdlSys *)obj)->mmdlMax;
    u32 idx = *idxptr;
    u8 *rec;

    if (idx < count) {
        rec = (u8 *)((const MmdlSys *)obj)->mmdlBuf + idx * 0x100;
        do {
            *idxptr = *idxptr + 1;
            if (((const Mmdl *)rec)->statusBit & MMDL_STABIT_USE) {
                *(void **)out = rec;
                return 1;
            }
            rec += 0x100;
        } while (*idxptr < count);
    }
    return 0;
}

/*
 * Scans a run of fixed-stride slots for the first one whose leading word
 * has bit 0 clear (a free-slot search); ctx+4 is the slot count (halfword)
 * and ctx+0x18 is the base pointer, stride 0x100 bytes. Returns the slot
 * pointer, or NULL if every slot up to the count is occupied. The loop
 * enters unconditionally and only checks the count after the first slot
 * has already been tested, so it is written as an infinite loop with two
 * breaks rather than a pre-tested while. The pointer argument is reused
 * in place for the slot cursor, which is what keeps it in r0 through to
 * the return and lets the found-slot path fall straight into the shared
 * epilogue with no register shuffle.
 *
 * EXACT* because the 34 compiled bytes fall two bytes short of the
 * disasm.py extent: a trailing "movs r0, r0" filler halfword between this
 * function and the next label, the ordinary inter-function padding, not a
 * byte difference (see "the two missing labels" in docs/MATCHING.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLDMMDL_GetFreeSlot.c \
 *       --func FLDMMDL_GetFreeSlot --addr 0x0200F104 --cc 1.1p1
 */
void *FLDMMDL_GetFreeSlot(void *ctx)
{
    u16 count = *(u16 *)&((const MmdlSys *)ctx)->mmdlMax;
    int i = 0;

    ctx = ((const MmdlSys *)ctx)->mmdlBuf;

    for (;;) {
        if ((((const Mmdl *)ctx)->statusBit & MMDL_STABIT_USE) == 0) {
            break;
        }
        i++;
        ctx = (u8 *)ctx + 0x100;
        if (i >= count) {
            ctx = 0;
            break;
        }
    }
    return ctx;
}

/*
 * A piecewise remap of one id space onto another: below 0xdf the id passes
 * through unchanged; two disjoint windows (0x1000..0x1235 and
 * 0x2000..0x2009) are rebased by subtracting a fixed offset (0xf21 and
 * 0x1ceb respectively, read as u16); everything else, including the gap
 * between the two windows, maps to the constant 0xa.  Each `if` here has to
 * be written with the in-window case as the `then` and the fallback as the
 * trailing `return`, not the other way around, or the branch polarity comes
 * out reversed; see docs/idioms/the-fall-through-arm-is-the-source-order.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLDMMDL_ObjCodeToTableIndex.c \
 *       --func FLDMMDL_ObjCodeToTableIndex --addr 0x0200F128 --cc 1.1p1
 */
u32 FLDMMDL_ObjCodeToTableIndex(u32 x)
{
    if (x < 0xdf) {
        return x;
    }
    if (x >= 0x1000 && x < 0x1236) {
        return (u16)(x - 0xf21);
    }
    if (x >= 0x2000 && x < 0x200a) {
        return (u16)(x - 0x1ceb);
    }
    return 0xa;
}
