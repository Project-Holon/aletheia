/*
 * function: func_021F8D88
 * address:  0x021F8D88
 * packet:   pkt_021F8D88
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unblocked by matching func_02157364 (ov010, EXACT, Thumb): the +0008 call
 * site now attests as `matched`. ov009 holds ARM code at that address; ov010
 * is the coherent Thumb leaf, so the declaration is thumb/ov010 (the earlier
 * `arm` was wrong).
 *
 * symbols:
 *   func_02157364  0x02157364  thumb  ov010
 *   func_021F6FB0  0x021F6FB0  thumb  ov112
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_02157364(void *);
extern void func_021F6FB0(void *, int);

void func_021F8D88(u8 *p)
{
    int v = func_02157364(*(void **)((u8 *)*(void **)(p + 0x30) + 0x14));
    func_021F6FB0(*(void **)(p + 0x3c), v);
}
