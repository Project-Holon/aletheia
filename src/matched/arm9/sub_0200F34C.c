/*
 * function: sub_0200F34C
 * address:  0x0200F34C
 * packet:   pkt_0200F17C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DWC_IsEqualFriendData  0x02059A5C  arm
 *   DWC_GetGsProfileId  0x020598EC  arm
 *
 * A three-way friend-key comparator: bails out (0) if DWC_IsEqualFriendData(a, c)
 * flags the pair invalid. Otherwise compares b against a with
 * DWC_GetGsProfileId; if that says "no difference" (<= 0) the function reports
 * "not newer" (2). Otherwise it re-derives the b-against-a comparison
 * (the call is issued twice) and compares it against a fresh b-against-c
 * comparison, reporting "newer" (1) only when they agree and "not newer"
 * (2) otherwise.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F34C.c \
 *       --func sub_0200F34C --addr 0x0200F34C --cc 1.1p1
 */

extern int DWC_IsEqualFriendData(void *b, void *c);
struct DWCstAccUserData;
extern int DWC_GetGsProfileId(struct DWCstAccUserData *userdata, void *frienddata);

int sub_0200F34C(void *a, void *b, void *c)
{
    if (DWC_IsEqualFriendData(a, c) != 0) {
        return 0;
    }

    if (DWC_GetGsProfileId(b, a) > 0) {
        int lhs = DWC_GetGsProfileId(b, a);
        int rhs = DWC_GetGsProfileId(b, c);
        if (lhs == rhs) {
            return 1;
        }
    }
    return 2;
}
