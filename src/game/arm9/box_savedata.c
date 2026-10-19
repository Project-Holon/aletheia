/*
 * file:     box_savedata.c
 * unit:     yes
 * function: BOX_SAVEDATA_Init, BOX_SAVEDATA_GetSize, BOX_SAVEDATA_InitHeader, BOX_SAVEDATA_GetHeader, BOX_SAVEDATA_AddPokemon, BOX_SAVEDATA_AddPokemonToBox, BOX_SAVEDATA_SetPokemon, BOX_SAVEDATA_SwapPokemon, BOX_SAVEDATA_ClearPokemon, BOX_SAVEDATA_GetCurrentBox, BOX_SAVEDATA_GetUsableBoxCount, BOX_SAVEDATA_UnlockBoxes, BOX_SAVEDATA_FindFreeSlot, BOX_SAVEDATA_CountFreeSlots, BOX_SAVEDATA_CountFreeSlotsInBox, BOX_SAVEDATA_SetCurrentBox, BOX_SAVEDATA_GetWallpaper, BOX_SAVEDATA_SetWallpaper, BOX_SAVEDATA_GetBoxName, BOX_SAVEDATA_SetBoxName, BOX_SAVEDATA_CountPokemonInBox, BOX_SAVEDATA_CountNonEggPokemonInBox, BOX_SAVEDATA_CountPokemon, BOX_SAVEDATA_CountNonEggPokemon, BOX_SAVEDATA_GetPokemonValue, BOX_SAVEDATA_GetPokemon, BOX_SAVEDATA_SetFlags, BOX_SAVEDATA_CheckFlags, BOX_SAVEDATA_GetBoxPageSize, BOX_SAVEDATA_CreateWordHolder, BOX_SAVEDATA_Delete, BOX_SAVEDATA_ClearBoxPage, BOX_SAVEDATA_GetBoxDataSize, BOX_SAVEDATA_GetBoxPokemon
 * address:  0x02007454
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from save_control.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   SAVEDATA_PanicFail   0x02034714  arm
 *   GFL_HEAP_Free       0x020307B0  arm
 *   _BoxEmptyString  0x020A7068  data
 *   SAVE_CONTROL_GetBlock       0x020071CC  thumb
 *   BOX_SAVEDATA_GetBoxPokemon       0x02007AF4  thumb
 *   POKE_TOOL_GetBoxValue       0x02017E88  thumb
 *   POKE_TOOL_RecoverBoxAllPP       0x020181A0  thumb
 *   MSGDATA_CreateFromArchive      0x02045B38  arm
 *   MSGDATA_Delete      0x02045C04  arm
 *   MSGDATA_ReadUnits      0x02045F5C  arm
 *   BOX_SAVEDATA_GetHeader       0x020074CC  thumb
 *   POKE_TOOL_ClearBoxParam  0x02017550  thumb
 *   STRBUF_SetString      0x02045924  arm
 *   STRBUF_ToChars      0x02045A38  arm
 *   _BoxSavedataFileName  0x020A706C  data
 */
#include "btl_setup_types.h"
#include "save_control_shared_types.h"
#include "box_savedata_shared_types.h"

struct MsgData;

struct Strbuf;

/* PC boxes. */
#define MAX_BOXES 0x18

#define BOX_CAPACITY 30

#define BOX_CURRENT (-1) /* box argument meaning the current box */

#define BOX_EXPAND_STEP 8

/* One stored Pokemon, 0x88 bytes (4-aligned so that a copy is an ldm/stm loop). */
struct BoxPokemon {
    u32 personality;
    u16 flags;
    u16 checksum;
    u8 blocks[0x80];
};

struct BoxName {
    u16 chars[0x14];
};

/* Box block header (block id 0), 0x3DE bytes; the 30 Pokemon of each box are blocks 1..24. */
struct BoxSaveHeader {
    u32 currentBox;
    struct BoxName names[MAX_BOXES];
    u8 wallpaper[MAX_BOXES];
    u8 flags;
    u8 usableBoxCount; /* 8, 16 or 24 */
};

#define MON_DATA_IS_EGG 0x4C

