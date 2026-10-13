/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/003_0200CA1C.s.
 *
 * unit:     yes
 * address:  0x0200D414
 * packet:   pkt_0200C9F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MOVE_POKEMON_SAVE_GetSize, MOVE_POKEMON_SAVE_GetBlock, MOVE_POKEMON_SAVE_Init, MOVE_POKEMON_SAVE_RollStartLocation,
 *           MOVE_POKEMON_SAVE_GetStartLocation, MOVE_POKEMON_SAVE_SetCommonArea, MOVE_POKEMON_SAVE_GetEntryState, MOVE_POKEMON_SAVE_SetEntryState,
 *           MOVE_POKEMON_SAVE_GetEntryLocation, MOVE_POKEMON_SAVE_SetEntryLocation, MOVE_POKEMON_SAVE_IsEntryActive, MOVE_POKEMON_SAVE_InitEntry,
 *           MOVE_POKEMON_SAVE_GetEntry, MOVE_POKEMON_SAVE_GetEntryField, MOVE_POKEMON_SAVE_SetEntryField, MOVE_POKEMON_SAVE_SetCooldown,
 *           MOVE_POKEMON_SAVE_TickCooldown, MOVE_POKEMON_SAVE_IsCooldownDone
 *
 * 392 bytes, 0x0200D414..0x0200D59C, 18 functions, sixteen of which carry no
 * label in the generated listing: everything here but the constructor and
 * MOVE_POKEMON_SAVE_RollStartLocation is a leaf that saves nothing.
 *
 * The object is the save block with id 0x38: MOVE_POKEMON_SAVE_GetSize returns 0x34,
 * MOVE_POKEMON_SAVE_GetBlock is the whole of the lookup `func_020071CC(sys, 0x38)`, and
 * MOVE_POKEMON_SAVE_Init clears exactly 0x34 bytes, which is the block-file opening
 * this region keeps producing.  The record is a pair of 0x14-byte entries at
 * +0x04 with four byte fields and two counters behind them.
 *
 * Three things cost time here.
 *
 *  - the two dispatchers at 0x0200D4B8 and 0x0200D50C emit their arms in the
 *    order 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, which is the order the source wrote
 *    them in and not the numeric order of the labels; the `.hword` table is
 *    what says so, since the entry for 10 sits between the entries for 3 and
 *    4 in address order.  See
 *    docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *  - both tables have an eleventh entry, for 0, pointing at the function's
 *    exit.  That entry is before every real arm, so it is an empty `case 0:`
 *    the source wrote rather than a gap: without it the labels are 1..10 and
 *    this front end emits a compare chain instead of a table.  See
 *    docs/idioms/empty-switch-arms-are-what-make-the-table.md.
 *  - MOVE_POKEMON_SAVE_TickCooldown reads +0x31 three times and stores it once with the
 *    address recomputed before each access, and nothing that leaves the field
 *    ordinary reproduces that: every spelling folds the three reads into one.
 *    Declaring it `volatile` keeps them, and it costs nothing in
 *    MOVE_POKEMON_SAVE_SetCooldown or MOVE_POKEMON_SAVE_IsCooldownDone, which touch it once each.  The same
 *    reading as `volatile u16 unkE0` in src/matched/unit_0200C0E8.c.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern u32 func_02005728(u32 range);

struct GdsEnt {
    u16 unk00;
    u8  unk02;
    u8  unk03;
    u32 unk04;
    u32 unk08;
    u16 unk0C;
    u16 unk0E;
    u8  unk10;
    u8  unk11;
    u8  unk12;
    u8  unk13;
};

struct Blk38 {
    u16 unk00;
    u16 unk02;
    struct GdsEnt unk04[2];
    u8  unk2C[2];
    u8  unk2E[2];
    u8  unk30;
    volatile u8 unk31;
    u8  unk32[2];
};

u32 MOVE_POKEMON_SAVE_GetSize(void)
{
    return sizeof(struct Blk38);
}

