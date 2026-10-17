/*
 * file:     mystery_data.c
 * unit:     yes
 * function: MYSTERY_DATA_GetWorkSize, MYSTERY_DATA_Init, MYSTERY_DATA_IsValidGiftType, MYSTERY_DATA_CheckCardSpace, MYSTERY_DATA_CheckCardExist, MYSTERY_DATA_CloseCardGap, MYSTERY_DATA_GetCardPtr, MYSTERY_DATA_GetCard, MYSTERY_DATA_AddCard, MYSTERY_DATA_DeleteCard, MYSTERY_DATA_HasCardSpace, MYSTERY_DATA_IsCardExist, MYSTERY_DATA_IsCardReceived, MYSTERY_DATA_SetCardReceived, MYSTERY_DATA_HasAnyCard, MYSTERY_DATA_IsEventFlag, MYSTERY_DATA_SetEventFlag, MYSTERY_DATA_CheckPacketCrc, MYSTERY_DATA_SwapCards, MYSTERY_DATA_SaveStart, MYSTERY_DATA_SaveMain, MYSTERY_DATA_Create, MYSTERY_DATA_Delete, MYSTERY_DATA_GetCardSlotNum, MYSTERY_DATA_IsMainSave, MYSTERY_DATA_Load, MYSTERY_DATA_Unload, MYSTERY_DATA_GetSaveType, MYSTERY_DATA_GetCardMax, MYSTERY_DATA_GetBuffer, MYSTERY_DATA_GetEventFlags, MYSTERY_DATA_GetCardSlot, MYSTERY_DATA_Encrypt, MYSTERY_DATA_Decrypt, MYSTERY_DATA_EncryptBuffer, MYSTERY_DATA_DecryptBuffer
 * address:  0x02009ED4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mystery_data.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   GF_STANDARD_SetupCalc  0x0203F1FC  arm
 *   SAVE_OUTSIDE_Prepare    0x021DFDC0  thumb
 *   SAVE_OUTSIDE_WriteAsync    0x021DFE00  thumb
 *   sMysteryDataFile      0x020A71A4  data
 *   SAVE_CONTROL_HasFlashSave   0x020071EC  thumb
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   SAVE_OUTSIDE_Load  0x021DFC20  thumb  ov228
 *   SAVE_OUTSIDE_IsLoaded  0x021DFE90  thumb  ov228
 *   SAVE_OUTSIDE_GetPayload  0x021DFEAC  thumb  ov228
 *   ov_id_E4       0x000000E4  data
 *   SAVE_OUTSIDE_Free  0x021DFDB8  thumb  ov228
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   GAME_DATA_SaveStart  0x02012DAC  thumb
 *   GAME_DATA_SaveMain  0x02012DD0  thumb
 *   GF_STANDARD_Checksum  0x0203F2FC  arm
 *   GF_STANDARD_Shuffle  0x0203F328  arm
 *   GF_STANDARD_ShuffleEx  0x0203F37C  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 */
#include "wifilist_tail_shared_types.h"

struct GameData;

/*
 * Mystery gift data (save block 0x22, 0xA94 bytes; 0x368 bytes when it is
 * read from the extra save of overlay 228): a 0x800-bit event flag table,
 * then 12 (or 3) gift cards of 0xCC bytes, then a 4-byte footer that holds
 * the checksum and the seed of the encryption key.
 */
struct MysteryCard {
    u8 body[0xB3];
    u8 giftType;                          /* 1..3 when the slot holds a card */
    u8 flags;                             /* bit 1: gift received */
    u8 tail[0x17];
};

/* Word view of one card: the slot copy needs a four-aligned type to be an
 * ldm/stm loop. */
struct MysteryCardImage {
    u32 words[0x33];
};

struct MysteryDataFooter {
    u16 checksum;
    u16 cryptSeed;
};

/* The 12-byte handle that MYSTERY_DATA_Create returns. */
struct MysteryData {
    u8   *buffer;
    u32   saveType;                       /* 1: main save block, 0: extra save */
    void *extraSave;                      /* overlay 228 work for saveType 0 */
};

/* A received gift packet: 0x2CE bytes of body and their CRC. */
struct MysteryGiftPacket {
    u8  body[0x2CE];
    u16 crc;
};

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

extern void *SAVE_CONTROL_GetBlock(struct SaveControl *save, u32 blockId);