#define MON_DATA_EXISTS 0xA9 /* nonzero when the slot holds a Pokemon */

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);

extern u32 GFL_HEAP_Free(void *memory);

extern void SAVEDATA_PanicFail(const char *file, u32 line, const char *message);

extern u32 POKE_TOOL_GetBoxValue(struct BoxPokemon *mon, u32 field, u32 arg);

extern void POKE_TOOL_ClearBoxParam(struct BoxPokemon *mon);

extern void POKE_TOOL_RecoverBoxAllPP(struct BoxPokemon *mon);

extern struct MsgData *MSGDATA_CreateFromArchive(u32 resident, u32 archiveId, u32 fileId, u32 heapId);

extern void MSGDATA_Delete(struct MsgData *msg);

extern void MSGDATA_ReadUnits(struct MsgData *msg, u32 index, u16 *dest, u32 maxLen);

extern void STRBUF_SetString(struct Strbuf *dest, const u16 *src);

extern void STRBUF_ToChars(const struct Strbuf *src, u16 *dest, u32 length);

extern const char _BoxEmptyString[];             /* assert text of box_savedata.c, empty */

extern const char _BoxSavedataFileName[];

void BOX_SAVEDATA_InitHeader(struct BoxSaveHeader *header);

struct BoxSaveHeader *BOX_SAVEDATA_GetHeader(struct GameData *gameData);

int BOX_SAVEDATA_AddPokemonToBox(struct GameData *gameData, u32 box, const struct BoxPokemon *mon);

void BOX_SAVEDATA_Init(struct BoxSaveHeader *header);

struct BoxPokemon *BOX_SAVEDATA_GetBoxPokemon(struct GameData *gameData, u32 box);

int BOX_SAVEDATA_CountPokemonInBox(struct GameData *gameData, u32 box);

int BOX_SAVEDATA_CountNonEggPokemonInBox(struct GameData *gameData, u32 box);

void *SAVE_CONTROL_GetBlock(struct SaveControl *saveControl, u32 blockId);

/*
 * "box_savedata.c" starts here.  It starts at 0x02007454 and not at the
 * constructor: the pair 0x02007454 and 0x0200745C (the twelve bytes right
 * after the last function of "save_control.c") is the block file opening
 * idiom.  0x0200745C returns the header size, 0x3E0, and 0x02007464, the next
 * function, is the constructor that clears exactly that header.  The function
 * before them passes the empty string 0x020A7064 as its assertion message;
 * the first function of this file that names anything names 0x020A7068, the
 * empty string every assert of "box_savedata.c" passes.  So the seam is
 * between 0x02007428 and 0x02007454 and the two halves use different
 * assertion strings across it.
 *
 * The box functions take the GameData object: its first word is the
 * SaveControl pointer (BOX_SAVEDATA_GetHeader reads it).
 *
 * Details of the bytes:
 *
 *  - BOX_SAVEDATA_InitHeader seeds the 24 wallpaper bytes with a counter that wraps at
 *    sixteen, and the reset is `adds r4, r1, #0` off a register holding zero
 *    rather than a `movs`.  The counter is not a `u8`: a byte variable would
 *    carry a `lsls #24` / `lsrs #24` pair at the increment and there is none,
 *    so it is an unsigned `int` stored through a `u8` array.  The counter has
 *    to be cleared in the `for` initialiser alongside the index.
 *  - BOX_SAVEDATA_AddPokemonToBox copies a whole 0x88 byte Pokemon with an inline `ldm`/`stm`
 *    loop of seventeen iterations
 *    (docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md); the struct
 *    has to be four-aligned, because a byte-aligned declaration turns the
 *    same assignment into a 0x88 iteration `ldrb`/`strb` loop.
 *  - BOX_SAVEDATA_AddPokemon walks the boxes from the current one and stops when it
 *    comes back to it, so the loop is a `do`/`while` with no guard, and the
 *    box count it reads on the way round is still live after the loop: the
 *    `cmp r1, #0x18` that follows compares the last value read inside it.
 *    Its declaration order is load bearing for the same reason: with the
 *    header pointer declared first it lands in r4 and the box index in r5,
 *    and the original has them the other way round.
 *  - the statement that bumps the box count by eight re-reads the field even
 *    though the value is in r1.  Only the compound form does that; see
 *    docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md.
 */
