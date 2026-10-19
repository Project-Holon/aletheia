/*
 * file:     backup_system.c
 * unit:     yes
 * function: BACKUP_SYSTEM_Init, BACKUP_SYSTEM_CreateCore, BACKUP_SYSTEM_Create, BACKUP_SYSTEM_CreateWithWork, BACKUP_SYSTEM_Delete, BACKUP_SYSTEM_GetWork, BACKUP_SYSTEM_GetRecordWork, BACKUP_SYSTEM_ClearWork, BACKUP_SYSTEM_GetDiffSize, BACKUP_SYSTEM_Erase, BACKUP_SYSTEM_Load, BACKUP_SYSTEM_StartSave, BACKUP_SYSTEM_MainSave, BACKUP_SYSTEM_CancelSave, BACKUP_SYSTEM_InitLinkedSave, BACKUP_SYSTEM_MainLinkedSave, BACKUP_SYSTEM_LoadLinked, BACKUP_SYSTEM_GetWrittenSize, BACKUP_SYSTEM_IsFlashBusy, BACKUP_SYSTEM_CalcCrcTableCrc, BACKUP_SYSTEM_GetAreaAddr, BACKUP_SYSTEM_GetCrcTable, BACKUP_SYSTEM_GetFooter, BACKUP_SYSTEM_CheckFooter, BACKUP_SYSTEM_SetFooter, BACKUP_SYSTEM_SetSaveCount, BACKUP_SYSTEM_GetFooterInfo, BACKUP_SYSTEM_GetRecordCount, BACKUP_SYSTEM_LoadDoubleCopy, BACKUP_SYSTEM_LoadSingleCopy, BACKUP_SYSTEM_WriteFooterBody, BACKUP_SYSTEM_WriteFooterLastByte, BACKUP_SYSTEM_InitSaveSeq, BACKUP_SYSTEM_CalcDiffSize, BACKUP_SYSTEM_CompareRecordStep, BACKUP_SYSTEM_WriteRecord, BACKUP_SYSTEM_WriteCrcTable, BACKUP_SYSTEM_SaveSeqMain, BACKUP_SYSTEM_EndSave, BACKUP_SYSTEM_CancelSaveSeq, BACKUP_SYSTEM_EraseFooter, BACKUP_SYSTEM_IncRecordCount, BACKUP_SYSTEM_UpdateRecordCrc, BACKUP_SYSTEM_GetBlockArea, BACKUP_SYSTEM_SetBlockArea, BACKUP_SYSTEM_SwapBlockAreas, BACKUP_SYSTEM_ClearBlockAreas, BACKUP_SYSTEM_FillBlockAreas, BACKUP_SYSTEM_WriteFlash, BACKUP_SYSTEM_WriteFlashAsync, BACKUP_SYSTEM_CheckFlashAsync, BACKUP_SYSTEM_ReadFlash, BACKUP_SYSTEM_ReadRecordFromFlash
 * address:  0x020316C8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from backup_system.c at 0x02033534 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   MATHi_CRC16InitTable  0x020819B8  arm
 *   str_020A7848   0x020A7848  data
 *   svsys     0x02146994  data
 *   SAVEDATA_GetTotalSize  0x02033BF8  arm
 *   GF_PANIC_Fail  0x02034714  arm
 *   str_020A7858   0x020A7858  data
 *   str_020A7868   0x020A7868  data
 *   UI_SetKeepAwakeFlagsGlobal  0x02034F84  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   UI_ClearKeepAwakeFlagsGlobal  0x02034FB8  arm
 *   MATH_CalcCRC16CCITT  0x02081B8C  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   str_020A7888   0x020A7888  data  a1
 *   MI_CpuFill8    0x02082BCC  arm
 *   FLASH_ACCESS_Identify 0x02033534 arm
 *   FLASH_ACCESS_Write 0x020335AC arm
 *   FLASH_ACCESS_Read 0x020335E8 arm
 *   FLASH_ACCESS_StartWrite 0x020336B8 arm
 *   FLASH_ACCESS_PollWrite 0x020337B8 arm
 *   FLASH_ACCESS_CancelWrite 0x0203386C arm
 *   FLASH_ACCESS_GetBusyFlag 0x020338F8 arm
 *   SAVEDATA_CreateTable 0x02033908 arm
 *   SAVEDATA_DeleteTable 0x020339B4 arm
 *   SAVEDATA_InitBuffer 0x020339D0 arm
 *   SAVEDATA_GetBlockOffset 0x02033B68 arm
 *   SAVEDATA_GetBlockSize 0x02033BAC arm
 *   SAVEDATA_GetTableMax 0x02033BF0 arm
 */

#include "../types.h"

#include "../sdk_math.h"

/* The record table built by savedata.c (opaque here). */
typedef struct SaveDataTable SaveDataTable;

/*
 * The backup system work (svsys), allocated once by BACKUP_SYSTEM_Init.  The
 * assert "svsys != NULL" in BACKUP_SYSTEM_CreateCore names the pointer.
 */
typedef struct BackupSystem {
    u32 flash_exists;              /* 0x000 the backup device answered the identify */
    u8  crc_table[0x200];          /* 0x004 MATHCRC16Table, CCITT polynomial */
    void (*read_error_func)(void); /* 0x204 handed to every flash read */
    u32 write_error_func;          /* 0x208 handed to every flash write */
    u16 lock_id;                   /* 0x20C lock of the asynchronous write in flight */
} BackupSystem;

/*
 * The description of one save data area the callers pass to the
 * constructor (save_control.c keeps a table of these).
 */
typedef struct SaveDataParam {
    const void *table_def; /* 0x00 record table definition for savedata.c */
    u32 table_num;         /* 0x04 number of records */
    u32 main_addr;         /* 0x08 flash address of the main copy */
    u32 backup_addr;       /* 0x0C flash address of the backup copy (== main_addr: one copy) */
    u32 savearea_size;     /* 0x10 flash bytes reserved for one copy */
    u32 magic_id;          /* 0x14 id written into the footer */
} SaveDataParam;

/*
 * One save data area (sv).  The assert "svwk_size >= sv->savearea_size" in
 * BACKUP_SYSTEM_CreateCore names the field at +0x08.
 *
 * block_area holds two bits per block: the records of the table, then the
 * CRC table block (index table_num) and the footer (index table_num + 1).
 * The value is the copy the block goes to or comes from: 1 the main copy,
 * 2 the backup copy, 0 none.
 */
typedef struct BackupSaveData {
    u32 area_addr[2];      /* 0x000 flash address of copy 1 (main) and copy 2 (backup) */
    u32 savearea_size;     /* 0x008 */
    u32 magic_id;          /* 0x00C */
    u32 prev_save_count;   /* 0x010 save_count before the running save, restored on failure */
    u32 write_block;       /* 0x014 block the save sequence is at */
    u8  write_seq;         /* 0x018 state of BACKUP_SYSTEM_SaveSeqMain */
    u8  write_pass;        /* 0x019 copies written by the running save */
    u8  pad_1A[2];
    u8  data_exists;       /* 0x01C set by a good load or a failed save, cleared by the erase */
    u8  work_allocated;    /* 0x01D svwk was allocated here (freed by the delete) */
    u8  link_seq;          /* 0x01E state of the linked save (BACKUP_SYSTEM_MainLinkedSave) */
    u8  link_result;       /* 0x01F result of the linked area's last pass */
    u32 *link_count;       /* 0x020 where the linked save stores the other area's save_count */
    u32 reserved;          /* 0x024 cleared by the constructor, never read here */
    u32 save_count;        /* 0x028 generation, written into the footer */
    SaveDataTable *table;  /* 0x02C */
    u32 data_size;         /* 0x030 bytes of one copy: records, CRC table, footer */
    u8 *svwk;              /* 0x034 RAM image of the data */
    u8  compare_buf[0x100];/* 0x038 flash chunk compared against svwk */
    u32 *block_area;       /* 0x138 two bits per block, see above */
    u32 block_area_size;   /* 0x13C bytes of block_area */
    u32 crc_table_size;    /* 0x140 bytes of the CRC table block (u16 per record, 4-aligned) */
    u32 written_size;      /* 0x144 record bytes written by the running save */
    u32 compare_rest;      /* 0x148 resumable compare: bytes left */
    u32 compare_budget;    /* 0x14C resumable compare: bytes since the last yield */
    u32 compare_done;      /* 0x150 resumable compare: bytes done */
} BackupSaveData;

/* The 0x10-byte footer at the end of one copy. */
typedef struct SaveFooter {
    u32 save_count;
    u32 data_size;
    u32 magic_id;
    u16 pad;
    u16 crc;          /* CRC of the CRC table block */
} SaveFooter;

/* The four bytes after the payload of every record. */
typedef struct SaveRecordFooter {
    u16 count;        /* bumped by every save of the record */
    u16 crc;          /* CRC of the payload */
} SaveRecordFooter;

extern void *GFL_HEAP_Alloc(u16 heap_id, u32 size, int align, const char *file,
                         u16 line);
