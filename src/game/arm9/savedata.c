/*
 * file:     savedata.c
 * unit:     yes
 * function: SAVEDATA_CreateTable, SAVEDATA_DeleteTable, SAVEDATA_InitBuffer, SAVEDATA_QueryBlockSize, SAVEDATA_BuildLayout, SAVEDATA_GetBlockOffset, SAVEDATA_GetBlockSize, SAVEDATA_GetTableMax, SAVEDATA_GetTotalSize
 * address:  0x02033908
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from backup_system.c at 0x02033908 (__FILE__ anchor boundary, certain cut).
 * The AREAMAN_* run was cut to areaman.c at 0x02033C00 and the VMAN_* and panic
 * run to vman.c at 0x02034520 by lane A4; both cuts are anchor-fixed (areaman.c at
 * 0x02033C00, vman.c at 0x02034558 with VMAN_GetBankSetSize at 0x02034520 by
 * module prefix).
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   MIi_CpuClear32   0x02082A7C  arm
 *   savedata_File  0x020A78CC  data
 *   savedata_AssertIdInRange  0x020A78D8  data
 *   savedata_AssertTableId  0x020A78F0  data
 *   savedata_AssertTotalSize  0x020A7908  data
 *   savedata_AssertGmdataidInRange  0x020A793C  data
 */

#include "../types.h"

typedef u32 (*BlockSizeFunc)(void);
typedef void (*BlockInitFunc)(void *block);
typedef void (*PanicHookFunc)(void);

/* ---- savedata.c: block table of the save area ---- */

/* One block definition handed in by the caller; indexed by gmdataID. */
struct SaveBlockDef {
    u32 gmdataID;
    BlockSizeFunc size_func;
    BlockInitFunc init_func;
};

/* Computed position of one block inside the save area. */
struct SaveBlockPos {
    u32 gmdataID;
    u32 size;
    u32 offset;
};

/* The "svdt" of the asserts: definition table plus the computed layout. */
struct SaveDataTable {
    struct SaveBlockDef *table;     /* +0x00 */
    u32 table_max;                  /* +0x04 */
    u32 header_size;                /* +0x08 */
    u32 total_size;                 /* +0x0c */
    u32 size_limit;                 /* +0x10 */
    struct SaveBlockPos *layout;    /* +0x14 */
    u32 footer_size;                /* +0x18 */
};

#include "gfl_heap_wrap.h"
#include "mi_memory.h"

struct SaveDataTable *SAVEDATA_CreateTable(u16 heap_id, struct SaveBlockDef *table, u32 table_max, u32 size_limit,
                                    u32 header_size, u32 block_overhead, u32 footer_size);
void SAVEDATA_DeleteTable(struct SaveDataTable *svdt);
void SAVEDATA_InitBuffer(u8 *buffer, struct SaveDataTable *svdt);
u32 SAVEDATA_QueryBlockSize(struct SaveDataTable *svdt, u32 id);
void SAVEDATA_BuildLayout(struct SaveDataTable *svdt, u32 block_overhead);
u32 SAVEDATA_GetBlockOffset(struct SaveDataTable *svdt, u32 gmdataid);
u32 SAVEDATA_GetBlockSize(struct SaveDataTable *svdt, u32 gmdataid);
u32 SAVEDATA_GetTableMax(struct SaveDataTable *svdt);
u32 SAVEDATA_GetTotalSize(struct SaveDataTable *svdt);
#include "gf_panic.h"

extern const char savedata_File[];
extern const u8 savedata_AssertIdInRange[];
extern const u8 savedata_AssertTableId[];
extern const u8 savedata_AssertTotalSize[];
extern const u8 savedata_AssertGmdataidInRange[];

struct SaveDataTable *SAVEDATA_CreateTable(u16 heap_id, struct SaveBlockDef *table, u32 table_max, u32 size_limit,
                                    u32 header_size, u32 block_overhead, u32 footer_size)
{
    struct SaveDataTable *svdt = GFL_HEAP_Alloc(heap_id, sizeof(*svdt), 0, savedata_File, 0x49);

    MIi_CpuClear32(0, svdt, sizeof(*svdt));
    svdt->table = table;
    svdt->table_max = table_max;
    svdt->size_limit = size_limit;
    svdt->header_size = header_size;
    svdt->layout = GFL_HEAP_Alloc(heap_id, table_max * sizeof(*svdt->layout), 1, savedata_File, 0x4f);
    svdt->footer_size = footer_size;
    SAVEDATA_BuildLayout(svdt, block_overhead);
    return svdt;
}

/*
 * SAVEDATA_DeleteTable: free the layout array, then the table record itself.
 */