void BOX_SAVEDATA_Init(struct BoxSaveHeader *header)
{
    BOX_SAVEDATA_InitHeader(header);
}

u32 BOX_SAVEDATA_GetSize(void)
{
    return sizeof(struct BoxSaveHeader);
}

/* Empty the box block: wallpapers 0..15 repeating, default box names from the message archive. */
void BOX_SAVEDATA_InitHeader(struct BoxSaveHeader *header)
{
    struct MsgData *boxNames;
    u32 box;
    u32 wallpaper;

    for (box = 0, wallpaper = 0; box < MAX_BOXES; box++) {
        header->wallpaper[box] = wallpaper;
        wallpaper++;
        if (wallpaper >= 0x10) {
            wallpaper = 0;
        }
    }
    header->flags = 0;
    boxNames = MSGDATA_CreateFromArchive(0, 2, 9, 1);
    if (boxNames != 0) {
        for (box = 0; box < MAX_BOXES; box++) {
            MSGDATA_ReadUnits(boxNames, box + 6, header->names[box].chars, 0x14);
        }
        MSGDATA_Delete(boxNames);
    }
    header->currentBox = 0;
    header->usableBoxCount = 8;
}

struct BoxSaveHeader *BOX_SAVEDATA_GetHeader(struct GameData *gameData)
{
    return SAVE_CONTROL_GetBlock(gameData->saveControl, 0);
}

/* Put a Pokemon in the first free slot, starting at the current box; unlock 8 more boxes when full. */
int BOX_SAVEDATA_AddPokemon(struct GameData *gameData, const struct BoxPokemon *mon)
{
    u32 box;
    struct BoxSaveHeader *header;
    u8 usableBoxCount;

    header = BOX_SAVEDATA_GetHeader(gameData);
    box = header->currentBox;

    do {
        if (BOX_SAVEDATA_AddPokemonToBox(gameData, box, mon) != 0) {
            return 1;
        }
        box++;
        usableBoxCount = header->usableBoxCount;
        if (box >= usableBoxCount) {
            box = 0;
        }
    } while (box != header->currentBox);
    if (usableBoxCount != MAX_BOXES) {
        header->usableBoxCount += BOX_EXPAND_STEP;
        BOX_SAVEDATA_AddPokemonToBox(gameData, usableBoxCount, mon);
        return 1;
    }
    return 0;
}

/* Put a Pokemon in the first free slot of one box (BOX_CURRENT for the current box). */
int BOX_SAVEDATA_AddPokemonToBox(struct GameData *gameData, u32 box, const struct BoxPokemon *mon)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);
    u32 slot;

    if (box == BOX_CURRENT) {
        box = header->currentBox;
    } else if (box >= header->usableBoxCount) {
        SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
    }
    for (slot = 0; slot < BOX_CAPACITY; slot++) {
        struct BoxPokemon *boxMons = BOX_SAVEDATA_GetBoxPokemon(gameData, box);

        if (POKE_TOOL_GetBoxValue(&boxMons[slot], MON_DATA_SPECIES, 0) == 0) {
            boxMons[slot] = *mon;
            POKE_TOOL_RecoverBoxAllPP(&boxMons[slot]);
            return 1;
        }
    }
    return 0;
}

/*
 * Writing one box slot and swapping two of them.  Both reach the slot array
 * through BOX_SAVEDATA_GetBoxPokemon and copy a whole 0x88 byte Pokemon with the inline
 * eight byte ldm/stm loop (0x11 iterations of two words).
 *
 * BOX_SAVEDATA_SetPokemon bounds the box index against the header byte at 0x3DD rather
 * than against the constant 0x18 the rest of the file uses, and that byte is
 * past every Thumb immediate, so it arrives as a pool word and a register
 * offset ldrb.  The failure arm passes 0x020A7068 twice to SAVEDATA_PanicFail,
 * the same empty string and the same three argument assert shape as
 * BOX_SAVEDATA_CountFreeSlotsInBox.
 *
 * BOX_SAVEDATA_SwapPokemon is the three assignment swap through a 0x88 byte stack
 * temporary, and its fifth argument arrives on the stack: `ldr r1, [sp,
 * #0xa0]` is 0x88 of locals plus the six saved registers, not a local.
 */
