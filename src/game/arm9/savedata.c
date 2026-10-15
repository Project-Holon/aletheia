/*
 * file:     savedata.c
 * unit:     yes
 * function: SAVEDATA_CreateTable, SAVEDATA_DeleteTable, SAVEDATA_InitBuffer, SAVEDATA_QueryBlockSize, SAVEDATA_BuildLayout, SAVEDATA_GetBlockOffset, SAVEDATA_GetBlockSize, SAVEDATA_GetTableMax, SAVEDATA_GetTotalSize, AREAMAN_Create, AREAMAN_Delete, AREAMAN_Alloc, AREAMAN_AllocUp, AREAMAN_AllocShortUp, AREAMAN_AllocLongUp, AREAMAN_AllocDown, AREAMAN_AllocShortDown, AREAMAN_AllocLongDown, AREAMAN_AllocAt, AREAMAN_Free, AREAMAN_FindClearRunUp, AREAMAN_FindClearRunDown, AREAMAN_ClearByteRun, AREAMAN_MarkUsed, AREAMAN_TraceByte, AREAMAN_TraceBitmap, AREAMAN_TraceAlloc, VMAN_GetBankSetSize, VMAN_Create, VMAN_Delete, VMAN_GetUnitSize, VMAN_InvalidateHandle, VMAN_IsHandleInvalid, VMAN_Alloc, VMAN_Free, VMAN_GetOffset, SAVEDATA_SetPanicHandlers, SAVEDATA_SetFailHook, SAVEDATA_PanicFail, SAVEDATA_PanicFailPrintf
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
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   MIi_CpuClear32   0x02082A7C  arm
 *   savedata_File  0x020A78CC  data
 *   savedata_AssertIdInRange  0x020A78D8  data
 *   savedata_AssertTableId  0x020A78F0  data
 *   savedata_AssertTotalSize  0x020A7908  data
 *   savedata_AssertGmdataidInRange  0x020A793C  data
 *   areaman_File  0x020A7958  data
 *   _LongestFreeRun  0x020A06A0  data
 *   _TrailingFreeRun  0x020A05A0  data
 *   _LeadingFreeRun  0x020A04A0  data
 *   _TopBitsMask  0x020A048C  data
 *   _LowBitsMask  0x020A0495  data
 *   _VramBankSizes  0x020A07C8  data
 *   vman_File  0x020A7964  data
 *   _UnitSizes  0x020A07A0  data
 *   _PanicHandlers  0x0214699C  data
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef u32 (*BlockSizeFunc)(void);
typedef void (*BlockInitFunc)(u32 block_addr);
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

/* ---- areaman.c: bitmap allocator for runs of equal-sized areas ---- */

struct AreaMan {
    u16 area_count;         /* +0x00, number of areas (bits) */
    u16 bitmap_bytes;       /* +0x02, bytes of bitmap, multiple of 4 */
    u32 *guard;             /* +0x04, guard word just past the bitmap */
    u32 trace_enabled;      /* +0x08, nonzero: dump bitmap changes */
    u8 bitmap[1];           /* +0x0c, one bit per area, bit 7 first */
};

#define AREAMAN_GUARD_WORD 0x573C765A

/* ---- vman.c: VRAM bank manager on top of AreaMan ---- */

struct VmanBank {
    struct AreaMan *areaman;    /* +0x00 */
    u16 unit_size;              /* +0x04, bytes per area */
    u16 base;                   /* +0x06, bytes reserved at the start */
};

/* An allocated run: first area and number of areas; all ones when unused. */
struct VmanHandle {
    u32 pos;
    u32 units;
};

struct VramBankSize {
    u32 bank_flag;
    u32 size_kb;
};

struct UnitSizeEntry {
    u32 key;
    u32 unit_size;
};

/* ---- panic handler table, set up by the boot code ---- */

struct PanicHandlers {
    u32 die_func;
    u32 print_func;
    u32 init_func;
    PanicHookFunc fail_hook;
};

