/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02007454
 * packet:   pkt_02006E40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BOX_SAVEDATA_Init, BOX_SAVEDATA_GetSize, BOX_SAVEDATA_InitHeader, BOX_SAVEDATA_GetHeader,
 *           BOX_SAVEDATA_AddPokemon, BOX_SAVEDATA_AddPokemonToBox
 *
 * symbols:
 *   sub_0200752C_File  0x020A7068  data
 *   SAVE_CONTROL_GetBlock       0x020071CC  thumb
 *   BOX_SAVEDATA_GetBoxPokemon       0x02007AF4  thumb
 *   POKE_TOOL_GetBoxValue       0x02017E88  thumb
 *   POKE_TOOL_RecoverBoxAllPP       0x020181A0  thumb
 *   func_02034714      0x02034714  arm
 *   func_02045B38      0x02045B38  arm
 *   func_02045C04      0x02045C04  arm
 *   MSGDATA_ReadUnits      0x02045F5C  arm
 *
 * alias: this is where "box_savedata.c" starts.  The header of
 * src/matched/unit_020079BC.c records the file name, recovered from the
 * string at 0x020A706C that BOX_SAVEDATA_CreateWordHolder passes to the debug allocator, and
 * says the file's boundaries are bracketed rather than located.  The front
 * one is located now: 0x02007454 is the first function of it.  What fixes it
 * is the pair 0x02007454 and 0x0200745C, the twelve bytes immediately after
 * the last function of "save_control.c".  0x0200745C returns 0x3E0, which is
 * sizeof of the 0x3DE byte box header rounded up to its four byte alignment,
 * and 0x02007464, the very next function, is the constructor that clears
 * exactly that header.  Every block file in this region opens with that
 * pair; see docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  The
 * function before them, SAVE_CONTROL_EraseOutsideSave, passes no file name at all, but the
 * one before that passes 0x020A7064, the empty string "save_control.c" uses,
 * and the first function of this file that names anything names 0x020A7068,
 * which is the empty string every assert in unit_020079BC.c, unit_02007774.c
 * and the rest of "box_savedata.c" passes.  So the seam is between 0x02007454
 * and 0x02007428 and the two halves use different assertion strings across
 * it.
 *
 * The struct is the one unit_020079BC.c already declares: a current box index
 * at +0, twenty-four 0x28 byte names at +4, twenty-four bytes at +0x3C4, a
 * flag at +0x3DC and the box count at +0x3DD.  Four details are worth
 * naming, and three of them are worth three bytes each.
 *
 *  - BOX_SAVEDATA_InitHeader seeds the twenty-four bytes at +0x3C4 with a counter that
 *    wraps at sixteen, and the reset is `adds r4, r1, #0` off a register
 *    holding zero rather than a `movs`, which is the same "derive the
 *    constant from a register that already has one" the rest of this region
 *    shows.  The counter is not a `u8`: a byte variable would carry a
 *    `lsls #24` / `lsrs #24` pair at the increment and there is none, so it
 *    is an unsigned `int` stored through a `u8` array.  Which of the two
 *    zeroes the copy in r1 is taken from is decided by which is written
 *    first, so the counter has to be cleared in the `for` initialiser
 *    alongside the index (`for (i = 0, c = 0; ...)`); clearing it in the
 *    statement before the loop swaps r3 and r4 throughout.
 *  - BOX_SAVEDATA_AddPokemonToBox copies a whole 0x88 byte entry with an inline `ldm`/`stm`
 *    loop of seventeen iterations, which is
 *    docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md: the entry has
 *    to be declared four-aligned (`u32 data[0x22]`), because a byte-aligned
 *    declaration turns the same assignment into a 0x88 iteration
 *    `ldrb`/`strb` loop.
 *  - BOX_SAVEDATA_AddPokemon walks the boxes from the current one and stops when it
 *    comes back to it, so the loop is a `do`/`while` with no guard, and the
 *    box count it reads on the way round is still live after the loop: the
 *    `cmp r1, #0x18` that follows compares the last value read inside it,
 *    not a fresh load, and the extra box it then opens is that value.  Its
 *    declaration order is load bearing for the same reason as the counter
 *    above: with the header pointer declared first it lands in r4 and the
 *    box index in r5, and the original has them the other way round.
 *  - the very next statement, the one that bumps the box count by eight,
 *    re-reads the field even though the value is sitting in r1.  Only the
 *    compound form does that; see
 *    docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub02007454Entry {
    u32 data[0x22];
};

