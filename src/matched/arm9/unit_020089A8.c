/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x020089A8
 * packet:   pkt_02008A34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: TRCARD_SIGN_GetSize, TRCARD_SIGN_Init, TRCARD_SIGN_GetFromSave, TRCARD_SIGN_GetBitmap,
 *           TRCARD_SIGN_HasAnySignature, TRCARD_SIGN_GetSeenBefore, TRCARD_SIGN_SetSeenBefore, TRCARD_SIGN_GetColor,
 *           TRCARD_SIGN_SetColor, TRCARD_SIGN_SetStyle, TRCARD_SIGN_GetStyle, TRCARD_SIGN_SetLastBadgeTime,
 *           TRCARD_SIGN_GetLastBadgeTime
 *
 * symbols:
 *   MI_CpuFill8   0x02082BCC  arm
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *
 * alias: the save block with id 0x21, 0x658 bytes, and its accessors.  The
 * original file is closed the same way unit_02008828.c is: it opens with the
 * four bytes that return the block size (0x658, which is what TRCARD_SIGN_Init
 * clears) and ends where the next such function returns 0x5C, at 0x02008AEC.
 * This file stops short of that, at 0x02008A54, because of the near miss
 * described below; the rest of the file is src/matched/unit_02008A7C.c and
 * the two should be merged the day 0x02008A54 closes.
 *
 * NEAR MISS, 0x02008A54, 40 bytes, 17 concrete bytes wrong, skipped.  It
 * assembles a little endian word out of the four bytes of record `i`.  The
 * shape is settled: the size is right, the four loads come out in the
 * original's order (unk01, unk00, unk02, unk03), the pool constant is the
 * original's 0x605, and the seventeen instructions are the same seventeen.
 * What differs is register allocation.  The original computes the record
 * pointer into `r3` and accumulates the result in `r0` from the first load
 * onwards; every source shape tried computes the pointer into `r0`,
 * accumulates in `r3`, and hoists the last `ldrb` two slots earlier so that
 * `r0` is free for the result at the end.  A generated sweep of 84 source
 * shapes (all 24 term permutations crossed with three statement groupings,
 * plus accumulator type, index type and constness) is flat at 17 wrong bytes
 * and never at 18 or below except for shapes that also lose the load order.
 * Nothing in the source appears to reach the allocator here.
 *
 * Layout, read off the accessors:
 *
 *   +0x000  u32[384]  a word array summed whole by TRCARD_SIGN_HasAnySignature
 *   +0x600  u16       get/set by TRCARD_SIGN_GetColor and TRCARD_SIGN_SetColor
 *   +0x602  u8        get by TRCARD_SIGN_GetSeenBefore, only ever set to 1
 *   +0x603  u8        get/set by TRCARD_SIGN_GetStyle and TRCARD_SIGN_SetStyle
 *   +0x604  8 x 4     a table of four-byte records, three bytes of which
 *                     TRCARD_SIGN_SetBadgeDate writes and TRCARD_SIGN_GetBadgeDate reads back as one
 *                     little endian word
 *   +0x624  u32       the low half of an RTC second count
 *   +0x628  u32       ... and its high half
 *   +0x638  u16[]     a parallel table TRCARD_SIGN_SetBadgeDate stamps with 0xF0
 *
 * Three things in here are worth naming:
 *
 *  - TRCARD_SIGN_GetLastBadgeTime returns the pair at +0x624 and +0x628 as one `u64`.  The
 *    field pair is not a `u64` in the object, because 0x624 is not eight
 *    aligned, but the return value is: the compiler loads the low half into a
 *    scratch register because `r0` is still the object pointer it needs for
 *    the second load, and only then moves it into place.  That `adds r0, r2,
 *    #0` at the end is what a 64 bit return of two separately declared words
 *    looks like.
 *  - TRCARD_SIGN_GetBadgeDate assembles a word out of four bytes and the pool constant it
 *    picks is 0x605, not 0x604: the second byte is the one it loads first, and
 *    the other three offsets are derived from it with subs/adds.  Reading the
 *    pool word as the base of the array gets the record boundary wrong by one.
 *  - TRCARD_SIGN_HasAnySignature compares its counter with `blt`, so the loop variable is a
 *    signed `int` even though what it walks is an array of `u32`.  The bound
 *    384 is materialised as `movs r1, #6` / `lsls r1, r1, #6` rather than
 *    loaded from a pool.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020089A8.c \
 *       --addr 0x020089A8 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned long long u64;

extern void MI_CpuFill8(void *dest, u8 data, u32 size);
struct Sub020071CCCtrl;
extern void *SAVE_CONTROL_GetBlock(struct Sub020071CCCtrl *ctrl, u32 id);

#define BLOCK_ID 0x21

struct Sub020089A8Rec {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
};

struct Sub020089A8Obj {
    u32 unk000[384];
    u16 unk600;
    u8  unk602;
    u8  unk603;
    struct Sub020089A8Rec unk604[8];
    union {
        u64 whole;
        struct {
            u32 lo;
            u32 hi;
        } half;
    } unk624;
    u8  unk62C[0xC];
    u16 unk638[16];
};

void TRCARD_SIGN_SetLastBadgeTime(struct Sub020089A8Obj *obj, u32 lo, u32 hi);

u32 TRCARD_SIGN_GetSize(void)
{
    return sizeof(struct Sub020089A8Obj);
}

void TRCARD_SIGN_Init(struct Sub020089A8Obj *obj)
{
    MI_CpuFill8(obj, 0, sizeof(struct Sub020089A8Obj));
}

struct Sub020089A8Obj *TRCARD_SIGN_GetFromSave(void *sys)
{
    return SAVE_CONTROL_GetBlock(sys, BLOCK_ID);
}

void TRCARD_SIGN_GetBitmap(void)
{
}

/* Is any word of the 0x600-byte array non zero. */
int TRCARD_SIGN_HasAnySignature(const struct Sub020089A8Obj *obj)
{
    u32 sum;
    int i;

    sum = 0;
    for (i = 0; i < 384; i++) {
        sum += obj->unk000[i];
    }
    if (sum == 0) {
        return 0;
    }
    return 1;
}

u8 TRCARD_SIGN_GetSeenBefore(const struct Sub020089A8Obj *obj)
{
    return obj->unk602;
}

struct Sub020089A8Obj *TRCARD_SIGN_SetSeenBefore(struct Sub020089A8Obj *obj)
{
    obj->unk602 = 1;
    return obj;
}

u16 TRCARD_SIGN_GetColor(const struct Sub020089A8Obj *obj)
{
    return obj->unk600;
}

void TRCARD_SIGN_SetColor(struct Sub020089A8Obj *obj, u16 value)
{
    obj->unk600 = value;
}

void TRCARD_SIGN_SetStyle(struct Sub020089A8Obj *obj, u8 value)
{
    obj->unk603 = value;
}

u8 TRCARD_SIGN_GetStyle(const struct Sub020089A8Obj *obj)
{
    return obj->unk603;
}

void TRCARD_SIGN_SetLastBadgeTime(struct Sub020089A8Obj *obj, u32 lo, u32 hi)
{
    obj->unk624.half.lo = lo;
    obj->unk624.half.hi = hi;
}

u64 TRCARD_SIGN_GetLastBadgeTime(const struct Sub020089A8Obj *obj)
{
    return obj->unk624.whole;
}
