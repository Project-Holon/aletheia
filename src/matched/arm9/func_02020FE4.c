/*
 * unit:     no
 * address:  0x02020FE4
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: FILE_UTIL_GetItemParam
 *
 * symbols:
 *   FILE_UTIL_LoadItemRecord  0x02020F34  thumb
 *   FILE_UTIL_GetItemRecordParam  0x02021014  thumb
 *   func_020307B0  0x020307B0  arm
 *
 * One-shot wrapper over the record getter of src/matched/unit_02021014.c:
 * build a temporary record for the id (with bit 15 forced on and the rest of
 * the id masked to fifteen bits), read one property out of it, free it, and
 * answer the property.
 *
 * 0x8000 costs no second pool word: the compiler keeps 0x7FFF in r3 for the
 * mask and derives the set bit from it with `adds r2, r3, #1`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FILE_UTIL_GetItemParam.c \
 *       --func FILE_UTIL_GetItemParam --addr 0x02020FE4 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FILE_UTIL_LoadItemRecord(u32 item, u32 which, u32 heap);
struct Rec;
extern u32 FILE_UTIL_GetItemRecordParam(struct Rec *p, u32 sel);
extern u32 func_020307B0(void *p);

u32 FILE_UTIL_GetItemParam(void *a, u32 sel, u32 id)
{
    void *rec;
    u32   v;

    rec = FILE_UTIL_LoadItemRecord((u32)a, 0, (u16)((id & 0x7FFF) | 0x8000));
    v = FILE_UTIL_GetItemRecordParam(rec, sel);
    func_020307B0(rec);
    return v;
}