extern u8   SAVE_CONTROL_HasFlashSave(const struct SaveControl *save);

extern u16  GF_STANDARD_SetupCalc(const void *data, u32 size);

extern u32  GF_STANDARD_Checksum(const void *data, u32 size);

extern void GF_STANDARD_Shuffle(void *data, u32 size, u32 key);

extern void GF_STANDARD_ShuffleEx(void *data, u32 size, u32 key);

extern void SAVE_OUTSIDE_Prepare(void *extraSave);

extern int  GAME_DATA_SaveStart(struct GameData *gameData);

extern int  SAVE_OUTSIDE_WriteAsync(void *extraSave);

extern int  GAME_DATA_SaveMain(struct GameData *gameData);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32  GFL_HEAP_Free(void *p);

extern int  GF_OVERLAY_Load(int overlayId);

extern void GF_OVERLAY_Unload(int overlayId);

extern void *SAVE_OUTSIDE_Load(u32 heapId);

extern u8   SAVE_OUTSIDE_IsLoaded(u8 *extraSave);

extern void *SAVE_OUTSIDE_GetPayload(u8 *extraSave);

extern void SAVE_OUTSIDE_Free(void *extraSave);

u32 MYSTERY_DATA_GetWorkSize(void);

void MYSTERY_DATA_Init(u8 *buffer);

u32 MYSTERY_DATA_IsValidGiftType(u32 giftType);

int MYSTERY_DATA_CheckCardSpace(struct MysteryData *data);

int MYSTERY_DATA_CheckCardExist(struct MysteryData *data, u32 slot);

void MYSTERY_DATA_CloseCardGap(struct MysteryData *data, u32 slot);

struct MysteryCard *MYSTERY_DATA_GetCardPtr(struct MysteryData *data, u32 slot);

int MYSTERY_DATA_GetCard(struct MysteryData *data, u32 slot, void *out);

int MYSTERY_DATA_AddCard(struct MysteryData *data, const void *card);

void MYSTERY_DATA_DeleteCard(struct MysteryData *data, u32 slot);

u32 MYSTERY_DATA_HasCardSpace(struct MysteryData *data);

u32 MYSTERY_DATA_IsCardExist(struct MysteryData *data, u32 slot);

int MYSTERY_DATA_IsCardReceived(struct MysteryData *data, u32 slot);

void MYSTERY_DATA_SetCardReceived(struct MysteryData *data, u32 slot);

int MYSTERY_DATA_HasAnyCard(struct MysteryData *data);

int MYSTERY_DATA_IsEventFlag(struct MysteryData *data, u32 flag);

void MYSTERY_DATA_SetEventFlag(struct MysteryData *data, u32 flag);

int MYSTERY_DATA_CheckPacketCrc(struct MysteryGiftPacket *packet);

void MYSTERY_DATA_SwapCards(struct MysteryData *data, u32 slotA, u32 slotB);

void MYSTERY_DATA_SaveStart(struct MysteryData *data, struct GameData *gameData);

int MYSTERY_DATA_SaveMain(struct MysteryData *data, struct GameData *gameData);

struct MysteryData *MYSTERY_DATA_Create(struct SaveControl *save, int mode, u32 heapId);

void MYSTERY_DATA_Delete(struct MysteryData *data);

u32 MYSTERY_DATA_GetCardSlotNum(struct MysteryData *data);

int MYSTERY_DATA_IsMainSave(struct MysteryData *data);

void MYSTERY_DATA_Load(struct MysteryData *data, struct SaveControl *save, int mode, int heapId);

void MYSTERY_DATA_Unload(struct MysteryData *data);

u32 MYSTERY_DATA_GetSaveType(struct MysteryData *data);

u32 MYSTERY_DATA_GetCardMax(struct MysteryData *data);

u8 *MYSTERY_DATA_GetBuffer(struct MysteryData *data);

u8 *MYSTERY_DATA_GetEventFlags(struct MysteryData *data);

struct MysteryCard *MYSTERY_DATA_GetCardSlot(struct MysteryData *data, u32 slot);

void MYSTERY_DATA_Encrypt(struct MysteryData *data);

void MYSTERY_DATA_Decrypt(struct MysteryData *data);

void MYSTERY_DATA_EncryptBuffer(u8 *buffer, u32 saveType);

void MYSTERY_DATA_DecryptBuffer(u8 *buffer, u32 saveType);

