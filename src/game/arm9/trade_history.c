/*
 * file:     trade_history.c
 * unit:     yes
 * function: TRADE_HISTORY_GetSize, TRADE_HISTORY_Init, TRADE_HISTORY_FindPartner, TRADE_HISTORY_AddPartner, TRADE_HISTORY_GetPartnerId, TRADE_HISTORY_GetPartner, TRADE_HISTORY_HasPartner, TRADE_HISTORY_GetPartnerCount, TRADE_HISTORY_GetTradeCount, TRADE_HISTORY_IncrementTradeCount, TRADE_HISTORY_GetFromSave
 * address:  0x02009D9C
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
 *   MI_CpuMove   0x02083194  arm
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   MYSTATUS_GetOutfit  0x02008554  thumb
 *   MYSTATUS_SetOutfit  0x02008558  thumb
 *   MYSTATUS_GetAvatarId  0x0200855C  thumb
 *   MYSTATUS_GetSize  0x02008468  thumb
 */
#include "wifilist_tail_shared_types.h"

/*
 * Save block 0x1F, the trade partner history: the last 100 trade partners,
 * most recent first, and a trade counter that saturates at 99999.
 */
struct TradeHistory {
    struct MyStatus partners[100];
    u8  reserved[0xD0];
    u32 tradeCount;
};

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

extern void MI_CpuMove(const void *src, void *dest, u32 size);

extern void *SAVE_CONTROL_GetBlock(struct SaveControl *save, u32 blockId);

extern u32  MYSTATUS_GetId(const struct MyStatus *status);

extern int  MYSTATUS_GetSize(void);

extern u8   MYSTATUS_GetOutfit(const struct MyStatus *status);

extern void MYSTATUS_SetOutfit(struct MyStatus *status, u8 value);

extern u8   MYSTATUS_GetAvatarId(const struct MyStatus *status);

u32 TRADE_HISTORY_GetSize(void);

void TRADE_HISTORY_Init(struct TradeHistory *history);

int TRADE_HISTORY_FindPartner(struct TradeHistory *history, u32 id);

void TRADE_HISTORY_AddPartner(struct TradeHistory *history, struct MyStatus *status);

u32 TRADE_HISTORY_GetPartnerId(struct TradeHistory *history, u32 slot);

struct MyStatus *TRADE_HISTORY_GetPartner(struct TradeHistory *history, u32 slot);

u32 TRADE_HISTORY_HasPartner(struct TradeHistory *history, u32 id);

int TRADE_HISTORY_GetPartnerCount(struct TradeHistory *history);

u32 TRADE_HISTORY_GetTradeCount(const struct TradeHistory *history);

void TRADE_HISTORY_IncrementTradeCount(struct TradeHistory *history);

struct TradeHistory *TRADE_HISTORY_GetFromSave(struct SaveControl *save);

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * alias: the head of the next file after wifilist.c, a 0xD54-byte record whose
 * rest is in pkt_02009DB8.  Same opening as every other record here: a four
 * byte function returning the size over its own pool word, then a constructor
 * that clears exactly that many bytes.
 *
 * Unlike the 0x23 block in src/matched/unit_02009448.c, this constructor
 * *calls* the size function instead of spelling the constant a second time, so
 * the two files differ in the source and not only in the bytes.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009D9C.c \
 *       --addr 0x02009D9C --thumb
 */
u32 TRADE_HISTORY_GetSize(void)
{
    return sizeof(struct TradeHistory);
}

