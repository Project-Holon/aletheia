/*
 * function: func_021E0410
 * address:  0x021E0410
 * packet:   pkt_ov119_021E0410
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetBoxSave  0x02012F98  thumb
 *   PERAPVOICE_IsRecorded   0x02007B50  thumb
 *   PERAPVOICE_ClearRecorded   0x02007B54  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22756.h"

typedef unsigned int u32;

struct Sub02007AC8Entry;
extern struct Sub02007AC8Entry *GAME_DATA_GetBoxSave(void *p);
struct PerapVoice;
extern void *PERAPVOICE_IsRecorded(void **p);
extern void PERAPVOICE_ClearRecorded(struct PerapVoice *p);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);

int func_021E0410(char *p, void *party, int idx)
{
    int count = 0;
    int i, n;
    void *voice = GAME_DATA_GetBoxSave(((struct Obj22756 *)p)->f82C);

    if (!PERAPVOICE_IsRecorded(voice))
        return count;
    n = POKEPARTY_GetCount(party);
    for (i = 0; i < n; i++) {
        if (POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(party, i), 5, 0) == 0x1B9)
            count++;
    }
    if (count != 1)
        return 0;
    count = 0;
    if (POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(party, idx), 5, 0) == 0x1B9) {
        PERAPVOICE_ClearRecorded(voice);
        return 1;
    }
    return count;
}