void *MOVE_POKEMON_SAVE_GetBlock(void *sys)
{
    return func_020071CC(sys, 0x38);
}

void MOVE_POKEMON_SAVE_Init(struct Blk38 *p)
{
    MI_CpuFill8(p, 0, sizeof(struct Blk38));
    p->unk30 = 0;
    p->unk31 = 0;
}

void MOVE_POKEMON_SAVE_RollStartLocation(void *sys)
{
    struct Blk38 *p = MOVE_POKEMON_SAVE_GetBlock(sys);

    p->unk30 = func_02005728(0x11);
}

u8 MOVE_POKEMON_SAVE_GetStartLocation(struct Blk38 *p)
{
    return p->unk30;
}

void MOVE_POKEMON_SAVE_SetCommonArea(struct Blk38 *p, u16 v)
{
    if (p->unk00 != v) {
        p->unk02 = p->unk00;
        p->unk00 = v;
    }
}

u8 MOVE_POKEMON_SAVE_GetEntryState(struct Blk38 *p, u32 i)
{
    return p->unk2E[i];
}

void MOVE_POKEMON_SAVE_SetEntryState(struct Blk38 *p, u32 i, u32 v)
{
    p->unk2E[i] = v;
}

u8 MOVE_POKEMON_SAVE_GetEntryLocation(struct Blk38 *p, u32 i)
{
    return p->unk2C[i];
}

void MOVE_POKEMON_SAVE_SetEntryLocation(struct Blk38 *p, u32 i, u8 v)
{
    p->unk2C[i] = v;
}

u8 MOVE_POKEMON_SAVE_IsEntryActive(struct Blk38 *p, u32 i)
{
    return p->unk04[i].unk12;
}

void MOVE_POKEMON_SAVE_InitEntry(struct GdsEnt *e)
{
    MI_CpuFill8(e, 0, sizeof(struct GdsEnt));
    e->unk00 = 0xFFFF;
}

struct GdsEnt *MOVE_POKEMON_SAVE_GetEntry(struct Blk38 *p, u32 i)
{
    return &p->unk04[i];
}

u32 MOVE_POKEMON_SAVE_GetEntryField(const struct GdsEnt *e, u32 i)
{
    switch (i) {
    case 0:
        break;
    case 1:
        return e->unk00;
    case 2:
        return e->unk04;
    case 3:
        return e->unk08;
    case 10:
        return e->unk02;
    case 4:
        return e->unk0C;
    case 5:
        return e->unk0E;
    case 6:
        return e->unk10;
    case 7:
        return e->unk11;
    case 8:
        return e->unk12;
    case 9:
        return e->unk13;
    }
    return 0;
}

void MOVE_POKEMON_SAVE_SetEntryField(struct GdsEnt *e, u32 i, u32 v)
{
    switch (i) {
    case 0:
        break;
    case 1:
        e->unk00 = v;
        break;
    case 2:
        e->unk04 = v;
        break;
    case 3:
        e->unk08 = v;
        break;
    case 10:
        e->unk02 = v;
        break;
    case 4:
        e->unk0C = v;
        break;
    case 5:
        e->unk0E = v;
        break;
    case 6:
        e->unk10 = v;
        break;
    case 7:
        e->unk11 = v;
        break;
    case 8:
        e->unk12 = v;
        break;
    case 9:
        e->unk13 = v;
        break;
    }
}

void MOVE_POKEMON_SAVE_SetCooldown(struct Blk38 *p, u8 v)
{
    p->unk31 = v;
}

u32 MOVE_POKEMON_SAVE_TickCooldown(struct Blk38 *p)
{
    if (p->unk31 != 0) {
        p->unk31 = p->unk31 - 1;
        if (p->unk31 == 0) {
            return 1;
        }
    }
    return 0;
}

u32 MOVE_POKEMON_SAVE_IsCooldownDone(struct Blk38 *p)
{
    if (p->unk31 == 0) {
        return 1;
    }
    return 0;
}