extern void MIi_CpuClear32(u32 value, void *dst, u32 size);
extern void MATHi_CRC16InitTable(struct MATHCRC16Table *table, u16 poly);
extern void GF_PANIC_Fail(const char *file, u32 line, const char *expr);
extern u32 GFL_HEAP_Free(void *mem);
extern void  UI_SetKeepAwakeFlagsGlobal(u8 flags);
extern void UI_ClearKeepAwakeFlagsGlobal(u8 v);
extern u16 MATH_CalcCRC16CCITT(const void *table, const void *data, u32 len);
extern void  MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 size);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);
void BACKUP_SYSTEM_Init(u32 heap_id, u32 read_error_func, u32 write_error_func);
BackupSaveData *BACKUP_SYSTEM_CreateCore(const SaveDataParam *param, u32 heap_id, void *svwk, u32 svwk_size, u32 init_mode);
BackupSaveData *BACKUP_SYSTEM_Create(const SaveDataParam *param, u32 heap_id);
BackupSaveData *BACKUP_SYSTEM_CreateWithWork(const SaveDataParam *param, u32 heap_id, void *svwk, u32 svwk_size, u32 init_mode);
void BACKUP_SYSTEM_Delete(BackupSaveData *sv);
u8 *BACKUP_SYSTEM_GetWork(BackupSaveData *sv, u32 *size);
u8 *BACKUP_SYSTEM_GetRecordWork(BackupSaveData *sv, u32 id);
void BACKUP_SYSTEM_ClearWork(BackupSaveData *sv);
void BACKUP_SYSTEM_GetDiffSize(BackupSaveData *sv, u32 *diff_size, u32 *total_size);
int BACKUP_SYSTEM_Erase(BackupSaveData *sv, u32 heap_id);
int BACKUP_SYSTEM_Load(BackupSaveData *sv, u32 heap_id);
void BACKUP_SYSTEM_StartSave(BackupSaveData *sv);
int BACKUP_SYSTEM_MainSave(BackupSaveData *sv);
void BACKUP_SYSTEM_CancelSave(BackupSaveData *sv);
void BACKUP_SYSTEM_InitLinkedSave(BackupSaveData *main_sv, BackupSaveData *link_sv, u32 *link_count);
int BACKUP_SYSTEM_MainLinkedSave(BackupSaveData *main_sv, BackupSaveData *link_sv);
int BACKUP_SYSTEM_LoadLinked(BackupSaveData *sv, u32 heap_id, u32 link_count);
u32 BACKUP_SYSTEM_GetWrittenSize(const BackupSaveData *sv);
void * BACKUP_SYSTEM_IsFlashBusy(void);
u16 BACKUP_SYSTEM_CalcCrcTableCrc(BackupSaveData *sv, u8 *buf);
u32 BACKUP_SYSTEM_GetAreaAddr(BackupSaveData *sv, u32 area);
u16 *BACKUP_SYSTEM_GetCrcTable(BackupSaveData *sv);
SaveFooter *BACKUP_SYSTEM_GetFooter(BackupSaveData *sv, u8 *buf);
u32 BACKUP_SYSTEM_CheckFooter(BackupSaveData *sv, u8 *buf, u32 area);
void BACKUP_SYSTEM_SetFooter(const BackupSaveData *sv, u8 *buf);
void BACKUP_SYSTEM_SetSaveCount(BackupSaveData *sv, u32 save_count);
void BACKUP_SYSTEM_GetFooterInfo(u32 *result, BackupSaveData *sv, u8 *buf, u32 area);
int BACKUP_SYSTEM_LoadDoubleCopy(BackupSaveData *sv, u32 heap_id, u32 mode, u32 link_count);
int BACKUP_SYSTEM_LoadSingleCopy(BackupSaveData *sv, int mode, int link_count);
int BACKUP_SYSTEM_WriteFooterBody(BackupSaveData *sv, u32 area);
int BACKUP_SYSTEM_WriteFooterLastByte(BackupSaveData *sv, u32 area);
void BACKUP_SYSTEM_InitSaveSeq(BackupSaveData *sv, u32 set_busy);
void BACKUP_SYSTEM_CalcDiffSize(BackupSaveData *sv, u32 *diff_size, u32 *total_size);
u32 BACKUP_SYSTEM_CompareRecordStep(BackupSaveData *sv, u32 id, u32 area, u32 *rest, u32 *budget, u32 *done_size, u32 *yield);
u16 BACKUP_SYSTEM_WriteRecord(BackupSaveData *sv, u32 id, u32 area, u32 pass);
int BACKUP_SYSTEM_WriteCrcTable(BackupSaveData *sv, u32 area);
int BACKUP_SYSTEM_SaveSeqMain(BackupSaveData *sv, u32 *pass_done);
void BACKUP_SYSTEM_EndSave(BackupSaveData *sv, u32 result, u32 clear_busy);
void BACKUP_SYSTEM_CancelSaveSeq(BackupSaveData *sv);
u32 BACKUP_SYSTEM_EraseFooter(BackupSaveData *sv, u32 area);
u16 BACKUP_SYSTEM_IncRecordCount(BackupSaveData *sv, u32 id);
u16 BACKUP_SYSTEM_UpdateRecordCrc(BackupSaveData *sv, u32 id);
u32 BACKUP_SYSTEM_GetBlockArea(BackupSaveData *sv, u32 block);
void BACKUP_SYSTEM_SetBlockArea(BackupSaveData *sv, u32 block, u32 area);
void BACKUP_SYSTEM_SwapBlockAreas(BackupSaveData *sv);
void BACKUP_SYSTEM_ClearBlockAreas(BackupSaveData *sv);
void BACKUP_SYSTEM_FillBlockAreas(BackupSaveData *sv, u32 area);
void BACKUP_SYSTEM_WriteFlash(u32 flash_addr, u32 src, u32 size);
u16 BACKUP_SYSTEM_WriteFlashAsync(u32 flash_addr, u32 src, u32 size);
int BACKUP_SYSTEM_CheckFlashAsync(u16 lock_id, u32 *success);
int BACKUP_SYSTEM_ReadFlash(u32 flash_addr, u32 dst, u32 size);
int BACKUP_SYSTEM_ReadRecordFromFlash(BackupSaveData *sv, u32 id, u32 area_index, u32 dst, u32 size);
/* flash_access.c */
int FLASH_ACCESS_Identify(u32 unused_arg);
u32 FLASH_ACCESS_Write(u32 flash_addr, u32 src, u32 size, u32 write_error_func);
int FLASH_ACCESS_Read(u32 flash_addr, u32 dst, u32 size, void (*read_error_func)(void));
u16 FLASH_ACCESS_StartWrite(u32 flash_addr, u32 ram_src, u32 size, void *on_error);
int FLASH_ACCESS_PollWrite(u16 lock_id, u32 *success, u32 write_error_func);
void FLASH_ACCESS_CancelWrite(u16 lock_id);
void *FLASH_ACCESS_GetBusyFlag(void);
struct SaveBlockDef;
/* savedata.c */
SaveDataTable *SAVEDATA_CreateTable(unsigned short heap_id, struct SaveBlockDef *table, unsigned int table_max, unsigned int size_limit, unsigned int header_size, unsigned int block_overhead, unsigned int footer_size);
void SAVEDATA_DeleteTable(SaveDataTable *table);
void SAVEDATA_InitBuffer(u32 buffer_addr, struct SaveDataTable *svdt);
u32 SAVEDATA_GetBlockOffset(SaveDataTable *table, u32 id);
u32 SAVEDATA_GetBlockSize(SaveDataTable *table, u32 id);
u32 SAVEDATA_GetTableMax(SaveDataTable *table);
u32 SAVEDATA_GetTotalSize(SaveDataTable *table);
extern BackupSystem *svsys;
extern const char str_020A7848[];
extern const u8 str_020A7858[];
extern const u8 str_020A7868[];
extern const char str_020A7888[];

/*
 * Blocked at MATCH on the `label`/`matched` classes: all 124 concrete bytes
 * of the body reproduce and 6 of 7 relocation sites resolve, but
 * FLASH_ACCESS_Identify (PC24 at +0x6c) has exactly one branch reference image-wide
 * and it is this call, so the site has no witness outside 020316C8..0203174C
 * and no cut frees it.  Filing 0x02033534 as an EXACT manifest entry promotes
 * this file with no change to the C.
 *
 * backup_system.c: the one-time allocation of the 0x210-byte save block.
 * The first parameter is narrowed to 16 bits at function entry (the split
 * `lsl r0, r0, #0x10` / `lsr r0, r0, #0x10` pair); written with the mask
 * folded into the call site.
 * The file string is at 0x020A7848 ("backup_system.c", pool word at
 * 0x02031744) and __LINE__ = 0xdf.  The second size argument 0x1100 - 0xdf
 * is spelled as the subtraction because 0x1021 is not an ARM-encodable
 * immediate and mwcc had 0xdf live in a register from the allocator's line
 * argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/BACKUP_SYSTEM_Init.c \
 *       --func BACKUP_SYSTEM_Init --addr 0x020316C8 --cc 1.1p1 --arm
 */
void BACKUP_SYSTEM_Init(u32 heap_id, u32 read_error_func, u32 write_error_func)
{
    BackupSystem *work = GFL_HEAP_Alloc((u16)heap_id, 0x210, 0, str_020A7848, 0xdf);

    svsys = work;
    MIi_CpuClear32(0, work, 0x210);
    MATHi_CRC16InitTable((struct MATHCRC16Table *)svsys->crc_table, 0x1100 - 0xdf);
    svsys->read_error_func = (void (*)(void))read_error_func;
    work = svsys;
    work->write_error_func = write_error_func;
    svsys->flash_exists = FLASH_ACCESS_Identify((u32)work);
}

/*
 * backup_system.c.  The save-block constructor; its already-matched caller
 * src/matched/BACKUP_SYSTEM_Create.c fixes the five-argument signature.  The
 * allocator GFL_HEAP_Alloc takes (heap, size, align, __FILE__, __LINE__)
 * with the line on the stack: 0x10e, 0x125 and 0x131.  0x154 is the block
 * size, kept live in sb, and the second assert's line 0x116 is derived from
 * it as `sub r1, sb, #0x3e` and the last allocation's 0x131 as
 * `add r0, sb, #0x130`
 * (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).
 * The `in` parameter must be `const`: without it an unrelated store may
 * alias the fields and the compiler reloads them, 151 concrete bytes out at
 * the same 480
 * (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md).
 * The heap id is narrowed per call site because the callee prototypes take
 * `u16`; a `(u16)heap` cast in the body is CSEd into one register instead.
 * The two size roundings are the `((n + k) >> s) << t` shape written out,
 * with the `tst`/`addne` correction being the low-bit remainder test the
 * front end derives from `+ 2` / `& 0xf`.
 */
BackupSaveData *BACKUP_SYSTEM_CreateCore(const SaveDataParam *param, u32 heap_id, void *svwk, u32 svwk_size, u32 init_mode)
{
    BackupSaveData *sv;
    u32 n;
    SaveDataTable *table;

    if (svsys == 0)
        GF_PANIC_Fail(str_020A7848, 0x10c, (const char *)str_020A7858);

    sv = GFL_HEAP_Alloc(heap_id, 0x154, 1, str_020A7848, 0x10e);
    sv->area_addr[0] = param->main_addr;
    sv->area_addr[1] = param->backup_addr;
    sv->savearea_size = param->savearea_size;
    sv->magic_id = param->magic_id;

    if (svwk != 0 && svwk_size < sv->savearea_size)
        GF_PANIC_Fail(str_020A7848, 0x154 - 0x3e, (const char *)str_020A7868);

    sv->crc_table_size = param->table_num << 1;
    if ((param->table_num & 1) != 0)
        sv->crc_table_size = sv->crc_table_size + 2;

    n = param->table_num + 2;
    sv->block_area_size = (n >> 4) << 2;
    if ((n & 0xf) != 0)
        sv->block_area_size = sv->block_area_size + 4;

    sv->block_area = GFL_HEAP_Alloc(heap_id, sv->block_area_size, 1, str_020A7848,
                                 0x125);
    table = SAVEDATA_CreateTable((u16)heap_id, (struct SaveBlockDef *)param->table_def, param->table_num, sv->savearea_size, 0x10, 4, sv->crc_table_size);
    sv->table = table;
    sv->data_size = SAVEDATA_GetTotalSize(table);
    if (svwk != 0) {
        sv->svwk = svwk;
        sv->work_allocated = 0;
    } else {
        sv->svwk = GFL_HEAP_Alloc(heap_id, sv->savearea_size, 1, str_020A7848,
                                    0x131);
        sv->work_allocated = 1;
    }
    sv->data_exists = 0;
    sv->save_count = 0;
    sv->reserved = 0;
    if (init_mode == 1)
        BACKUP_SYSTEM_ClearWork(sv);
    else
        BACKUP_SYSTEM_FillBlockAreas(sv, 1);
    return sv;
}

/*
 * backup_system.c.  A one-line forwarder: its two arguments go straight
 * through to 0x0203174C together with three zero/one flags, the fifth landing
 * on the stack.  The two zero arguments cost a single `mov r2, #0` plus the
 * `mov r3, r2` copy the compiler makes instead of a second move, and the `1`
 * is materialised into `ip` because an ARM `str` has no immediate form.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_Create.c \
 *       --func BACKUP_SYSTEM_Create --addr 0x0203192C --cc 1.1p1 --arm
 */
BackupSaveData *BACKUP_SYSTEM_Create(const SaveDataParam *param, u32 heap_id)
{
    return BACKUP_SYSTEM_CreateCore(param, heap_id, 0, 0, 1);
}