int BOX_SAVEDATA_SetPokemon(struct GameData *gameData, u32 box, u32 slot, const struct BoxPokemon *mon)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    if (box < header->usableBoxCount && slot < BOX_CAPACITY) {
        struct BoxPokemon *boxMons = BOX_SAVEDATA_GetBoxPokemon(gameData, box);

        boxMons[slot] = *mon;
        POKE_TOOL_RecoverBoxAllPP(&boxMons[slot]);
        return 1;
    }
    SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
    return 0;
}

void BOX_SAVEDATA_SwapPokemon(struct GameData *gameData, u32 box1, u32 slot1, u32 box2, u32 slot2)
{
    struct BoxPokemon temp;
    struct BoxPokemon *boxMons1 = BOX_SAVEDATA_GetBoxPokemon(gameData, box1);
    struct BoxPokemon *boxMons2 = BOX_SAVEDATA_GetBoxPokemon(gameData, box2);

    temp = boxMons1[slot1];
    boxMons1[slot1] = boxMons2[slot2];
    boxMons2[slot2] = temp;
}

/*
 * The box accessors: BOX_SAVEDATA_GetHeader turns the GameData into the 0x3DE byte box
 * header, and BOX_SAVEDATA_GetBoxPokemon turns a box index into that box's array of thirty
 * 0x88 byte Pokemon.
 *
 * The header's usableBoxCount sits past every Thumb immediate, so it arrives
 * as a pool word and a register offset `ldrb`, and BOX_SAVEDATA_UnlockBoxes loads that
 * same pool word twice, once for the read-modify-write and once for the value
 * it returns.  The slot index is scaled by 0x88, which is not a power of two,
 * so it is a real `muls` with the constant materialised by `movs r1, #0x88`.
 */
void BOX_SAVEDATA_ClearPokemon(struct GameData *gameData, u32 box, u32 slot)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    if (slot < BOX_CAPACITY && box < MAX_BOXES) {
        POKE_TOOL_ClearBoxParam(&BOX_SAVEDATA_GetBoxPokemon(gameData, box)[slot]);
    }
}

u32 BOX_SAVEDATA_GetCurrentBox(struct GameData *gameData)
{
    return BOX_SAVEDATA_GetHeader(gameData)->currentBox;
}

u8 BOX_SAVEDATA_GetUsableBoxCount(struct GameData *gameData)
{
    return BOX_SAVEDATA_GetHeader(gameData)->usableBoxCount;
}

/* Unlock 8 more boxes unless all are usable; returns the new count. */
u8 BOX_SAVEDATA_UnlockBoxes(struct GameData *gameData)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (header->usableBoxCount != MAX_BOXES) {
        header->usableBoxCount += BOX_EXPAND_STEP;
    }
    return header->usableBoxCount;
}

/*
 * Given a box and a slot by reference, find the next free slot at or after
 * it, wrapping round the usable boxes, and write the answer back through the
 * two pointers; when every usable box is full, unlock 8 more boxes and answer
 * with the first slot of the first new box.  The field id MON_DATA_EXISTS
 * asked of an entry is the "is this entry empty" test, the same call the
 * counting functions use.
 *
 * Three things the shape says.  The box and slot are read out of the two
 * pointers once, before the outer loop, and are carried in registers: the
 * back edge lands on the BOX_SAVEDATA_GetBoxPokemon call and not on the loads, so a source
 * that re-read `*pBox` each time round would be a different function.  The
 * wrap comparison is signed (`blt`), so the index is an int even though the
 * bound is the unsigned byte in the header.  And that byte is loaded once for
 * the whole tail: the compiler keeps it live across the loop exit and uses
 * the same register for the `cmp #0x18` and for the value written back, so
 * only the increment reloads it.
 *
 * The four parameters and the header pointer are all spilled to the stack at
 * sp+0..sp+0xC.  That is register pressure with r4..r7 carrying the box, the
 * slot, the box array and the constant 0x88, not five pointers in the source.
 */
