/*
 * file:     net_device_table.c
 * unit:     yes
 * function: NET_DEVICE_TABLE_GetSize, NET_DEVICE_TABLE_Clear, NET_DEVICE_TABLE_BuildFromProducer, NET_DEVICE_TABLE_Setup, NET_DEVICE_TABLE_CopyRecord, NET_DEVICE_TABLE_InitEntry, NET_DEVICE_TABLE_GetNextUsed, NET_DEVICE_TABLE_GetFreeSlot, NET_DEVICE_TABLE_RemapId, NET_DEVICE_TABLE_GetZero, NET_DEVICE_TABLE_SetHeader, NET_DEVICE_TABLE_Select, NET_DEVICE_TABLE_Reset
 * address:  0x0200EE48
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id sites
 *           ov_id_72 (114) and ov_id_0E (14) resolve as `overlay_id` (a
 *           layout overlay index, loaded by a pc-relative load of this
 *           function, reaching the id register of a known overlay loader),
 *           which was the last blocker.
 * The argument constants are absolute symbols, not numbers: every one of the
 * fifteen argument positions in the image loads its value from a literal pool
 * (`ldr r0, [pc]`), and mwccarm materialises any literal in 0..255 with
 * `movs`.  See docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 * The cases are written in the memory order of the arms (6, 1, 2, 0/5, 3/4).
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   MI_CpuFill8     0x02082BCC  arm
 *   FLDMMDL_LoadObjCodeParam   0x0216E2E8  thumb  ov010
 *   func_02034A5C  0x02034A5C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   GFL_NET_DEVWIFI_GetDeviceTable  0x0215536C  thumb  ov009
 *   GFL_NET_DEVWIRELESS_GetDeviceTable  0x02177020  thumb  ov014
 *   IRCNET_GetHandlerTable  0x021798D4  thumb  ov015
 *   ov_id_0A       0x0000000A  data
 *   ov_id_0B       0x0000000B  data
 *   ov_id_09       0x00000009  data
 *   ov_id_0D       0x0000000D  data
 *   ov_id_72       0x00000072  data
 *   ov_id_0E       0x0000000E  data
 *   ov_id_0F       0x0000000F  data
 */
#include "../ov010/fldmmdl_types.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef signed char    s8;

typedef signed int     s32;

/*
 * The 0x50-byte packed field model: the network form of one Mmdl, built by
 * NET_DEVICE_TABLE_CopyRecord and read back by NET_DEVICE_TABLE_InitEntry.
 * Every field carries the Mmdl field of the same name, narrowed where the
 * packed form is smaller.  64 of them (0x1400 bytes) make up a device table
 * block (NET_DEVICE_TABLE_GetSize).
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

/* Three-word header NET_DEVICE_TABLE_SetHeader stamps. */
typedef struct NetDeviceHeader {
    u32 tag;
    u32 size;
    u32 count;
} NetDeviceHeader;

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void FLDMMDL_LoadObjCodeParam(const MmdlSys *sys, u32 objCode, MmdlObjCodeParam *out);
extern void func_02034A5C(s32 handle);
extern int func_02034AC4(s32 handle);
extern void *GFL_NET_DEVWIFI_GetDeviceTable(void);
extern void *GFL_NET_DEVWIRELESS_GetDeviceTable(void);
extern void *IRCNET_GetHandlerTable(void);
u32 NET_DEVICE_TABLE_GetSize(void);
void NET_DEVICE_TABLE_Clear(void *dest);
void NET_DEVICE_TABLE_BuildFromProducer(MmdlSys *producer, u8 *records);
void NET_DEVICE_TABLE_Setup(MmdlSys *sys, const u8 *records);
void NET_DEVICE_TABLE_CopyRecord(const Mmdl *mmdl, NetDeviceRecord *record);
void NET_DEVICE_TABLE_InitEntry(Mmdl *mmdl, const NetDeviceRecord *record, MmdlSys *sys);
u32 NET_DEVICE_TABLE_GetNextUsed(const void *obj, void *out, u32 *idxptr);
void *NET_DEVICE_TABLE_GetFreeSlot(void *ctx);
u32 NET_DEVICE_TABLE_RemapId(u32 x);
u32 NET_DEVICE_TABLE_GetZero(void);
void NET_DEVICE_TABLE_SetHeader(NetDeviceHeader *hdr);
int NET_DEVICE_TABLE_Select(u32 sel);
void NET_DEVICE_TABLE_Reset(u32 sel);
extern u8 ov_id_0A[];
extern u8 ov_id_0B[];
extern u8 ov_id_09[];
extern u8 ov_id_0D[];
extern u8 ov_id_72[];
extern u8 ov_id_0E[];
extern u8 ov_id_0F[];




