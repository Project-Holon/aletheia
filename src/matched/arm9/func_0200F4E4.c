/*
 * function: func_0200F4E4
 * address:  0x0200F4E4
 * packet:   pkt_0200F38C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     promoted from src/pending 2026-09-19 with NO C change: the only unresolved site was the
 *           call at +0x0012 to func_0200F38C, which became a `matched` witness when
 *           src/matched/func_0200F38C.c was filed (layout/matched/arm9/pkt_0200F38C.json).
 *           match.py one: EXACT, compiled 60 bytes, 3 of 3 relocations resolved.
 * symbols:
 *   GFL_NET_GetFriendList  0x0203D610  arm
 *   func_0200F38C  0x0200F38C  thumb
 *   func_02082D44  0x02082D44  arm
 * blocker:  unresolved relocation(s): 0200F38C (thumb, from header)*/

typedef unsigned int u32;

extern u32 GFL_NET_GetFriendList(void);
extern int func_0200F38C(void *a, int *out);
extern void  func_02082D44(void *dst, const void *src, u32 n);

int func_0200F4E4(void *o)
{
    u32 out;
    int r = 0;
    void *base = (void *)GFL_NET_GetFriendList();
    int v = func_0200F38C(o, (int *)(&out));

    if (v == 0) {
        /* nothing */
    } else if (v == 1) {
        func_02082D44(o, (unsigned char *)base + out * 0xc, 0xc);
    } else if (v == 2) {
        r = 1;
    }
    return r;
}