/*
 * The public constructor for a caller-supplied work buffer: forwards all
 * five arguments.  The FSi_ name is a false SDK match (layout/symbols_sdk.json
 * lists it as rejected at this address); rename_map.tsv gives the game name.
 */
BackupSaveData *BACKUP_SYSTEM_CreateWithWork(const SaveDataParam *param, u32 heap_id, void *svwk, u32 svwk_size, u32 init_mode)
{
    return BACKUP_SYSTEM_CreateCore(param, heap_id, svwk, svwk_size, init_mode);
}

/*
 * A four-store teardown of one record: release the object at +0x2c, the one
 * at +0x138 unconditionally, the one at +0x34 only when the byte at +0x1d is
 * exactly 1, then the record itself.  The release callee is the overruled
 * SDK address 0x020307B0 (layout/symbols_sdk.txt calls it ENV_SetResourceSet,
 * the game code proves otherwise); it is already matched, which is what
 * attests the three PC24 sites.  0x020339B4, the +0x2c argument's own
 * destructor, was matched in the same wave and attests the fourth.
 *
 * The leaf follower at 0x02031994 (a two-field getter, no prologue) carries
 * no label, so the inferred extent from this address runs long: EXACT*.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_Delete.c \
 *       --func BACKUP_SYSTEM_Delete --addr 0x0203195C --arm --cc 1.1p1
 */