void SAVEDATA_DeleteTable(struct SaveDataTable *svdt)
{
    GFL_HEAP_Free(svdt->layout);
    GFL_HEAP_Free(svdt);
}

/*
 * SAVEDATA_InitBuffer: clear the whole save buffer, then clear every block
 * at its computed offset and run the block's init function on it.
 */
void SAVEDATA_InitBuffer(u8 *buffer, struct SaveDataTable *svdt)
{
    struct SaveBlockDef *table = svdt->table;
    u32 table_max = svdt->table_max;
    int i;

    MIi_CpuClear32(0, buffer, svdt->size_limit);
    for (i = 0; i < table_max; i++) {
        u32 offset = svdt->layout[i].offset;
        MIi_CpuClear32(0, buffer + offset, svdt->layout[i].size);
        table[i].init_func(buffer + offset);
    }
}

/*
 * SAVEDATA_QueryBlockSize: size of block `id`, as reported by the block's own
 * size function, rounded up to a multiple of four.
 */
u32 SAVEDATA_QueryBlockSize(struct SaveDataTable *svdt, u32 id)
{
    BlockSizeFunc size_func;
    struct SaveBlockDef *table = svdt->table;

    if (id >= svdt->table_max) {
        GF_PANIC_Fail(savedata_File, 0x85, (const char *)savedata_AssertIdInRange);
    }
    size_func = table[id].size_func;
    return (size_func() + 3) & ~3;
}

/*
 * SAVEDATA_BuildLayout: lay out the save blocks (id check, per-block size
 * from SAVEDATA_QueryBlockSize, each block start rounded up to 0x100) and
 * assert the total fits the size limit.  Closed by two declaration facts:
 * GF_PANIC_FailPrintf takes FIVE arguments (the total in r3 and the limit on the
 * stack, which is what the image's `sub sp, sp, #8` and `str r4, [sp]` are),
 * and the locals are declared table, i, table_max, layout, total (i before
 * table_max puts i in r5 and table_max in r6).  The `mov r1, r5` before the
 * size call is that call's second argument.
 */
void SAVEDATA_BuildLayout(struct SaveDataTable *svdt, u32 block_overhead)
{
    struct SaveBlockDef *table;
    u32 i;
    u32 table_max;
    struct SaveBlockPos *layout;
    u32 total;
    u32 size;
    u32 end;
    u32 padding;

    table = svdt->table;
    table_max = svdt->table_max;
    layout = svdt->layout;
    total = 0;

    for (i = 0; i < table_max; i++) {
        if (i != table[i].gmdataID) {
            GF_PANIC_Fail(savedata_File, 0x9e, (const char *)savedata_AssertTableId);
        }
        layout[i].gmdataID = table[i].gmdataID;
        size = SAVEDATA_QueryBlockSize(svdt, i);
        layout[i].size = size;
        layout[i].offset = total;
        end = block_overhead + size;
        padding = end & 0xff;
        if (padding != 0)
            padding = 0x100 - padding;
        else
            padding = 0;
        total += end + padding;
    }
    svdt->total_size = svdt->header_size + (total + svdt->footer_size);
    if (svdt->total_size > svdt->size_limit) {
        GF_PANIC_FailPrintf(savedata_File, 0xb3, (const char *)savedata_AssertTotalSize,
                      svdt->total_size, svdt->size_limit);
    }
}

/*
 * SAVEDATA_GetBlockOffset: offset of block `gmdataid` inside the save area.
 */
u32 SAVEDATA_GetBlockOffset(struct SaveDataTable *svdt, u32 gmdataid)
{
    if (gmdataid >= svdt->table_max) {
        GF_PANIC_Fail(savedata_File, 0xc7, (const char *)savedata_AssertGmdataidInRange);
    }
    return svdt->layout[gmdataid].offset;
}

/*
 * SAVEDATA_GetBlockSize: stored (aligned) size of block `gmdataid`.
 */
u32 SAVEDATA_GetBlockSize(struct SaveDataTable *svdt, u32 gmdataid)
{
    if (gmdataid >= svdt->table_max) {
        GF_PANIC_Fail(savedata_File, 0xd6, (const char *)savedata_AssertGmdataidInRange);
    }
    return svdt->layout[gmdataid].size;
}

/*
 * SAVEDATA_GetTableMax and SAVEDATA_GetTotalSize: plain field accessors on
 * the table record.
 */
u32 SAVEDATA_GetTableMax(struct SaveDataTable *svdt)
{
    return svdt->table_max;
}

u32 SAVEDATA_GetTotalSize(struct SaveDataTable *svdt)
{
    return svdt->total_size;
}
