/*
 * function: GFL_NET_ERR_UpdateFriendRecord
 * address:  0x0200F4E4
 * packet:   pkt_0200F38C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     promoted from src/pending 2026-09-19 with NO C change: the only unresolved site was the
 *           call at +0x0012 to GFL_NET_ERR_SearchFriendSlot, which became a `matched` witness when
 *           src/matched/GFL_NET_ERR_SearchFriendSlot.c was filed (layout/matched/arm9/pkt_0200F38C.json).
 *           match.py one: EXACT, compiled 60 bytes, 3 of 3 relocations resolved.
 * symbols:
 *   GFL_NET_GetFriendList  0x0203D610  arm
 *   GFL_NET_ERR_SearchFriendSlot  0x0200F38C  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 * blocker:  unresolved relocation(s): 0200F38C (thumb, from header)*/

typedef unsigned int u32;

extern u32 GFL_NET_GetFriendList(void);
extern int GFL_NET_ERR_SearchFriendSlot(void *a, int *out);
extern void  MI_CpuCopy8(void *dst, const void *src, u32 n);

int GFL_NET_ERR_UpdateFriendRecord(void *o)
{
    u32 out;
    int r = 0;
    void *base = (void *)GFL_NET_GetFriendList();
    int v = GFL_NET_ERR_SearchFriendSlot(o, (int *)(&out));

    if (v == 0) {
        /* nothing */
    } else if (v == 1) {
        MI_CpuCopy8(o, (unsigned char *)base + out * 0xc, 0xc);
    } else if (v == 2) {
        r = 1;
    }
    return r;
}