int BOX_SAVEDATA_FindFreeSlot(struct GameData *gameData, int *pBox, int *pSlot)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);
    int box;
    int slot;

    if (*pBox == -1) {
        *pBox = header->currentBox;
    }
    box = *pBox;
    slot = *pSlot;
    while (1) {
        struct BoxPokemon *boxMons = BOX_SAVEDATA_GetBoxPokemon(gameData, box);

        while (slot < BOX_CAPACITY) {
            if (POKE_TOOL_GetBoxValue(&boxMons[slot], MON_DATA_EXISTS, 0) == 0) {
                *pBox = box;
                *pSlot = slot;
                return 1;
            }
            slot++;
        }
        box++;
        if (box >= header->usableBoxCount) {
            box = 0;
        }
        if (box == *pBox) {
            break;
        }
        slot = 0;
    }
    if (header->usableBoxCount != MAX_BOXES) {
        *pBox = header->usableBoxCount;
        *pSlot = 0;
        header->usableBoxCount += BOX_EXPAND_STEP;
        return 1;
    }
    return 0;
}

/*
 * Free slots over all boxes and in one box, the current box setter, and the
 * getter and setter for the per box wallpaper byte.
 *
 * BOX_SAVEDATA_CountFreeSlots spills its outer loop counter to the stack even though it is
 * an ordinary `int`: r4 through r7 are already carrying the inner counter,
 * the running total, the box array and the constant 0x88, and the GameData
 * pointer is on the stack too.  The spill is register pressure.
 *
 * The failure path of BOX_SAVEDATA_CountFreeSlotsInBox passes the same pointer as the first and
 * the third argument of SAVEDATA_PanicFail, which is the shape of an assertion
 * helper taking a file name twice; see
 * docs/idioms/file-string-is-an-abs32-into-the-string-area.md.
 */
int BOX_SAVEDATA_CountFreeSlots(struct GameData *gameData)
{
    int box;
    int slot;
    int freeCount = 0;

    for (box = 0; box < MAX_BOXES; box++) {
        struct BoxPokemon *boxMons = BOX_SAVEDATA_GetBoxPokemon(gameData, box);

        for (slot = 0; slot < BOX_CAPACITY; slot++) {
            if (POKE_TOOL_GetBoxValue(&boxMons[slot], MON_DATA_EXISTS, 0) == 0) {
                freeCount++;
            }
        }
    }
    return freeCount;
}

int BOX_SAVEDATA_CountFreeSlotsInBox(struct GameData *gameData, u32 box)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);
    struct BoxPokemon *boxMons;
    int slot;
    int freeCount;

    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    if (box >= MAX_BOXES) {
        SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
    }
    freeCount = 0;
    boxMons = BOX_SAVEDATA_GetBoxPokemon(gameData, box);
    for (slot = 0; slot < BOX_CAPACITY; slot++) {
        if (POKE_TOOL_GetBoxValue(&boxMons[slot], MON_DATA_EXISTS, 0) == 0) {
            freeCount++;
        }
    }
    return freeCount;
}

void BOX_SAVEDATA_SetCurrentBox(struct GameData *gameData, u32 box)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (box < MAX_BOXES) {
        header->currentBox = box;
    }
}

u8 BOX_SAVEDATA_GetWallpaper(struct GameData *gameData, u32 box)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (box < MAX_BOXES) {
        return header->wallpaper[box];
    }
    return 0;
}

void BOX_SAVEDATA_SetWallpaper(struct GameData *gameData, u32 box, u8 wallpaper)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    if (box < MAX_BOXES) {
        header->wallpaper[box] = wallpaper;
    }
}