extern char sMysteryDataFile[];

extern u8   ov_id_E4[];

/*
 * Save-table size callback: returns 0xA94, the size of the block whose
 * init is MYSTERY_DATA_Init.  Pointer word 0x02009ED5 at 0x0209DBC4 (the
 * save table's (size, init, id) row for id 0x22).
 */
u32 MYSTERY_DATA_GetWorkSize(void)
{
    return 0xA94;
}

void MYSTERY_DATA_Init(u8 *buffer)
{
    struct MysteryData data;

    MI_CpuFill8(&data, 0, sizeof(data));
    data.buffer = buffer;
    data.saveType = 1;
    MI_CpuFill8(buffer, 0, 0xa94);
    MYSTERY_DATA_Encrypt(&data);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/MYSTERY_DATA_IsValidGiftType.c \\
 *       --func MYSTERY_DATA_IsValidGiftType --addr 0x02009F0C --thumb --cc 1.1p1
 */
u32 MYSTERY_DATA_IsValidGiftType(u32 giftType)
{
    if (giftType != 0 && giftType < 4) {
        return 1;
    }
    return 0;
}

int MYSTERY_DATA_CheckCardSpace(struct MysteryData *data)
{
    u32 i;
    u32 max = MYSTERY_DATA_GetCardMax(data);

    for (i = 0; i < max; i++) {
        if (MYSTERY_DATA_IsValidGiftType(MYSTERY_DATA_GetCardSlot(data, i)->giftType) == 0)
            return 1;
    }
    return 0;
}

int MYSTERY_DATA_CheckCardExist(struct MysteryData *data, u32 slot)
{
    struct MysteryCard *card = MYSTERY_DATA_GetCardSlot(data, slot);
    MYSTERY_DATA_GetCardMax(data);
    if (slot < 0xc && MYSTERY_DATA_IsValidGiftType(card->giftType) != 0)
        return 1;
    return 0;
}

void MYSTERY_DATA_CloseCardGap(struct MysteryData *data, u32 slot)
{
    u32 i;
    u32 max = MYSTERY_DATA_GetCardMax(data);
    if (MYSTERY_DATA_CheckCardExist(data, slot) != 0)
        return;
    for (i = slot; i < max - 1; i++) {
        void *dst = MYSTERY_DATA_GetCardSlot(data, i);
        void *src = MYSTERY_DATA_GetCardSlot(data, i + 1);
        /* word view: the copy is an ldm/stm loop only for a four-aligned type */
        *(struct MysteryCardImage *)dst = *(struct MysteryCardImage *)src;
    }
    MI_CpuFill8(MYSTERY_DATA_GetCardSlot(data, i), 0, sizeof(struct MysteryCard));
}

struct MysteryCard *MYSTERY_DATA_GetCardPtr(struct MysteryData *data, u32 slot)
{
    struct MysteryCard *card = MYSTERY_DATA_GetCardSlot(data, slot);
    u32 max = MYSTERY_DATA_GetCardMax(data);
    if (slot < max && MYSTERY_DATA_IsValidGiftType(card->giftType) != 0)
        return card;
    return 0;
}

int MYSTERY_DATA_GetCard(struct MysteryData *data, u32 slot, void *out)
{
    struct MysteryCard *card;
    int found = 0;
    MYSTERY_DATA_GetCardMax(data);
    MYSTERY_DATA_Decrypt(data);
    card = MYSTERY_DATA_GetCardPtr(data, slot);
    if (card != 0) {
        MI_CpuCopy8(card, out, sizeof(struct MysteryCard));
        found = 1;
    }
    MYSTERY_DATA_Encrypt(data);
    return found;
}

int MYSTERY_DATA_AddCard(struct MysteryData *data, const void *card)
{
    u32 i;
    int added = 0;
    u32 max = MYSTERY_DATA_GetCardMax(data);
    MYSTERY_DATA_Decrypt(data);
    if (MYSTERY_DATA_CheckCardSpace(data) == 1) {
        for (i = 0; i < max; i++) {
            struct MysteryCard *slot = MYSTERY_DATA_GetCardSlot(data, i);
            if (MYSTERY_DATA_IsValidGiftType(slot->giftType) == 0) {
                MI_CpuCopy8(card, slot, sizeof(struct MysteryCard));
                added = 1;
                break;
            }
        }
    }
    MYSTERY_DATA_Encrypt(data);
    return added;
}

void MYSTERY_DATA_DeleteCard(struct MysteryData *data, u32 slot)
{
    u32 max = MYSTERY_DATA_GetCardMax(data);
    MYSTERY_DATA_Decrypt(data);
    if (slot < max) {
        struct MysteryCard *card = MYSTERY_DATA_GetCardSlot(data, slot);
        card->giftType = 0;
        MYSTERY_DATA_CloseCardGap(data, slot);
    }
    MYSTERY_DATA_Encrypt(data);
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/MYSTERY_DATA_HasCardSpace.c \\
 *       --func MYSTERY_DATA_HasCardSpace --addr 0x0200A0C8 --thumb --cc 1.1p1
 */
u32 MYSTERY_DATA_HasCardSpace(struct MysteryData *data)
{
    u32 hasSpace;

    MYSTERY_DATA_Decrypt(data);
    hasSpace = MYSTERY_DATA_CheckCardSpace(data);
    MYSTERY_DATA_Encrypt(data);
    return hasSpace;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/MYSTERY_DATA_IsCardExist.c \\
 *       --func MYSTERY_DATA_IsCardExist --addr 0x0200A0E4 --thumb --cc 1.1p1
 */
u32 MYSTERY_DATA_IsCardExist(struct MysteryData *data, u32 slot)
{
    u32 exists;

    MYSTERY_DATA_Decrypt(data);
    exists = MYSTERY_DATA_CheckCardExist(data, slot);
    MYSTERY_DATA_Encrypt(data);
    return exists;
}

int MYSTERY_DATA_IsCardReceived(struct MysteryData *data, u32 slot)
{
    int received = 0;
    u32 max = MYSTERY_DATA_GetCardMax(data);
    MYSTERY_DATA_Decrypt(data);
    if (slot < max) {
        struct MysteryCard *card = MYSTERY_DATA_GetCardSlot(data, slot);
        if (((u32)card->flags << 0x1e) >> 0x1f)
            received = 1;
    }
    MYSTERY_DATA_Encrypt(data);
    return received;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/MYSTERY_DATA_SetCardReceived.c \\
 *       --func MYSTERY_DATA_SetCardReceived --addr 0x0200A13C --thumb --cc 1.1p1
 */
void MYSTERY_DATA_SetCardReceived(struct MysteryData *data, u32 slot)
{
    u32 max = MYSTERY_DATA_GetCardMax(data);
    struct MysteryCard *card;

    MYSTERY_DATA_Decrypt(data);
    if (slot < max) {
        card = MYSTERY_DATA_GetCardSlot(data, slot);
        card->flags |= 2;
    }
    MYSTERY_DATA_Encrypt(data);
}

int MYSTERY_DATA_HasAnyCard(struct MysteryData *data)
{
    int found = 0;
    u32 i;
    u32 max = MYSTERY_DATA_GetCardMax(data);
    MYSTERY_DATA_Decrypt(data);
    for (i = 0; i < max; i++) {
        if (MYSTERY_DATA_CheckCardExist(data, i) == 1)
            found = 1;
    }
    MYSTERY_DATA_Encrypt(data);
    return found;
}

int MYSTERY_DATA_IsEventFlag(struct MysteryData *data, u32 flag)
{
    int set = 0;
    u8 *flags = MYSTERY_DATA_GetEventFlags(data);
    MYSTERY_DATA_Decrypt(data);
    if (flag < 0x800) {
        if (flags[flag >> 3] & (1 << (flag & 7)))
            set = 1;
    }
    MYSTERY_DATA_Encrypt(data);
    return set;
}

void MYSTERY_DATA_SetEventFlag(struct MysteryData *data, u32 flag)
{
    u8 *flags = MYSTERY_DATA_GetEventFlags(data);
    MYSTERY_DATA_Decrypt(data);
    if (flag < 0x800) {
        flags[flag >> 3] |= (u8)(1 << (flag & 7));
    }
    MYSTERY_DATA_Encrypt(data);
}

/*
 * note:     closed 2026-09-21 by tools/permuter.py (hill, --types): declaration order i before n,
 *           and the counter n is unsigned (8 bytes)
 */
int MYSTERY_DATA_CheckPacketCrc(struct MysteryGiftPacket *packet)
{
    int i;
    u32 spinLimit = 0x2d0;
    u32 spin = 0;

    do {
        for (i = 0; i < 16; i++) {
            spin++;
        }
    } while (spin < (int)spinLimit);
    return packet->crc == GF_STANDARD_SetupCalc(packet, 0x2ce);
}

void MYSTERY_DATA_SwapCards(struct MysteryData *data, u32 slotA, u32 slotB)
{
    u8 swapCard[0xcc];
    MYSTERY_DATA_Decrypt(data);
    if (MYSTERY_DATA_CheckCardExist(data, slotA) && MYSTERY_DATA_CheckCardExist(data, slotB)) {
        struct MysteryCard *cardA = MYSTERY_DATA_GetCardPtr(data, slotA);
        struct MysteryCard *cardB = MYSTERY_DATA_GetCardPtr(data, slotB);
        MI_CpuCopy8(cardA, swapCard, sizeof(struct MysteryCard));
        MI_CpuCopy8(cardB, cardA, sizeof(struct MysteryCard));
        MI_CpuCopy8(swapCard, cardB, sizeof(struct MysteryCard));
    }
    MYSTERY_DATA_Encrypt(data);
}

void MYSTERY_DATA_SaveStart(struct MysteryData *data, struct GameData *gameData)
{
    if (MYSTERY_DATA_IsMainSave(data) == 0) {
        SAVE_OUTSIDE_Prepare(data->extraSave);
    } else {
        GAME_DATA_SaveStart(gameData);
    }
}

int MYSTERY_DATA_SaveMain(struct MysteryData *data, struct GameData *gameData)
{
    if (MYSTERY_DATA_IsMainSave(data) == 0) {
        if (SAVE_OUTSIDE_WriteAsync(data->extraSave) != 0)
            return 2;
        return 0;
    }
    return GAME_DATA_SaveMain(gameData);
}

struct MysteryData *MYSTERY_DATA_Create(struct SaveControl *save, int mode, u32 heapId)
{
    struct MysteryData *data = GFL_HEAP_Alloc(heapId, sizeof(struct MysteryData), 0, sMysteryDataFile, 0x260);

    MI_CpuFill8(data, 0, sizeof(struct MysteryData));
    MYSTERY_DATA_Load(data, save, mode, heapId);
    return data;
}

void MYSTERY_DATA_Delete(struct MysteryData *data)
{
    MYSTERY_DATA_Unload(data);
    GFL_HEAP_Free(data);
}

/*
 * Four bytes of code and a pool word: the plain Thumb tail call of
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.  It carries no label in the
 * generated listing (it saves nothing), so it was read out of the bytes; it
 * sits between MYSTERY_DATA_Delete and MYSTERY_DATA_IsMainSave at the end of its packet.
 * Its target reads one object pointer in r0 and returns the unsigned count
 * used by the overlay callers.
 */
u32 MYSTERY_DATA_GetCardSlotNum(struct MysteryData *data)
{
    return MYSTERY_DATA_GetCardMax(data);
}

int MYSTERY_DATA_IsMainSave(struct MysteryData *data)
{
    return MYSTERY_DATA_GetSaveType(data);
}

/*
 * note:     wave 16: promoted.  0x021DFE90 and 0x021DFEAC are unlabelled
 *           ov228 leaves (a byte getter at +0x378 and `p + 0xC`), now matched
 *           in src/matched/SAVE_OUTSIDE_IsLoaded.c / SAVE_OUTSIDE_GetPayload.c (shard
 *           ov228/pkt_021DFC20); the ov228 hints below make both sites
 *           `matched, overlay`.  SAVE_OUTSIDE_GetPayload's body reads r0, so its
 *           prototype now takes the pointer SAVE_OUTSIDE_Load returned (the
 *           callee-arity lever; same bytes, it was a live leftover before).
 * WHAT CHANGED THIS WAVE (docs/notes/pkt_0200A358.c.txt had this row at DIFF,
 * 112 bytes against 120, 91 concrete bytes out).  The note's C spelled the
 * dispatch on a2 as `if (a2 == 1) t = SAVE_CONTROL_HasFlashSave(a1);` with `t` initialised
 * to 1.  The original is a SWITCH with an explicit empty-ish case 0:
 *
 *   0200A36A  cmp r4, #0 / beq  ->  0200A374: b 0200A37E  (t = 1)
 *   0200A36E  cmp r4, #1 / beq  ->  0200A376: bl 20071EC
 *   0200A372  b            ->  0200A37E: movs r0, #1      (default, t = 1)
 *
 * Two separate branch targets that both land on `movs r0, #1` is the tell of
 * docs/idioms/empty-switch-arms-are-what-make-the-table.md read the other way
 * round: case 0 and the default arm are written out separately in the source
 * even though they do the same thing.  Writing the switch with case 0,
 * case 1 and default each assigning `t` recovers the missing 8 bytes AND the
 * register allocation -- the `if` form spilled a3 to `[sp]` where the
 * original keeps it in r7 -- and takes the row from 91 concrete bytes out to
 * zero in one edit.  The 0xE4 pool word is the same absolute linker symbol
 * MYSTERY_DATA_Unload next door uses
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/pending/MYSTERY_DATA_Load.c \
 *       --func MYSTERY_DATA_Load --addr 0x0200A358 --cc 1.1p1 --thumb
 */
void MYSTERY_DATA_Load(struct MysteryData *data, struct SaveControl *save, int mode, int heapId)
{
    int inMainSave;
    void *work;

    MI_CpuFill8(data, 0, sizeof(struct MysteryData));
    switch (mode) {
    case 0:
        inMainSave = 1;
        break;
    case 1:
        inMainSave = SAVE_CONTROL_HasFlashSave(save);
        break;
    default:
        inMainSave = 1;
        break;
    }
    if (inMainSave != 0) {
        data->buffer = SAVE_CONTROL_GetBlock(save, 0x22);
        data->saveType = 1;
        return;
    }
    GF_OVERLAY_Load((int)ov_id_E4);
    work = SAVE_OUTSIDE_Load(heapId);
    data->extraSave = work;
    data->buffer = SAVE_OUTSIDE_GetPayload(work);
    data->saveType = 0;
    if (SAVE_OUTSIDE_IsLoaded(data->extraSave) == 0) {
        MI_CpuFill8(data->buffer, 0, 0x368);
        MYSTERY_DATA_Encrypt(data);
    }
}

/*
 * note:     wave 16: promoted.  0x021DFDB8 is an unlabelled ov228 leaf, a
 *           one-argument tail call to the ARM heap free GFL_HEAP_Free, now
 *           matched in src/matched/SAVE_OUTSIDE_Free.c (shard ov228/pkt_021DFC20);
 *           the ov228 hint below makes the site `matched, overlay`.
 * Third pass, lane 1: this row was DIFF for two passes and is now byte-correct.
 * The residue was never a codegen difference.  The original's second call is
 *
 *   0200A3E4  04 48        ldr r0, [pc, #0x10]
 *   0200A3E6  2a f0 3a eb  blx #0x2034a5c
 *   ...
 *   0200A3F8  e4 00 00 00  0x000000E4
 *
 * a small constant loaded from the pool where `GF_OVERLAY_Unload(0xe4)` gives
 * `movs r0, #0xe4`.  That is the reading of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md: a pool
 * word holding a value too small to be an address is an `R_ARM_ABS32` against
 * an absolute symbol, i.e. 0xE4 is a linker-defined id, and declaring it and
 * passing it reproduces the original's pool word and all 44 bytes.  The
 * site resolves as `literal x2` (two other pool words in the image hold
 * 0x000000E4, e.g. 0x02007070), which is what confirms the reading.
 * Five numeric spellings were tried and all five give `movs`:
 * `0xe4`, `(u32)0xe4`, a macro, a `static const u32`, and a file-scope
 * `const u32`.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/MYSTERY_DATA_Unload.c \
 *       --func MYSTERY_DATA_Unload --addr 0x0200A3D0 --cc 1.1p1 --thumb
 */
void MYSTERY_DATA_Unload(struct MysteryData *data)
{
    switch (data->saveType) {
    case 0:
        SAVE_OUTSIDE_Free(data->extraSave);
        GF_OVERLAY_Unload((int)ov_id_E4);
        break;
    case 1:
        break;
    }
    MI_CpuFill8(data, 0, sizeof(struct MysteryData));
}

#define HW_VBLANK_COUNT_BUF (*(volatile u32 *)0x02FFFC3C)

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           MYSTERY_DATA_GetCardSlot, MYSTERY_DATA_Encrypt, MYSTERY_DATA_Decrypt, MYSTERY_DATA_EncryptBuffer,
 *           MYSTERY_DATA_DecryptBuffer, MUSICAL_SAVE_GetSize, MUSICAL_SAVE_Init, MUSICAL_SAVE_GetFromSave,
 *           MUSICAL_SAVE_InitOutfits, MUSICAL_SAVE_GetOutfits, MUSICAL_SAVE_IsShowActive, MUSICAL_SAVE_NoOp,
 *           MUSICAL_SAVE_IsPropOwned, MUSICAL_SAVE_IsPropNew, MUSICAL_SAVE_AddProp
 *
 * 764 bytes, 0x0200A3FC..0x0200A6F8, 19 functions.  Five of the nineteen
 * carry no label in the generated listing (0x0200A53C, 0x0200A628,
 * 0x0200A630, 0x0200A640 and 0x0200A680): none of them saves lr, so
 * disasm.py's prologue sweep does not fire and the listing prints their
 * bytes as `.word` data in the middle of a literal pool.  They were read out
 * of those words.  0x0200A53C is the giveaway of the three: `movs r0, #0xa9;
 * lsls r0, #2; bx lr` returns 0x2A4, which is exactly the size the
 * constructor at 0x0200A544 clears, the same "a block file opens with a
 * function returning its own size" shape docs/MATCHING.md records for the
 * 0x0200857C run.
 *
 * This unit absorbs the previously matched single function
 * src/matched/MUSICAL_SAVE_AddProp.c (0x0200A6BC, 60 bytes), which is its last
 * function.  Its legacy manifest entry is superseded by this unit.
 *
 * What the range is.  Two objects, and two layers.
 *
 * `struct MysteryData` is a twelve byte handle: a pointer to a block, a kind that is
 * only ever 0 or 1, and a third word.  Every accessor on it is a `switch`
 * over that kind with the default falling through to a zero return, and the
 * two arms are byte for byte identical in three of the four cases, so the
 * distinction is in the source and not in the code.  The 0x0200A4B8 /
 * 0x0200A50C pair stamps and clears a four byte header sitting at the end of
 * the block (offset 0x364 or 0xA90 for the two kinds), holding a 32-bit key
 * built out of a system word and handed to the pair of routines at
 * 0x0203F2FC / 0x0203F328 / 0x0203F37C.
 *
 * `struct MusicalSave` is a 0x2A4-byte record with two parallel 0x20-byte bitmaps at
 * 0x258 and 0x278.  0x0200A6BC sets the same bit in both, 0x0200A644 tests
 * the first and 0x0200A680 tests the second; the constructor at 0x0200A544
 * clears the record, seeds two arrays and then sets fifteen of those bits by
 * hand.  100 (0x64) is the bound on every one of the three, so 100 of the
 * 256 bits are in use.
 *
 * Three things in this unit cost time and are recorded under docs/idioms/:
 *
 *  - the assignment that both arms of a switch make is emitted once, at a
 *    merge point the default case jumps over.  Writing it after the switch
 *    instead puts the default's branch on that merge point and changes one
 *    branch target and the whole register allocation of the function.  See
 *    docs/idioms/switch-arms-tail-merge.md.
 *  - a repeated read of a hardware address has to be written as two named
 *    locals.  `(X << 8) | X` on a volatile lvalue interleaves the shift
 *    between the two loads; the original loads both and then shifts.  See
 *    docs/idioms/volatile-reread-needs-two-locals.md.
 *  - 0x02FFFC3C is a cast address constant and not an extern.  An `extern
 *    volatile u32` at that address produces an ABS32 relocation and puts the
 *    address in a different register.  Same idiom file as above.
 *
 * Near miss, left out of this unit deliberately: the function at
 * 0x0200A3D0, which is the one immediately before it and is almost certainly
 * part of the same original file.  Two separate reasons, either of which is
 * enough:
 *
 *  1. it calls 0x021DFDB8, which is an overlay address.  `attest()` now has a
 *     rule for those: a target inside an overlay per layout/layout.json is
 *     attested when that overlay's own listing carries a `func_` label at the
 *     address, the label's ISA is the declared ISA, and some branch outside
 *     the compared range targets it.  The third part holds here (a `bl` from
 *     0x02006F42 inside arm9_main and another from ov088 at 0x021BC378); the
 *     first does not.  0x021DFDB8 is inside seven overlays at once, because
 *     overlays share load windows, and they disagree about what is there:
 *     ov093 has an instruction in the middle of a function, ov119 a `movs`,
 *     ov170 a data word, ov228 an eight byte Thumb thunk.  None of them
 *     labels it, so nothing says which of the seven the call means and the
 *     relocation stays a wildcard.  (The thunk in ov228 is the linker's Thumb
 *     veneer shape, which the `veneer` class deliberately does not recognise:
 *     mwccarm emits those same eight bytes for a Thumb tail call.  See "The
 *     veneer class" in docs/MATCHING.md.)
 *  2. two concrete bytes are wrong regardless.  The original materialises the
 *     constant 0xE4 with `ldr r0, [pc, #0x10]` out of its own literal pool,
 *     where every spelling of the integer 228 tried here (decimal, hex,
 *     suffixed, cast, enumerator, `sizeof`, `offsetof`) compiles to `movs
 *     r0, #0xE4` under all nine front ends at every optimisation level.  The
 *     function immediately before it does the same thing with the same value,
 *     so whatever the construct is, it is used twice in a row and is not an
 *     accident.  The rest of the function is byte for byte right.
 */
u32 MYSTERY_DATA_GetSaveType(struct MysteryData *data)
{
    return data->saveType;
}

u32 MYSTERY_DATA_GetCardMax(struct MysteryData *data)
{
    switch (data->saveType) {
    case 0:
        return 3;
    case 1:
        return 12;
    }
    return 0;
}

u8 *MYSTERY_DATA_GetBuffer(struct MysteryData *data)
{
    return data->buffer;
}

u8 *MYSTERY_DATA_GetEventFlags(struct MysteryData *data)
{
    switch (data->saveType) {
    case 0:
        return MYSTERY_DATA_GetBuffer(data);
    case 1:
        return MYSTERY_DATA_GetBuffer(data);
    }
    return 0;
}

struct MysteryCard *MYSTERY_DATA_GetCardSlot(struct MysteryData *data, u32 slot)
{
    MYSTERY_DATA_GetCardMax(data);
    switch (data->saveType) {
    case 0:
        return (struct MysteryCard *)(MYSTERY_DATA_GetBuffer(data) + 0x100 + slot * 0xCC);
    case 1:
        return (struct MysteryCard *)(MYSTERY_DATA_GetBuffer(data) + 0x100 + slot * 0xCC);
    }
    return 0;
}

void MYSTERY_DATA_Encrypt(struct MysteryData *data)
{
    MYSTERY_DATA_EncryptBuffer(MYSTERY_DATA_GetBuffer(data), MYSTERY_DATA_GetSaveType(data));
}

void MYSTERY_DATA_Decrypt(struct MysteryData *data)
{
    MYSTERY_DATA_DecryptBuffer(MYSTERY_DATA_GetBuffer(data), MYSTERY_DATA_GetSaveType(data));
}

void MYSTERY_DATA_EncryptBuffer(u8 *buffer, u32 saveType)
{
    u32 size;
    struct MysteryDataFooter *footer;
    u32 seedHigh, seedLow;

    switch (saveType) {
    case 0:
        size = 0x368;
        footer = (struct MysteryDataFooter *)(buffer + (size - 4));
        break;
    case 1:
        size = 0xA94;
        footer = (struct MysteryDataFooter *)(buffer + (size - 4));
        break;
    }
    seedHigh = HW_VBLANK_COUNT_BUF;
    seedLow = HW_VBLANK_COUNT_BUF;
    footer->cryptSeed = (u16)((seedHigh << 8) | seedLow);
    if (footer->cryptSeed == 0) {
        footer->cryptSeed = 1;
    }
    footer->checksum = GF_STANDARD_Checksum(buffer, size - 4);
    GF_STANDARD_Shuffle(buffer, size - 4, footer->checksum + (footer->cryptSeed << 16));
}

void MYSTERY_DATA_DecryptBuffer(u8 *buffer, u32 saveType)
{
    u32 size;
    struct MysteryDataFooter *footer;

    switch (saveType) {
    case 0:
        size = 0x368;
        footer = (struct MysteryDataFooter *)(buffer + (size - 4));
        break;
    case 1:
        size = 0xA94;
        footer = (struct MysteryDataFooter *)(buffer + (size - 4));
        break;
    }
    GF_STANDARD_ShuffleEx(buffer, size - 4, footer->checksum + (footer->cryptSeed << 16));
    footer->cryptSeed = 0;
}
