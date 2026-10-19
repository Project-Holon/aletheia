/*
 * file:     met_trainers_savedata.c
 * unit:     yes
 * function: MET_TRAINERS_GetSize, MET_TRAINERS_Init, MET_TRAINERS_GetFromSave, MET_TRAINERS_Insert, MET_TRAINERS_Contains, MET_TRAINERS_TestBit, MET_TRAINERS_SetBit
 * address:  0x0200ED38
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from misc_savedata_2.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 */
#include "misc_savedata_shared_types.h"
#include "greeting_savedata_shared_types.h"

/* Save block 0x44 (0xFC bytes): the 32 most recently met trainer ids and a
 * 256-bit bitmap. */
struct MetTrainersSave {
    u32 values[32];         /* +0x00 */
    u32 count;              /* +0x80 */
    u8  bitmap[0x20];       /* +0x84 */
};

extern void MI_CpuFill8(void *dst, unsigned char val, unsigned long size);
struct SaveControl;

extern void *SAVE_CONTROL_GetBlock(struct SaveControl *saveControl, u32 blockId);

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

extern void *SAVE_CONTROL_GetBlock(struct SaveControl *saveControl, u32 blockId);

u32 MET_TRAINERS_GetSize(void);

void MET_TRAINERS_Init(void *block);

void *MET_TRAINERS_GetFromSave(void *p);

void MET_TRAINERS_Insert(struct MetTrainersSave *l, u32 val);

int MET_TRAINERS_Contains(struct MetTrainersSave *l, u32 val);

int MET_TRAINERS_TestBit(char *obj, int i);

void MET_TRAINERS_SetBit(char *obj, int i);

/*
 * Save-table size callback: returns 0xFC, the size of the block that
 * MET_TRAINERS_Init clears.  Pointer word 0x0200ED39 at 0x0209DD5C.
 */
u32 MET_TRAINERS_GetSize(void)
{
    return 0xFC;
}

/*
 * Save-table init callback: clears the 0xFC-byte block (tail call to
 * MI_CpuFill8 through the pool word at 0x0200ED44).  Pointer word
 * 0x0200ED3D at 0x0209DD60.
 */
void MET_TRAINERS_Init(void *block)
{
    MI_CpuFill8(block, 0, 0xFC);
}

void *MET_TRAINERS_GetFromSave(void *saveData)
{
    return SAVE_CONTROL_GetBlock(saveData, 0x44);
}

/*
 * Insert `val` into a 32-entry u32 list unless it is already there: the
 * table is the object's first 0x80 bytes and the count lives at +0x80.
 * When the value is found at index i, everything above it shifts up one
 * slot (the memmove) and the value is rewritten into the last live slot
 * (`p[-1]` on a pointer to one past the end), so the list keeps its
 * length; when it is not found and there is room it goes at the end, and
 * when the list is full the whole table shifts up one slot and the value
 * lands in slot 31.
 *
 * Two shapes the bytes pinned down, both from
 * docs/idioms/pointer-minus-one-scales-before-the-subtraction.md and the
 * signed/unsigned split:
 *
 *  - the copy is MI_CpuCopy8(src, dst, size) -- the SDK's argument order,
 *    which is why the source passes the higher index first: the shift is
 *    downward, arr[i+1] is copied onto arr[i];
 *  - the trailing store is NOT `l->values[l->count - 1]` (which subtracts one
 *    from the count and then scales) but `p[-1]` on a pointer computed as
 *    `l->values + l->count`: the original scales the count by four first and
 *    subtracts the element size afterwards, four instructions against
 *    three and the whole tail shifts;
 *  - the walk is unsigned (`bls`/`blo`) while the element count `n` that
 *    gates the shift is signed (`ble`).
 *
 * EXACT* rather than EXACT: the follower at 0x0200EDC4 saves registers but
 * not lr, so disasm.py did not label it (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md) and the inferred extent
 * runs to 0x0200EE48. The bytes all match; see
 * src/matched/unit_0200EDC4.c for that follower, which this project can
 * reproduce but has not been able to seed in layout/function_starts.txt.
 */
void MET_TRAINERS_Insert(struct MetTrainersSave *list, u32 value)
{
    u32 index;
    int shiftCount;

    for (index = 0; index < list->count; index++) {
        if (list->values[index] != value)
            continue;
        shiftCount = (int)list->count - 1 - (int)index;
        if (shiftCount <= 0)
            return;
        MI_CpuCopy8(&list->values[index + 1], &list->values[index], (u32)shiftCount * 4);
        {
            u32 *end = list->values + list->count;
            end[-1] = value;
        }
        return;
    }

    if (list->count < 32) {
        list->values[list->count] = value;
        list->count++;
        return;
    }

    MI_CpuCopy8(&list->values[1], &list->values[0], 0x7c);
    list->values[31] = value;
    list->count = 32;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * The three functions that follow MET_TRAINERS_Insert (src/matched/
 * MET_TRAINERS_Insert.c) inside this packet, none of which carries a label in
 * the generated listing: 0x0200EDC4 saves registers but not lr, and the
 * other two save nothing, so disasm.py's lr-saving prologue sweep never
 * fired on any of them and they print as runs of `.word` (docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  Nothing branches to
 * them either: the only references are the calls from the two functions
 * just past the end of the range.
 *
 * 0x0200EDC4, 40 bytes, is `contains` on the same 32-entry list
 * MET_TRAINERS_Insert inserts into, and 0x0200EDEC / 0x0200EE14 are the
 * get-bit and set-bit pair of a 256-bit bitmap at +0x84 of the same
 * object, both written with a signed index (`/ 32` and `% 32`, which is
 * what the `asrs`/`rors` pair is).
 */
int MET_TRAINERS_Contains(struct MetTrainersSave *list, u32 value)
{
    u32 index;

    for (index = 0; index < list->count; index++) {
        if (list->values[index] == value)
            return 1;
    }
    return 0;
}

int MET_TRAINERS_TestBit(char *list, int bitIndex)
{
    u32 *bitmap = (u32 *)(list + 0x84);

    return (bitmap[bitIndex / 32] >> (bitIndex % 32)) & 1;
}

void MET_TRAINERS_SetBit(char *list, int bitIndex)
{
    if (bitIndex >= 256)
        return;
    ((u32 *)(list + 0x84))[bitIndex / 32] |= (u32)(1 << (bitIndex % 32));
}
