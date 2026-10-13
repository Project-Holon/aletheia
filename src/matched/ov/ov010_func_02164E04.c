/*
 * function: GAME_BEACON_SEARCH_PickBestScanResult
 * address:  0x02164E04
 * packet:   pkt_ov010_02164E04
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Scans 16 slots for the best usable entry, stores its index through *out
 * and returns its record; 0 when none.
 *
 * symbols:
 *   NET_WHPIPE_GetEntryKind  0x02178098  thumb ov014
 *   GFL_NET_GetScanResult  0x0203CF10  arm
 *   GAME_BEACON_SEARCH_SelectBetterEntry  0x02164F9C  thumb ov010
 *   func_02177BF4  0x02177BF4  thumb ov014
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18986.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Ent {
    u8 b0;
    u8 lo : 4;
    u8 hi : 4;
    u8 flag : 1;
    u8 kind : 5;
    u8 rest : 2;
} Ent;

extern u8 NET_WHPIPE_GetEntryKind(u8 i);
extern u32 GFL_NET_GetScanResult(u32 a);
extern Ent  *GAME_BEACON_SEARCH_SelectBetterEntry(Ent *a, Ent *b);
extern void func_02177BF4(unsigned int idx);

Ent *GAME_BEACON_SEARCH_PickBestScanResult(u8 *obj, int *out)
{
    int none = -1;
    int best = -1;
    int i;
    Ent *p;
    int r;
    for (i = 0; i < 16; i++) {
        r = NET_WHPIPE_GetEntryKind(i);
        if ((u32)(r - 2) > 1) {
            continue;
        }
        if (r == 2 && ((struct Obj18986 *)obj)->fC != 0) {
            continue;
        }
        p = (Ent *)GFL_NET_GetScanResult(i);
        if (p == 0) {
            continue;
        }
        if (p->lo < p->hi) {
            if (best == none) {
                best = i;
            } else if (GAME_BEACON_SEARCH_SelectBetterEntry(p, (Ent *)GFL_NET_GetScanResult(best)) == p) {
                best = i;
            }
        } else {
            func_02177BF4(i);
        }
    }
    if (best != -1) {
        *out = best;
        return (Ent *)GFL_NET_GetScanResult(best);
    }
    return 0;
}
