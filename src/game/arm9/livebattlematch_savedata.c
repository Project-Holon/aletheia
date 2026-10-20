/*
 * file:     livebattlematch_savedata.c
 * unit:     yes
 * function: LIVEBATTLEMATCH_SAVE_InitRecord, LIVEBATTLEMATCH_SAVE_GetCounter, LIVEBATTLEMATCH_SAVE_AddCounter, LIVEBATTLEMATCH_SAVE_GetOpponentMac, LIVEBATTLEMATCH_SAVE_SetOpponentMac, LIVEBATTLEMATCH_SAVE_SetOpponentResultByte, LIVEBATTLEMATCH_SAVE_HasOpponentMac, LIVEBATTLEMATCH_SAVE_GetSize, LIVEBATTLEMATCH_SAVE_Init, LIVEBATTLEMATCH_SAVE_GetFromSave, LIVEBATTLEMATCH_SAVE_GetStats, LIVEBATTLEMATCH_SAVE_GetStats2, LIVEBATTLEMATCH_SAVE_GetRecord
 * address:  0x0200E904
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
 *   OS_GetMacAddress 0x02087C6C  arm
 *   LIVEBATTLEMATCH_SAVE_GetCounter  0x0200E918  thumb
 *   LIVEBATTLEMATCH_SAVE_GetOpponentMac  0x0200E938  thumb
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   BSUBWAY_SAVEDATA_InitStats  0x0200DFCC  thumb
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "greeting_savedata_shared_types.h"

#include "../types.h"

#include "mi_memory.h"
struct SaveControl;

#include "save_control.h"

#include "os_ownerinfo.h"


#include "gf_standard.h"

typedef unsigned short StatRow;
#include "bsubway_savedata.h"


void LIVEBATTLEMATCH_SAVE_InitRecord(void *obj);

u8 LIVEBATTLEMATCH_SAVE_GetCounter(const u8 *base, u32 idx);

void LIVEBATTLEMATCH_SAVE_AddCounter(u8 *base, u32 idx, int delta);

void LIVEBATTLEMATCH_SAVE_GetOpponentMac(u8 *obj, u32 id, void *dest);

void LIVEBATTLEMATCH_SAVE_SetOpponentMac(u8 *obj, u32 id, const void *src);

void LIVEBATTLEMATCH_SAVE_SetOpponentResultByte(u8 *obj, u32 id, u32 extra, u8 value);

u32 LIVEBATTLEMATCH_SAVE_HasOpponentMac(void *base, void *key);

unsigned int LIVEBATTLEMATCH_SAVE_GetSize(void);

void LIVEBATTLEMATCH_SAVE_Init(void *record);

void *LIVEBATTLEMATCH_SAVE_GetFromSave(void *p);

int LIVEBATTLEMATCH_SAVE_GetStats(int p);

int LIVEBATTLEMATCH_SAVE_GetStats2(int p);

int LIVEBATTLEMATCH_SAVE_GetRecord(int p);

void LIVEBATTLEMATCH_SAVE_InitRecord(void *buffer)
{
    MI_CpuFill8(buffer, 0, 0x5a);
    OS_GetMacAddress(buffer);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: a byte array at offset 6 of some base object, indexed by the second
 * parameter.  LIVEBATTLEMATCH_SAVE_GetCounter is the plain getter; LIVEBATTLEMATCH_SAVE_AddCounter adds a signed
 * delta to one element and clamps the result to 0..255 before storing it
 * back.  LIVEBATTLEMATCH_SAVE_GetCounter has no register-saving prologue (two instructions, no
 * push), so disasm.py's sweep never labelled it; it sits in the listing as a
 * .word between two functions.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E918.c \
 *       --addr 0x0200E918 --thumb
 */
u8 LIVEBATTLEMATCH_SAVE_GetCounter(const u8 *keys, u32 index)
{
    return (keys + index)[6];
}