u32 NET_DEVICE_TABLE_GetSize(void)
{
    return 5 << 10;
}




void NET_DEVICE_TABLE_Clear(void *dest)
{
    MI_CpuFill8(dest, 0, NET_DEVICE_TABLE_GetSize());
}




/*
 * Drain loop over a producer: while the enumerator at 0x0200F0CC still hands
 * back 1, take the item at the out-slot and, unless bit 20 of its +4 word is
 * set, retire the 0x50-byte destination cursor through NET_DEVICE_TABLE_CopyRecord.  The
 * enumerator call is rotated (first test above the loop body) so this is a
 * plain `while`, not a do/while.
 */
void NET_DEVICE_TABLE_BuildFromProducer(MmdlSys *producer, u8 *records)
{
    u32 hint = 0;
    void *item;

    NET_DEVICE_TABLE_Clear(records);

    while (NET_DEVICE_TABLE_GetNextUsed((const void *)producer, &item, &hint) == 1) {
        if ((((const Mmdl *)item)->moveBit & MMDL_MOVEBIT_ATTR_EFFECT_OFF) == 0) {
            NET_DEVICE_TABLE_CopyRecord((const Mmdl *)item, (NetDeviceRecord *)records);
            records += 0x50;
        }
    }
}



/*
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 *
 * Walks 64 0x50-byte records; for each whose leading word has bit 0 set,
 * looks up a free slot with func_0200F104 and hands it, the record and
 * the context to NET_DEVICE_TABLE_InitEntry. Stores the record count (always 0x40)
 * into the context at +6 once the walk finishes.
 *
 * Every concrete byte matches; func_0200F104 (a documented near miss,
 * still open) and NET_DEVICE_TABLE_InitEntry are each called from exactly this one
 * site in the whole ROM, so both relocations stay unresolved under the
 * honesty rule.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NET_DEVICE_TABLE_Setup.c \
 *       --func NET_DEVICE_TABLE_Setup --addr 0x0200EEAC --cc 1.1p1
 *
 * The `matched` class does not reach it: neither func_0200F104 nor
 * NET_DEVICE_TABLE_InitEntry is matched, so no EXACT entry covers either address.  It closes
 * when one of the two is matched, or when the image acquires a second caller.
 */
