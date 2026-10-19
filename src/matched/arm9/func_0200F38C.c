/*
 * function: WIFILIST_SearchFriendSlot
 * address:  0x0200F38C
 * packet:   pkt_0200F38C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_GetWifiUserData   0x0203D5EC  arm
 *   GFL_NET_GetFriendList   0x0203D610  arm
 *   GFL_NET_GetFriendListNum   0x0203D634  arm
 *   func_020596D8   0x020596D8  arm
 *   DWC_GetGsProfileId   0x020598EC  arm
 *   DWC_IsEqualFriendData   0x02059A5C  arm
 *
 * Search for a free friend slot: the out-parameter starts at -1 and the
 * function reports 3 when the object is not known at all (func_020596D8),
 * 0 for the first record whose tester (DWC_IsEqualFriendData) accepts it with that
 * slot index, 1 when the key (DWC_GetGsProfileId) of the object matches the
 * record's, and 2 when the scan finishes.  A slot that no key names and that
 * the tester still rejects is kept as a fallback in *out.
 *
 * This is the callee src/pending/sub_0200F4E4.c is capped on: its only
 * branch anywhere in the image is that one call site, so this entry is the
 * witness that turns it EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIFILIST_SearchFriendSlot.c \
 *       --func WIFILIST_SearchFriendSlot --addr 0x0200F38C --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 GFL_NET_GetWifiUserData(void);
extern u32 GFL_NET_GetFriendList(void);
struct DWCstAccUserData;
extern u32 GFL_NET_GetFriendListNum(void);
extern int   func_020596D8(void *p);
extern int DWC_GetGsProfileId(struct DWCstAccUserData *userdata, void *frienddata);
extern int   DWC_IsEqualFriendData(void *a, void *b);

int WIFILIST_SearchFriendSlot(void *a, int *out)
{
    int   i;
    void *key = (void *)GFL_NET_GetWifiUserData();
    u8   *tbl = (u8 *)GFL_NET_GetFriendList();
    int   n = GFL_NET_GetFriendListNum();

    *out = -1;
    if (func_020596D8(a) == 0)
        return 3;
    for (i = 0; i < n; i++) {
        int off = i * 12;

        if (DWC_IsEqualFriendData(a, tbl + off) != 0) {
            *out = i;
            return 0;
        }
        if (DWC_GetGsProfileId(key, a) > 0
            && DWC_GetGsProfileId(key, a) == DWC_GetGsProfileId(key, tbl + off)) {
            *out = i;
            return 1;
        }
        if (*out < 0 && func_020596D8(tbl + off) == 0)
            *out = i;
    }
    return 2;
}