struct Sub02007454Name {
    u8 data[0x28];
};

struct Sub02007454Header {
    u32 unk00;
    struct Sub02007454Name unk04[0x18];
    u8  unk3C4[0x18];
    u8  unk3DC;
    u8  unk3DD;
};

extern const char sub_0200752C_File[];

struct MsgBank;
struct Rec;
struct Sub020071CCCtrl;
extern void *SAVE_CONTROL_GetBlock(struct Sub020071CCCtrl *ctrl, u32 id);
typedef unsigned short u16;
struct MsgData;
struct Sub02007AC8Entry;
extern struct Sub02007AC8Entry *BOX_SAVEDATA_GetBoxPokemon(void **save, u32 box);
extern u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_RecoverBoxAllPP(void *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern void MSGDATA_ReadUnits(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);

void BOX_SAVEDATA_InitHeader(struct Sub02007454Header *h);
struct Sub02007454Header *BOX_SAVEDATA_GetHeader(void **save);
int BOX_SAVEDATA_AddPokemonToBox(void **save, u32 box, const struct Sub02007454Entry *src);

void BOX_SAVEDATA_Init(struct Sub02007454Header *h)
{
    BOX_SAVEDATA_InitHeader(h);
}

u32 BOX_SAVEDATA_GetSize(void)
{
    return sizeof(struct Sub02007454Header);
}

void BOX_SAVEDATA_InitHeader(struct Sub02007454Header *h)
{
    void *msg;
    u32 i;
    u32 c;

    for (i = 0, c = 0; i < 0x18; i++) {
        h->unk3C4[i] = c;
        c++;
        if (c >= 0x10) {
            c = 0;
        }
    }
    h->unk3DC = 0;
    msg = func_02045B38(0, 2, 9, 1);
    if (msg != 0) {
        for (i = 0; i < 0x18; i++) {
            MSGDATA_ReadUnits(msg, i + 6, (u16 *)(&h->unk04[i]), 0x14);
        }
        func_02045C04(msg);
    }
    h->unk00 = 0;
    h->unk3DD = 8;
}

struct Sub02007454Header *BOX_SAVEDATA_GetHeader(void **save)
{
    return SAVE_CONTROL_GetBlock(*save, 0);
}

int BOX_SAVEDATA_AddPokemon(void **save, const struct Sub02007454Entry *src)
{
    u32 box;
    struct Sub02007454Header *h;
    u8 n;

    h = BOX_SAVEDATA_GetHeader(save);
    box = h->unk00;

    do {
        if (BOX_SAVEDATA_AddPokemonToBox(save, box, src) != 0) {
            return 1;
        }
        box++;
        n = h->unk3DD;
        if (box >= n) {
            box = 0;
        }
    } while (box != h->unk00);
    if (n != 0x18) {
        h->unk3DD += 8;
        BOX_SAVEDATA_AddPokemonToBox(save, n, src);
        return 1;
    }
    return 0;
}

int BOX_SAVEDATA_AddPokemonToBox(void **save, u32 box, const struct Sub02007454Entry *src)
{
    struct Sub02007454Header *h = BOX_SAVEDATA_GetHeader(save);
    u32 slot;

    if (box == -1) {
        box = h->unk00;
    } else if (box >= h->unk3DD) {
        func_02034714(sub_0200752C_File, 0, sub_0200752C_File);
    }
    for (slot = 0; slot < 30; slot++) {
        struct Sub02007454Entry *base = (struct Sub02007454Entry *)BOX_SAVEDATA_GetBoxPokemon(save, box);

        if (POKE_TOOL_GetBoxValue(&base[slot], 5, 0) == 0) {
            base[slot] = *src;
            POKE_TOOL_RecoverBoxAllPP(&base[slot]);
            return 1;
        }
    }
    return 0;
}