extern void *func_02030734(u32 heap_id, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern void MIi_CpuClear32(u32 v, void *dst, u32 n);

struct SaveDataTable *SAVEDATA_CreateTable(u16 heap_id, struct SaveBlockDef *table, u32 table_max, u32 size_limit,
                                    u32 header_size, u32 block_overhead, u32 footer_size);
void SAVEDATA_DeleteTable(struct SaveDataTable *svdt);
void SAVEDATA_InitBuffer(u32 buffer_addr, struct SaveDataTable *svdt);
u32 SAVEDATA_QueryBlockSize(struct SaveDataTable *svdt, u32 id);
void SAVEDATA_BuildLayout(struct SaveDataTable *svdt, u32 block_overhead);
u32 SAVEDATA_GetBlockOffset(struct SaveDataTable *svdt, u32 gmdataid);
u32 SAVEDATA_GetBlockSize(struct SaveDataTable *svdt, u32 gmdataid);
u32 SAVEDATA_GetTableMax(struct SaveDataTable *svdt);
u32 SAVEDATA_GetTotalSize(struct SaveDataTable *svdt);
struct AreaMan *AREAMAN_Create(u32 area_count, u16 heap_id);
u32 AREAMAN_Delete(void *areaman);
s32 AREAMAN_Alloc(struct AreaMan *areaman, u32 len);
s32 AREAMAN_AllocUp(struct AreaMan *areaman, u32 start, u32 limit, u32 len);
s32 AREAMAN_AllocShortUp(struct AreaMan *areaman, u32 start, u32 limit, u32 len);
s32 AREAMAN_AllocLongUp(struct AreaMan *areaman, u32 start, u32 limit, u32 len);
s32 AREAMAN_AllocDown(struct AreaMan *areaman, u32 start, u32 limit, u32 len);
s32 AREAMAN_AllocShortDown(struct AreaMan *areaman, u32 start, u32 limit, u32 len);
s32 AREAMAN_AllocLongDown(struct AreaMan *areaman, u32 start, u32 limit, u32 len);
s32 AREAMAN_AllocAt(struct AreaMan *areaman, u32 start, u32 len);
void AREAMAN_Free(struct AreaMan *areaman, u32 start, s32 len);
s32 AREAMAN_FindClearRunUp(u32 byte_bits, u32 start, u32 len);
s32 AREAMAN_FindClearRunDown(u32 byte_bits, u32 start, u32 len);
void AREAMAN_ClearByteRun(u8 *byte_ptr, u32 start, u32 len);
s32 AREAMAN_MarkUsed(struct AreaMan *areaman, s32 start, u32 len);
void AREAMAN_TraceByte(u8 byte_value);
void AREAMAN_TraceBitmap(struct AreaMan *areaman);
void AREAMAN_TraceAlloc(struct AreaMan *areaman, s32 pos, u32 len, u32 line);
u32 VMAN_GetBankSetSize(u32 bank_flags);
struct VmanBank *VMAN_Create(u16 heap_id, u32 mode, u32 bank_flags, u32 base, u32 mode_arg);
void VMAN_Delete(struct VmanBank *bank);
u32 VMAN_GetUnitSize(u32 key);
void VMAN_InvalidateHandle(struct VmanHandle *handle);
int VMAN_IsHandleInvalid(struct VmanHandle *handle);
int VMAN_Alloc(struct VmanBank *bank, u32 size, struct VmanHandle *out);
void VMAN_Free(struct VmanBank *bank, struct VmanHandle *handle);
u32 VMAN_GetOffset(struct VmanBank *bank, u32 *units_ptr);
void SAVEDATA_SetPanicHandlers(u32 initFunc, u32 printFunc, u32 dieFunc);
void SAVEDATA_SetFailHook(u32 failHook);
void SAVEDATA_PanicFail(const char *file, u32 line, const char *expr);
void SAVEDATA_PanicFailPrintf(const char *file, u32 line, const char *fmt, ...);

extern const char savedata_File[];
extern const u8 savedata_AssertIdInRange[];
extern const u8 savedata_AssertTableId[];
extern const u8 savedata_AssertTotalSize[];
extern const u8 savedata_AssertGmdataidInRange[];
extern const char areaman_File[];
extern const u8 _LongestFreeRun[256];
extern const u8 _TrailingFreeRun[256];
extern const u8 _LeadingFreeRun[256];
extern const u8 _TopBitsMask[];
extern const u8 _LowBitsMask[];
extern const struct VramBankSize _VramBankSizes[9];
extern char vman_File[];
extern const struct UnitSizeEntry _UnitSizes[5];
extern struct PanicHandlers _PanicHandlers;


/*
 * SAVEDATA_CreateTable: allocate the 0x1c-byte table record (tag 0x49) and
 * clear it, store the caller's definitions, entry count, size limit and
 * header size, allocate the 12-byte-per-entry layout array (tag 0x4f), store
 * the footer size, and compute the layout.  The stores go in the order
 * +0 / +4 / +0x10 / +8 / +0x14 / +0x18.  Seven arguments, the last three on
 * the stack.
 */
struct SaveDataTable *SAVEDATA_CreateTable(u16 heap_id, struct SaveBlockDef *table, u32 table_max, u32 size_limit,
                                    u32 header_size, u32 block_overhead, u32 footer_size)
{
    struct SaveDataTable *svdt = func_02030734(heap_id, 0x1c, 0, savedata_File, 0x49);

    MIi_CpuClear32(0, svdt, 0x1c);
    svdt->table = table;
    svdt->table_max = table_max;
    svdt->size_limit = size_limit;
    svdt->header_size = header_size;
    svdt->layout = func_02030734(heap_id, table_max * 12, 1, savedata_File, 0x4f);
    svdt->footer_size = footer_size;
    SAVEDATA_BuildLayout(svdt, block_overhead);
    return svdt;
}


/*
 * SAVEDATA_DeleteTable: free the layout array, then the table record itself.
 */
void SAVEDATA_DeleteTable(struct SaveDataTable *svdt)
{
    func_020307B0(svdt->layout);
    func_020307B0(svdt);
}


/*
 * SAVEDATA_InitBuffer: clear the whole save buffer, then clear every block
 * at its computed offset and run the block's init function on it.
 */
void SAVEDATA_InitBuffer(u32 buffer_addr, struct SaveDataTable *svdt)
{
    struct SaveBlockDef *table = svdt->table;
    u32 table_max = svdt->table_max;
    int i;

    MIi_CpuClear32(0, (void *)buffer_addr, svdt->size_limit);
    for (i = 0; i < table_max; i++) {
        u32 offset = svdt->layout[i].offset;
        MIi_CpuClear32(0, (void *)(buffer_addr + offset), svdt->layout[i].size);
        table[i].init_func(buffer_addr + offset);
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
        SAVEDATA_PanicFail(savedata_File, 0x85, (const char *)savedata_AssertIdInRange);
    }
    size_func = table[id].size_func;
    return (size_func() + 3) & ~3;
}


/*
 * SAVEDATA_BuildLayout: lay out the save blocks (id check, per-block size
 * from SAVEDATA_QueryBlockSize, each block start rounded up to 0x100) and
 * assert the total fits the size limit.  Closed by two declaration facts:
 * SAVEDATA_PanicFailPrintf takes FIVE arguments (the total in r3 and the limit on the
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
            SAVEDATA_PanicFail(savedata_File, 0x9e, (const char *)savedata_AssertTableId);
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
        SAVEDATA_PanicFailPrintf(savedata_File, 0xb3, (const char *)savedata_AssertTotalSize,
                      svdt->total_size, svdt->size_limit);
    }
}


/*
 * SAVEDATA_GetBlockOffset: offset of block `gmdataid` inside the save area.
 */
u32 SAVEDATA_GetBlockOffset(struct SaveDataTable *svdt, u32 gmdataid)
{
    if (gmdataid >= svdt->table_max) {
        SAVEDATA_PanicFail(savedata_File, 0xc7, (const char *)savedata_AssertGmdataidInRange);
    }
    return svdt->layout[gmdataid].offset;
}


/*
 * SAVEDATA_GetBlockSize: stored (aligned) size of block `gmdataid`.
 */
u32 SAVEDATA_GetBlockSize(struct SaveDataTable *svdt, u32 gmdataid)
{
    if (gmdataid >= svdt->table_max) {
        SAVEDATA_PanicFail(savedata_File, 0xd6, (const char *)savedata_AssertGmdataidInRange);
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


/*
 * AREAMAN_Create: constructor of the area manager.  `area_count` is a count
 * of areas; the object carries a bitmap with one bit per area.  The byte
 * count is rounded up from the bit count and then up again to a multiple of
 * four.  The allocation is 0xC bytes of header, the bitmap and a four-byte
 * guard word (0x573C765A) written just past the bitmap, and the bitmap is
 * cleared.  The pool word for the file name holds 0x020A7958 ("areaman.c"),
 * which is what anchors this range.
 */
struct AreaMan *AREAMAN_Create(u32 area_count, u16 heap_id)
{
    struct AreaMan *areaman;
    u32 n;
    u16 nbytes;

    n = ((area_count & 7) != 0) + (area_count >> 3);
    while ((n & 3) != 0) {
        n++;
    }
    nbytes = (u16)n;

    areaman = func_02030734(heap_id, nbytes + 0x10, 0, areaman_File, 0x94);
    areaman->area_count = (u16)area_count;
    areaman->bitmap_bytes = nbytes;
    areaman->guard = (u32 *)(areaman->bitmap + nbytes);
    *areaman->guard = AREAMAN_GUARD_WORD;
    areaman->trace_enabled = 0;
    MI_CpuFill8(areaman->bitmap, 0, nbytes);
    return areaman;
}


/*
 * AREAMAN_Delete: release the manager.  A bare tail call: a pool word and a
 * bx (docs/idioms/tail-call-is-a-pool-word-and-bx.md), so the callee's
 * arguments and result pass straight through.
 */
u32 AREAMAN_Delete(void *areaman)
{
    return func_020307B0(areaman);
}


/*
 * AREAMAN_Alloc: allocate a run of `len` areas anywhere in the bitmap.  It
 * forwards to the ranged form with a start of zero and a limit of the area
 * count.  The forwarding call to the next function in the same file still
 * costs a pool word (one section per function), and keeping both in one unit
 * makes that site local.
 */
s32 AREAMAN_Alloc(struct AreaMan *areaman, u32 len)
{
    return AREAMAN_AllocUp(areaman, 0, areaman->area_count, len);
}


/*
 * AREAMAN_AllocUp: validate the request against the bitmap extent and
 * dispatch on the run length: runs shorter than eight areas go to the
 * bit-at-a-time scanner, longer runs to the byte-at-a-time scanner.  Both
 * arms are written as their own return so that each gets its own `bl`/`pop`
 * pair, as in the original.
 */
s32 AREAMAN_AllocUp(struct AreaMan *areaman, u32 start, u32 limit, u32 len)
{
    if (limit < len || start + len > areaman->area_count) {
        return -1;
    }

    if (len < 8) {
        return AREAMAN_AllocShortUp(areaman, start, limit, len);
    }

    return AREAMAN_AllocLongUp(areaman, start, limit, len);
}


/*
 * AREAMAN_AllocShortUp: bit-at-a-time upward search for a free run shorter
 * than eight areas.  Bit 0 of an area byte is the most significant bit.
 * Looks inside the first byte, then at every following byte, either for a
 * run inside it or for a run that starts in its trailing free bits and
 * continues in the leading free bits of the next byte.  The found run is
 * marked used and traced.
 */
s32 AREAMAN_AllocShortUp(struct AreaMan *areaman, u32 start, u32 limit, u32 len)
{
    s32 found;
    s32 last;
    s32 last_byte;
    s32 i;
    s32 bit;
    u32 trailing;

    last = start + limit + 1 - len;
    last_byte = last / 8;
    i = start >> 3;
    found = -1;

    if ((start & 7) + len <= 8) {
        bit = AREAMAN_FindClearRunUp(areaman->bitmap[i], start & 7, len);
        if (bit != -1) {
            found = bit + i * 8;
            goto done;
        }
    }

    while (i <= last_byte) {
        if (_LongestFreeRun[areaman->bitmap[i]] >= len) {
            bit = AREAMAN_FindClearRunUp(areaman->bitmap[i], 0, len);
            if (bit != -1) {
                found = bit + i * 8;
                goto done;
            }
        } else {
            trailing = _TrailingFreeRun[areaman->bitmap[i]];
            if (trailing != 0 && i < last_byte) {
                if (_LeadingFreeRun[areaman->bitmap[i + 1]] >= len - trailing) {
                    found = (8 - trailing) + i * 8;
                    goto done;
                }
            }
        }
        i++;
    }

done:
    if (found != -1 && found <= last) {
        if (AREAMAN_MarkUsed(areaman, found, len) == 0) {
            return -1;
        }
        AREAMAN_TraceAlloc(areaman, found, len, 0x17c);
        return found;
    }
    return -1;
}


/*
 * AREAMAN_AllocLongUp: byte-at-a-time upward search for a free run of eight
 * areas or more.  It anchors on the trailing free run of byte `i`, skips
 * whole zero bytes, and then checks the leading free run of the byte the
 * remainder lands in.
 */
s32 AREAMAN_AllocLongUp(struct AreaMan *areaman, u32 start, u32 limit, u32 len)
{
    u32 last;
    s32 last_byte;
    s32 run;
    s32 trailing_run;
    s32 remaining;
    s32 i;
    s32 full_bytes;
    s32 next;
    s32 rest_bits;
    s32 found;

    i = start >> 3;
    last = start + limit - len;
    last_byte = last / 8;

    run = 8 - (start & 7);
    trailing_run = _TrailingFreeRun[areaman->bitmap[i]];
    if (trailing_run < run) {
        run = trailing_run;
    }

    while (i <= last_byte) {
        if (run != 0) {
            remaining = len - run;
            full_bytes = remaining / 8;
            rest_bits = remaining % 8;
            next = i + 1;
            while (full_bytes != 0) {
                if (areaman->bitmap[next] != 0) {
                    break;
                }
                next++;
                full_bytes--;
            }
            if (full_bytes == 0) {
                found = -1;
                if (rest_bits == 0) {
                    found = (8 - run) + i * 8;
                } else if (_LeadingFreeRun[areaman->bitmap[next]] >= rest_bits) {
                    found = (8 - run) + i * 8;
                }
                if (found != -1) {
                    if (AREAMAN_MarkUsed(areaman, found, len) == 0) {
                        return -1;
                    }
                    AREAMAN_TraceAlloc(areaman, found, len, 0x1db);
                    return found;
                }
            }
        }
        i++;
        if (i <= last_byte) {
            run = _TrailingFreeRun[areaman->bitmap[i]];
        }
    }

    return -1;
}


/*
 * AREAMAN_AllocDown: like AREAMAN_AllocUp but searching towards lower
 * positions: short runs go to the bit scanner, long runs to the byte
 * scanner; the result is traced with line 0x230.
 */
s32 AREAMAN_AllocDown(struct AreaMan *areaman, u32 start, u32 limit, u32 len)
{
    s32 pos;

    if (limit < len) {
        return -1;
    }

    if (len < 8) {
        pos = AREAMAN_AllocShortDown(areaman, start, limit, len);
    } else {
        pos = AREAMAN_AllocLongDown(areaman, start, limit, len);
    }

    AREAMAN_TraceAlloc(areaman, pos, len, 0x230);
    return pos;
}


/*
 * AREAMAN_AllocShortDown: the downward bit-at-a-time scanner, the mirror of
 * AREAMAN_AllocShortUp walking towards lower addresses.
 */
s32 AREAMAN_AllocShortDown(struct AreaMan *areaman, u32 start, u32 limit, u32 len)
{
    s32 i;
    s32 last;
    s32 last_byte;
    s32 found;
    s32 bit;
    u32 leading;

    last = start - limit + 1;
    last_byte = last / 8;
    i = start >> 3;
    found = -1;

    if ((start & 7) != 0) {
        bit = AREAMAN_FindClearRunDown(areaman->bitmap[i], start & 7, len);
        if (bit != -1) {
            found = bit + i * 8;
            goto done;
        }
    }

    while (i >= last_byte) {
        if (_LongestFreeRun[areaman->bitmap[i]] >= len) {
            bit = AREAMAN_FindClearRunDown(areaman->bitmap[i], 7, len);
            if (bit != -1) {
                found = bit + i * 8;
                goto done;
            }
        } else {
            leading = _LeadingFreeRun[areaman->bitmap[i]];
            if (leading != 0 && i > last_byte) {
                if (_TrailingFreeRun[areaman->bitmap[i - 1]] >= len - leading) {
                    found = (8 - (len - leading)) + (i - 1) * 8;
                    goto done;
                }
            }
        }
        i--;
    }

done:
    if (found != -1 && found >= last) {
        if (AREAMAN_MarkUsed(areaman, found, len) == 0) {
            found = -1;
        }
        return found;
    }
    return -1;
}


/*
 * AREAMAN_AllocLongDown: the downward byte-at-a-time scanner, the mirror of
 * AREAMAN_AllocLongUp.  The anchor is the leading free run of byte `i`,
 * whole zero bytes are skipped downwards, and the trailing free run of the
 * byte the remainder lands in closes the request.
 */
s32 AREAMAN_AllocLongDown(struct AreaMan *areaman, u32 start, u32 limit, u32 len)
{
    s32 i;
    u32 last;
    s32 last_byte;
    s32 run;
    s32 rest_bits;
    s32 leading_run;
    s32 remaining;
    s32 full_bytes;
    s32 next;
    s32 found;

    last = start - limit + 1;
    i = start >> 3;
    last_byte = last / 8;

    run = (start & 7) + 1;
    leading_run = _LeadingFreeRun[areaman->bitmap[i]];
    if (leading_run < run) {
        run = leading_run;
    }

    while (i >= last_byte) {
        if (run != 0) {
            remaining = len - run;
            full_bytes = remaining / 8;
            rest_bits = remaining % 8;
            next = i - 1;
            while (full_bytes != 0) {
                if (next < last_byte || areaman->bitmap[next] != 0) {
                    break;
                }
                next--;
                full_bytes--;
            }
            if (full_bytes == 0) {
                found = -1;
                if (rest_bits == 0) {
                    found = (next + 1) * 8;
                } else if (next >= last_byte && _TrailingFreeRun[areaman->bitmap[next]] >= rest_bits) {
                    found = (8 - rest_bits) + next * 8;
                }
                if (found != -1 && found >= last) {
                    if (AREAMAN_MarkUsed(areaman, found, len) == 0) {
                        found = -1;
                    }
                    return found;
                }
            }
        }
        i--;
        if (i >= last_byte) {
            run = _LeadingFreeRun[areaman->bitmap[i]];
        }
    }

    return -1;
}


/*
 * AREAMAN_AllocAt: try to take the run [start, start+len) at a fixed place.
 * AREAMAN_MarkUsed fails when any bit is already set; on success the change
 * is traced with line 0x304.  The three arguments live in callee-saved
 * registers across the first call because the second call needs them again.
 */
s32 AREAMAN_AllocAt(struct AreaMan *areaman, u32 start, u32 len)
{
    if (AREAMAN_MarkUsed(areaman, start, len) == 0) {
        return 0;
    }

    AREAMAN_TraceAlloc(areaman, start, len, 0x304);
    return 1;
}


/*
 * AREAMAN_Free: clear `len` bits starting at bit `start` of the bitmap.  A
 * run inside one byte goes to AREAMAN_ClearByteRun; otherwise the head bits
 * are cleared with the low-bits mask, whole bytes are zeroed and the top-bits
 * mask clears the head of the last byte.  AREAMAN_TraceBitmap then reports
 * the new state.
 *
 * The byte cursor past the head is the PARAMETER reused, `start = idx + 1;`,
 * not idx incremented.  That puts the cursor in start's own register r1 and
 * rotates the zero and the count to the image's r2 / r3; the same lever
 * closes AREAMAN_MarkUsed.
 * docs/idioms/a-dead-parameter-reused-as-the-index-rotates-the-loop-registers.md.
 */
void AREAMAN_Free(struct AreaMan *areaman, u32 start, s32 len)
{
    u32 bit = start % 8;
    u32 idx = start / 8;
    s32 avail;
    s32 rest;
    u32 full_bytes;
    u32 rest_bits;
    u32 mask;

    if ((bit + len) <= 8) {
        AREAMAN_ClearByteRun(&areaman->bitmap[idx], bit, len);
    } else {
        avail = 8 - bit;
        mask = _LowBitsMask[avail];
        rest = len - avail;
        full_bytes = rest / 8;
        rest_bits = rest % 8;
        areaman->bitmap[idx] &= (u8)~mask;
        start = idx + 1;
        while (full_bytes-- != 0) {
            areaman->bitmap[start] = 0;
            start++;
        }
        areaman->bitmap[start] &= (u8)~_TopBitsMask[rest_bits];
    }
    AREAMAN_TraceBitmap(areaman);
}


/*
 * AREAMAN_FindClearRunUp: inside one bitmap byte, starting at bit `start`,
 * walk the run mask down and return the first bit position at which `len`
 * consecutive bits are all clear, or -1.
 *
 * _TopBitsMask is a nine byte table, 00 80 C0 E0 F0 F8 FC FE FF, the mask of
 * the top `len` bits of a byte; the entry for len == 8 is the last, which is
 * why the length guard is `> 8` here and `>= 8` in the downward scanner
 * (that one indexes the same table after adding one).  The address has three
 * pool words in the image, so compiling this function alone leaves two of
 * them outside the compared range.
 */
s32 AREAMAN_FindClearRunUp(u32 byte_bits, u32 start, u32 len)
{
    u8 mask;
    u32 last;

    if (len <= 8) {
        last = 8 - len;
        mask = _TopBitsMask[len] >> start;

        while (start <= last) {
            if ((byte_bits & mask) == 0) {
                return start;
            }
            mask >>= 1;
            start++;
        }
    }

    return -1;
}


/*
 * AREAMAN_FindClearRunDown: the backward twin of AREAMAN_FindClearRunUp:
 * same mask table, but the cursor walks down from `start`, so the mask is
 * shifted left each step and the loop ends when the signed cursor goes
 * negative.  The cursor really is signed: the original reuses the flags of
 * the `subs` that computes it for both the entry guard (`bmi`) and the loop
 * back edge (`bpl`).
 */
s32 AREAMAN_FindClearRunDown(u32 byte_bits, u32 start, u32 len)
{
    u8 mask;
    s32 i;

    if (len < 8) {
        i = (s32)(start + 1) - (s32)len;
        mask = _TopBitsMask[len] >> i;

        while (i >= 0) {
            if ((byte_bits & mask) == 0) {
                return i;
            }
            mask <<= 1;
            i--;
        }
    }

    return -1;
}


/*
 * AREAMAN_ClearByteRun: clear a run of `len` bits starting at bit `start`
 * inside one bitmap byte, with the same top-bits mask table as the scanners.
 * The `and r1, r1, #0xff` after the complement is the u8 truncation, not a
 * mask written in the source.
 */
void AREAMAN_ClearByteRun(u8 *byte_ptr, u32 start, u32 len)
{
    u8 mask = _TopBitsMask[len] >> start;

    *byte_ptr = *byte_ptr & (u8)~mask;
}


/*
 * AREAMAN_MarkUsed: mark `len` bits starting at bit `start` of the bitmap as
 * used.  Fails (0) past the managed range or when any target bit is already
 * set (dumping the mask and the byte through AREAMAN_TraceByte when tracing
 * is enabled); otherwise it sets the head bits, fills whole bytes with 0xFF
 * and ORs the tail mask into the last byte.
 *
 * The byte index is the PARAMETER reused, `start = start / 8;`, not a fresh
 * local: that is the image's `asr r1, r1, #3` into start's own register,
 * which rotates the index/count/tail registers to r1/r3/r2; with it the
 * then-arm zeros go in the natural order `full_bytes = 0; rest_bits = 0;`.
 * docs/idioms/a-dead-parameter-reused-as-the-index-rotates-the-loop-registers.md.
 */
s32 AREAMAN_MarkUsed(struct AreaMan *areaman, s32 start, u32 len)
{
    u32 bit;
    u32 avail;
    u32 full_bytes;
    u32 rest_bits;
    u32 mask;
    u8 *byte_ptr;
    u8 value;

    if (start + len > areaman->area_count) {
        return 0;
    }

    bit = start % 8;
    avail = 8 - bit;
    start = start / 8;
    if (avail >= len) {
        mask = _TopBitsMask[len] >> bit;
        full_bytes = 0;
        rest_bits = 0;
    } else {
        len = len - avail;
        mask = _LowBitsMask[avail];
        full_bytes = len >> 3;
        rest_bits = len & 7;
    }
    byte_ptr = &areaman->bitmap[start];
    value = areaman->bitmap[start];
    if ((mask & value) != 0) {
        if (areaman->trace_enabled != 0) {
            AREAMAN_TraceByte((u8)mask);
            AREAMAN_TraceByte(areaman->bitmap[start]);
        }
        return 0;
    }
    start++;
    *byte_ptr = value | (u8)mask;
    while (full_bytes-- != 0) {
        areaman->bitmap[start] = 0xFF;
        start++;
    }
    if (rest_bits != 0) {
        areaman->bitmap[start] |= _TopBitsMask[rest_bits];
    }
    return 1;
}


/*
 * AREAMAN_TraceByte: the trace hook, a single `bx lr`.  An empty function
 * body, kept as a real entry point because AREAMAN_TraceBitmap calls it once
 * per loop iteration (the debug output was compiled out of the release
 * build).
 */
void AREAMAN_TraceByte(u8 byte_value)
{
}


/*
 * AREAMAN_TraceBitmap: when tracing is enabled, pass every bitmap byte to
 * AREAMAN_TraceByte.
 */
void AREAMAN_TraceBitmap(struct AreaMan *areaman)
{
    if (areaman->trace_enabled != 0) {
        int i;
        for (i = 0; i < areaman->bitmap_bytes; i++) {
            AREAMAN_TraceByte(areaman->bitmap[i]);
        }
    }
}


/*
 * AREAMAN_TraceAlloc: guard-and-forward: report the bitmap through
 * AREAMAN_TraceBitmap only when tracing is enabled.  The position, length
 * and source line are only used by the debug build of the trace.
 */
void AREAMAN_TraceAlloc(struct AreaMan *areaman, s32 pos, u32 len, u32 line)
{
    if (areaman->trace_enabled != 0) {
        AREAMAN_TraceBitmap(areaman);
    }
}


/*
 * VMAN_GetBankSetSize: sum the sizes of the nine VRAM banks whose flag bit is
 * set in `bank_flags`, scaled from kilobytes to bytes (`<< 0xa`).
 */
u32 VMAN_GetBankSetSize(u32 bank_flags)
{
    u32 i;
    u32 sum = 0;

    for (i = 0; i < 9; i++) {
        if (bank_flags & _VramBankSizes[i].bank_flag) {
            sum += _VramBankSizes[i].size_kb;
        }
    }
    return sum << 0xa;
}


/*
 * VMAN_Create: allocate a VRAM bank record and carve its area map: the bank
 * set's size less the base, divided by the unit size (0x20, or the size from
 * VMAN_GetUnitSize(mode_arg) when mode is 1).  The image stores the unit size
 * into the record in each arm and the divide re-reads the field (`strh` then
 * `ldrh r1, [r5, #4]`), so there is no unit-size local.
 */
struct VmanBank *VMAN_Create(u16 heap_id, u32 mode, u32 bank_flags, u32 base, u32 mode_arg)
{
    struct VmanBank *bank;
    u32 size;

    bank = func_02030734(heap_id, 8, 0, vman_File, 0x7a);
    size = VMAN_GetBankSetSize(bank_flags) - base;
    if (mode == 1)
        bank->unit_size = VMAN_GetUnitSize(mode_arg);
    else
        bank->unit_size = 0x20;
    bank->areaman = AREAMAN_Create(size / bank->unit_size, heap_id);
    bank->base = base;
    return bank;
}


/*
 * VMAN_Delete: delete the bank's area manager, then the bank record.
 */
void VMAN_Delete(struct VmanBank *bank)
{
    AREAMAN_Delete(bank->areaman);
    func_020307B0(bank);
}


/*
 * VMAN_GetUnitSize: five-entry linear search over _UnitSizes for `key`,
 * returning the unit size of the matching entry or a default of 0x20.
 */
u32 VMAN_GetUnitSize(u32 key)
{
    u32 i;

    for (i = 0; i < 5; i++) {
        if (_UnitSizes[i].key == key) {
            return _UnitSizes[i].unit_size;
        }
    }
    return 0x20;
}


/*
 * VMAN_InvalidateHandle and VMAN_IsHandleInvalid: a handle is invalid when
 * both of its words are 0xFFFFFFFF.
 */
void VMAN_InvalidateHandle(struct VmanHandle *handle)
{
    handle->pos = 0xFFFFFFFFu;
    handle->units = 0xFFFFFFFFu;
}


int VMAN_IsHandleInvalid(struct VmanHandle *handle)
{
    return handle->pos == 0xFFFFFFFFu && handle->units == 0xFFFFFFFFu;
}


/*
 * VMAN_Alloc: round `size` bytes up to whole units, take that many areas
 * from the bank's area manager and, on success, return the first area and
 * the area count in `out`.  Returns 1 on success, 0 when no run was free.
 */
int VMAN_Alloc(struct VmanBank *bank, u32 size, struct VmanHandle *out)
{
    u16 unit_size = bank->unit_size;
    u32 units = size / unit_size;
    u32 pos;

    if (size % unit_size != 0) {
        units++;
    }
    pos = AREAMAN_Alloc(bank->areaman, units);
    if (pos != (u32)-1) {
        out->pos = pos;
        out->units = units;
        return 1;
    }
    return 0;
}


/*
 * VMAN_Free: hand a handle's run back to the bank's area manager and then
 * invalidate the handle in place.  The handle's two words are the argument
 * pair, which is the `ldm r4, {r1, r2}`: one aggregate read of the handle.
 * The handle is copied into a callee-saved register because it is needed
 * again afterwards for VMAN_InvalidateHandle; the bank load is consumed by
 * the first call.
 */
void VMAN_Free(struct VmanBank *bank, struct VmanHandle *handle)
{
    AREAMAN_Free(bank->areaman, handle->pos, handle->units);
    VMAN_InvalidateHandle(handle);
}


/*
 * VMAN_GetOffset: byte offset of the area numbered *units_ptr:
 * *units_ptr * unit_size + base.
 */
u32 VMAN_GetOffset(struct VmanBank *bank, u32 *units_ptr)
{
    return *units_ptr * bank->unit_size + bank->base;
}


/*
 * Registers the three panic handlers in _PanicHandlers.  Only offsets 0, 4
 * and 8 are written; the fail hook at +0xc is set by the next function.
 */
void SAVEDATA_SetPanicHandlers(u32 initFunc, u32 printFunc, u32 dieFunc)
{
    _PanicHandlers.init_func = initFunc;
    _PanicHandlers.print_func = printFunc;
    _PanicHandlers.die_func = dieFunc;
}


/*
 * Sets the fail hook that the assert functions below call.
 */
void SAVEDATA_SetFailHook(u32 failHook)
{
    _PanicHandlers.fail_hook = (PanicHookFunc)failHook;
}


/*
 * The assert failure trampoline all `bl 0x2034714` sites reach: the callers
 * pass file name, line and expression string, in that order.  If a fail hook
 * is registered, call it.  This is the forwarding-call idiom read in
 * reverse (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md):
 * the call is `hook()`, zero C-visible arguments, and r1/r2 survive into the
 * hook only because nothing here touches them.  Writing the call as
 * `hook(line, expr)` forces two `mov`s that are not in the original.  The
 * parameters are declared to keep the prototype honest for callers and are
 * otherwise dead in the body.
 */
void SAVEDATA_PanicFail(const char *file, u32 line, const char *expr)
{
    PanicHookFunc failHook = _PanicHandlers.fail_hook;

    if (failHook) {
        failHook();
    }
}


/*
 * The printf-shaped sibling of the assert trampoline: byte for byte the same
 * body, dispatching the hook through `blx` so a Thumb handler works, wrapped
 * in a variadic frame.  The whole difference is the trailing `...`: a
 * variadic function homes all four argument registers (leading
 * `push {r0, r1, r2, r3}`, see
 * docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md) and
 * its epilogue becomes `pop {r3, lr}` / `add sp, sp, #0x10` / `bx lr`.  No
 * `va_start` appears because this function never reads the variadic tail;
 * the registered hook does.  As above, calling the hook with arguments would
 * add `mov`s the original does not have.
 */
void SAVEDATA_PanicFailPrintf(const char *file, u32 line, const char *fmt, ...)
{
    PanicHookFunc failHook = _PanicHandlers.fail_hook;

    if (failHook) {
        failHook();
    }
}