void NET_DEVICE_TABLE_Setup(MmdlSys *sys, const u8 *records)
{
    const u8 *rec = records;
    u32 i;

    for (i = 0; i < 0x40; i++, rec += 0x50) {
        if (((const NetDeviceRecord *)rec)->statusBit & MMDL_STABIT_USE) {
            NET_DEVICE_TABLE_InitEntry((Mmdl *)NET_DEVICE_TABLE_GetFreeSlot(sys), (const NetDeviceRecord *)rec, sys);
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
 *   python tools/match.py one --src src/matched/NET_DEVICE_TABLE_CopyRecord.c \
 *       --func NET_DEVICE_TABLE_CopyRecord --addr 0x0200EED8 --cc 1.1p1
 */
void NET_DEVICE_TABLE_CopyRecord(const Mmdl *mmdl, NetDeviceRecord *record)
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




void NET_DEVICE_TABLE_InitEntry(Mmdl *mmdl, const NetDeviceRecord *record, MmdlSys *sys) {
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
 *   python tools/match.py one --src src/matched/NET_DEVICE_TABLE_GetNextUsed.c \
 *       --func NET_DEVICE_TABLE_GetNextUsed --addr 0x0200F0CC --cc 1.1p1
 */
u32 NET_DEVICE_TABLE_GetNextUsed(const void *obj, void *out, u32 *idxptr)
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
 *   python tools/match.py one --src src/matched/NET_DEVICE_TABLE_GetFreeSlot.c \
 *       --func NET_DEVICE_TABLE_GetFreeSlot --addr 0x0200F104 --cc 1.1p1
 */
void *NET_DEVICE_TABLE_GetFreeSlot(void *ctx)
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
 *   python tools/match.py one --src src/matched/NET_DEVICE_TABLE_RemapId.c \
 *       --func NET_DEVICE_TABLE_RemapId --addr 0x0200F128 --cc 1.1p1
 */
u32 NET_DEVICE_TABLE_RemapId(u32 x)
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




/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: NET_DEVICE_TABLE_GetZero is a stub returning 0; NET_DEVICE_TABLE_SetHeader stamps a
 * three-word header (a type tag, a size, a count) into the caller's struct.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200F168.c \
 *       --addr 0x0200F168 --thumb
 */
u32 NET_DEVICE_TABLE_GetZero(void)
{
    return 0;
}




void NET_DEVICE_TABLE_SetHeader(NetDeviceHeader *hdr)
{
    hdr->tag = 2;
    hdr->size = 4;
    hdr->count = 1;
}



/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id sites
 *           ov_id_72 (114) and ov_id_0E (14) resolve as `overlay_id` (a
 *           layout overlay index, loaded by a pc-relative load of this
 *           function, reaching the id register of a known overlay loader),
 *           which was the last blocker.
 *
 * The jump table at 0x0200F18E (base 0x0200F190, selector order 0..6) is
 * 0x006c, 0x0030, 0x004e, 0x0078, 0x0078, 0x006c, 0x000c, i.e. selectors 0
 * and 5 share the arm at 0x0200F1FC, selectors 3 and 4 the one at
 * 0x0200F208, and 6, 1, 2 have their own (0x0200F19C, 0x0200F1C0,
 * 0x0200F1DE).  The cases below are written in that memory order, which is
 * what decides the arm layout (the sibling function NET_DEVICE_TABLE_Reset, same
 * packet, closes the same way).
 *
 * The arguments are absolute symbols, not numbers: every one of them arrives
 * in a literal pool (`ldr r0, [pc]`), and mwccarm writes any literal in
 * 0..255 with `movs`
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).  The
 * seven words of the pool are, in order, 0x0A, 0x0B, 9, 0x0D, 0x72, 0x0E,
 * 0x0F -- all seven are loaded.
 *
 * seed round 9: the five overlay call sites now resolve (0x0215536C,
 *           0x02177020 and 0x021798D4 seeded in layout/function_starts.txt);
 *           25 of 27 sites resolved.  The two left are the pooled overlay-id
 *           constants ov_id_72 and ov_id_0E, which have no witness outside
 *           this range, so the file stayed MATCH until the wave 17
 *           `overlay_id` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NET_DEVICE_TABLE_Select.c \
 *       --func NET_DEVICE_TABLE_Select --addr 0x0200F17C --cc 1.1p1 --thumb
 */
int NET_DEVICE_TABLE_Select(u32 sel)
{
    switch (sel) {
    case 6:
        func_02034A5C((u32)ov_id_0A);
        func_02034A5C((u32)ov_id_0B);
        func_02034AC4((u32)ov_id_09);
        func_02034AC4((u32)ov_id_0D);
        func_02034AC4((u32)ov_id_72);
        return (int)GFL_NET_DEVWIFI_GetDeviceTable();
    case 1:
        func_02034A5C((u32)ov_id_0A);
        func_02034A5C((u32)ov_id_0B);
        func_02034AC4((u32)ov_id_09);
        func_02034AC4((u32)ov_id_0D);
        return (int)GFL_NET_DEVWIFI_GetDeviceTable();
    case 2:
        func_02034A5C((u32)ov_id_0A);
        func_02034A5C((u32)ov_id_0B);
        func_02034AC4((u32)ov_id_09);
        func_02034AC4((u32)ov_id_0D);
        return (int)GFL_NET_DEVWIFI_GetDeviceTable();
    case 0:
    case 5:
        func_02034AC4((u32)ov_id_0E);
        return (int)GFL_NET_DEVWIRELESS_GetDeviceTable();
    case 3:
    case 4:
        func_02034AC4((u32)ov_id_0F);
        return (int)IRCNET_GetHandlerTable();
    }
    return 0;
}


void NET_DEVICE_TABLE_Reset(u32 sel)
{
    switch (sel) {
    case 6:
        func_02034A5C((u32)ov_id_72);
        func_02034A5C((u32)ov_id_09);
        func_02034A5C((u32)ov_id_0D);
        func_02034AC4((u32)ov_id_0A);
        func_02034AC4((u32)ov_id_0B);
        break;
    case 1:
        func_02034A5C((u32)ov_id_09);
        func_02034A5C((u32)ov_id_0D);
        func_02034AC4((u32)ov_id_0A);
        func_02034AC4((u32)ov_id_0B);
        break;
    case 2:
        func_02034A5C((u32)ov_id_09);
        func_02034A5C((u32)ov_id_0D);
        func_02034AC4((u32)ov_id_0A);
        func_02034AC4((u32)ov_id_0B);
        break;
    case 0:
    case 5:
        func_02034A5C((u32)ov_id_0E);
        break;
    case 3:
    case 4:
        func_02034A5C((u32)ov_id_0F);
        break;
    }
}