/*
 * The box name getter and setter, two per box counts, and the whole-storage
 * totals that sum each of them over all 24 boxes.
 *
 * The range has to be exactly these six functions.  BOX_SAVEDATA_CountPokemonInBox is called
 * from one place in the image and BOX_SAVEDATA_CountNonEggPokemonInBox from one place, and those two
 * places are BOX_SAVEDATA_CountPokemon and BOX_SAVEDATA_CountNonEggPokemon respectively, so a file that
 * stopped before the summing loops would leave both counts with no witness
 * outside the compared range.  It cuts the other way too: the file cannot
 * start any later than 0x0200785C, because that is where the 0x28 byte name
 * array's first user is.
 *
 * The header's layout falls out of the shapes.  The name accessors do
 * `adds r2, r1, #4` and then multiply the box index by 0x28, so the names
 * are an array of 24 0x28 byte entries starting at offset 4 and ending at
 * 4 + 24 * 0x28 = 0x3C4, which is exactly where the per box byte starts.
 *
 * Two of the six needed their locals reordering before they matched, and the
 * evidence is only ever which register a value lands in.  BOX_SAVEDATA_CountNonEggPokemonInBox
 * declares its slot counter before the box array, the reverse of
 * BOX_SAVEDATA_CountPokemonInBox immediately above it.  The two summing loops initialise the
 * box index before the running total, which is why they are written
 * `for (box = 0, total = 0; ...)`: the order of the two `movs rN, #0` follows
 * the order of the initialisers.
 */
void BOX_SAVEDATA_GetBoxName(struct GameData *gameData, u32 box, struct Strbuf *dest)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    if (box < MAX_BOXES) {
        STRBUF_SetString(dest, header->names[box].chars);
        return;
    }
    SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
}

void BOX_SAVEDATA_SetBoxName(struct GameData *gameData, u32 box, const struct Strbuf *name)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    if (box < MAX_BOXES) {
        STRBUF_ToChars(name, header->names[box].chars, 0x14);
    }
}

/* Number of Pokemon in a box. */
int BOX_SAVEDATA_CountPokemonInBox(struct GameData *gameData, u32 box)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);
    struct BoxPokemon *boxMons;
    int slot;
    int count;

    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    if (box < MAX_BOXES) {
        count = 0;
        boxMons = BOX_SAVEDATA_GetBoxPokemon(gameData, box);
        for (slot = 0; slot < BOX_CAPACITY; slot++) {
            if (POKE_TOOL_GetBoxValue(&boxMons[slot], MON_DATA_EXISTS, 0) != 0) {
                count++;
            }
        }
        return count;
    }
    SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
    return 0;
}

/* Number of Pokemon in a box that are not eggs. */
int BOX_SAVEDATA_CountNonEggPokemonInBox(struct GameData *gameData, u32 box)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);
    int slot;
    struct BoxPokemon *boxMons;
    int count;

    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    if (box < MAX_BOXES) {
        count = 0;
        boxMons = BOX_SAVEDATA_GetBoxPokemon(gameData, box);
        for (slot = 0; slot < BOX_CAPACITY; slot++) {
            if (POKE_TOOL_GetBoxValue(&boxMons[slot], MON_DATA_EXISTS, 0) != 0 &&
                POKE_TOOL_GetBoxValue(&boxMons[slot], MON_DATA_IS_EGG, 0) == 0) {
                count++;
            }
        }
        return count;
    }
    SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
    return 0;
}

/* Pokemon in all boxes. */
int BOX_SAVEDATA_CountPokemon(struct GameData *gameData)
{
    int total;
    u32 box;

    for (box = 0, total = 0; box < MAX_BOXES; box++) {
        total += BOX_SAVEDATA_CountPokemonInBox(gameData, box);
    }
    return total;
}

/* Pokemon in all boxes that are not eggs. */
int BOX_SAVEDATA_CountNonEggPokemon(struct GameData *gameData)
{
    int total;
    u32 box;

    for (box = 0, total = 0; box < MAX_BOXES; box++) {
        total += BOX_SAVEDATA_CountNonEggPokemonInBox(gameData, box);
    }
    return total;
}

