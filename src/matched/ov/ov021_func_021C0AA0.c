/*
 * function: EVENT_RECOVERY_CreatePartyEvent
 * address:  0x021C0AA0
 * packet:   pkt_ov021_021C0AA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Spawns a 0x3C-byte task (callback EVENT_RECOVERY_RunParty) and initialises it.
 *
 * symbols:
 *   EVENT_RECOVERY_InitParty  0x021C0B3C  thumb  ov021
 *   EVENT_RECOVERY_RunParty  0x021C0AC0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Desc;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
void *func_020124E8(struct Obj *p);
int EVENT_RECOVERY_RunParty(u32 a, int *st, u8 *p);
void EVENT_RECOVERY_InitParty(u8 *p, u32 a);

void *EVENT_RECOVERY_CreatePartyEvent(void *p, int a1)
{
    void *t = func_020122C0(p, (void *)a1, EVENT_RECOVERY_RunParty, 0x3C);
    u8 *w = func_020124E8(t);

    EVENT_RECOVERY_InitParty(w, (u32)p);
    return t;
}
