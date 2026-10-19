/*
 * function: GAME_DATA_GetBattleRecSlotByNetId
 * address:  0x021583CC
 * packet:   pkt_021583CC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Dispatch on the record's key: an equal key goes to the
 * single-argument arm9 read, anything else to the pair form.
 *
 * symbols:
 *   GAME_DATA_GetOwnNetId   0x02012B58  thumb
 *   GAME_DATA_GetLastBattleRecSlot   0x020127B8  thumb
 *   GAME_DATA_GetBattleRecSlot   0x020127AC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
extern u8 GAME_DATA_GetOwnNetId(const struct BigObj *p);
extern void *GAME_DATA_GetLastBattleRecSlot(void *p);
struct SaveBlock;
extern void *GAME_DATA_GetBattleRecSlot(struct SaveBlock *p, u32 idx);

int GAME_DATA_GetBattleRecSlotByNetId(void *a0, int a1)
{
    if (GAME_DATA_GetOwnNetId(a0) == a1)
        return (int)GAME_DATA_GetLastBattleRecSlot(a0);

    return (int)GAME_DATA_GetBattleRecSlot(a0, a1);
}