/*
 * The checked slot accessor in its two forms, the flag byte in the header,
 * the size of one box page, and the four byte allocation the box code hangs
 * its per-save state on.
 *
 * The file identity is in the image.  BOX_SAVEDATA_CreateWordHolder passes 0x020A706C to the
 * debug allocator at 0x02030734, and the bytes at 0x020A706C spell
 * "box_savedata.c".  PERAPVOICE_Create, further down the same run, passes
 * 0x020A707C instead, and those bytes spell "perapvoice.c", so a translation
 * unit boundary falls between the two.  See "The string class" in
 * docs/MATCHING.md for why 0x020A706C is carried.
 *
 * BOX_SAVEDATA_GetBoxPageSize carries no label because it saves nothing: `movs r0, #0xFF`,
 * `lsls r0, r0, #4`, `bx lr`.  0xFF0 is 30 entries of 0x88 bytes, which is
 * one box, and it never reaches a literal pool because a byte shifted left
 * costs two halfwords against a pool word plus its `ldr`.
 */
int BOX_SAVEDATA_GetPokemonValue(struct GameData *gameData, u32 box, u32 slot, int field, int arg)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (box >= MAX_BOXES && box != BOX_CURRENT) {
        SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
    }
    if (slot >= BOX_CAPACITY) {
        SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
    }
    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    return POKE_TOOL_GetBoxValue(&BOX_SAVEDATA_GetBoxPokemon(gameData, box)[slot], field, arg);
}

struct BoxPokemon *BOX_SAVEDATA_GetPokemon(struct GameData *gameData, u32 box, u32 slot)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (box >= MAX_BOXES && box != BOX_CURRENT) {
        SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
    }
    if (slot >= BOX_CAPACITY) {
        SAVEDATA_PanicFail(_BoxEmptyString, 0, _BoxEmptyString);
    }
    if (box == BOX_CURRENT) {
        box = header->currentBox;
    }
    return &BOX_SAVEDATA_GetBoxPokemon(gameData, box)[slot];
}

void BOX_SAVEDATA_SetFlags(struct GameData *gameData, u32 bits)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    header->flags |= (u8)bits;
}

int BOX_SAVEDATA_CheckFlags(struct GameData *gameData, u32 bits)
{
    struct BoxSaveHeader *header = BOX_SAVEDATA_GetHeader(gameData);

    if (header->flags & bits) {
        return 1;
    }
    return 0;
}

/* Size of one box page. */
u32 BOX_SAVEDATA_GetBoxPageSize(void)
{
    return BOX_CAPACITY * sizeof(struct BoxPokemon);
}

/* Allocate the four byte word holder (line 0x3B9 of box_savedata.c) and store `value` in it. */
u32 *BOX_SAVEDATA_CreateWordHolder(u32 heapId, u32 value)
{
    u32 *word = GFL_HEAP_Alloc(heapId, 4, 0, _BoxSavedataFileName, 0x3B9);

    *word = value;
    return word;
}

/*
 * The two block lookups everything above goes through, the page clear, and a
 * constructor.  BOX_SAVEDATA_GetBoxDataSize and PERAPVOICE_GetSize return the two object sizes,
 * 0xFF0 and 0x3EC, each as `movs` plus `lsls` rather than a pool word;
 * BOX_SAVEDATA_GetBoxPokemon is a tail call through a pool word, and it is the function
 * every accessor above reaches the box array with.
 */
void BOX_SAVEDATA_Delete(void *memory)
{
    GFL_HEAP_Free(memory);
}

/* Clear every Pokemon of a box page. */
void BOX_SAVEDATA_ClearBoxPage(struct BoxPokemon *boxMons)
{
    u32 slot;

    for (slot = 0; slot < BOX_CAPACITY; slot++) {
        POKE_TOOL_ClearBoxParam(&boxMons[slot]);
    }
}

u32 BOX_SAVEDATA_GetBoxDataSize(void)
{
    return BOX_CAPACITY * sizeof(struct BoxPokemon);
}

/* The Pokemon of one box: block box + 1 (block 0 is the header). */
struct BoxPokemon *BOX_SAVEDATA_GetBoxPokemon(struct GameData *gameData, u32 box)
{
    return SAVE_CONTROL_GetBlock(gameData->saveControl, box + 1);
}