void TRADE_HISTORY_Init(struct TradeHistory *history)
{
    MI_CpuFill8(history, 0, TRADE_HISTORY_GetSize());
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 *           TRADE_HISTORY_HasPartner, TRADE_HISTORY_GetPartnerCount, TRADE_HISTORY_GetTradeCount, TRADE_HISTORY_IncrementTradeCount
 *
 * alias: the body of the 0xD54-byte record whose head is
 * src/matched/unit_02009D9C.c.  It is a hundred-slot most-recently-used list
 * of the 0x20-byte object of src/matched/unit_0200852C.c, plus one counter:
 *
 *   +0x000  MyStatus[100]         0x20 bytes each
 *   +0xD50  u32                   a use count, saturating at 99999
 *
 * MYSTATUS_GetSize, four bytes returning 0x20, is the element size, and
 * TRADE_HISTORY_AddPartner uses it for both of its block moves rather than spelling 0x20
 * out.  The insert shifts the whole list up by one slot with MI_CpuMove and
 * copies the new object into slot 0, so slot 0 is the most recent; when the
 * object is already in the list only its +0x1C byte is refreshed.
 *
 * TRADE_HISTORY_FindPartner returns -1 for "not found", materialised as `movs r0, #0` and
 * `mvns r0, r0` rather than as a pool word, and every caller compares against
 * that same pair.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02009DB8.c \
 *       --addr 0x02009DB8 --thumb
 */
int TRADE_HISTORY_FindPartner(struct TradeHistory *history, u32 id)
{
    int i;

    for (i = 0; i < 100; i++) {
        if (MYSTATUS_GetAvatarId(&history->partners[i]) != 0
            && id == MYSTATUS_GetId(&history->partners[i])) {
            return i;
        }
    }
    return -1;
}

void TRADE_HISTORY_AddPartner(struct TradeHistory *history, struct MyStatus *status)
{
    u32 id = MYSTATUS_GetId(status);
    u32 size = MYSTATUS_GetSize();
    int slot;

    if (id == 0) {
        return;
    }
    slot = TRADE_HISTORY_FindPartner(history, id);
    if (slot != -1) {
        MYSTATUS_SetOutfit(&history->partners[slot], MYSTATUS_GetOutfit(status));
        return;
    }
    MI_CpuMove(history->partners, &history->partners[1], size * 99);
    MI_CpuCopy8(status, history->partners, size);
}

u32 TRADE_HISTORY_GetPartnerId(struct TradeHistory *history, u32 slot)
{
    if (slot >= 100) {
        slot = 0;
    }
    return MYSTATUS_GetId(&history->partners[slot]);
}

struct MyStatus *TRADE_HISTORY_GetPartner(struct TradeHistory *history, u32 slot)
{
    if (slot >= 100) {
        return 0;
    }
    if (TRADE_HISTORY_GetPartnerId(history, slot) == 0) {
        return 0;
    }
    return &history->partners[slot];
}

u32 TRADE_HISTORY_HasPartner(struct TradeHistory *history, u32 id)
{
    if (TRADE_HISTORY_FindPartner(history, id) != -1) {
        return 1;
    }
    return 0;
}

int TRADE_HISTORY_GetPartnerCount(struct TradeHistory *history)
{
    int i;

    for (i = 0; i < 100; i++) {
        if (MYSTATUS_GetAvatarId(&history->partners[i]) == 0) {
            break;
        }
    }
    return i;
}

u32 TRADE_HISTORY_GetTradeCount(const struct TradeHistory *history)
{
    return history->tradeCount;
}

void TRADE_HISTORY_IncrementTradeCount(struct TradeHistory *history)
{
    history->tradeCount = history->tradeCount + 1;
    if (history->tradeCount > 99999) {
        history->tradeCount = 99999;
    }
}

/*
 * Save-block getter for block 0x1F, the same one-line shape as
 * WORLDTRADE_GetFromSave (block 0x2E): a tail call through the pool with the id in
 * r1. Seeded from ov120 (0x021D4A90, 0x021D4AC8), ov135 (0x02201B78) and
 * the ov175 root WIFIBATTLEMATCH_NET_CompStepF (0x021D827E).
 */
struct TradeHistory *TRADE_HISTORY_GetFromSave(struct SaveControl *save)
{
    return SAVE_CONTROL_GetBlock(save, 0x1f);
}