void BACKUP_SYSTEM_Delete(BackupSaveData *sv)
{
    SAVEDATA_DeleteTable(sv->table);
    GFL_HEAP_Free(sv->block_area);
    if (sv->work_allocated == 1) {
        GFL_HEAP_Free(sv->svwk);
    }
    GFL_HEAP_Free(sv);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_GetWork.c \\
 *       --func BACKUP_SYSTEM_GetWork --addr 0x02031994 --arm --cc 1.1p1
 */
u8 *BACKUP_SYSTEM_GetWork(BackupSaveData *sv, u32 *size)
{
    *size = sv->data_size;
    return sv->svwk;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_GetRecordWork.c \\
 *       --func BACKUP_SYSTEM_GetRecordWork --addr 0x020319A4 --arm --cc 1.1p1
 */
u8 *BACKUP_SYSTEM_GetRecordWork(BackupSaveData *sv, u32 id)
{
    return SAVEDATA_GetBlockOffset(sv->table, id) + sv->svwk;
}

/*
 * promoted: from src/pending on 2026-09-19, no C change: its blocker is filed,
 *           every relocation site resolves and match.py one reports EXACT*.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_ClearWork.c \\
 *       --func BACKUP_SYSTEM_ClearWork --addr 0x020319C0 --arm --cc 1.1p1
 */
void BACKUP_SYSTEM_ClearWork(BackupSaveData *sv)
{
    SAVEDATA_InitBuffer((u32)sv->svwk, sv->table);
    BACKUP_SYSTEM_FillBlockAreas(sv, 1);
}

void BACKUP_SYSTEM_GetDiffSize(BackupSaveData *sv, u32 *diff_size, u32 *total_size)
{
    BACKUP_SYSTEM_CalcDiffSize(sv, diff_size, total_size);
}

/*
 * Erase the whole backup device in 0x1000-byte pages.  A 0x1000-byte scratch
 * page is allocated on the heap named by the u16 second argument (the
 * __FILE__ is "backup_system.c" at 0x020A7848 and the __LINE__ is 0x1e8),
 * filled with 0xff by MIi_CpuClear32, and written over every page of the
 * device: the job's +8 word is the total length, its +0 word the destination
 * base, and the device handle comes from the +0x208 field of the object
 * behind the global at 0x02146994, re-read once per page along with the base.
 *
 * The literal 1 is materialised ONCE into r4 and reused as the second
 * argument of the first BACKUP_SYSTEM_EraseFooter call
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md);
 * the second call's 2 is its own `mov`.  The 0x1000 page size is materialised
 * twice, once for the allocation and once into callee-saved r8 for the loop,
 * because the fill call in between clobbers it.
 *
 * The lengths compare unsigned (`bls`/`blo`), so a zero-length device skips
 * the loop entirely; the +4 word is a second length whose inequality with
 * +0 triggers an extra BACKUP_SYSTEM_EraseFooter(obj, 2) pass before the fill.
 *
 * Declaration order is one/off/page, which is what shares r4 between the
 * literal 1 and the loop cursor and leaves r5 for the scratch page
 * (docs/idioms/declaration-order-decides-which-register-a-local-gets.md);
 * page-first gives the exact same 240 bytes with r4 and r5 swapped, 12 out.
 * The heap id is a u32 parameter truncated at the call site, not a u16
 * parameter: the explicit `(u16)` is what produces the `lsl`/`lsr` pair at
 * +0x0008/+0x0018, and a u16 parameter folds it to a single `mov` for 236.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_Erase.c \
 *       --func BACKUP_SYSTEM_Erase --addr 0x020319F0 --cc 1.1p1 --arm
 */
int BACKUP_SYSTEM_Erase(BackupSaveData *sv, u32 heap_id)
{
    u32 one;
    u32 off;
    void *page;

    page = GFL_HEAP_Alloc((u16)heap_id, 0x1000, 0, str_020A7848, 0x1e8);

    one = 1;
    UI_SetKeepAwakeFlagsGlobal(one);
    BACKUP_SYSTEM_EraseFooter(sv, one);
    if (sv->area_addr[0] != sv->area_addr[1])
        BACKUP_SYSTEM_EraseFooter(sv, 2);

    MIi_CpuClear32(0xFFFFFFFF, page, 0x1000);

    for (off = 0; off < sv->savearea_size; off += 0x1000)
        FLASH_ACCESS_Write(off + sv->area_addr[0], (u32)page, 0x1000, svsys->write_error_func);

    GFL_HEAP_Free(page);
    BACKUP_SYSTEM_ClearWork(sv);
    sv->data_exists = 0;

    UI_ClearKeepAwakeFlagsGlobal(1);
    return 1;
}

/*
 * Dispatch one step of the object's state machine: if the manager global's
 * front object is unarmed the call reports 4 immediately; otherwise the
 * object is either re-armed (its two queue cursors agree) or advanced, and
 * the call's status is dispatched through the dense switch that runs from
 * case 0 to case 4.  The armed transition stamps the progress byte at +0x1c.
 *
 * Two spellings were load-bearing in reaching EXACT, both worth keeping:
 *   - if/else polarity: the unequal arm is written first so it becomes the
 *     fall-through arm and the equal arm goes out of line at +0x40;
 *   - the case order 1, 2, 3, 0, 4: mwcc lays the arm bodies out in source
 *     order and the original's case-0 body sits after case 3's, at +0x90.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_Load.c \
 *       --func BACKUP_SYSTEM_Load --addr 0x02031AE0 --cc 1.1p1 --arm
 */
int BACKUP_SYSTEM_Load(BackupSaveData *sv, u32 heap_id)
{
    u32 result;

    if (svsys->flash_exists == 0)
        return 4;

    if (sv->area_addr[0] != sv->area_addr[1])
        result = BACKUP_SYSTEM_LoadDoubleCopy(sv, heap_id, 0, 0);
    else
        result = BACKUP_SYSTEM_LoadSingleCopy(sv, 0, 0);

    switch (result) {
    case 1:
        sv->data_exists = 1;
        return 1;
    case 2:
        sv->data_exists = 1;
        return 2;
    case 3:
        return 3;
    case 0:
        return 0;
    case 4:
        return 4;
    }
    return 4;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_StartSave.c \\
 *       --func BACKUP_SYSTEM_StartSave --addr 0x02031B8C --arm --cc 1.1p1
 */
void BACKUP_SYSTEM_StartSave(BackupSaveData *sv)
{
    if (svsys->flash_exists != 0) {
        BACKUP_SYSTEM_InitSaveSeq(sv, 1);
    }
}

/*
 * Blocked at MATCH on the `label`/`matched` classes: 75 of 76 bytes
 * reproduce and the only unresolved site is the PC24 at +0x24 to
 * BACKUP_SYSTEM_SaveSeqMain, whose single branch reference image-wide is this call, so
 * there is no witness outside 02031BB4..02031C04.  Filing 0x02032CD0 as an
 * EXACT manifest entry promotes this file with no change to the C.
 *
 * 0x02031BB4 is called from 0x02031B88 (the same packet's neighbour) and the
 * stack slot it hands BACKUP_SYSTEM_SaveSeqMain is the pushed r3 scratch word, so the
 * local's address is taken but its value is never read here.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/BACKUP_SYSTEM_MainSave.c \
 *       --func BACKUP_SYSTEM_MainSave --addr 0x02031BB4 --cc 1.1p1 --arm
 */
int BACKUP_SYSTEM_MainSave(BackupSaveData *sv)
{
    int result;
    u32 pass_done;

    if (svsys->flash_exists == 0)
        return 3;
    result = BACKUP_SYSTEM_SaveSeqMain(sv, &pass_done);
    if (result != 0 && result != 1)
        BACKUP_SYSTEM_EndSave(sv, result, 1);
    return result;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_CancelSave.c \\
 *       --func BACKUP_SYSTEM_CancelSave --addr 0x02031C04 --arm --cc 1.1p1
 */
void BACKUP_SYSTEM_CancelSave(BackupSaveData *sv)
{
    BACKUP_SYSTEM_CancelSaveSeq(sv);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_InitLinkedSave.c \\
 *       --func BACKUP_SYSTEM_InitLinkedSave --addr 0x02031C10 --arm --cc 1.1p1
 */
void BACKUP_SYSTEM_InitLinkedSave(BackupSaveData *main_sv, BackupSaveData *link_sv, u32 *link_count)
{
    main_sv->link_count = link_count;
    main_sv->link_seq = 0;
    main_sv->link_result = 2;
    link_sv->link_seq = 0;
    link_sv->link_result = 2;
}

/*
 * Drive a two-copy save through BACKUP_SYSTEM_SaveSeqMain (the write state machine),
 * one step per call, on the state byte at q+0x1E: open a generation on `p`
 * (BACKUP_SYSTEM_InitSaveSeq), write `p`, copy its generation word to *q->link_count and open one
 * on `q`, write `q` (on failure also report it against `p` when p's two
 * area words differ), finish `p` if its two area words differ, then finish
 * `q`, answering 3 when p's result byte says so.  Both objects are the same
 * save-record type (both go to BACKUP_SYSTEM_SaveSeqMain and BACKUP_SYSTEM_EndSave).
 * Wave 11, 2026-09-23.
 *
 * The one lever the 2026-09-21 lanes named and did not reach: case 4 is
 * written with the UNEQUAL test first and the bare `q->link_seq++` in the `else`
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).  That moves the
 * `state = s + 1` block out of line (0x02031D78) and lets case 1's
 * `state++; break;` share case 4's `b 0x02031C70`.  All four BACKUP_SYSTEM_SaveSeqMain
 * result tests are negated (`r != 0 && r != 1`), per the note.
 */
int BACKUP_SYSTEM_MainLinkedSave(BackupSaveData *main_sv, BackupSaveData *link_sv)
{
    u32 pass_done;
    int result;

    switch (main_sv->link_seq) {
    case 0:
        BACKUP_SYSTEM_InitSaveSeq(link_sv, 1);
        main_sv->link_seq++;
        break;
    case 1:
        result = BACKUP_SYSTEM_SaveSeqMain(link_sv, &pass_done);
        if (result != 0 && result != 1) {
            BACKUP_SYSTEM_EndSave(link_sv, result, 1);
            if (result == 3)
                return 3;
            main_sv->link_seq++;
            break;
        }
        if (pass_done == 1)
            main_sv->link_seq++;
        break;
    case 2:
        *main_sv->link_count = link_sv->save_count;
        BACKUP_SYSTEM_InitSaveSeq(main_sv, 0);
        main_sv->link_seq++;
        break;
    case 3:
        result = BACKUP_SYSTEM_SaveSeqMain(main_sv, &pass_done);
        if (result != 0 && result != 1) {
            BACKUP_SYSTEM_EndSave(main_sv, result, 1);
            if (link_sv->area_addr[0] != link_sv->area_addr[1])
                BACKUP_SYSTEM_EndSave(link_sv, result, 1);
            return 3;
        }
        if (pass_done == 1)
            main_sv->link_seq++;
        break;
    case 4:
        if (link_sv->area_addr[0] != link_sv->area_addr[1]) {
            result = BACKUP_SYSTEM_SaveSeqMain(link_sv, &pass_done);
            if (result != 0 && result != 1) {
                BACKUP_SYSTEM_EndSave(link_sv, result, 0);
                link_sv->link_result = result;
                main_sv->link_seq++;
            }
        } else {
            main_sv->link_seq++;
        }
        break;
    case 5:
        result = BACKUP_SYSTEM_SaveSeqMain(main_sv, &pass_done);
        if (result != 0 && result != 1) {
            BACKUP_SYSTEM_EndSave(main_sv, result, 1);
            if (link_sv->link_result == 3)
                result = 3;
            return result;
        }
        break;
    }
    return 0;
}

/*
 * Drive one step of the object's state machine.  The engine pointer is read
 * through the global at 0x02146994 twice (`ldr ip,[pc]; ldr ip,[ip]; cmp`),
 * so the declaration is a `u32 *` and a null engine reports 4 without
 * touching anything.  The object's +0x00 and +0x04 words then pick which of
 * the two engine entry points runs - different words take BACKUP_SYSTEM_LoadDoubleCopy with
 * the object, the first argument, a hard 1 and the third argument, equal
 * words take BACKUP_SYSTEM_LoadSingleCopy - and that call's status picks the arm: 1 and 2
 * also set the +0x1C byte, 0/3/4 report themselves and anything above 4
 * reports 4.
 *
 * The case labels are NOT in numeric order in the source.  Written
 * `case 0: return 0; case 1: ... case 2: ... case 3: return 3; case 4:
 * return 4;` the five arms come out in the table's own order and the
 * function is 8 bytes of DIFF (every arm's body is 8 bytes early, case 0's
 * body lands first instead of just before case 4's).  mwccarm emits the
 * bodies in the order the labels are written, so the source order here is
 * 1, 2, 3, 0, 4 - which is what reproduces the listing: the table's entry 0
 * branches past the three arms to 0x02031E4C.
 *
 * EXACT* rather than EXACT: the byte comparison passes at all 168 bytes (164
 * of code plus the pool word for 0x02146994) and all three sites resolve,
 * but the listing's next label is beyond 0x02031E68, where the follower at
 * 0x02031E68 (`ldr r0,[r0,#0x144]; bx lr`) has no func_ entry point, so the
 * inferred extent runs long.  Report the unlabelled follower rather than
 * edit layout/function_starts.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_LoadLinked.c \
 *       --func BACKUP_SYSTEM_LoadLinked --addr 0x02031DC0 --cc 1.1p1 --arm
 */
int BACKUP_SYSTEM_LoadLinked(BackupSaveData *sv, u32 heap_id, u32 link_count)
{
    int result;

    if (svsys->flash_exists == 0)
        return 4;
    if (sv->area_addr[0] != sv->area_addr[1])
        result = BACKUP_SYSTEM_LoadDoubleCopy(sv, heap_id, 1, link_count);
    else
        result = BACKUP_SYSTEM_LoadSingleCopy(sv, 1, link_count);
    switch (result) {
    case 1:
        sv->data_exists = 1;
        return 1;
    case 2:
        sv->data_exists = 1;
        return 2;
    case 3:
        return 3;
    case 0:
        return 0;
    case 4:
        return 4;
    }
    return 4;
}

u32 BACKUP_SYSTEM_GetWrittenSize(const BackupSaveData *sv)
{
    return sv->written_size;
}

void * BACKUP_SYSTEM_IsFlashBusy(void)
{
    return FLASH_ACCESS_GetBusyFlag();
}

/*
 * backup_system.c.  The CRC-16/CCITT of one backup record: the table is the
 * CRC table that lives inline at +4 of the object at 0x02146994 (the same
 * `struct { u8 pad000[4]; u8 crcTable[1]; }` shape src/matched/BACKUP_SYSTEM_UpdateRecordCrc.c
 * uses), the data starts at `buf + p->data_size - 0x10 - p->crc_table_size` and runs for
 * p->crc_table_size bytes.  The result is what src/matched/BACKUP_SYSTEM_CheckFooter.c compares
 * against the footer halfword and what src/matched/BACKUP_SYSTEM_SetFooter.c stores
 * into it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_CalcCrcTableCrc.c \
 *       --func BACKUP_SYSTEM_CalcCrcTableCrc --addr 0x02031E7C --cc 1.1p1 --arm
 */
u16 BACKUP_SYSTEM_CalcCrcTableCrc(BackupSaveData *sv, u8 *buf)
{
    return MATH_CalcCRC16CCITT(svsys->crc_table,
                               buf + (sv->data_size - 0x10 - sv->crc_table_size),
                               sv->crc_table_size);
}

/*
 * backup_system.c.  The flash address of one copy: area 2 gets the backup
 * copy's address, any other area the main copy's.  When the two addresses
 * are equal (an area with one copy) the main address is returned at once.
 * Callers feed the answer straight to a flash read or write, e.g.
 * `FLASH_ACCESS_Read(BACKUP_SYSTEM_GetAreaAddr(sv, 1), work, sv->data_size, ...)`.
 *
 * Both loads happen in source order (+4 first), and the equal case returns the
 * word already in r0, so the tail is a bare `bxeq lr`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_GetAreaAddr.c \
 *       --func BACKUP_SYSTEM_GetAreaAddr --addr 0x02031EAC --cc 1.1p1 --arm
 */
u32 BACKUP_SYSTEM_GetAreaAddr(BackupSaveData *sv, u32 area)
{
    u32 addr;

    addr = sv->area_addr[1];
    if (sv->area_addr[0] == addr)
        return sv->area_addr[0];
    if (area != 2)
        addr = sv->area_addr[0];
    return addr;
}

u16 *BACKUP_SYSTEM_GetCrcTable(BackupSaveData *sv)
{
    return (u16 *)(sv->svwk + ((sv->data_size - 0x10) - sv->crc_table_size));
}

SaveFooter *BACKUP_SYSTEM_GetFooter(BackupSaveData *sv, u8 *buf)
{
    return (SaveFooter *)(buf + (sv->data_size - 0x10));
}

/*
 * backup_system.c.  Verifies one copy of a backup area and returns 0 when both
 * words of its footer agree with the descriptor, 1 when the running check
 * disagrees, 2 when the length or the sequence number disagrees.
 *
 * The footer descriptor comes from BACKUP_SYSTEM_GetFooter(p, buf) (src/matched/
 * BACKUP_SYSTEM_GetFooter.c): it is `buf + p->data_size - 0x10`.  Word +4 and word +8 of that
 * footer are compared against p->data_size and p->unkC, and the halfword at +0xE is
 * compared against BACKUP_SYSTEM_CalcCrcTableCrc(p, buf), the CRC16 of the area (the packet's
 * only SDK call).  Only 0x02031F9C calls this function anywhere in the image,
 * which is why that file was parked at MATCH until this one landed; it can now
 * be promoted.
 *
 * The third parameter is dead in the body (the original never reads r2) and the
 * callers pass nothing for it; it is kept in the declaration only because
 * src/matched/BACKUP_SYSTEM_GetFooterInfo.c declares the same three-argument prototype.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_CheckFooter.c \
 *       --func BACKUP_SYSTEM_CheckFooter --addr 0x02031EF8 --cc 1.1p1 --arm
 */
u32 BACKUP_SYSTEM_CheckFooter(BackupSaveData *sv, u8 *buf, u32 area)
{
    SaveFooter *footer;

    footer = BACKUP_SYSTEM_GetFooter(sv, buf);

    if (footer->data_size != sv->data_size)
        return 2;
    if (footer->magic_id != sv->magic_id)
        return 2;
    if (footer->crc != BACKUP_SYSTEM_CalcCrcTableCrc(sv, buf))
        return 1;
    return 0;
}

/*
 * backup_system.c.  Writes the footer descriptor that BACKUP_SYSTEM_CheckFooter verifies,
 * at BACKUP_SYSTEM_GetFooter(p, buf) (buf + p->data_size - 0x10): generation p->save_count,
 * size p->data_size, id p->magic_id, then the CRC-16/CCITT from BACKUP_SYSTEM_CalcCrcTableCrc at
 * +0x0E.  Closed wave 12: the record pointer is `const`.  With a non-const
 * pointer every field load stays below the previous footer store (the
 * compiler must assume they alias) and six instructions come out in the
 * wrong order; with const the loads float above the stores exactly as the
 * image has them (docs/idioms/const-pointer-lets-a-field-load-survive-a-
 * store.md).  dsi/1.1p1 only; ../2.0/sp2 keeps the 16-byte residue.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/BACKUP_SYSTEM_SetFooter.c \
 *       --func BACKUP_SYSTEM_SetFooter --addr 0x02031F54 --arm
 */
void BACKUP_SYSTEM_SetFooter(const BackupSaveData *sv, u8 *buf)
{
    SaveFooter *footer = BACKUP_SYSTEM_GetFooter((BackupSaveData *)sv, buf);
    footer->save_count = sv->save_count;
    footer->data_size = sv->data_size;
    footer->magic_id = sv->magic_id;
    footer->crc = BACKUP_SYSTEM_CalcCrcTableCrc((BackupSaveData *)sv, buf);
}

void BACKUP_SYSTEM_SetSaveCount(BackupSaveData *sv, u32 save_count)
{
    sv->save_count = save_count;
}

/*
 * PROMOTED TO EXACT.  This file was parked at MATCH because its only open
 * relocation site was the `bl` to 0x02031EF8: that function's one and only
 * branch in the whole image is the one inside this file
 * (match.image_call_sites(0x02031EF8) == [0x02031FCC]), so the `label` class
 * had no outside witness and there was no literal or runtime witness either.
 * 0x02031EF8 is now matched itself (src/matched/BACKUP_SYSTEM_CheckFooter.c), so the site
 * resolves in the `matched` class and every byte here is attested.
 *
 * backup_system.c.  Fills the two-word record descriptor `out` for one of the
 * two copies of a backup area: word 0 is the verification answer from
 * 0x02031EF8 (0 both words of the footer agree, 1 the running check disagrees,
 * 2 the length or the sequence number disagrees), word 1 is the first word of
 * that footer, reached through 0x02031EE8, buf + (p->data_size - 0x10).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_GetFooterInfo.c \
 *       --func BACKUP_SYSTEM_GetFooterInfo --addr 0x02031F9C --cc 1.1p1 --arm
 */
void BACKUP_SYSTEM_GetFooterInfo(u32 *result, BackupSaveData *sv, u8 *buf, u32 area)
{
    SaveFooter *footer;

    footer = BACKUP_SYSTEM_GetFooter(sv, buf);
    result[0] = BACKUP_SYSTEM_CheckFooter(sv, buf, area);
    result[1] = footer->save_count;
}

static inline u16 BACKUP_SYSTEM_GetRecordCount(SaveRecordFooter *rec)
{
    return rec->count;
}

/*
 * backup_system.c.  The two-copy load: read both copies of the save area
 * (FLASH_ACCESS_Read at BACKUP_SYSTEM_GetAreaAddr(self, 1) into the staging buffer self->svwk
 * and at (self, 2) into a heap block from GFL_HEAP_Alloc, line 0x429), repair
 * one copy from the other when only one read failed, check both footers
 * (BACKUP_SYSTEM_GetFooterInfo, the mode == 1 generation test), cross-copy the footer block
 * when exactly one is bad, pick the newer good copy, then walk every record
 * checking its CRC against both copies, marking each record 0/1/2 through
 * BACKUP_SYSTEM_SetBlockArea and retrying with the other copy if the walk breaks.  A
 * completed walk copies the marked records back and commits the generation
 * (BACKUP_SYSTEM_SetSaveCount).  The two-copy twin of BACKUP_SYSTEM_LoadSingleCopy
 * (docs/notes/pkt_02031FE0.c.txt holds the history from wave 11).
 *
 * Closed wave 19 by `unsigned long AB` together with the declaration order
 * AB, pa, pb, i, A, B: the long-typed A + B colours apart from the u32
 * locals (image: AB r4, B r8, A r7).  Either change alone is 13 or 22 bytes
 * out; the earlier 9-byte residue was this one register swap.  The inline
 * cnt16 on the two record-counter compares and the one-argument
 * BACKUP_SYSTEM_ClearBlockAreas are load-bearing (wave 12); GFL_HEAP_Alloc uses its real
 * prototype with an explicit (u16) heap.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/BACKUP_SYSTEM_LoadDoubleCopy.c \
 *       --func BACKUP_SYSTEM_LoadDoubleCopy --addr 0x02031FE0 --arm
 */
int BACKUP_SYSTEM_LoadDoubleCopy(BackupSaveData *sv, u32 heap_id, u32 mode, u32 link_count)
{
    u32 info2[2];
    u32 info1[2];
    u8 *works[2];
    u32 counts[2];
    u32 areas[2];
    u8 *work1;
    u16 *crc_table;
    u8 *cur_work;
    u32 pass;
    u8 *work2;
    int read1;
    int read2;
    unsigned long footer_ofs;
    SaveRecordFooter *rec1;
    SaveRecordFooter *rec2;
    u32 id;
    u32 ofs;
    u32 size;
    u32 crc_ofs;

    BACKUP_SYSTEM_ClearBlockAreas(sv);
    work1 = sv->svwk;
    work2 = GFL_HEAP_Alloc((u16)heap_id, sv->data_size, 0, str_020A7848, 0x429);
    read1 = FLASH_ACCESS_Read(BACKUP_SYSTEM_GetAreaAddr(sv, 1), (u32)work1, sv->data_size, svsys->read_error_func);
    read2 = FLASH_ACCESS_Read(BACKUP_SYSTEM_GetAreaAddr(sv, 2), (u32)work2, sv->data_size, svsys->read_error_func);
    if (read1 == 0 && read2 == 0) {
        BACKUP_SYSTEM_FillBlockAreas(sv, 1);
        MIi_CpuClear32(0, work1, sv->data_size);
        GFL_HEAP_Free(work2);
        return 0;
    }
    if (read1 == 1 && read2 == 0) {
        BACKUP_SYSTEM_FillBlockAreas(sv, 2);
        MIi_CpuCopy16(work1, work2, sv->data_size);
    } else if (read1 == 0 && read2 == 1) {
        BACKUP_SYSTEM_FillBlockAreas(sv, 1);
        MIi_CpuCopy16(work2, work1, sv->data_size);
    }

    BACKUP_SYSTEM_GetFooterInfo(info1, sv, work1, 0);
    BACKUP_SYSTEM_GetFooterInfo(info2, sv, work2, 1);
    if (mode == 1) {
        if (info1[1] != link_count)
            info1[0] = 2;
        if (info2[1] != link_count)
            info2[0] = 2;
    }

    if (info1[0] == 0) {
        if (info2[0] != 0) {
        BACKUP_SYSTEM_SetBlockArea(sv, SAVEDATA_GetTableMax(sv->table), 2);
        BACKUP_SYSTEM_SetBlockArea(sv, SAVEDATA_GetTableMax(sv->table) + 1, 2);
        crc_ofs = sv->data_size - 0x10 - sv->crc_table_size;
        MIi_CpuCopy16(work1 + crc_ofs, work2 + crc_ofs, sv->crc_table_size + 0x10);
        }
    } else if (info2[0] == 0) {
        if (info1[0] != 0) {
        BACKUP_SYSTEM_SetBlockArea(sv, SAVEDATA_GetTableMax(sv->table), 1);
        BACKUP_SYSTEM_SetBlockArea(sv, SAVEDATA_GetTableMax(sv->table) + 1, 1);
        crc_ofs = sv->data_size - 0x10 - sv->crc_table_size;
        MIi_CpuCopy16(work2 + crc_ofs, work1 + crc_ofs, sv->crc_table_size + 0x10);
        }
    } else {
        if (info1[0] == 1 || info2[0] == 1) {
            BACKUP_SYSTEM_FillBlockAreas(sv, 1);
            GFL_HEAP_Free(work2);
            return 3;
        }
        BACKUP_SYSTEM_FillBlockAreas(sv, 1);
        GFL_HEAP_Free(work2);
        return 0;
    }

    if (info1[0] == 0
        && ((info1[1] == 0 && info2[1] == 0xFFFFFFFF) || info1[1] >= info2[1]
            || info2[0] != 0)) {
        works[0] = work1;
        works[1] = work2;
        areas[0] = 1;
        areas[1] = 2;
        counts[0] = info1[1];
        counts[1] = info2[1];
    } else {
        areas[0] = 2;
        works[0] = work2;
        works[1] = work1;
        areas[1] = 1;
        counts[0] = info2[1];
        counts[1] = info1[1];
    }

    for (pass = 0; pass < 2; pass++) {
        crc_ofs = sv->data_size - 0x10 - sv->crc_table_size;
        cur_work = works[pass];
        crc_table = (u16 *)(works[pass] + crc_ofs);
        for (id = 0; id < SAVEDATA_GetTableMax(sv->table); id++) {
            ofs = SAVEDATA_GetBlockOffset(sv->table, id);
            size = SAVEDATA_GetBlockSize(sv->table, id);
            footer_ofs = ofs + size;
            rec1 = (SaveRecordFooter *)(work1 + footer_ofs);
            rec2 = (SaveRecordFooter *)(work2 + footer_ofs);
            BACKUP_SYSTEM_SetBlockArea(sv, id, 0);
            if (rec1->crc != crc_table[id]
                && rec2->crc != crc_table[id])
                break;
            if (rec1->crc == crc_table[id]) {
                if (rec1->crc != MATH_CalcCRC16CCITT(svsys->crc_table, work1 + ofs, size))
                    BACKUP_SYSTEM_SetBlockArea(sv, id, 1);
            } else {
                BACKUP_SYSTEM_SetBlockArea(sv, id, 1);
            }
            if (rec2->crc == crc_table[id]) {
                if (rec2->crc != MATH_CalcCRC16CCITT(svsys->crc_table, work2 + ofs, size)) {
                    if (BACKUP_SYSTEM_GetBlockArea(sv, id) == 1)
                        break;
                    BACKUP_SYSTEM_SetBlockArea(sv, id, 2);
                }
            } else {
                if (BACKUP_SYSTEM_GetBlockArea(sv, id) == 1)
                    break;
                BACKUP_SYSTEM_SetBlockArea(sv, id, 2);
            }
            if (BACKUP_SYSTEM_GetBlockArea(sv, id) == 0) {
                if (BACKUP_SYSTEM_GetRecordCount(rec1) != ((SaveRecordFooter *)(works[pass] + footer_ofs))->count)
                    BACKUP_SYSTEM_SetBlockArea(sv, id, 1);
                if (BACKUP_SYSTEM_GetRecordCount(rec2) != ((SaveRecordFooter *)(works[pass] + footer_ofs))->count) {
                    if (BACKUP_SYSTEM_GetBlockArea(sv, id) == 1)
                        break;
                    BACKUP_SYSTEM_SetBlockArea(sv, id, 2);
                }
            }
        }
        if (id >= SAVEDATA_GetTableMax(sv->table)) {
            u32 area = areas[pass ^ 1];

            BACKUP_SYSTEM_SetBlockArea(sv, SAVEDATA_GetTableMax(sv->table) + 1, area);
            BACKUP_SYSTEM_SetBlockArea(sv, SAVEDATA_GetTableMax(sv->table), area);
            break;
        }
    }
    if (pass >= 2) {
        BACKUP_SYSTEM_FillBlockAreas(sv, 1);
        GFL_HEAP_Free(work2);
        return 3;
    }

    crc_ofs = sv->data_size - 0x10 - sv->crc_table_size;
    MIi_CpuCopy16(works[pass] + crc_ofs, work1 + crc_ofs, sv->crc_table_size + 0x10);
    for (id = 0; id < SAVEDATA_GetTableMax(sv->table); id++) {
        if (BACKUP_SYSTEM_GetBlockArea(sv, id) == 1) {
            ofs = SAVEDATA_GetBlockOffset(sv->table, id);
            size = SAVEDATA_GetBlockSize(sv->table, id);
            MIi_CpuCopy16(work2 + ofs, work1 + ofs, size + 4);
        }
    }
    BACKUP_SYSTEM_SetSaveCount(sv, counts[pass]);
    GFL_HEAP_Free(work2);
    for (id = 0; id < SAVEDATA_GetTableMax(sv->table); id++)
        BACKUP_SYSTEM_GetBlockArea(sv, id);
    return 1;
}

/*
 * backup_system.c.  The one-copy load: read copy 1 of the save area into the
 * staging buffer self->svwk (FLASH_ACCESS_Read at BACKUP_SYSTEM_GetAreaAddr(self, 1)); on a
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
int BACKUP_SYSTEM_LoadSingleCopy(BackupSaveData *sv, int mode, int link_count)
{
    u32 info[2];
    u8 *work;
    u32 id2, ofs, size;
    int save_count;
    u8 *crc_table;
    SaveRecordFooter *rec;
    u32 id;

    BACKUP_SYSTEM_ClearBlockAreas(sv);
    work = sv->svwk;
    if (FLASH_ACCESS_Read(BACKUP_SYSTEM_GetAreaAddr(sv, 1), (u32)work, sv->data_size,
                      svsys->read_error_func) == 0) {
        BACKUP_SYSTEM_FillBlockAreas(sv, 1);
        MIi_CpuClear32(0, work, sv->data_size);
        return 0;
    }
    BACKUP_SYSTEM_GetFooterInfo(info, sv, work, 0);
    if (mode == 1) {
        if ((s32)info[1] != link_count)
            info[0] = 2;
    }
    if (info[0] != 0) {
        if (info[0] == 1) {
            BACKUP_SYSTEM_FillBlockAreas(sv, 1);
            return 3;
        }
        BACKUP_SYSTEM_FillBlockAreas(sv, 1);
        return 0;
    }

    crc_table = work + (sv->data_size - 0x10 - sv->crc_table_size);
    save_count = (s32)info[1];
    for (id = 0; id < SAVEDATA_GetTableMax(sv->table); id++) {
        ofs = SAVEDATA_GetBlockOffset(sv->table, id);
        size = SAVEDATA_GetBlockSize(sv->table, id);
        rec = (SaveRecordFooter *)(work + (ofs + size));
        BACKUP_SYSTEM_SetBlockArea(sv, id, 0);
        if (rec->crc != *(u16 *)(crc_table + id * 2))
            goto done;
        if (rec->crc == *(u16 *)(crc_table + id * 2)) {
            if (rec->crc != MATH_CalcCRC16CCITT(svsys->crc_table, work + ofs, size)) {
                BACKUP_SYSTEM_SetBlockArea(sv, id, 1);
                goto done;
            }
        }
    }
done:
    if (id >= SAVEDATA_GetTableMax(sv->table)) {
        BACKUP_SYSTEM_SetBlockArea(sv, SAVEDATA_GetTableMax(sv->table) + 1, 1);
        BACKUP_SYSTEM_SetBlockArea(sv, SAVEDATA_GetTableMax(sv->table), 1);
    } else {
        BACKUP_SYSTEM_FillBlockAreas(sv, 1);
        return 3;
    }
    BACKUP_SYSTEM_SetSaveCount(sv, save_count);
    for (id2 = 0; id2 < SAVEDATA_GetTableMax(sv->table); id2++)
        BACKUP_SYSTEM_GetBlockArea(sv, id2);
    return 1;
}

/*
 * PARKED AT MATCH.  Every concrete byte is right.  The one open site is the
 * `bl` to 0x02031F54: the image holds exactly one branch to that address,
 * the one inside this function, so the `label` class has no outside witness
 * and no split can make one.  It closes the day a second caller turns up or
 * 0x02031F54 itself is matched.
 *
 * backup_system.c.  Writes the sixteen byte footer of a backup record: the
 * destination is the last sixteen bytes of the area that starts at +0x30
 * and runs for the length 0x02031EAC reports, the source is the matching
 * sixteen bytes of the staging buffer at +0x34, and the fourth argument is
 * the handle the global at 0x02146994 keeps at +0x208.  The call to
 * 0x02031F54 in between is made for its effect only; its result is dropped.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/BACKUP_SYSTEM_WriteFooterBody.c  *       --func BACKUP_SYSTEM_WriteFooterBody --addr 0x020328E0 --cc 1.1p1 --arm
 */
int BACKUP_SYSTEM_WriteFooterBody(BackupSaveData *sv, u32 area)
{
    u32 flash_addr;
    u32 data_size;
    u8 *work;

    data_size = sv->data_size;
    flash_addr = data_size + BACKUP_SYSTEM_GetAreaAddr(sv, area) - 0x10;
    work = sv->svwk;
    BACKUP_SYSTEM_SetFooter(sv, work);
    return FLASH_ACCESS_StartWrite(flash_addr, (u32)(work + (data_size - 0x10)), 0xF, (void *)svsys->write_error_func);
}

/*
 * backup_system.c.  The one byte twin of BACKUP_SYSTEM_WriteFooterBody: same area and staging
 * buffer, but it rewrites only the single trailing byte of the record.
 * Unlike BACKUP_SYSTEM_WriteFooterBody it does not touch 0x02031F54 first, so nothing has to
 * survive the call and the function gets away with three saved registers.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_WriteFooterLastByte.c  *       --func BACKUP_SYSTEM_WriteFooterLastByte --addr 0x02032930 --cc 1.1p1 --arm
 */
int BACKUP_SYSTEM_WriteFooterLastByte(BackupSaveData *sv, u32 area)
{
    u32 data_size = sv->data_size;
    u32 end_addr = data_size + BACKUP_SYSTEM_GetAreaAddr(sv, area);

    return FLASH_ACCESS_StartWrite(end_addr - 1, (u32)(sv->svwk + (data_size - 1)), 1, (void *)svsys->write_error_func);
}

/*
 * backup_system.c.  Opens a new backup generation: clears the two status bytes
 * and the two counters, remembers the generation the write is going to
 * carry in +0x10 and bumps the running generation in +0x28, then, when the
 * caller asked for it, raises the "busy" flag through the setter veneer at
 * 0x02034F84.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_InitSaveSeq.c  *       --func BACKUP_SYSTEM_InitSaveSeq --addr 0x02032970 --cc 1.1p1 --arm
 */
void BACKUP_SYSTEM_InitSaveSeq(BackupSaveData *sv, u32 set_busy)
{
    u32 save_count;

    sv->write_seq = 0;
    sv->write_block = 0;
    sv->write_pass = 0;
    save_count = sv->save_count;
    sv->save_count = save_count + 1;
    sv->written_size = 0;
    sv->prev_save_count = save_count;

    if (set_busy == 1) {
        UI_SetKeepAwakeFlagsGlobal(1);
    }
}

/*
 * backup_system.c.  Walks every record of the save table and reports two running
 * totals through the caller's two out-parameters: the nominal size of every
 * record, and the size actually accounted for.  A record 0x020332FC says is
 * not resident is pumped through the seven-argument step function at
 * 0x02032A9C until it stops answering 0, and a step that answers 2 drops
 * that record's contribution to the second total to zero.
 *
 * The four scratch cells the step function writes through are stack locals
 * whose addresses are taken, which is why the frame is 0x24 bytes with the
 * first three outgoing stack arguments at the bottom; per
 * docs/idioms/local-declaration-order-is-stack-order.md the first declared
 * of the four sits highest, at sp+0x20, and the fourth at sp+0x14, matching
 * the order they are passed in.  The fourth is deliberately not initialised:
 * the original zeroes only three of the four.
 *
 * The outer loop is a do/while, not a for: the bound is recomputed by a call
 * at the bottom of every iteration and the compiler has no way to rotate an
 * unknown bound, so the test really is written after the body.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_CalcDiffSize.c \
 *       --func BACKUP_SYSTEM_CalcDiffSize --addr 0x020329AC --cc 1.1p1 --arm
 */
void BACKUP_SYSTEM_CalcDiffSize(BackupSaveData *sv, u32 *diff_size, u32 *total_size)
{
    u32 rest;
    u32 budget;
    u32 done_size;
    u32 yield;
    u32 size;
    u32 i;
    u32 result;

    i = 0;
    UI_SetKeepAwakeFlagsGlobal(1);

    *diff_size = 0;
    *total_size = 0;
    rest = 0;
    budget = 0;
    done_size = 0;

    do {
        size = SAVEDATA_GetBlockSize(sv->table, i);
        *total_size = *total_size + size;

        if (BACKUP_SYSTEM_GetBlockArea(sv, i) == 0) {
            do {
                result = BACKUP_SYSTEM_CompareRecordStep(sv, i, 1, &rest, &budget, &done_size, &yield);
                if (result == 2) {
                    size = 0;
                }
            } while (result == 0);
        }

        *diff_size = *diff_size + size;
        i++;
    } while (i < SAVEDATA_GetTableMax(sv->table));

    UI_ClearKeepAwakeFlagsGlobal(1);
}

/*
 * backup_system.c.  One resumable step of a record copy: read the record out of
 * Flash into the 0x38 scratch area 0x100 bytes at a time and hand each
 * chunk to 0x0203EFC8, stopping either when the record is exhausted (answer
 * 2) or when the running byte budget in *pb crosses 0x800 (answer 0, with
 * the remaining length and the progress written back through *pa and *pc so
 * the caller can call again).  A read or write failure answers 1.
 *
 * The seven arguments mean the last three arrive on the stack; the compiler
 * keeps the sixth in its own incoming slot and reloads it, which is why
 * there is a `ldr r2, [sp, #0x2c]` / `str r2, [sp, #0x2c]` pair that looks
 * like a no-op in the prologue.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_CompareRecordStep.c \
 *       --func BACKUP_SYSTEM_CompareRecordStep --addr 0x02032A9C --cc 1.1p1 --arm
 */
u32 BACKUP_SYSTEM_CompareRecordStep(BackupSaveData *sv, u32 id, u32 area, u32 *rest, u32 *budget,
                 u32 *done_size, u32 *yield)
{
    u32 flash_addr;
    u32 rest_size;
    u32 chunk;
    u32 done;
    u8 *record;
    u32 total;

    flash_addr = BACKUP_SYSTEM_GetAreaAddr(sv, area);
    flash_addr = flash_addr + SAVEDATA_GetBlockOffset(sv->table, id);

    rest_size = *rest;
    if (rest_size != 0) {
        done = *done_size;
        flash_addr = flash_addr + done;
    } else {
        rest_size = SAVEDATA_GetBlockSize(sv->table, id);
        done = 0;
    }

    record = BACKUP_SYSTEM_GetRecordWork(sv, id);

    *rest = 0;
    *done_size = 0;
    *yield = 0;

    do {
        if (rest_size > 0x100) {
            chunk = 0x100;
            rest_size = rest_size - 0x100;
        } else {
            chunk = rest_size;
            rest_size = 0;
        }

        total = *budget + chunk;
        *budget = total;
        if (total > 0x800) {
            *yield = 1;
            *budget = 0;
        }

        if (FLASH_ACCESS_Read(flash_addr, (u32)sv->compare_buf, chunk, svsys->read_error_func) == 0) {
            return 1;
        }

        if (GF_STANDARD_CompareBytes(sv->compare_buf, record + done, chunk) != 0) {
            return 1;
        }

        done = done + chunk;
        flash_addr = flash_addr + chunk;

        if (*yield == 1) {
            if (rest_size == 0) {
                return 2;
            }
            *rest = rest_size;
            *done_size = done;
            return 0;
        }
    } while (rest_size != 0);

    return 2;
}

/*
 * backup_system.c.  Commits one record of a backup generation: refresh the
 * record's CRC through BACKUP_SYSTEM_UpdateRecordCrc (src/matched/BACKUP_SYSTEM_UpdateRecordCrc.c) and file
 * it in the halfword table 0x02031ECC owns, then write the record itself,
 * four bytes longer than its payload, to the Flash offset that 0x02031EAC
 * and 0x02033B68 name between them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_WriteRecord.c \
 *       --func BACKUP_SYSTEM_WriteRecord --addr 0x02032BF8 --cc 1.1p1 --arm
 */
u16 BACKUP_SYSTEM_WriteRecord(BackupSaveData *sv, u32 id, u32 area, u32 pass)
{
    u16 *crc_table;
    u32 area_addr;
    u32 ofs;
    u32 size;
    u8 *record;

    crc_table = BACKUP_SYSTEM_GetCrcTable(sv);
    crc_table[id] = BACKUP_SYSTEM_UpdateRecordCrc(sv, id);
    area_addr = BACKUP_SYSTEM_GetAreaAddr(sv, area);
    ofs = SAVEDATA_GetBlockOffset(sv->table, id);
    size = SAVEDATA_GetBlockSize(sv->table, id);
    record = BACKUP_SYSTEM_GetRecordWork(sv, id);
    FLASH_ACCESS_StartWrite(area_addr + ofs, (u32)record, size + 4, (void *)svsys->write_error_func);
}

/*
 * backup_system.c.  Writes the trailing block of a backup record: the length is
 * the +0x140 field, the destination is that many bytes back from the end
 * of the area, and the source is whatever 0x02031ECC hands back.  The
 * destination has to be computed before the 0x02031ECC call so that the
 * register holding `p` can be reused for it, which is what keeps the frame
 * down to three saved registers.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_WriteCrcTable.c \n *       --func BACKUP_SYSTEM_WriteCrcTable --addr 0x02032C84 --cc 1.1p1 --arm
 */
int BACKUP_SYSTEM_WriteCrcTable(BackupSaveData *sv, u32 area)
{
    u32 flash_addr;
    u16 *crc_table;

    flash_addr = sv->data_size + BACKUP_SYSTEM_GetAreaAddr(sv, area);
    flash_addr = flash_addr - 0x10 - sv->crc_table_size;
    crc_table = BACKUP_SYSTEM_GetCrcTable(sv);
    return FLASH_ACCESS_StartWrite(flash_addr, (u32)crc_table, sv->crc_table_size, (void *)svsys->write_error_func);
}

/*
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
int BACKUP_SYSTEM_SaveSeqMain(BackupSaveData *sv, u32 *pass_done)
{
    u32 success;
    u32 yield;
    u32 area;
    u32 result;

    *pass_done = 0;
    switch (sv->write_seq) {
    case 0:
        sv->compare_rest = 0;
        sv->compare_budget = 0;
        sv->compare_done = 0;
        sv->write_seq++;
    case 1:
        yield = 0;
        do {
            if (yield == 1)
                return 0;
            if (BACKUP_SYSTEM_GetBlockArea(sv, sv->write_block) == 0) {
                result = BACKUP_SYSTEM_CompareRecordStep(sv, sv->write_block, 1, &sv->compare_rest, &sv->compare_budget, &sv->compare_done, &yield);
                if (result == 1) {
                    BACKUP_SYSTEM_SetBlockArea(sv, sv->write_block, 1);
                } else if (result == 0) {
                    if (yield != 1)
                        GF_PANIC_Fail(str_020A7848, 0x72A, str_020A7888);
                    return 0;
                } else {
                    goto next;
                }
            }
            BACKUP_SYSTEM_IncRecordCount(sv, sv->write_block);
        next:
            sv->write_block++;
        } while (sv->write_block < SAVEDATA_GetTableMax(sv->table));
        sv->write_seq++;
        break;
    case 2:
        sv->write_block = 0;
        sv->write_seq++;
    case 3:
        for (; sv->write_block < SAVEDATA_GetTableMax(sv->table); sv->write_block++) {
            area = BACKUP_SYSTEM_GetBlockArea(sv, sv->write_block);
            if (area != 0) {
                svsys->lock_id = BACKUP_SYSTEM_WriteRecord(sv, sv->write_block, area, sv->write_pass);
                sv->write_seq++;
                break;
            }
        }
        if (sv->write_block >= SAVEDATA_GetTableMax(sv->table)) {
            sv->write_block = 0;
            sv->write_seq = 5;
        }
        break;
    case 4:
        if (FLASH_ACCESS_PollWrite(svsys->lock_id, &success, svsys->write_error_func) == 0)
            break;
        if (success == 0)
            return sv->write_pass == 0 ? 3 : 2;
        sv->written_size += SAVEDATA_GetBlockSize(sv->table, sv->write_block);
        sv->write_block++;
        sv->write_seq = 3;
        break;
    case 5:
        area = BACKUP_SYSTEM_GetBlockArea(sv, SAVEDATA_GetTableMax(sv->table));
        if (area == 0) {
            area = 1;
            BACKUP_SYSTEM_SetBlockArea(sv, SAVEDATA_GetTableMax(sv->table), area);
        }
        svsys->lock_id = BACKUP_SYSTEM_WriteCrcTable(sv, area);
        sv->write_seq++;
    case 6:
        if (FLASH_ACCESS_PollWrite(svsys->lock_id, &success, svsys->write_error_func) == 0)
            break;
        if (success == 0)
            return sv->write_pass == 0 ? 3 : 2;
        sv->write_seq++;
        break;
    case 7:
        area = BACKUP_SYSTEM_GetBlockArea(sv, SAVEDATA_GetTableMax(sv->table) + 1);
        if (area == 0) {
            area = 1;
            BACKUP_SYSTEM_SetBlockArea(sv, SAVEDATA_GetTableMax(sv->table) + 1, area);
        }
        svsys->lock_id = BACKUP_SYSTEM_WriteFooterBody(sv, area);
        sv->write_seq++;
    case 8:
        if (FLASH_ACCESS_PollWrite(svsys->lock_id, &success, svsys->write_error_func) == 0)
            break;
        if (success == 0)
            return sv->write_pass == 0 ? 3 : 2;
        sv->write_seq++;
        return 1;
    case 9:
        svsys->lock_id = BACKUP_SYSTEM_WriteFooterLastByte(sv, BACKUP_SYSTEM_GetBlockArea(sv, SAVEDATA_GetTableMax(sv->table) + 1));
        sv->write_seq++;
    case 10:
        if (FLASH_ACCESS_PollWrite(svsys->lock_id, &success, svsys->write_error_func) == 0)
            break;
        if (success == 0)
            return sv->write_pass == 0 ? 3 : 2;
        if (++sv->write_pass == 1 && sv->area_addr[0] != sv->area_addr[1]) {
            BACKUP_SYSTEM_SwapBlockAreas(sv);
            sv->write_seq = 2;
            *pass_done = 1;
            return 0;
        }
        BACKUP_SYSTEM_ClearBlockAreas(sv);
        sv->write_seq++;
        return 2;
    case 11:
        return 2;
    }
    return 0;
}

/*
 * backup_system.c.  The completion callback of a backup write: on result 3 the
 * generation counter is rolled back to the one the write carried, on any
 * other result the failure byte at +0x1C is raised instead, and either way
 * the "busy" flag is dropped through the veneer at 0x02034FB8 when the
 * caller asked for it.  The two arms share one epilogue, which is why they
 * are written as an if/else over predicated stores rather than two
 * statements.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_EndSave.c  *       --func BACKUP_SYSTEM_EndSave --addr 0x020331A4 --cc 1.1p1 --arm
 */
void BACKUP_SYSTEM_EndSave(BackupSaveData *sv, u32 result, u32 clear_busy)
{
    if (result == 3) {
        sv->save_count = sv->prev_save_count;
    } else {
        sv->data_exists = 1;
    }

    if (clear_busy == 1) {
        UI_ClearKeepAwakeFlagsGlobal(1);
    }
}

/*
 * PARKED AT MATCH.  Every concrete byte is right.  The one open site is the
 * `bl` to 0x0203386C, which has exactly one caller image-wide, this one, so
 * `label` has nothing outside the range to point at.
 *
 * backup_system.c.  The same completion path as BACKUP_SYSTEM_EndSave but for the
 * unconditional case: roll the generation back, hand the halfword at
 * +0x20C of the object the global at 0x02146994 points at to 0x0203386C,
 * and drop the busy flag.
 *
 * The `add r0, r0, #0x200` before the `ldrh r0, [r0, #0xc]` is the reach of
 * the Thumb-era halfword load showing through, not a second object: see
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/BACKUP_SYSTEM_CancelSaveSeq.c  *       --func BACKUP_SYSTEM_CancelSaveSeq --addr 0x020331D0 --cc 1.1p1 --arm
 */
void BACKUP_SYSTEM_CancelSaveSeq(BackupSaveData *sv)
{
    sv->save_count = sv->prev_save_count;
    FLASH_ACCESS_CancelWrite(svsys->lock_id);
    UI_ClearKeepAwakeFlagsGlobal(1);
}

/*
 * backup_system.c.  Blanks the sixteen byte footer of a backup record by
 * pushing an all-0xFF block from the stack over it.  The 0x10 is kept in a
 * callee-saved register because it is both the fill length and the write
 * length, one on each side of the MI_CpuFill8 call.
 *
 * 0x02031EAC takes two arguments here.  BACKUP_SYSTEM_WriteFooterBody in the same file
 * reaches it with only r0 set, which is the leftover-argument shape of
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md
 * seen from the caller side; two arguments is the honest prototype.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_EraseFooter.c \n *       --func BACKUP_SYSTEM_EraseFooter --addr 0x02033200 --cc 1.1p1 --arm
 */
u32 BACKUP_SYSTEM_EraseFooter(BackupSaveData *sv, u32 area)
{
    u8 blank[0x10];

    MI_CpuFill8(blank, 0xFF, sizeof(blank));
    return FLASH_ACCESS_Write(sv->data_size + BACKUP_SYSTEM_GetAreaAddr(sv, area) - 0x10, (u32)blank, sizeof(blank),
                  svsys->write_error_func);
}

/*
 * backup_system.c.  Bumps the halfword counter that sits at the head of one of
 * the records inside the staging buffer and answers the new value.  The
 * closing `ldrh` is not a redundant reload: reloading the halfword is one
 * instruction where truncating the incremented value in a register would
 * be two, so the compiler reads the store back rather than masking.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_IncRecordCount.c \n *       --func BACKUP_SYSTEM_IncRecordCount --addr 0x02033264 --cc 1.1p1 --arm
 */
u16 BACKUP_SYSTEM_IncRecordCount(BackupSaveData *sv, u32 id)
{
    u32 ofs;
    u32 size;
    u16 *count;

    ofs = SAVEDATA_GetBlockOffset(sv->table, id);
    size = SAVEDATA_GetBlockSize(sv->table, id);
    count = (u16 *)(sv->svwk + (ofs + size));
    *count = *count + 1;
    return *count;
}

/*
 * backup_system.c.  Recomputes the CRC-16/CCITT of one record in the staging
 * buffer and stores it in the halfword that follows the record.  The table
 * argument is the global at 0x02146994 plus four, i.e. a MATHCRC16Table
 * that lives inline at +4 of that object rather than a pointer kept there.
 * As in BACKUP_SYSTEM_IncRecordCount the answer is read back out of the halfword it was
 * just stored into.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_UpdateRecordCrc.c \n *       --func BACKUP_SYSTEM_UpdateRecordCrc --addr 0x020332A4 --cc 1.1p1 --arm
 */
u16 BACKUP_SYSTEM_UpdateRecordCrc(BackupSaveData *sv, u32 id)
{
    u32 ofs;
    u32 size;
    SaveRecordFooter *record_footer;
    u8 *work;

    ofs = SAVEDATA_GetBlockOffset(sv->table, id);
    size = SAVEDATA_GetBlockSize(sv->table, id);
    work = sv->svwk;
    record_footer = (SaveRecordFooter *)(work + (ofs + size));
    record_footer->crc = MATH_CalcCRC16CCITT(svsys->crc_table, work + ofs, size);
    return record_footer->crc;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * A packed 2-bit-per-slot array getter. The backing store is a u32 array
 * reached through offset 0x138 of the object; slot `idx` lives in word
 * `idx >> 4` at bit position `(idx & 0xf) * 2`. The companion setter at
 * 0x0203331C (immediately following, same file) computes its clear mask
 * through a `long long` NOT (docs/idioms/a-64-bit-complement-is-eors-with-minus-one-not-mvns.md)
 * that this getter does not need and is left open.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020332FC.c \
 *       --addr 0x020332FC --arm
 */
u32 BACKUP_SYSTEM_GetBlockArea(BackupSaveData *sv, u32 block)
{
    return (sv->block_area[block >> 4] >> ((block & 0xf) * 2)) & 3;
}

/*
 * backup_system.c.  The packed 2-bit-per-slot array SETTER, companion to
 * the getter src/matched/unit_020332FC.c at 0x020332FC (same file, the
 * function immediately before it).  The backing store is a u32 array at
 * offset 0x138 of the object; slot `idx` lives in word `idx >> 4` at bit
 * position `(idx & 0xf) * 2`.
 *
 * Two spellings carry this function and neither is optional:
 *
 * 1. The clear mask is a 64-bit complement, not `~`.  The original's
 *    `mov r3, #3` / `sub r1, r3, #4` / `eor r1, r1, r3, lsl lr` triple is
 *    the low half of a `long long` NOT with the high half dead-code
 *    eliminated -- see docs/idioms/
 *    a-64-bit-complement-is-eors-with-minus-one-not-mvns.md.  Spelling it
 *    `~(3 << sh)` compiles to `mvn r1, r1, lsl r4` and loses four bytes
 *    (60 against 64); the literal `3` must stay inline in the `^ -1` form
 *    so the same `mov r3, #3` feeds both the `sub` that makes -1 and the
 *    shifted operand of the `eor`.  Binding it to a `long long mask = 3;`
 *    local instead costs a second constant materialisation (68 bytes).
 *
 * 2. The word index of the CLEAR half goes through a two-step copy chain
 *    (`tmp1 = idx >> 4; tmp = tmp1;`) while the SET half re-reads
 *    `idx >> 4` and `sh` directly.  Without the copy chain the compiler
 *    colours the shift amount r4 and the word index lr, which is the
 *    exact reverse of the original (10 concrete bytes, a pure r4 <-> lr
 *    swap with every instruction otherwise identical).  The extra copy
 *    splits the word index's live range so the allocator numbers the
 *    shift amount first and it takes lr.  Found by tools/permuter.py
 *    (--mode anneal, `expand(sh) ; temp(tmp=idx >> 4) ; temp(tmp1=idx >> 4)
 *    ; reorder(-1)`), then reduced by hand: dropping either temp returns
 *    the residue to the same 10 bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_SetBlockArea.c \
 *       --func BACKUP_SYSTEM_SetBlockArea --addr 0x0203331C --cc 1.1p1 --arm
 */
void BACKUP_SYSTEM_SetBlockArea(BackupSaveData *sv, u32 block, u32 area)
{
    u32 shift = (block & 0xf) * 2;
    u32 word;
    u32 word_index;

    word_index = block >> 4;
    word = word_index;
    sv->block_area[word] &= (3 << ((block & 0xf) * 2)) ^ -1;
    sv->block_area[block >> 4] |= area << shift;
}

/*
 * backup_system.c.  Swaps the two record marks across the whole packed
 * 2-bit-per-slot bitmap at +0x138: every slot holding 1 becomes 2 and every
 * slot holding 2 becomes 1 (0 and 3 are left alone).  The slot count is
 * SAVEDATA_GetTableMax(p->table) + 2, the same count BACKUP_SYSTEM_FillBlockAreas fills; the one-slot
 * getter and setter are src/matched/unit_020332FC.c and BACKUP_SYSTEM_SetBlockArea.c.
 * Called by BACKUP_SYSTEM_SaveSeqMain when a save generation completes.
 *
 * Three spellings carry it (docs/notes/BACKUP_SYSTEM_SwapBlockAreas.c.txt has four lanes of
 * measurements at 21 bytes out before these were found):
 *
 * 1. The clear mask is the 64-bit complement written on a widened value,
 *    `(long long)(3 << sh) ^ -1` (docs/idioms/
 *    a-64-bit-complement-is-eors-with-minus-one-not-mvns.md).  With the int
 *    form `(3 << sh) ^ -1` every instruction is right but the hoisted 3 is
 *    coloured before the word index; the widened form numbers the 3 and the
 *    -1 after it and gives the image's sb/r7/r8 for 3/-1/mask.
 * 2. The first read indexes with `(int) w` while the clear and the set
 *    index with the plain u32 `w`; without the cast the word index, the
 *    slots pointer and the slot value rotate (r2/r6/r5 -> r6/r5/r2, 28
 *    bytes).  Found by tools/permuter.py anneal, then isolated by a sweep.
 * 3. The bound is a copy `n_ = n` tested by the loop, the guard tests `n`
 *    (the lever that closed BACKUP_SYSTEM_FillBlockAreas); all loop values are u32 so the
 *    wrap uses subhs/addhs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_SwapBlockAreas.c \
 *       --func BACKUP_SYSTEM_SwapBlockAreas --addr 0x0203335C --cc 1.1p1 --arm
 */
void BACKUP_SYSTEM_SwapBlockAreas(BackupSaveData *sv)
{
    u32 count;
    u32 word;
    u32 shift;
    u32 count_copy;
    u32 block;
    u32 area;

    count = SAVEDATA_GetTableMax(sv->table) + 2;
    word = 0;
    shift = 0;
    block = 0;
    count_copy = count;
    if (count == 0) {
        return;
    }
    do {
        area = (sv->block_area[(int)word] >> shift) & 3;
        if (area != 0) {
            if (area == 1) {
                area = 2;
            } else if (area == 2) {
                area = 1;
            }
            sv->block_area[word] &= (long long)(3 << shift) ^ -1;
            sv->block_area[word] |= area << shift;
        }
        shift += 2;
        block++;
        if (shift >= 0x20) {
            shift -= 0x20;
            word++;
        }
    } while (block < count_copy);
}

void BACKUP_SYSTEM_ClearBlockAreas(BackupSaveData *sv)
{
    MIi_CpuClear32(0, sv->block_area, sv->block_area_size);
}

/*
 * backup_system.c.  Fills the whole packed 2-bit-per-slot bitmap at offset
 * 0x138 with one repeated value: MIi_CpuClear32 (MIi_CpuClear32) wipes
 * p->block_area_size bytes of it, then `val` is OR'd in two bits at a time for
 * SAVEDATA_GetTableMax(p->table) + 2 slots.  The getter/setter for one slot of the
 * same bitmap are src/matched/unit_020332FC.c and
 * src/matched/BACKUP_SYSTEM_SetBlockArea.c.
 *
 * Two spellings carry this function:
 *
 * 1. The shift amount and the word index must be u32, not int.  An int
 *    gives the SIGNED conditional pair `subge`/`addge` where the original
 *    has the unsigned `subhs`/`addhs`; docs/notes/pkt_02033410.c.txt
 *    records that this alone was worth 38 of the original 44 residue bytes.
 *
 * 2. The loop bound is read through a COPY of the count declared before the
 *    counter (`n_ = n;` with `u32 n_;` ahead of `u32 i;`).  Written the
 *    obvious way -- the loop testing `n` directly -- the allocator swaps
 *    the counter and the bound (original `mov ip, r6` / `adds r3, r0, #2`
 *    / `add ip, ip, #1` / `cmp ip, r3`; compiled the same four with r3 and
 *    ip exchanged), which is 9 concrete bytes at the right size and is the
 *    residue the old note parked at.  The extra copy splits the bound's
 *    live range so it is numbered after the counter and takes r3.  Found
 *    by tools/permuter.py --mode hill (`copy(n->n_@9) ; decl-order(n_<->i)`).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_FillBlockAreas.c \
 *       --func BACKUP_SYSTEM_FillBlockAreas --addr 0x02033410 --cc 1.1p1 --arm
 */
void BACKUP_SYSTEM_FillBlockAreas(BackupSaveData *sv, u32 area)
{
    u32 count;
    u32 word;
    u32 shift;
    u32 count_copy;
    u32 block;

    MIi_CpuClear32(0, sv->block_area, sv->block_area_size);
    count = SAVEDATA_GetTableMax(sv->table) + 2;
    word = 0;
    shift = 0;
    count_copy = count;
    block = 0;
    if (count_copy == 0) {
        return;
    }
    do {
        block++;
        sv->block_area[word] |= area << shift;
        shift += 2;
        if (shift >= 0x20) {
            shift -= 0x20;
            word++;
        }
    } while (block < count_copy);
}

void BACKUP_SYSTEM_WriteFlash(u32 flash_addr, u32 src, u32 size)
{
    FLASH_ACCESS_Write(flash_addr, src, size, svsys->write_error_func);
}

/*
 * Tail-call accessor, the sibling of BACKUP_SYSTEM_WriteFlash: load the object at
 * 0x02146994, read its field at +0x208, and forward r0-r2 plus that word
 * as the fourth argument of FLASH_ACCESS_StartWrite.  Unlabelled in the listing (it
 * saves no lr), so it is invisible to `sole-ref/code` until this entry
 * exists; it is the witness that unblocks the thumb caller SAVE_OUTSIDE_WriteAsync.
 */
u16 BACKUP_SYSTEM_WriteFlashAsync(u32 flash_addr, u32 src, u32 size)
{
    return FLASH_ACCESS_StartWrite(flash_addr, src, size, (void *)svsys->write_error_func);
}

/*
 * Tail-call accessor, the sibling of BACKUP_SYSTEM_WriteFlash: load the object at
 * 0x02146994, read its field at +0x208, and forward r0-r1 plus that word
 * as the third argument of FLASH_ACCESS_PollWrite.  The loaded word lands in r2
 * (not r3 like BACKUP_SYSTEM_WriteFlashAsync), which is what fixes the arity at three.
 * Unlabelled in the listing (it saves no lr), so it is invisible to
 * `sole-ref/code` until this entry exists; it is the witness that
 * unblocks the thumb caller SAVE_OUTSIDE_WriteAsync.
 */
int BACKUP_SYSTEM_CheckFlashAsync(u16 lock_id, u32 *success)
{
    return FLASH_ACCESS_PollWrite(lock_id, success, svsys->write_error_func);
}

/*
 * Tail-call thunk: forwards its arguments to FLASH_ACCESS_Read with the word at
 * +0x204 of the object at svsys as the last argument.  No arm9 code
 * calls it; its callers are Thumb blx in ov228, so the listing carried it as
 * raw words until the seed in layout/function_starts.txt.
 */
int BACKUP_SYSTEM_ReadFlash(u32 flash_addr, u32 dst, u32 size)
{
    return FLASH_ACCESS_Read(flash_addr, dst, size, svsys->read_error_func);
}

int BACKUP_SYSTEM_ReadRecordFromFlash(BackupSaveData *sv, u32 id, u32 area_index, u32 dst, u32 size)
{
    u32 area_addr = BACKUP_SYSTEM_GetAreaAddr(sv, area_index + 1);
    u32 ofs = SAVEDATA_GetBlockOffset(sv->table, id);

    return FLASH_ACCESS_Read(area_addr + ofs, dst, size, svsys->read_error_func);
}
