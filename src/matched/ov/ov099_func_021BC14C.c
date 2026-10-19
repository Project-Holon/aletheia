/*
 * function: WIFICLUB_StateStartInvite
 * address:  0x021BC14C
 * packet:   pkt_ov099_021BC14C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-05 (wD5 lane01): EXACT. Each arm ends with `off -= 0x76; p[off] = 0x42 / 0x49;`; tail
 *   merging builds the shared join. The value local r merged at the join swapped p and off.
 *   Older notes below.
 *
 * note (2026-10-04): DIFF, 124 vs 120 bytes. Original pushes r3-r7 (v in r6, zero local in r7), loads the 0x242 pool offset into r5 inside each arm and reuses it at the join as subs r5,#0x76 for the 0x1CC store; ours reads 0x242 into r1 (dies at the ldrh), builds 0x1CC separately, and uses only r4-r6. Semantics are right; the open question is what keeps the 0x242 constant live to the join.
 *
 * note (2026-10-04, lane17): lane17 wave D2: re-read, no new change. Same residue as the note above (0x242 pool offset kept in r5 to the join; pushes r3-r7).
 *
 * note: 2026-10-05 (wD4 lane20): constant-in-a-local lever applied: int off = 0x242 assigned in each arm, join is off -= 0x76; p[off] = r. Down from 50 to 14 differing bytes, same size, r4-r7 push set now matches, offset kept live to the join. Residue: p/off colour swap only (image p r4, off r5; ours p r5, off r4). Tried declaration orders of z/r/off, off initialised at the top (loses the r7 zero), off -= inside the index expression.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_SetAcceptConnection  0x0203D1E8  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   WIFICLUB_SetPartnerNameWord  0x021BA874  thumb  ov099
 *   WIFICLUB_ShowStreamedMessage  0x021BAAB8  thumb  ov099
 *   WIFICLUB_ResetTimeIcon  0x021BC090  thumb  ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Link;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_SetAcceptConnection(u32 unused, void *arg);
extern u32 GFL_NET_IsParentAid(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, u32 lo, u32 hi);
extern void WIFICLUB_SetPartnerNameWord(char *p, int id);
extern void WIFICLUB_ShowStreamedMessage(char *p, int a, int b);
extern void WIFICLUB_ResetTimeIcon(char *p);

int WIFICLUB_StateStartInvite(char *p, int v)
{
    int z;
    int off;
    GFL_NET_SetAcceptConnection((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0);
    z = 0;
    if (GFL_NET_IsParentAid() == 0) {
        *(int *)(p + 0x135C) = 3;
        off = 0x242;
        WIFICLUB_SetPartnerNameWord(p, *(u16 *)(p + off) - 1);
        WIFICLUB_ShowStreamedMessage(p, 0x5F, z);
        off -= 0x76;
        *(int *)(p + off) = 0x42;
    } else {
        *(int *)(p + 0x135C) = 4;
        off = 0x242;
        WIFICLUB_SetPartnerNameWord(p, *(u16 *)(p + off) - 1);
        WIFICLUB_ShowStreamedMessage(p, 0x7E, z);
        WIFICLUB_ResetTimeIcon(p);
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1B, 0xA);
        off -= 0x76;
        *(int *)(p + off) = 0x49;
    }
    return v;
}