void LIVEBATTLEMATCH_SAVE_AddCounter(u8 *keys, u32 index, int delta)
{
    u8 *array = keys + 6;
    int value = array[index] + delta;

    if (value > 0xff) {
        value = 0xff;
    } else if (value < 0) {
        value = 0;
    }
    array[index] = (u8)value;
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * alias: three accessors on an array of 6-byte records that starts 0xa bytes
 * into the object, indexed by "id mod 10".  LIVEBATTLEMATCH_SAVE_GetOpponentMac reads a record out,
 * LIVEBATTLEMATCH_SAVE_SetOpponentMac stores one in, and LIVEBATTLEMATCH_SAVE_SetOpponentResultByte writes a single byte field at
 * +0x10 past an extra caller-given offset from the same slot.  Each divides
 * by 10 for the remainder only; the
 * quotient the helper also returns is never used, per
 * docs/idioms/div-and-mod-are-two-calls.md and
 * docs/idioms/runtime-helper-reloc.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E938.c \
 *       --addr 0x0200E938 --thumb
 */
void LIVEBATTLEMATCH_SAVE_GetOpponentMac(u8 *obj, u32 id, void *dest)
{
    u32 idx = id % 10;

    MI_CpuCopy8(obj + 0xa + idx * 8, dest, 6);
}

void LIVEBATTLEMATCH_SAVE_SetOpponentMac(u8 *obj, u32 id, const void *src)
{
    u32 idx = id % 10;

    MI_CpuCopy8(src, obj + 0xa + idx * 8, 6);
}

void LIVEBATTLEMATCH_SAVE_SetOpponentResultByte(u8 *obj, u32 id, u32 extra, u8 value)
{
    u32 idx = id % 10;
    u8 *p = obj + idx * 8;

    p += extra;
    p[0x10] = value;
}

/*
 * Linear search over up to 10 stored 6-byte keys: LIVEBATTLEMATCH_SAVE_GetCounter(base, 0)
 * gives the stored count (capped at 10), LIVEBATTLEMATCH_SAVE_GetOpponentMac copies the i'th key
 * into a stack buffer, and GF_STANDARD_CompareBytes (DWC's own key comparator)
 * compares it against the caller's key. Returns 1 on the first match, 0
 * if none of the stored keys match.
 *
 * EXACT* because the 70 compiled bytes fall six short of the disasm.py
 * extent: LIVEBATTLEMATCH_SAVE_GetSize, a four-byte constant getter with no
 * register-saving prologue, hides in the two trailing pad bytes plus this
 * function's own alignment filler (see "the two missing labels" in
 * docs/MATCHING.md); it is matched separately.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/LIVEBATTLEMATCH_SAVE_HasOpponentMac.c \
 *       --func LIVEBATTLEMATCH_SAVE_HasOpponentMac --addr 0x0200E994 --cc 1.1p1
 */
u32 LIVEBATTLEMATCH_SAVE_HasOpponentMac(void *keys, void *key)
{
    int i;
    int count = LIVEBATTLEMATCH_SAVE_GetCounter(keys, 0);
    u8 buf[6];

    if (count > 10) {
        count = 10;
    }

    for (i = 0; i < count; i++) {
        LIVEBATTLEMATCH_SAVE_GetOpponentMac(keys, i, buf);
        if (GF_STANDARD_CompareBytes(key, buf, 6) == 0) {
            return 1;
        }
    }
    return 0;
}

/*
 * A four-byte constant getter with no register-saving prologue; it was
 * hiding as the unlabelled follower behind LIVEBATTLEMATCH_SAVE_HasOpponentMac's EXACT* extent
 * (see docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md). Its own
 * follower, LIVEBATTLEMATCH_SAVE_Init, already carries a label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/LIVEBATTLEMATCH_SAVE_GetSize.c \
 *       --func LIVEBATTLEMATCH_SAVE_GetSize --addr 0x0200E9DC --cc 1.1p1
 */
unsigned int LIVEBATTLEMATCH_SAVE_GetSize(void)
{
    return 0x9c;
}

void LIVEBATTLEMATCH_SAVE_Init(void *record)
{
    LIVEBATTLEMATCH_SAVE_InitRecord(record);
    BSUBWAY_SAVEDATA_InitStats((u8 *)record + 0x5a);
}

/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
void *LIVEBATTLEMATCH_SAVE_GetFromSave(void *saveData)
{
    return SAVE_CONTROL_GetBlock(saveData, 0x3c);
}

/*
 * Unlabelled leaf accessor matched to give overlay call sites a matched
 * witness.  Addresses are Black-image addresses.
 */
int LIVEBATTLEMATCH_SAVE_GetStats(int stats)
{
    return stats + 0x5a;
}

int LIVEBATTLEMATCH_SAVE_GetStats2(int stats)
{
    return stats + 0x5a;
}

int LIVEBATTLEMATCH_SAVE_GetRecord(int stats)
{
    return stats;
}
