/*
 * file:     vman.c
 * unit:     yes
 * function: VMAN_GetBankSetSize, VMAN_Create, VMAN_Delete, VMAN_GetUnitSize, VMAN_InvalidateHandle, VMAN_IsHandleInvalid, VMAN_Alloc, VMAN_Free, VMAN_GetOffset
 * address:  0x02034520
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from vman.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc              0x02030734  arm
 *   GFL_HEAP_Free              0x020307B0  arm
 *   AREAMAN_Create             0x02033C00  arm
 *   AREAMAN_Delete             0x02033C9C  arm
 *   AREAMAN_Alloc              0x02033CA8  arm
 *   AREAMAN_Free               0x0203422C  arm
 *   vman_File                  0x020A7964  data
 *   _VramBankSizes             0x020A07C8  data
 *   _UnitSizes                 0x020A07A0  data
 *   _u32_div_f                   0x0209C2B0  arm
 */

#include "../types.h"

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

extern void *GFL_HEAP_Alloc(u32 heap_id, u32 size, int clear, const char *file, u16 line);

extern u32 GFL_HEAP_Free(void *p);

struct AreaMan;

struct AreaMan *AREAMAN_Create(u32 area_count, u16 heap_id);

u32 AREAMAN_Delete(void *areaman);

s32 AREAMAN_Alloc(struct AreaMan *areaman, u32 len);

void AREAMAN_Free(struct AreaMan *areaman, u32 start, s32 len);

u32 VMAN_GetBankSetSize(u32 bank_flags);

struct VmanBank *VMAN_Create(u16 heap_id, u32 mode, u32 bank_flags, u32 base, u32 mode_arg);

void VMAN_Delete(struct VmanBank *bank);

u32 VMAN_GetUnitSize(u32 key);

void VMAN_InvalidateHandle(struct VmanHandle *handle);

int VMAN_IsHandleInvalid(struct VmanHandle *handle);

int VMAN_Alloc(struct VmanBank *bank, u32 size, struct VmanHandle *out);

void VMAN_Free(struct VmanBank *bank, struct VmanHandle *handle);

u32 VMAN_GetOffset(struct VmanBank *bank, u32 *units_ptr);

extern const struct VramBankSize _VramBankSizes[9];

extern char vman_File[];

extern const struct UnitSizeEntry _UnitSizes[5];

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

    bank = GFL_HEAP_Alloc(heap_id, 8, 0, vman_File, 0x7a);
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
    GFL_HEAP_Free(bank);
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
