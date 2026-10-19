/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x020095C8
 * packet:   pkt_020095E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: WIFI_HISTORY_GetFirstFreeEntry, WIFI_HISTORY_IncrementVisitedCountryCount, WIFI_HISTORY_SetRatingLevel, WIFI_HISTORY_GetRatingLevel,
 *           WIFI_HISTORY_SetGreetingSet, WIFI_HISTORY_GetGreetingSet, WIFI_HISTORY_GetEntryField, WIFI_HISTORY_SetEntryField,
 *           WIFI_HISTORY_GetEntry, WIFI_HISTORY_GetEntries, WIFI_HISTORY_MarkCountryVisited, WIFI_HISTORY_IsCountryVisited
 *
 * alias: the rest of the save block with id 0x1D whose first half is
 * src/matched/unit_02009470.c.  This half is the twenty 0x28-byte records at
 * the front of the block, the 0xE9-bit flag array at +0x320, and the four
 * scalars at +0x344..+0x347 that sit between them.
 *
 * WIFI_HISTORY_GetEntryField and WIFI_HISTORY_SetEntryField are the getter and the setter over the record
 * fields, both dispatched through a PC-relative halfword table; see
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.  The two tables
 * are the interesting part, because they disagree.  The getter's seven entries
 * all point at real bodies, so the source has `case 0` through `case 6`.  The
 * setter's first four point at the function's exit, and those four are still
 * case labels in the source: with only `case 4`, `case 5` and `case 6` this
 * compiler abandons the table and emits a three-way `cmp` / `beq` chain, eight
 * bytes longer and a completely different function.  Four empty arms in front
 * of the real ones are what bring the table back.  See
 * docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *
 * The setter also has to reach the record through a pointer,
 * `e = &obj->unk000[i]`, while the getter's `obj->unk000[i].field` spelling
 * would do: written with the index in each arm the multiply by 0x28 is
 * recomputed inside every case instead of being hoisted in front of the
 * switch, and seventy bytes move.
 *
 * The record's byte at +0x26 is three fields, and the getter is the only place
 * that says so: `lsls #0x1D` / `lsrs #0x1D` for the low three bits, then
 * `lsls #0x1C` / `lsrs #0x1F` and `lsls #0x1B` / `lsrs #0x1F` for the two bits
 * above them.  The setter writes the three-bit field as one masked assignment
 * and the two single bits as `orrs #8` / `bics #8` and `orrs #0x10` /
 * `bics #0x10`, which is an `if (value) f = 1; else f = 0;` on a one-bit
 * bitfield and not an assignment of the value itself.
 *
 * The index bound is checked unsigned in the getter (`blo`) and signed in the
 * setter and in WIFI_HISTORY_GetEntry (`bge`, `blt`), so the three functions do not
 * agree about the type of their index and the source says so.
 *
 * WIFI_HISTORY_MarkCountryVisited seeds its result from a literal pool word holding zero rather
 * than from a `movs`, which costs four bytes and is what the compiler does
 * here for a value initialised before a conditional; the `bne` that follows
 * reads the flags of the `adds r5, r1, #0` that moved the argument, so there
 * is no `cmp` for the first test at all.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020095C8.c \
 *       --addr 0x020095C8 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub02009470Ent {
    u8  unk00[0x20];
    u16 unk20;
    u16 unk22;
    u8  unk24;
    u8  unk25;
    u8  unk26_0 : 3;
    u8  unk26_3 : 1;
    u8  unk26_4 : 1;
    u8  unk26_5 : 3;
    u8  unk27;
};

struct Sub02009470Obj {
    struct Sub02009470Ent unk000[20];
    u8 unk320[0x1D];
    u8 unk33D[7];
    u8 unk344;
    u8 unk345;
    u8 unk346;
    u8 unk347;
    u8 unk348[0xFF0];
};

u32 WIFI_HISTORY_IsCountryVisited(const struct Sub02009470Obj *obj, u32 n);

u8 WIFI_HISTORY_GetFirstFreeEntry(const struct Sub02009470Obj *obj)
{
    int i;

    for (i = 0; i < 20; i++) {
        if (obj->unk000[i].unk26_4 == 0) {
            break;
        }
    }
    return i;
}

void WIFI_HISTORY_IncrementVisitedCountryCount(struct Sub02009470Obj *obj)
{
    if (obj->unk345 < 0xE9) {
        obj->unk345++;
    }
}

void WIFI_HISTORY_SetRatingLevel(struct Sub02009470Obj *obj, int value)
{
    if (value < 5) {
        obj->unk347 = value;
    }
}

u8 WIFI_HISTORY_GetRatingLevel(const struct Sub02009470Obj *obj)
{
    return obj->unk347;
}

void WIFI_HISTORY_SetGreetingSet(struct Sub02009470Obj *obj, int value)
{
    if (value < 9) {
        obj->unk346 = value;
    }
}

u8 WIFI_HISTORY_GetGreetingSet(const struct Sub02009470Obj *obj)
{
    return obj->unk346;
}

u32 WIFI_HISTORY_GetEntryField(const struct Sub02009470Obj *obj, u32 i, u32 field)
{
    const struct Sub02009470Ent *e;

    if (i >= 20) {
        return 0;
    }
    e = &obj->unk000[i];
    switch (field) {
    case 0:
        return e->unk20;
    case 1:
        return e->unk22;
    case 2:
        return e->unk24;
    case 3:
        return e->unk25;
    case 4:
        return e->unk26_0;
    case 5:
        return e->unk26_3;
    case 6:
        return e->unk26_4;
    }
    return 0;
}

void WIFI_HISTORY_SetEntryField(struct Sub02009470Obj *obj, int i, u32 field, u32 value)
{
    struct Sub02009470Ent *e;

    if (i >= 20) {
        return;
    }
    e = &obj->unk000[i];
    switch (field) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        if (value < 5) {
            e->unk26_0 = value;
        }
        break;
    case 5:
        if (value) {
            e->unk26_3 = 1;
        } else {
            e->unk26_3 = 0;
        }
        break;
    case 6:
        if (value) {
            e->unk26_4 = 1;
        } else {
            e->unk26_4 = 0;
        }
        break;
    }
}

struct Sub02009470Ent *WIFI_HISTORY_GetEntry(struct Sub02009470Obj *obj, int i)
{
    if (i >= 20) {
        return 0;
    }
    return &obj->unk000[i];
}

void WIFI_HISTORY_GetEntries(void)
{
}

u32 WIFI_HISTORY_MarkCountryVisited(struct Sub02009470Obj *obj, u32 n)
{
    u32 ret = 0;

    if (n == 0) {
        return ret;
    }
    if (n < 0xE9) {
        if (WIFI_HISTORY_IsCountryVisited(obj, n) == 0) {
            ret = 1;
        }
        obj->unk320[n >> 3] |= (u8)(1 << (u8)(n & 7));
    }
    return ret;
}

u32 WIFI_HISTORY_IsCountryVisited(const struct Sub02009470Obj *obj, u32 n)
{
    if (n < 0xE9) {
        u8 bit = (obj->unk320[n >> 3] >> (u8)(n & 7)) & 1;

        if (bit != 0) {
            return 1;
        }
    }
    return 0;
}
